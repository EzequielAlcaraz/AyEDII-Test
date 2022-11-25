#include <iostream>
#include <conio.h>

#include <IClient.hpp>
#include <Client.hpp>
#include <ClientManager.hpp>
#include <IAgent.hpp>
#include <Agent.hpp>
#include <AgentManager.hpp>
#include <Ticket.hpp>
#include <TicketManager.hpp>
#include <INotify.hpp>
#include <NotifyEmail.hpp>

#include <JSONSerialization.hpp>

using namespace std;

void clientTest();
void agentTest();
void ticketTest();
void ticketTestShow();

int main()
{
    cout << "---->  Client Test: \n" << endl;
    clientTest();

    cout << "\n\n---->  Agent Test: \n" << endl;
    agentTest();

    cout << "\n\n---->  Ticket Test: \n" << endl;
    ticketTest();

    getch();

    return 0;
}

void clientTest()
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
}

void agentTest()
{
    AgentManager *ageMan = new AgentManager;
    JSONSerialization JSONManager;

    IAgent *age1 = new Agent(1114, "Lucas", 42289337, "lucas@gmail.com", "Supervision");
    IAgent *age2 = new Agent(1115, "Jose", 38782983, "jose@gmail.com", "Gestion");
    IAgent *age3 = new Agent(1112, "Maria", 28983784, "maria@gmail.com", "Mantenimiento");

    JSONManager.saveJSONAgent(age1);
    JSONManager.saveJSONAgent(age2);
    JSONManager.saveJSONAgent(age3);

    cout << "Agregar Agentes" << endl;
    ageMan->addAgent(age1);
    ageMan->addAgent(age2);
    ageMan->addAgent(age3);

    cout << "\nMostrar vector de agentes" << endl;
    ageMan->showAgentVec();

    cout << "\nAgrega agente creandolo desde el manager" << endl;
    ageMan->createAgent(1231, "Flor", 24783746, "flor@gmail.com", "Supervision");

    cout << "\nBuscar agente (1114)" << endl;
    ageMan->searchAgent(1114);

    cout << "\nModificar - Actualizar un agente (Jose a Carlos)" << endl;
    IAgent *age4 = new Agent(1115, "Carlos", 38728378, "carlos@gmail.com", "Gestion");
    ageMan->updateAgent(age4, 1115);

    cout << "\nMostrar vector de agentes" << endl;
    ageMan->showAgentVec();

    cout << "\nEliminar un agente (1112)" << endl;
    ageMan->deleteAgent(1112);

    cout << "\nMostrar vector de agentes" << endl;
    ageMan->showAgentVec();

    cout << "\nNotificar al email" << endl;
    ageMan->agentEmailNotify();

    delete age1;
    delete age2;
    delete age3;
    delete age4;
    delete ageMan;
}

void ticketTest()
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

    cout << "\n" << endl;
    JSONManager.readJSONData();

    delete age1;
    delete cli1;
    delete ticketMan;

}
