#include "User.h"
#include "Train.h"
#include "FileManager.h"
inline void User::inputDataFromKeyboard(std::vector<Train>& trains)
{
    int number;
    string destination, departure_time;
    cout << "������� ����� ������: ";
    cin >> number;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "������� ������� ����������: ";
    getline(cin, destination);
    cout << "������� ����� �����������: ";
    getline(cin, departure_time);
    trains.push_back(Train(number, destination, departure_time));
}

inline void User::displayAllTrains(const std::vector<Train>& trains)
{
    for (Train train : trains) {
        train.displayInfo();
    }
}

inline void User::displayTrainByNumber(const vector<Train>& trains)
{
    int number;
    cout << "������� ����� ������: ";
    cin >> number;
    for (Train train : trains) {
        if (train.number == number) {
            train.displayInfo();
            return;
        }
    }
    cout << "����� � ����� ������� �� ������.\n";
}

inline void User::displayTrainsToDestination(const std::vector<Train>& trains)
{
    string destination;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "������� ������� ����������: ";
    getline(cin, destination);
    bool found = false;
    for (Train train : trains) {
        if (train.destination == destination) {
            train.displayInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "������ �� �������� ������� �� �������.\n";
    }
}

inline void User::start()
{
    setlocale(LC_ALL, "RU");
    vector<Train> trains;
    int choice;

    do {
        cout << "1. ������ ������ � ����������\n";
        cout << "2. ��������� ������ �� �����\n";
        cout << "3. ������� ���������� � ���� �������\n";
        cout << "4. ������� ���������� � ������ �� ������\n";
        cout << "5. ������� ���������� � ������� �� �������� �������\n";
        cout << "6. �����\n";
        cout << "�������� ��������: ";
        cin >> choice;
        switch (choice) {
        case 1:
            inputDataFromKeyboard(trains);
            break;
        case 2:
            FileManager::loadFromFile(trains);
            cout << "������ �� ����� ������� ���������." << endl;
            break;
        case 3:
            displayAllTrains(trains);
            break;
        case 4:
            displayTrainByNumber(trains);
            break;
        case 5:
            displayTrainsToDestination(trains);
            break;
        case 6:
            cout << "����� �� ���������.\n";
            break;
        default:
            cout << "�������� �����. ����������, ���������� �����.\n";
        }
    } while (choice != 6);
}

