//
// Created by iwona on 21.07.2019.
//
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <vector>
#include "Fruit.h"
#include "Vegetable.h"

using namespace std;
#include "Bill.h"

void Bill :: add()
{
    string code;
    string name;
    double price = 0;
    double qty;
    string codeInFile;
    bool codeFound = false;
    char unitOfMeasure = 'p';
    cout<<"PODAJ KOD PRODUKTU, KTORY CHCESZ DODAC: ";
    cin>>code;
    this->file.open("products.txt", ios::in);
    if(this->file.good())
    {
        while(!this->file.eof())
        {
            file>>codeInFile>>unitOfMeasure>>name>>price;
            if(codeInFile == code)
            {
                codeFound = true;
                break;
            }
        }
        this->file.close();
    }

    if(codeFound)
    {
        if(unitOfMeasure == 'p')
        {
            int qtyInt;

            cout<<endl<<"PODAJ LICZBE SZTUK: ";
            cin>>qtyInt;
            qty = (double)qtyInt;
        }
        else
        {
            cout<<endl<<"PODAJ MASE W KILOGRAMACH: ";
            cin>>qty;
        }
        cout<<endl;

        if(code[0] == '0')
        {
            auto *nextFruit = new Fruit;
            nextFruit->name = name;
            nextFruit->price = price/100.0;
            nextFruit->code = code;
            nextFruit->qty = qty;
            nextFruit->unitOfMeasure = unitOfMeasure;
            this->fruits.push_back(nextFruit);
        }
        else
        {
            auto *nextVegetable = new Vegetable;
            nextVegetable->name = name;
            nextVegetable->price = price/100.0;
            nextVegetable->code = code;
            nextVegetable->qty = qty;
            nextVegetable->unitOfMeasure = unitOfMeasure;
            this->vegetables.push_back(nextVegetable);
        }

    }
    else
    {
        cout<<"PRODUKT O TAKIM KODZIE NIE ISTNIEJE"<<endl;
        this->add();
    }
    this->showMenu();
}

void Bill :: printBill()
{
    double cost = 0;
    if(!fruits.empty())
    {
        cout<<"OWOCE:"<<endl;
        for(int i = 0; i < fruits.size(); i++)
        {
            cout<<fruits[i]->name<<" "<<fruits[i]->qty;
            (fruits[i]->unitOfMeasure == 'p') ? cout<<" szt."<<endl : cout<<" kg"<<endl;
            cost+= fruits[i]->qty*fruits[i]->price;
        }
    }
    if(!vegetables.empty())
    {
        cout<<"WARZYWA:"<<endl;
        for(int i = 0; i < fruits.size(); i++)
        {
            cout<<vegetables[i]->name<<" "<<vegetables[i]->qty;
            (vegetables[i]->unitOfMeasure == 'p') ? cout<<" szt."<<endl : cout<<" kg"<<endl;
            cost+= vegetables[i]->qty*vegetables[i]->price;
        }
    }
    cout<<"CALKOWITY KOSZT = "<<cost<<" zl"<<endl;
}

void Bill :: readAndPrintWholeFile()
{
    string line;
    string code;
    string name;
    double price;
    char unitOfMeasure;

    this->file.open("products.txt", ios::in);
    if(this->file.good())
    {
        while(!this->file.eof())
        {
            file>>code>>unitOfMeasure>>name>>price;
            cout<<code<<" "<<name<<" "<<price/100;
            if(unitOfMeasure == 'p')
                cout<<" zl/szt."<<endl;
            else
                cout<<" zl/kg"<<endl;
        }
        this->file.close();
    }
    this->showMenu();
}


void Bill :: showMenu()
{
    char choice;
    cout<<"CO CHCESZ WYKONAC? (1 - DODANIE NOWEJ POZYCJI DO RACHUNKU, 2 - DRUKOWANIE RACHUNKU, 3 - PODGLAD LISTY PRODUKTOW)"<<endl;
    cin>>choice;
    switch(choice)
    {
        case('1'):
        {
            this->add();
            break;
        }
        case('2'):
        {
            this->printBill();
            break;
        }
        case('3'):
        {
            this->readAndPrintWholeFile();
            break;
        }
        default:
        {
            cout<<"NIEPRAWIDLOWA WARTOSC"<<endl;
            this->showMenu();
        }
    }
}