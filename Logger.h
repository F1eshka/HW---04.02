#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

class Logger
{
    static Logger* instance;
    int log_ñount = 0;

    Logger(){}

public:
    static Logger* GetInstance()
    {
        return instance == nullptr ? instance = new Logger() : instance;
    }

    void Write(string message)
    {
        log_ñount++;
        cout << log_ñount << ": " << message << "\n";
        ofstream output_file("log.txt", ios::app);
        if (output_file.is_open()) {
            output_file << message << "\n";
            output_file.close();
        }
        else {
        }
    }
    void Write(int value)
    {
        Write(to_string(value));
    }
};

Logger* Logger::instance = nullptr;