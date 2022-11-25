#include <iostream>

#include "../include/IClient.hpp"
#include "../include/Client.hpp"
#include "../include/ClientManager.hpp"
#include "../include/IAgent.hpp"
#include "../include/Agent.hpp"
#include "../include/AgentManager.hpp"
#include "../include/Ticket.hpp"
#include "../include/TicketManager.hpp"
#include "../include/INotify.hpp"
#include "../include/NotifyEmail.hpp"

#include "../include/JSONSerialization.hpp"

using namespace std;

int main()
{
    ClientManager *cliMan = new ClientManager;
    JSONSerialization JSONManager;

    IClient *cli1 = new Client(1114, "Lucas", 42289337, "lucas@gmail.com");
    IClient *cli2 = new Client(1115, "Jose", 38782983, "jose@gmail.com");
    IClient *cli3 = new Client(1112, "Maria", 28983784, "maria@gmail.com");

    JSONManager.saveJSONClient(cli1);
    JSONManager.saveJSONClient(cli2);
    JSONManager.saveJSONClient(cli3);

    cout << "Agregar clientes" << endl;
    cliMan->addClient(cli1);
    cliMan->addClient(cli2);
    cliMan->addClient(cli3);

    cout << "\nMostrar vector de clientes" << endl;
    cliMan->showClientVec();

    cout << "\nAgrega cliente creandolo desde el manager" << endl;
    cliMan->createClient(1111, "Flor", 24783746, "flor@gmail.com");

    cout << "\nBuscar cliente (1114)" << endl;
    cliMan->searchClient(1114);

    cout << "\nModificar - Actualizar un cliente (Jose a Carlos)" << endl;
    IClient *cli4 = new Client(1115, "Carlos", 38728378, "carlos@gmail.com");
    cliMan->updateClient(cli4, 1115);

    cout << "\nMostrar vector de clientes" << endl;
    cliMan->showClientVec();

    cout << "\nEliminar un cliente (1112)" << endl;
    cliMan->deleteClient(1112);

    cout << "\nMostrar vector de clientes" << endl;
    cliMan->showClientVec();

    cout << "\nNotificar al email" << endl;
    cliMan->clientEmailNotify();

    delete cli1;
    delete cli2;
    delete cli3;
    delete cli4;
    delete cliMan;

    return 0;
}
