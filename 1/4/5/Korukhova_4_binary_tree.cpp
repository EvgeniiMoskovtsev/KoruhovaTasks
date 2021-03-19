// Korukhova_4_binary_tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Node {
private:
    int m_value;
    Node* left_child;
    Node* right_child;
public:
    Node(int input_value) {
        m_value = input_value;
        left_child = NULL;
        right_child = NULL;
    }

    void SetLeft(Node * ptr) {
        left_child = ptr;
    }

    void SetRight(Node* ptr) {
        right_child = ptr;
    }

    int GetValue() {
        return m_value;
    }
};

class Tree {
private:
    Node* root;
public:
    Tree(int input_value) {
        root = new Node(input_value);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
