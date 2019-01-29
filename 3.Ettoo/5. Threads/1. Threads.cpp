#include <iostream>
#include <thread>
#include <chrono>//sirve para especificar datos de tiempo
#include <vector>
#include <mutex>//es un objeto que  marca un hilo cuando esta siendo usada, entonces otro hilo no puede entrar a ese codigo
using namespace std;
//TREADS
//*son unidades de ejecucion independiente y concurrente dentro de un proceso
//*COMPARTEN ADDRES SPACE (rapido intercambio de datos)
//*deadlocks/colisiones de carrera
//*CONTEXT-SWITCH-LIGERO
//PROCESO
//*es una unidad de ejecucion independiente y concurrente dentro de un sistema operativo
//*NO COMPARTEN ADDRES SPACE (intercambio de datos lento) IPC
//*no hay condiciones de carrera
//*CONTEXT SWITCH PESADO

void f(const string& name)
{
    for(int i = 0; i < 1000; i++)
    {
        this_thread::sleep_for(10ms);//mi hilo llama a su metodo sleep_for() hace un CONTEXT SWITCH

        // this_thread::yield();//le sugiere al procesador hacer un salto al otro hilo
        // cout << this_thread::get_id() << ":" << i <<"\n";
        cout << name << ":" << i <<"\n";
    }
}

int main()
{
    thread p{f, "p"};//al instanciar ya se debe pasar una funcion... compilar con -lpthread

    string* s = new string{"q"};
    thread q{f, *s};//esta llamando a la funcion bind() internamente, y hace una copia del string que le esta llegando
    delete s;//debe ser una copia xq en este punto se destruye el string
    p.join();//hago dormir al hilo main, esperare hasta que el hilo p termine
    q.join();
}