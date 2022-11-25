#include "../include/AgentManager.hpp"

AgentManager::AgentManager(){}

AgentManager::~AgentManager()
{
    delete age;
}

void AgentManager::createAgent(int id, std::string name, int dni, std::string email, std::string area)
{
    this->age = new Agent(id, name, dni, email, area);

    addAgent(age);
}

void AgentManager::addAgent(IAgent *agent)
{
    a_ageVec.push_back(agent);

    std::cout << "Agent " << agent->getName() << " was added" << std::endl;

    // sort(a_ageVec.begin(), a_ageVec.end());
    // El metodo addAgent tambien ordena los elementos del vector

    sort(a_ageVec.begin(), a_ageVec.end(), [] (IAgent *x, IAgent *y) {return x->getId() < y->getId(); } );
}

void AgentManager::deleteAgent(int id)
{
    int pos = findAgent(id);
    
    if (pos != -1)
    {
        // a_ageVec.erase(begin(a_ageVec) + pos); 
        a_ageVec.erase(a_ageVec.begin() + pos); 
    }
}

int AgentManager::findAgent(int id)
{
    int index = -1;

    for (size_t i = 0; i < a_ageVec.size(); i++)
    {
        if (a_ageVec[i]->getId() == id)
        {
            index = i;            
        }
    }
    
    return index++;
}

void AgentManager::searchAgent(int id)
{
    int pos = findAgent(id);

    std::cout << "ID: "<< a_ageVec[pos]->getId() << "   Name: " << a_ageVec[pos]->getName() 
        << "   DNI: " << a_ageVec[pos]->getDNI() << "   Email: " << a_ageVec[pos]->getEmail()
        << "   Area: " << a_ageVec[pos]->getArea() << std::endl;
}

void AgentManager::showAgentVec()
{
    for (size_t i = 0; i < a_ageVec.size(); i++)
    {
        std::cout << "ID: "<< a_ageVec[i]->getId() << " Name: " << a_ageVec[i]->getName() 
            << " DNI: " << a_ageVec[i]->getDNI() << " Email: " << a_ageVec[i]->getEmail() 
            << " Area: " << a_ageVec[i]->getId() << std::endl;
    }
}

void AgentManager::updateAgent(IAgent *agent, int id)
{
    int pos = findAgent(id);

    for(size_t i = 0; i < a_ageVec.size(); i++)
    {
        if( a_ageVec[i]->getId()==id)
        {
            a_ageVec.at(pos) = agent;

            // a_ageVec.erase(begin(a_ageVec) + pos); 
            // // Verificar como agregar un dato en una posicion de un vector
            // a_ageVec.push_back(agent);      
        }
    }

}

void AgentManager::agentEmailNotify()
{
    INotify *notify = new NotifyEmail();

    notify->notify();
}
