#include <string>
#include <iostream>

using namespace std;

#ifndef GIFT_H
#define GIFT_H


class gift
{
    public:
    	gift(int price,int value,string type_of_gift,int luxury_rating,int difficulty_to_obtain_gift,int utility_value,char utility_class)
	{
    		this->price = price;
    		this->value = value;
    		this->type_of_gift = type_of_gift;
   		this->luxury_rating = luxury_rating;
    		this->difficulty_to_obtain_gift = difficulty_to_obtain_gift;
    		this->utility_value = utility_value;
    		this->utility_class = utility_class;

}

    
        int price;
        int value;
        string type_of_gift;
        int luxury_rating;
        int difficulty_to_obtain_gift;
        int utility_value;
        string utility_class;

};

#endif // GIFT_H
