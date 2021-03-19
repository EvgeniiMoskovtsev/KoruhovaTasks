#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <thread>
#include "account.h"

int main()
{
    //std::time_t currentTime = std::time(nullptr);
    //std::cout << std::put_time(std::localtime(&currentTime), "%c %Z");
    Person my_person = { "Evgenii", "Moskovtsev" };
    Account my_account(my_person, 86000.0);
    my_account.printCurrentMoney();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    my_account.topUp(2090.0);
    my_account.printLastOperations();
    my_account.printCurrentMoney();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    my_account.takeOff(1900);
    my_account.printLastOperations();
    my_account.printCurrentMoney();
    my_account.takeOff(100000);
  
    Account my_account2(my_account);
    std::cout << "-------------------------------------" << std::endl;
    my_account2.printLastOperations();


    return 0;
}

