#include <iostream>
using namespace std;

class cashRegister {
private:
    int cashOnHand;
public:
    cashRegister() {
        cashOnHand = 500;
    }

    cashRegister(int cash) {
        cashOnHand = cash;
    }

    int getCurrentBalance() {
        return cashOnHand;
    }

    void acceptAmount(int amount) {
        cashOnHand += amount;
    }
};

class dispenserType {
private:
    int numberOfItems;
    int itemCost;
public:
    dispenserType() {
        numberOfItems = 50;
        itemCost = 0;
    }

    dispenserType(int items, int cost) {
        numberOfItems = items;
        itemCost = cost;
    }

    int getNoOfItems() {
        return numberOfItems;
    }

    int getCost() {
        return itemCost;
    }

    void makeSale() {
        if (numberOfItems > 0) {
            numberOfItems--;
        }
    }
};

void showSelection() {
    cout << "1. Snickers 50rub" << endl;
    cout << "2. Kit Kat 30rub" << endl;
    cout << "3. Twix 20rub" << endl;
}

void sellProduct(dispenserType& dispenser, cashRegister& cashRegister) {
    int choice;
    cout << "Enter the number corresponding to the product: ";
    cin >> choice;

    switch (choice) {
    case 1:
        if (dispenser.getNoOfItems() > 0) {
            cout << "The cost of Snickers is 50rub" << endl;
            cout << "Please insert 50rub: ";
            int amount;
            cin >> amount;
            if (amount >= dispenser.getCost()) {
                dispenser.makeSale();
                cashRegister.acceptAmount(dispenser.getCost());
                cout << "Product dispensed. Enjoy your Snickers!" << endl;
            }
            else {
                cout << "Insufficient amount. No product dispensed." << endl;
            }
        }
        else {
            cout << "Snickers is out of stock." << endl;
        }
        break;
    case 2:
        if (dispenser.getNoOfItems() > 0) {
            cout << "The cost of Kit kat is 30rub" << endl;
            cout << "Please insert 30rub: ";
            int amount;
            cin >> amount;
            if (amount >= dispenser.getCost()) {
                dispenser.makeSale();
                cashRegister.acceptAmount(dispenser.getCost());
                cout << "Product dispensed. Enjoy your Kit kat!" << endl;
            }
            else {
                cout << "Insufficient amount. No product dispensed." << endl;
            }
        }
        else {
            cout << "Kit kat is out of stock." << endl;
        }
        break;
    case 3:
        if (dispenser.getNoOfItems() > 0) {
            cout << "The cost of Twix is 20rub" << endl;
            cout << "Please insert 20rub: ";
            int amount;
            cin >> amount;
            if (amount >= dispenser.getCost()) {
                dispenser.makeSale();
                cashRegister.acceptAmount(dispenser.getCost());
                cout << "Product dispensed. Enjoy your Twix!" << endl;
            }
            else {
                cout << "Insufficient amount. No product dispensed." << endl;
            }
        }
        break;
    default:
        cout << "Invalid choice." << endl;
        break;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    cashRegister register1;
    dispenserType dispenser1;

    cout << "Welcome to the candy machine!" << endl;
    showSelection();
    sellProduct(dispenser1, register1);

    return 0;
}