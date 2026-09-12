#include <iostream>
using namespace std;

class Vehicle {
public:
    int no;
    float rate;
    bool rented;

    Vehicle(int n, float r) {
        no = n;
        rate = r;
        rented = false;
    }

    virtual float calculateRentalCost(int days) {
        return rate * days;
    }

    virtual void displayInfo() = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
    int seats;

public:
    Car(int n, float r, int s) : Vehicle(n, r) {
        seats = s;
    }

    float calculateRentalCost(int days) {
        float cost = rate * days;
        if (days >= 3)
            cost = cost * 1.10;
        return cost;
    }

    void displayInfo() {
        cout << "Car  No:" << no << " Rate:" << rate
             << " Seats:" << seats
             << " [" << (rented ? "Rented" : "Available") << "]\n";
    }
};

class Bike : public Vehicle {
    bool helmet;

public:
    Bike(int n, float r, bool h) : Vehicle(n, r) {
        helmet = h;
    }

    float calculateRentalCost(int days) {
        float cost = rate * days;

        if (!helmet) {
            char ch;
            cout << "Need helmet? (y/n): ";
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
                cost += 50;
        }
         else {
            cout << "Error\n";
          }

        return cost;
    }

    void displayInfo() {
        cout << "Bike No:" << no << " Rate:" << rate
             << " Helmet:" << (helmet ? "Yes" : "No")
             << " [" << (rented ? "Rented" : "Available") << "]\n";
    }
};

int main() {
    Vehicle* v[20];
    int count = 0, choice;

    do {
        cout << "\n1.wanna add new mechine bro? ";
        cout << "\n2.Rent a damn horse";
        cout << "\n3.available now";
        cout << "\n4.screen them all";
        cout << "\n5.Return now buddy";
        cout << "\n6.Exit";
        cout << "\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            int type, no;
            float rate;

            cout << "1.wife and kids  2.solo\nType: ";
            cin >> type;

            cout << "(1-20): ";
            cin >> no;
          if (no<= 20) {
              cout << "proceed\n";
          }
          else {
            cout << "hahaha jokes on you\n";
          }

            cout << "how many days trip dude?: ";
            cin >> rate;

            if (type == 1) {
                int seats;
                cout << "ahh feeling sad for you man,anyways Seats ?: ";
                cin >> seats;
                v[count] = new Car(no, rate, seats);
            }
            else if (type == 2) {
                char h;
                cout << "wanna have safe ride,Helmet included? (y/n): ";
                cin >> h;
                v[count] = new Bike(no, rate, h == 'y' || h == 'Y');
            }
            else {
                cout << "Invalid type\n";
                continue;
            }

            count++;
            cout << "Vehicle added\n";
        }
        else if (choice == 2) {
            int no, days, i;
            cout << "Vehicle No: ";
            cin >> no;
            for (i = 0; i < count; i++)
                if (v[i]->no == no)
                    break;
            if (i == count)
                cout << "Vehicle not found\n";
            else if (v[i]->rented)
                cout << "Vehicle currently unavailable\n";
            else {
                cout << "Days: ";
                cin >> days;

                float cost = v[i]->calculateRentalCost(days);

                v[i]->rented = true;
                cout << "Rental Cost = Rs." << cost << "\n";
            }
        }
        else if (choice == 3) {
            for (int i = 0; i < count; i++)
                if (!v[i]->rented)
                    v[i]->displayInfo();
        }

        else if (choice == 4) {
            for (int i = 0; i < count; i++)
                v[i]->displayInfo();
        }

        else if (choice == 5) {
            int no, i;

            cout << "Vehicle No: ";
            cin >> no;

            for (i = 0; i < count; i++)
                if (v[i]->no == no)
                    break;

            if (i == count)
                cout << "Vehicle not found\n";
            else {
                v[i]->rented = false;
                cout << "Vehicle returned\n";
            }
        }

    } while (choice != 6);

    for (int i = 0; i < count; i++)
        delete v[i];

    return 0;
}

