#include <connection/FTPManager.hpp>
#include <view/RenderEngine.hpp>


int main()
{
    RenderEngine renderEngine;
    renderEngine.startEngine();

    FTPManager manager(&renderEngine);
    manager.startFTP();
    while(renderEngine.getThreadState()){
        sf::sleep(sf::seconds(0.1));
    }

    return 0;
}