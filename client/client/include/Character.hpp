//
// Created by Lucas on 02/03/2016.
//

#ifndef DEF_CHARACTER_HPP
#define DEF_CHARACTER_HPP


class Character{

    private:
        bool m_choosed;
        std::wstring m_description;
        std::wstring m_name;
        std::string m_id;

    public:
        //Constructor
        Character();

        //Destructor
        ~Character();

        //Methods
        void selectCharacter();
        void deselectCharacter();
        std::wstring getDescription();
        std::wstring getName();
        void setName(std::wstring name);
        void setDescription(std::wstring description);
        void setId(std::string id);

};
#endif //DEF_CHARACTER_HPP
