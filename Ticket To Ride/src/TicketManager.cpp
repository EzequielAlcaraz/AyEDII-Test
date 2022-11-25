#include "../include/TicketManager.hpp"

TicketManager::TicketManager(){}

TicketManager::~TicketManager()
{
    delete cli;
    delete age;
}

void TicketManager::createTicket(int id, IClient *client, IAgent *agent, std::string message, std::string date)
{
    Ticket ticket(id, client, agent, message, date);

    addTicket(ticket);
}

void TicketManager::addTicket(Ticket ticket)
{
    m_ticketL.push_back(ticket);

    std::cout << "Ticket " << ticket.getId() << " was added" << std::endl;

    // sort(m_ticketL.begin(), m_ticketL.end());
    // El metodo addClient tambien ordena los elementos del vector

    sort(m_ticketL.begin(), m_ticketL.end(), [] (Ticket &x, Ticket &y) {return x.getId() < y.getId(); } );
}

void TicketManager::deleteTicket(int id)
{
    int pos = findTicket(id);
    
    if(pos != -1)
    {
        // m_ticketL.erase(begin(m_ticketL) + pos); 
        m_ticketL.erase(m_ticketL.begin() + pos); 
    }
}

int TicketManager::findTicket(int id)
{
    int index = -1;

    for (size_t i = 0; i < m_ticketL.size(); i++)
    {
        Ticket t = m_ticketL[i];
        if (m_ticketL[i].getId() == id)
        {
            index = i;
            
        }
    }

    return index++;
}

void TicketManager::searchTicket(int id)
{
    int pos = findTicket(id);

    this->cli = m_ticketL[pos].getClient();
    this->age = m_ticketL[pos].getAgent();

    std::cout << "ID: "<< m_ticketL[pos].getId() << "   Client: " << cli->getName() 
        << "   Agent: " << age->getName() << "   Message: " << m_ticketL[pos].getMessage()
        << "   Date: " << m_ticketL[pos].getDate() << std::endl;
}

void TicketManager::showTicketVec()
{
    for (size_t i = 0; i < m_ticketL.size(); i++)
    {
        this->cli = m_ticketL[i].getClient();
        this->age = m_ticketL[i].getAgent();

        std::cout << "ID: "<< m_ticketL[i].getId() << "   Client: " << cli->getName() 
            << "   Agent: " << age->getName() << "   Date: " << m_ticketL[i].getDate()
            << "   Message: " << m_ticketL[i].getMessage() << std::endl;
    }
}

void TicketManager::updateTicket(Ticket ticket, int id)
{
    int pos = findTicket(id);

    if(pos != -1)
    {
        m_ticketL.at(pos) = ticket;
    }

}
