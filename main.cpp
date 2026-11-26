
#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct FarmerData {
    string name;
    int age;
    string addressof;
    string phone;
    string village;
    int ID;
};

struct BuyerData {
    string name;
    int age;
    string addressof;
    string phone;
    string buyertype;
    int ID;
};

class Farmer {
    vector<FarmerData> farmers;

public:
    void addfarmer() {
        FarmerData f;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter farmer details:\n";
        cout << "Name: ";
        getline(cin, f.name);

        cout << "Age: ";
        cin >> f.age;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
            cout << "Error: Invalid or empty fields.\n";
            return;
        }

        farmers.push_back(f);
        cout << "Farmer added successfully!\n";
    }

    void searchFarmer() {
        int id;
        cout << "Enter farmer ID: ";
        cin >> id;

        for (const FarmerData& current : farmers) {
            if (current.ID == id) {
                cout << "Farmer found!\n";
                cout << "Name: " << current.name << '\n';
                cout << "Age: " << current.age << '\n';
                cout << "Address: " << current.addressof << '\n';
                cout << "Phone: " << current.phone << '\n';
                cout << "Village: " << current.village << '\n';
                return;
            }
        }

        cout << "Farmer with ID " << id << " not found.\n";
    }

    void modifyFarmer() {
        int searchID;
        cout << "Enter farmer ID to update: ";
        cin >> searchID;

        for (FarmerData& current : farmers) {
            if (current.ID == searchID) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "New name: ";
                getline(cin, current.name);

                cout << "New age: ";
                cin >> current.age;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "New phone: ";
                getline(cin, current.phone);

                cout << "New address: ";
                getline(cin, current.addressof);

                cout << "New village: ";
                getline(cin, current.village);

                cout << "Farmer details updated!\n";
                return;
            }
        }

        cout << "Farmer not found.\n";
    }

    void displayFarmer() {
        if (farmers.empty()) {
            cout << "No farmers available.\n";
            return;
        }

        for (const FarmerData& current : farmers) {
            cout << "\nFarmer ID: " << current.ID << '\n';
            cout << "Name: " << current.name << '\n';
            cout << "Age: " << current.age << '\n';
            cout << "Phone: " << current.phone << '\n';
            cout << "Address: " << current.addressof << '\n';
            cout << "Village: " << current.village << '\n';
        }
    }
};

class Buyer {
    vector<BuyerData> buyers;

public:
    void addbuyer() {
        BuyerData b;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter buyer details:\n";
        cout << "Name: ";
        getline(cin, b.name);

        cout << "Age: ";
        cin >> b.age;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Address: ";
        getline(cin, b.addressof);

        cout << "Phone: ";
        getline(cin, b.phone);

        cout << "Buyer type: ";
        getline(cin, b.buyertype);

        cout << "ID: ";
        cin >> b.ID;

        if (b.ID <= 0 || b.name.empty() || b.age <= 0 ||
            b.addressof.empty() || b.phone.empty() ||
            b.buyertype.empty()) {
            cout << "Error: Invalid or empty fields.\n";
            return;
        }

        buyers.push_back(b);
        cout << "Buyer added successfully!\n";
    }

    void searchbuyer() {
        int id;
        cout << "Enter buyer ID: ";
        cin >> id;

        for (const BuyerData& current : buyers) {
            if (current.ID == id) {
                cout << "Buyer found!\n";
                cout << "Name: " << current.name << '\n';
                cout << "Age: " << current.age << '\n';
                cout << "Address: " << current.addressof << '\n';
                cout << "Phone: " << current.phone << '\n';
                cout << "Buyer type: " << current.buyertype << '\n';
                return;
            }
        }

        cout << "Buyer with ID " << id << " not found.\n";
    }

    void modifybuyer() {
        int searchID;
        cout << "Enter buyer ID to update: ";
        cin >> searchID;

        for (BuyerData& current : buyers) {
            if (current.ID == searchID) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "New name: ";
                getline(cin, current.name);

                cout << "New age: ";
                cin >> current.age;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "New phone: ";
                getline(cin, current.phone);

                cout << "New address: ";
                getline(cin, current.addressof);

                cout << "New buyer type: ";
                getline(cin, current.buyertype);

                cout << "Buyer details updated!\n";
                return;
            }
        }

        cout << "Buyer not found.\n";
    }

    void displayBuyer() {
        if (buyers.empty()) {
            cout << "No buyers available.\n";
            return;
        }

        for (const BuyerData& current : buyers) {
            cout << "\nBuyer ID: " << current.ID << '\n';
            cout << "Name: " << current.name << '\n';
            cout << "Age: " << current.age << '\n';
            cout << "Phone: " << current.phone << '\n';
            cout << "Address: " << current.addressof << '\n';
            cout << "Buyer type: " << current.buyertype << '\n';
        }
    }
};

void farmerMenu(Farmer& f) {
    int option;

    do {
        cout << "\n========== Farmer Management ==========\n";
        cout << "1. Add a Farmer\n";
        cout << "2. Search a Farmer\n";
        cout << "3. Modify a Farmer\n";
        cout << "4. Display Farmers\n";
        cout << "5. Main Menu\n";
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1:
                f.addfarmer();
                break;
            case 2:
                f.searchFarmer();
                break;
            case 3:
                f.modifyFarmer();
                break;
            case 4:
                f.displayFarmer();
                break;
            case 5:
                return;
            default:
                cout << "Invalid option!\n";
        }
    } while (true);
}

void buyerMenu(Buyer& b) {
    int option;

    do {
        cout << "\n========== Buyer Management ==========\n";
        cout << "1. Add a Buyer\n";
        cout << "2. Search a Buyer\n";
        cout << "3. Modify a Buyer\n";
        cout << "4. Display Buyers\n";
        cout << "5. Main Menu\n";
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1:
                b.addbuyer();
                break;
            case 2:
                b.searchbuyer();
                break;
            case 3:
                b.modifybuyer();
                break;
            case 4:
                b.displayBuyer();
                break;
            case 5:
                return;
            default:
                cout << "Invalid option!\n";
        }
    } while (true);
}

int main() {
    Farmer f;
    Buyer b;
    int choice = 0;

    do {
        cout << "\n======= Organic Farm Produce Trading Management System =======\n";
        cout << "1. Farmer Management\n";
        cout << "2. Buyer Management\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                farmerMenu(f);
                break;
            case 2:
                buyerMenu(b);
                break;
            case 3:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    } while (true);
}
