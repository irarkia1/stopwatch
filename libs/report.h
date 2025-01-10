#ifndef REPORT_H
#define REPORT_H

//libs standard
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <exception>

//libs criet


//namespace
namespace filter = std::filesystem;

class ReportSearch {

        private:


            //var
            std::string pathDirectory = "./register";
            std::vector <std::string> filter_txt;

        public:
            
            ReportSearch(){
                try{
                    for(const auto& entrada : filter::directory_iterator(pathDirectory)){
                        if(entrada.is_regular_file() && entrada.path().extension() == ".txt"){
                            filter_txt.push_back(entrada.path().string());
                        }

                        std::cout << "Arquivos encontrados:\n";
                        for(const auto& entrada : filter_txt){
                            std::cout << entrada << std::endl;
                        }
                    }
                }catch(const std::exception& e){
                    std::cout << "Erro ao ler os arquivos" << e.what() << std::endl;
                }
            }

};



#endif // REPORT.H