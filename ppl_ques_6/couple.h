#include "boy.h"
#include "girl.h"
#include "gift.h"
#include <bits/stdc++.h>

using namespace std;



#ifndef COUPLE_H
#define COUPLE_H

class couple{

	public:
		 int happiness_of_couple;
		int compatibility_of_couple;
		string b_name;
		string g_name;
		int mnt_budget;
		int b_budget;
		vector <gift> gft;
		string b_type;
		string g_type;
		int total_price;
		int g_intl;
		int total_val;
		int lux_val;
		int b_intl;
		int b_attr;
		int g_attr;
		
		

		couple(long long int happiness_of_couple,int compatibility_of_couple,string b_name,string g_name,int mnt_budget,int b_budget,vector <gift> gft,string b_type,string g_type,int total_price,int g_intl,int total_val,int lux_val,int b_intl,int b_attr,int g_attr){

			this->b_name = b_name;
			this->g_name = g_name;
			this->mnt_budget = mnt_budget;
			this->b_budget = b_budget;
			this->happiness_of_couple = happiness_of_couple;
			this->compatibility_of_couple = compatibility_of_couple;
			this->gft = gft;
			this->b_type = b_type;
			this->g_type = g_type;
			this->total_price = total_price;
			this->g_intl = g_intl;
			this->total_val = total_val;
			this->lux_val = lux_val;
			this->b_intl = b_intl;
			this->b_attr = b_attr;	
			this->g_attr = g_attr;		
		}

};

#endif // COUPLE_H
