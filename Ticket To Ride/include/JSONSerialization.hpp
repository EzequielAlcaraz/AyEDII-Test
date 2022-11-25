#ifndef JSONSERIALIZATION_HPP
#define JSONSERIALIZATION_HPP

#include "Agent.hpp"
#include "Client.hpp"
#include "Ticket.hpp"
#include "../lib/json.hpp"
#include <iostream>
#include <fstream>

using json = nlohmann::json;

class JSONSerialization
{
    private:
        json j_storage;
    
    public:
        JSONSerialization();
        ~JSONSerialization();

        void saveJSONClient(IClient *client);
        void saveJSONAgent(IAgent *agent);
        void saveJSONTicket(Ticket ticket);
        
        void readJSONData();
};


#endif // !JSONSERIALIZATION_HPP