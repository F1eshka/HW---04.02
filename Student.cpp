#include "Logger.h"
#include "Student.h"
#include <iostream>
using namespace std;

    /// <summary>
    /// Конструктор копирования класса Student.
    /// Создает копию студента на основе переданного объекта.
    /// </summary>
    /// <param name="original">Оригинальный студент, который будет скопирован.</param>
    

Student::Student(const Student& original)
    {
        cout << "COPY C-TOR\n";

        this->surname = original.surname;
        this->name = original.name;
        this->middlename = original.middlename;
        this->adress = original.adress;
        this->phonenumber = original.phonenumber;
        this->countpractic = original.countpractic;
        this->counthomework = original.counthomework;
        this->countexam = original.countexam;
        this->averagegrade = original.averagegrade;



        this->grade_of_practic = new int[original.countpractic];
        for (int i = 0; i < countpractic; i++)
        {
            this->grade_of_practic[i] = original.grade_of_practic[i];
        }

        this->grade_of_homework = new int[original.counthomework];
        for (int i = 0; i < counthomework; i++)
        {
            this->grade_of_homework[i] = original.grade_of_homework[i];
        }

        this->grade_of_exam = new int[original.countexam];
        for (int i = 0; i < countexam; i++)
        {
            this->grade_of_exam[i] = original.grade_of_exam[i];
        }
    }

    /// <summary>
    ///  Конструктор по умолчанию класса Student.
    /// Инициализирует студента значениями по умолчанию.
    /// </summary>
    Student::Student() : Student("Studenchenko", "Student", "Studentovich", "Studencheskaya 38", "0630300033") { Logger::GetInstance()->Write("Student has been created\n"); }

    /// <summary>
    /// Конструктор класса Student.
    /// Инициализирует студента с переданными значениями.
    /// </summary>
    /// <param name="surname">Фамилия студента.</param>
    /// <param name="name">Имя студента.</param>
    /// <param name="middlname">Отчество студента.</param>
    /// <param name="adress">Адрес студента.</param>
    /// <param name="phonenumber">Номер телефона студента.</param>
    Student::Student(string surname, string name, string middlname, string adress, string phonenumber)
    {
        cout << "MAIN C-TOR\n";
        SetSurname(surname);
        SetName(name);
        SetMiddlName(middlname);
        SetAdress(adress);
        SetPhone(phonenumber);
        Logger::GetInstance()->Write("Student has been added\n");
        Time();
    }
    


    /// <summary>
    /// Деструктор класса Student.
    /// Освобождает память, занятую массивами оценок.
    /// </summary>
    Student::~Student()
    {
        cout << "DESTRUCTOR\n";
        if (grade_of_practic != nullptr)
            delete[] grade_of_practic;
        if (grade_of_homework != nullptr)
            delete[] grade_of_homework;
        if (grade_of_exam != nullptr)
            delete[] grade_of_exam;
        Logger::GetInstance()->Write("Student has been deleted\n");
        Time();
    }

    void Student::Time()
    {
        SYSTEMTIME st;
        char title[200]{};
        GetSystemTime(&st);
        printf("%02d:%02d:%02d\n", (st.wHour + 3) % 24, st.wMinute, st.wSecond);
    }
    /// <summary>
    /// Выводит информацию о студенте в консоль.
    /// </summary>
    void Student::PrintStudent() const
    {
        cout << "Surname: " << surname << "\n";
        cout << "Name: " << name << "\n";
        cout << "Midlname: " << middlename << "\n";
        cout << "Adress: " << adress << "\n";
        cout << "Phonnumber: " << phonenumber << "\n";
        PrintExam();
        PrintPractic();
        PrintHomeWork();
        AverageGrade();
        Logger::GetInstance()->Write("Student print\n");
        Time();
    }

    void  Student::AverageGrade()
    {

        for (int i = 0; i < counthomework; i++)
        {
            averagegrade += grade_of_homework[i] / counthomework;
        }
        cout << averagegrade << "\n";
    }


    /// <summary>
    /// Добавляет новую оценку за практику студенту.
    /// </summary>
    /// <param name="newcountry">Новая оценка за практику.</param>
    void Student::AddPractic(int newcountry)
    {
        int* temp = new int[countpractic + 1];
        for (int i = 0; i < countpractic; i++)
        {
            temp[i] = grade_of_practic[i];
        }

        temp[countpractic] = newcountry;
        countpractic++;
        delete[]grade_of_practic;
        grade_of_practic = temp;
    }

    /// <summary>
    /// Выводит оценки за практику студента в консоль.
    /// </summary>
    void Student::PrintPractic() const
    {
        for (int i = 0; i < countpractic; i++)
        {
            cout << grade_of_practic[i] << ", ";
        }
    }

    /// <summary>
    /// Получает оценку за практику студента по указанному индексу.
    /// </summary>
    /// <param name="index">Индекс оценки за практику</param>
    /// <returns>Оценка за практику по указанному индексу</returns>
    int Student::GePracticRatesCount(unsigned int index) const
    {
        if (index < countpractic)
        {
            return grade_of_practic[index];
        }
    }

    /// <summary>
    /// Добавляет новую оценку за домашнюю работу студенту
    /// </summary>
    /// <param name="newcountry">Новая оценка за домашнюю работу</param>
    void Student::AddHomeWork(int newcountry)
    {
        int* temp = new int[counthomework + 1];
        for (int i = 0; i < counthomework; i++)
        {
            temp[i] = grade_of_homework[i];
        }
        temp[counthomework] = newcountry;
        counthomework++;
        delete[]grade_of_homework;
        grade_of_homework = temp;
    }

    /// <summary>
    /// Выводит оценки за домашнюю работу студента в консоль.
    /// </summary>
    void Student::PrintHomeWork() const
    {
        for (int i = 0; i < counthomework; i++)
        {
            cout << grade_of_homework[i] << ", ";
        }
    }

    /// <summary>
    /// Получает оценку за домашнюю работу студента по указанному индексу.
    /// </summary>
    /// <param name="index">Индекс оценки за домашнюю работу</param>
    /// <returns>Оценка за домашнюю работу по указанному индексу</returns>
    int Student::GetHomeWorkRatesCount(unsigned int index) const
    {
        if (index < counthomework)
        {
            return grade_of_homework[index];
        }
    }

    /// <summary>
    /// Добавляет новую оценку за экзамен студенту
    /// </summary>
    /// <param name="newcountry">Новая оценка за экзамен</param>
    void Student::AddExam(int newcountry)
    {
        int* temp = new int[countexam + 1];
        for (int i = 0; i < countexam; i++)
        {
            temp[i] = grade_of_exam[i];
        }
        temp[countexam] = newcountry;
        countexam++;
        delete[]grade_of_exam;
        grade_of_exam = temp;
    }

    /// <summary>
    /// Выводит оценки за экзамен студента в консоль
    /// </summary>
    void Student::PrintExam() const
    {
        for (int i = 0; i < countexam; i++)
        {
            cout << grade_of_exam[i] << ", ";
        }
    }

    /// <summary>
    /// Получает оценку за экзамен студента по указанному индексу
    /// </summary>
    /// <param name="index">Индекс оценки за экзамен</param>
    /// <returns>Оценка за экзамен по указанному индексу</returns>
    int Student::GetExamRatesCount(unsigned int index) const
    {
        if (index < countexam)
        {
            return grade_of_exam[index];
        }
    }

    /// <summary>
    /// Устанавливает фамилию студента
    /// </summary>
    /// <param name="surname">Новая фамилия студента</param>
    void Student::SetSurname(string surname)
    {
        this->surname = surname;
    }

    /// <summary>
    /// Возвращает фамилию студента
    /// </summary>
    /// <returns>Фамилия студента</returns>
    string Student::GetSurname() const
    {
        return surname;
    }

    /// <summary>
    /// Устанавливает имя студента
    /// </summary>
    /// <param name="name">Новое имя студента</param>
    void Student::SetName(string name)
    {
        this->name = name;
    }

    /// <summary>
    /// Возвращает имя студента
    /// </summary>
    /// <returns>Имя студента</returns>
    string Student::GetName() const
    {
        return name;
    }

    /// <summary>
    /// Устанавливает отчество студента
    /// </summary>
    /// <param name="middlname">Новое отчество студента</param>
    void Student::SetMiddlName(string middlname)
    {
        this->middlename = middlname;
    }

    /// <summary>
    /// Возвращает отчество студента
    /// </summary>
    /// <returns>Отчество студента</returns>
    string Student::GetMiddlName() const
    {
        return middlename;
    }

    /// <summary>
    /// Устанавливает адрес студента
    /// </summary>
    /// <param name="adress">Новый адрес студента</param>
    void Student::SetAdress(string adress)
    {
        this->adress = adress;
    }

    /// <summary>
    /// Возвращает адрес студента
    /// </summary>
    /// <returns>Адрес студента</returns>
    string Student::GetAdress() const
    {
        return adress;
    }

    /// <summary>
    ///  Устанавливает номер телефона студента
    /// </summary>
    /// <param name="phonenumber">Новый номер телефона студента</param>
    void Student::SetPhone(string phonenumber)
    {
        this->phonenumber = phonenumber;
    }

    /// <summary>
    /// Возвращает номер телефона студента
    /// </summary>
    /// <returns>Номер телефона студента</returns>
    string Student::GetPhone() const
    {
        return phonenumber;
    }

    /// <summary>
    /// Метод для демонстрации работы с передачей студента по значению.
    /// </summary>
    /// <param name="s">Студент, который будет передан</param>
    void Student::GoToPeresdacha(Student s)
{
    cout << "hey hey peresdacha...\n";
}
    void Student::SetAverageGrade(int averagegrade)
    {
        this->averagegrade = averagegrade;
    }
    int Student::GetAverageGrade() const
    {
        return averagegrade;
    }