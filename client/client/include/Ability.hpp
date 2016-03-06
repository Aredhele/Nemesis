//
// Created by Jehan on 05/03/2016.
//

#ifndef CLIENT_ABILITY_HPP
#define CLIENT_ABILITY_HPP
#include <string>

#endif //CLIENT_ABILITY_HPP

class Ability{
	private:
		int m_id;
		std::string m_name;
		std::string m_type;

	public:
		Ability();
		~Ability();
		void setAbility(int id, std::string name,std::string type);
		std::string getType();
		std::string getName();
		int getId();

		
};