#include <iostream>
#include <string>
#include "boy.h"
#include "gift.h"
#include "girl.h"
#include <bits/stdc++.h>

using namespace std;

void generate_random_boy(vector<boy>&Boy,int no_of_boys){

    int i,j,attractiveness,intelligence,budget,min_attraction_req;
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
	
        boy Newboy(name,intelligence,budget,attractiveness,min_attraction_req,false,type_of_committed_boy,"");
	
        Boy.push_back(Newboy);
    }
    file.close();
}

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

void generate_random_gifts(int no_of_gifts){

    int price,value,i,lux_r,diffc,util_val;
    ofstream file;
    file.open("gifts_record.txt",ios_base::app);
    char type[15],type_of_gifts[][25] = {"Essential gift","Luxury gift","Utility gift"};
    char Class[] = "ABC",util_class;
    for(i = 1;i <= no_of_gifts;i++){
        strcpy(type,type_of_gifts[rand()%3]);
        price = rand()%100 + 1;
        value = rand()%10 + 1;
        file <<"gift - " << i << endl;
        file << "type : " << type << endl;
        file << "price : " << price << endl;
        file << "value : " << value << endl;

        if(type[0] == 'L'){
            lux_r = rand()%10 + 1;
            diffc = rand()%10 + 1;
            file << "luxury_rating : " << lux_r<< endl;
            file << "difficulty_to_obtain_the_gift :" << diffc << endl;
        }
        else if(type[0] == 'U'){
            util_val = rand()% 10 + 1;
            util_class  = Class[rand()%3];
            file << "utility value : " << util_val << endl;
            file << "utility class : " << util_class << endl;
        }

        file << endl;
    }
    file.close();
}

void utility(vector<boy> &Boy,vector<girl>&Girl,int no_of_boys,int no_of_girls,int no_of_gifts){
    generate_random_boy(Boy,no_of_boys);
    generate_random_girl(Girl,no_of_girls);
    generate_random_gifts(no_of_gifts);
}

void Allocate(vector<boy> &Boy,vector<girl> &Girl){

    ofstream file;
    file.open("log.txt",ios_base::app);
    int i,j,type,index,Max,count = 0;
	
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
			//cout<<"boy " << Boy[j].attractiveness << " " <<Boy[j].intelligence <<" " <<Boy[j].budget << endl;
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
		file <<"timestamp : "<< count <<"  "<<Boy[index].name << "(boy) commited with " <<Girl[i].name <<"(girl)"<< endl;
	}
    }
}

int main(){

    vector<boy> Boy;
    vector<girl> Girl;
    utility(Boy,Girl,10000,10000,10000);
    Allocate(Boy,Girl);

}
