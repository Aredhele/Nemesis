//
// Created by Jehan on 08/02/2016.
//

#include "Lobby.hpp"
/*!
 * \brief Constructor
 */
Lobby::Lobby(bool debug, ManagerGroup * ptr_managerGroup) :
        BasicInterface(debug, ptr_managerGroup),
        m_monSuperLabel(),
        m_refreshButton(),
        m_createButton()
{
    noError();
    nbWarmUp = 0;
    firstConnect = true;

    ptr_textureButton1 = ptr_managerGroup->ptr_textureManager->getTexture("rejoindreButton_1");
    ptr_textureButton2 = ptr_managerGroup->ptr_textureManager->getTexture("rejoindreButton_2");

    if (!m_font.loadFromFile("../res/font/Roboto-Regular.ttf"))
    {
        std::cout << "Probleme dans le chargement des textures" << std::endl;
    }

    m_monSuperLabel.create("monSuperLabel", 450, 100, 20, &m_font, L"Parties en cours...", sf::Color(196,130,56));

    m_refreshButton.create("refreshButton", 50, 700,
                        ptr_managerGroup->ptr_textureManager->getTexture("refreshButton_1"),
                        ptr_managerGroup->ptr_textureManager->getTexture("refreshButton_2"));
    m_createButton.create("createButton", 940, 700,
                        ptr_managerGroup->ptr_textureManager->getTexture("createButton_1"),
                        ptr_managerGroup->ptr_textureManager->getTexture("createButton_2"));

    getContentPane()->addComponent(&m_monSuperLabel);
    getContentPane()->addComponent(&m_refreshButton);
    getContentPane()->addComponent(&m_createButton);
}

/*!
 * \brief Constructor
 */
Lobby::~Lobby() {
    // TODO
}

/*!
 * \brief Update current object
 * \param window The pointer on the window
 * \param frameTime The elpased time
 */
void Lobby::update(sf::RenderWindow * window,
                       sf::Event * e, double frameTime) {


    if(!m_ptr_managerGroup->ptr_targetManager->isLobby())
        return;

    if(m_ptr_managerGroup->ptr_networkManager->getHasPacket()){
        receiveRequest();
    }

    if(firstConnect){
        //We call one time the number of WarmUps and their name
        requestUpdateWarmUp();
        firstConnect = false;
    }

    for(int i = 1; i <= 5; i++){
        if(m_inputHandler.getComponentId() == "connectButton"+i) {
            requestJoinWarmUp(i);
        }
    }

    if(m_inputHandler.getComponentId() == "refreshButton") {
        requestUpdateWarmUp();
    }
    if(m_inputHandler.getComponentId() == "createButton") {
        std::cout << "Creation WarmUp" << std::endl;
        requestCreateNewWarmUp();
        std::cout << "Join WarmUp" << std::endl;
        requestJoinWarmUp(nbWarmUp);

    }


    // Basic Interface updating
    basicInput(e, frameTime);

    // Drawing all content
    basicDraw(window);
}

void Lobby::requestCreateNewWarmUp(){
    if(m_ptr_managerGroup->ptr_networkManager->request(1, m_ptr_managerGroup->ptr_gameManager->getPlayer()->getName(),"")){

        std::cout << "Creation WarmUp réussi par " <<
                m_ptr_managerGroup->ptr_gameManager->getPlayer()->getName() << std::endl;
    }
    else{
        errorConnection();
    }
}

void Lobby::requestUpdateWarmUp(){
    if(m_ptr_managerGroup->ptr_networkManager->request(3, "","")){
        std::cout << "Requete update salon bien envoyé" << std::endl;
    }
    else{
        errorConnection();
    }
}

void Lobby::requestJoinWarmUp(int idWarmUp){
    if(m_ptr_managerGroup->ptr_networkManager->request(2, "" + cast::toString(idWarmUp) +
                                                          std::string("&") + std::string(m_ptr_managerGroup
                                                                                                 ->ptr_gameManager->getPlayer()->getName()),"")){
    }
    else{
        errorConnection();
    }
}

void Lobby::receiveRequest(){

    std::vector <sf::Packet> packet = m_ptr_managerGroup->ptr_networkManager->getPacket();

    for(unsigned int i = 0; i < packet.size(); i++){
        sf::Int32 idRequest;
        std::string sRequest;
        packet.at(i) >> idRequest >> sRequest;

        std::cout << "debug idRequest : " << idRequest << std::endl;
        std::cout << "debug sRequest : " << sRequest << std::endl;

        switch (idRequest){
            case 2:
                //Rejoindre les salons
                if(sRequest == "Ok"){
                    std::cout << "Requete pour rejoindre WarmUp réussi par " <<
                    m_ptr_managerGroup->ptr_gameManager->getPlayer()->getName() << std::endl;

                    m_ptr_managerGroup->ptr_targetManager->isOnWarmUp();
                }
                else{
                    std::cout << "Le warmUp est complet" << std::endl;
                    errorWarmUpFull();
                }
                break;

            case 3:
                // Récupération la liste des salons

                updateNewWarmUp(sRequest);
                break;
            default:
                std::cout << "LOBBY : IDRequete non conforme -> " << idRequest << std::endl;
                break;
        }
    }


}



