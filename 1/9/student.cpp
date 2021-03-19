#include <iostream>
#include "student.h"

bool Student::isStudy() const {
	return m_courseName.empty();
}

const std::string& Student::getName() const {
	return m_firstName;
}

const std::string& Student::getCourse() const {
	return m_courseName;
}

void Student::setCourse(const std::string& courseName) {
	m_courseName = courseName;
}


void isStudyTogether(const Student& student1,const Student& student2){ //const Student& не работает, т.к. getCourse не константный метод
	if (student1.getCourse() == student2.getCourse()) {
		std::cout << student1.getName() << " study together with " << student2.getName() << std::endl;
	}
	else {
		std::cout << student1.getName() << " doesn't study together with " << student2.getName() << std::endl;
	}
}