# INFO198-Sistemas-Operativos---Proyecto
===============================================================

>>Propósito de la aplicación

El objetivo de este proyecto es implentar un menú interactivo al que se accede con usuario y contraseña.
Existen dos tipos de perfiles:
 - Administrador: además de las funciones generales, puede acceder al menú de usuarios, que le permite agregar usuarios con nombre, usuario, contraseña e ID, eliminar usuarios por ID, listar los usuarios y volver al menú principal.
 - General: tiene acceso únicamente a las opciones generales del menú.

las funciones disponibles son:
 - Salir del menú
 - Multiplicar matrices
 - Juego (en construcción)
 - Verificar si una palabra es un palíndromo
 - Calcular una función
 - Conteo sobre texto
 - Índice invertido: éste solicita un nombre de archivo para registrar palabras, indicando en qué libro se encontró y cuántas veces aparece en la carpeta de los libros.

El menú es interactivo e intuitivo, adaptándose automáticamente según el tipo de perfil con el que se accede.

===============================================================

>>Ejecución

1- Primero hay que ingresar a la carpeta del proyecto
 cd entrega2

2- Configurar las variables de entorno, exportándolas en la terminal
 export USER_FILE=../data/USUARIOS.TXT
 export ADMIN_SYS=../entrega_1
 export MUTLI_M=../funcion_Matriz
 export CREATE_INDEX=../índice

3- Realizar make

4- Ejecutar el programa 
 ./bin/app2 -u <username> -p <password>
 reemplazando <username> y <password> por las variables de acceso.
 Si ingresas con un perfil admin, tendrás acceso al menú de usuarios además de las funciones generales.
 Si ingresas con un perfil general, verás únicamente el menú principal con sus opciones.

===============================================================

>>Extras

Los paths para la matriz son:
 path1: ../matriz/A3x3.txt
 path2: ../matriz/B3x3.txt

y el path para los libros es:
 ../Libros

===============================================================

Integrantes:
 - Samantha Espinoza
 - Felipe Reyes

