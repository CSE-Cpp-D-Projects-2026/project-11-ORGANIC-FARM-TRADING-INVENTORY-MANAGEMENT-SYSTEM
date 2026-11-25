#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct farmer {
    string name;
    int age;
    string addressof;
    string phone;
    string village;
    int ID;
};

class Farmer {
    vector<farmer> farmers;
    public:
        void addfarmer() {
            cout << "Enter farmer details:" << endl;
            farmer f;

            cin.ignore();

            cout << "Name: ";
            getline(cin, f.name);
            cout << "Age: ";
            cin >> f.age;
            cin.ignore();

            cout << "Address: ";
            getline(cin, f.addressof);
            cout << "Phone: ";
            getline(cin, f.phone);
            cout << "Village: ";
            getline(cin, f.village);
            cout << "ID: ";
            cin >> f.ID;

            if (f.ID <= 0 || f.name.empty() || f.age <= 0 ||
                f.addressof.empty() || f.phone.empty() ||
                f.village.empty()) {
                cout << "Error: All fields must be filled and age must be greater than 0." << endl;
                return;
            }else {
                farmers.push_back(f);
                cout << "Farmer added successfully !" << endl;
            }
        }

        void searchFarmer() {
            int id;
            cout << "---------------Search a Farmer----------------" << endl;
            cout << "Enter the farmer's id: ";
            cin >> id;

            for (farmer current: farmers){
                if (current.ID == id) {
                    cout << "Farmer found!" << endl;
                    cout << "Name: " << current.name << endl;
                    cout << "Age: " << current.age << endl;
                    cout << "Address: " << current.addressof << endl;
                    cout << "Phone: " << current.phone << endl;
                    cout << "Village: " << current.village << endl;
                    return;
                }
            }
            cout << "Farmer with ID" << id << " not found." << endl;
        }

        void modifyFarmer() {
        }

        void displayFarmer() {
        }
};

int main() {
    Farmer f;

    do {
        cout << "===============ORGANIC FARM PRODUCE TRADING MANAGEMENT SYSTEM===============" << endl;
        cout << "option 1: Add a Farmer" << endl;
        cout << "option 2: search a Farmer" << endl;
        cout << "option 3: modifyFarmer" << endl;
        cout << "option 4: Display a Farmer" << endl;
        cout << "option 5: exit" << endl;
        cout << "Enter your option: " << endl;
        cout << "===========================================================================" << endl;

        int option = 0;
        cin >> option;

        switch (option) {
            case 1: {
                f.addfarmer();
                break;
            }

            case 2: {
                f.searchFarmer();
                break;
            }

            case 3: {
                f.modifyFarmer();
                break;
            }

            case 4: {
                f.displayFarmer();
                break;
            }

            case 5: {
                return 0;
            }
        }
    } while (true);
}