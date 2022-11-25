#ifndef AGENT_HPP
#define AGENT_HPP

#include "IAgent.hpp"
#include <iostream>

class Agent : public IAgent
{
    private:
        int a_id;
        std::string a_name;
        int a_dni;
        std::string a_email;
        std::string a_area;

    public:
        Agent();
        Agent(int id, std::string name, int dni, std::string email, std::string area);
        virtual ~Agent();

        void setId(int id);
        int getId();

        void setArea(std::string area);
        std::string getArea();

        void setName(std::string name);
        std::string getName();

        void setDNI(int DNI);
        int getDNI();

        void setEmail(std::string email);
        std::string getEmail();
};


#endif //AGENT_HPP