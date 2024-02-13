#pragma once
class Date
{
        unsigned short day;
        unsigned short month;
        long long year;
    public:

        Date();

        Date(unsigned short day, unsigned short month, long long year);
        Date(unsigned short day, unsigned short month) : Date(day, month, 2006) {};

        void PrintDate() const;
        void SetDay(unsigned short day);
        unsigned short GetDay() const;
        void SetMonth(unsigned short month);
        unsigned short GetMonth() const;
        void SetYear(long long year);
        long long GetYear() const;
    }; 



