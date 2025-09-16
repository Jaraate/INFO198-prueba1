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
}