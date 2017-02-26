#include <iostream>
#include <string>
#include "boy.h"
#include "gift.h"
#include "girl.h"
#include "couple.h"
#include <bits/stdc++.h>

using namespace std;

// distribute gifts given by boy to girl and makes a record in "gift_exchange.txt"

void gift_distribution(vector<couple>&Couple,vector<gift>&Gift){
	
	ofstream file;
	
	file.open("gift_exchange.txt",ios_base::app);
	file << "------------------------------------Gift Distribution-------------------------------------------" << endl;
	for(int i = 0;i < Couple.size();i++){
		bool lux = false;
		int lux_value = 0;
		int cost = 0,value = 0;
		
		file << Couple[i].b_type <<" "<< Couple[i].b_name <<"(boy) has given "; 
		if(Couple[i].b_type == "The Miser"){
			
			
			for(int j = 0;j < Gift.size();j++){
				
				if(cost + Gift[j].price <= Couple[i].mnt_budget){
					value += Gift[j].value;
					cost += Gift[j].price;
					Couple[i].gft.push_back(Gift[j]);
					file << Gift[j].type_of_gift << "("<<Gift[j].price << ") ,";
				}
			}

		}
		else if(Couple[i].b_type == "The Generous"){

			for(int j = 0;j < Gift.size();j++){
				
				if(cost + Gift[j].price <= Couple[i].b_budget){
					value += Gift[j].value;
					cost += Gift[j].price;
					Couple[i].gft.push_back(Gift[j]);
					file << Gift[j].type_of_gift << "("<<Gift[j].price << ") ,";
				}
			}
			
		}

		else{
			for(int j = 0;j < Gift.size();j++){
				
				if(cost + Gift[j].price <= Couple[i].b_budget){

					
					if(Gift[j].type_of_gift == "Luxury gift" && lux == true)
						continue;

					if(Gift[j].type_of_gift == "Luxury gift")
						lux = true;
					lux_value += Gift[j].value;	

					cost += Gift[j].price;
					Couple[i].gft.push_back(Gift[j]);
					file << Gift[j].type_of_gift << "("<<Gift[j].price << ") ,";
					
				}
			}
		}
		Couple[i].total_price = cost;
		Couple[i].total_val = value;
		file <<" gift to " << Couple[i].g_name << "(girl) worth " << Couple[i].total_price<<endl;
		file << endl;
		
	}

	file.close();
		
}

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

// generates a random file named "gifts_record.txt" which contains records of all gifts and their attributes
void generate_random_gifts(vector<gift>&Gift,int no_of_gifts){

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
	gift Newgift(price,value,type,lux_r,diffc,util_val,util_class);

	

	Gift.push_back(Newgift);
    }
    file.close();
}

// utility function for generation of random data

void utility(vector<boy> &Boy,vector<girl>&Girl,vector<gift>&Gift,int no_of_boys,int no_of_girls,int no_of_gifts){
    generate_random_boy(Boy,no_of_boys);
    generate_random_girl(Girl,no_of_girls);
    generate_random_gifts(Gift,no_of_gifts);
}

// function to make couples

void Allocate(vector<boy> &Boy,vector<girl> &Girl,vector<couple>&Couple){

    
    ofstream file;
    vector <gift> v;
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

//calculates happiness of boy

void Boy_happiness(vector<couple>&Couple){

	for(int i = 0;i < Couple.size();i++){
		if(Couple[i].b_type == "The Miser"){
			Couple[i].happiness_of_couple += (Couple[i].b_budget - Couple[i].total_price);
		}

		if(Couple[i].b_type == "The Generous")
			Couple[i].happiness_of_couple += Couple[i].happiness_of_couple ;

		else{
			Couple[i].happiness_of_couple += Couple[i].g_intl;
		} 
	}	
}

//calculates happiness of girl

void Girl_happiness(vector<couple>&Couple){
	
	for(int i = 0;i < Couple.size();i++){
		if(Couple[i].g_type == "The choosy")
			Couple[i].happiness_of_couple += (int)log(abs(Couple[i].total_price - Couple[i].mnt_budget + Couple[i].lux_val*2));
		
		else if(Couple[i].g_type == "The normal")
			Couple[i].happiness_of_couple += Couple[i].total_price - Couple[i].mnt_budget + Couple[i].total_val + Couple[i].lux_val;
		else{
			Couple[i].happiness_of_couple += (int)exp(abs(Couple[i].total_price - Couple[i].mnt_budget));
		}
	}

}

//calculates Compatibility of couple

void Compatibility(vector<couple>&Couple){
	
	for(int i = 0;i < Couple.size();i++){
		Couple[i].compatibility_of_couple =  abs(Couple[i].mnt_budget - Couple[i].b_budget) + abs(Couple[i].b_intl - Couple[i].g_intl) + abs(Couple[i].b_attr - Couple[i].g_attr) ;
		
	}
}

// sorts according to couple's happiness

void Sort_happy(vector<couple>&Couple,int k){
	ofstream file;
	int i;
	file.open("k_most_happiest_couple.txt",ios_base::app);
	file << " ----------------------------"<< k <<"_most_happiest_couple-------------------------------" << endl;
	file <<endl;
	for( i = 0;i < Couple.size();i++){
		for(int j = 0;j < Couple.size();j++){
				
			if(Couple[i].happiness_of_couple > Couple[j].happiness_of_couple){
				swap(Couple[i].happiness_of_couple,Couple[j].happiness_of_couple);
				swap(Couple[i].compatibility_of_couple,Couple[j].compatibility_of_couple);
				swap(Couple[i].b_name,Couple[j].b_name);
				swap(Couple[i].g_name,Couple[j].g_name);
				
			}
		}
	}

	for(i = 1;i <= k;i++){
		if(Couple[i].happiness_of_couple < 0){
			i--;
			break;
		}
		
		file << Couple[i].b_name << "(boy) " << Couple[i].g_name << "(girl) " << Couple[i].happiness_of_couple << endl;
	}
}

// sorts according to couple's compatibility

void Sort_Compt(vector<couple>&Couple,int k){

	int i;
	ofstream file;
	file.open("k_most_compatible_couple.txt",ios_base::app);
	
	file << " ----------------------------"<< k <<"_most_compatible_couple-------------------------------" << endl;
	file << endl;
	for( i = 0;i < Couple.size();i++){
		for(int j = 0;j < Couple.size();j++){
				
			if(Couple[i].compatibility_of_couple > Couple[j].compatibility_of_couple){
				swap(Couple[i].happiness_of_couple,Couple[j].happiness_of_couple);
				swap(Couple[i].compatibility_of_couple,Couple[j].compatibility_of_couple);
				swap(Couple[i].b_name,Couple[j].b_name);
				swap(Couple[i].g_name,Couple[j].g_name);
				
			}
		}
	}

	for(i = 0;i < k;i++){
		file << Couple[i].b_name << "(boy) " << Couple[i].g_name << "(girl) " << Couple[i].compatibility_of_couple << endl;
	}
}

int main(){

    vector<boy> Boy;
    vector<girl> Girl;
    vector<gift> Gift;
    vector<couple> Couple;
    utility(Boy,Girl,Gift,1000,1000,1000);
    Allocate(Boy,Girl,Couple);
    gift_distribution(Couple,Gift);
    Girl_happiness(Couple);
    Boy_happiness(Couple);
    Compatibility(Couple);

    Sort_happy(Couple,100);
    Sort_Compt(Couple,100);

    
   
    

}
