//////////////////////////////////
/*          Ahmet Polat        */
/*          150170109          */
/*          01/05/2021         */
//////////////////////////////////
#pragma once
#include <iostream>
#include "Mission.h"

using namespace std;

class Agency{
    private:
        string name;
        int cash;
        int ticketPrice;
        Mission* completedMissions;
        int numOfCompletedMission;
        Mission* nextMission;
        int numOfNextMission;
    public:
        Agency(string="", int=0, int=0);
        ~Agency();
        void addMission(const Mission&);
        void executeNextMission();
        friend ostream& operator<<(ostream& os, const Agency& obj);

        //getters setter
        string getName() const{
            return name;
        }
        int getCash()const{
            return cash;
        }
        int getTicketPrice()const{
            return ticketPrice;
        }
        int getNumOfCompletedMission()const{
            return numOfCompletedMission;
        }
        int getNumOfNextMission()const{
            return numOfNextMission;
        }    
        void setName(string name){
            this->name = name;
        }
        void setCash(int cash){
            this->cash = cash;
        }
        void setTicketPrice(int ticketPrice){
            this->ticketPrice = ticketPrice;
        }
};


