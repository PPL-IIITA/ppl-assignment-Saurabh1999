#include <string>
#include <math.h>
#include "girl.h"
#include "gift.h"
#include <vector>

using namespace std;

#ifndef BOY_H
#define BOY_H


class boy
{
    public:

    string name;
    int attractiveness;
    int intelligence;
    int budget;
    int min_attraction_req;
    bool Iscommitted;
    string type_of_committed_boy;
    string gf_name;
    vector<gift> gift_for_girl;



        boy(string name,int intelligence,int budget,int attractiveness,int min_attraction_req,bool Iscommitted,string type_of_committed_boy,string gf_name,vector<gift>gift_for_girl)
        {
		
	
            this->name = name;
            this->intelligence = intelligence;
            this->budget = budget;
	    this->attractiveness = attractiveness;
            this->min_attraction_req = min_attraction_req;
            this->Iscommitted = Iscommitted;
            this->type_of_committed_boy = type_of_committed_boy;
            this->gf_name = gf_name;
	    this->gift_for_girl = gift_for_girl;

        }

        bool check_dating_req(boy,girl);




};

#endif // BOY_H
