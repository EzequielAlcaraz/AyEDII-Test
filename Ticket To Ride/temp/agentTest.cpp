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

    return 0;
}
