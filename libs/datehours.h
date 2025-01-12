#ifndef DATES_H
#define DATES_H

#include <chrono>
#include <iostream>
#include <iomanip>
#include <string>

class DateHours{
    private:
       

    public:
          
            static std::string get_date_horas(){
                auto now = std::chrono::system_clock::now();
                auto in_time_t = std::chrono::system_clock::to_time_t(now);

                std::ostringstream oss;
                oss << std::put_time(std::localtime(&in_time_t), "%d-%m-%Y %H %M %S");
                return oss.str();

            }

            static std::string get_date(){
                auto now = std::chrono::system_clock::now();
                auto in_time_t = std::chrono::system_clock::to_time_t(now);

                std::ostringstream oss;
                oss << std::put_time(std::localtime(&in_time_t), "%d-%m-%Y");
                return oss.str();

            }

             static std::string get_horas(){
                auto now = std::chrono::system_clock::now();
                auto in_time_t = std::chrono::system_clock::to_time_t(now);

                std::ostringstream oss;
                oss << std::put_time(std::localtime(&in_time_t), "%H %M %S");
                return oss.str();

            }
};

#endif //Datas_H