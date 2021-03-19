// Krokunova_9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "course.h"
#include "student.h"

int main()
{
    Course math{"Math",  20 };
    Student student1("Vasya", "Pupkin", 123);
    Student student2("Ivan", "Ivanovich", 456);
    math.addStudent(student1);
    math.addStudent(student2);
    math.printStudents();
    math.deleteStudent(student1);
    math.printStudents();

    Course physics("Physics",  1);
    Student student3("Petya", "Vaskin", 789);

    isStudyTogether(student1, student2);
    isStudyTogether(student1, student3);
}
