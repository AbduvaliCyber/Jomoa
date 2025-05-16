#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Asosiy Uy klassi
class Uy {
protected:
    string manzil;
    int xonaSoni;
    double maydon;
    bool hovliBormi;

public:
    Uy(string m, int x, double y, bool h)
        : manzil(m), xonaSoni(x), maydon(y), hovliBormi(h) {}

    virtual void info() const {
        cout << "Manzil: " << manzil << endl;
        cout << "Xona soni: " << xonaSoni << endl;
        cout << "Maydon: " << maydon << " m2" << endl;
        cout << "Hovli: " << (hovliBormi ? "Bor" : "Yo'q") << endl;
    }

    virtual ~Uy() {}
};

// Kvartira klassi
class Kvartira : public Uy {
    int qavat;
    bool liftBormi;

public:
    Kvartira(string m, int x, double y, bool h, int q, bool l)
        : Uy(m, x, y, h), qavat(q), liftBormi(l) {}

    void info() const override {
        cout << "---- Kvartira ----" << endl;
        Uy::info();
        cout << "Qavat: " << qavat << endl;
        cout << "Lift: " << (liftBormi ? "Bor" : "Yo'q") << endl;
    }
};

// Hovli uyi klassi
class HovliUy : public Uy {
    bool garaj;
    double tomorqa;

public:
    HovliUy(string m, int x, double y, bool h, bool g, double t)
        : Uy(m, x, y, h), garaj(g), tomorqa(t) {}

    void info() const override {
        cout << "---- Hovli uyi ----" << endl;
        Uy::info();
        cout << "Garaj: " << (garaj ? "Bor" : "Yo'q") << endl;
        cout << "Tomorqa: " << tomorqa << " m2" << endl;
    }
};

// Uylar ro‘yxatini boshqaruvchi tizim
class UyBoshqaruvTizimi {
    vector<Uy*> uylar;

public:
    void uyQo‘sh(Uy* uy) {
        uylar.push_back(uy);
    }

    void barchaUylar() const {
        cout << "\n--- Barcha uylar ro'yxati ---\n";
        for (const auto& uy : uylar) {
            uy->info();
            cout << "----------------------------\n";
        }
    }

    ~UyBoshqaruvTizimi() {
        for (auto& uy : uylar) {
            delete uy;
        }
    }
};

// Asosiy funksiya
int main() {
    UyBoshqaruvTizimi tizim;

    tizim.uyQo‘sh(new Kvartira("Toshkent, Chilonzor", 3, 85.5, false, 5, true));
    tizim.uyQo‘sh(new HovliUy("Samarqand, Past Darg'om", 4, 120.0, true, true, 250.5));
    tizim.uyQo‘sh(new Kvartira("Andijon, Asaka", 2, 60.0, false, 2, false));
    tizim.uyQo‘sh(new HovliUy("Farg'ana, Buvayda", 5, 150.0, true, false, 400.0));

    tizim.barchaUylar();

    return 0;
}
