#include <iostream>
#include <string>
using namespace std;

#ifndef GIRL_H
#define GIRL_H


class girl
{
    public:
        
        string name;
        int attractiveness;
        int mnt_budget;
        int intelligence;
        string criteria_for_choosing_boys;
        bool Iscommitted;
        string type_of_committed_girl;
        string bf_name;

        girl(string name,int attractiveness,int mnt_budget,int intelligence,string criteria_for_choosing_boys,bool Iscommitted,string type_of_committed_girl,string bf_name)
        {
            this->name = name;
            this->attractiveness = attractiveness;
            this->mnt_budget = mnt_budget;
            this->intelligence = intelligence;
            this->criteria_for_choosing_boys = criteria_for_choosing_boys;
            this->Iscommitted = Iscommitted;
            this->type_of_committed_girl = type_of_committed_girl;
            this->bf_name = bf_name;
        }


        

};

#endif // GIRL_H
