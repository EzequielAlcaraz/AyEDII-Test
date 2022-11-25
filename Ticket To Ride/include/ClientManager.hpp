#ifndef CLIENTMANAGER_HPP
#define CLIENTMANAGER_HPP

// #include <IClient.hpp>
#include "Client.hpp"
#include "NotifyEmail.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

class ClientManager
{
    private:
        std::vector<IClient*> c_cliVec;  
        IClient *cli;

    public:
        // std::vector<IClient> c_cliVec;       //Para memoria dinamica
        // std::vector<Client> c_cliVec;

        ClientManager();
        virtual ~ClientManager();
        
        void createClient(int id, std::string name, int dni, std::string email);
        void addClient(IClient *client);
        void deleteClient(int id);
        int findClient(int id);
        void searchClient(int id);
        void showClientVec();
        void updateClient(IClient *client, int id);
        void clientEmailNotify();
};  


#endif //CLIENTMANAGER_HPP