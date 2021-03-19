#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

#define Q_(X) #X
#define QUOTE(X) Q_(X)

enum class OperationType
{
	TOPUP, //eTopup
	TAKEOFF  //eTakeoff
};
struct Operation {
	std::time_t operationDate;
	OperationType operationType;
	double money;
	bool isStore;
};

struct Person {
	std::string firstName;
	std::string lastName;
};

class Account {
private:
	std::time_t  m_accountDate; // как сделать const
	Person m_holder; // как сделать const
	Operation* m_lastOperations;
	double m_currentMoney;
	int m_operationCounter;

	void putInfoOperation(OperationType type, double money) {
		if (m_operationCounter > 9) {
			m_operationCounter = 0;
		}
		m_lastOperations[m_operationCounter].operationDate = std::time(nullptr);
		m_lastOperations[m_operationCounter].operationType = type;
		m_lastOperations[m_operationCounter].money = money;
		m_lastOperations[m_operationCounter].isStore = true;
		++m_operationCounter;
	};
	std::string operationType(OperationType type) {
		if (type == OperationType::TOPUP) {
			return "top up";
		}
		if (type == OperationType::TAKEOFF) {
			return "take off";
		}
		else {
			throw -1;
		}

	}
public:
	Account(Person holder, double money)
		: m_accountDate(std::time(nullptr)),
		m_holder(holder),
		m_currentMoney(money),
		m_operationCounter(0)
	{
		m_lastOperations = new (std::nothrow) Operation[10]();
		if (m_lastOperations == 0) { 
			throw std::runtime_error("Out of memory " QUOTE(__LINE__));
		}
	}
	~Account() {
		delete[] m_lastOperations;
	}
	Account(const Account& other) {
		m_accountDate = other.m_accountDate; 
		m_holder = other.m_holder;
		m_currentMoney = other.m_currentMoney;
		m_operationCounter = other.m_operationCounter;
		m_lastOperations = new (std::nothrow) Operation[10]();
		if (m_lastOperations == 0) {
			throw - 1;
		}
		for (int i = 0; i < 10; ++i) {
			m_lastOperations[i] = other.m_lastOperations[i];
		}
	}

	Account& operator=(const Account& other) {
		delete[] m_lastOperations;

		m_accountDate = other.m_accountDate;
		m_holder = other.m_holder;
		m_currentMoney = other.m_currentMoney;
		m_lastOperations = new (std::nothrow) Operation[10]();
		if (m_lastOperations == 0) {
			throw - 1;
		}
		for (int i = 0; i < 10; ++i) {
			m_lastOperations[i] = other.m_lastOperations[i];
		}
	}

	void topUp(double money) {
		m_currentMoney += money;
		putInfoOperation(OperationType::TOPUP, money);
	};
	void takeOff(double money) {
		if ((m_currentMoney - money) < 0) {
			std::cout << "Cant take off " << money << " when account has " << m_currentMoney << std::endl;
		}
		else {
			m_currentMoney -= money;
			putInfoOperation(OperationType::TAKEOFF, money);
		}
	};
	void printLastOperations() {
		for (Operation* op = m_lastOperations; op != (m_lastOperations + 10); ++op) {
			if (op->isStore == true) {
				std::cout << "Operation date: " << std::put_time(std::localtime(&op->operationDate), "%c %Z") << std::endl;
				std::cout << "Operation money: " << op->money << std::endl;
				std::cout << "Operation type: " << operationType(op->operationType) << std::endl;

			}
		}
	};
	void printCurrentMoney() {
		std::cout << "Current money: " << m_currentMoney << std::endl;
	}
};
#endif // !ACCOUNT_H
