#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>

using namespace std;

HANDLE color = GetStdHandle( STD_OUTPUT_HANDLE );

#include "Bill.h"

void showFinalMenu()
{
    char choice;
    cout<<"CO CHCESZ WYKONAC? (1 - NOWY RACHUNEK, 2 - WYJSCIE) "<<endl;
    cin>>choice;
    if(choice == '1')
    {
        Bill *nextBill = new Bill();
        nextBill->showMenu();
    }
    else
    {
        if(choice == '2')
        {
            cout<<"DZIEKUJE ZA SKORZYSTANIE Z PROGRAMU"<<endl;
            exit(0);
        }
        else
        {
            do
            {
                cout<< "WPROWADZONA WARTOSC JEST NIEPRAWIDLOWA"<<endl;
                cout<< "CO CHCESZ WYKONAC? (N - NOWY RACHUNEK, W - WYJSCIE)"<<endl;
                cin>>choice;
            }
            while(choice != '1' && choice != '2');
        }
    }
}

int main()
{
    SetConsoleTextAttribute( color, 10 );
    cout<<"WITAJ W KASIE DLA SKLEPU WARZYWNO-OWOCOWEGO"<<endl;
    SetConsoleTextAttribute( color, 14 );
    showFinalMenu();

    cin.get();
    system("pause");
    return 0;
}
