#include "Date.h"
#include "Student.h"
#include <iostream>
#include "Fraction.h"
#include <ctime>
#include <string>;
using namespace std;

int operator - (const Date& date_now, const Date& other_date)
{
    int thisDays = date_now.GetDay() + 31 * (date_now.GetMonth() - 1);
    int otherDays = other_date.GetDay() + 31 * (other_date.GetMonth() - 1);

    thisDays += (date_now.GetYear() % 4 == 0 && date_now.GetMonth() > 2);
    otherDays += (other_date.GetYear() % 4 == 0 && other_date.GetMonth() > 2);

    thisDays += (date_now.GetMonth() > 1);
    otherDays += (other_date.GetMonth() > 1);

    thisDays += date_now.GetMonth() / 2 + ((date_now.GetMonth() % 2 == 0 && date_now.GetMonth() > 7));
    otherDays += other_date.GetMonth() / 2 + ((other_date.GetMonth() % 2 == 0 && other_date.GetMonth() > 7));

    thisDays += 365 * (date_now.GetYear() - 1);
    otherDays += 365 * (other_date.GetYear() - 1);

    return thisDays - otherDays;
}

Group operator + (const Group& one, const Group two)
{
    Group result;
    result.SetGroupName(one.GetGroupName() + two.GetGroupName());
    result.SetCourse(one.GetCourse());
    result.SetSpecialization(one.GetSpecialization());

    for (int i = 0; i < one.GetCountOfStudent(); ++i)
    {
        result.NewStudent(*one.students[i]);
    }
    for (int i = 0; i < two.GetCountOfStudent(); ++i)
    {
        result.NewStudent(*two.students[i]);
    }

    return result;
}

bool operator > (const Student& a, const Student& b)
{
    return a.GetAverageGrade() > b.GetAverageGrade();
}

bool operator < (const Student& a, const Student& b)
{
    return a.GetAverageGrade() < b.GetAverageGrade();
}

bool operator >= (const Student& a, const Student& b)
{
    return a.GetAverageGrade() > b.GetAverageGrade();
}

bool operator <= (const Student& a, const Student& b)
{
    return a.GetAverageGrade() <= b.GetAverageGrade();
}

bool operator == (const Student& a, const Student& b)
{
    return a.GetAverageGrade() == b.GetAverageGrade();
}

bool operator != (const Student& a, const Student& b)
{
    return a.GetAverageGrade() != b.GetAverageGrade();
}

bool operator > (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() > b.GetCountOfStudent();
}

bool operator < (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() < b.GetCountOfStudent();
}

bool operator >= (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() >= b.GetCountOfStudent();
}

bool operator <= (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() <= b.GetCountOfStudent();
}

bool operator == (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() == b.GetCountOfStudent();
}

bool operator != (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() != b.GetCountOfStudent();
}

istream& operator >> (const istream& i, Student& d)
{

    cout << "surname: ";
    string answear;
    cin >> answear;
    d.SetSurname(answear);

    cout << "name: ";
    cin >> answear;
    d.SetName(answear);

    cout << "middle name: ";
    cin >> answear;
    d.SetMiddlName(answear);

    cout << "adress: ";
    cin >> answear;
    d.SetAdress(answear);

    cout << "phon: ";
    cin >> answear;
    d.SetPhone(answear);

    cout << "adress: ";
    cin >> answear;
    d.SetAdress(answear);

    return cin;

}

ostream& operator << (const ostream& i, Student& d)
{
    d.PrintStudent();
    d.PrintExam();
    d.PrintPractic();
    d.PrintHomeWork();
    return cout;
}

istream& operator >> (const istream& i, Group& g)
{

    cout << "Group: ";
    string answear;
    cin >> answear;
    g.SetGroupName(answear);

    cout << "Group Specification: ";
    cin >> answear;
    g.SetSpecialization(answear);

    cout << "Course: ";
    unsigned short amswear2;
    cin >> amswear2;
    g.SetCourse(amswear2);

    return cin;

}

ostream& operator << (const ostream& i, Group& d)
{
    d.PrintAllStudents();
    return cout;
}

istream& operator >> (const istream& i, Fraction& f)
{

    cout << "numerator: ";
    int answear;
    cin >> answear;
    f.SetNumerator(answear);

    cout << "denominator: ";
    cin >> answear;
    f.SetDenominator(answear);

    return cin;

}

ostream& operator << (const ostream& i, Fraction& f)
{
    f.Print();
    return cout;
}

int main()

/*   Student Malika;
   Malika.AddExam(10);
   Malika.AddExam(12);
   Malika.AddPractic(7);
   Malika.AddPractic(6);
   Malika.AddHomeWork(11);
   Malika.AddHomeWork(1);
   Malika.AddHomeWork(12);*/

   //Student Pasha;
   //Pasha.AddExam(2);
   //Pasha.AddExam(3);
   //Pasha.AddPractic(8);
   //Pasha.AddPractic(5);
   //Pasha.AddHomeWork(4);
   //Pasha.AddHomeWork(4);
   //Pasha.AddHomeWork(20);
   //Pasha.PrintStudent();

   //Group g;
   //g.NewStudent(Malika);
   //g.NewStudent(Lena);
   ///*   g.Expel();*/
   //g.PrintStudent();

   //g += Malika;

   //g.PrintStudent();

       //Group one;
   //one.NewStudent(Malika);
   //Group two;
   //two.NewStudent(Max);

   //if (a > b)
   //{
   //    cout << "a>b\n";
   //}

   //if (one == two)
   //{
   //    cout << "==\n";
   //}

 /*  Student a;
   Group g;
   g += a;
   g.PrintStudent();*/

   //Date:
   
   //Date now;
   //Date start(23, 7, 2021);
   //int days = now - start;
   //cout << days;
   // 
   //Student s;
   //cin >> s;
   //cout << s;

   //Group g;
   //cin >> g;
   //g.PrintStudent();

   //Fraction f;
   //cin >> f;
   //cout << f;



