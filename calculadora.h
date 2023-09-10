class Calculadora{

    private:
        float x, y;

    public:
        Calculadora(float x1, float y1);
        Calculadora(float x1);

        float sumar();
        float restar();
        float multiplicar();
        float dividir();
        float ElevarAlCuadrado();
        float ElevarAUnNumero();
        float RaizCuadrada();
        float Factorial();
        float Logaritmo();

};