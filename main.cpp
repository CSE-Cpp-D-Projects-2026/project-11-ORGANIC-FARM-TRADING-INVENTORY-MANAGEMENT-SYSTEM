
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

struct ProduceData {
    string name, ID, Harvest_date, unit, certification_no;
    double price;
};

struct lotData {

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

    
    bool checkFarmerDetails() {
        int checkID;

        cout << "Enter the farmer ID which should be checked: ";
        cin >> checkID;

        for (int i = 0; i < farmers.size(); i++) {
            if (farmers[i].ID == checkID) {
                return true;
            }
        }

        return false;
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

    
    bool checkBuyerDetails() {
        int checkID;

        cout << "Enter the buyer ID which should be checked: ";
        cin >> checkID;

        for (int i = 0; i < buyers.size(); i++) {
            if (buyers[i].ID == checkID) {
                return true;
            }
        }

        return false;
    }

};

struct productData{
    int productID;
    string productname;
    char grade;
    double price;
    string harvestdate;
    int quantity;
};

class ProductManager {
    vector<productData> products;

public:
    void addproduct() {
        cout << "Enter product details:" << endl;
        productData p;

        cout << "Product ID: ";
        cin >> p.productID;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Product Name: ";
        getline(cin, p.productname);
        cout << "Grade: ";
        cin >> p.grade;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Price: ";
        cin >> p.price;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Harvest Date: ";
        getline(cin, p.harvestdate);
        cout << "Quantity: ";
        cin >> p.quantity;

        if (p.productID <= 0 || p.productname.empty() || p.grade == '\0' ||
            p.price <= 0 || p.harvestdate.empty() || p.quantity <= 0) {
            cout << "Error: All fields must be filled and values must be greater than 0." << endl;
            return;
        }
    }
};

class lot{
    vector<lotData> lots;
};

void farmerMenu(Farmer& f) {
    int option;

    do {
        cout << "\n========== Farmer Management ==========\n";
        cout << "1. Add a Farmer\n";
        cout << "2. Search a Farmer\n";
        cout << "3. Modify a Farmer\n";
        cout << "4. Display Farmers\n";
        cout << "5. check farmer details\n";
        cout << "6. Main Menu\n";
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
                f.checkFarmerDetails();
                break;
            case 6:
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
        cout << "5. check buyer details\n";
        cout << "6. Main Menu\n";
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
                b.checkBuyerDetails();
                break;
            case 6:
                return;
            default:
                cout << "Invalid option!\n";
        }
    } while (true);
}

void isBlank(const string& str){
    if(str.empty()){
        cout << "Error: Field cannot be empty. \n";
    }
}

void isValidGrade(char grade){
    if(grade != 'A' && grade != 'B' && grade != 'C'){
        cout << "Error: Invalid grade. Must be A, B, or C.\n";
    }
}

void isValidUnit(const string& unit){
    if(unit != "kg" && unit != "lb" && unit != "g"){
        cout << "Error: Invalid unit. Must be kg, lb, or g.\n";
    }
}

void isValidPrice(double price){
    if(price < 0){
        cout << "Error: Price cannot be negative.\n";
    }
}

void isValidDate(const string& date){
    if(date.length() != 10 || date[4] != '-' || date[7] != '-'){
        cout << "Error: Invalid date format. Use YYYY-MM-DD.\n";
    }
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
