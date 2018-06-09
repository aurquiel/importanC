#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *text= "00001400MAYONESA  00000005102000\n";
char *text2= "0010550MAYONESA  00000045102130\n";

int long long gCantidadPrecioEnt = 0;
int long long gCantidadPrecioDec = 0;
int long long gImpuestoEnt = 0;
int long long gImpuestoDec = 0;
int long long gCantidadPrecioEntImp = 0;
int long long gCantidadPrecioDecImp = 0;

void formatGlobal(void)
{
    if((gCantidadPrecioDec/100)*10!=0) //acaarea
        gCantidadPrecioEnt += (gCantidadPrecioDec/100)*10;
    if((gImpuestoDec/100)*10!=0) //acaarea
        gImpuestoEnt += (gImpuestoDec/100)*10;
    if((gCantidadPrecioDecImp/100)*10!=0) //acaarea
        gCantidadPrecioEntImp += (gCantidadPrecioDecImp/100)*10;

    printf("\nTotal sin Impuestos; %lld.%lld\nImpuestos Totales: %lld.%lld\nTotal con Impuestos: %lld.%lld",gCantidadPrecioEnt, gCantidadPrecioDec, gImpuestoEnt, gImpuestoDec, gCantidadPrecioEntImp, gCantidadPrecioDecImp);
}

int main()
{
    //Variables de los campos
    char cantidad[9];
    memset(cantidad,'\0',9);
    char descripcion[11];
    memset(descripcion,'\0',11);
    char precio[11];
    memset(precio,'\0',11);
    char impuesto[5];
    memset(impuesto,'\0',5);

    //Extraer campos
    memccpy(cantidad,text,1,8);
    memccpy(descripcion,text+8,1,10);
    memccpy(precio,text+18,1,10);
    memccpy(impuesto,text+28,1,4);

    //aputar despues de los ceros iniciales de los campos con digitos
    char *cantidadNoZero = NULL;
    char *precioNoZero = NULL;
    char *impuestoNoZero = NULL;

    char *i = NULL;
    if (*cantidad == '0')
    {
        for(i=cantidad; *(i++) == '0'; cantidadNoZero = i)
            ;
    }
    else
    {
        cantidadNoZero = cantidad;
    }
    if (*precio == '0')
    {
        for(i=precio; *(i++) == '0'; precioNoZero = i)
            ;
    }
    else
    {
        precioNoZero = precio;
    }
    if (*impuesto == '0')
    {
        for(i=impuesto; *(i++) == '0'; impuestoNoZero = i)
            ;
    }
    else
    {
        impuestoNoZero = impuesto;
    }

    //Cantidad por precio
    //transformar a entero
    char *ptr = NULL;
    int long long cantidadTotal = strtol(cantidadNoZero, &ptr, 10); //todo el campo entero
    int long long precioTotal = strtol(precioNoZero, &ptr, 10);     //todo el campo entero
    //separar decimal y entero
    int long long cantidadPrecioEnt = (cantidadTotal * precioTotal) / 100000; //precio por cantidad entero
    int long long cantidadPrecioDec = ((cantidadTotal * precioTotal) - (cantidadPrecioEnt*100000)) / 1000; //precio por cantidad decimal
    //obtener parte entera y decimal de cantidad y precio
    int long long cantidadEnt = cantidadTotal / 1000;
    int long long cantidadDec = cantidadTotal - cantidadEnt*1000;
    int long long precioEnt = precioTotal / 100;
    int long long precioDec = precioTotal - precioEnt*100;

    //Obtner impuesto
    //obterne entero y decimal de impuesto
    int long long impuestoTotal = strtol(impuestoNoZero, &ptr, 10); //todo el campo entero
    //multiplicar cantidad*precio * impuesto
    char aux[19]; //variable auxiliar para unir cantidad decimal y entera
    sprintf(aux,"%lld%lld", cantidadPrecioEnt, cantidadPrecioDec);
    int long long cantidadPrecioTotal = strtol(aux,&ptr,10); //todo el campo entero
    int long long impuestoEnt = (cantidadPrecioTotal * impuestoTotal) /1000000;
    int long long impuestoDec = ((cantidadPrecioTotal * impuestoTotal) - (impuestoEnt*1000000)) / 10000;

    //Cantiddad*precio + impuesto
    sprintf(aux,"%lld%lld",impuestoEnt, impuestoDec);
    int long long impuestoTotal2 = strtol(aux, &ptr, 10);
    int long long sumTotalEnt = (cantidadPrecioTotal + impuestoTotal2) / 100;
    int long long sumTotalDec = (cantidadPrecioTotal + impuestoTotal2) - sumTotalEnt*100;

    printf("%lld.%lld %s %lld.%lld %lld.%lld %lld.%lld %lld.%lld",cantidadEnt, cantidadDec, descripcion, precioEnt, precioDec, cantidadPrecioEnt, cantidadPrecioDec, impuestoEnt, impuestoDec, sumTotalEnt, sumTotalDec);

    //actualizar variables globales

    //total sin impuesto
    gCantidadPrecioEnt += cantidadPrecioEnt;
    gCantidadPrecioDec += cantidadPrecioDec;
    //impuestos Totales
    gImpuestoEnt += impuestoEnt;
    gImpuestoDec += impuestoDec;
    //total con impuesto
    gCantidadPrecioEntImp += sumTotalEnt;
    gCantidadPrecioDecImp += sumTotalDec;

    formatGlobal();
    return 0;
}
