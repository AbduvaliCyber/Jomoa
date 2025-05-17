#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <fstream>
using namespace std;

class Plant {
protected:
    string name;
    int age;       // yosh (yil)
    float height;  // balandlik (sm)

public:
    Plant(const string& n = "Unknown", int a = 0, float h = 0.0f)
        : name(n), age(a), height(h) {}

    virtual ~Plant() {}

    virtual void grow() {
        age++;
        height += 5.0f;  // har yili 5 sm o‘sadi
    }

    virtual void print() const {
        cout << "Plant: " << name << ", Age: " << age << " years, Height: " << height << " cm\n";
    }
};

class Bush : public Plant {
private:
    int branches; // shoxlar soni

public:
    Bush(const string& n = "Bush", int a = 0, float h = 0.0f, int b = 0)
        : Plant(n, a, h), branches(b) {}

    void grow() override {
        Plant::grow();
        branches += 3;  // har yili 3ta shox ko‘payadi
    }

    void print() const override {
        cout << "Bush: " << name << ", Age: " << age << " years, Height: " << height
             << " cm, Branches: " << branches << "\n";
    }
};

int main() {
    vector<shared_ptr<Plant>> garden;

    garden.push_back(make_shared<Bush>("Rose", 1, 30.0f, 10));
    garden.push_back(make_shared<Bush>("Lilac", 2, 50.0f, 15));

    for (auto& plant : garden) {
        plant->print();
        plant->grow();
    }

    cout << "After one year:\n";
    for (auto& plant : garden) {
        plant->print();
    }

    return 0;
}
