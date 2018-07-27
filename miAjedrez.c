#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//Tamanios no variables del juego
#define TABLERO_LINEA_TAMANIO 8
#define PEONES_NUMERO 8
#define TORRES_NUMERO 2
#define CABALLOS_NUMERO 2
#define ALFILES_NUMERO 2
#define DAMA_NUMERO 1
#define REY_NUMERO 1

enum COLOR {BLANCO,NEGRO};

typedef struct TableroEstructura{
    uint8_t VerticalTablero[TABLERO_LINEA_TAMANIO];
    uint8_t HorizontalTablero[TABLERO_LINEA_TAMANIO];
}TableroEstructura;

typedef struct PeonEstructura{
    uint8_t PosicionVertical;
    uint8_t PosicionHorizontal;
    uint8_t Inicial; //no se a movido desde el comienzo, por eso cero para posible movimiento de dos casilla;
    uint8_t Color;
}PeonEstructura;

typedef struct TorreEstructura{
    uint8_t PosicionVertical;
    uint8_t PosicionHorizontal;
    uint8_t Inicial; //no se a movido desde el comienzo, posible enrroque
    uint8_t Color;
}TorreEstructura;

typedef struct CaballoEstructura{
    uint8_t PosicionVertical;
    uint8_t PosicionHorizontal;
    uint8_t Color;
}CaballoEstructura;

typedef struct AlfilEstructura{
    uint8_t PosicionVertical;
    uint8_t PosicionHorizontal;
    uint8_t Color;
}AlfilEstructura;

typedef struct DamaEstructura{
    uint8_t PosicionVertical;
    uint8_t PosicionHorizontal;
    uint8_t Color;
}DamaEstructura;

typedef struct ReyEstructura{
    uint8_t PosicionVertical;
    uint8_t PosicionHorizontal;
    uint8_t Inicial; //no se a movido desde el comienzo, posible enrroque
    uint8_t Color;
}ReyEstructura;

TableroEstructura* TableroInicializador(void)
{
    //Alojar el Tablero
    TableroEstructura *Tablero = calloc(sizeof(TableroEstructura),1);
    if(Tablero)
    {
        //Inicializar los valores de las lineas para identificar las casillas
        for(uint_fast8_t i = 0; i<TABLERO_LINEA_TAMANIO; i++)
        {
            Tablero->VerticalTablero[i] = i+1;
            Tablero->HorizontalTablero[i] = i+97;

        }
        return Tablero;
    }
    else
        exit(-1);
}

PeonEstructura** PeonesInicializador(uint8_t colorSeleccionado)
{
    //Alojar un apuntador de apuntadores de estructuras
    PeonEstructura **Peones = calloc(sizeof(PeonEstructura*), PEONES_NUMERO);

    if(Peones)
    {
        //Alojar cada peon inidividualmente
        for(uint8_t i = 0; i<PEONES_NUMERO ; i++)
        {
            Peones[i] = calloc(sizeof(PeonEstructura),1);
            if(Peones[i])
            {
                Peones[i]->Color = colorSeleccionado;
                Peones[i]->Inicial = 0; //no se ha movido de la posicion inicial posible movieminto de dos espacios
                if (NEGRO == colorSeleccionado)
                {
                    Peones[i]->PosicionVertical = 2;     //Posiciones opr defecto de los peones negros
                    Peones[i]->PosicionHorizontal = 'a' + i;
                }
                else if (BLANCO == colorSeleccionado)
                {
                    Peones[i]->PosicionVertical = 7;     //Posiciones por defecto de los peones blancos
                    Peones[i]->PosicionHorizontal = 'a' + i;
                }
            }
            else
                exit(-1);
        }
        return Peones;
    }
    else
        exit(-1);
}

TorreEstructura** TorresInicializador(uint8_t colorSeleccionado)
{
    //Alojar un apuntador de apuntadores de estructuras
    TorreEstructura **Torres = calloc(sizeof(TorreEstructura*), TORRES_NUMERO);

    if(Torres)
    {
        //Alojar cada peon inidividualmente
        for(uint8_t i = 0; i<TORRES_NUMERO ; i++)
        {
            Torres[i] = calloc(sizeof(TorreEstructura),1);
            if(Torres[i])
            {
                Torres[i]->Color = colorSeleccionado;
                Torres[i]->Inicial = 0; //no se ha movido de la posicion inicial posible movieminto de dos espacios
                if (NEGRO == colorSeleccionado)
                {
                    Torres[i]->PosicionVertical = 1;     //Posiciones opr defecto de los peones negros
                    Torres[i]->PosicionHorizontal = 'a' + i*7;
                }
                else if (BLANCO == colorSeleccionado)
                {
                    Torres[i]->PosicionVertical = 8;     //Posiciones por defecto de los peones blancos
                    Torres[i]->PosicionHorizontal = 'a' + i*7;
                }
            }
            else
                exit(-1);
        }
        return Torres;
    }
    else
        exit(-1);
}

