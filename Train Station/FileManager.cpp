#include "FileManager.h"
#include "Train.h"

inline void FileManager::loadFromFile(vector<Train>& trains)
{
    ifstream file("trains.txt");
    int number;
    string destination, departure_time;

    while (file >> number >> destination >> departure_time) {
        trains.push_back(Train(number, destination, departure_time));
    }
    file.close();
}
