#ifndef COURSE_H
#define COURSE_H
#include <vector>
#include "student.h"

class Course {
	int m_maxStudents;
	std::string m_courseName;
	std::vector<Student> m_students;
public:
	Course(std::string courseName, int maxStudents)
		:m_courseName(courseName), m_maxStudents(maxStudents)
	{

	}

	void addStudent(Student& student);
	void deleteStudent(Student& student);
	int getMaxStudents();
	int getCurrentStudents();
	void printStudents();

};
#endif // COURSE_H

