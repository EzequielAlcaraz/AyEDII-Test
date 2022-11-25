#ifndef TICKET_HPP
#define TICKET_HPP

#include "IAgent.hpp"
#include "IClient.hpp"
#include "../lib/json.hpp"
#include <iostream>

using json = nlohmann::json;

class Ticket
{
    private:
        int t_id;
        IClient *t_client;
        IAgent *t_agent;
        std::string t_message;
        std::string t_date;

    public:
        Ticket();
        Ticket(int id, IClient *client, IAgent *agent, std::string message, std::string date);
        virtual ~Ticket();

        void setId(int id);
        int getId();

        void setClient(IClient *client);
        IClient* getClient();

        void setAgent(IAgent *agent);
        IAgent* getAgent();

        void setMessage(std::string message);
        std::string getMessage();

        void setDate(std::string date);
        std::string getDate();

};


#endif //TICKET_HPP