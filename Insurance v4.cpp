#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <vector>


using namespace std;

struct client
{
    char name[51], surname[51], number[15], address1[51], address2[51], gender[5], username[51], password[51], email[51],
        sdate[15], edate[15], dob[15];
    int p1, p2, ptotal;
    char rego1[15], rego2[15];
    char pd1[150], pd2[150], renew;
};

//alex Structure 
struct admin
{
    int s;
    char uName[51];
    char pass[51];
    char name[51];
    char email[51];
    char phone[51];
};


//alex structure
struct claim
{
    char firstName[51];
    char lastName[51];
    char addressLine1[51];
    char addressLine2[51];
    char phone[14];
    char email[51];
    char description[300];
    char time[15];
    char date[12];
    char dateStart[12];
    char dateEnd[12];
    char otherfirstName[51];
    char otherlastName[51];
    char otherphone[14];
    char otheremail[51];
    char insCompany[51];
    char otherRego[10];
    char count[51];
    char policeRE[2];
    char vehType[5];
    char vehMake[51];
    char vehYear[5];
    char PolNum[51];
    char rego[10];
};

// STYLING
HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
void placeCursor(HANDLE, int, int);
void line();
void heading();

// NOLENE'S FUNCTIONS
void policy();
void newclient(client& clients);
void signup();
void clientdisplay();
void clientedit();
void clientupdate();
void clientrenew();

//ALEX FUNCTIONS
void claims();
void adminLogin();
void registerAdmin();
void adminlogMenu();
void adminmainMenu();
void updateDis();
void customerReport();
void weeklyClaims();
void weeklyRenew();
void weeklyRegi();


int choice;
client clients;
int renew = '0';

