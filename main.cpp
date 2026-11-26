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

struct lotData {
    int lotID;
    int farmerID;
    int productID;
    int quantity;
    string status;
};

bool isBlank(const string& str){
    if(str.empty()){
        cout << "Error: Field cannot be empty. \n";
        return true;
    }
    return false;
}

bool isValidGrade(char grade){
    if(grade != 'A' && grade != 'B' && grade != 'C'){
        cout << "Error: Invalid grade. Must be A, B, or C.\n";
        return false;
    }
    return true;
}

bool isValidUnit(const string& unit){
    if(unit != "kg" && unit != "lb" && unit != "g"){
        cout << "Error: Invalid unit. Must be kg, lb, or g.\n";
        return false;
    }
    return true;
}

bool isValidPrice(double price){
    if(price <= 0){
        cout << "Error: Price must be greater than 0.\n";
        return false;
    }
    return true;
}

bool isValidDate(const string& date){
    if(date.length() != 10 || date[4] != '-' || date[7] != '-'){
        cout << "Error: Invalid date format. Use YYYY-MM-DD.\n";
        return false;
    }
    return true;
}

bool isValidAge(int age){
    if(age <= 0){
        cout << "Error: Age must be greater than 0.\n";
        return false;
    }
    return true;
}

class Farmer {
    vector<FarmerData> farmers;

public:
    void addfarmer() {
        FarmerData f;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter farmer details:\n";

        do {
            cout << "Name: ";
            getline(cin, f.name);
        } while (isBlank(f.name));

        do {
            cout << "Age: ";
            cin >> f.age;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (!isValidAge(f.age));

        do {
            cout << "Address: ";
            getline(cin, f.addressof);
        } while (isBlank(f.addressof));

        do {
            cout << "Phone: ";
            getline(cin, f.phone);
        } while (isBlank(f.phone));

        do {
            cout << "Village: ";
            getline(cin, f.village);
        } while (isBlank(f.village));

        cout << "ID: ";
        cin >> f.ID;

        if (f.ID <= 0 || f.age <= 0) {
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

                do {
                    cout << "New name: ";
                    getline(cin, current.name);
                } while (isBlank(current.name));

                cout << "New age: ";
                do {
                    cin >> current.age;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } while (!isValidAge(current.age));
                
                do {
                    cout << "New phone: ";
                    getline(cin, current.phone);
                } while (isBlank(current.phone));

                do {
                    cout << "New address: ";
                    getline(cin, current.addressof);
                } while (isBlank(current.addressof));

                do {
                    cout << "New village: ";
                    getline(cin, current.village);
                } while (isBlank(current.village));

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

    bool validateFarmerReference(int farmerID) {
        for (const FarmerData& current : farmers) {
            if (current.ID == farmerID) {
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

        do {
            cout << "Name: ";
            getline(cin, b.name);
        } while (isBlank(b.name));

        do {
            cout << "Age: ";
            cin >> b.age;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (!isValidAge(b.age));

        do {
            cout << "Address: ";
            getline(cin, b.addressof);
        } while (isBlank(b.addressof));

        do {
            cout << "Phone: ";
            getline(cin, b.phone);
        } while (isBlank(b.phone));

        do {
            cout << "Buyer type: ";
            getline(cin, b.buyertype);
        } while (isBlank(b.buyertype));

        cout << "ID: ";
        cin >> b.ID;

        if (b.ID <= 0 || b.age <= 0) {
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

                do {
                    cout << "New name: ";
                    getline(cin, current.name);
                } while (isBlank(current.name));

                do {
                    cout << "New age: ";
                    cin >> current.age;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } while (!isValidAge(current.age));

                do {
                    cout << "New phone: ";
                    getline(cin, current.phone);
                } while (isBlank(current.phone));

                do {
                    cout << "New address: ";
                    getline(cin, current.addressof);
                } while (isBlank(current.addressof));

                do {
                    cout << "New buyer type: ";
                    getline(cin, current.buyertype);
                } while (isBlank(current.buyertype));

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
    int farmerID;
    string productname;
    char grade;
    double price;
    string harvestdate;
    int quantity;
};

class ProductManager {
    vector<productData> products;

public:

    // TC07 and TC08 - Validate farmer reference
    bool validateFarmerReference(Farmer& f, int farmerID)
    {
        return f.validateFarmerReference(farmerID);
    }

    // TC22 - Validate quantity boundary
    bool validateQuantity(int quantity)
    {
        if(quantity >= 1 && quantity <= 1000)
        {
            return true;
        }

        cout << "Error: Quantity must be between 1 and 1000.\n";
        return false;
    }

    // Add product
    void addproduct(Farmer& f)
    {
        cout << "Enter product details:" << endl;
        productData p;

        cout << "Product ID: ";
        cin >> p.productID;

        cout << "Farmer ID: ";
        cin >> p.farmerID;

        // TC07 and TC08
        if(!validateFarmerReference(f, p.farmerID))
        {
            cout << "Error: Farmer ID does not exist. Product rejected.\n";
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        do
        {
            cout << "Product Name: ";
            getline(cin, p.productname);
        } while(isBlank(p.productname));

        do
        {
            cout << "Grade: ";
            cin >> p.grade;
        } while(!isValidGrade(p.grade));

        do
        {
            cout << "Price: ";
            cin >> p.price;
        } while(!isValidPrice(p.price));

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        do
        {
            cout << "Harvest Date: ";
            getline(cin, p.harvestdate);
        } while(isBlank(p.harvestdate) || !isValidDate(p.harvestdate));

        do
        {
            cout << "Quantity: ";
            cin >> p.quantity;
        } while(!validateQuantity(p.quantity));

        // TC22
        if(p.productID <= 0)
        {
            cout << "Error: Invalid product details.\n";
            return;
        }

        products.push_back(p);

        cout << "Product added successfully!\n";
    }

    // Display product
    void displayproduct()
    {
        cout << "-----------------Display Product Details------------------\n";

        if(products.empty())
        {
            cout << "No products available.\n";
            return;
        }

        for(const productData& current : products)
        {
            cout << "Product ID : " << current.productID << endl;
            cout << "Farmer ID : " << current.farmerID << endl;
            cout << "Product Name : " << current.productname << endl;
            cout << "Product Grade : " << current.grade << endl;
            cout << "Product Price : " << current.price << endl;
            cout << "Product Harvest Date : " << current.harvestdate << endl;
            cout << "Product Quantity : " << current.quantity << endl;
            cout << "---------------------------------------------------------\n";
        }
    }

    // Modify product
    void modifyproduct()
    {
        int modifyID;

        cout << "Enter the product ID which should be modified : ";
        cin >> modifyID;

        for(int i = 0; i < products.size(); i++)
        {
            if(products[i].productID == modifyID)
            {
                cout << "Product found !\n";
                cout << "Enter new product details:\n";

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                do
                {
                    cout << "Product Name : ";
                    getline(cin, products[i].productname);
                } while(isBlank(products[i].productname));

                do
                {
                    cout << "Product Grade : ";
                    cin >> products[i].grade;
                } while(!isValidGrade(products[i].grade));

                do
                {
                    cout << "Product Price : ";
                    cin >> products[i].price;
                } while(!isValidPrice(products[i].price));

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                do
                {
                    cout << "Product Harvest Date : ";
                    getline(cin, products[i].harvestdate);
                } while(isBlank(products[i].harvestdate) || !isValidDate(products[i].harvestdate));

                do
                {
                    cout << "Product Quantity : ";
                    cin >> products[i].quantity;
                } while(!validateQuantity(products[i].quantity));

                cout << "Product updated successfully!\n";
                return;
            }
        }

        cout << "Product not found.\n";
    }

    // TC20 - Sort product by selected field
    void sortproduct()
    {
        int choice;

        cout << "\n1. Sort by Product Name\n";
        cout << "2. Sort by Price\n";
        cout << "3. Sort by Quantity\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice < 1 || choice > 3)
        {
            cout << "Invalid sorting choice.\n";
            return;
        }

        if(products.size() < 2)
        {
            cout << "Not enough products to sort.\n";
            return;
        }

        for(int i = 0; i < products.size() - 1; i++)
        {
            for(int j = 0; j < products.size() - i - 1; j++)
            {
                bool swapNeeded = false;

                if(choice == 1 &&
                   products[j].productname > products[j+1].productname)
                {
                    swapNeeded = true;
                }

                else if(choice == 2 &&
                        products[j].price > products[j+1].price)
                {
                    swapNeeded = true;
                }

                else if(choice == 3 &&
                        products[j].quantity > products[j+1].quantity)
                {
                    swapNeeded = true;
                }

                if(swapNeeded)
                {
                    swap(products[j], products[j+1]);
                }
            }
        }

        cout << "Products sorted successfully!\n";
        displayproduct();
    }
};

class lot{
    vector<lotData> lots;

    public:
    void addLot(){

    }

    void displayLot(){

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

void productMenu(ProductManager& p, Farmer& f) {
    int option;

    do {
        cout << "\n========== Product Management ==========\n";
        cout << "1. Add a Product\n";
        cout << "2. Display Products\n";
        cout << "3. Modify a Product\n";
        cout << "4. Sort Products\n";
        cout << "5. Main Menu\n";
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1:
                p.addproduct(f);
                break;
            case 2:
                p.displayproduct();
                break;
            case 3:
                p.modifyproduct();
                break;
            case 4:
                p.sortproduct();
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
    ProductManager p;
    
    int choice = 0;

    do {
        cout << "\n======= Organic Farm Produce Trading Management System =======\n";
        cout << "1. Farmer Management\n";
        cout << "2. Buyer Management\n";
        cout << "3. Product Management\n";
        cout << "4. exit\n";
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
                productMenu(p, f);
                break;
            case 4:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    } while (true);
}