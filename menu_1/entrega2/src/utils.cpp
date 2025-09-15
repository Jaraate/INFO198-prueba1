#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include "utils.h"


using namespace std;

void conteoTexto() {
    cout << "\n--- Conteo sobre texto ---\n";
    cout << "Ingrese un texto: ";
    string texto;
    getline(cin, texto);

    int vocales = 0, consonantes = 0, especiales = 0, palabras = 0;
    bool enPalabra = false;

    for (char c : texto) {
        if (isalpha(static_cast<unsigned char>(c))) {
            char lower = tolower(c);
            if (lower=='a'||lower=='e'||lower=='i'||lower=='o'||lower=='u')
                vocales++;
            else
                consonantes++;
            enPalabra = true;
        } else if (isspace(static_cast<unsigned char>(c))) {
            if (enPalabra) {
                palabras++;
                enPalabra = false;
            }
        } else {
            especiales++;
        }
    }
    if (enPalabra) palabras++; // contar última palabra

    cout << "Vocales: " << vocales << "\n";
    cout << "Consonantes: " << consonantes << "\n";
    cout << "Caracteres especiales: " << especiales << "\n";
    cout << "Palabras: " << palabras << "\n";
}

void calcularFuncion() {
    cout << "\n--- Calculo de f(x) = x*x + 2x + 8 ---\n";
    cout << "Ingrese un valor para x: ";
    double x;
    cin >> x;
    cin.ignore();
    double resultado = x*x + 2*x + 8;
    cout << "f(" << x << ") = " << resultado << "\n";
}

void iniciarJuego() {
    cout << "[Juego] Módulo en construccion\n";
}

void multiplicarMatrices() {
    system("clear");
    int N, opcion;
    string path1, path2;
    do{
    cout << "Ingrese el N de la matriz: ";
    cin >> N;
    cout<< "Ingrese los path de los archivos:\n";
    cout<< "Path 1: "; cin >> path1;
    cout<< "Path 2: "; cin >> path2;
    cout<< "Elija una opcion"<<endl;
    cout<< "Ejecutar (1)        volver(2)";
    cin>>opcion; 
    }while(opcion!=1);
    
}

bool isPalindrome(const string &text) {
    string clean;
    for (char c : text) {
        if (isalnum(static_cast<unsigned char>(c))) {
            clean.push_back(tolower(c));
        }
    }
    string reversed = clean;
    reverse(reversed.begin(), reversed.end());
    return clean == reversed;
}

void opcionPalindromo() {
    cout << "\n--- Verificar Palindromo ---\n";
    cout << "Ingrese un texto: ";
    string texto;
    getline(cin, texto);

    cout << "1) Validar\n2) Cancelar\n";
    int subop;
    cin >> subop;
    cin.ignore();

    if (subop == 1) {
        if (isPalindrome(texto))
            cout << "✅ Es un palindromo.\n";
        else
            cout << "❌ No es un palindromo.\n";
    } else {
        cout << "Operacion cancelada.\n";
    }
}

void adminUsuarios(const string& perfil) {
    if (perfil == "ADMIN") {
        system("cd ../entrega_1 && make && ./app");
    } else {
        cout << "Acceso denegado: solo usuarios admin pueden usar esta opcion." << endl;
    }
}

