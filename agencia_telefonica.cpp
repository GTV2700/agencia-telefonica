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
    printf("h3");
        break;
    //guardar y cargar desde archivo    
    case 4:
    printf("h4");
        break;
        //salir
    case 5:
    printf("exit");
    op = 0;
     break;
}
}while (op != 0);

printf("finish");
return 0;
}