//////////////////////////////////
/*          Ahmet Polat        */
/*          150170109          */
/*          01/05/2021         */
//////////////////////////////////
#include <iostream>
#include "Mission.h"

using namespace std;

Mission::Mission(string name, int cost, int faultProbability)
    :cost(cost), faultProbability(faultProbability){
        passengerList = nullptr;
        crewList = nullptr;
        numOfPassenger = 0;
        numOfCrew = 0;

        numMissions += 1;
        this->missionNumber = numMissions;
        
        completed = false;
        next = NULL;

        if(name.length() == 5){
            if(name[0]>=65 && name[0]<=90 && name[1]>=65 && name[1]<=90 && name[2]=='-' && name[3]>=48 && name[3]<=57 && name[4]>=48 && name[4]<=57){
                this->name = name;
            }
            else{
                cout << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl;
                this->name = "AA-00";
            }
        }
        else{
            cout << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl;
            this->name = "AA-00";
        }
    }

Mission::~Mission(){
    delete []passengerList;
    delete []crewList;
    next = NULL;
}

Mission::Mission(const Mission& add_mission)
    :name(add_mission.name), cost(add_mission.cost), faultProbability(add_mission.faultProbability){
    missionNumber = add_mission.missionNumber;
    completed = add_mission.completed;
    numOfPassenger = add_mission.numOfPassenger;
    numOfCrew = add_mission.numOfCrew;
    next = NULL;

    passengerList = new Passenger[add_mission.numOfPassenger];
    for (int i = 0; i < add_mission.numOfPassenger; i++)
    {
        passengerList[i] = add_mission.passengerList[i];
    }
    crewList = new Astronaut[add_mission.numOfCrew];
    for (int i = 0; i < add_mission.numOfCrew; i++)
    {
        crewList[i] = add_mission.crewList[i];
    }
}

Mission& Mission::operator+=(const Passenger* add_passenger){
    if(add_passenger->getTicket()){
        numOfPassenger++;
        Passenger* temp = new Passenger[numOfPassenger];
        for(int i = 0; i < numOfPassenger-1; i++){
            temp[i] = passengerList[i];
        }
        temp[numOfPassenger-1].setName(add_passenger->getName());
        temp[numOfPassenger-1].setSurname(add_passenger->getSurname());
        temp[numOfPassenger-1].setCash(add_passenger->getCash());
        temp[numOfPassenger-1].setTicket(add_passenger->getTicket());
        if (passengerList != nullptr)
        {
            delete []passengerList;
        }
        passengerList = temp;
    }
    else
        cout << "Passenger " << add_passenger->getName() << " " << add_passenger->getSurname() << " does not have a valid ticket!" << endl;
    return *this;
}

Mission& Mission::operator+=(const Astronaut* add_astronaut){
    numOfCrew++;
    Astronaut* temp = new Astronaut[numOfCrew];
    for(int i = 0; i < numOfCrew-1; i++){
        temp[i] = crewList[i];
    }
    temp[numOfCrew-1].setName(add_astronaut->getName());
    temp[numOfCrew-1].setSurname(add_astronaut->getSurname());
    temp[numOfCrew-1].setNumMissions(add_astronaut->getNumMissions());
    if (crewList != nullptr)
    {
        delete []crewList;
    }
    crewList = temp;
    return *this;
}

bool Mission::executeMission(){
    int successRate = rand() % 100;
    if (successRate > faultProbability)
    {
        completed = true;
        cout << "MISSION "<< name <<" SUCCESSFUL!" << endl;
        for (int i = 0; i < numOfCrew; i++)
        {
            crewList[i].completeMission();
        }
        for (int i = 0; i < numOfCrew; i++)
        {
            cout << "Astronaut " ;
            cout << crewList[i].getName() << " " << crewList[i].getSurname();
            cout << " successfully completed " << crewList[i].getNumMissions() << " missions." << endl;
        }
    }
    else{
        cout << "MISSION "<< name <<" FAILED!" << endl;
    }
    return completed;
}

int Mission::calculateProfit(int ticketPrice){
    int profit = 0;
    if (completed)
    {
        profit += numOfPassenger * ticketPrice;
    }
    profit -= cost;
    return profit;
}