#ifndef INTERACTIONUSER_H
#define INTERACTIONUSER_H

//libs standard
#include <iostream>
#include <string>
#include <typeinfo>
#include <limits>

//Libs creat


class InteractionUser{
    private:
        bool valid_input = false;
        bool valid_imput_questUser = false;
    public:
    //object
        int questCliente;


    //var 
        double time_typed_user;
        
    //Method 
        int questUser(){
             
            while(!valid_imput_questUser){
                std::cout << "Ver relatorio: (1)" << std::endl;
                std::cout << "Usar conometro: (2)" << std::endl;
                std::cin >> questCliente;

               if( std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout << "Digite uma opcao valida: 1 ou 2" << std::endl;
                   
                    continue;
               }
               if(questCliente == 1 || questCliente == 2){
                    std::cout << "\n\n:Registros salvos:" << std::endl;
                    valid_imput_questUser = true;
               }else{
                    std::cout << "\n\n\nDigite uma opcao valida: 1 ou 2\n\n" << std::endl;
               }
                
            }
            return questCliente;
                
        };
           
             
        void timeTypedKeyboard (){
            do{
                std::cout << "Digite o tempo que deseja estudar (EX: 1.10): " << std::endl;
                std::cin >> time_typed_user;

            //validation
                if(std::cin.fail()){
                    std::cout << "Divite um valor valido (EX: 10.12): " << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }else if(time_typed_user < 0){
                    std::cout << "Valor deve ser maior que 0 (EX: 00.01): " << std::endl;
                } else{
                     valid_input = true;
                }
            }while(!valid_input);
            std::cout << "Voce deseja estudar " << time_typed_user << " horas." << std::endl;
            
        };
};

#endif // INTERACTIONUSER_H