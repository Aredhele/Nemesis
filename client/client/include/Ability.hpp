//
// Created by Jehan on 05/03/2016.
//

#ifndef CLIENT_ABILITY_HPP
#define CLIENT_ABILITY_HPP

#endif //CLIENT_ABILITY_HPP

class Ability{
	private:
		int m_damage;
		int m_length; // en secondes

	public:
		Ability();
		~Ability();
		void setAbilityEldora(int dmg, int lgth);
		void setAbilityTristan(int dmg, int lgth);
		void setAbilityRemington(int dmg, int lgth);
		void setAbilityNumero8(int dmg, int lgth);
		int getAbilityDamage();
		int getAbilityLength();

		
};