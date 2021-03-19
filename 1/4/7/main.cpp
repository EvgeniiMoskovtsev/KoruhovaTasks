#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class cat {
public:
	double weight;
	char name[100];
public:
	cat(const char* n, double w = 12.0) : weight(w) {
		strcpy(name, n);
	}
	cat(double w) : weight(w) {
		strcpy(name, "cat");
	}

};
int f(const cat c1, const cat c2, const cat& c3, const cat& c4)
{
	return c1.weight + c2.weight + c3.weight + c4.weight;
}
int main() {
	f("Murzik", 22.0, "Kuzya", 10.2);
	return 0;
}
