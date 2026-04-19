#include <iostream>
using namespace std;

class Device {
protected:
    string* deviceName;
    int* deviceID;

public:
    Device(string name, int id) {
        deviceName = new string;
        deviceID = new int;

        *deviceName = name;
        *deviceID = id;

        cout << "Device Constructor Called\n";
    }

    void displayDevice() {
        cout << "Device Name: " << *deviceName << endl;
        cout << "Device ID: " << *deviceID << endl;
    }

    ~Device() {
        cout << "Device Destructor Called\n";
        delete deviceName;
        delete deviceID;
    }
};

class Sensor : public Device {
private:
    string* sensorType;

public:
    Sensor(string name, int id, string type) : Device(name, id) {
        sensorType = new string;
        *sensorType = type;

        cout << "Sensor Constructor Called\n";
    }

    void displaySensor() {
        displayDevice();
        cout << "Sensor Type: " << *sensorType << endl;
    }

    ~Sensor() {
        cout << "Sensor Destructor Called\n";
        delete sensorType;
    }
};

int main() {
    Sensor* s1 = new Sensor("DeviceA", 101, "Temperature");

    s1->displaySensor();

    delete s1;

    return 0;
}
