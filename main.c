
#include <stdio.h>
#include <stdlib.h>

int contador = 1;

struct Contenedor {
    int id;
    float tara;
    float pesoCarga;
    float pesoTotal;
    float precio;

    struct Contenedor *siguiente;
    struct Contenedor *anterior;
};

// Funcion para insertar contenedores
struct Contenedor* insertarContenedor(struct Contenedor *lista) {

    struct Contenedor *nuevo;

    nuevo = (struct Contenedor*) malloc(sizeof(struct Contenedor));

    if (nuevo == NULL) {
        printf("Error al reservar memoria\n");
        return lista;
    }

    nuevo->id = contador;
    contador++;

    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;

    printf("\nIngrese la tara: ");
    scanf("%f", &nuevo->tara);

    printf("Ingrese el peso de carga: ");
    scanf("%f", &nuevo->pesoCarga);

    nuevo->pesoTotal = nuevo->tara + nuevo->pesoCarga;

    printf("Ingrese el precio: ");
    scanf("%f", &nuevo->precio);

    if (lista == NULL) {
        return nuevo;
    }

    struct Contenedor *actual = lista;

    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    actual->siguiente = nuevo;
    nuevo->anterior = actual;

    return lista;
}

// Funcion para mostrar contenedores
void mostrarContenedores(struct Contenedor *lista) {

    struct Contenedor *actual = lista;

    if (actual == NULL) {
        printf("\nNo hay contenedores registrados.\n");
        return;
    }

    while (actual != NULL) {

        printf("\n== DATOS DEL CONTENEDOR ==\n");
        printf("ID: %d\n", actual->id);
        printf("Tara: %.2f\n", actual->tara);
        printf("Peso de carga: %.2f\n", actual->pesoCarga);
        printf("Peso total: %.2f\n", actual->pesoTotal);
        printf("Precio: %.2f\n", actual->precio);

        actual = actual->siguiente;
    }
}

// Funcion para buscar contenedores
void buscarContenedor(struct Contenedor *lista) {

    int idBuscar;
    struct Contenedor *actual = lista;

    printf("\nIngrese el ID del contenedor: ");
    scanf("%d", &idBuscar);

    while (actual != NULL) {

        if (actual->id == idBuscar) {

            printf("\n== CONTENEDOR ENCONTRADO ==\n");
            printf("ID: %d\n", actual->id);
            printf("Tara: %.2f\n", actual->tara);
            printf("Peso de carga: %.2f\n", actual->pesoCarga);
            printf("Peso total: %.2f\n", actual->pesoTotal);
            printf("Precio: %.2f\n", actual->precio);

            return;
        }

        actual = actual->siguiente;
    }

    printf("\nNo se encontro el contenedor.\n");
}

// Funcion para modificar contenedores
void modificarContenedor(struct Contenedor *lista) {

    int idModificar;
    struct Contenedor *actual = lista;

    printf("\nIngrese el ID del contenedor que desea modificar: ");
    scanf("%d", &idModificar);

    while (actual != NULL) {

        if (actual->id == idModificar) {

            printf("\nIngrese la nueva tara: ");
            scanf("%f", &actual->tara);

            printf("Ingrese el nuevo peso de carga: ");
            scanf("%f", &actual->pesoCarga);

            actual->pesoTotal = actual->tara + actual->pesoCarga;

            printf("Ingrese el nuevo precio: ");
            scanf("%f", &actual->precio);

            printf("\nContenedor modificado correctamente.\n");

            return;
        }

        actual = actual->siguiente;
    }

    printf("\nNo se encontro el contenedor.\n");
}


// Funcion para eliminar contenedores
struct Contenedor* eliminarContenedor(struct Contenedor *lista) {

    int idEliminar;
    struct Contenedor *actual = lista;

    printf("\nIngrese el ID del contenedor que desea eliminar: ");
    scanf("%d", &idEliminar);

    while (actual != NULL) {

        if (actual->id == idEliminar) {

            if (actual->anterior != NULL) {
                actual->anterior->siguiente = actual->siguiente;
            } else {
                lista = actual->siguiente;
            }

            if (actual->siguiente != NULL) {
                actual->siguiente->anterior = actual->anterior;
            }

            free(actual);

            printf("\nContenedor eliminado correctamente.\n");

            return lista;
        }

        actual = actual->siguiente;
    }

    printf("\nNo se encontro el contenedor.\n");

    return lista;
}
// Funcion para liberar memoria
void liberarMemoria(struct Contenedor *lista) {

    struct Contenedor *actual;

    while (lista != NULL) {

        actual = lista;
        lista = lista->siguiente;
        free(actual);
    }

    printf("\nMemoria liberada correctamente.\n");
}

// Programa principal
int main() {

    struct Contenedor *p = NULL;
    int opcion;

    do {

        printf("\n== SISTEMA DE GESTION DE CONTENEDORES ==\n");
        printf("1. Insertar contenedor\n");
        printf("2. Mostrar contenedores\n");
        printf("3. Buscar contenedor\n");
        printf("4. Modificar contenedor\n");
        printf("5. Eliminar contenedor\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");

        scanf("%d", &opcion);

        switch (opcion) {

            case 1:
                p = insertarContenedor(p);
                break;

            case 2:
                mostrarContenedores(p);
                break;

            case 3:
                buscarContenedor(p);
                break;

            case 4:
                modificarContenedor(p);
                break;

            case 5:
                p = eliminarContenedor(p);
                break;

            case 6:
                printf("\nSaliendo del sistema...\n");
                break;

            default:
                printf("\nOpcion no valida.\n");
        }

    } while (opcion != 6);

    liberarMemoria(p);

    return 0;
}
