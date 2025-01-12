#ifndef FILER_H
#define FILER_H

//libs standard
#include <fstream>
#include <iostream>
#include <string>

//libs create
#include "datehours.h"

class SaiveFiler{
    private:
        //var
            std::string captureDate;
            std::string dayRegister;
            std::string PathRegister;
            std::string captureDateHours;
            std::string captureHours;
            
        
        //method
            void setPathRegister(){
                PathRegister = "register\\";
            }

    public:
        //var   
        std::string dateOfDay;
        std::string logStopwatch;
        std::string houtsRegister;
        std::string dayHoutsRegister;
        bool finishCounth;
        
        
        
        //method

            SaiveFiler(){
                setPathRegister();
                captureDate = DateHours::get_date();
                captureHours = DateHours::get_horas();
                captureDateHours = DateHours::get_date_horas();
                dayRegister = PathRegister + captureDate + ".txt";
                dayHoutsRegister =captureDateHours;

            }

            void filerSaive(){
                std::fstream filer;
                filer.open(dayRegister, std::ios::out | std::ios::app);

                if(filer.is_open()){
                    filer << "Quantidade de Horas escolhida: " + dateOfDay;
                    filer << "\nInicio da contagem no dia: " + captureDate + " As " + captureHours + "\n";
                    filer.close();
                    std::cout << "Salvo registro do dia" << std::endl;
                    
                } else {
                    std::cerr << "Erro ao salvar" << std::endl;
                }

            }

            void logRegister(){
                std::fstream filer;
                filer.open(dayRegister, std::ios::out | std::ios::app);

                if(filer.is_open()) {
                    filer << "O usuario parou a contagem no dia: " + captureDate +" As: "+ logStopwatch + "\n\n";
                        if(finishCounth){
                             std::cerr << "log Registrado." << std::endl;
                            filer.close();
                        }

                }else{
                      std::cerr << "Erro ao Registrar log" << std::endl;
                }
            }
            

            void getDebug(){
                std::cout << PathRegister << std::endl;
                std::cout << captureDate << std::endl;
                std::cout << dayRegister << std::endl;
                std::cout << captureDateHours << std::endl;
                std::cout << captureHours << std::endl;
                std::cout << dateOfDay << std::endl;
                std::cout << logStopwatch << std::endl;
                std::cout << houtsRegister << std::endl;
                //std::cout << dayHoutsRegister << std::endl;
                std::cout << finishCounth << std::endl;
            }
};

#endif // FILER_H