//
// Created by Jehan on 05/03/2016.
//

#ifndef CLIENT_CARACTERISTIC_HPP
#define CLIENT_CARACTERISTIC_HPP

#include <string>
#include <sstream>

class Caracteristic{
	private:
		int m_attackDamage;
		int m_health;
		int m_armor;
		int m_maxHealth;


	public:
		Caracteristic();

		~Caracteristic();

		//Methods 
		void setMaxHealth(int maxHealth)
		void setCaracteristics(int atckDmg, int health, int armor);

		int getArmor();
		int getHealth();
		int getAttackDamage();

};

#endif //CLIENT_CARACTERISTIC_HPP