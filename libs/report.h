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
            std::string dateBegin, dateEnd;

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
                     dateBegin = "register\\" + interaction.WhatReportBegin + ".txt";
                     dateEnd = "register\\" + interaction.WhatReportEnd + ".txt";
                     std::string line;
                     //std::cout << dateBegin << dateEnd << std::endl;

                    std::fstream openRepoth;
                    openRepoth.open(dateBegin, std::ios::in);

                    if(openRepoth.is_open()){
                         std::cout << "\n=========: REGISTRO SALVOS :=========:" << std::endl;
                        while(std::getline(openRepoth, line)){
                            std::cout << line << std::endl;
                            //std::cout << "=========REGISTRO SALVOS=========" << std::endl;
                        }
                        openRepoth.close();
                    }else{
                        std::cout << "Nao foi possivel abrir o arquivo" << std::endl;
                    }

            }
};



#endif // REPORT.H