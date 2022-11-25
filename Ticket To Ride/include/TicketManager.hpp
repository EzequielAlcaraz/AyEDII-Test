#ifndef TICKETMANAGER_HPP
#define TICKETMANAGER_HPP

#include "Ticket.hpp"
#include "Client.hpp"
#include "Agent.hpp"
#include <iostream>
#include <vector>

class TicketManager
{
    private:
        std::vector<Ticket> m_ticketL;
        IClient *cli = new Client();
        IAgent *age = new Agent();

    public:
        TicketManager();
        virtual ~TicketManager();

        void createTicket(int id, IClient *client, IAgent *agent, std::string message, std::string date);
        void addTicket(Ticket ticket);
        void deleteTicket(int id);
        int findTicket(int id);
        void searchTicket(int id);
        void showTicketVec();
        void updateTicket(Ticket ticket, int id);

};


#endif //TICKETMANAGER_HPP