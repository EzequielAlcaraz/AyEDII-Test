#ifndef AGENTMANAGER_HPP
#define AGENTMANAGER_HPP

#include "Agent.hpp"
#include "NotifyEmail.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

class AgentManager
{
    private:
        std::vector<IAgent*> a_ageVec;
        IAgent *age;

    public:
        AgentManager();
        virtual ~AgentManager();

        void createAgent(int id, std::string name, int DNI, std::string email, std::string area);
        void addAgent(IAgent *agent);
        void deleteAgent(int id);
        int findAgent(int id);
        void searchAgent(int id);
        void showAgentVec();
        void updateAgent(IAgent *agent, int id);
        void agentEmailNotify();
};  


#endif //AGENTMANAGER_HPP