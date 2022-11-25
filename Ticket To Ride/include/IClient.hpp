#ifndef ICLIENT_HPP
#define ICLIENT_HPP

#include <iostream>

class IClient
{
    public:
        virtual ~IClient() = default;
        virtual void setId(int id) = 0;
        virtual int getId() = 0;
        virtual void setName(std::string name) = 0;
        virtual std::string getName() = 0;
        virtual void setDNI(int DNI) = 0;
        virtual int getDNI() = 0;
        virtual void setEmail(std::string email) = 0;
        virtual std::string getEmail() = 0;
};


#endif //ICLIENT_HPP