int main()
{
    // LIST OF POLICIES //
    char pc[6][150] = { "1.Full Cover for your Car for $50",
        "2.Only Fire and Theft for your car $25",
        "3.Only Third Party cover for your car $10",
        "4.Full Cover for your Motorcylce for $55",
        "5.Only Fire and Theft for your Motorcylce for $30",
        "6.Only Third Party cover for your Motorcycle $12",
    };

    while (true)
    {
        heading();
        // MAIN MENU AND HOME PAGE
        placeCursor(screen, 6, 39);
        cout << "Here is a helpful tip!";
        placeCursor(screen, 8, 35);
        cout << "Select 1. To view Our Policy and Benefits";
        placeCursor(screen, 9, 35);
        cout << "Select 2. Sign up to the Best Insurance Company";
        placeCursor(screen, 10, 35);
        cout << "Select 3. To View, Update or Renew your Policy";
        placeCursor(screen, 11, 35);
        cout << "Select 4. To Make a Claim";
        placeCursor(screen, 12, 35);
        cout << "Select 5. For Admin Login";
        placeCursor(screen, 13, 35);
        cout << "Select 6. To Exit the App";
        cout << endl;
        line();

        //HOME PAGE WITH SWITCH CASE TO ALL MENU OPTIONS
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
            system("cls");
            newclient(clients);
            break;
        }
        case 3:
        {
            system("cls");
            clientdisplay();
            break;
        }
        case 4:
        {
            system("cls");
            claims();
            break;
        }
        case 5:
        {
            system("cls");
            //adminmainMenu();
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

// FUNCTIONS // 
// STYLING // 
void placeCursor(HANDLE screen, int row, int col)
{

    COORD position;
    position.Y = row;
    position.X = col;
    SetConsoleCursorPosition(screen, position);
}
void line() // LINE OF _ x 110
{
    for (int i = 0; i < 110; i++)
    {
        cout << "_";
    }
}
// COMPANY HEADER APPEARING ON EACH 'PAGE' // -
void heading()
{
    //COMPANY LOGO CENTRED
    placeCursor(screen, 1, 45);
    cout << "\x1b[3;43;30mB I C\033[0m" << endl;
    placeCursor(screen, 2, 35);
    for (int i = 0; i < 5; i++)
    {
        cout << "x - x";
    }
    placeCursor(screen, 4, 39);
    cout << "Best Insurance Cover" << endl;
    cout << endl << endl;
    line();

    // company contact align right
    placeCursor(screen, 1, 90);
    cout << "0800 GO BIG " << endl;
    placeCursor(screen, 2, 90);
    cout << "21 Bigger Street, Earth" << endl;
    placeCursor(screen, 3, 90);
    cout << "help@bic.co.nz" << endl;
}

// MENU # 1 // -
// DISPLAYING POLICIES AND OPTION TO SIGN UP - void newclient OR RETURN TO MAIN MENU
void policy()
{
    heading();
    int a;
    placeCursor(screen, 10, 5);
    printf("\x1b[33mFull Cover\033[0m");
    placeCursor(screen, 12, 5);
    cout << "Accidental Loss or Damage";
    placeCursor(screen, 13, 5);
    cout << "Fire Damage";
    placeCursor(screen, 14, 5);
    cout << "Theft or illegal converstion";
    placeCursor(screen, 15, 5);
    cout << "Legal Liability";
    placeCursor(screen, 16, 5);
    cout << "Vehicle removal";
    placeCursor(screen, 18, 5);
    cout << fixed << showpoint;
    printf("\x1b[33mCar\033[0m"); cout << setw(12) << " $50 per month";
    placeCursor(screen, 19, 5);
    printf("\x1b[33mMotorcycle\033[0m"); cout << setw(12) << " $55 per month";

    placeCursor(screen, 10, 50);
    printf("\x1b[33mFire and Theft\033[0m"); cout << endl;
    placeCursor(screen, 12, 50);
    cout << "Fire Damage";
    placeCursor(screen, 13, 50);
    cout << "Theft or illegal converstion";
    placeCursor(screen, 14, 50);
    cout << "Legal Liability0";
    placeCursor(screen, 15, 50);
    cout << "Vehicle removal" << endl;
    placeCursor(screen, 18, 50);
    cout << fixed << showpoint;
    printf("\x1b[33mCar\033[0m"); cout << setw(12) << " $25 per month";
    placeCursor(screen, 19, 50);
    printf("\x1b[33mMotorcycle\033[0m"); cout << setw(12) << " $30 per month";

    placeCursor(screen, 10, 90);
    printf("\x1b[33mThird party\033[0m");
    placeCursor(screen, 12, 90);
    cout << "Legal Liability";
    placeCursor(screen, 13, 90);
    cout << "Vehicle removal" << endl;
    placeCursor(screen, 18, 90);
    cout << fixed << showpoint;
    printf("\x1b[33mCar\033[0m"); cout << setw(12) << " $10 per month";
    placeCursor(screen, 19, 90);
    printf("\x1b[33mMotorcycle\033[0m"); cout << setw(12) << " $12 per month";

    placeCursor(screen, 22, 5);
    cout << "\x1b[3;43;30mBenefits for signing up to BIC insurance\033[0m";
    placeCursor(screen, 23, 5);
    cout << "5% discount if you take out 2 policies";

    placeCursor(screen, 25, 5);
    cout << "\x1b[3;43;30mWould You like to continue to..\033[0m";
    placeCursor(screen, 27, 5);
    cout << "1. Sign up a BIC Insurance";
    placeCursor(screen, 29, 5);
    cout << "2. Exit to home page ";
    placeCursor(screen, 25, 50);
    cin >> a;
    switch (a)
    {
    case 1:
    {
        system("cls");
        newclient(clients);
        break;
    }
    case 2:
    {
        system("cls");
        break;
    }
    }
}

// MENU #2 //
// NEW CLIENT SIGN UP // 
void newclient(client& clients)
{
    fstream insurance;
    insurance.open("clientform.dat", ios::out | ios::app | ios::binary);

    heading();
    placeCursor(screen, 10, 5);
    cout << "\x1b[3;43;30mNEW CLIENT PAGE\033[0m" << endl;
    cin.ignore();
    placeCursor(screen, 11, 5);
    cout << "Enter Policy Start Date (dd/mm/yy) : ";
    cin.getline(clients.sdate, 15);
    placeCursor(screen, 11, 70);
    cout << "Enter Policy End Date (dd/mm/yy) : ";
    cin.getline(clients.edate, 15);
    placeCursor(screen, 12, 5);
    cout << "Please enter first name : ";
    cin.getline(clients.name, 51);
    placeCursor(screen, 12, 70);
    cout << "Please enter last name : ";
    cin.getline(clients.surname, 51);
    placeCursor(screen, 13, 5);
    cout << "Street name and number : ";
    cin.getline(clients.address1, 51);
    placeCursor(screen, 13, 70);
    cout << "Town : ";
    cin.getline(clients.address2, 51);
    placeCursor(screen, 14, 5);
    cout << "Gender (m / f / x) : ";
    cin.getline(clients.gender, 5);
    placeCursor(screen, 14, 70);
    cout << "Date of Birth (dd/yy/mm): ";
    cin.getline(clients.dob, 15);
    placeCursor(screen, 15, 5);
    cout << "Choose a username : ";
    cin.getline(clients.username, 51);
    placeCursor(screen, 15, 70);
    cout << "Choose a password : ";
    cin.getline(clients.password, 51);
    placeCursor(screen, 16, 5);
    cout << "Please enter your email address : ";
    cin.getline(clients.email, 51);

    // displaying policies and pick from two.
    insurance.write(reinterpret_cast<char*>(&clients), sizeof(clients));

    insurance.close();

    system("cls");
    signup();
    
    system("cls");
    main();
}

void signup()
{
    client clients;
    fstream insurance;
    int num;
    int num2;
    int count = 0;
    int total = 0;
    int i = 0;
    int p1 = 0;
    int p2 = 0;
    int p1total = 0;
    int p2total = 0;
    char add;
    int discount;



    char pc[6][150] = { "1.Full Cover for your Car for $50",
        "2.Only Fire and Theft for your car $25",
        "3.Only Third Party cover for your car $10",
        "4.Full Cover for your Motorcylce for $55",
        "5.Only Fire and Theft for your Motorcylce for $30",
        "6.Only Third Party cover for your Motorcycle $12",
    };

    placeCursor(screen, 9, 5);
    cout << "\x1b[3;43;30mPOLICY SIGN UP FORM\033[0m";
    placeCursor(screen, 10, 5);
    cout << "1.Full Cover for your Car for $50";
    placeCursor(screen, 11, 5);
    cout << "2.Only Fire and Theft for your car $25";
    placeCursor(screen, 12, 5);
    cout << "3.Only Third Party cover for your car $10";
    placeCursor(screen, 13, 5);
    cout << "4.Full Cover for your Motorcylce for $55";
    placeCursor(screen, 14, 5);
    cout << "5.Only Fire and Theft for your Motorcylce for $30";
    placeCursor(screen, 15, 5);
    cout << "6.Only Third Party cover for your Motorcycle $12";

    

    insurance.open("clientform.dat", ios::out | ios::app | ios::binary);

    placeCursor(screen, 17, 5);
    cout << endl << "\x1b[3;43;30mCHOOSE A POLICY : \033[0m ";
    cin >> num;

    placeCursor(screen, 19, 5);
    cin.ignore();
    cout << "Enter Car Registration : ";
    cin.getline(clients.rego1, 15);
    count++;

    if (num == 1)
    {
        p1 = 1;
        clients.p1 = p1;
        p1total = 50;
        clients.ptotal = p1total;
        insurance.write(reinterpret_cast<char*>(&clients), sizeof(clients));
    }
    if (num == 2)
    {
        p1 = 2;
        clients.p1 = p1;
        p1total = 25;
        clients.ptotal = p1total;
        insurance.write(reinterpret_cast<char*>(&clients), sizeof(clients));
    }
    if (num == 3)
    {
        p1 = 3;
        clients.p1 = p1;
        p1total = 10;
        clients.ptotal = p1total;
        insurance.write(reinterpret_cast<char*>(&clients), sizeof(clients));
    }
    if (num == 4)
    {
        p1 = 4;
        clients.p1 = p1;
        p1total = 55;
        clients.ptotal = p1total;
        insurance.write(reinterpret_cast<char*>(&clients), sizeof(clients));
    }
    if (num == 5)
    {
        p1 = 5;
        clients.p1 = p1;
        p1total = 30;
        clients.ptotal = p1total;
        insurance.write(reinterpret_cast<char*>(&clients), sizeof(clients));
    }
    if (num == 6)
    {
        p1 = 6;
        clients.p1 = p1;
        p1total = 12;
        clients.ptotal = p1total;
        insurance.write(reinterpret_cast<char*>(&clients), sizeof(clients));
    }



    insurance.write(reinterpret_cast<char*>(&clients), sizeof(clients));

    placeCursor(screen, 21, 5);
    cout << "Would you like to add another policy? Y/N ";
    cin >> add;

    if (add == 'y' || add == 'Y');
    {
        placeCursor(screen, 23, 5);
        cout << endl << "\x1b[3;43;30mCHOOSE A SECOND POLICY : \033[0m";
        cin >> num2;
        placeCursor(screen, 25, 5);
        cout << "Enter Car Registration : ";
        cin.ignore();
        cin.getline(clients.rego1, 15);
        insurance.write(reinterpret_cast<char*>(&clients), sizeof(clients));
        count++;
    }

    if (num2 == 1)
    {
        p2 = 1;
        p2total = 50;
        discount = (p1total + p2total) * (5 / 100);
        clients.p2 = p2;
        clients.ptotal = p1total + p2total - discount;
        insurance.write(reinterpret_cast<char*>(&clients), sizeof(clients));

    }
    if (num2 == 2)
    {
        p2 = 2;
        p2total = 25;
        discount = (p1total + p2total) * (5 / 100);
        clients.p2 = p2;
        clients.ptotal = p1total + p2total - discount;
        insurance.write(reinterpret_cast<char*>(&clients), sizeof(clients));
    }
    if (num2 == 3)
    {
        p2 = 3;
        p2total = 10;
        discount = (p1total + p2total) * (5 / 100);
        clients.p2 = p2;
        clients.ptotal = p1total + p2total - discount;
        insurance.write(reinterpret_cast<char*>(&clients), sizeof(clients));
    }
    if (num2 == 4)
    {
        p2 = 4;
        p2total = 55;
        discount = (p1total + p2total) * (5 / 100);
        clients.p2 = p2;
        clients.ptotal = p1total + p2total - discount;
        insurance.write(reinterpret_cast<char*>(&clients), sizeof(clients));;
    }
    if (num2 == 5)
    {
        p2 = 5;
        p2total = 30;
        discount = (p1total + p2total) * (5 / 100);
        clients.p2 = p2;
        clients.ptotal = p1total + p2total - discount;
        insurance.write(reinterpret_cast<char*>(&clients), sizeof(clients));
    }
    if (num2 == 6)
    {
        p2 = 6;
        p2total = 12;
        discount = (p1total + p2total) * (5 / 100);
        clients.p2 = p2;
        clients.ptotal = p1total + p2total - discount;
        insurance.write(reinterpret_cast<char*>(&clients), sizeof(clients));;
    }

    
    insurance.close();

    if (num == 1)
    {
        placeCursor(screen, 24, 5);
        cout << " You have successfully added 1 Policy to your account";
        placeCursor(screen, 25, 5);
        cout << "Policy # 1 : " << pc[0];
        placeCursor(screen, 26, 5);
        cout << "Your Total Monthly Repayment will be $ " << p1total;
    }
    if (num == 2)
    {
        placeCursor(screen, 24, 5);
        cout << " You have successfully added 1 Policy to your account";
        placeCursor(screen, 25, 5);
        cout << "Policy # 1 : " << pc[1];
        placeCursor(screen, 26, 5);
        cout << "Your Total Monthly Repayment will be $ " << p1total;
    }
    if (num == 3)
    {
        placeCursor(screen, 24, 5);
        cout << " You have successfully added 1 Policy to your account";
        placeCursor(screen, 25, 5);
        cout << "Policy # 1 : " << pc[2];
        placeCursor(screen, 26, 5);
        cout << "Your Total Monthly Repayment will be $ " << p1total;
    }
    if (num == 4)
    {
        placeCursor(screen, 24, 5);
        cout << " You have successfully added 1 Policy to your account";
        placeCursor(screen, 25, 5);
        cout << "Policy # 1 : " << pc[3];
        placeCursor(screen, 26, 5);
        cout << "Your Total Monthly Repayment will be $ " << p1total;
    }
    if (num == 5)
    {
        placeCursor(screen, 24, 5);
        cout << " You have successfully added 1 Policy to your account";
        placeCursor(screen, 25, 5);
        cout << "Policy # 1 : " << pc[4];
        placeCursor(screen, 26, 5);
        cout << "Your Total Monthly Repayment will be $ " << p1total;
    }
    if (num == 6)
    {
        placeCursor(screen, 24, 5);
        cout << " You have successfully added 1 Policy to your account";
        placeCursor(screen, 25, 5);
        cout << "Policy # 1 : " << pc[5];
        placeCursor(screen, 26, 5);
        cout << "Your Total Monthly Repayment will be $ " << p1total;
    }

    if (num2 == 1)
    {
        placeCursor(screen, 27, 5);
        cout << "Policy # 2 : " << pc[0];
        placeCursor(screen, 28, 5);
        cout << "Policy total " << p2total;
        placeCursor(screen, 29, 5);
        cout << "Multi-policy Discount " << discount;
        placeCursor(screen, 31, 5);
        cout << "Total Monthly repayment" << clients.ptotal;
    }
    if (num2 == 2)
    {
        placeCursor(screen, 27, 5);
        cout << "Policy # 2 : " << pc[1];
        placeCursor(screen, 28, 5);
        cout << "Policy total " << p2total;
        placeCursor(screen, 29, 5);
        cout << "Multi-policy Discount " << discount;
        placeCursor(screen, 31, 5);
        cout << "Total Monthly repayment" << clients.ptotal;
    }
    if (num2 == 3)
    {
        placeCursor(screen, 27, 5);
        cout << "Policy # 2 : " << pc[2];
        placeCursor(screen, 28, 5);
        cout << "Policy total " << p2total;
        placeCursor(screen, 29, 5);
        cout << "Multi-policy Discount " << discount;
        placeCursor(screen, 31, 5);
        cout << "Total Monthly repayment" << clients.ptotal;
    }
    if (num2 == 4)
    {
        placeCursor(screen, 27, 5);
        cout << "Policy # 2 : " << pc[3];
        placeCursor(screen, 28, 5);
        cout << "Policy total " << p2total;
        placeCursor(screen, 29, 5);
        cout << "Multi-policy Discount " << discount;
        placeCursor(screen, 31, 5);
        cout << "Total Monthly repayment" << clients.ptotal;
    }
    if (num2 == 5)
    {
        placeCursor(screen, 27, 5);
        cout << "Policy # 2 : " << pc[4];
        placeCursor(screen, 28, 5);
        cout << "Policy total " << p2total;
        placeCursor(screen, 29, 5);
        cout << "Multi-policy Discount " << discount;
        placeCursor(screen, 31, 5);
        cout << "Total Monthly repayment" << clients.ptotal;
    }
    if (num2 == 6)
    {
        placeCursor(screen, 27, 5);
        cout << "Policy # 2 : " << pc[5];
        placeCursor(screen, 28, 5);
        cout << "Policy total " << p2total;
        placeCursor(screen, 29, 5);
        cout << "Multi-policy Discount " << discount;
        placeCursor(screen, 31, 5);
        cout << "Total Monthly repayment" << clients.ptotal;
    }
    
    placeCursor(screen, 33, 50);
    cout << "\x1b[3;43;30mWELCOME TO BEST INSURANCE COMPANY\033[0m";
    system("pause");
}

// MENU #3 // 
// CLIENT LOGIN TO VIEW POLICY AND MENU TO UPDATE DATA
// FIRST DISPLAY
void clientdisplay()
{
    fstream insurance;
    char usen[51], passw[51];
    int count = 0;
    bool flag = false;

    system("cls");
    heading();
    placeCursor(screen, 10, 5);
    cout << "\x1b[3;43;30mCLIENT PORTAL\033[0m";

    insurance.open("clientform.dat", ios::in | ios::binary);
    placeCursor(screen, 12, 5);
    cout << "Please enter Username & Password to view details : ";
    cin.ignore();
    placeCursor(screen, 13, 5);
    cout << "Username : ";
    cin.getline(usen, 51);
    placeCursor(screen, 13, 70);
    cout << "Password : ";
    cin.getline(passw, 51);


    insurance.read(reinterpret_cast<char*>(&clients), sizeof(clients));
    while (!insurance.eof())
    {
        if ((strcmp(usen, clients.username) == 0) || (strcmp(passw, clients.password) == 0))
        {
            placeCursor(screen, 14, 5);
            cout << "\x1b[3;43;30mPOLICY DETAILS\033[0m";

            placeCursor(screen, 16, 5);
            cout << "First Name : " << clients.name;
            placeCursor(screen, 16, 70);
            cout << "Last name : " << clients.surname;
            placeCursor(screen, 17, 5);
            cout << "Street Name and Number : " << clients.address1;
            placeCursor(screen, 17, 70);
            cout << "Town : " << clients.address2;

            placeCursor(screen, 18, 5);
            cout << "Date of Birth : " << clients.dob;
            placeCursor(screen, 18, 70);
            cout << "Email address : " << clients.email;

            placeCursor(screen, 19, 5);
            cout << "\x1b[3; 43; 30mExpire Date\033[0m" << clients.edate;
            placeCursor(screen, 20, 5);
            cout << clients.pd1;
            placeCursor(screen, 21, 5);
            cout << clients.pd2;
            placeCursor(screen, 22, 5);
            cout << "Total Monthly Installment " << clients.ptotal;

            flag = true;
        }
        insurance.read(reinterpret_cast<char*>(&clients), sizeof(clients));
    }
    if (flag == true)
    {
        clientedit();
    }
    else
    {
        cout << "You have entered the wrong username & password combination.";

    }
    insurance.close();
}
void clientedit()
{
    placeCursor(screen, 23, 5);
    cout << "\x1b[3;43;30mYou can now\033[0m";

    placeCursor(screen, 24, 5);
    cout << "1. Update your Details" << endl;
    placeCursor(screen, 25, 5);
    cout << "2. Renew your Policy: ";
    placeCursor(screen, 26, 5);
    cout << "3. Exit";

    placeCursor(screen, 27, 5);
    cout << "What would you like to do: ";
    placeCursor(screen, 27, 50);
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        system("cls");
        clientupdate();


    }
    case 2:
    {
        clientrenew();
        break;

    }
    case 3:
    {
        system("cls");
        main();
    }
    }

}
void clientupdate()
{
    fstream insurance;
    client clientsedit;
    int rego;

    insurance.open("clientform.dat", ios::in | ios::out | ios::binary);
    placeCursor(screen, 27, 5);
    cout << "MAINTAIN DATA";
    placeCursor(screen, 28, 5);
    cout << "1. Surname ";
    placeCursor(screen, 29, 5);
    cout << "2. Car Registration number ";
    placeCursor(screen, 30, 5);
    cout << "3. Address ";
    placeCursor(screen, 31, 5);
    cout << "4. Email address";
    placeCursor(screen, 32, 5);
    cout << "5. Exit to Client Portal";
    placeCursor(screen, 33, 5);
    cout << "6. Exit to Home Page";
    placeCursor(screen, 34, 5);
    cout << "Please make a choice ";
    placeCursor(screen, 34, 50);
    cin >> choice;

    insurance.seekg(choice & sizeof(clientsedit), ios::beg);
    insurance.read(reinterpret_cast<char*>(&clientsedit), sizeof(clientsedit));

    switch (choice)
    {
    case 1:
    {
        cin.ignore();
        cout << "Enter new Surname : ";
        cin.getline(clientsedit.surname, 51);
        insurance.seekp(choice & sizeof(clientsedit), ios::beg);
        insurance.write(reinterpret_cast<char*>(&clientsedit), sizeof(clientsedit));
        break;

    }
    case 2:
    {
        cin.ignore();
        cout << "Here are your vehicle registration on our records";
        cout << clients.rego1 << " " << clients.rego2;
        cout << "Enter the correct Car registrion : ";
        cin.getline(clientsedit.rego1, 51);
        cin.getline(clientsedit.rego2, 51);
        insurance.seekp(choice & sizeof(clientsedit), ios::beg);
        insurance.write(reinterpret_cast<char*>(&clientsedit), sizeof(clientsedit));
        break;
    }
    case 3:
    {
        cin.ignore();
        cout << "Enter new street number and name : ";
        cin.getline(clientsedit.address1, 51);
        cout << endl;
        cout << "Enter new city : ";
        cin.getline(clientsedit.address2, 51);
        insurance.seekp(choice & sizeof(clientsedit), ios::beg);
        insurance.write(reinterpret_cast<char*>(&clientsedit), sizeof(clientsedit));
        break;
    }
    case 4:
    {
        cin.ignore();
        cout << "Enter new Email Address ";
        cin.getline(clientsedit.email, 51);
        insurance.seekp(choice & sizeof(clientsedit), ios::beg);
        insurance.write(reinterpret_cast<char*>(&clientsedit), sizeof(clientsedit));
        break;

    }
    case 5:
    {
        clientdisplay();
        break;
    }
    case 6:
    {
        main();
        break;
    }
    }


}
void clientrenew()
{

    system("cls");
    heading();
    placeCursor(screen, 10, 25);
    cout << "\x1b[3;43;30m YOUR POLICY HAS BEEN RENEWED FOR ANOTHER YEAR\033[0m";
    clients.renew = 1;
    placeCursor(screen, 12, 45);
    system("PAUSE");
}

