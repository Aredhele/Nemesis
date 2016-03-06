//
// Created by Jehan on 05/03/2016.
//

#ifndef CLIENT_CARACTERISTIC_HPP
#define CLIENT_CARACTERISTIC_HPP

#endif //CLIENT_CARACTERISTIC_HPP

class Caracteristic{
	private:
		int m_attackDamage;
		int m_health;
		int m_armor;


	public:
		Caracteristic();

		~Caracteristic();

		//Methods 

		void setCaracteristicsEldora(int atckDmg, int health, int armor);
		void setCaracteristicsRemington(int atckDmg, int health, int armor);
		void setCaracteristicsTristan(int atckDmg, int health, int armor);
		void setCaracteristicsNumero8(int atckDmg, int health, int armor);
		void setCaracteristics(int atckDmg, int health, int armor);

		int getArmor();
		int getHealth();
		int getAttackDamage();

};
