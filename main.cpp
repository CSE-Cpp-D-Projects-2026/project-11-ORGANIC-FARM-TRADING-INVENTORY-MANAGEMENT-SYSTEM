#include <iostream>
#include <vector>
#include <string>
#include <limits>
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
            int searchID;
            cout << "Enter the ID of the farmer to update: ";
            cin >> searchID;

            for (farmer& current : farmers) {
                if (current.ID == searchID) {
                    cout << "Farmer found!\n";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Enter new name: ";
                    getline(cin, current.name);
                    cout << "Enter new age: ";
                    cin >> current.age;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Enter new phone number: ";
                    getline(cin, current.phone);
                    cout << "Enter new address: ";
                    getline(cin, current.addressof);
                    cout << "Enter new village: ";
                    getline(cin, current.village);

                    cout << "Farmer details updated successfully!\n";
                    return;
                }
            }

            cout << "Farmer with ID " << searchID << " not found!\n";
        }

        void displayFarmer() {
            cout << "-----------------Display Farmer Details------------------\n";
            for (const farmer& current : farmers) {
                cout << "Farmer ID : " << current.ID << endl;
                cout << "Farmer Name : " << current.name << endl;
                cout << "Farmer Age : " << current.age << endl;
                cout << "Farmer Phone Number : " << current.phone << endl;
                cout << "Farmer Address : " << current.addressof << endl;
                cout << "Farmer Village : " << current.village << endl;
                cout << "---------------------------------------------------------\n";
            }
        }

};
class buyer {
    vector<buyer> buyers;
public:
    string name;
    int age;
    string addressof;
    string phone;
    string buyertype;
    int ID;

public:
    void addbuyer() {
        cout << "Enter buyer details:" << endl;
        buyer b;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Name: ";
        getline(cin, b.name);
        cout << "Age: ";
        cin >> b.age;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Address: ";
        getline(cin, b.addressof);
        cout << "Phone: ";
        getline(cin, b.phone);
        cout << "Buyer Type: ";
        getline(cin, b.buyertype);
        cout << "ID: ";
        cin >> b.ID;

        if (b.ID <= 0 || b.name.empty() || b.age <= 0 ||
            b.addressof.empty() || b.phone.empty() || b.buyertype.empty()) {
            cout << "Error: All fields must be filled and age must be greater than 0." << endl;
            return;
        }
        buyers.push_back(b);
        cout << "Buyer added successfully!" << endl;
    }

    void searchbuyer() {
        int id;
        cout << "---------------Search a Buyer----------------" << endl;
        cout << "Enter the buyer's id: ";
        cin >> id;

        for (const buyer& current : buyers) {
            if (current.ID == id) {
                cout << "Buyer found!" << endl;
                cout << "Name: " << current.name << endl;
                cout << "Age: " << current.age << endl;
                cout << "Address: " << current.addressof << endl;
                cout << "Phone: " << current.phone << endl;
                cout << "Buyer Type: " << current.buyertype << endl;
                return;
            }
        }
        cout << "Buyer with ID " << id << " not found." << endl;
    }
    void modifybuyer() {
            int searchID;
            cout << "Enter the ID of the buyer to update: ";
            cin >> searchID;

            for (buyer& current : buyers) {
                if (current.ID == searchID) {
                    cout << "Buyer found!\n";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Enter new name: ";
                    getline(cin, current.name);
                    cout << "Enter new age: ";
                    cin >> current.age;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Enter new phone number: ";
                    getline(cin, current.phone);
                    cout << "Enter new address: ";
                    getline(cin, current.addressof);
                    cout << "Enter new buyer type: ";
                    getline(cin, current.buyertype);

                    cout << "Buyer details updated successfully!\n";
                    return;
                }
            }

            cout << "Buyer with ID " << searchID << " not found!\n";
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
        cout << "option 5: Main Menu" << endl;
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