#include<stdio.h>
//integrantes:
//Gustavo Herrera 32.788.274
//Emil Gomez 31.695.619
//Daniel Daza 31.129.232
//objetivos:
//1.Registro de contactos con telefono y nombre
//2.buscar contacto por inicial del nombre
//3.editar y cargar contacto
//4.guardar y cargar desde archivo
//5.usar recursion para buscar coincidencias
int main(){
    printf("Agencia Telefonica De Busqueda Inteligente");
    int op = 2;
    int selec;
while (op != 0)
{
    printf("seleciones una opcion:");
    printf("1.reistro de contacto");
    printf("2.busqueda de contacto");
    printf("3.editar y cargar contacto");
    printf("4.guardar y cargar desde archivo");
    printf("5.salir");
    scanf("%d",&selec);
switch (selec)
{
 //Regristro de contacto
    case 1:
     printf("h1");
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
}
printf("finish");
return 0;
}