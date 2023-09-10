#include <iostream>
#include "funciones.h"
#include "calculadora.h"
#include <limits>


void limpiarBuffer(){
    while (getchar() != '\n'){
        //pass
    }
}

void pausa(std::string msg){
    std::cout << msg;
    while(getchar() != '\n'){
        //para generar pausa
    }
    getchar();
}

char confirmarSN(std::string msg){

    std::cin.ignore();
    std::cin.clear();
    while (true) {
        std::string respuesta;
        std::cout << msg << std::endl;
        std::cout << "Digite (s/n) para confirmar: ";
        std::getline(std::cin, respuesta);

        if (respuesta.length() == 1) {
            char opcion = respuesta[0];
            if (opcion == 's' || opcion == 'S') {
                return 's';
            } else if (opcion == 'n' || opcion == 'N') {
                return 'n';
            }
        }
        pausa("Respuesta inválida. Por favor, ingresa 's' para Sí o 'n' para No.");
        system("clear");
    }
    
}

char Confirmacion(char opcion) {
    //char opcion;
    bool entrada_valida = false;
    
    do {
        std::cout << "Ingrese 's' para Sí o 'n' para No: ";
        std::cin >> opcion;
        
        // Limpiar el buffer del cin en caso de que se ingresen caracteres adicionales
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        // Verificar que solo se haya ingresado un carácter válido
        if (opcion == 's' || opcion == 'n') {
            entrada_valida = true;
        } else {
            std::cout << "Entrada inválida. Intente nuevamente." << std::endl;
        }
    } while (!entrada_valida);
    
    return opcion;
}

void menu(){
    std::cout << "\tCALCULADORA\n" << std::endl;
    std::cout << "1. Sumar" << std::endl;
    std::cout << "2. Restar" << std::endl;
    std::cout << "3. Multiplicar" << std::endl;
    std::cout << "4. Dividir" << std::endl;
    std::cout << "5. Elevar numero x al cuadrado" << std::endl;
    std::cout << "6. Elevar numero x al numero y" << std::endl;
    std::cout << "7. Raiz Cuadrada" << std::endl;
    std::cout << "8. Factorial" << std::endl;
    std::cout << "9. Logaritmo" << std::endl;
    std::cout << "10. Salir" << std::endl;
}

int pedirOpcion(){
    int opcion = 0;
    
    while (true){
        menu();
        std::cout << "\nIngrese una opcion valida: ";
        std::cin >> opcion;
        limpiarBuffer();
        if (opcion >=1 and opcion <= 19){
            break; //salgo while
            std::cin.clear();
        }
        pausa("El valor ingresado es invalido, por favor ingrese un valor valido.");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("clear");
    };

    return opcion;
};


void sumar (){

    system("clear");
    int numx1,numx2;
    Calculadora * operaciones;
    std::cout << "|======|" << std::endl;
    std::cout << "  SUMA." << std::endl;
    std::cout << "|======|" << std::endl;
    char confirmacion;
    float result;
    bool flag = false;

    std::cout << "Ingresar primer numero" << std::endl;
    std::cout << ">...";
    std::cin >> numx1;
    std::cout << "\n";
    std::cout << "Ingresar segundo numero" << std::endl;
    std::cout << ">...";
    std::cin >> numx2;
    std::cout << "\n";
    operaciones = new Calculadora(numx1,numx2);
    result = operaciones->sumar();
    do{
        std::cout << "Desea seguir en la misma operacion (s/n)?" << std::endl;
        std::cin >> confirmacion;
        confirmacion = std::tolower(confirmacion);
        if(confirmacion == 's'){
            system("clear");
            std::cout << "|======|" << std::endl;
            std::cout << "  SUMA." << std::endl;
            std::cout << "|======|" << std::endl;
            flag = true;
            std::cout << "Numero anterior = " << result << std::endl;
            std::cout << "Ingresar numero" << std::endl;
            std::cout << ">...";
            std::cin >> numx2;
            operaciones = new Calculadora(result,numx2);
            result = operaciones->sumar();
            std::cout << std::endl;
            //pausa("Presione enter para continuar...");
        }else{
            flag = false;
            pausa("Presione enter para volver al menu.");
        }
    }while(flag == true);
    
}

