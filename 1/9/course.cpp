#include "course.h"
#include "student.h"
#include <iostream>
void Course::addStudent(Student& student)
{
	if (!student.isStudy()) {
		std::cout << "The student is already studying" << std::endl;
	}
	else if ((getCurrentStudents() >= getMaxStudents())) {
		std::cout << "Auditorium is full" << std::endl;
	}
	else {
		student.setCourse(m_courseName);
		m_students.push_back(student);
	}
}

void Course::deleteStudent(Student& student)
{
	m_students.erase(std::remove(m_students.begin(), m_students.end(), student), m_students.end()); // оператор == исправил ситуацию
}

int Course::getCurrentStudents()
{
	return m_students.size();
}

int Course::getMaxStudents()
{
	return m_maxStudents;
}

void Course::printStudents() {
	std::cout << m_courseName << std::endl;
	std::cout << "Current students: " << std::endl;
	for (Student student : m_students) {
		std::cout << student.getName() << std::endl;
	}
	std::cout << "--------------------------" << std::endl;
}