#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <filesystem>
#include <sstream>
#include <cctype>

namespace fs = std::filesystem;
using namespace std;

string limpiar(const string& word){
    string result;
    for(char c : word){
        if(isalnum(static_cast<unsigned char>(c))){
            result += tolower(c);
        }
    }
    return result;
}


int main(int argc, char* argv[]){
    if(argc != 3){
        cout << "Uso: " << argv[0] << " <archivo.idx> <path_carpeta_libros>" << endl;
        return 1;
    }

    string idxFile = argv[1];
    string pathLibros = argv[2];

    //validación de extensión .idx
    if(idxFile.size()<4 || idxFile.substr(idxFile.size()-4) != ".idx"){
        cerr << "Error, el archivo debe tener extensión .idx !!" << endl;
        return 1;
    }

    //validación que la carpeta existe
    if(!fs::exists(pathLibros) || !fs::is_directory(pathLibros)){
        cerr << "Error, la carpeta no existe u_u" << endl;
        return 1;
    }

    //mapa
    map<string, map<string,int>> indice;

    for(auto& entry : fs::directory_iterator(pathLibros)){
        if(entry.is_regular_file()){
            string n_archivo = entry.path().filename().string();
            ifstream fin(entry.path());
            if(!fin) continue;

            string palabra;
            while(fin >> palabra){
                string pal = limpiar(palabra);
                if(!pal.empty()){
                    indice[pal][n_archivo]++;
                }
            }
        }
    }

    //indice invertido en idx
    ofstream fout(idxFile);
    if(!fout){
        cerr << "Error al crear el archivo " << idxFile << " :(" << endl;
        return 1;
    }

    for(auto& [palabra, docMap] : indice){
        fout << palabra;
        for(auto& [doc, count] : docMap){
            fout << ";(" << doc << "," << count << ")";
        }
        fout << endl;
    }

    cout << "el índice invertido ha sido generado en " << idxFile << endl;
    return 0;
}