void Lobby::updateNewWarmUp(std::string sRequest){
    std::cout << sRequest << std::endl;
    if(sRequest.length() != 0) {
        char *cstr = new char[sRequest.length() + 1];
        strcpy(cstr, sRequest.c_str());
        std::vector<std::vector<char *>> sVectorRequestSplit1;
        std::vector<char*> sVectorRequestSplit2;
        std::vector<char*> sVectorRequestSplit;

        //Création des vecteurs
        for(int i = 1; i < 6; i++)
            sVectorRequestSplit1.push_back(std::vector < char * > ());

        //Split avec ;
        char *sRequestSplit1 = strtok(cstr, ";");


       // std::cout << "Split1  : " << sRequestSplit1 << std::endl;

        while (sRequestSplit1 != NULL) {
            sVectorRequestSplit2.push_back(sRequestSplit1);
            std::cout << "Split1  : " << sRequestSplit1 << std::endl;
            sRequestSplit1 = strtok(NULL, ";");
        }

        //Split avec &
        for(int i = 0; i < sVectorRequestSplit2.size(); i++){
            char *sRequestSplit1 = strtok(sVectorRequestSplit2[i], "&");
            //std::cout << "Split2  : " << sRequestSplit1 << std::endl;

            while (sRequestSplit1 != NULL) {
                sVectorRequestSplit.push_back(sRequestSplit1);
                //sVectorRequestSplit1[i].push_back(sRequestSplit1);
                std::cout << "Split2  : " << sRequestSplit1 << std::endl;
                sRequestSplit1 = strtok(NULL, "&");
            }
        }

        for(int i = 0; i < sVectorRequestSplit.size(); i++){
            std::cout << sVectorRequestSplit[i] << std::endl;
        }


        for (int i = 0; i < sVectorRequestSplit.size(); i+=2) {
            warmUpButton.push_back(new NButton());
            std::string tmp = cast::toString(sVectorRequestSplit[i]);

            std::cout << "Nouveau bouton :"<< tmp << ";" << std::endl;

            warmUpButton[i]->create("connectButton" +(i+1), 550, 250 + i/2 * 75,
                                    ptr_textureButton1, ptr_textureButton2);
            getContentPane()->addComponent(warmUpButton[i]);
        }

        for (int i = 0; i < sVectorRequestSplit.size(); i+=2) {
            //Convert i to wString
            std::wostringstream ws;
            ws << sVectorRequestSplit[i+1];
            const std::wstring s(ws.str());

            std::string tmp = cast::toString(sVectorRequestSplit[i]);

            warmUpLabel.push_back(new NLabel());
            warmUpLabel[i]->create("monSuperLabel" + tmp, 200, 255 + i/2 * 75,
                                   30, &m_font, L"Partie de  " + s, sf::Color::White);
            getContentPane()->addComponent(warmUpLabel[i]);
            nbWarmUp++;
            std::cout << "Nombre WARMUP " <<nbWarmUp << std::endl;
        }
    }
}

/*
void Lobby::joinWarmUp(int idWarmUp){
    sf::Packet *  packet = new sf::Packet();
    sf::Int32 idRequest;
    std::string sRequest;

    if(m_ptr_managerGroup->ptr_networkManager->request(2, ""+ cast::toString(idWarmUp) +
            std::string("&") + std::string(m_ptr_managerGroup
            ->ptr_gameManager->getPlayer()->getName() ))){

        std::cout << "Requete pour rejoindre WarmUp réussi par " <<
        m_ptr_managerGroup->ptr_gameManager->getPlayer()->getName() << std::endl;

        //We receive the request : if it's ok, when you can enter the WarmUp, if no, then the warmup
        // is full
        packet = m_ptr_managerGroup->ptr_networkManager->requestReceive();
        *packet >> idRequest >> sRequest;
        if(sRequest == "Ok"){
            std::cout << "On rejoint bien le warmUp" << std::endl;
            m_ptr_managerGroup->ptr_targetManager->isOnWarmUp();
        }
        else{
            std::cout << "Le warmUp est complet" << std::endl;
            errorWarmUpFull();
        }
    }
    else{
        errorConnection();
    }
}*/