CaballoEstructura** CaballosInicializador(uint8_t colorSeleccionado)
{
    //Alojar un apuntador de apuntadores de estructuras
    CaballoEstructura **Caballos = calloc(sizeof(CaballoEstructura*), CABALLOS_NUMERO);

    if(Caballos)
    {
        //Alojar cada peon inidividualmente
        for(uint8_t i = 0; i<CABALLOS_NUMERO ; i++)
        {
            Caballos[i] = calloc(sizeof(CaballoEstructura),1);
            if(Caballos[i])
            {
                Caballos[i]->Color = colorSeleccionado;
                if (NEGRO == colorSeleccionado)
                {
                    Caballos[i]->PosicionVertical = 1;     //Posiciones opr defecto de los peones negros
                    Caballos[i]->PosicionHorizontal = 'b' + i*5;
                }
                else if (BLANCO == colorSeleccionado)
                {
                    Caballos[i]->PosicionVertical = 8;     //Posiciones por defecto de los peones blancos
                    Caballos[i]->PosicionHorizontal = 'b' + i*5;
                }
            }
            else
                exit(-1);
        }
        return Caballos;
    }
    else
        exit(-1);
}

AlfilEstructura** AlfilesInicializador(uint8_t colorSeleccionado)
{
    //Alojar un apuntador de apuntadores de estructuras
    AlfilEstructura **Alfiles = calloc(sizeof(AlfilEstructura*), ALFILES_NUMERO);

    if(Alfiles)
    {
        //Alojar cada peon inidividualmente
        for(uint8_t i = 0; i<ALFILES_NUMERO ; i++)
        {
            Alfiles[i] = calloc(sizeof(AlfilEstructura),1);
            if(Alfiles[i])
            {
                Alfiles[i]->Color = colorSeleccionado;
                if (NEGRO == colorSeleccionado)
                {
                    Alfiles[i]->PosicionVertical = 1;     //Posiciones opr defecto de los peones negros
                    Alfiles[i]->PosicionHorizontal = 'c' + i*3;
                }
                else if (BLANCO == colorSeleccionado)
                {
                    Alfiles[i]->PosicionVertical = 8;     //Posiciones por defecto de los peones blancos
                    Alfiles[i]->PosicionHorizontal = 'c' + i*3;
                }
            }
            else
                exit(-1);
        }
        return Alfiles;
    }
    else
        exit(-1);
}

DamaEstructura** DamaInicializador(uint8_t colorSeleccionado)
{
    //Alojar un apuntador de apuntadores de estructuras
    DamaEstructura **Dama = calloc(sizeof(AlfilEstructura*), DAMA_NUMERO);

    if(Dama)
    {
        //Alojar cada Dama inidividualmente
        for(uint8_t i = 0; i<DAMA_NUMERO ; i++)
        {
            Dama[i] = calloc(sizeof(DamaEstructura),1);
            if(Dama[i])
            {
                Dama[i]->Color = colorSeleccionado;
                if (NEGRO == colorSeleccionado)
                {
                    Dama[i]->PosicionVertical = 1;     //Posiciones opr defecto de los peones negros
                    Dama[i]->PosicionHorizontal = 'd';
                }
                else if (BLANCO == colorSeleccionado)
                {
                    Dama[i]->PosicionVertical = 8;     //Posiciones por defecto de los peones blancos
                    Dama[i]->PosicionHorizontal = 'd';
                }
            }
            else
                exit(-1);
        }
        return Dama;
    }
    else
        exit(-1);
}

int main ()
{
    TableroEstructura *Tablero = TableroInicializador();

    for (int i = 0; i <TABLERO_LINEA_TAMANIO; i++)
        for (int j = 0; j <TABLERO_LINEA_TAMANIO; j++)
            ;//printf("%c%d ",Tablero->HorizontalTablero[i],Tablero->VerticalTablero[j]);

    //Se crean las piezas de los perones blancos y negros
    PeonEstructura **PeonesNegros = PeonesInicializador(NEGRO);
    PeonEstructura **PeonesBlancos = PeonesInicializador(BLANCO);

    printf("%d\n",PeonesNegros[1]->Color);
    printf("%d\n",PeonesNegros[1]->PosicionVertical);
    printf("%c\n",PeonesNegros[1]->PosicionHorizontal);


    return(0);
}
