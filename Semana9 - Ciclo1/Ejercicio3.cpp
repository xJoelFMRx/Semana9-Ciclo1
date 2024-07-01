#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

void Mostrar_Menu()
{
    cout << "\tMENU\n";
    cout << "===========================\n";
    cout << "1. Sumar 2 Numeros Complejos.\n";
    cout << "2. Restar 2 Numeros Complejos.\n";
    cout << "3. Salir del Programa\n";
}

void Texto(float* pr1, float* pi1, float* pr2, float* pi2)
{
    cout << "Numero 1";
    cout << endl << "Parte Real: "; cin >> *pr1;
    cout << "Parte Imaginaria: "; cin >> *pi1;
    cout << "Numero 2";
    cout << endl << "Parte Real: "; cin >> *pr2;
    cout << "Parte Imaginaria: "; cin >> *pi2;
}

void Imprimir_NumComplejo(float* pr, float* pi)
{
    cout << "(" << *pr << "+";
    if (*pi != 1) cout << *pi;
    cout << "i)";
}

void Sumar_Complejos(float* pr1, float* pi1, float* pr2, float* pi2)
{
    float* pr_resultado;
    float* pi_resultado;
    pr_resultado = new float;
    pi_resultado = new float;
    Imprimir_NumComplejo(pr1, pi1);
    cout << " + ";
    Imprimir_NumComplejo(pr2, pi2);
    cout << " = ";
    *pr_resultado = *pr1 + *pr2;
    *pi_resultado = *pi1 + *pi2;
    Imprimir_NumComplejo(pr_resultado, pi_resultado);
    delete pr_resultado;
    delete pi_resultado;
    pr_resultado = nullptr;
    pi_resultado = nullptr;
}

void Restar_Complejos(float* pr1, float* pi1, float* pr2, float* pi2)
{
    float* pr_resultado;
    float* pi_resultado;
    pr_resultado = new float;
    pi_resultado = new float;
    Imprimir_NumComplejo(pr1, pi1);
    cout << " - ";
    Imprimir_NumComplejo(pr2, pi2);
    cout << " = ";
    *pr_resultado = *pr1 - *pr2;
    *pi_resultado = *pi1 - *pi2;
    Imprimir_NumComplejo(pr_resultado, pi_resultado);
    delete pr_resultado;
    delete pi_resultado;
    pr_resultado = nullptr;
    pi_resultado = nullptr;
}

int main()
{
    int* opc;
    float* pr1;
    float* pi1;
    float* pr2;
    float* pi2;

    opc = new int;
    pr1 = new float;
    pi1 = new float;
    pr2 = new float;
    pi2 = new float;

    *opc = 0;

    do
    {
        Mostrar_Menu();
        cout << "Ingrese una opcion: "; cin >> *opc;
        system("cls");
        switch (*opc)
        {
        case 1:
            system("cls");
            Texto(pr1, pi1, pr2, pi2);
            Sumar_Complejos(pr1, pi1, pr2, pi2);
            cout << endl << "Presione una tecla para continuar.....";
            system("pause>0");
            break;
        case 2:
            system("cls");
            Texto(pr1, pi1, pr2, pi2);
            Restar_Complejos(pr1, pi1, pr2, pi2);
            cout << endl << "Presione una tecla para continuar.....";
            system("pause>0");
            break;
        case 3:
            break;
        }
        system("cls");
    } while (*opc != 3);

    delete opc;
    delete pr1;
    delete pi1;
    delete pr2;
    delete pi2;

    opc = nullptr;
    pr1 = nullptr;
    pi1 = nullptr;
    pr2 = nullptr;
    pi2 = nullptr;

    return 0;
}