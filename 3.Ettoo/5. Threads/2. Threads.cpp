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

void g(int id, mutex& m)
{
    // mutex m;//solo un hilo puede entrar a este pedazo de codigo a la vez pero no sirve
    // m.lock();
    for(int i = 0; i < 1000; i++)
    {
        lock_guard<mutex> gr{m};//siempre usar un lock_guard, se asegura de llama a unlock
        cout << id <<";" << i << "\n";
        this_thread::yield();
        // if(i==8) return;//aca causamos un deadlock y nunca de ejecuta unlock
    }
    // m.unlock();
}

int main()
{
    mutex m;//soluciona las colisiones de carrera
    vector<thread> r;
    for(int i=0; i <1000; i++)
    {
        r.emplace_back(g, i, ref(m));//SSSJ
    }

    for(auto& x : r)
    {
        x.join();
    }
}