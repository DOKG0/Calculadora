#include "calculadora.h"
#include "funciones.h"
#include <iostream>


int main()
{
    bool flag = false;
    int opt = 0;
    do{
        system("clear");
        opt = pedirOpcion();
        switch(opt){
        case 1:
            sumar();
            break;
        case 2:
            resto();
            break;
        case 3:
            multiplico();
            break;
        case 4:
            divido();
            break;
        case 5:
            elevarnumero();
            break;
        case 6:
            elevonumeroaotro();
            break;
        case 7:
            raiz();
            break;
        case 8:
            factorial();
            break;
        case 9:
            logaritmo();
            break;
        case 10:
            flag = true;
            break;
        }
    } while (!flag);
    return 0;
}


   