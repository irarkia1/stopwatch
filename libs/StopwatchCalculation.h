#ifndef STOPWATCHCALCULATION_H
#define STOPWATCHCALCULATION_H

#include <iostream>
#include <chrono>
#include <thread>
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
    private:
};

// class Count_Stopwatch{
//     public:
//         //var
        
//         //method
//             void countStopwatch(const Calculation_stopwatch& CalculateTime){
//                 if (true == true){
//                     for(int i = CalculateTime.seconds_all; i >= 0; i--){
//                         std::this_thread::sleep_for(std::chrono::seconds(1));
//                         std::cout << "Tempo restante: " << i << std::endl;
//                     }
//                 }
//             }
//     private:
// };
#endif // STOPWATCHCALCULATION_H