#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

void Mostrar_Menu()
{
    cout << "\tMENU PRINCIPAL\n";
    cout << "1) Determinar el factorial de un numero\n";
    cout << "2) Calcular el valor de ea\n";
    cout << "3) Imprime rombo\n";
    cout << "4) Fin\n";
}

int Validar_NumFactorial(int* numfactorial)
{
    do
    {
        cout << "Ingrese un numero: "; cin >> *numfactorial;
    } while (*numfactorial <= 0);
    return *numfactorial;
}

long long Factorial(int* numfactorial)
{
    long long* res;
    res = new long long;
    *res = 1;
    for (int i = 1; i <= *numfactorial; i++)
    {
        *res *= i;
    }
    return *res;
    delete res;
}

double Validar_a(double* a)
{
    do
    {
        cout << "Ingrese el valor de a: "; cin >> *a;
    } while (*a == 0);
    return *a;
}

int Validar_k(int* k)
{
    do
    {
        cout << "Ingrese el valor de k: "; cin >> *k;
    } while (*k > 20);
    return *k;
}

double Calcular_ea(int* k, double* a)
{
    double* ea;
    double* termino;
    ea = new double;
    termino = new double;
    *ea = 0;
    for (int i = 0; i <= *k; i++)
    {
        *termino = pow(*a, i) / Factorial(&i);
        *ea += *termino;
    }
    return *ea;
    delete ea;
    delete termino;
}

int Validar_NumRombo(int* numrombo)
{
    do
    {
        cout << "Ingrese un numero: "; cin >> *numrombo;
    } while (*numrombo >= 11);
    return *numrombo;
}

void Dibujar_Espacios(int espacios)
{
    for (int i = 0; i < espacios; i++)
    {
        cout << " ";
    }
}

void Dibujar_Rombo(int* numrombo)
{
    for (int i = 1; i <= *numrombo; i++)
    {
        Dibujar_Espacios(*numrombo - i);
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << j;
        }
        cout << endl;
    }
    for (int i = *numrombo - 1; i >= 1; i--)
    {
        Dibujar_Espacios(*numrombo - i);
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}

int main()
{
    int* opc;
    int* numfactorial;
    double* a;
    int* k;
    int* numrombo;

    opc = new int;
    numfactorial = new int;
    a = new double;
    k = new int;
    numrombo = new int;

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
            Validar_NumFactorial(numfactorial);
            cout << endl << "El factorial de " << *numfactorial << " es: " << Factorial(numfactorial) << endl;
            system("pause>0");
            break;
        case 2:
            system("cls");
            Validar_a(a);
            Validar_k(k);
            cout << endl << "El valor de ea es: " << Calcular_ea(k, a);
            system("pause>0");
            break;
        case 3:
            system("cls");
            Validar_NumRombo(numrombo);
            Dibujar_Rombo(numrombo);
            system("pause>0");
            break;
        case 4:
            break;
        }
        system("cls");
    } while (*opc != 4);

    delete opc;
    delete numfactorial;
    delete a;
    delete k;
    delete numrombo;

    opc = nullptr;
    numfactorial = nullptr;
    a = nullptr;
    k = nullptr;
    numrombo = nullptr;

    return 0;
}