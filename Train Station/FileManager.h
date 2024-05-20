#pragma once
#include "Train.h"
#include <fstream>
class FileManager
{
public:
	static void loadFromFile(vector<Train>& trains);
};

