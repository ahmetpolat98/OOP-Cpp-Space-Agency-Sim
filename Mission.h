//////////////////////////////////
/*          Ahmet Polat        */
/*          150170109          */
/*          01/05/2021         */
//////////////////////////////////
#pragma once
#include <iostream>
#include "Person.h"

using namespace std;

class Mission{
    friend class Agency;
    private:
        static int numMissions;
        string name;
        int missionNumber;
        int cost;
        int faultProbability;
        bool completed;
        Passenger *passengerList;
        int numOfPassenger;
        Astronaut *crewList;
        int numOfCrew;
        Mission *next;

    public:
        Mission(string="", int=0, int=0);
        Mission(const Mission&);
        ~Mission();
        Mission& operator+=(const Passenger*);
        Mission& operator+=(const Astronaut*);
        bool executeMission();
        int calculateProfit(int);

        //getters setters
        string getName() const{
            return name;
        }
        int getMissionNumber() const{
            return missionNumber;
        }
        int getCost() const{
            return cost;
        }
        int getFaultProbability() const{
            return faultProbability;
        }
        bool getCompleted() const{
            return completed;
        }
        int getNumOfPassenger() const{
            return numOfPassenger;
        }
        int getNumOfCrew() const{
            return numOfCrew;
        }
        Mission* getNext()const{
            return next;
        }

        void setName(string name){
            this->name = name;
        }
};



