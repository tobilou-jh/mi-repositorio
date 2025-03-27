#include <stdio.h>
#include <string.h>

int main() {
    int id, stock, cantidad, opcion, validacion,val;
    float precio, total_ganancias = 0;
    char nombre[30];

    

    do {
        printf("\nMenu de Opciones:\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar informacion del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        if(opcion==1){
            validacion=1;
        }

        switch(opcion) {
            case 1:
                // Registro del producto
                printf("Ingrese el ID del producto: \n");
                scanf("%d", &id);
    
                printf("Ingrese el nombre del producto: \n");
                fflush(stdin);
                fgets(nombre, 30, stdin);
    
                
                do{

                    printf("Ingrese la cantidad inicial en stock: \n");
                    fflush(stdin);

                    val= scanf("%d", &stock);
                    if(val != 1){
                        printf("Dato invalido\n");
                        stock=0;
                    
                    }else if(stock<1){
                        printf("Ingreser una cantidad positiva\n");
    
                    }
                }while(stock<1);
               
                do{
                    printf("Ingrese el precio unitario del producto: \n");
                    fflush(stdin);
                    val=scanf("%f", &precio); 
                    if(val != 1){
                        printf("Dato invalido\n");
                        precio=-1;
                    
                    }else if(precio<0){
                        printf("Ingrese un numero positivo para el precio: \n");
                    }
                }while(precio<0);
                
                break;

            case 2:
                if(validacion==1){
                    do {
                        printf("Ingrese la cantidad a vender: ");
                        scanf("%d", &cantidad);
                        if(cantidad <= 0){
                            printf("La cantidad ingresada no es valida. Intente nuevamente.\n");
                        }
                    }while(cantidad <= 0);
                    
                    if (cantidad > stock) {
                        printf("No hay suficiente stock para realizar la venta.\n");
                        break;
                    }else{
                        stock-=cantidad;
                        total_ganancias += cantidad * precio;
                    } 
                }else{
                    printf("Primero tiene que registrar un producto\n");
                }
                
                break;

            case 3:
                if(validacion==1){
                    do{
                        printf("Ingrese la cantidad a agregar al stock: ");
                        scanf("%d", &cantidad);
                        if(cantidad <= 0){
                            printf("La cantidad ingresada no es valida. Intente nuevamente.\n");
                        }
    
                    }while(cantidad <= 0);
                    stock+=cantidad;
                }else{
                    printf("Primero tiene que registrar un producto\n");
                }
                break;

            case 4:
                if(validacion==1){
                    printf("\nInformacion del producto:\n");
                    printf("ID: %d\n", id);
                    printf("Nombre: %s", nombre);
                    printf("Stock disponible: %d\n", stock);
                    printf("Precio unitario: %.2f\n", precio);
                    break; 
                }else{
                    printf("Primero tiene que registrar un producto\n");
                }

            case 5:
                if(validacion==1){
                    printf("Total de ganancias: $%.2f\n", total_ganancias);
                }else{
                    printf("Primero tiene que registrar un producto\n");
                }
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    return 0;
}
