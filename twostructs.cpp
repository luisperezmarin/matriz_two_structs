#include <iostream>
#include <conio.h>

using namespace std;


// Prototipos de las funciones y estructuras
struct nodo;
struct nodo2;

void insertar(int dato);
void imprimir();
void eliminarTodo();
void menu();

// Variables globales
nodo *inicio;

// Estructura de nodo
struct nodo
{
    int columna;
    nodo *siguiente;
    nodo2 *abajo;
};

// Estructura de nodo2
struct nodo2
{
    int dato;
    nodo2 *abajo;
};

void insertar(int columna, int dato)
{
    // Definicion de variables tipo nodo y nodo2
    nodo *col_aux = new nodo;
    nodo2 *valor = new nodo2;

    // Asignacion de valores a las variables para crear el nodo
    col_aux->columna = columna;
    col_aux->siguiente = NULL;
    col_aux->abajo = NULL;


    valor->dato = dato;
    valor->abajo = NULL;

    // Verificacion de que el nodo este vacio
    if (inicio == NULL)
    {
        col_aux->abajo = valor;
        inicio = col_aux;
    }
    else
    {
        nodo *aux = inicio;
        nodo2 *aux2;
        while (aux != NULL)
        {
            if (aux->columna == columna)
            {
                aux2 = aux->abajo;
                while (aux2->abajo != NULL)
                {
                    aux2 = aux2->abajo;
                }
                aux2->abajo = valor;
                return;
            }
            aux = aux->siguiente;
        }
        col_aux->abajo = valor;
        aux = inicio;
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = col_aux;
    }
}

void imprimir()
{
    nodo *aux = inicio;
    nodo2 *aux2;
    if (aux == NULL){
        cout << "No hay datos" << endl;
        return;
    }

    while (aux != NULL)
    {
        cout << "Columna: " << aux->columna << "-> ";
        aux2 = aux->abajo;
        while (aux2 != NULL)
        {
            cout << aux2->dato << ",";
            aux2 = aux2->abajo;
        }
        aux = aux->siguiente;
        cout << endl;
    }
}

void eliminarTodo(){
    nodo *aux = inicio;
    nodo2 *aux2;
    while (aux != NULL)
    {
        inicio = inicio->siguiente;
        aux2 = aux->abajo;
        while (aux2 != NULL)
        {
            aux->abajo = aux->abajo->abajo;
            delete(aux2);
            aux2 = aux->abajo;
        }
        delete (aux);
        aux = inicio;
    }
}

void menu(){
    int opcion;
    int columna;
    int dato;
    do{
        system("cls");
        cout << "1. Insertar" << endl;
        cout << "2. Imprimir" << endl;
        cout << "3. Eliminar Todo" << endl;
        cout << "4. Salir" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "Ingrese la columna: ";
            cin >> columna;
            cout << "Ingrese el dato: ";
            cin >> dato;
            insertar(columna, dato);
            cout << "Se inserto correctamente" << endl;
            getche();
            break;
        case 2:
            cout << "Imprimiendo Matriz..." << endl;
            imprimir();
            cout << "Imprimiendo Matriz... Terminado" << endl;
            getche();
            break;
        case 3:
            cout << "Eliminando Matriz..." << endl;
            eliminarTodo();
            cout << "Eliminando Matriz... Terminado" << endl;
            getche();
            break;
        case 4:
            break;
        default:
            cout << "Opcion no valida" << endl;
            getche();
            break;
        }
    } while (opcion != 4);
}

int main()
{
    menu();
    return 0;
}
