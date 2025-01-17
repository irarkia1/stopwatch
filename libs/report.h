#ifndef REPORT_H
#define REPORT_H

//libs standard
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <exception>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>


//libs criet
#include "countStopwatch.h"
#include "StopwatchCalculation.h"

//namespace
namespace filter = std::filesystem;

class ReportSearch {

        private:


            //var
            std::string pathDirectory = "register";
            std::vector <std::string> filter_txt;
            std::vector<double> timeTypedRepoth;
            std::vector<std::chrono::duration<long long int>> calcuDateBeginEnd;
            std::vector <std::chrono::system_clock::time_point> begin;
            std::vector <std::chrono::system_clock::time_point> end;
        public:
            //method
            ReportSearch(){
                try{
                    for(const auto& entrada : filter::directory_iterator(pathDirectory)){
                        if(entrada.is_regular_file() && entrada.path().extension() == ".txt"){
                            filter_txt.push_back(entrada.path().string());
                        }
                        system("cls");
                        std::cout << "/////////Relatorios encontrados///////\n";
                        
                        for(const auto& entrada : filter_txt){
                            
                            std::string nameFile = entrada.substr(pathDirectory.length()+1);
                            size_t pos = nameFile.find(".txt");
                            if(pos != std::string::npos){
                                nameFile = nameFile.substr(0,pos);
                            }
                            std::cout << nameFile << std::endl;
                        }
                    }
                }catch(const std::exception& e){
                    std::cout << "Erro ao ler os arquivos" << e.what() << std::endl;
                }
            }

            void viewReportDetailed(const InteractionUser& interaction){
                    std::string dateBeginStr =  interaction.WhatReportBegin;
                    std::string dateEndStr = interaction.WhatReportEnd;

                    std::tm dateBegin = {}, dateEnd ={};
                    std::istringstream dateBeginISS{dateBeginStr}, dateEndISS{dateEndStr};

                    dateBeginISS >> std::get_time(&dateBegin, "%d-%m-%Y");
                    dateEndISS >> std::get_time(&dateEnd, "%d-%m-%Y");

                    if(dateBeginISS.fail() || dateBeginISS.fail()){
                        std::cerr << "Erro ao converter as datas fornecidas. Verifique o formato (dd-mm-yyyy)." << std::endl;
                        return;
                    }

                    std::vector<std::string> allLines;

                    while (std::mktime(&dateBegin) <= std::mktime(&dateEnd)) {
                        std::ostringstream oss;
                        oss << "register\\" << std::put_time(&dateBegin, "%d-%m-%Y") << ".txt";
                        std::string currentFileName  = oss.str();
                    

                        std::fstream openRepoth;
                        openRepoth.open(currentFileName, std::ios::in);

                        if(openRepoth.is_open()){
                            system("cls");
                            std::cout << "\n=========: Relatorio Detalhado: :=========:" << std::endl;
                            std::cout << "\n========Arquivo: " << currentFileName<< "========\n\n" << std::endl;
                            std::string line;
                            
                            while(std::getline(openRepoth, line)){
                                allLines.push_back(line);
                                std::cout << line << std::endl;
                            };
                            
                            std::cout << "\n\n     >>>>>>>>>> Total de tempo estudado <<<<<<<<<\n" << std::endl;
                            openRepoth.close();

                        }else{
                             std::cout << "Nao foi possivel abrir o arquivo: " << currentFileName << std::endl;
                        }
                        dateBegin.tm_mday++;
                        std::mktime(&dateBegin);
                    }
                 calculationReporth(allLines);
            }

            void calculationReporth(const std::vector<std::string>& lines){
                 std::string option01 = "Quantidade de Horas escol", option02 = "Inicio da contagem no dia", option03 = "O usuario parou a contage";
                    for (const auto& line02 : lines){
                        std::string capturado = line02.substr(0,25);

                        //Debug
                        //std::cout << capturado << std::endl;
                        
                        if(capturado == option01){
                            std::string capture01 = line02.substr(31);
                            double resultAllChoice = std::stod(capture01);
                            timeTypedRepoth.push_back (resultAllChoice);
                            //Debug
                            //std::cout << resultAllChoice << std::endl;

                        }else if (capturado == option02) {
                            std::string capture02 = line02.substr(27);


                            std::tm tm = {};
                            std::istringstream iss(capture02);
                            iss >> std::get_time(&tm, "%d-%m-%Y As %H %M %S");

                            if(iss.fail()){
                                std::cout << "Erro ao converter a data" << capture02 << std::endl;
                            }else{
                                auto resultAllBegin = std::chrono::system_clock::from_time_t(std::mktime(&tm));
                                begin.push_back (resultAllBegin);
                                 //Debug
                                std::cout << "DIA: " << capture02 <<" Ate ";
                                //std::cout << "Data convertida para 'begin': " << capture02 << std::endl;
                                //std::cout << "Valor adicionado a begin: " << resultAllBegin.time_since_epoch().count() << std::endl;
                            };

                        }else if (capturado == option03) {
                            std::string capture03 = line02.substr(35);
                                
                            std::tm tm{};
                            std::istringstream iss(capture03);
                            iss >> std::get_time(&tm, "%d-%m-%Y As %H %M %S");

                            if(iss.fail()){
                                std::cout << "Erro ao converter a data" << capture03 << std::endl;
                                
                            }else{
                                auto resultAllEnd = std::chrono::system_clock::from_time_t(std::mktime(&tm));
                                end.push_back(resultAllEnd);
                                //Debug
                                std::cout << capture03 << std::endl;
                                //std::cout << "Data convertida para 'E: " << capture03 << std::endl;
                                //std::cout << "Valor adicionado a End: " << resultAllEnd.time_since_epoch().count() << std::endl;
                            };

                            if(!begin.empty() && !end.empty()){
                                //Debug
                                //std::cout << "Begin size: " << begin.size() << ", End size: " << end.size() << std::endl;
                                // Calculando a diferença entre os primeiros elementos de 'begin' e 'end'
                                auto duration = std::chrono::duration_cast<std::chrono::seconds>(end[0] - begin[0]);
                                calcuDateBeginEnd.push_back(duration);

                                //calculando a duracao 
                                int SecondsReport = Calculation_stopwatch::Calculation_Report_All(duration);

                                // Formatando e imprimindo o tempo
                                
                                Count_Stopwatch::get_FormatTime_Report(SecondsReport);

                                // Imprimindo a duração
                                 //Debug
                                //std::cout << "\n segundos:" << duration.count() <<  std::endl;

                                // Limpando os vetores
                                begin.clear();
                                end.clear();
                                }else {
                                    std::cout << "Erro: Vetores 'begin' ou 'end' estão vazios." << std::endl;
                                }
                            
                        }else{
                            std::cout << "      ------------Fim do registro.----------\n\n" << std::endl;
                        }
                        //std::cout << capturado << std::endl;
                           
                    }       
            }


};


#endif // REPORT.H