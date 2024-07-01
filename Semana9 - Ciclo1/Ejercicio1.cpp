#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

void Generar_Numeros(int* a, int* b, int* c, int* d)
{
    do
    {
        *a = rand() % 40 + 1;
        *b = rand() % 40 + 1;
        *c = rand() % 40 + 1;
        *d = rand() % 40 + 1;
    } while (*a == *b || *a == *c || *a == *d || *b == *c || *b == *d || *c == *d);
}

void Imprimir_Numeros(int* a, int* b, int* c, int* d)
{
    cout << "a: " << *a << endl;
    cout << "b: " << *b << endl;
    cout << "c: " << *c << endl;
    cout << "d: " << *d << endl;
}

int Mayor_Numero(int* a, int* b, int* c, int* d)
{
    return max(*a, max(*b, max(*c, *d)));
}

int Menor_Numero(int* a, int* b, int* c, int* d)
{
    return min(*a, min(*b, min(*c, *d)));
}

void Ordenar(int* a, int* b, int* c, int* d)
{
    //Comparando con a
    if (*b < *a) swap(*a, *b);
    if (*c < *a) swap(*a, *c);
    if (*d < *a) swap(*a, *d);
    //Comparando con b
    if (*c < *b) swap(*b, *c);
    if (*d < *b) swap(*b, *d);
    //Comparando con c
    if (*d < *c) swap(*c, *d);
}

int Hallar_Anterior_Mayor(int* a, int* b, int* c, int* d)
{
    Ordenar(a, b, c, d);
    return *c;
}

void Dibujar_Escalon(int* num, int* alt)
{
    if (*num > 9)
    {
        Console::SetCursorPosition(78 - *num, *alt);
    }
    else
    {
        Console::SetCursorPosition(79 - *num, *alt);
    }
    cout << *num;
    for (int i = 0; i < *num; i++)
    {
        cout << "*";
    }
    *alt = *alt + 1;
}

void Graficar(int* a, int* b, int* c, int* d)
{
    int* ptralt;
    ptralt = new int;
    *ptralt = 2;
    Dibujar_Escalon(a, ptralt);
    Dibujar_Escalon(b, ptralt);
    Dibujar_Escalon(c, ptralt);
    Dibujar_Escalon(d, ptralt);
    delete ptralt;
    ptralt = nullptr;
}

int main()
{
    srand(time(nullptr));
    int* a;
    int* b;
    int* c;
    int* d;

    a = new int;
    b = new int;
    c = new int;
    d = new int;

    Generar_Numeros(a, b, c, d);
    Imprimir_Numeros(a, b, c, d);
    cout << "El mayor de los numeros es: " << Mayor_Numero(a, b, c, d) << endl;
    cout << "El menor de los numeros es: " << Menor_Numero(a, b, c, d) << endl;
    cout << "El numero anterior al mayor es: " << Hallar_Anterior_Mayor(a, b, c, d) << endl;
    Ordenar(a, b, c, d);
    cout << "Numeros en orden: " << endl;
    Imprimir_Numeros(a, b, c, d);
    Graficar(a, b, c, d);

    delete a;
    delete b;
    delete c;
    delete d;

    a = nullptr;
    b = nullptr;
    c = nullptr;
    d = nullptr;

    system("pause>0");
    return 0;
}