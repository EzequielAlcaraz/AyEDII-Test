#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "IClient.hpp"
#include <iostream>

class Client : public IClient
{
    private:
        int c_id;
        std::string c_name;
        int c_dni;
        std::string c_email;

    public:
        Client();
        Client(int id, std::string name, int dni, std::string email);
        virtual ~Client();

        void setId(int id);
        int getId();

        void setName(std::string name);
        std::string getName();

        void setDNI(int dni);
        int getDNI();

        void setEmail(std::string email);
        std::string getEmail();

};


#endif //CLIENT_HPP