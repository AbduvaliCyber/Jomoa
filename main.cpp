#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Telefon {
    string brend;
    string model;
    int yil;
    double narx;
};

void telefonQoshish(vector<Telefon>& roxat) {
    Telefon t;
    cout << "Brend kiriting: ";
    cin >> t.brend;
    cout << "Model kiriting: ";
    cin >> t.model;
    cout << "Chiqqan yilini kiriting: ";
    cin >> t.yil;
    cout << "Narxini kiriting: ";
    cin >> t.narx;
    roxat.push_back(t);
    cout << "✅ Telefon muvaffaqiyatli qo‘shildi!\n";
}

void barchaTelefonlar(const vector<Telefon>& roxat) {
    if (roxat.empty()) {
        cout << "📭 Telefonlar ro‘yxati bo‘sh.\n";
        return;
    }

    cout << "\n📱 Telefonlar ro‘yxati:\n";
    for (size_t i = 0; i < roxat.size(); ++i) {
        cout << i + 1 << ". " << roxat[i].brend << " "
             << roxat[i].model << " - $" << roxat[i].narx
             << " (" << roxat[i].yil << ")\n";
    }
}

void filterYilBoyicha(const vector<Telefon>& roxat, int yil) {
    bool topildi = false;
    for (const auto& t : roxat) {
        if (t.yil == yil) {
            cout << t.brend << " " << t.model << " - $" << t.narx << " (" << t.yil << ")\n";
            topildi = true;
        }
    }
    if (!topildi) {
        cout << "🛑 " << yil << " yilga oid telefon topilmadi.\n";
    }
}

void engQimmatTelefon(const vector<Telefon>& roxat) {
    if (roxat.empty()) {
        cout << "📭 Telefonlar ro‘yxati bo‘sh.\n";
        return;
    }

    const Telefon* maxTel = &roxat[0];
    for (const auto& t : roxat) {
        if (t.narx > maxTel->narx) {
            maxTel = &t;
        }
    }

    cout << "💰 Eng qimmat telefon: " << maxTel->brend << " " << maxTel->model
         << " - $" << maxTel->narx << " (" << maxTel->yil << ")\n";
}

int menyu() {
    int tanlov;
    cout << "\n--- Telefon Bazasini Boshqarish ---\n";
    cout << "1. Telefon qo‘shish\n";
    cout << "2. Barcha telefonlarni ko‘rish\n";
    cout << "3. Yil bo‘yicha qidirish\n";
    cout << "4. Eng qimmat telefon\n";
    cout << "0. Chiqish\n";
    cout << "Tanlovingiz: ";
    cin >> tanlov;
    return tanlov;
}

int main() {
    vector<Telefon> telefonlar;
    int tanlov;

    do {
        tanlov = menyu();
        switch (tanlov) {
            case 1:
                telefonQoshish(telefonlar);
                break;
            case 2:
                barchaTelefonlar(telefonlar);
                break;
            case 3: {
                int yil;
                cout << "Qaysi yilni qidirmoqchisiz? ";
                cin >> yil;
                filterYilBoyicha(telefonlar, yil);
                break;
            }
            case 4:
                engQimmatTelefon(telefonlar);
                break;
            case 0:
                cout << "Dasturdan chiqildi.\n";
                break;
            default:
                cout << "Noto‘g‘ri tanlov. Qayta urinib ko‘ring.\n";
        }
    } while (tanlov != 0);

    return 0;
}
