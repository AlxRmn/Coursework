#include "Train.h"

using namespace std;
inline Train::Train(int num, string dest, string time)
	: number(num), destination(dest), departure_time(time) {};

inline void Train::displayInfo()
{
	cout << "Номер поезда: " << number
		<< ", Станция назначения: " << destination
		<< ", Время отправления: " << departure_time << endl;
}
