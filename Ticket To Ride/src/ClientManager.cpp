#include "../include/ClientManager.hpp"

ClientManager::ClientManager(){}

ClientManager::~ClientManager()
{
    delete cli;
}

void ClientManager::createClient(int id, std::string name, int dni, std::string email)
{
    cli = new Client(id, name, dni, email);

    addClient(cli);
}

void ClientManager::addClient(IClient *client)
{
    c_cliVec.push_back(client);

    std::cout << "Client " << client->getName() << " was added" << std::endl;

    // sort(c_cliVec.begin(), c_cliVec.end());
    // El metodo addClient tambien ordena los elementos del vector

    sort(c_cliVec.begin(), c_cliVec.end(), [] (IClient *x, IClient *y) {return x->getId() < y->getId(); } );
}

void ClientManager::deleteClient(int id)
{
    int pos = findClient(id);
    
    if(pos != -1)
    {
        // c_cliVec.erase(begin(c_cliVec) + pos); 
        c_cliVec.erase(c_cliVec.begin() + pos); 
    }
}

int ClientManager::findClient(int id)
{
    int index = -1;

    for (size_t i = 0; i < c_cliVec.size(); i++)
    {
        if (c_cliVec[i]->getId() == id)
        {
            index = i;
        }
    }
    
    return index++;
}

void ClientManager::searchClient(int id)
{
    int pos = findClient(id);

    std::cout << "ID: "<< c_cliVec[pos]->getId() << "   Name: " << c_cliVec[pos]->getName() 
        << "   DNI: " << c_cliVec[pos]->getDNI() << "   Email: " << c_cliVec[pos]->getEmail() << std::endl;
}

void ClientManager::showClientVec()
{
    // for (auto clivec : c_cliVec)
    // {
    //     std::cout << "ID: "<< clivec.getName() << " Name: " << clivec.getName() 
    //         << " DNI: " << clivec.getDNI() << " Email: " << clivec.getEmail() << std::endl;       
    // }

    for (size_t i = 0; i < c_cliVec.size(); i++)
    {
        std::cout << "ID: "<< c_cliVec[i]->getId() << "   Name: " << c_cliVec[i]->getName() 
            << "   DNI: " << c_cliVec[i]->getDNI() << "   Email: " << c_cliVec[i]->getEmail() << std::endl;
    }
}

void ClientManager::updateClient(IClient *client, int id)
{
    int pos = findClient(id);

    if(pos != -1)
    {
        c_cliVec.at(pos) = client;

        // c_cliVec.erase(begin(c_cliVec) + pos); 
        // // Verificar como agregar un dato en una posicion de un vector
        // c_cliVec.push_back(client);      
    }

}

void ClientManager::clientEmailNotify()
{
    INotify *notify = new NotifyEmail();

    notify->notify();
}
