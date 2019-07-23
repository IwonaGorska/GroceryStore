//
// Created by iwona on 21.07.2019.
//

#ifndef REKRUTACJATELDAT_BILL_H
#define REKRUTACJATELDAT_BILL_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Fruit.h"
#include "Vegetable.h"

using namespace std;

class Bill
{
    public:
        void showMenu();
        vector <Fruit*> fruits;
        vector <Vegetable*> vegetables;
    private:
        fstream file;
        void add();
        void printBill();
        void readAndPrintWholeFile();
};

#endif //REKRUTACJATELDAT_BILL_H
