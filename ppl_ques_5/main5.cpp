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
					file << Gift[j].type_of_gift  << "("<<Gift[j].price << ") ,";
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

// function to make couples using new alternate choosing algorithm which generates New_Allocation_algorithm.txt

void New_Allocate(vector<boy> &Boy,vector<girl> &Girl,vector<couple>&Couple,bool new_allocation){

    
    ofstream file;
    vector <gift> v;
    if(new_allocation == false)
    	file.open("New_alternate_Allocation_algorithm.txt",ios_base::app);
    else
    	file.open("new_allocation.txt",ios_base::app);
    int i,j,type,index,Max,count = 0,flag = 0,sz;
    sz = min(Girl.size(),Boy.size());

    while(sz--){

	if(flag == 0){
    for(i = 0;i < Girl.size() && flag == 0;i++){
	
		

		if(Girl[i].Iscommitted)
			continue;
	
		for(j = 0;j < Boy.size();j++){
                if(!Boy[j].Iscommitted){
			
		    		if(Boy[j].check_dating_req(Boy[j],Girl[i])){
						Girl[i].Iscommitted = true;
						Boy[j].Iscommitted = true;
						Boy[j].gf_name = Girl[i].name;
						Girl[i].bf_name = Boy[j].name;
						count++;
						couple Newcp(0,0,Boy[j].name,Girl[i].name,Girl[i].mnt_budget,Boy[j].budget,v,Boy[j].type_of_committed_boy,Girl[i].type_of_committed_girl,0,Girl[i].intelligence,0,0,Boy[j].intelligence,Boy[j].attractiveness,Girl[i].attractiveness);
		
						file << "girl '" << Girl[i].name << "' chooses boy '" << Boy[j].name << "'" <<endl;
						Couple.push_back(Newcp);
						flag = 1;
						break;
                    }
				}
            }
		
		
	
    }
    
	}
	else{
    for(i = 0;i < Boy.size() && flag == 1;i++){
	
		

		if(Boy[i].Iscommitted)
			continue;
	
		for(j = 0;j < Girl.size();j++){
                if(!Girl[j].Iscommitted){
			
		    		if(Boy[i].check_dating_req(Boy[i],Girl[j])){
						Girl[j].Iscommitted = true;
						Boy[i].Iscommitted = true;
						Boy[i].gf_name = Girl[j].name;
						Girl[j].bf_name = Boy[i].name;
						count++;
						couple Newcp(0,0,Boy[i].name,Girl[j].name,Girl[j].mnt_budget,Boy[i].budget,v,Boy[i].type_of_committed_boy,Girl[j].type_of_committed_girl,0,Girl[j].intelligence,0,0,Boy[i].intelligence,Boy[i].attractiveness,Girl[j].attractiveness);
		
						file << "boy '" << Boy[i].name << "' chooses girl '" << Girl[j].name << "'" << endl;
						Couple.push_back(Newcp);
						flag = 0;
						break;
                    }
				}
            }
		
			
		
		flag = 0;
    }
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
	file.open("k_most_happiest_couple_using_new_alternate_allocation_algorithm.txt",ios_base::app);
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


int main(){

    vector<boy> Boy;
	vector<girl> Girl;
    vector<gift> Gift;
    vector<couple> Couple;

    utility(Boy,Girl,Gift,10000,1000,1000); // utility function for generation of random data
	
	New_Allocate(Boy,Girl,Couple,false); // function to make couples using new alternate choosing algorithm which generates New_Allocation_algorithm.txt

    gift_distribution(Couple,Gift); // distribute gifts given by boy to girl and makes a record in "gift_exchange.txt"

    Girl_happiness(Couple); // Calculate girl happiness
    Boy_happiness(Couple);  // Calculate boy happiness
    
    
    
    Sort_happy(Couple,100); // give 100 most happiest couple

   
   
    

}
