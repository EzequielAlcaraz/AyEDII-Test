#include "../include/Agent.hpp"

Agent::Agent(){}

Agent::Agent(int id, std::string name, int dni, std::string email, std::string area)
    :a_id(id), a_name(name), a_dni(dni), a_email(email), a_area(area){}

Agent::~Agent(){}

void Agent::setId(int id)
{
    a_id = id;
}

int Agent::getId()
{
    return a_id;
}

void Agent::setArea(std::string area)
{
    a_area = area;
}

std::string Agent::getArea()
{
    return a_area;
}

void Agent::setName(std::string name)
{
    a_name = name;
}

std::string Agent::getName()
{
    return a_name;
}

void Agent::setDNI(int dni)
{
    a_dni = dni;
}

int Agent::getDNI()
{
    return a_dni;
}

void Agent::setEmail(std::string email)
{
    a_email = email;
}

std::string Agent::getEmail()
{
    return a_email;
}
