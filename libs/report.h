#ifndef REPORT_H
#define REPORT_H

//libs standard
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <exception>
#include <fstream>

//libs criet


//namespace
namespace filter = std::filesystem;

class ReportSearch {

        private:


            //var
            std::string pathDirectory = "register";
            std::vector <std::string> filter_txt;
            double resultAllChoice, resultAllBegin, resultAllEnd;
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
                            std::cout << "\n=========: REGISTRO SALVOS :=========:" << std::endl;
                            std::cout << "\nLendo arquivo..........................:\n " << currentFileName << std::endl;
                            std::string line;

                            while(std::getline(openRepoth, line)){
                                allLines.push_back(line);
                                std::cout << line << std::endl;
                            }
                        
                            openRepoth.close();

                        }else{
                             std::cout << "Não foi possível abrir o arquivo: " << currentFileName << std::endl;
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
                                //Debug
                                //std::cout << "Data convertida com sucesso! Inicio" << std::endl;
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
                                //Debug
                                //std::cout << "Data convertida com sucesso! Final" << std::endl;
                            }
                        }else{
                            std::cout << "Err:210" << std::endl;
                        }
                        //std::cout << capturado << std::endl;
                            
                    }       
            }


};



#endif // REPORT.H