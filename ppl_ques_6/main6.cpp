#include <iostream>
#include <string>
#include "boy.h"
#include "gift.h"
#include "girl.h"
#include "couple.h"
#include <bits/stdc++.h>

using namespace std;


// generates a random file named "boys_record.txt" which contains records of all boys and their attributes

void generate_random_boy(vector<boy>&Boy,int no_of_boys){

    int i,j,attractiveness,intelligence,budget,min_attraction_req;
    vector<gift> v;
    ofstream file;
    char type_of_committed_boy[15],type[][15] = {"The Miser","The Generous","The Geeks"};

    file.open("boys_record.txt",ios_base::app);

    if(!file.is_open())
        cout << "unable to open file" << endl;

    for(j = 0;j < no_of_boys;j++){


        file << "boy " << j+1 << " :"<<endl;
        char name[11];
        char str[] = "abcdefghijklmnopqrstuvwxyz";
        for(i = 0;i < 10;i++){
            name[i] = str[rand()%26];
        }

        name[i] = '\0';


        attractiveness = rand()%10 + 1;
        intelligence = rand()%10 + 1;
        budget = rand()%10000 + 1;
        min_attraction_req = rand()%10 + 1;

        strcpy(type_of_committed_boy,type[rand()%3]);

        file << "name : " << name << endl;
        file << "attractiveness : " << attractiveness << endl;
        file << "intelligence : " << intelligence <<endl;
        file << "budget : " << budget <<endl;
        file << "min_attraction_req : " << min_attraction_req << endl;
        file << "type_of_committed_boy : " << type_of_committed_boy << endl;


        file << endl;
	
        boy Newboy(name,intelligence,budget,attractiveness,min_attraction_req,false,type_of_committed_boy,"",v);
	
        Boy.push_back(Newboy);
    }
    file.close();
}

// generates a random file named "girls_record.txt" which contains records of all girls and their attributes

void generate_random_girl(vector<girl>&Girl,int no_of_girls){

    int i,j,attractiveness,intelligence,mnt_budget;
    ofstream file;
    char type_of_committed_girl[15],type[][15] = {"The choosy","The normal","The desperate"};
    char criteria_for_choosing_boys[20],criteria[][20] = {"Most attractive","Most intelligent","Most rich"};

    file.open("girls_record.txt",ios_base::app);
    if(!file.is_open())
        cout << "unable to open file" << endl;
    for(j = 0;j < no_of_girls;j++){

        file << "girl " << j+1 << " :"<<endl;
        char name[11];
        char str[] = "abcdefghijklmnopqrstuvwxyz";
        for(i = 0;i < 10;i++){
            name[i] = str[rand()%26];
        }

        name[i] = '\0';

        attractiveness = rand()%10 + 1;
        intelligence = rand()%10 + 1;
        mnt_budget = rand()%10000 + 1;
        strcpy(criteria_for_choosing_boys,criteria[rand()%3]);

        strcpy(type_of_committed_girl,type[rand()%3]);

        file << "name : " << name << endl;
        file << "attractiveness : " << attractiveness << endl;
        file << "intelligence : " << intelligence <<endl;
        file << "maintainence_budget : " << mnt_budget<<endl;
        file << "criteria_for_choosing_boys : " << criteria_for_choosing_boys << endl;
        file << "type_of_committed_girl : " << type_of_committed_girl << endl;

        file << endl;

        girl Newgirl(name,attractiveness,mnt_budget,intelligence,criteria_for_choosing_boys,false,type_of_committed_girl,"");
	
        Girl.push_back(Newgirl);

    }
    file.close();
}

// utility function for generation of random data

void utility(vector<boy> &Boy,vector<girl>&Girl,vector<gift>&Gift,int no_of_boys,int no_of_girls,int no_of_gifts){
    generate_random_boy(Boy,no_of_boys);
    generate_random_girl(Girl,no_of_girls);
    
}

/*function to make couples if new_allocation = true then it allocates couple before breakup 
 else after breakup */

