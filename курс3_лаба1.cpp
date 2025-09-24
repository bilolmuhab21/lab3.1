#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Airport
{
private:
    string name;
    double price;  
    int place;      
    int ticket;     

public:
    Airport(string n, double price, int seats, int sold) {
        setName(n);
        setPrice(price);
        setPlace(seats);
        setTicket(sold);
    }

    void setName(const string& n) {
        name = n;
    }

    void setPrice(double p) {
        while (p > 1000000 || p <= 0) {
            cout << "Ошибка: цена должна быть > 0 и < 1000000. Введите снова: ";
            cin >> p;
        }
        price = p;
    }

    void setPlace(int seats) {
        while (seats <= 0 || seats > 500) {
            cout << "Ошибка: количество мест должно быть от 1 до 500. Введите снова: ";
            cin >> seats;
        }
        place = seats;
    }

    void setTicket(int sold) {
        while (sold < 0 || sold > place) {
            if (sold < 0) {
                cout << "Ошибка: количество проданных билетов не может быть отрицательным. Введите снова: ";
            }
            else {
                cout << "Ошибка: билетов не может быть больше, чем мест (" << place << "). Введите снова: ";
            }
            cin >> sold;
        }
        ticket = sold;
    }

    string getName() const { return name; }
    double getPrice() const { return price; }
    int getPlace() const { return place; }
    int getTicket() const { return ticket; }

    double allticketprice() const {
        return ticket * price;
    }

};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(LC_ALL, "rus");

    string name;
    double price;
    int seats, sold;

    cout << "Введите название аэропорта: ";
    getline(cin, name);

    cout << "Введите цену билета: ";
    cin >> price;

    cout << "Введите количество мест (1-500): ";
    cin >> seats;

    cout << "Введите количество проданных билетов: ";
    cin >> sold;

    Airport tablo(name, price, seats, sold);

    cout << "\n--- Итоговые данные ---\n";
    cout << "Название: " << tablo.getName() << endl;
    cout << "Цена: " << tablo.getPrice() << " руб.\n";
    cout << "Всего мест: " << tablo.getPlace() << endl;
    cout << "Продано билетов: " << tablo.getTicket() << endl;
    cout << "Выручка: " << tablo.allticketprice() << " руб.\n";

    return 0;
}
