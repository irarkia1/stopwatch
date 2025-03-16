#ifndef StopwatchTimeTyped_H
#define StopwatchTimeTyped_H

#include <iostream>

class Time_typed_client{
    public:
        //var 
        int hours_typed;
        double minutes_typyd;
        //double seconds_typed;
        
        //method
            Time_typed_client(double time_typed){
                hours_typed = static_cast<int>(time_typed);
                minutes_typyd = (time_typed - hours_typed) *100;
            }

            void debug(){
                std::cout << "Horas digitadas: " << hours_typed << std::endl;
                std::cout << "Minutos digitados: " << minutes_typyd << std::endl; 
            }
    private:
};

#endif //StopwatchTimeTyped_H