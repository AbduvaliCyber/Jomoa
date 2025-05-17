// Fayl: main.cpp
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ===== MENU ITEM KLASSI =====
class MenuItem {
public:
    string name;
    double price;

    MenuItem(string n, double p) {
        name = n;
        price = p;
    }
};

// ===== ORDER ITEM KLASSI =====
class OrderItem {
public:
    MenuItem item;
    int quantity;

    OrderItem(MenuItem mItem, int qty) : item(mItem), quantity(qty) {}

    double getTotal() const {
        return quantity * item.price;
    }
};

// ===== CAFE CLASSI =====
class Cafe {
private:
    vector<MenuItem> menu;
    vector<OrderItem> order;

public:
    void addMenuItem(const string& name, double price) {
        menu.emplace_back(name, price);
    }

    void showMenu() const {
        cout << "\n---- MENYU ----\n";
        for (size_t i = 0; i < menu.size(); ++i) {
            cout << i + 1 << ". " << menu[i].name << " - $" << fixed << setprecision(2) << menu[i].price << endl;
        }
    }

    void takeOrder() {
        int choice, quantity;

        while (true) {
            showMenu();
            cout << "\nBuyurtma raqamini tanlang (0 - yakunlash): ";
            cin >> choice;
            if (choice == 0) break;

            if (choice < 1 || choice > (int)menu.size()) {
                cout << "Noto‘g‘ri tanlov. Qayta urinib ko‘ring.\n";
                continue;
            }

            cout << "Miqdorini kiriting: ";
            cin >> quantity;

            order.emplace_back(menu[choice - 1], quantity);
            cout << "Buyurtma qo‘shildi!\n";
        }
    }

    void printBill() const {
        cout << "\n========== CHEK ==========\n";
        double total = 0;
        for (const auto& item : order) {
            cout << item.item.name << " x " << item.quantity
                 << " = $" << fixed << setprecision(2) << item.getTotal() << endl;
            total += item.getTotal();
        }
        cout << "---------------------------\n";
        cout << "Jami: $" << fixed << setprecision(2) << total << endl;
        cout << "===========================\n";
    }

    void run() {
        addDefaultItems();
        takeOrder();
        printBill();
    }

private:
    void addDefaultItems() {
        addMenuItem("Americano", 2.50);
        addMenuItem("Cappuccino", 3.00);
        addMenuItem("Latte", 3.50);
        addMenuItem("Choy", 1.50);
        addMenuItem("Keks", 2.00);
        addMenuItem("Sandwich", 4.00);
    }
};

// ===== MAIN FUNCTION =====
int main() {
    Cafe myCafe;
    myCafe.run();
    return 0;
}
gi