//////////////////////////////////
/*          Ahmet Polat        */
/*          150170109          */
/*          01/05/2021         */
//////////////////////////////////
#include <iostream>
#include "Agency.h"

using namespace std;

Agency::Agency(string name, int cash, int in_ticketPrice)
    :name(name), cash(cash){
        if (in_ticketPrice < 0)
        {
            cout << "Ticket price can't be negative. It is set to 0." << endl;
            this->ticketPrice = 0;
        }
        else
        {
            this->ticketPrice = in_ticketPrice;
        }          
        completedMissions = NULL;
        nextMission = NULL;
        numOfCompletedMission = 0;
        numOfNextMission = 0;
}

Agency::~Agency(){
    while (nextMission != NULL)
    {
        Mission* del1 = nextMission;
        nextMission = nextMission->next;  
        delete del1;
    }
    while (completedMissions != NULL)
    {
        Mission* del2 = completedMissions;
        completedMissions = completedMissions->next;
        delete del2;
    }
}

void Agency::addMission(const Mission& add_mission){
    if(nextMission == NULL){//add head
        nextMission = new Mission(add_mission);
    }
    else{
        Mission* iter = nextMission;
        while (iter->next != NULL)
        {
            iter = iter->next;
        }
        iter->next = new Mission(add_mission);
    }
    numOfNextMission++;
}

void Agency::executeNextMission(){

    if(nextMission != NULL){
        Mission* runMission = nextMission;
        nextMission = nextMission->next;
        runMission->next = NULL;

        //mission successfull
        if (runMission->executeMission())
        {
            if(completedMissions == NULL){
                completedMissions = runMission;
            }
            else{
                Mission* iter = completedMissions;
                while(iter->next != NULL){
                    iter = iter->next;
                }
                iter->next = runMission;
            }
        }
        //mission failed
        else{
            cout << "Agency reschedules the mission." << endl;
            if(nextMission == NULL){
                nextMission = runMission;
            }
            else{
                Mission* temp = nextMission;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = runMission;
            }            
        }
        int profit = runMission->calculateProfit(ticketPrice);
        cash += profit;
    }
    else
    {
        cout << "No available mission to execute!" << endl;
    }
}
  

ostream& operator<<(ostream& os, const Agency& obj){
    os << "Agency name: " << obj.name << ", ";
    os << "Total cash: " << obj.cash << ", ";
    os << "Ticket Price: " << obj.ticketPrice<< endl;
    os << "Next Missions:" << endl;
    if(obj.nextMission != NULL){
        Mission* iter = obj.nextMission;
        while (iter)
        {
            os << "Mission number: " << iter->getMissionNumber();
            os << " Mission name: " << iter->getName(); 
            os << " Cost: " << iter->getCost() << endl;
            iter = iter->getNext();
        }
    }
    else
        os << "No missions available." << endl;
    os << "Completed Missions:" << endl;
    if(obj.completedMissions != NULL){
        Mission* iter = obj.completedMissions;
        while (iter)
        {
            os << "Mission number: " << iter->getMissionNumber();
            os << " Mission name: " << iter->getName(); 
            os << " Cost: " << iter->getCost() << endl;
            iter = iter->getNext();
        }
    }
    else
        os << "No missions completed before." << endl;
    return os;
}
