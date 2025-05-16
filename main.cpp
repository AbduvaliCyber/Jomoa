#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stul {
private:
    string rang;
    string material;
public:
    Stul(string r, string m) : rang(r), material(m) {}

    void show() const {
        cout << "    Stul - Rang: " << rang << ", Material: " << material << endl;
    }
};

class Stol {
private:
    string rang;
    string material;
    vector<Stul> stullar;
public:
    Stol(string r, string m) : rang(r), material(m) {}

    void stulQosh(const Stul& s) {
        stullar.push_back(s);
    }

    void show() const {
        cout << "Stol - Rang: " << rang << ", Material: " << material << endl;
        cout << "Stullar soni: " << stullar.size() << endl;
        for (const auto& stul : stullar) {
            stul.show();
        }
        cout << endl;
    }
};

void stolQoshish(vector<Stol>& stolalar) {
    string rang, material;
    cout << "Stol rangini kiriting: ";
    cin >> rang;
    cout << "Stol materialini kiriting: ";
    cin >> material;
    Stol yangiStol(rang, material);
    stolalar.push_back(yangiStol);
    cout << "✅ Stol qo'shildi!\n";
}

void stulQoshish(vector<Stol>& stolalar) {
    if (stolalar.empty()) {
        cout << "⚠️ Stol mavjud emas. Iltimos, avval stol qo'shing.\n";
        return;
    }

    cout << "Qaysi stolga stul qo'shmoqchisiz? Stollar ro'yxati:\n";
    for (size_t i = 0; i < stolalar.size(); ++i) {
        cout << i + 1 << ". Rang: " << stolalar[i].rang << ", Material: " << stolalar[i].material << endl;
    }
    cout << "Stol raqamini kiriting: ";
    int index;
    cin >> index;
    if (index < 1 || index > (int)stolalar.size()) {
        cout << "❌ Noto'g'ri raqam!\n";
        return;
    }

    string rang, material;
    cout << "Stul rangini kiriting: ";
    cin >> rang;
    cout << "Stul materialini kiriting: ";
    cin >> material;
    Stul yangiStul(rang, material);
    stolalar[index - 1].stulQosh(yangiStul);
    cout << "✅ Stul qo'shildi!\n";
}

void barchaStollarniKorish(const vector<Stol>& stolalar) {
    if (stolalar.empty()) {
        cout << "⚠️ Stol ro'yxati bo'sh.\n";
        return;
    }
    cout << "\n--- Barcha stollar ---\n";
    for (const auto& stol : stolalar) {
        stol.show();
    }
}

int menyu() {
    int tanlov;
    cout << "\n--- Stol va stullar boshqaruvi ---\n";
    cout << "1. Stol qo'shish\n";
    cout << "2. Stul qo'shish\n";
    cout << "3. Barcha stollarni ko'rish\n";
    cout << "0. Chiqish\n";
    cout << "Tanlovingiz: ";
    cin >> tanlov;
    return tanlov;
}

int main() {
    vector<Stol> stolalar;
    int tanlov;

    do {
        tanlov = menyu();
        switch (tanlov) {
            case 1:
                stolQoshish(stolalar);
                break;
            case 2:
                stulQoshish(stolalar);
                break;
            case 3:
                barchaStollarniKorish(stolalar);
                break;
            case 0:
                cout << "Dasturdan chiqildi. Xayr!\n";
                break;
            default:
                cout << "Noto'g'ri tanlov, qayta urinib ko'ring.\n";
        }
    } while (tanlov != 0);

    return 0;
}
