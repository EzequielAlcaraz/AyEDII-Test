#include "../include/JSONSerialization.hpp"

JSONSerialization::JSONSerialization(){}

JSONSerialization::~JSONSerialization(){}

void JSONSerialization::saveJSONClient(IClient *client)
{
    j_storage["id"] = client->getId();
    j_storage["name"] = client->getName();
    j_storage["dni"] = client->getDNI();
    j_storage["email"] = client->getEmail();

    std::ofstream myFile;
    myFile.open("../temp/client.json", std::ios::app);
    myFile << std::setw(4) << j_storage << std::endl;
    myFile.close();
}

void JSONSerialization::saveJSONAgent(IAgent *agent)
{
    j_storage["id"] = agent->getId();
    j_storage["area"] = agent->getArea();
    j_storage["name"] = agent->getName();
    j_storage["dni"] = agent->getDNI();
    j_storage["email"] = agent->getEmail();

    std::ofstream myFile;
    myFile.open("../temp/agent.json", std::ios::app);
    myFile << std::setw(4) << j_storage << std::endl;
    myFile.close();
}

void JSONSerialization::saveJSONTicket(Ticket ticket)
{
    IClient *cli = new Client();
    IAgent *age = new Agent();
    cli = ticket.getClient();
    age = ticket.getAgent();

    j_storage["id"] = ticket.getId();
    j_storage["client"] = cli->getName();
    j_storage["agent"] = age->getName();
    j_storage["message"] = ticket.getMessage();
    j_storage["date"] = ticket.getDate();

    j_storage = json{{"id", ticket.getId()}, {"client", cli->getName()}, {"agent", age->getName()}, {"message", ticket.getMessage()}, {"date", ticket.getDate()}};

    std::ofstream myFile;
    myFile.open("../temp/ticket.json", std::ios::app);
    myFile << std::setw(4) << j_storage << std::endl;
    myFile.close();
}

void JSONSerialization::readJSONData()
{
    std::ifstream myJSON;
    myJSON.open("../temp/ticket.json");
    json j;
    myJSON >> j;
    for(auto& el : j.items()){
        std::cout << j["message"] << std::endl;
    }
    // std::cout << j_storage["name"];
    myJSON.close();

    // std::ifstream f("ticket.js");
    // json j;
    // f >> j;
    // f.close();
}
