#ifndef STOPWATCHCALCULATION_H
#define STOPWATCHCALCULATION_H

#include <iostream>
#include <chrono>
#include <thread>

//path libs craidas

class Calculation_stopwatch {
    public:
        //var
            double minutes_all;
            double seconds_all;

        //method
            Calculation_stopwatch(const Time_typed_client& ObjTimeTyped){
                minutes_all = (ObjTimeTyped.hours_typed * 60) + ObjTimeTyped.minutes_typyd;
                seconds_all = minutes_all  * 60; 
            }

            void debug(){
                std::cout << "Minutos total: " << minutes_all << std::endl;
                std::cout << "segundos total: " << seconds_all << std::endl;
            }

            static int Calculation_Report_All(std::chrono::duration<long long int> &calcule){
                return static_cast<int>(calcule.count());
                
            }
    private:
};

#endif // STOPWATCHCALCULATION_H