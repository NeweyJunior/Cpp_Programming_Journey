#include <iostream>
#include <string>

using namespace std;

class sensor{
    public:
        string sensorName;

        sensor(string sensorName){
            this->sensorName = sensorName;
        }

        virtual void readData(){
            cout << "Sensor datas is reading..." << endl;
        }

        virtual ~sensor(){}
};

class tempSensor : public sensor{
    public:
        tempSensor(string sensorName) : sensor(sensorName){

        }

        void readData() override{
            cout << sensorName << " is readed. Engine temperature is 100 degrees." << endl;
        }
};

class pressureSensor : public sensor{
    public:
        pressureSensor(string sensorName) : sensor(sensorName){

        }

        void readData() override{
            cout << sensorName << " is readed. Pressure is 22.5 PSI." << endl;
        }
};

class telemetryBoard{
    public:
        sensor* activeSensor;

        void showDashBoard(){
            activeSensor->readData();
        }
};

int main()
{
    telemetryBoard* newSensor = new  telemetryBoard;
    int sensorType;
    cout << "Please enter your sensor type (1-Temperature / 2-Pressure): ";
    cin >> sensorType;

    switch(sensorType){
        case 1: newSensor->activeSensor = new tempSensor("RB19 V6 Turbo");
            break;
        case 2: newSensor->activeSensor = new pressureSensor("Pirelli Soft");
            break;
        default: newSensor->activeSensor = new tempSensor("RB19 V6 Turbo");
            break;
    }

    newSensor->showDashBoard();

    delete newSensor->activeSensor;
    delete newSensor;

    return 0;
}