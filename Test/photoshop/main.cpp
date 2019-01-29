#include <iostream>
#include "photoshop.h"

using namespace std;

void erase_shape()
{
}

void resize_shape()
{
}

void add_shape()
{
    cout << "1. Add line\n";
    cout << "2. Add circle\n";
}

void process_option(int op, )

void draw_menu()
{
    int op;
    cout << "1. Add shape\n";
    cout << "2. Resize shape\n";
    cout << "3. Erase shape\n";

    cin >> op;

    switch (op)
    {
        case 1:
            add_shape();
            break;
        case 2:
            resize_shape();
            break;
        case 3:
            erase_shape();
            break;
    }
}

int main()
{
    photoshop<text_renderer> ps;

    int op = -1;
    while (op != 5)
    {
        // ps.show_image();
        draw_menu();
        cin >> op;
        process_option(op, ps);
    }
}