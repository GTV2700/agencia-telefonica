#include<stdio.h>
#include <string.h>
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
printf("Desea crear un contacto (s/n): ");
    scanf(" %c", &opcion);
    if (opcion == 's' || opcion == 'S') {
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
        printf("\nContacto guardado\n\n");
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
    printf("\nIngrese el nombre exacto del contacto a editar: ");
    scanf("%29s", buscaNombre);

    for(int i = 0; i < total_contactos; i++) {
        if(strcmp(contactos[i].nombre, buscaNombre) == 0) {
            printf("--- Editando a %s ---\n", contactos[i].nombre);
            printf("Nuevo Nombre: "); scanf("%29s", contactos[i].nombre);
            printf("Nuevo Apellido: "); scanf("%29s", contactos[i].apellido);
            printf("Nuevo Telefono: "); scanf("%12s", contactos[i].telefono);
            printf("Nuevo Apodo: "); scanf("%19s", contactos[i].apodo);
            printf("Contacto actualizado con exito.\n");
            encontrado = 1;
            break;
        }
    }
    if(!encontrado) printf("Contacto no encontrado.\n");
}

//  Guardar y Cargar Archivo //
void guardarEnArchivo() {
    FILE *f = fopen("contactos.txt", "w");
    if (f == NULL) {
        printf("Error al abrir archivo.\n");
        return;
    }
    for (int i = 0; i < total_contactos; i++) {
        fprintf(f, "%s %s %s %s\n", contactos[i].nombre, contactos[i].apellido, contactos[i].telefono, contactos[i].apodo);
    }
    fclose(f);
    printf("Datos guardados en 'contactos.txt'.\n");
}

void cargarDesdeArchivo() {
    FILE *f = fopen("contactos.txt", "r");
    if (f == NULL) {
        printf("No existe archivo previo.\n");
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
    printf("Se cargaron %d contactos desde el archivo.\n", total_contactos);
}
int main(){
    printf("Agencia Telefonica De Busqueda Inteligente");
    int op;
    char letra;
do
{
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
    }else{
        printf("\nIngrese la letra inicial a buscar:");
        scanf(" %c",&letra);

        printf("\n===Resultado de la busqueda===\n");
        buscarRecursivo( 0,letra);
     }      
    break;
     //editar contacto y cargar contacto     
    case 3:
    if(total_contactos == 0) printf("Agenda vacia.\n");
        else editarContacto();
        break;
    //guardar y cargar desde archivo    
    case 4:
   printf("1. Guardar en archivo\n2. Cargar desde archivo\nOpcion: ");
         int subOp;
         scanf("%d", &subOp);
         if(subOp == 1) guardarEnArchivo();
         else if(subOp == 2) cargarDesdeArchivo();
        break;
        //salir
    case 5:
    printf("exit ");
    op = 0;
     break;
}
}while (op != 0);

printf("finish");
return 0;
}

