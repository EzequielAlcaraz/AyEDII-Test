#ifndef IAGENT_HPP
#define IAGENT_HPP

#include <iostream>

class IAgent
{
    public:
        virtual ~IAgent() = default;
        virtual void setId(int id) = 0;
        virtual int getId() = 0;
        virtual void setArea(std::string area) = 0;
        virtual std::string getArea() = 0;
        virtual void setName(std::string name) = 0;
        virtual std::string getName() = 0;
        virtual void setDNI(int DNI) = 0;
        virtual int getDNI() = 0;
        virtual void setEmail(std::string email) = 0;
        virtual std::string getEmail() = 0;
};


#endif //IAGENT_HPP