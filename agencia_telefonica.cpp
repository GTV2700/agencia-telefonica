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
}info; //organiza las variable para solo tener que llamar la funion


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



int main(){
    printf("Agencia Telefonica De Busqueda Inteligente");
    int op;
do
{
    printf("seleciones una opcion.\n");
    printf("1.reistro de contacto:\n");
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
    printf("h2");
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