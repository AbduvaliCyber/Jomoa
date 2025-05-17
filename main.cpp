#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Light {
protected:
    string name;
    bool isOn;
    float intensity; // 0.0 dan 1.0 gacha

public:
    Light(string n, float inten = 1.0f) : name(n), isOn(false), intensity(inten) {
        if (intensity < 0.0f) intensity = 0.0f;
        if (intensity > 1.0f) intensity = 1.0f;
    }

    virtual ~Light() {}

    virtual void turnOn() {
        isOn = true;
    }

    virtual void turnOff() {
        isOn = false;
    }

    virtual void setIntensity(float inten) {
        if (inten < 0.0f || inten > 1.0f) {
            cout << "Noto'g'ri intensivlik! 0.0 - 1.0 oralig'ida bo'lishi kerak.\n";
            return;
        }
        intensity = inten;
    }

    virtual void printStatus() const {
        cout << "Light '" << name << "' is " << (isOn ? "ON" : "OFF")
             << ", Intensity: " << intensity << endl;
    }
};

class PointLight : public Light {
private:
    float x, y, z; // joylashuv

public:
    PointLight(string n, float xx, float yy, float zz, float inten = 1.0f)
        : Light(n, inten), x(xx), y(yy), z(zz) {}

    void setPosition(float xx, float yy, float zz) {
        x = xx; y = yy; z = zz;
    }

    void printStatus() const override {
        cout << "PointLight '" << name << "' at (" << x << ", " << y << ", " << z << ") "
             << (isOn ? "ON" : "OFF") << ", Intensity: " << intensity << endl;
    }
};

class DirectionalLight : public Light {
private:
    float dirX, dirY, dirZ; // yo'nalish

public:
    DirectionalLight(string n, float dx, float dy, float dz, float inten = 1.0f)
        : Light(n, inten), dirX(dx), dirY(dy), dirZ(dz) {}

    void setDirection(float dx, float dy, float dz) {
        dirX = dx; dirY = dy; dirZ = dz;
    }

    void printStatus() const override {
        cout << "DirectionalLight '" << name << "' direction (" << dirX << ", " << dirY << ", " << dirZ << ") "
             << (isOn ? "ON" : "OFF") << ", Intensity: " << intensity << endl;
    }
};

class LightManager {
private:
    vector<Light*> lights;

public:
    ~LightManager() {
        for (auto l : lights)
            delete l;
    }

    void addLight(Light* l) {
        lights.push_back(l);
    }

    void turnAllOn() {
        for (auto l : lights)
            l->turnOn();
    }

    void turnAllOff() {
        for (auto l : lights)
            l->turnOff();
    }

    void printAll() const {
        cout << "------ All Lights Status ------\n";
        for (auto l : lights)
            l->printStatus();
        cout << "------------------------------\n";
    }
};

int main() {
    LightManager lm;

    PointLight* pl1 = new PointLight("Lamp1", 1.0f, 2.0f, 3.0f, 0.8f);
    DirectionalLight* dl1 = new DirectionalLight("SunLight", 0.0f, -1.0f, 0.0f, 1.0f);

    lm.addLight(pl1);
    lm.addLight(dl1);

    lm.printAll();

    pl1->turnOn();
    dl1->turnOn();

    lm.printAll();

    pl1->setPosition(5.0f, 5.0f, 5.0f);
    dl1->setDirection(1.0f, 0.0f, 0.0f);
    pl1->setIntensity(0.5f);

    lm.printAll();

    lm.turnAllOff();
    lm.printAll();

    return 0;
}
