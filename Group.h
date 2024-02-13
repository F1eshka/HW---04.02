#pragma once
#include "Student.h"

class Group {
public:
    Student** students = nullptr;
private:
    unsigned short size = 0;
    string groupName;
    string specialization;
    unsigned short course = 0;

public:
    Group();

    Group(const Group& other);

    ~Group();

    void NewStudent(const Student& newstudent);

    void ExcludedStudent(unsigned short index);

    void LaggingStudent();

    void SetCountOfStudent(int countstudent);

    int  GetCountOfStudent() const;

    void SetGroupName(const string& name);

    string GetGroupName() const;

    void SetSpecialization(const string& spec);

    string GetSpecialization() const;

    void SetCourse(int course);

    int  GetCourse() const;

    Group& operator += (const Student& n)
    {
        NewStudent(n);
        return *this;
    }
    void PrintAllStudents() const;
};