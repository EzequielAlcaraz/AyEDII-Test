#include "../include/Client.hpp"

Client::Client(){}

Client::Client(int id, std::string name, int dni, std::string email)
    :c_id(id), c_name(name), c_dni(dni), c_email(email){}

Client::~Client(){}

void Client::setId(int id)
{
    c_id = id;
}

int Client::getId()
{
    return c_id;
}

void Client::setName(std::string name)
{
    c_name = name;
}

std::string Client::getName()
{
    return c_name;
}

void Client::setDNI(int dni)
{
    c_dni = dni;
}

int Client::getDNI()
{
    return c_dni;
}

void Client::setEmail(std::string email)
{
    c_email = email;
}

std::string Client::getEmail()
{
    return c_email;
}
