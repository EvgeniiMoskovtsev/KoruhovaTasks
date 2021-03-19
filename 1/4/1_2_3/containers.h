#ifndef CONTAINERS_H_
#define CONTAINERS_H_
#include <iostream>
class my_queue {
private:
    int m_end;
    double* m_queue;
    int m_size;

    void shift() {
        for (int i = 0; i < m_size - 1; ++i) {
            m_queue[i] = m_queue[i + 1];
        }
    }
public:
    my_queue(int size) {
        std::cout << "Конструктор" << std::endl;
        m_size = size;
        m_end = 0;
        m_queue = new double[m_size];
    }
    my_queue(const my_queue& m) {
        std::cout << "Конструктор копирования" << std::endl;
        m_size = m.m_size;
        m_end = m.m_end;
        m_queue = new double[m_size];
        for (int i = 0; i < m_size; ++i) {
            m_queue[i] = m.m_queue[i];
        }
    }
    ~my_queue() {
        std::cout << "Деструктор" << std::endl;
        delete[] m_queue;
    }

    my_queue& operator=(const my_queue& m) {
        delete[] m_queue;
        m_queue = new double[m.m_size];
        m_size = m.m_size;
        m_end = m.m_end;
        for (int i = 0; i < m_size; ++i) {
            m_queue[i] = m.m_queue[i];
        }
    }

    bool empty() {
        if (m_end <= 0) {
            return true;
        }
        else {
            return false;
        }
    }
    bool full() {
        if (m_end != m_size) {
            return false;
        }
        else {
            return true;
        }
    }
    double get() {
        if (!empty()) {
            double value = m_queue[0];
            --m_end;
            shift();
            return value;
        }
        else {
            return NULL;
        }
    }
    void push(double value) {
        m_queue[m_end] = value;
        ++m_end;
    }

};

#endif // !CONTAINERS_H_