//-------------------------------------------------------------------------------

// ALEX FUNCTIONS //
// MENU #4 //

void claims()
{
    heading();
    placeCursor(screen, 9, 45);
    cout << "\x1b[3;43;30mCLAIMS\033[0m";
    placeCursor(screen, 11, 10);
    cout << "To make a claim please fill out the following claims information";

    // Variables needed to write the file
    claim record2;

    // Create file object and open file
    fstream claims1;
    claims1.open("claims.dat", ios::out | ios::app | ios::binary);

    if (!claims1)
    {
        placeCursor(screen, 12, 10);
        cout << "Error opening file.";
    }

    // Now write the records
    for (int count = 0; count < 1; count++)
    {
        placeCursor(screen, 13, 10);
        cout << "Incident Details";
        placeCursor(screen, 14, 10);
        cout << "*****************************";
        cin.ignore();

        placeCursor(screen, 15, 10);
        cout << "Date of incident: ";
        cin.getline(record2.date, 12);

        placeCursor(screen, 16, 10);
        cout << "Date of incident (Week Starting): ";
        cin.getline(record2.dateStart, 12);

        placeCursor(screen, 18, 10);
        cout << "Date of incident (Week Ending): ";
        cin.getline(record2.dateEnd, 12);

        placeCursor(screen, 20, 10);
        cout << "Time of incident: ";
        cin.getline(record2.time, 15);

        placeCursor(screen, 22, 10);
        cout << "Police report completed (y/n): ";
        cin.getline(record2.policeRE, 2);


        placeCursor(screen, 13, 71);
        cout << "Policy holder vehicle details";
        placeCursor(screen, 114, 71);
        cout << "*****************************";

        placeCursor(screen, 15, 71);
        cout << "Type of vehicle (Car/Bike): ";
        cin.getline(record2.vehType, 5);

        placeCursor(screen, 16, 71);
        cout << "Make of Vehicle (i.e. Holden/kawasaki): ";
        cin.getline(record2.vehMake, 51);

        placeCursor(screen, 18, 71);
        cout << "Manufacture year (yyyy): ";
        cin.getline(record2.vehYear, 5);

        placeCursor(screen, 20, 71);
        cout << "Registration number: ";
        cin.getline(record2.rego, 10);


        placeCursor(screen, 26, 10);
        cout << "Policy holder Details";
        placeCursor(screen, 27, 10);
        cout << "*****************************";

        placeCursor(screen, 28, 10);
        cout << "Policy Number: ";
        cin.getline(record2.PolNum, 51);

        placeCursor(screen, 30, 10);
        cout << "First Name: ";
        cin.getline(record2.firstName, 51);

        placeCursor(screen, 32, 10);
        cout << "Last Name: ";
        cin.getline(record2.lastName, 51);

        placeCursor(screen, 34, 10);
        cout << "Address Line 1: ";
        cin.getline(record2.addressLine1, 51);

        placeCursor(screen, 36, 10);
        cout << "Address Line 2: ";
        cin.getline(record2.addressLine2, 51);

        placeCursor(screen, 38, 10);
        cout << "Phone: ";
        cin.getline(record2.phone, 14);

        placeCursor(screen, 40, 10);
        cout << "Email: ";
        cin.getline(record2.email, 51);

        placeCursor(screen, 42, 10);
        cout << "Decription of incident";

        placeCursor(screen, 43, 10);
        cout << "Please decribe the incident, all relevant information";
        cin.getline(record2.description, 300);



        placeCursor(screen, 25, 71);
        cout << "Other Party Details";
        placeCursor(screen, 26, 71);
        cout << "*****************************";

        placeCursor(screen, 27, 71);
        cout << "First Name: ";
        cin.getline(record2.otherfirstName, 51);

        placeCursor(screen, 28, 71);
        cout << "Last Name: ";
        cin.getline(record2.otherlastName, 51);

        placeCursor(screen, 30, 71);
        cout << "Phone: ";
        cin.getline(record2.otherphone, 14);

        placeCursor(screen, 32, 71);
        cout << "Email: ";
        cin.getline(record2.otheremail, 51);

        placeCursor(screen, 34, 71);
        cout << "Insurance Company: ";
        cin.getline(record2.insCompany, 51);

        placeCursor(screen, 36, 71);
        cout << "Registration number: ";
        cin.getline(record2.otherRego, 10);


        placeCursor(screen, 44, 10);
        cout << "Thank you for your claim submission, we will evaluate your claim shortly";
        placeCursor(screen, 46, 10);
        cout << "Your claim Number is: ref" << count + 5236;
        claims1.write(reinterpret_cast<char*>(&record2), sizeof(record2));
    }
    // Close the file
    claims1.close();

    placeCursor(screen, 48, 10);
    cout << "Press enter to return to menu";
    cin.get();
    system("cls");

}
 
