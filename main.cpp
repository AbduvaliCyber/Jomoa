#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

// Baza sinf: Televizor
class Television {
protected:
    string brand;
    int screenSize;
    double price;
    bool isOn;
    int volume;
    int channel;

public:
    Television(string br, int size, double pr)
        : brand(br), screenSize(size), price(pr), isOn(false), volume(10), channel(1) {}

    virtual void powerOn() {
        isOn = true;
        cout << brand << " televizori yoqildi.\n";
    }

    virtual void powerOff() {
        isOn = false;
        cout << brand << " televizori o‘chirildi.\n";
    }

    virtual void volumeUp() {
        if (isOn && volume < 100) {
            volume++;
            cout << brand << " ovozi: " << volume << endl;
        }
    }

    virtual void volumeDown() {
        if (isOn && volume > 0) {
            volume--;
            cout << brand << " ovozi: " << volume << endl;
        }
    }

    virtual void changeChannel(int ch) {
        if (isOn && ch > 0 && ch <= 999) {
            channel = ch;
            cout << brand << " kanal o‘zgartirildi: " << channel << endl;
        }
    }

    virtual void showInfo() const {
        cout << "📺 Brend: " << brand
             << ", O‘lcham: " << screenSize << "\""
             << ", Narx: $" << price
             << ", Holati: " << (isOn ? "Yoqilgan" : "O‘chirilgan")
             << ", Ovoz: " << volume
             << ", Kanal: " << channel << endl;
    }

    virtual ~Television() {}
};

// Merosxo‘r sinf: Smart TV
class SmartTV : public Television {
private:
    vector<string> apps;

public:
    SmartTV(string br, int size, double pr)
        : Television(br, size, pr) {
        apps = {"YouTube", "Netflix", "HBO Max"};
    }

    void openApp(const string& appName) {
        if (isOn) {
            for (const string& app : apps) {
                if (app == appName) {
                    cout << brand << " da " << appName << " ochildi.\n";
                    return;
                }
            }
            cout << appName << " ilovasi topilmadi.\n";
        }
    }

    void showInfo() const override {
        Television::showInfo();
        cout << "📱 Ilovalar: ";
        for (const string& app : apps) {
            cout << app << " ";
        }
        cout << endl;
    }
};

// Televizorlar ro‘yxatini boshqaruvchi menejer sinf
class TVManager {
private:
    vector<shared_ptr<Television>> tvList;

public:
    void addTV(shared_ptr<Television> tv) {
        tvList.push_back(tv);
    }

    void listAllTVs() {
        cout << "\n=== Televizorlar ro‘yxati ===\n";
        for (size_t i = 0; i < tvList.size(); ++i) {
            cout << "ID: " << i + 1 << " -> ";
            tvList[i]->showInfo();
        }
    }

    void controlTV(int index) {
        if (index >= 0 && index < (int)tvList.size()) {
            auto& tv = tvList[index];
            tv->powerOn();
            tv->changeChannel(5);
            tv->volumeUp();
            tv->volumeDown();
            if (SmartTV* smart = dynamic_cast<SmartTV*>(tv.get())) {
                smart->openApp("YouTube");
            }
            tv->powerOff();
        } else {
            cout << "Noto‘g‘ri ID kiritildi.\n";
        }
    }
};

int main() {
    TVManager manager;

    shared_ptr<Television> tv1 = make_shared<Television>("Samsung", 42, 499.99);
    shared_ptr<Television> tv2 = make_shared<SmartTV>("LG", 55, 899.99);
    shared_ptr<Television> tv3 = make_shared<SmartTV>("Sony", 65, 1199.99);

    manager.addTV(tv1);
    manager.addTV(tv2);
    manager.addTV(tv3);

    manager.listAllTVs();

    int choice;
    cout << "\nQaysi televizorni boshqarmoqchisiz? (ID ni kiriting): ";
    cin >> choice;
    manager.controlTV(choice - 1);

    return 0;
}
