#include <iostream> //el # es una directiva del preprocesador, agarra el iostream y lo incluye en el codigo 
//fuente sale del preprocesador y va al compilador

// using namespace std;

// namespace // es un conjunto de simbolos, se inventaron para que no haya choque de nombres

int main()//el main tiene una funcion que retorna el cero que es del tipo int
{
      std::cout << "hello world\n";//cout es un objeto que representa la salida standar
      return 0;//le retorna cero para decirle al sistema que todo a salido bien
}