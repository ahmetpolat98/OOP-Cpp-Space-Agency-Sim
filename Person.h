//////////////////////////////////
/*          Ahmet Polat        */
/*          150170109          */
/*          01/05/2021         */
//////////////////////////////////
#pragma once
#include <iostream>

using namespace std;


class Person{
    protected:
        string name, surname;

    public:
        Person(string="", string="");

        //getters setters
        string getName() const{
            return name;
        }
        string getSurname() const{
            return surname;
        }
        void setName(string name){
            this->name = name;
        }
        void setSurname(string surname){
            this->surname = surname;
        }
};

class Passenger:public Person{
    private:
        int cash;
        bool ticket;

    public:
        Passenger(string="", string="", int=0);
        Passenger(const Passenger&);
        bool buyTicket(int);
    
        //getters setters
        int getCash() const{
            return cash;
        }
        bool getTicket() const{
            return ticket;
        }
        void setCash(int cash){
            this->cash = cash;
        }
        void setTicket(bool ticket){
            this->ticket = ticket;
        }
};

class Astronaut:public Person{
    private:
        int numMissions;

    public:
        Astronaut(string="", string="", int=0);
        Astronaut(const Astronaut&);
        void completeMission();

        //getters setter
        int getNumMissions() const{
            return numMissions;
        }
        void setNumMissions(int numMissions){
            this->numMissions = numMissions;
        }
};

//
