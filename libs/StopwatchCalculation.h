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

            static int converterToSecond(double time) {
                // Separar a parte inteira e decimal do tempo (tempo em horas)
                int hours = static_cast<int>(time);              
                double fractionalPart = time - hours;           

                // Converter para minutos e depois para segundos
                int minutes = static_cast<int>(fractionalPart * 100); 
                int seconds = (hours * 3600) + (minutes * 60);       

                return seconds;
            }


            void debug(){
                std::cout << "Minutos total: " << minutes_all << std::endl;
                std::cout << "segundos total: " << seconds_all << std::endl;
            }

            static int Calculation_Report_All(std::chrono::duration<long long int> &calcule){
                return static_cast<int>(calcule.count());
                
            }

        //   static bool Calculation_TimeTyped_Or_Interupt(
        //     double timetyped,
        //     const std::chrono::system_clock::time_point &interupt
        //     ) {
        //     return interupt <= std::chrono::system_clock::time_point(std::chrono::seconds(timetyped));
        //     }


    private:
};

#endif // STOPWATCHCALCULATION_H