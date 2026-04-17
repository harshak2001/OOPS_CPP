#include <iostream>
#include <memory>

// Abstract class representing a generic device
class Device {
public:
    virtual void turnOn() const = 0;
    virtual void turnOff() const = 0;
    virtual ~Device() = default;
};

class TV : public Device {
public:
    void turnOn() const override {
        std::cout << "TV is turning on..." << std::endl;
    }
    void turnOff() const override {
        std::cout << "TV is turning off..." << std::endl;
    }
};

class Radio : public Device {
public:
    void turnOn() const override {
        std::cout << "Radio is turning on..." << std::endl;
    }
    void turnOff() const override {
        std::cout << "Radio is turning off..." << std::endl;
    }
};

int main() {
    std::unique_ptr<Device> device;

    // Use the abstraction of a Device without knowing the concrete type
    device = std::make_unique<TV>();
    device->turnOn();
    device->turnOff();

    device = std::make_unique<Radio>();
    device->turnOn();
    device->turnOff();

    return 0;
}
