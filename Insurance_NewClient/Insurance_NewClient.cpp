#include<iostream>
#include<Windows.h>
#include <string>
#include <fstream>

using namespace std;

struct quoteform
{
    char rego[6], licencetype[1];
    int insurance, birth;
};

void placeCursor(HANDLE, int, int);
void policy();


HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
void logo();
void line();

void quote(fstream& qdata, quoteform& qform);

quoteform qform;
fstream qdata;

int main()
{
    int choice;

    while (true)
    {
    logo();
    placeCursor(screen, 1, 45);
    cout << "\x1b[3;43;30mB I C\033[0m" << endl;
    placeCursor(screen, 4, 39);
    cout << "Best Insurance Cover" << endl;
    cout << endl << endl;
    line();
   
    // company contact align right
    placeCursor(screen, 1, 90);
    cout << "0800 555 5555" << endl;
    placeCursor(screen, 2, 90);
    cout << "21 Here Street, Earth" << endl;
    placeCursor(screen, 3, 90);
    cout << "help@tip.co.nz" << endl;

    // Menu on screen for various users
    placeCursor(screen, 6, 39);
    cout << "Here is a helpful tip!";
    placeCursor(screen, 8, 35);
    cout << "Select 1. To view our Our Policy";
    placeCursor(screen, 9, 35);
    cout << "Select 2. Get a quote";
    placeCursor(screen, 10, 35);
    cout << "Select 3. To Update Your Insurance policy";
    placeCursor(screen, 11, 35);
    cout << "Select 4. To Make a Claim";
    placeCursor(screen, 12, 35);
    cout << "Select 5. For Admin Login";
    placeCursor(screen, 13, 35);
    cout << "Select 6. To Exit the App";
    cout << endl;
    line();

    placeCursor(screen, 15, 35);
    cout << "How can we help? ";
    cin >> choice;
    
    switch (choice)
    {
    case 1:
    {
        system("cls");
        policy();
        break;
    }
    case 2:
    {
        quote(qdata, qform);
        break;
    }
    case 3:
    {
        system("cls");
        cout << "Update Your Insurance policy";
        break;
    }
    case 4:
    {
        cout << "Make a claim";
        break;
    }
    case 5:
    {
        cout << "admin login";
        break;
    }
    case 6:
    {
        cout << "Exit";
        exit(0);
    }
    }
    }

    return 0;

}

void line()
{
    for (int i = 0; i < 110; i++)
    {
        cout << "_";
    }
}

void placeCursor(HANDLE screen, int row, int col)
{

    COORD position;
    position.Y = row;
    position.X = col;
    SetConsoleCursorPosition(screen, position);
}

void logo()
{
    placeCursor(screen, 2, 35);
    for (int i = 0; i <5; i++)
    {
            cout << "x - x";
    }
 
    
}
void policy()
{
    int a;
    placeCursor(screen, 18, 5);
    printf("\x1b[33mFull Cover\033[0m");
    placeCursor(screen,20, 5);
    cout << "Accidental Loss or Damage";
    placeCursor(screen, 21, 5);
    cout << "Fire Damage";
    placeCursor(screen, 22, 5);
    cout << "Theft or illegal converstion";
    placeCursor(screen, 23, 5);
    cout << "Legal Liability";
    placeCursor(screen, 24, 5);
    cout << "Vehicle removal";

    placeCursor(screen, 18, 50);
    printf("\x1b[33mFire and Theft\033[0m"); cout << endl;
    placeCursor(screen, 20, 50);
    cout << "Fire Damage";
    placeCursor(screen, 21, 50);
    cout << "Theft or illegal converstion";
    placeCursor(screen, 22, 50);
    cout << "Legal Liability0";
    placeCursor(screen, 23, 50);
    cout << "Vehicle removal" << endl;

    placeCursor(screen, 18, 90);
    printf("\x1b[33mThird party\033[0m");
    placeCursor(screen, 20, 90);
    cout << "Legal Liability";
    placeCursor(screen, 21, 90);
    cout << "Vehicle removal" << endl;
    placeCursor(screen, 27, 35);
    cout << "\x1b[33mWould You like to continue to..\033[0m";
    placeCursor(screen, 28, 35);
    cout << "1. Get a quote?";
    placeCursor(screen, 29, 35);
    cout << "2. Exit to home page?";
    ("pause");
    cin >> a;
    switch (a)
    {
    case 1:
    {
        system("cls");
        quote(qdata, qform);
    }
    case 2:
    {
        break;
    }
    }
}
void quote(fstream& qdata, quoteform& qform)
{
    char a, b;
    
    system("cls");
    placeCursor(screen, 18, 5);
    cout << "\x1b[3;43;30mGet Your Quote\033[0m" << endl;
    placeCursor(screen, 20, 5);
    // this will go into a from which can be pulled when policy will be taken out.
    cout << "Is this quote for a Car (c) or Motorbike (m)? : ";
    cin >> a;

    if (a == 'c')
    {
        qdata.open("quoteform.dat", ios::out | ios:: app | ios::binary);
        placeCursor(screen, 21, 5);
        cin.ignore();
        cout << "What is your Car's Registration Number?";
        cin.getline(qform.rego, 6);
        placeCursor(screen, 22, 5);
        cout << "Enter your birth year e.g 2001";
        cin >> qform.birth;
            if (qform.birth < 2003)
            {
                cout << "You are not old enough to take out insurance";
                exit(0);
            }
        placeCursor(screen, 23, 5);
        cout << "What type of Licence do you have ?";
        cin >> b;

        placeCursor(screen, 22, 50);
        cout << "[F] Full NZ Licence" << endl;
        cout << "[R] Restricted NZ Licencee" << endl;
        cout << "[X] Foreign" << endl;
        cout << "[N] No Licence" << endl;

    }
  /*  else if (a == 'm')
    {
        qdata.open("quoteform.dat", ios::out | ios::app | ios::binary);
        placeCursor(screen, 21, 5);
        cout << "Enter your birth year e.g 2001";
        cin >> 
        if (qform.birth < '2003')
        {

        }*/
  
    else
    {
        exit(0);
    }
    qdata.close();
}
