#include "../include/Ticket.hpp"

Ticket::Ticket(){}

Ticket::Ticket(int id, IClient *client, IAgent *agent, std::string message, std::string date)
    :t_id(id), t_client(client), t_agent(agent), t_message(message), t_date(date){}

Ticket::~Ticket(){}

void Ticket::setId(int id)
{
    t_id = id; 
}

int Ticket::getId()
{
    return t_id;
}

void Ticket::setClient(IClient *client)
{
    t_client = client;
}

IClient* Ticket::getClient()
{
    return t_client;
}

void Ticket::setAgent(IAgent *agent)
{
    t_agent = agent;
}

IAgent* Ticket::getAgent()
{
    return t_agent;
}

void Ticket::setMessage(std::string message)
{
    t_message = message;
}

std::string Ticket::getMessage()
{
    return t_message;
}

void Ticket::setDate(std::string date)
{
    t_date = date;
}

std::string Ticket::getDate()
{
    return t_date;
}