// ADMIN FUNCTIONS //------------------------------------------------------------
//
//void adminmainMenu()
//{
//    //variables
//    char select;
//
//    placeCursor(screen, 4, 55);
//    cout << "\x1b[3;43;30mADMINISTRATION\033[0m";
//
//
//    //Switch case for user option selection
//    while (1)
//    {
//        placeCursor(screen, 7, 35);
//        cout << "1. Update information & Discounts";
//        placeCursor(screen, 8, 35);
//        cout << "2. Display Customer Reports";
//        placeCursor(screen, 9, 35);
//        cout << "3. Display Claims (weekly report)";
//        placeCursor(screen, 10, 35);
//        cout << "4. Display Renewals (weekly report";
//        placeCursor(screen, 11, 35);
//        cout << "5. Display New Registrations (weekly report)";
//        placeCursor(screen, 12, 35);
//        cout << "6. Return To Homepage"; // NH added to allow function to exit to main /'homepage'
//
//        placeCursor(screen, 13, 35);
//        cout << "Please enter your selection: ";
//        cin >> select;
//        cin.ignore();
//        cout << endl;
//
//        switch (select)
//        {
//        case '1':
//            //updateDis();
//            break;
//        case '2':
//
//            //customerReport();
//            break;
//        case '3':
//
//            //weeklyClaims();
//            break;
//        case '4':
//            //weeklyRenew();
//            break;
//        case '5':
//            //weeklyRegi();
//            break;
//        case '6':
//            system("cls");
//            main();
//            break;
//        default:
//            exit(0);
//        }
//    }
//}
////Admin Registration 
//void registerAdmin()
//{
//    admin record;
//    fstream output;
//    output.open("admin.dat", ios::out | ios::app | ios::binary);
//
//    placeCursor(screen, 12, 35);
//    cout << "Enter serial: ";
//    cin >> record.s;
//    cin.ignore();
//
//    placeCursor(screen, 13, 35);
//    cout << "Enter username: ";
//    cin.getline(record.uName, 51);
//
//    placeCursor(screen, 14, 35);
//    cout << "Enter password: ";
//    cin.getline(record.pass, 51);
//
//    placeCursor(screen, 15, 35);
//    cout << "Enter name: ";
//    cin.getline(record.name, 51);
//
//    placeCursor(screen, 16, 35);
//    cout << "Enter company email: ";
//    cin.getline(record.email, 51);
//
//    placeCursor(screen, 17, 35);
//    cout << "Enter company phone number: ";
//    cin.getline(record.phone, 51);
//
//    output.write(reinterpret_cast<char*>(&record), sizeof(record));
//    output.close();
//
//    placeCursor(screen, 20, 35);
//    cout << "Registration complete, Please now login.";
//
//}
//
////working 29/06/2021
//void adminLogin()
//{
//    bool flag = false;
//    admin record;
//    char logname[51];
//    char logpass[51];
//
//    cout << endl;
//
//    placeCursor(screen, 4, 55);
//    cout << "ADMINISTRATION" << endl;
//
//    placeCursor(screen, 5, 60);
//    cout << "Login" << endl;
//
//    //login
//    fstream input;
//    input.open("admin.dat", ios::in | ios::binary);
//
//    if (!input)
//    {
//        cout << "Error creating file!";
//    }
//    else
//    {
//        placeCursor(screen, 7, 35);
//        cout << "Enter username:";
//        cin.getline(logname, 51);
//
//        placeCursor(screen, 7, 60);
//        cout << "Enter password:";
//        cin.getline(logpass, 51);
//
//        // check if reading was successfull and input  uName trying to get to the file and read the already entered uName and match with the current entered name by user, same with pass
//        // Now read and display the records
//
//        input.read(reinterpret_cast<char*>(&record), sizeof(record));
//        while (!input.eof())
//        {
//            if ((strcmp(logname, record.uName) == 0) && (strcmp(logpass, record.pass) == 0))
//            {
//                flag = true;
//                break;
//            }
//            input.read(reinterpret_cast<char*>(&record), sizeof(record));
//        }
//
//
//
//        if (flag)
//        {
//            placeCursor(screen, 20, 55);
//            cout << "Login successful" << endl;
//            placeCursor(screen, 21, 55);
//            cout << "Welcome" << endl;
//
//            system("cls");
//            adminmainMenu();
//
//        }
//        else
//        {
//
//            placeCursor(screen, 20, 55);
//            cout << "Login failed!" << endl;
//            placeCursor(screen, 21, 55);
//            cout << "Please Try again" << endl;
//            //do nothing
//            system("cls");
//        }
//    }
//    input.close();
//}
////working 29/06/2021
//void adminlogMenu()
//{
//
//    //variables
//    char select;
//
//
//
//    cout << "\n";
//    placeCursor(screen, 4, 55);
//    cout << "ADMINISTRATION";
//
//    cout << "\n";
//
//
//
//    //Switch case for user option selection
//    while (1)
//    {
//        //system("cls");
//        placeCursor(screen, 7, 35);
//        cout << "1. Register New Admin";
//        placeCursor(screen, 8, 35);
//        cout << "2. Login";
//        placeCursor(screen, 9, 35);
//        cout << "3. Return to main menu";
//        placeCursor(screen, 10, 35);
//        cout << "Please enter your selection: ";
//        cin >> select;
//        cin.ignore();
//        cout << endl;
//
//        switch (select)
//        {
//        case '1':
//
//            registerAdmin();
//            break;
//        case '2':
//            system("cls");
//            adminLogin();
//            break;
//        case'3':
//            system("cls");
//            main();
//        }
//    }
//}
//
////working 02/07/2021
//void updateDis()
//{
//    client record7;
//
//    char lname;
//    // Create file object and open file
//    fstream clientform;
//    clientform.open("clientform.dat", ios::in | ios::out | ios::binary);
//
//    if (!clientform)
//    {
//        cout << "Error opening file.";
//
//    }
//    else
//    {
//        // Move to the desired record and read it into record3
//        cout << "Enter Surname to search: ";
//        cin >> lname;
//        cin.ignore();
//
//        clientform.seekg(lname * sizeof(record7), ios::beg);
//        clientform.read(reinterpret_cast<char*>(&record7), sizeof(record7));
//
//        //Display the record first
//        cout << "Name: ";
//        cout << record7.name << endl;
//
//        cout << "Surname: ";
//        cout << record7.surname << endl;
//
//        cout << "Address line 1: ";
//        cout << record7.address1 << endl;
//
//        cout << "Address line 2: ";
//        cout << record7.address2 << endl;
//
//        cout << "Number: ";
//        cout << record7.number << endl;
//
//        cout << "Registration of vehicle: ";
//        cout << record7.rego1 << endl;
//
//        cout << "Registration of other vehicles ";
//        cout << record7.rego2 << endl;
//
//        cout << "Monthly Payment total: ";
//        cout << record7.ptotal << endl;
//
//        cout << "Policy 1: ";
//        cout << record7.p1 << endl;
//
//        cout << "Policy 2: ";
//        cout << record7.p2 << endl;
//
//
//        //Get new data from user and edit in-memory record
//        cout << "Enter the new data: \n";
//        cout << "Surname";
//        cin.getline(record7.surname, 15);
//        cout << "\n";
//
//        cout << "Address line 1: ";
//        cin.getline(record7.address1, 50);
//        cout << "\n";
//
//        cout << "Address line 2: ";
//        cin.getline(record7.address2, 50);
//        cout << "\n";
//
//        cout << "Number: ";
//        cin.getline(record7.number, 12);
//        cout << "\n";
//
//        cout << "Registration of vehicle: ";
//        cin.getline(record7.rego1, 51);
//        cout << "\n";
//
//        cout << "Registration of other vehicles ";
//        cin.getline(record7.rego2, 51);
//        cout << "\n";
//
//        cout << "Monthly Payment total: ";
//        cout << record7.ptotal;
//        cin.ignore();
//        cout << "\n";
//
//        // Move to the right place in file and write the record
//        clientform.seekp(lname * sizeof(record7), ios::beg);
//        clientform.write(reinterpret_cast<char*>(&record7), sizeof(record7));
//    }
//    // Close the file
//    clientform.close();
//
//    cout << "Press enter to return to menu";
//    cin.get();
//    system("cls");
//    adminmainMenu();
//
//}
////working 29/06/2021
//void customerReport()
//{
//    client record5; //change to Nolene Struct
//    fstream clientform;
//
//    char fName[12];
//    char lName[12];
//    bool flag = false;
//
//    //Open the file for reading
//    clientform.open("clientform.dat", ios::in | ios::app | ios::binary);
//    if (!clientform)
//    {
//        placeCursor(screen, 16, 10);
//        cout << "Error in opening the file. ";
//    }
//
//    placeCursor(screen, 16, 55);
//    cout << "CUSTOMER REPORT";
//
//    placeCursor(screen, 18, 10);
//    cout << "Please enter the customers first and last name to serach records ";
//
//    placeCursor(screen, 20, 10);
//    cout << "First name: ";
//    cin.getline(fName, 12);
//
//    placeCursor(screen, 20, 71);
//    cout << "Last name: ";
//    cin.getline(lName, 12);
//
//    // Now read and display the records
//    clientform.read(reinterpret_cast<char*>(&record5), sizeof(record5));
//
//    while (!clientform.eof())
//    {
//
//        if ((strcmp(fName, record5.name) == 0) && (strcmp(lName, record5.surname) == 0))
//        {
//            placeCursor(screen, 24, 10);
//            cout << "Customer Full name : ";
//            cout << record5.name << " " << record5.surname;
//
//            placeCursor(screen, 26, 10);
//            cout << "Gender: ";
//            cout << record5.gender;
//
//            placeCursor(screen, 26, 71);
//            cout << "Date of Birth: ";
//            cout << record5.dob;
//
//            placeCursor(screen, 28, 10);
//            cout << "Address Line 1: " << record5.address1;
//
//            placeCursor(screen, 28, 71);
//            cout << "Address Line 2: " << record5.address2;
//
//            placeCursor(screen, 30, 10);
//            cout << "Phone Number: " << record5.number;
//
//            placeCursor(screen, 30, 71);
//            cout << "Email Address: " << record5.email;
//
//            placeCursor(screen, 32, 10);
//            cout << "Date policy taken: " << record5.sdate;
//
//            placeCursor(screen, 32, 71);
//            cout << "Current vehicle registration covered by policy" << record5.rego1;
//
//            placeCursor(screen, 34, 10);
//            cout << "Current Payment structure: " << record5.ptotal;
//
//
//
//            flag = true;
//        }
//
//
//        clientform.read(reinterpret_cast<char*>(&record5), sizeof(record5));
//    }
//
//    if (flag == false)
//    {
//        placeCursor(screen, 24, 10);
//        cout << "No such record, please try again.";
//    }
//    clientform.close();
//    placeCursor(screen, 36, 10);
//    cout << "Press enter to return to menu";
//    cin.get();
//    system("cls");
//    adminmainMenu();
//}
////working 29/06/2021
//void weeklyClaims()
//{
//
//    claim record2;
//    fstream claims1;
//
//    char startDate[12];
//    char endDate[12];
//    bool flag = false;
//
//    //Open the file for reading
//    claims1.open("claims.dat", ios::in | ios::app | ios::binary);
//    if (!claims1)
//    {
//        placeCursor(screen, 19, 10);
//        cout << "Error in opening the file. ";
//
//    }
//
//    placeCursor(screen, 15, 55);
//    cout << "CLAIM REPORT";
//
//    placeCursor(screen, 17, 10);
//    cout << "Please enter the week starting date (dd/mm/yyyy): ";
//    cin.getline(startDate, 12);
//
//    placeCursor(screen, 17, 71);
//    cout << "& week ending date (dd/mm/yyyy): ";
//    cin.getline(endDate, 12);
//
//    int  i = 0;
//    // Now read and display the records
//    claims1.read(reinterpret_cast<char*>(&record2), sizeof(record2));
//
//
//    while (!claims1.eof())
//    {
//
//        if ((strcmp(startDate, record2.dateStart) == 0) && (strcmp(endDate, record2.dateEnd) == 0))
//        {
//            placeCursor(screen, 19, 10);
//            cout << "Claim submitted by: " << record2.firstName << " " << record2.lastName;
//
//            placeCursor(screen, 22, 10);
//            cout << "----Incident Details----";
//
//            placeCursor(screen, 24, 10);
//            cout << "Actual Date of incident: ";
//            cout << record2.date;
//
//
//            placeCursor(screen, 26, 10);
//            cout << "Claim submission date (Week Starting): ";
//            cout << record2.dateStart;
//
//
//            placeCursor(screen, 28, 10);
//            cout << "Claim submission date (Week Ending): ";
//            cout << record2.dateEnd;
//
//
//            placeCursor(screen, 30, 10);
//            cout << "Time of incident: ";
//            cout << record2.time;
//
//            placeCursor(screen, 32, 10);
//            cout << "Police report completed (y/n): ";
//            cout << record2.policeRE;
//
//
//
//
//
//            placeCursor(screen, 22, 71);
//            cout << "----Policy holder vehicle details----";
//
//            placeCursor(screen, 24, 71);
//            cout << "Type of vehicle (Car/Bike): ";
//            cout << record2.vehType;
//
//            placeCursor(screen, 26, 71);
//            cout << "Make of Vehicle (i.e. Holden/kawasaki): ";
//            cout << record2.vehMake;
//
//            placeCursor(screen, 28, 71);
//            cout << "Manufacture year (yyyy): ";
//            cout << record2.vehYear;
//
//            placeCursor(screen, 30, 71);
//            cout << "Registration of Vehicle";
//            cout << record2.rego;
//
//
//
//            placeCursor(screen, 36, 10);
//            cout << "----Policy holder Details----";
//
//            placeCursor(screen, 38, 10);
//            cout << "Policy Number: ";
//            cout << record2.PolNum;
//
//            placeCursor(screen, 40, 10);
//            cout << "First Name: ";
//            cout << record2.firstName;
//
//            placeCursor(screen, 42, 10);
//            cout << "Last Name: ";
//            cout << record2.lastName;
//
//            placeCursor(screen, 44, 10);
//            cout << "Address Line 1: ";
//            cout << record2.addressLine1;
//
//            placeCursor(screen, 46, 10);
//            cout << "Address Line 2: ";
//            cout << record2.addressLine2;
//
//            placeCursor(screen, 48, 10);
//            cout << "Phone: ";
//            cout << record2.phone;
//
//            placeCursor(screen, 50, 10);
//            cout << "Email: ";
//            cout << record2.email;
//
//            placeCursor(screen, 36, 71);
//            cout << "----Other Party Details----";
//
//            placeCursor(screen, 38, 71);
//            cout << "First Name: ";
//            cout << record2.otherfirstName;
//
//            placeCursor(screen, 40, 71);
//            cout << "Last Name: ";
//            cout << record2.otherlastName;
//
//            placeCursor(screen, 42, 71);
//            cout << "Phone: ";
//            cout << record2.otherphone;
//
//            placeCursor(screen, 44, 71);
//            cout << "Email: ";
//            cout << record2.otheremail;
//
//            placeCursor(screen, 46, 71);
//            cout << "Insurance Company: ";
//            cout << record2.insCompany;
//
//            placeCursor(screen, 48, 71);
//            cout << "Registration number: ";
//            cout << record2.otherRego;
//
//
//            placeCursor(screen, 54, 10);
//            cout << "----Decription of incident----";
//
//            placeCursor(screen, 56, 10);
//            cout << record2.description;
//
//
//            i++;
//            flag = true;
//        }
//
//        claims1.read(reinterpret_cast<char*>(&record2), sizeof(record2));
//    }
//
//    if (flag == false)
//    {
//        placeCursor(screen, 19, 10);
//        cout << "No records, please try again.";
//
//    }
//
//
//    placeCursor(screen, 65, 10);
//    cout << "The total claims made for the given start and end dates: " << i;
//    claims1.close();
//
//    placeCursor(screen, 67, 10);
//    cout << "Press enter to return to menu";
//    cin.get();
//    system("cls");
//    adminmainMenu();
//
//}
//
////working 02/06/2021
//void weeklyRenew()
//{
//    client record4;
//    fstream clientform;
//    char prevHolder[3];
//    char startDate[12];
//    char endDate[12];
//    bool flag = false;
//
//    //Open the file for reading
//    clientform.open("clientform.dat", ios::in | ios::binary);
//    if (!clientform)
//    {
//        cout << "Error in opening the file. ";
//
//    }
//
//
//    placeCursor(screen, 15, 55);
//    cout << "RENEWAL REPORT";
//
//    placeCursor(screen, 17, 10);
//    cout << "Please enter the week starting date (dd/mm/yyyy): ";
//    cin.getline(startDate, 12);
//
//    placeCursor(screen, 19, 10);
//    cout << "Please enter the week ending date (dd/mm/yyyy): ";
//    cin.getline(endDate, 12);
//
//    placeCursor(screen, 21, 10);
//    cout << "Previous policy holder (Y/N): ";
//    cin.getline(prevHolder, 3);
//
//
//    int i = 0;
//
//    // Now read and display the records
//    clientform.read(reinterpret_cast<char*>(&record4), sizeof(record4));
//
//    while (!clientform.eof())
//    {
//
//        if ((strcmp(startDate, record4.sdate) == 0) && (strcmp(endDate, record4.edate) == 0) && (strcmp(prevHolder, record4.renew) == 0))
//        {
//            placeCursor(screen, 23, 10);
//            cout << "Renewal details for the week of " << record4.sdate << " to " << record4.edate;
//
//            placeCursor(screen, 25, 10);
//            cout << "Policy Number POL123456";
//
//            placeCursor(screen, 27, 10);
//            cout << "Record holder Name" << record4.name << " " << record4.surname;
//            
//            i++;
//            flag = true;
//        }
//
//        if (flag == false)
//        {
//            placeCursor(screen, 23, 10);
//            cout << "No such record, please try again.";
//        }
//
//
//        placeCursor(screen, 29, 10);
//        cout << "The total customer renewals made for the given start and end dates: " << i;
//        clientform.read(reinterpret_cast<char*>(&record4), sizeof(record4));
//    }
//
//
//
//    clientform.close();
//
//    placeCursor(screen, 30, 10);
//    cout << "Press enter to return to menu";
//    cin.get();
//    system("cls");
//    adminmainMenu();
//
//
//}
////working 02/06/2021
//void weeklyRegi()
//{
//
//    client record3; //change to Nolene Struct
//    fstream clientform;
//    char prevHolder[3];
//    char startDate[12];
//    char endDate[12];
//    bool flag = false;
//
//    //Open the file for reading
//    clientform.open("clientform.dat", ios::in | ios::binary);
//    if (!clientform)
//    {
//        placeCursor(screen, 16, 10);
//        cout << "Error in opening the file. ";
//
//    }
//
//    placeCursor(screen, 16, 55);
//    cout << "REGISTRATION REPORT";
//
//    placeCursor(screen, 18, 10);
//    cout << "Please enter the week starting date (dd/mm/yyyy): ";
//    cin.getline(startDate, 12);
//
//    placeCursor(screen, 20, 10);
//    cout << "Please enter the week ending date (dd/mm/yyyy): ";
//    cin.getline(endDate, 12);
//
//    placeCursor(screen, 24, 10);
//    cout << "Previous policy holder (Y/N): ";
//    cin.getline(prevHolder, 3);
//
//
//    int i = 0;
//
//    // Now read and display the records
//    clientform.read(reinterpret_cast<char*>(&record3), sizeof(record3));
//
//
//    while (!clientform.eof())
//    {
//
//
//        if ((strcmp(startDate, record3.sdate) == 0) && (strcmp(endDate, record3.edate) == 0) && (strcmp(prevHolder, record3.renew) == 0))
//        {
//            placeCursor(screen, 26, 10);
//            cout << "The total new registrations made for the week of " << startDate << " to " << endDate << " is: " << i;
//            i++;
//            flag = true;
//        }
//
//
//        clientform.read(reinterpret_cast<char*>(&record3), sizeof(record3));
//    }
//
//    if (flag == false)
//    {
//        placeCursor(screen, 26, 10);
//        cout << "No such record, please try again.";
//    }
//
//    placeCursor(screen, 28, 10);
//    cout << "The total new registrations made for the week of " << startDate << " to " << endDate << " is: " << i;
//
//    clientform.close();
//
//    placeCursor(screen, 30, 10);
//    cout << "Press enter to return to menu";
//    cin.get();
//    system("cls");
//    adminmainMenu();
//
//}