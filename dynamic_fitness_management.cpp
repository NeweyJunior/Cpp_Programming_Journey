#include <iostream>
#include <string>

using namespace std;

class FitnessCenter{
    public:
        static int personNumber;
        static int priceForMonth;
        static int personLimit;
};

class Customer{
    private:
        int membershipTime;
    public:
        string customerName;

        Customer(string customerName){
            this->customerName = customerName;
            this->membershipTime = 0;
            cout << "======================================== WELCOME! ===========================================\n";
            cout << "Welcome to our fitness center, " << customerName <<"." << endl;
            cout << "=============================================================================================\n";
        }

        void getMembershipTime(){
            cout << "===================================== Informations ==========================================\n";
            cout << "Customer Name: " << customerName << endl;
            cout << "Remaining membership: " << membershipTime << " Months"<< endl; 
            cout << "=============================================================================================\n";
        }

        void setMembershipTime(){
            cout << "===================================== BUY MEMBERSHIP ========================================\n";
            if(FitnessCenter::personNumber < FitnessCenter::personLimit){
                while(true){
                    cout << "How many months would you like the duration to be (please select 1-12): ";
                    cin >> membershipTime;
                    if(membershipTime > 12 || membershipTime < 1){
                        cout << "Please enter a value between 1-12 months. " << endl;
                        continue;
                    }else{
                        int payment;
                        cout << "---- Payment Process ----" << endl;
                        cout << "Price: $" <<  (FitnessCenter::priceForMonth) * membershipTime << endl;
                        cout << "Please enter the amount you wish to pay: ";
                        cin >> payment;

                        if(payment == (FitnessCenter::priceForMonth) * membershipTime){
                            cout << "Membersihp process completed✅" << endl;
                            FitnessCenter::personNumber++;
                            cout << "=============================================================================================\n";
                            break;
                        }else if(payment > (FitnessCenter::priceForMonth) * membershipTime){
                            cout << "Please purchase more memberships or deposit $"<< payment - ((FitnessCenter::priceForMonth) * membershipTime) << " less!" << endl;
                            cout << "=============================================================================================\n";
                            continue;
                        }else if(payment < (FitnessCenter::priceForMonth) * membershipTime){
                            cout << "Please purchase fewer memberships or deposit $"<< ((FitnessCenter::priceForMonth) * membershipTime) - payment << " more!" << endl;
                            cout << "=============================================================================================\n";
                            continue;
                        }
                    }
                }
            }else{
                cout << "Unfortunately, we have no vacancies at the moment, but we hope to see you again later." << endl;
                cout << "=============================================================================================\n";
            }
            
        }
};

int FitnessCenter::personNumber = 0;
int FitnessCenter::priceForMonth = 100;
int FitnessCenter::personLimit = 20;

int main()
{
    string driverNames[21] = {
        "Max Verstappen", "Sergio Perez", "Christian Horner", "Adrian Newey",
        "Fernando Alonso", "Lewis Hamilton", "Charles Leclerc", "Daniel Ricciardo",
        "Carlos Sainz", "George Russell", "Oscar Piastri", "Alexander Albon",
        "Yuki Tsunoda", "Pierre Gasly", "Esteban Ocon", "Lance Stroll",
        "Kevin Magnussen", "Nico Hulkenberg", "Valtteri Bottas", "Sebastian Vettel",
        "Lando Norris"
    };

    Customer* grid[21];

    for(int i = 0; i < 21; i++){
        grid[i] = new Customer(driverNames[i]);
    }

    grid[0]->getMembershipTime();
    grid[0]->setMembershipTime();
    grid[0]->getMembershipTime();

    for(int i = 0; i < 21; i++){
        delete grid[i];
    }

    return 0;
}