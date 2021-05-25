//////////////////////////////////
/*          Ahmet Polat        */
/*          150170109          */
/*          01/05/2021         */
//////////////////////////////////
#include <iostream>
#include "Person.h"

using namespace std;

Person::Person(string name, string surname)
    :name(name), surname(surname){}


Passenger::Passenger(string name, string surname, int cash)
    :Person(name, surname){
        if(cash < 0){
            this->cash = 0;
            cout << "Passenger cash can't be negative. It is set to 0." << endl;
        }
        else{
            this->cash = cash;
        }
        this->ticket = false;
    }

Passenger::Passenger(const Passenger& add_passenger)
    :Person(add_passenger), cash(add_passenger.cash), ticket(add_passenger.ticket){}

bool Passenger::buyTicket(int ticket_price){
    if (cash >= ticket_price)
    {
        cash -= ticket_price;
        ticket = true;
        return ticket;
    }
    else{
        return ticket;
    }
}


Astronaut::Astronaut(string name, string surname, int num_of_missions)
    :Person(name, surname){
        if(num_of_missions < 0){
            cout << "Number of missions that astronaut completed can't be negative. It is set to 0." << endl;
            numMissions = 0;
        }
        else
        {
            numMissions = num_of_missions;
        }
    }

Astronaut::Astronaut(const Astronaut& add_astronaut)
    :Person(add_astronaut), numMissions(add_astronaut.numMissions){}

void Astronaut::completeMission(){
    this->numMissions += 1;
}
