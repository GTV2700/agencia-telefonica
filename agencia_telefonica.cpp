#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
//integrantes:
//Gustavo Herrera 32.788.274
//Emil Gomez 31.695.619
//Daniel Daza 31.129.232
//Seccion D3
//objetivos:
//1.Registro de contactos con telefono y nombre
//2.buscar contacto por inicial del nombre
//3.editar y cargar contacto
//4.guardar y cargar desde archivo
//5.usar recursion para buscar coincidencias

//hola emil prueba de ramas v:
typedef struct Info
{
	char nombre[30];
	char apellido[30];
	char telefono[13];
	char apodo[20];
}info; //organiza las variable para solo tener que llamar la funcion


Info contactos[100];  //Array, registro de contactos
int total_contactos = 0;

//Opcion 1 crear un contacto
void addinfo(){
    char opcion;
system("cls");
printf("Desea crear un contacto (s/n): ");
    scanf(" %c", &opcion);
    if (opcion == 's' || opcion == 'S') {
        system("cls");
        printf("=== Crear Contacto ===\n");
        printf("Nombre: ");
        scanf("%29s",& contactos[total_contactos].nombre); 
        printf("Apellido: ");
        scanf("%29s",& contactos[total_contactos].apellido);
        printf("Telefono: ");
        scanf("%12s",& contactos[total_contactos].telefono);
        printf("Apodo: ");
        scanf("%19s", contactos[total_contactos].apodo);
        
        total_contactos++;
        system("cls");
        printf("\nContacto guardado\n\n");
        sleep(1);
        system("cls");
    }
}
// === FUNCIÓN DE BÚSQUEDA RECURSIVA  ===
void buscarRecursivo(int indice, char inicial) {
    if (indice >= total_contactos) return; // Caso base

    // Compara la inicial del nombre guardado con la letra buscada
    if (contactos[indice].nombre[0] == inicial) {

        printf("-> %s %s | Tel: %s\n", 
                contactos[indice].nombre, 
                contactos[indice].apellido, 
                contactos[indice].telefono);
    }
    buscarRecursivo(indice + 1, inicial); // Llamada recursiva
}

//Editar contacto //
void editarContacto() {
    char buscaNombre[30];
    int encontrado = 0;
    system("cls");
    printf("\nIngrese el nombre exacto del contacto a editar: ");
    scanf("%29s", buscaNombre);
    system("cls");
    for(int i = 0; i < total_contactos; i++) {
        if(strcmp(contactos[i].nombre, buscaNombre) == 0) {
            printf("--- Editando a %s ---\n", contactos[i].nombre);
            printf("Nuevo Nombre: "); scanf("%29s", contactos[i].nombre);
            printf("Nuevo Apellido: "); scanf("%29s", contactos[i].apellido);
            printf("Nuevo Telefono: "); scanf("%12s", contactos[i].telefono);
            printf("Nuevo Apodo: "); scanf("%19s", contactos[i].apodo);
            system("cls");
            printf("Contacto actualizado con exito.\n");
            sleep(1);
            system("cls");
            encontrado = 1;
            break;
        }
    }
    if(!encontrado) printf("Contacto no encontrado.\n");
    system("pause");
}

//  Guardar y Cargar Archivo //
void guardarEnArchivo() {
    FILE *f = fopen("contactos.txt", "w");
    if (f == NULL) {
        system("cls");
        printf("Error al abrir archivo.\n");
        sleep(1);
        return;
    }
    for (int i = 0; i < total_contactos; i++) {
        fprintf(f, "%s %s %s %s\n", contactos[i].nombre, contactos[i].apellido, contactos[i].telefono, contactos[i].apodo);
    }
    fclose(f);
    system("cls");
    printf("Datos guardados en 'contactos.txt'.\n");
    sleep(2);
    system("cls");
}

void cargarDesdeArchivo() {
    FILE *f = fopen("contactos.txt", "r");
    if (f == NULL) {
        system("cls");
        printf("No existe archivo previo.\n");
        sleep(1);
        system("cls");
        return;
    }
    total_contactos = 0;
    while (fscanf(f, "%s %s %s %s", contactos[total_contactos].nombre, 
                  contactos[total_contactos].apellido, 
                  contactos[total_contactos].telefono, 
                  contactos[total_contactos].apodo) != EOF) {
        total_contactos++;
        
    }
    fclose(f);
    system("cls");
    printf("Se cargaron %d contactos desde el archivo.\n", total_contactos);
    system("pause");
    system("cls");
}
int main(){
    
    int op;
    char letra;
do
{
    system("cls");
    printf("Agencia Telefonica De Busqueda Inteligente\n");
    printf("\nselecione una opcion.\n");
    printf("1.registro de contacto:\n");
    printf("2.busqueda de contacto:\n");
    printf("3.editar y cargar contacto:\n");
    printf("4.guardar y cargar desde archivo:\n");
    printf("5.salir:\n");
    scanf("%d",&op);
switch (op)
{
 //Registro de contactos con telefono y nombre
    case 1:
    addinfo();
        break;
    //Buscar contacto por inicial    
    case 2:
     if(total_contactos==0){ 
    printf("\nNo hay contactos registrados todavia\n");
    sleep (2);
    }else{
        system("cls");
        printf("\nIngrese la letra inicial a buscar:");
        scanf(" %c",&letra);
        system("cls");
        printf("\n===Resultado de la busqueda===\n");
        buscarRecursivo( 0,letra);
        system("pause");
        system("cls");
     }      
    break;
     //editar contacto y cargar contacto     
    case 3:
    if(total_contactos == 0){
    system("cls");
    printf("Agenda vacia.\n"); system("pause");}
        else editarContacto();
        break;
    //guardar y cargar desde archivo    
    case 4:
    system("cls");
   printf("1. Guardar en archivo\n2. Cargar desde archivo\nOpcion: ");
         int subOp;
         scanf("%d", &subOp);
         if(subOp == 1) guardarEnArchivo();
         else if(subOp == 2) cargarDesdeArchivo();
        break;
        //salir
    case 5:
    printf("");
    system("cls");
    op = 0;
     break;
}
}while (op != 0);

printf("finish");
sleep(2);
system("cls");
return 0;
}

