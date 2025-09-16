#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include "utils.h"
#include <filesystem>
#include <cstdlib>

namespace fs = std::filesystem; 
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
    int opcion;
    string path1, path2;

    cout << "Ingrese los path de los archivos:" << endl;
    cout << "Path 1: "; cin >> path1;
    cout << "Path 2: "; cin >> path2;

    cout << "Elija una opción..."<<endl;
    cout << "Ejecutar (1)        volver(2)" << endl;
    cin >> opcion; 

    if(opcion == 2){
        cout << "Volviendo al menú principal..." << endl;
        return;
    }

    if(!fs::exists(path1) || !fs::exists(path2)){
        cout << "Error, uno de los archivos no existe u_u";
        return;
    }
    const char* path = getenv("MUTLI_M");
    if (!path){
            cout<<"ERROR: La variable de entorno ADMIN_SYS no está definida." << endl;
            return;
        }
    string comando = "cd " + string(path) + " && make && ./mult_matrices \"" + path1 + "\" \"" + path2 + "\" \"#\"";
    int result = system(comando.c_str());
    if (result == -1) {
            cout << "ERROR al ejecutar el multiplicador de matrices" << endl;
        }
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
        const char* path = getenv("ADMIN_SYS");
        if (!path){
            cout<<"ERROR: La variable de entorno ADMIN_SYS no está definida." << endl;
            return;
        }
        string comando = "cd " + string(path) + " && make && ./app";
        int result = system(comando.c_str());
        if (result == -1) {
            cout << "ERROR al ejecutar administrador de usuarios." << endl;
        }
    } else {
        cout << "Acceso denegado: solo usuarios admin pueden usar esta opcion." << endl;
    }
}



void invertido_indice(){
    system("clear");
    string archivo, path1;

    cout<<"Ingrese el nombre del archivo a crear: ";
    cin>> archivo;
    if (archivo.empty()){
        cout<<"Error, el nombre no debe estar vacio";
        return;
    }
    if (archivo.size() < 4 || archivo.substr(archivo.size() - 4) != ".idx"){
        cout<<"Error, el archivo debe tener la extension .idx"<<endl;
        return;
    }
    cout<<"Ingrese la direccion de la carpeta de los libros: ";
    cin>> path1;
    if(!fs::exists(path1) || !fs::is_directory(path1)){
        cout << "Error, la carpeta no existe u_u o no es un directorio";
        return;
    }
    

    //Llamar indice invertido
    const char* path = getenv("CREATE_INDEX");
    if(path==nullptr){
        cout << "Error, variable de entorno CREATE_INDEX no definida" << endl;
        return;
    }
    string comando = "cd " + string(path) + " && make && ./bin/creaIndice " + archivo + " " + path1;
    cout<<comando;
    int status = system(comando.c_str());

    if (status == -1) {
            cout << "ERROR al ejecutar el indice invertido" << endl;
        }


}
