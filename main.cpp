#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

using namespace std;

// Bazaviy Gilam sinfi
class Carpet {
protected:
    string name;
    string material;
    double length;
    double width;
    double price;
    string origin;

public:
    Carpet(string n, string m, double l, double w, double p, string o)
        : name(n), material(m), length(l), width(w), price(p), origin(o) {}

    virtual double area() const {
        return length * width;
    }

    virtual void showInfo() const {
        cout << "🧶 Nomi: " << name
             << ", Materiali: " << material
             << ", O‘lchami: " << length << "m x " << width << "m"
             << ", Maydoni: " << area() << "m²"
             << ", Narxi: $" << price
             << ", Ishlab chiqarilgan joyi: " << origin << endl;
    }

    virtual double getPrice() const {
        return price;
    }

    virtual string getName() const {
        return name;
    }

    virtual ~Carpet() {}
};

// Qo‘lda to‘qilgan gilam sinfi
class HandmadeCarpet : public Carpet {
private:
    int knotsPerSquareInch;

public:
    HandmadeCarpet(string n, string m, double l, double w, double p, string o, int kpsi)
        : Carpet(n, m, l, w, p, o), knotsPerSquareInch(kpsi) {}

    void showInfo() const override {
        Carpet::showInfo();
        cout << "   ➤ Qo‘lda to‘qilgan (Tugun zichligi: " << knotsPerSquareInch << " PSI)\n";
    }
};

// Mashinada to‘qilgan gilam sinfi
class MachineMadeCarpet : public Carpet {
private:
    string machineType;

public:
    MachineMadeCarpet(string n, string m, double l, double w, double p, string o, string mt)
        : Carpet(n, m, l, w, p, o), machineType(mt) {}

    void showInfo() const override {
        Carpet::showInfo();
        cout << "   ➤ Mashinada to‘qilgan (Stanok turi: " << machineType << ")\n";
    }
};

// Gilamlarni boshqaruvchi sinf
class CarpetManager {
private:
    vector<shared_ptr<Carpet>> carpets;

public:
    void addCarpet(shared_ptr<Carpet> carpet) {
        carpets.push_back(carpet);
    }

    void listCarpets() {
        cout << "\n=== Gilamlar ro‘yxati ===\n";
        for (size_t i = 0; i < carpets.size(); ++i) {
            cout << "ID: " << i + 1 << " → ";
            carpets[i]->showInfo();
        }
    }

    void sortByPrice(bool ascending = true) {
        sort(carpets.begin(), carpets.end(), [ascending](shared_ptr<Carpet> a, shared_ptr<Carpet> b) {
            return ascending ? a->getPrice() < b->getPrice() : a->getPrice() > b->getPrice();
        });
        cout << (ascending ? "\nNarx bo‘yicha o‘sish tartibida" : "\nNarx bo‘yicha kamayish tartibida") << " saralandi.\n";
    }

    void searchByName(const string& keyword) {
        cout << "\n🔍 Qidiruv natijalari (kalit: \"" << keyword << "\"):\n";
        bool found = false;
        for (auto& c : carpets) {
            if (c->getName().find(keyword) != string::npos) {
                c->showInfo();
                found = true;
            }
        }
        if (!found) {
            cout << "Hech qanday mos gilam topilmadi.\n";
        }
    }
};

// Interaktiv menyu
void showMenu() {
    cout << "\n=== GILAMLAR TIZIMI ===\n";
    cout << "1. Gilamlar ro‘yxatini ko‘rsatish\n";
    cout << "2. Narx bo‘yicha saralash (oshish)\n";
    cout << "3. Narx bo‘yicha saralash (kamayish)\n";
    cout << "4. Nomi bo‘yicha qidirish\n";
    cout << "0. Chiqish\n";
    cout << "Tanlovingiz: ";
}

int main() {
    CarpetManager manager;

    // Ba'zi gilamlarni qo‘shamiz
    manager.addCarpet(make_shared<HandmadeCarpet>("Buxoro Lux", "Jun", 2.5, 3.0, 750.00, "O‘zbekiston", 120));
    manager.addCarpet(make_shared<MachineMadeCarpet>("Antep Gold", "Sintetik", 2.0, 3.0, 350.00, "Turkiya", "Jacquard"));
    manager.addCarpet(make_shared<HandmadeCarpet>("Qom Classic", "Ipak", 1.5, 2.5, 1200.00, "Eron", 220));
    manager.addCarpet(make_shared<MachineMadeCarpet>("Istanbul Style", "Aralash", 2.4, 3.5, 450.00, "Turkiya", "Loomax"));

    int choice;
    string keyword;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                manager.listCarpets();
                break;
            case 2:
                manager.sortByPrice(true);
                manager.listCarpets();
                break;
            case 3:
                manager.sortByPrice(false);
                manager.listCarpets();
                break;
            case 4:
                cout << "Qidirilayotgan so‘zni kiriting: ";
                getline(cin, keyword);
                manager.searchByName(keyword);
                break;
            case 0:
                cout << "Dasturdan chiqilmoqda...\n";
                break;
            default:
                cout << "Noto‘g‘ri tanlov. Qaytadan urinib ko‘ring.\n";
        }

    } while (choice != 0);

    return 0;
}
