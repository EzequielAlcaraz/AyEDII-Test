#include <iostream>

#include "../include/IClient.hpp"
#include "../include/Client.hpp"
#include "../include/ClientManager.hpp"
#include "../include/IAgent.hpp"
#include "../include/Agent.hpp"
#include "../include/AgentManager.hpp"
#include "../include/Ticket.hpp"
#include "../include/TicketManager.hpp"

#include "../include/JSONSerialization.hpp"

using namespace std;

int main()
{
    TicketManager *ticketMan = new TicketManager;
    JSONSerialization JSONManager;

    
    IClient *cli1 = new Client(1114, "Lucas", 42289337, "lucas@gmail.com"); 
    IAgent *age1 = new Agent(1115, "Jose", 38782983, "jose@gmail.com", "Gestion");

    Ticket tick1(2224, cli1, age1, "No funciona la pagina inicial", "12/11/2022");
    Ticket tick2(2225, cli1, age1, "No carga complemento", "12/11/2022");
    Ticket tick3(2222, cli1, age1, "Faltan elementos graficos", "12/11/2022");

    JSONManager.saveJSONTicket(tick1);
    JSONManager.saveJSONTicket(tick2);
    JSONManager.saveJSONTicket(tick3);

    cout << "Agregar Ticket" << endl;
    ticketMan->addTicket(tick1);
    ticketMan->addTicket(tick2);
    ticketMan->addTicket(tick3);

    cout << "\nMostrar vector de Tickets" << endl;
    ticketMan->showTicketVec();

    cout << "\nAgrega ticket creandolo desde el manager" << endl;
    ticketMan->createTicket(2221, cli1, age1, "Se necesita boton de cerrar sesion", "13/11/2022");

    cout << "\nBuscar ticket (2224)" << endl;
    ticketMan->searchTicket(2224);

    cout << "\nModificar - Actualizar un ticket (Cambio de mensaje)" << endl;
    Ticket tick4(2225, cli1, age1, "Incorporar barra de busqueda", "12/11/2022");
    ticketMan->updateTicket(tick4, 2225);

    cout << "\nMostrar vector de tickets" << endl;
    ticketMan->showTicketVec();

    cout << "\nEliminar un ticket (1112)" << endl;
    ticketMan->deleteTicket(2222);

    cout << "\nMostrar vector de tickets" << endl;
    ticketMan->showTicketVec();

    cout << "\n\n\n" << endl;
    JSONManager.readJSONData();

    delete age1;
    delete cli1;
    delete ticketMan;

    return 0;
}

