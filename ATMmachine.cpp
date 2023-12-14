#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
class ATM
{
private:
    long int account_no;
    int pin;
    string name;
    double account_bal;
    string mobile_no;

public:
    void setData(long int account_no_a, int pin_a, string name_a, double account_bal_a, string mobile_no_a)
    {
        account_no = account_no_a;
        pin = pin_a;
        name = name_a;
        account_bal = account_bal_a;
        mobile_no = mobile_no_a;
    }

    long int getAccountNo()
    {
        return account_no;
    }

    int getPIN()
    {
        return pin;
    }
    string getName()
    {
        return name;
    }
    double getAccountBal()
    {
        return account_bal;
    }
    string getMobileNo()
    {
        return mobile_no;
    }
    void setMobile(string mobile_pre, string mobile_new)
    {
        if (mobile_pre == mobile_no)
        {
            mobile_no = mobile_new;
            cout << endl
                 << "Successfully updated your mobile no.";
            getch();
        }
        else
        {
            cout << endl
                 << "Incorrect mobile no. please provide correct old mobile no.";
            _getch();
        }
    }

    void cashWithdrawl(int amount_a)
    {
        if (amount_a > 0 && amount_a < account_bal)
        {
            account_bal -= amount_a;
            cout << endl
                 << "Please collect your cash\n";
            cout << endl
                 << "your available balance is :" << account_bal;
            _getch();
        }
        else
        {
            cout << endl
                 << "Invalid amount or insufficient balance";
            _getch();
        }
    }
};

int main()
{
    int choice = 0, enterPIN , n;
    long int enterAccountNo;
    system("cls");

    ATM user1;
    // list of user's
    user1.setData(123456789, 2005, "kartik", 400000, "9300868487");
    user1.setData(987654321, 2222, "RAM", 10, "5555666333");
    user1.setData(553566320, 4455, "JOE", 6500, "6655442211");
    user1.setData(456321595, 5544, "SENSI", 10000000, "2288446696");
    user1.setData(445512632, 2233, "PRITAM", 1400000, "1166779944");
    user1.setData(779564821, 1212, "BABLU", 55, "1800108080");
    user1.setData(124563987, 8956, "SANKET", 852, "4695713511");
    user1.setData(456328719, 7458, "DEVANSH", 456, "7711993366");

    ATM user2;
    user2.setData(111111111, 1111, "OWNER", 0, " ");
   
    do
    {
        system("cls");
        cout << endl;
             << "Welcome to Atm\n";
        cout << endl;
             << "Enter your account no. : ";
        cin >> enterAccountNo;
        cout << endl;
             << "Enter your PIN : ";
        cin >> enterPIN;
        cout << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            if ((enterAccountNo == user2.getAccountNo()) && (enterPIN == user2.getPIN()))
            {n=7;

                for (int i = 0; i < n; i++)
                {
                    cout << user1.getName()<< " " << user1.getAccountNo()<< " " << user1.getMobileNo()<< " " << user1.getAccountBal();
                    cout<<endl;               
                }
                getch();
            }
            break;

        case 2:
        if ((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
        {
            do
            {
                int amount = 0;
                string oldMobileNo, newMobileNo;
                system("cls");

                cout << endl
                     << "Welcome to Atm\n";
                cout << endl
                     << "Select Option\n";
                cout << "1. Cash withdrawal\n 2.Check Balance \n 3. Show user details\n 4. Update Mobile No.\n 5. Exit\n";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "enter your amount : ";
                    cin >> amount;
                    user1.cashWithdrawl(amount);
                    break;

                case 2:
                    cout << "your bank balance is : " << user1.getAccountBal();
                    _getch();
                    break;

                case 3:
                    cout << endl
                         << "user details\n";
                    cout << endl
                         << "name :" << user1.getName();
                    cout << endl
                         << "Account No. :" << user1.getAccountNo();
                    cout << endl
                         << "Mobile No. :" << user1.getMobileNo();
                    cout << endl
                         << "Account balance :" << user1.getAccountBal();
                    _getch();
                    break;

                 case 4:
                    cout << endl
                         << "Enter your old mobile No. : ";
                    cin >> oldMobileNo;

                    cout << endl
                         << "Enter your new Mobile No. : ";
                    cin >> newMobileNo;

                    user1.setMobile(oldMobileNo, newMobileNo);
                    break;

                case 5:
                    exit(0);

                default:
                    cout << "Enter valid data!!!";
                }
            }
             while (1);
        }
        break;
        default:
            printf("INVALID...");
       
        }
    } while (1);

    return 0;
}
