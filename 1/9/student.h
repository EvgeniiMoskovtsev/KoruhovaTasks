#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
	std::string m_firstName;
	std::string m_lastName;
	int m_passportNumber;
	std::string m_courseName;

public:
	Student(std::string firstName, std::string lastName, int passportNummber, std::string courseName="")
		:m_firstName(firstName), m_lastName(lastName), m_passportNumber(passportNummber), m_courseName(courseName)
	{

	}

	bool operator==(const Student& other) {
		return (m_passportNumber == other.m_passportNumber);
	}

	bool isStudy() const;
	const std::string& getCourse() const;
	const std::string& getName() const;

private:
	void setCourse(const std::string& courseName);

	friend class Course;

};

void isStudyTogether(const Student& student1, const Student& student2);

#endif // !STUDENT

