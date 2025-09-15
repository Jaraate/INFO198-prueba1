#include <iostream>
#include "user.h"
#include <unistd.h>

using namespace std; 

//para compilar make 
//escribir export USER_FILE=../data/USUARIOS.TXT
//Por ultimo para ejecutarlo ./app

int main(){
    int opcion;
    ListaUser lista;
    cargarUsuariosLista(lista);
    system("clear");
    do {
        cout << "PID del proceso principal: " << getpid() << endl;
        cout<<"--- Administrador de Usuarios ---"<< endl;
        cout<<"1. Ingresar usuario"<< endl;
        cout<<"2. Lista usuarios"<< endl;
        cout<<"3. Eliminar usuario"<< endl;
        cout<<"0. Salir"<< endl;
        cout<<"Seleccione una opción: ";
        cin>>opcion;
        

        switch(opcion){
            case 1:
                ingresarUsuario(lista);
                break;
            case 2:
                listarUsuarios(lista);
                break;
            case 3:
                eliminarUsuario(lista);
                break;
            case 0:
                cout<<"Fin del programa :P"<<endl;
                break;
            default:
                cout<<"Opcion inválida"<< endl;
        }
        cout<<endl;
    }while(opcion !=0);


    return 0;
}