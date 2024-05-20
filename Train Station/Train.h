#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Train
{

    public:
        int number;
        string destination;
        string departure_time;
        Train(int num, string dest, string time);
        void displayInfo();
};