void elevarnumero(){
    system("clear");
    std::cout << "|=============================|" << std::endl;
    std::cout << "  Elevar numero al cuadrado." << std::endl;
    std::cout << "|=============================|" << std::endl;

    int numx1;
    char confirmacion;
    float result;
    bool flag = false;
    Calculadora * operaciones;

    std::cout << "Ingresar numero" << std::endl;
    std::cout << ">...";
    std::cin >> numx1;
    operaciones = new Calculadora(numx1);
    result = operaciones->ElevarAlCuadrado();
do{
        std::cout << "Desea seguir en la misma operacion (s/n)?" << std::endl;
        std::cin >> confirmacion;
        confirmacion = std::tolower(confirmacion);
        if(confirmacion == 's'){
            system("clear");
            std::cout << "|=============================|" << std::endl;
            std::cout << "  Elevar numero al cuadrado." << std::endl;
            std::cout << "|=============================|" << std::endl;
            flag = true;
            std::cout << "Numero anterior = " << result << std::endl;
            operaciones = new Calculadora(result);
            result = operaciones->ElevarAlCuadrado();
            std::cout << std::endl;
            //pausa("Presione enter para continuar...");
        }else{
            flag = false;
            pausa("Presione enter para volver al menu.");
        }
    }while(flag == true);
}

void resto(){
    system("clear");
    std::cout << "|=======|" << std::endl;
    std::cout << "  RESTA." << std::endl;
    std::cout << "|=======|" << std::endl;
    int numx1,numx2;
    char confirmacion;
    float result;
    bool flag = false;
    Calculadora * operaciones;
    
    std::cout << "Ingresar primer numero" << std::endl;
    std::cout << ">...";
    std::cin >> numx1;
    std::cout << "\n";
    std::cout << "Ingresar segundo numero" << std::endl;
    std::cout << ">...";
    std::cin >> numx2;
    std::cout << "\n";
    operaciones = new Calculadora(numx1,numx2);
    result = operaciones->restar();
    do{
        std::cout << "Desea seguir en la misma operacion (s/n)?" << std::endl;
        std::cin >> confirmacion;
        confirmacion = std::tolower(confirmacion);
        if(confirmacion == 's'){
            system("clear");
            std::cout << "|=======|" << std::endl;
            std::cout << "  RESTA." << std::endl;
            std::cout << "|=======|" << std::endl;
            flag = true;
            std::cout << "Numero anterior = " << result << std::endl;
            std::cout << "Ingresar numero" << std::endl;
            std::cout << ">...";
            std::cin >> numx2;
            operaciones = new Calculadora(result,numx2);
            result = operaciones->restar();
            std::cout << std::endl;
            //pausa("Presione enter para continuar...");
        }else{
            flag = false;
            pausa("Presione enter para volver al menu.");
        }
    }while(flag == true);

}

void multiplico(){
    system("clear");
    std::cout << "|================|" << std::endl;
    std::cout << "  MULTIPLICACION." << std::endl;
    std::cout << "|================|" << std::endl;
    int numx1,numx2;
    char confirmacion;
    float result;
    bool flag = false;
    Calculadora * operaciones;
    
    std::cout << "Ingresar primer numero" << std::endl;
    std::cout << ">...";
    std::cin >> numx1;
    std::cout << "\n";
    std::cout << "Ingresar segundo numero" << std::endl;
    std::cout << ">...";
    std::cin >> numx2;
    std::cout << "\n";
    operaciones = new Calculadora(numx1,numx2);
    result = operaciones->multiplicar();
    do{
        std::cout << "Desea seguir en la misma operacion (s/n)?" << std::endl;
        std::cin >> confirmacion;
        confirmacion = std::tolower(confirmacion);
        if(confirmacion == 's'){
            system("clear");
            std::cout << "|================|" << std::endl;
            std::cout << "  MULTIPLICACION." << std::endl;
            std::cout << "|================|" << std::endl;
            flag = true;
            std::cout << "Numero anterior = " << result << std::endl;
            std::cout << "Ingresar numero" << std::endl;
            std::cout << ">...";
            std::cin >> numx2;
            operaciones = new Calculadora(result,numx2);
            result = operaciones->multiplicar();
            std::cout << std::endl;
            //pausa("Presione enter para continuar...");
        }else{
            flag = false;
            pausa("Presione enter para volver al menu.");
        }
    }while(flag == true);
}

void divido(){
    system("clear");
    std::cout << "|==========|" << std::endl;
    std::cout << "  DIVISION." << std::endl;
    std::cout << "|==========|" << std::endl;
    int numx1,numx2;
    char confirmacion;
    float result;
    bool flag = false;
    Calculadora * operaciones;
    
    std::cout << "Ingresar primer numero" << std::endl;
    std::cout << ">...";
    std::cin >> numx1;
    std::cout << "\n";
    std::cout << "Ingresar segundo numero" << std::endl;
    std::cout << ">...";
    std::cin >> numx2;
    std::cout << "\n";
    operaciones = new Calculadora(numx1,numx2);
    result = operaciones->dividir();
    do{
        std::cout << "Desea seguir en la misma operacion (s/n)?" << std::endl;
        std::cin >> confirmacion;
        confirmacion = std::tolower(confirmacion);
        if(confirmacion == 's'){
            system("clear");
            std::cout << "|==========|" << std::endl;
            std::cout << "  DIVISION." << std::endl;
            std::cout << "|==========|" << std::endl;
            flag = true;
            std::cout << "Numero anterior = " << result << std::endl;
            std::cout << "Ingresar numero" << std::endl;
            std::cout << ">...";
            std::cin >> numx2;
            operaciones = new Calculadora(result,numx2);
            result = operaciones->dividir();
            std::cout << std::endl;
            //pausa("Presione enter para continuar...");
        }else{
            flag = false;
            pausa("Presione enter para volver al menu.");
        }
    }while(flag == true);
}

