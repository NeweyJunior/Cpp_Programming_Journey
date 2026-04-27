#include <iostream>
#include <string>

using namespace std;

class carPart{
    public:
        string partName;

        carPart(string partName){
            this->partName = partName;
        }

        virtual void inspect(){
            cout << "General parts are being examined..." << endl;
        }

        virtual ~carPart(){}
};

class engine : public carPart {
    public:
        engine(string partName) : carPart(partName){}

        void inspect() override{
            cout << partName <<" testing: Honda RBPTH02 RPM data is stable!" << endl;
        }
};

class gearBox : public carPart{
    public:
        gearBox(string partName) : carPart(partName){}

        void inspect() override{
            cout << partName <<" testing: 8-speed synchronizers are running perfectly!" << endl;
        }
};

class carSystem{
    public:
        carPart* components[2];

        void runAllDiagnostics(){
            for(int i = 0; i < 2; i++){
                components[i]->inspect();
            }
        }
};

int main()
{
    carSystem* mySystem = new carSystem;

    mySystem->components[0] = new engine("Honda Engine");
    mySystem->components[1] = new gearBox("RBPT GearBox");

    mySystem->runAllDiagnostics();

    delete mySystem->components[0];
    delete mySystem->components[1];
    delete mySystem;

    return 0;
}