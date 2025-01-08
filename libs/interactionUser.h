#ifndef INTERACTIONUSER_H
#define INTERACTIONUSER_H

//libs standard
#include <iostream>

//Libs creat


class InteractionUser{
    private:

    public:
    //var 
        double time_typed_user;
    //Method 
        void timeTypedKeyboard (){
            std::cout << "Digete o quantas horas deseja estudar: " << std::endl;
            std::cin >> time_typed_user;
        }
};


#endif // INTERACTIONUSER_H