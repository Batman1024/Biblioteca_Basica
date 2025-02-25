#include <iostream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

struct Nodo {
    string dato;
    Nodo* siguiente;
};

// Declaraciones de funciones
void menu_principal();
void pausa();
void agg(Nodo*& lista);
void Lista(Nodo*&, string);
void ver(Nodo*);
void buscar(Nodo*);
void eliminar(Nodo*& lista, string);

Nodo* lista = NULL;

int main() {
    menu_principal();
    pausa();
    return 0;
}

void menu_principal() {
    bool repite = true;
    int opcion;
    do {
        system("cls");
        cout << "\n\t\t\tMENU PRINCIPAL\n";
        cout << "\t1. AGREGAR LIBRO\n";
        cout << "\t2. VER LISTA DE LIBROS\n";
        cout << "\t3. BUSCAR LIBRO\n";
        cout << "\t4. ELIMINAR LIBRO\n";
        cout << "\t0. SALIR\n";

        cout << "\n\tElija una Opcion: ";
        cin >> opcion;
        cin.ignore(); // Evita problemas con getline()

        switch (opcion) {
        case 1:
            agg(lista);
            break;
        case 2:
            ver(lista);
            break;
        case 3:
            buscar(lista);
            break;
        case 4: {
            string libro;
            cout << "Ingrese el nombre del libro a eliminar: ";
            getline(cin, libro);
            eliminar(lista, libro);
            break;
        }
        case 0:
            repite = false;
            break;
        default:
            cout << "Opcion no valida.\n";
            system("pause");
            break;
        }
    } while (repite);
}

void agg(Nodo*& lista) {
    string dato;
    cout << "Ingrese el nombre del libro: ";
    getline(cin, dato);
    Lista(lista, dato);
}

void Lista(Nodo*& lista, string dato) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = dato;
    nuevo_nodo->siguiente = lista;
    lista = nuevo_nodo;
    cout << "\n\tEl libro \"" << dato << "\" se agrego correctamente.\n";
    pausa();
}

void pausa() {
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
}

void ver(Nodo* lista) {
    if (lista == NULL) {
        cout << "La lista esta vacia.\n";
        return;
    }
    Nodo* actual = lista;
    while (actual != NULL) {
        cout << "- " << actual->dato << "\n";
        actual = actual->siguiente;
    }
    system("pause");
}

void buscar(Nodo* lista) {
    if (lista == NULL) {
        cout << "La lista esta vacia.\n";
        return;
    }
    string dato;
    cout << "Ingrese el nombre del libro a buscar: ";
    getline(cin, dato);

    Nodo* actual = lista;
    bool encontrado = false;
    while (actual != NULL) {
        if (actual->dato == dato) {
            cout << "El libro \"" << dato << "\" fue encontrado en la lista.\n";
            encontrado = true;
            break;
        }
        actual = actual->siguiente;
    }
    if (!encontrado) {
        cout << "El libro \"" << dato << "\" no esta en la lista.\n";
    }
    system("pause");
}

void eliminar(Nodo*& lista, string dato) {
    if (lista == NULL) {
        cout << "La lista esta vacia.\n";
        return;
    }
    Nodo* actual = lista;
    Nodo* anterior = NULL;
    while (actual != NULL && actual->dato != dato) {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual == NULL) {
        cout << "El libro \"" << dato << "\" no se encuentra en la lista.\n";
    }
    else {
        if (anterior == NULL) {
            lista = actual->siguiente;
        }
        else {
            anterior->siguiente = actual->siguiente;
        }
        delete actual;
        cout << "El libro \"" << dato << "\" ha sido eliminado.\n";
    }
    system("pause");
}
