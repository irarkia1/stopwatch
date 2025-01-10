//libs standard
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <conio.h>
#include <filesystem>
#include <windows.h>

//path libs craidas
#include "libs/StopwatchTimeTyped.h"
#include "libs/StopwatchCalculation.h"
#include "libs/filerCreate.h"
#include "libs/countStopwatch.h"
#include "libs/interactionUser.h"
#include "libs/report.h"

//struct

//API WINDOWS

// Função para alterar o ícone da janela


//funtion main
int main(){
//var

//criat mkdir
std::filesystem::create_directory("register");
//{-----------------
InteractionUser interactionUser;
// var
 bool valid_input = false;
//quest cliente to report
    while (!valid_input) {
    
        if(interactionUser.questUser() == 1){
        ReportSearch reportSearch;
        
        };
        valid_input = true;
    }

    interactionUser.timeTypedKeyboard();
    double time_typed = interactionUser.time_typed_user;
//}-----------------    
//message to client

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