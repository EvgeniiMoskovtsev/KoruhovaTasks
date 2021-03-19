#include <iostream>

class electricity_meter {
private:
    int m_start;
    int m_end;
    int m_value;
public:
    electricity_meter(int start, int end)
    {
        m_start = start;
        m_end = end;
        m_value = start;
    }
    electricity_meter(const electricity_meter& m) {
        m_start = m.m_start;
        m_end = m.m_end;
        m_value = m.m_value;
    }
    ~electricity_meter() {};
    //перегрузить на += TODO
    electricity_meter& operator+=(const int value) {
        m_value += value;
        return *this;
    }
    electricity_meter operator+(const int value) {
        electricity_meter electricity_meter_copy(*this);
        electricity_meter_copy += value;
        return electricity_meter_copy;
    }

    void increase_value(int N) {
        m_value += N;
        if (m_value > m_end){
            m_value = 0;
        }
    }

    void print_current_value() const {
        std::cout << "Current value: " << m_value << std::endl;
    }
};

class my_stack {
public:
    //попробовать переписать на 2 указателя TODO
    int m_size;
    int* m_start;
    int* m_end;

    my_stack(int size) {
        m_size = size;
        m_start = new int[size];
        m_end = m_start;
    }
    my_stack(const my_stack& m) {
        m_size = m.m_size;
        m_start = new int[m_size];
        m_end = m_start;
        for (int i = 0; i < m_size; ++i) {
            m_start[i] = m.m_start[i];
        }
    }
    ~my_stack() {
        delete[] m_start;
    }

    bool empty() {
        // Проверка на пустой масив
        if (m_start == m_end) {
            return true;
        }
        else {
            return false;
        }
    }

    bool full() {
        // Проверка на заполненый массив
        if ((m_end - m_start) == m_size) {
            return true;
        }
        else {
            return false;
        }
    }

    int pop() {
        // Чтение последенего элемента
        --m_end;
        return *m_end;
    }

    void push(int element) {
        //  Добавление в конец стека элемента
            *m_end = element;
            ++m_end;


    }
};

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
    ~my_queue(){
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

template <typename T>
const T& max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}

int main()
{
    setlocale(LC_ALL, "rus");
    electricity_meter meter(0, 100);
    meter.print_current_value();
    meter += 10;
    meter = meter + 10;
    //meter.increase_value(11);
    meter.print_current_value();
    //int STACK_SIZE = 4;
    //my_stack stack_1(STACK_SIZE);
    //std::cout << stack_1.empty() << std::endl;
    //while (!stack_1.full()) {
    //    stack_1.push(5);
    //}
    //std::cout << stack_1.full() << std::endl;
    //std::cout << stack_1.pop() << std::endl;

    //my_stack stack_2 = stack_1;
    //std::cout << stack_2.pop() << std::endl;
    
    //return 0;
    /*my_queue queue_1(3);
    queue_1.push(2);
    queue_1.push(3);
    queue_1.push(4);
    my_queue queue_2 = queue_1;
    std::cout << queue_2.get() << std::endl;*/

    //int a = max(1, 2);
    //a = 3;



}
