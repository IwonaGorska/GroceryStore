//
// Created by iwona on 21.07.2019.
//

#ifndef REKRUTACJATELDAT_PRODUCT_H
#define REKRUTACJATELDAT_PRODUCT_H

#include <iostream>

using namespace std;

class Product
{
    public:
        string code;
        string name;
        double price;
        char unitOfMeasure;// 'p' is for pieces and 'w' is for weight
        double qty;
};

#endif //REKRUTACJATELDAT_PRODUCT_H
