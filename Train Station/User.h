#pragma once
#include <vector>
#include "Train.h"
#include "FileManager.h"
class User
{
public:
	void inputDataFromKeyboard(vector<Train>& trains);
	void displayAllTrains(const vector<Train>& trains);
	void displayTrainByNumber(const vector<Train>& trains);
	void displayTrainsToDestination(const vector<Train>& trains);
	void start();
};

