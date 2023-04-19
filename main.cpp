#include <iostream>
#include <fstream>
using namespace std;

class employee
{
public:
    fstream file1,file2;
    float da, hra, gs, bs;
    char emp_fname[30], emp_lname[30];
    int emp_id;

    void show()
    {
        file1.open("header.txt", ios::in);
        if (!file1)
        {
            cout << "File Can't Be Opened";
        }
        else
        {
            string myText;
            while (getline(file1, myText))
            {

                cout << myText << endl;
            }
            file1.close();
        }
    }

    void getData()
    {
        cout << "Enter Employee First Name : ";
        cin >> emp_fname;
        cout << "\nEnter Employee Last Name : ";
        cin >> emp_lname;
        cout << "\nEnter Employee ID : ";
        cin >> emp_id;
        cout << "\nEnter Basic Salary : ";
        cin >> bs;
    }
};
class cal : public employee
{
public:
    void calc()
    {
        da = (bs * 74.5) / 100;
        hra = (bs * 30) / 100;
        gs = bs + da + hra;
    }
};
class display : public cal
{
public:
    void header()
    {
        file1.open("data.txt", ios::out);
        file1 << "************************ SALARY MANAGERMENT SYSTEM ************************" << endl;
        file1.close();
    }
    void writeData()
    {
        if (!file1)
        {
            cout << "File Can't Be Opened";
        }
        else
        {
            file1.open("data.txt", ios::app);
            file1 << endl;
            file1 << "\t\t\tEmploye Name : " << emp_fname << " " << emp_lname << endl;
            file1 << "\t\t\tEmployee ID  : " << emp_id << endl;
            file1 << "\t\t\tBasic Salary : "
                  << "Rs. " << bs << endl;
            file1 << "\t\t\tDA           : " << da << endl;
            file1 << "\t\t\tHRA          : " << hra << endl;
            file1 << "\t\t\tGross Salary : "
                  << "Rs. " << gs << endl;
            file1 << endl;
            file1 << "**************************************************************************" << endl;
            file1.close();
        }
    }
    void readData()
    {
        file2.open("data.txt", ios::in);
        if (!file2)
        {
            cout << "File Can't Be Opened";
        }
        else
        {
            string myText;
            while (getline(file2, myText))
            {

                cout << myText << endl;
            }
            file2.close();
        }
    }
};

int main()
{
    int choice;
    string uid = "uid", pwd = "pwd";
    display d1;
    cout << "Enter UID : ";
    cin >> uid;
    cout << "\nEnter Password : ";
    cin >> pwd;
    if (uid == "uid" && pwd == "pwd")
    {
        d1.show();
        d1.header();
        while (1)
        {
            cout << "1. New Salary Entry" << endl;
            cout << "2. View Salary" << endl;
            cout << "3. Exit" << endl;
            cin >> choice;
            if (choice == 1)
            {
                d1.getData();
                d1.calc();
                d1.writeData();
            }
            else if (choice == 2)
            {
                d1.readData();
            }
            else if (choice == 3)
            {
                cout << "Exiting.... Thanks For Using Our Software :)";
                exit(0);
            }
            else
            {
                cout << "Invalid Input\n";
            }
        }
    }
    else
    {
        cout << "Wrong Password, Exiting System!!!";
    }
    return 0;
}