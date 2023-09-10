#include "calculadora.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>


Calculadora::Calculadora(float x1, float y1){
    this->x = x1;
    this->y = y1;
}

Calculadora::Calculadora(float x1){
    this->x = x1;
}

float Calculadora::sumar(){
    
    float result = x + y;
    std::cout << "Suma = " << result << std::endl;
    return result;
}

float Calculadora::restar(){
    float result = x - y;
    std::cout << "Resta = " << result << std::endl;
    return result;
}
float Calculadora::multiplicar(){
    float result = x * y;
    std::cout << "Multiplicacion = " << result << std::endl;
    return result;
}
float Calculadora::dividir(){
    float result;
    if (y != 0){
        x / y;
        result = x / y;
        std::cout << "Division = " << result << std::endl;
    }else{
        std::cout << "No se puede dividir por 0" << std::endl;
    }
    return result;
}

float Calculadora::ElevarAlCuadrado(){
    float result;
    result = pow(x, 2);
    std::cout << "\nEl numero " << x << " elevado al cuadrado es " << result << std::endl;
    return result;
}

float Calculadora::ElevarAUnNumero(){
    float result;
    result = pow(x,y);
    std::cout << "\nEl numero " << x << " elevado a " << y << " es " << result << std::endl;
    return result;
}

float Calculadora::RaizCuadrada(){
    float result;
    result = sqrt(x);
    std::cout << "\nLa raiz cuadrada de " << x << " es " << result << std::endl;  
    return result;
}

float Calculadora::Factorial(){
    float result = 1;

    for (int i = 1; i <= x; i++){
        result *= i;
    }
    std::cout << "\nEl factorial de " << x << " es " << result << std::endl;
    return result;
}

float Calculadora::Logaritmo(){
    float result;
    if(x > 0){
        result = log(x);
        std::cout << "El logaritmo de " << x << "es " << result << std::endl;
    }else{
        std::cout << "0 no es valido." << std::endl;
    }
    return result;
}