#include <string>
#include <iostream>

using namespace std;

#ifndef GIFT_H
#define GIFT_H


class gift
{
    public:
        gift(int,int,string,int,int,int,string);

    private:
        int price;
        int value;
        string type_of_gift;
        int luxury_rating;
        int difficulty_to_obtain_gift;
        int utility_value;
        string utility_class;

};

#endif // GIFT_H
