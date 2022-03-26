#include <iostream>

using namespace std;

struct nodo;
struct nodo2;

void insertar(int dato);
void imprimir();

nodo *inicio;

struct nodo
{
    int columna;
    nodo *siguiente;
    nodo2 *abajo;
};

struct nodo2
{
    int dato;
    nodo2 *abajo;
};

void insertar(int columna, int dato)
{
    // Definicion de variables tipo nodo y nodo2
    nodo *col = new nodo;
    nodo2 *num = new nodo2;

    // Asignacion de valores a las variables para crear el nodo
    col->columna = columna;
    col->siguiente = NULL;
    col->abajo = NULL;


    num->dato = dato;
    num->abajo = NULL;

    // Verificacion de que el nodo este vacio
    if (inicio == NULL)
    {
        cout << "Nodo vacio Insertando Columna " << columna << " y dato " << dato << endl;
        col->abajo = num;
        inicio = col;
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
                cout << "Ya existe una columna " << columna << " Insertando dato " << dato << endl;
                while (aux2->abajo != NULL)
                {
                    aux2 = aux2->abajo;
                }
                aux2->abajo = num;
                return;
            }
            aux = aux->siguiente;
        }
        cout << "Nueva columna " << columna << " Insertando dato " << dato << endl;
        col->abajo = num;
        aux = inicio;
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = col;
    }
}

void insertar2(int columna, int dato)
{
    // Definicion de variables tipo nodo y nodo2
    nodo *col = new nodo;
    nodo2 *num = new nodo2;

    // Asignacion de valores a las variables para crear el nodo
    col->columna = columna;
    col->siguiente = NULL;
    col->abajo = NULL;

    if (inicio == NULL){
        cout << "Nodo vacio Insertando Columna " << columna << " y dato " << dato << endl;
        num->dato = dato;
        num->abajo = NULL;
        col->abajo = num;
        inicio = col;
    } else {
        nodo *aux = inicio;
        nodo2 *aux2;
        while (aux != NULL)
        {
            if (aux->columna == columna)
            {
                aux2 = aux->abajo;
                cout << "Ya existe una columna " << columna << " Insertando dato " << dato << endl;
                while (aux2->abajo != NULL)
                {
                    aux2 = aux2->abajo;
                }
                aux2->abajo = num;
                return;
            }
            aux = aux->siguiente;
        }
    }
}

void imprimir()
{
    nodo *aux = inicio;
    nodo2 *aux2;
    while (aux != NULL)
    {
        cout << "Columna: " << aux->columna << endl;
        aux2 = aux->abajo;
        while (aux2 != NULL)
        {
            cout << "Dato: " << aux2->dato << endl;
            aux2 = aux2->abajo;
        }
        aux = aux->siguiente;
    }
}

void imprimirColumna(int columna)
{
    nodo *aux = inicio;
    nodo2 *aux2;
    while (aux != NULL)
    {
        cout << "Columna: " << aux->columna << endl;
        aux = aux->siguiente;
    }
}

int main()
{
    int dato, columna;
    /*    cout << "Ingrese la columna: ";
        cin >> columna;
        cout << "Ingrese el dato a insertar: ";
        cin >> dato;
        cout << "La columna es: " << columna << endl;
        cout << "El dato es: " << dato << endl;
    */
    insertar(1, 1);
    insertar(1, 2);
    insertar(1, 3);
    insertar(2, 100);
    insertar(2, 2);
    insertar(3, 1);

    cout << "Imprimiendo ..." << endl;
    imprimir();
    return 0;
}
