#include <iostream>
#include <thread>
#include <chrono>

class AirConditioner {
private:
    float currentTemperature;
    float desiredTemperature;
    bool powerOn;

public:
    AirConditioner(float initialTemp = 25.0) {
        currentTemperature = initialTemp;
        desiredTemperature = initialTemp;
        powerOn = false;
    }

    void turnOn() {
        powerOn = true;
        std::cout << "Konditsioner yoqildi.\n";
    }

    void turnOff() {
        powerOn = false;
        std::cout << "Konditsioner o‘chirildi.\n";
    }

    void setDesiredTemperature(float temp) {
        desiredTemperature = temp;
        std::cout << "Istalgan harorat: " << desiredTemperature << "°C\n";
    }

    void simulate() {
        if (!powerOn) {
            std::cout << "Konditsioner ishlamayapti.\n";
            return;
        }

        std::cout << "Haroratni sozlamoqda...\n";

        while (powerOn && abs(currentTemperature - desiredTemperature) > 0.1) {
            if (currentTemperature < desiredTemperature)
                currentTemperature += 0.5;
            else
                currentTemperature -= 0.5;

            std::cout << "Hozirgi harorat: " << currentTemperature << "°C\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }

        std::cout << "Istalgan haroratga yetdi: " << currentTemperature << "°C\n";
    }

    float getCurrentTemperature() const {
        return currentTemperature;
    }

    bool isOn() const {
        return powerOn;
    }
};

int main() {
    AirConditioner ac(30.0);

    ac.turnOn();
    ac.setDesiredTemperature(22.0);
    ac.simulate();

    ac.turnOff();
    return 0;
}
