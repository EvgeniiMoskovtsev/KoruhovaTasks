// Krokunova_2_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vector.h"
int main()
{
    Vector v1{ 1,2,3 };
    Vector v2{ 1,2,3 };
    Vector v3 = v1 ^ v2;
    std::cout << v3;
}