void Allocate(vector<boy> &Boy,vector<girl> &Girl,vector<couple>&Couple,bool new_allocation,int t){

    
    ofstream file;
    vector <gift> v;
    if(new_allocation == false)
    	file.open("log.txt",ios_base::app);
    else
    	file.open("new_day_to_day_allocation_after_breakup.txt",ios_base::app);
    int i,j,type,index,Max,count = 0;
	
    if(new_allocation == true)
        file << "-------------------------------------------Day " << t << " allocations ----------------------------------------------" << endl << endl;;
    
    for(i = 0;i < Girl.size();i++){
	
	if(Girl[i].Iscommitted)
		continue;
	Max = 0,index = -1,type = -1;
	
        if(Girl[i].criteria_for_choosing_boys == "Most attractive")
            type = 0;

        else if(Girl[i].criteria_for_choosing_boys == "Most intelligent")
            type = 1;
        else
            type = 3;


        for(j = 0;j < Boy.size();j++){
                if(!Boy[j].Iscommitted){
			
		    
                    if(Boy[j].check_dating_req(Boy[j],Girl[i])){
			
			if(type == 0){
				if(Boy[j].attractiveness > Max){
					Max = Boy[j].attractiveness;
					index = j;
				}
			}

			if(type == 1){
				if(Boy[j].intelligence > Max){
					Max = Boy[j].intelligence;
					index = j;
				}
			}

			if(type == 3){
				if(Boy[j].budget > Max){
					Max = Boy[j].budget;
					index = j;
				}
			}
                    }
		

                }

        }
	if(index == -1)
		file << Girl[i].name << "(girl) requirements are damn too high.So now She is single in this valentine season" << endl;
	else{
		Girl[i].Iscommitted = true;
		Boy[index].Iscommitted = true;
		Boy[index].gf_name = Girl[i].name;
		Girl[i].bf_name = Boy[index].name;
		count++;
		file <<"timestamp : "<< count <<"  "<<Boy[index].name << "(boy) committed with " <<Girl[i].name <<"(girl)"<< endl;
		couple Newcp(0,0,Boy[index].name,Girl[i].name,Girl[i].mnt_budget,Boy[index].budget,v,Boy[index].type_of_committed_boy,Girl[i].type_of_committed_girl,0,Girl[i].intelligence,0,0,Boy[index].intelligence,Boy[index].attractiveness,Girl[i].attractiveness);
		

		Couple.push_back(Newcp);
	}
    }
}


// performs breakup  

void break_up(vector<couple> &Couple,vector<boy> &Boy,vector<girl> &Girl,int l,int t){
	ofstream file;
	int i,j,k,count = 0;
	file.open("day_to_day_break_up.txt",ios_base::app);

    file << "--------------------------------------Day " << t << " breakups ---------------------------------------------------" << endl << endl;
	for(i = Couple.size()-1;i >= 0;i--){
		
		if(count == l)
			break;
		count++;
		for(j = 0;j < Boy.size();j++){
			if(Boy[j].name == Couple[i].b_name){
				//cout << "ok" << endl;
				for(k = 0;k < Girl.size();k++){
					if(Girl[k].name == Couple[i].g_name){
						file << Girl[k].name << "(girl)  " << Boy[j].name << "(boy) broke_up in this valentine season. Why the girls requirements are too high to be fulfilled?" << endl;
						Boy[j].gf_name = "";
						Boy[j].Iscommitted = false;
						Girl[k].bf_name = "";
						Girl[k].Iscommitted = false;
						Couple.pop_back();
					}
				}
			}
		}
	}
}

int main(){

    int t = 10,i;
    vector<boy> Boy;
    vector<girl> Girl;
    vector<gift> Gift;
    vector<couple> Couple;
    utility(Boy,Girl,Gift,10000,1000,1000); // utility function for generation of random data
    Allocate(Boy,Girl,Couple,false,-1);  /*function to make couples before breakup */
    for(i = 1;i <= t;i++){ // perfoming 10 days breakup 

        break_up(Couple,Boy,Girl,50,i); //performs breakup
   	    Allocate(Boy,Girl,Couple,true,i); /*function to make couples after breakup */
    }

}