void elevonumeroaotro(){
    system("clear");
    std::cout << "|=====================================|" << std::endl;
    std::cout << "  ELEVAR NUMERO \"X\" A NUMERO \"Y\"." << std::endl;
    std::cout << "|=====================================|" << std::endl;
    int numx1,numx2;
    char confirmacion;
    float result;
    bool flag = false;
    Calculadora * operaciones;
    
    std::cout << "Ingresar primer numero" << std::endl;
    std::cout << ">...";
    std::cin >> numx1;
    std::cout << "\n";
    std::cout << "Ingresar segundo numero" << std::endl;
    std::cout << ">...";
    std::cin >> numx2;
    std::cout << "\n";
    operaciones = new Calculadora(numx1,numx2);
    result = operaciones->ElevarAUnNumero();
    do{
        std::cout << "Desea seguir en la misma operacion (s/n)?" << std::endl;
        std::cin >> confirmacion;
        confirmacion = std::tolower(confirmacion);
        if(confirmacion == 's'){
            system("clear");
            std::cout << "|=====================================|" << std::endl;
            std::cout << "  ELEVAR NUMERO \"X\" A NUMERO \"Y\"." << std::endl;
            std::cout << "|=====================================|" << std::endl;
            flag = true;
            std::cout << "Numero anterior = " << result << std::endl;
            std::cout << "Ingresar numero" << std::endl;
            std::cout << ">...";
            std::cin >> numx2;
            operaciones = new Calculadora(result,numx2);
            result = operaciones->ElevarAUnNumero();
            std::cout << std::endl;
            //pausa("Presione enter para continuar...");
        }else{
            flag = false;
            pausa("Presione enter para volver al menu.");
        }
    }while(flag == true);
}

void raiz(){
    system("clear");
    std::cout << "|================|" << std::endl;
    std::cout << "  RAIZ CUADRADA. " << std::endl;
    std::cout << "|================|" << std::endl;
    int numx1;
    char confirmacion;
    float result;
    bool flag = false;
    Calculadora * operaciones;
    
    std::cout << "Ingresar numero" << std::endl;
    std::cout << ">...";
    std::cin >> numx1;
    operaciones = new Calculadora(numx1);
    result = operaciones->RaizCuadrada();
    do{
        std::cout << "Desea seguir en la misma operacion (s/n)?" << std::endl;
        std::cin >> confirmacion;
        confirmacion = std::tolower(confirmacion);
        if(confirmacion == 's'){
            system("clear");
            std::cout << "|================|" << std::endl;
            std::cout << "  RAIZ CUADRADA. " << std::endl;
            std::cout << "|================|" << std::endl;
            flag = true;
            operaciones = new Calculadora(result,numx1);
            result = operaciones->RaizCuadrada();
            std::cout << std::endl;
            //pausa("Presione enter para continuar...");
        }else{
            flag = false;
            pausa("Presione enter para volver al menu.");
        }
    }while(flag == true);
}

void factorial(){
    system("clear");
    std::cout << "|============|" << std::endl;
    std::cout << "  FACTORIAL. " << std::endl;
    std::cout << "|============|" << std::endl;
    int numx1;
    char confirmacion;
    float result;
    bool flag = false;
    Calculadora * operaciones;
    
    std::cout << "Ingresar numero" << std::endl;
    std::cout << ">...";
    std::cin >> numx1;
    operaciones = new Calculadora(numx1);
    operaciones->Factorial();
    std::cout << std::endl;
    pausa("Presione enter para volver al menu.");
}

void logaritmo(){
    system("clear");
    std::cout << "|============|" << std::endl;
    std::cout << "  LOGARITMO. " << std::endl;
    std::cout << "|============|" << std::endl;
    int numx1;
    char confirmacion;
    float result;
    bool flag = false;
    Calculadora * operaciones;
    
    std::cout << "Ingresar numero" << std::endl;
    std::cout << ">...";
    std::cin >> numx1;
    operaciones = new Calculadora(numx1);
    operaciones->Logaritmo();
    std::cout << std::endl;
    pausa("Presione enter para volver al menu.");
}
