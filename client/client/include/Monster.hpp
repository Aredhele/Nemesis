#ifndef DEF_MONSTER_HPP
#define DEF_MONSTER_HPP

#include <string>
#include "Caracteristic.hpp"

class Monster{

	private:

		bool m_choosed;
        std::wstring m_name;
        std::string m_id;
        Caracteristic *ptr_caracteristic;

    public:

    	 //Constructor
        Monster();
        

        //Destructor
        ~Monster();

        //Methods
        void selectMonster();
        void deselectMonster();
        bool getSelectMonster();
        std::wstring getName();
        std::string getId();
        void setName(std::wstring name);
        void setId(std::string id);

        void setCaracteristics(int atckDmg, int health, int armor);
        Caracteristic * getCaracteristic();

        int hitDamage(int atckDmg, int pvEnemy);
        int summonDamage(int atckDmg, int pvEnemy);
};
#endif //DEF_MONSTER_HPP