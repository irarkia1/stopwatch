//libs standard
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <conio.h>

//path libs craidas
#include "libs/StopwatchTimeTyped.h"
#include "libs/StopwatchCalculation.h"
#include "libs/filerCreate.h"
#include "libs/countStopwatch.h"

//struct


//funtion main
int main(){


//variable standard
    double time_typed;

//message to client
    std::cout << "Digete o quantas horas deseja estudar: " << std::endl;
    std::cin >> time_typed;

//class
    Time_typed_client time_typed_client (time_typed);
    //time_typed_client.debug();
    
    Calculation_stopwatch calculation_stopwatch (time_typed_client);
    //calculation_stopwatch.debug();  

    SaiveFiler saiveFiler;
    saiveFiler.dateOfDay = std::to_string(time_typed);
    saiveFiler.filerSaive();

    Count_Stopwatch count_stopwatch;
    count_stopwatch.countStopwatch(calculation_stopwatch);
    
    //SaiveFiler saiveFiler;
    saiveFiler.finishCounth = count_stopwatch.getfinished();
    saiveFiler.logStopwatch = count_stopwatch.logRegister();
    saiveFiler.logRegister();
    //saiveFiler.getDebug();

//struct
   
//Finish coding
std::cout << "Pressione qualquer tecla para finalizar." << std::endl;
    std::cin.get();
    std::cin.get();
    return 0;
}