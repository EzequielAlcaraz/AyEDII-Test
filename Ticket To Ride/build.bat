:: Compilacion de codigo objeto
g++ -Wall -std=c++11 -I.\include\ -c .\src\Agent.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\AgentManager.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\Client.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\ClientManager.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\JSONSerialization.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\NotifyEmail.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\Ticket.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\TicketManager.cpp
g++ -Wall -std=c++11 -I.\include\ -c main.cpp

:: Elace y generacion de binario
g++ Agent.o AgentManager.o Client.o ClientManager.o JSONSerialization.o NotifyEmail.o Ticket.o TicketManager.o main.o -o TicketToRide.exe

:: Limpieza de codigo objeto
DEL .\*.o
