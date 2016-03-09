//
// Created by Lucas on 02/03/2016.
//

#ifndef DEF_CHARACTER_HPP
#define DEF_CHARACTER_HPP

#include <string>
#include "Caracteristic.hpp"
#include "Ability.hpp"

class Character{

    private:
        bool m_choosed;
        std::wstring m_description;
        std::wstring m_name;
        std::string m_id;
        Caracteristic *ptr_caracteristic;
        Ability *ptr_ability;

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
        std::string getId();
        void setCaracteristics(int atckDmg, int health, int armor);
        void setAbility(int id, std::string name,std::string type);
        Caracteristic * getCaracteristic();
};
#endif //DEF_CHARACTER_HPP
