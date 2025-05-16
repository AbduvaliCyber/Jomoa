#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Baza klass - Eshik
class Door {
protected:
    string material;
    bool isOpen;

public:
    Door(string mat) : material(mat), isOpen(false) {}

    virtual void open() {
        if (!isOpen) {
            isOpen = true;
            cout << "Eshik ochildi.\n";
        } else {
            cout << "Eshik allaqachon ochiq.\n";
        }
    }

    virtual void close() {
        if (isOpen) {
            isOpen = false;
            cout << "Eshik yopildi.\n";
        } else {
            cout << "Eshik allaqachon yopiq.\n";
        }
    }

    virtual void info() const {
        cout << "Material: " << material << ", Holati: " << (isOpen ? "Ochiq" : "Yopiq") << endl;
    }

    virtual ~Door() {}
};

// Qulfli eshik
class LockedDoor : public Door {
protected:
    bool isLocked;

public:
    LockedDoor(string mat) : Door(mat), isLocked(true) {}

    void lock() {
        if (!isLocked) {
            isLocked = true;
            cout << "Eshik qulflandi.\n";
        } else {
            cout << "Eshik allaqachon qulflangan.\n";
        }
    }

    void unlock() {
        if (isLocked) {
            isLocked = false;
            cout << "Eshik qulfdan chiqarildi.\n";
        } else {
            cout << "Eshik allaqachon qulfdan chiqarilgan.\n";
        }
    }

    void open() override {
        if (isLocked) {
            cout << "Eshik qulflangan! Ochish uchun qulfdan chiqaring.\n";
        } else {
            Door::open();
        }
    }

    void info() const override {
        Door::info();
        cout << "Qulf holati: " << (isLocked ? "Qulflangan" : "Qulfdan chiqqan") << endl;
    }
};

// Elektron eshik
class ElectronicDoor : public LockedDoor {
    bool hasPower;

public:
    ElectronicDoor(string mat) : LockedDoor(mat), hasPower(true) {}

    void powerOff() {
        hasPower = false;
        cout << "Tok o‘chdi. Eshik ishlamaydi.\n";
    }

    void powerOn() {
        hasPower = true;
        cout << "Tok yoqildi. Eshik faol.\n";
    }

    void open() override {
        if (!hasPower) {
            cout << "Tok yo‘q! Eshik ochilmaydi.\n";
        } else {
            LockedDoor::open();
        }
    }

    void info() const override {
        LockedDoor::info();
        cout << "Elektr quvvati: " << (hasPower ? "Bor" : "Yo‘q") << endl;
    }
};

// Bosh menyu
void showMenu() {
    cout << "\n--- Eshiklar Boshqaruvi ---\n";
    cout << "1. Oddiy eshik\n";
    cout << "2. Qulfli eshik\n";
    cout << "3. Elektron eshik\n";
    cout << "0. Chiqish\n";
    cout << "Tanlang: ";
}

int main() {
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 0) {
            cout << "Dastur tugatildi.\n";
            break;
        }

        Door* door = nullptr;

        if (choice == 1)
            door = new Door("Yog‘och");
        else if (choice == 2)
            door = new LockedDoor("Temir");
        else if (choice == 3)
            door = new ElectronicDoor("Zamonaviy plastmassa");
        else {
            cout << "Noto‘g‘ri tanlov.\n";
            continue;
        }

        int action;
        do {
            cout << "\n--- Amalni tanlang ---\n";
            cout << "1. Ochish\n";
            cout << "2. Yopish\n";
            cout << "3. Ma'lumot\n";

            if (LockedDoor* ld = dynamic_cast<LockedDoor*>(door)) {
                cout << "4. Qulfdan chiqarish\n5. Qulfni yopish\n";
            }

            if (ElectronicDoor* ed = dynamic_cast<ElectronicDoor*>(door)) {
                cout << "6. Tokni o‘chirish\n7. Tokni yoqish\n";
            }

            cout << "0. Ortga\nTanlang: ";
            cin >> action;

            switch (action) {
                case 1: door->open(); break;
                case 2: door->close(); break;
                case 3: door->info(); break;
                case 4: {
                    if (auto ld = dynamic_cast<LockedDoor*>(door)) ld->unlock();
                    else cout << "Bu amal mavjud emas.\n";
                    break;
                }
                case 5: {
                    if (auto ld = dynamic_cast<LockedDoor*>(door)) ld->lock();
                    else cout << "Bu amal mavjud emas.\n";
                    break;
                }
                case 6: {
                    if (auto ed = dynamic_cast<ElectronicDoor*>(door)) ed->powerOff();
                    else cout << "Bu amal mavjud emas.\n";
                    break;
                }
                case 7: {
                    if (auto ed = dynamic_cast<ElectronicDoor*>(door)) ed->powerOn();
                    else cout << "Bu amal mavjud emas.\n";
                    break;
                }
                case 0: break;
                default: cout << "Noto‘g‘ri amal.\n";
            }

        } while (action != 0);

        delete door;
    }

    return 0;
}
