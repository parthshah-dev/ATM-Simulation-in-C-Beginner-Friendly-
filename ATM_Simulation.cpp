#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class ATM{
    private: 
        int accpin = -1;
        string name, mob, dob, gen;
        long long accno, totalamount = -1;

    public:
        void generateAcc() {
            srand(static_cast<unsigned>(time(0)));

            // Generate the first 6 digits ensuring it is at least 6 digits
            long long firstPart = 100000 + rand() % 900000; // Random number between 100000 and 999999

            // Generate the second 6 digits ensuring it is at least 6 digits
            long long secondPart = 100000 + rand() % 900000; // Random number between 100000 and 999999

            // Combine them into a 12-digit number
            accno = firstPart * 1000000LL + secondPart;
}

        void openAcc(){
            cout << "\nEnter Account Holder Name: ";
            cin.ignore(); 
            getline(cin, name);
            cout << "\nEnter 10 Digits Mobile Number: ";
            cin >> mob;
            if(mob.length()!=10){
                cout << "10 digits only!!!" << endl;
                return;
            }
            cout << "\nEnter Date of Birth(dd/mm/yyyy): ";
            cin >> dob;
            cout << "\nEnter Gender(male/female/other): ";
            cin >> gen;
            cout << "\nEnter Amount to Deposit Initially (Min 500): ";
            cin >> totalamount;
            if(totalamount < 500){
                cout << "\nInitial amount should be more than 500!!!";
                totalamount = -1;
                return;
            }
            cout << "\n\nCongratulations your account is now opened....";
            generateAcc();
            cout << "\nYour Account Number is: " << accno;
        }

        void setPin(){
            string mo;
            long long acc;
            cout << "\nEnter Account Number: ";
            cin >> acc;
            if(acc != accno){
                cout << "\nInvalid Account Number!!!";
                return;
            }
            cout << "\nEnter Registered Mobile Number: ";
            cin >> mo;
            if(mo != mob){
                cout << "\nInvalid Mobile Number!!!";
            }
            cout << "\nSet a 4 digit Pin: ";
            cin >> accpin;
            if(to_string(accpin).length() != 4){
                cout << "\n4 Digits Only!!!";
                accpin = -1;
                return;
            }
            cout << "\nPin Generation Successfull...";
        }

        void checkBalance(){
            int pin;
            long long acc;
            cout << "\nEnter Account Number: ";
            cin >> acc;
            if(acc != accno){
                cout << "\nInvalid Account Number!!!";
                return;
            }
            else{
                cout << "\nEnter Pin: ";
                cin >> pin;
                if(accpin == -1){
                    cout << "Set the Pin First!!!";
                    return;
                }
                if(pin==accpin){
                    cout << "\nBalance: " << totalamount;
                }else{
                    cout << "\nWrong Pin!!!";
                }
            }
        }

        void withdrawMoney(){
            long long acc;
            int pin, amount;
            cout << "\nEnter Account Number: ";
            cin >> acc;
            if(acc != accno){
                cout << "\nInvalid Account Number!!!";
                return;
            }
            cout << "\nEnter Amount to Withdraw: ";
            cin >> amount;
            if(amount <= 0){
                cout << "\nInvalid Amount!!!";
                return;
            }
            cout << "\nEnter Pin: ";
            cin >> pin;
            if(accpin == -1){
                cout << "Set the Pin First!!!";
                return;
            }
            if(pin==accpin){
                if(totalamount < amount){
                    cout << "\nInsufficient Balance!!! Try Adding Money First";
                    return;
                }
                totalamount -= amount;
                cout << "\nAmount Withdrawl Successfull...";
            }else{
                cout << "\nWrong Pin!!!";
            }
            cout << "\nRemaining Balance: " << totalamount << endl;
        }

        void depositMoney(){
            long long acc;
            int pin, amount;
            cout << "\nEnter Account Number: ";
            cin >> acc;
            if(acc != accno){
                cout << "\nInvalid Account Number!!!";
                return;
            }
            cout << "\nEnter Amount to Deposit: ";
            cin >> amount;
            if(amount <= 0){
                cout << "\nInvalid Amount!!!";
                return;
            }
            cout << "\nEnter Pin: ";
            cin >> pin;
            if(pin==accpin){
                totalamount += amount;
            }else{
                cout << "\nWrong Pin!!!";
            }
            cout << "\nAmount Deposit Successfull...";
            cout << "Remaining Balance: " << totalamount << endl;
        }
};
int main(){
    ATM obj;
    int ch;

    do{
        cout << "\n\n******** ATM Simulation ********";
        cout << "\n1. Open New Account";
        cout << "\n2. Generate New Pin";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Deposit Money";
        cout << "\n5. Check Account Balance";
        cout << "\n6. Exit";
        cout << "\n\nEnter input: ";
        cin >> ch;

        switch (ch)
        {
        case 1: obj.openAcc();
            break;

        case 2: obj.setPin();
            break;
        case 3: obj.withdrawMoney();
            break;
        case 4: obj.depositMoney();
            break;
        case 5: obj.checkBalance();
            break;
    
        default:
            cout << "\nInvalid Input!! Try Again...";
            break;
        }
    }while(ch!=6);

    cout << "\n\nThank You! Visit Again";

    return 0;
}
