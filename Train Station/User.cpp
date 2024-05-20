#include "User.h"
#include "Train.h"
#include "FileManager.h"
inline void User::inputDataFromKeyboard(std::vector<Train>& trains)
{
    int number;
    string destination, departure_time;
    cout << "Введите номер поезда: ";
    cin >> number;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Введите станцию назначения: ";
    getline(cin, destination);
    cout << "Введите время отправления: ";
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
    cout << "Введите номер поезда: ";
    cin >> number;
    for (Train train : trains) {
        if (train.number == number) {
            train.displayInfo();
            return;
        }
    }
    cout << "Поезд с таким номером не найден.\n";
}

inline void User::displayTrainsToDestination(const std::vector<Train>& trains)
{
    string destination;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Введите станцию назначения: ";
    getline(cin, destination);
    bool found = false;
    for (Train train : trains) {
        if (train.destination == destination) {
            train.displayInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "Поезда до заданной станции не найдены.\n";
    }
}

inline void User::start()
{
    setlocale(LC_ALL, "RU");
    vector<Train> trains;
    int choice;

    do {
        cout << "1. Ввести данные с клавиатуры\n";
        cout << "2. Загрузить данные из файла\n";
        cout << "3. Вывести информацию о всех поездах\n";
        cout << "4. Вывести информацию о поезде по номеру\n";
        cout << "5. Вывести информацию о поездах до заданной станции\n";
        cout << "6. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;
        switch (choice) {
        case 1:
            inputDataFromKeyboard(trains);
            break;
        case 2:
            FileManager::loadFromFile(trains);
            cout << "Данные из файла успешно загружены." << endl;
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
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
        }
    } while (choice != 6);
}

