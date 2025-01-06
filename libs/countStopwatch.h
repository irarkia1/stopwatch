#ifndef COUNTSTOPWATCH_H
#define COUNTSTOPWATCH_H

//libs standard
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <conio.h>
#include <sstream>

//libs create
#include "datehours.h"
#include "StopwatchCalculation.h"

class Count_Stopwatch{
    private:
        std::string capitureDate;
        bool finished  = false;

         //formatation of hours
            std::string formatTime(int totalSeconds){
                int hours = totalSeconds / 3600;
                int minutes = totalSeconds % 3600 / 60;
                int seconds = totalSeconds % 60;

                std::stringstream timeStream;
                timeStream << (hours < 10 ? "0" : "") << hours << ":"
                           << (minutes < 10 ? "0" : "") << minutes << ":"
                           << (seconds < 10 ? "0" : "") << seconds;
                return timeStream.str();
            };

    public:
        void countStopwatch(const Calculation_stopwatch& calculation){
            double CalculateTime = calculation.seconds_all;
            
            //Verificarion if nagativo
                if (CalculateTime < 0) {
                    std::cerr << "Erro: tempo inválido." << std::endl;
                return;
                }

            //Count regrass
            while(CalculateTime >= 0){
                if(_kbhit()){
                    char stopCount = _getch();
                        if(stopCount == '\r'){
                            std::cout << "Tempo restante: " << formatTime(static_cast<int>(CalculateTime)) << std::endl;
                            finished  = true;
                            break;
                        }
                } 
            
                std::cout << "Tempo restante: " << formatTime(static_cast<int>(CalculateTime)) << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                CalculateTime--;
            }
     };

        std::string logRegister (){
            capitureDate = DateHours::get_horas();
            return capitureDate;
        }
     
        bool getfinished () const{
            return finished ;
        }
};


#endif