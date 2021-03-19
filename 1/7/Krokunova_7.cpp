// Krokunova_7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
class Date {
    int m_day, m_month, m_year;
public:
    static Date today;
    static int m_count;
    Date(int day=today.m_day, int month=today.m_month, int year=today.m_year)
        :m_day(day), m_month(month), m_year(year)
    {
        ++m_count;
        std::cout << "Constructor: m_count now equal " << m_count << std::endl;
    }
    ~Date()
    {
        --m_count;
        std::cout << "Destructor: m_count now equal " << m_count << std::endl;
    }
    Date(const Date& other)
        :m_day(other.m_day), m_month(other.m_month), m_year(other.m_year)
    {
        ++m_count;
        std::cout << "Copy constructor: m_count now equal " << m_count << std::endl;
    }
    Date& operator=(const Date& other)
    {
        assert(this != &other);
        m_day = other.m_day;
        m_month = other.m_month;
        m_year = other.m_year;
        std::cout << "Operator =" << std::endl;
        return *this;
    }

    friend std::ostream& operator <<(std::ostream& os, const Date& date) {
        os << date.m_day << "/" << date.m_month << "/" << date.m_year;
        return os;
    }
};

Date Date::today(1, 1, 1970); // тут вызывается конструктор
int Date::m_count = 0;

int main()
{   
    //Date* date1 = new Date();
    //delete date1;
    std::cout << Date::today << std::endl;
    Date d1(1, 1, 2009), d2(28, 2), d3, d4 = d1;
    auto something = d1.m_count + Date::m_count;
    std::cout << "something is equal " << something << std::endl;
    Date d6;
    d6 = d1; // тут вызовется оператор присваивания, т.к. d6 уже создан. в случае d4, конструктор копирвания, т.к. на момент инициализации.

}


