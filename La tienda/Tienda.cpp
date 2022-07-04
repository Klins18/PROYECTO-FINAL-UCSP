#define _WIN32_WINNT 0x0500 // Es necesaria esta definicion para esconder ventana de consola
#include <iostream>
#include <string.H>
#include <vector>
#include <cstring>
#include <windows.h> // Libreria que contiene las funciones de Winapi

#define ID1 100
#define IDAceptar 101
#define IDCancelar 102
#define IDobtenerID 103
#define IDobtenerclave 104
#define Est1 105
#define Est2 106
#define Est3 107
#define Est4 108

// Admin
#define IDModificarobjetos 109
#define IDEliminarobjetos 125
#define IDAgregarobjetos 126
#define IDLogout 127

#define ObtnEst 110
#define Obtenernombre 111

#define ObtmarcaEst 112
#define Obtenermarca 113

#define ObtnnSerieEst 114
#define ObtenernSerie 115

#define ObtprecioEst 116
#define Obtenerprecio 117

#define ObtcantidadEst 118
#define Obtenercantidad 119

#define ObtcategoriaEst 120
#define Obtenercategoria 121

#define Salir 122
#define Agregaralalista 123

#define eliminarl 124

/* Includes aqui para evitar confusiones eh?*/

#include "Persona.cpp"
#include "Producto.cpp"
#include "Administrador.cpp"
#include "ListaProductos.cpp"
#include "Cliente.cpp"


using namespace std;

using std::vector;

Persona Manu = Persona("Manu","92322","jacintopichimawido25@gmail.com","idk","923121311");

Cliente ManuCliente = Cliente("Manu","92322","jacintopichimawido25@mail.com","idk","923123131","29","Manu", 2000);

Admin ManuAdmin = Admin("Manu","92322","jacintopichimawido25@gmail.com","idk","923121311", "29", "Manu");

/*  Declaracion del procedimiento de windows  */

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);



/*  Declaramos una variable de tipo char para guardar el nombre de nuestra aplicacion  */

char NombreClase[] = "Estilos";

char textoclave[20];

char textoID[20];

char nombre[20];
char marca[20];
char nSerie[20];
char precio[20];
char cantidad[20];
char categoria[20];

char elimn[20];

HWND ventana1;           /* Manejador de la ventana*/

HWND boton1;             /* Creamos un boton */

HWND boton2;

HWND boton3;

HWND Obtenerclave;

HWND ObtenerID;

HWND Estatico1;

HWND Estatico2;

HWND Estatico3;

HWND Estatico4;

HWND Modificar;

HWND Agregar;

HWND Eliminar;

HWND Logout;

HWND botonnombre;
//nombre
HWND Obtnest;

HWND Obtnmarcaest;
//marca
HWND botonmarca;

HWND ObtSerieEst;
//nserie
HWND botonSer;

HWND ObtnPrecest;
//precio
HWND botonprecio;

HWND Obtncantidadest;
//cantidad
HWND botoncantidad;

HWND Obtncategoria;
//categoria
HWND botoncategoria;

HWND Salirmenu;
HWND AgregaralaLista;

HWND Eliminardelalista;

MSG mensajecomunica;     /* Mensajes internos que se envian a la aplicacion */

WNDCLASSEX estilo1;      /* Nombre de la clase para los estilos de ventana */



int WINAPI WinMain (HINSTANCE hThisInstance,

                     HINSTANCE hPrevInstance,

                     LPSTR lpszArgument,

                     int nCmdShow)

{



    /* Creamos la estructura de la ventana indicando varias caracteristicas */

    estilo1.hInstance = hThisInstance;

    estilo1.lpszClassName = NombreClase;

    estilo1.lpfnWndProc = WindowProcedure;

    estilo1.style = CS_DBLCLKS;

    estilo1.cbSize = sizeof (WNDCLASSEX);

    estilo1.hIcon = LoadIcon (NULL, IDI_QUESTION);

    estilo1.hIconSm = LoadIcon (NULL, IDI_INFORMATION);

    estilo1.hCursor = LoadCursor (NULL, IDC_ARROW);

    estilo1.lpszMenuName = NULL;   /* Sin Menu */

    estilo1.cbClsExtra = 0;

    estilo1.cbWndExtra = 0;

    estilo1.hbrBackground = (HBRUSH) COLOR_WINDOW; /* Color del fondo de ventana */



    /* Registramos la clase de la ventana */

    if (!RegisterClassEx (&estilo1))

        return 0;



    /* Ahora creamos la ventana a partir de la clase anterior */

    ventana1 = CreateWindowEx (

           0,

           NombreClase,         /* Nombre de la clase */

           ("La tienda"),       /* Titulo de la ventana */

           WS_OVERLAPPEDWINDOW|WS_BORDER, /* Ventana por defecto */

           300,       /* Posicion de la ventana en el eje X (de izquierda a derecha) */

           70,       /* Posicion de la ventana, eje Y (arriba abajo) */

           800,                 /* Ancho de la ventana */

           575,                 /* Alto de la ventana */

           HWND_DESKTOP,

           NULL,                /* Sin menu */

           hThisInstance,

           NULL

           );



    /* Hacemos que la ventana sea visible */

    ShowWindow (ventana1, nCmdShow);

    ShowWindow(GetConsoleWindow(), SW_HIDE ); // Funcion para esconder la ventana de consola



    /* Hacemos que la ventan se ejecute hasta que se obtenga resturn 0 */

    while (GetMessage (&mensajecomunica, NULL, 0, 0))

    {

        /* Traduce mensajes virtual-key */

        TranslateMessage(&mensajecomunica);

        /* Envia mensajes a WindowProcedure */

        DispatchMessage(&mensajecomunica);

    }



    return mensajecomunica.wParam;

}



LRESULT CALLBACK WindowProcedure (HWND ventana1, UINT mensajecomunica, WPARAM wParam, LPARAM lParam)

{
        /* Aqui estoy agregando los vectores y cosillas que necesitamos ·······························································*/
    vector <Admin> VecAdmins;
    VecAdmins.reserve(10);
    VecAdmins.push_back(ManuAdmin);

    vector <Cliente> VecClientes;
    VecClientes.reserve(10);
    VecClientes.push_back(ManuCliente);

    ListaProductos LProductos = ListaProductos();
    //Extrae elementos de un archivo txt
    LProductos.extraer();

    int Adminquien = 0;
    //if (Adminquien == 1) activara las funciones de admin

    switch (mensajecomunica) /* Manejamos los mensajes */

    {

        case WM_CLOSE: /* Que hacer en caso de recibir el mensaje WM_CLOSE*/

        DestroyWindow(ventana1); /* Destruir la ventana */

             break;

        case WM_DESTROY:

        PostQuitMessage(0);

            break;

        case WM_CREATE:

            boton1 = CreateWindowEx(0, "button", ("Ayuda"), WS_VISIBLE | WS_CHILD | 0x00000001, 10, 400, 80, 25, ventana1, (HMENU)ID1, GetModuleHandle(NULL), 0);

            boton2 = CreateWindowEx(0, "button", ("Aceptar"), WS_VISIBLE | WS_CHILD | 0x00000001, 90, 400, 80, 25, ventana1, (HMENU)IDAceptar, GetModuleHandle(NULL), 0);

            boton3 = CreateWindowEx(0, "button", ("Cancelar"), WS_VISIBLE | WS_CHILD | 0x00000001, 170, 400, 80, 25, ventana1, (HMENU)IDCancelar, GetModuleHandle(NULL), 0);

            Obtenerclave = CreateWindowEx(0, "EDIT",0, WS_BORDER|WS_CHILD|WS_VISIBLE, 10, 150, 150, 18, ventana1, (HMENU)IDobtenerclave, GetModuleHandle(NULL), 0);
            
            Estatico1 = CreateWindowEx(0, "STATIC", ("Introduzca su clave:"), WS_VISIBLE | WS_CHILD | 0x00000001, 10, 125, 150, 25, ventana1, (HMENU)Est1, GetModuleHandle(NULL), 0);

            ObtenerID = CreateWindowEx(0, "EDIT",0, WS_BORDER|WS_CHILD|WS_VISIBLE, 10, 100, 150, 18, ventana1, (HMENU)IDobtenerID, GetModuleHandle(NULL), 0);

            Estatico2 = CreateWindowEx(0, "STATIC", ("Introduzca su ID:"), WS_VISIBLE | WS_CHILD | 0x00000001, 10, 75, 150, 25, ventana1, (HMENU)Est2, GetModuleHandle(NULL), 0);

            break;

        case WM_COMMAND:

            if (LOWORD(wParam) == ID1){

            MessageBox(NULL, "Ingrese su ID y su contraseña.", "Ayuda", MB_OKCANCEL | MB_DEFBUTTON2);

            }

            else if(LOWORD(wParam)== IDAceptar){
                int gwtstat = 0;
                char *t = &textoclave[0];
                gwtstat = GetWindowText(Obtenerclave,t,20);

                int gwtstat2 = 0;
                char *t2 = &textoID[0];
                gwtstat2 = GetWindowText(ObtenerID,t2,20);

                string s;
                string s2;
                for(int i = 0; i < VecAdmins.size(); i++){
                    s = VecAdmins.at(i).getcontraseña();
                    s2 = VecAdmins.at(i).getID();
                    //Convierte de char a string
                    std::string aux(t);
                    std::string aux2(t2);
                    if(aux2 == s2 && aux == s){
                        cout << "Eureka! XD";
                        cout << "Logeado como: " << VecAdmins.at(i).getID();
                        Estatico3 = CreateWindowEx(0, "STATIC", ("Bienvenido Admin"), WS_VISIBLE | WS_CHILD | 0x00000001, 180, 10, 150, 25, ventana1, (HMENU)Est3, GetModuleHandle(NULL), 0);

                        Agregar = CreateWindowEx(0, "button", ("Agregar productos"), WS_VISIBLE | WS_CHILD | 0x00000001, 180, 60, 180, 25, ventana1, (HMENU)IDAgregarobjetos, GetModuleHandle(NULL), 0);

                        Modificar = CreateWindowEx(0, "button", ("Modificar productos"), WS_VISIBLE | WS_CHILD | 0x00000001, 180, 100, 180, 25, ventana1, (HMENU)IDModificarobjetos, GetModuleHandle(NULL), 0);

                        Eliminar = CreateWindowEx(0, "button", ("Eliminar productos"), WS_VISIBLE | WS_CHILD | 0x00000001, 180, 140, 180, 25, ventana1, (HMENU)IDEliminarobjetos, GetModuleHandle(NULL), 0);

                        Logout = CreateWindowEx(0, "button", ("Salir"), WS_VISIBLE | WS_CHILD | 0x00000001, 180, 180, 180, 25, ventana1, (HMENU)IDLogout, GetModuleHandle(NULL), 0);


                        /*botonnombre = CreateWindowEx(0, "EDIT", ("Nombre"), WS_VISIBLE | WS_CHILD | 0x00000001, 180, 60, 80, 25, ventana1, (HMENU)Obtenernombre, GetModuleHandle(NULL), 0);

                        botonmarca = CreateWindowEx(0, "EDIT", ("Marca"), WS_VISIBLE | WS_CHILD | 0x00000001, 180, 90, 80, 25, ventana1, (HMENU)Obtenermarca, GetModuleHandle(NULL), 0);

                        botonSer = CreateWindowEx(0, "EDIT", ("nSerie"), WS_VISIBLE | WS_CHILD | 0x00000001, 180, 120, 80, 25, ventana1, (HMENU)ObtenernSerie, GetModuleHandle(NULL), 0);*/

                         
                    }
                    break;
                }
                break;
            }
            if(LOWORD(wParam)== IDAgregarobjetos){
                Obtnest = CreateWindowEx(0, "STATIC", ("Nombre:"), WS_VISIBLE | WS_CHILD | 0x00000001, 400, 60, 150, 25, ventana1, (HMENU)ObtnEst, GetModuleHandle(NULL), 0);

                botonnombre = CreateWindowEx(0, "EDIT", 0, WS_VISIBLE | WS_CHILD | 0x00000001, 400, 90, 190, 25, ventana1, (HMENU)Obtenernombre, GetModuleHandle(NULL), 0);

                Obtnmarcaest = CreateWindowEx(0, "STATIC", ("Marca:"), WS_VISIBLE | WS_CHILD | 0x00000001, 400, 120, 150, 25, ventana1, (HMENU)Obtnmarcaest, GetModuleHandle(NULL), 0);

                botonmarca = CreateWindowEx(0, "EDIT", 0, WS_VISIBLE | WS_CHILD | 0x00000001, 400, 150, 190, 25, ventana1, (HMENU)Obtenermarca, GetModuleHandle(NULL), 0);

                ObtSerieEst = CreateWindowEx(0, "STATIC", ("Numero de Serie:"), WS_VISIBLE | WS_CHILD | 0x00000001, 400, 180, 150, 25, ventana1, (HMENU)ObtnnSerieEst, GetModuleHandle(NULL), 0);

                botonSer = CreateWindowEx(0, "EDIT", 0, WS_VISIBLE | WS_CHILD | 0x00000001, 400, 210, 190, 25, ventana1, (HMENU)ObtenernSerie, GetModuleHandle(NULL), 0);

                ObtnPrecest = CreateWindowEx(0, "STATIC", ("Precio:"), WS_VISIBLE | WS_CHILD | 0x00000001, 400, 240, 150, 25, ventana1, (HMENU)ObtprecioEst, GetModuleHandle(NULL), 0);

                botonprecio = CreateWindowEx(0, "EDIT", 0, WS_VISIBLE | WS_CHILD | 0x00000001, 400, 270, 190, 25, ventana1, (HMENU)Obtenerprecio, GetModuleHandle(NULL), 0);

                Obtncantidadest = CreateWindowEx(0, "STATIC", ("Cantidad:"), WS_VISIBLE | WS_CHILD | 0x00000001, 400, 300, 150, 25, ventana1, (HMENU)ObtcantidadEst, GetModuleHandle(NULL), 0);

                botoncantidad = CreateWindowEx(0, "EDIT", 0, WS_VISIBLE | WS_CHILD | 0x00000001, 400, 330, 190, 25, ventana1, (HMENU)Obtenercantidad, GetModuleHandle(NULL), 0);

                Obtncategoria = CreateWindowEx(0, "STATIC", ("Categoria:"), WS_VISIBLE | WS_CHILD | 0x00000001, 400, 360, 150, 25, ventana1, (HMENU)ObtcategoriaEst, GetModuleHandle(NULL), 0);

                botoncategoria = CreateWindowEx(0, "EDIT", 0, WS_VISIBLE | WS_CHILD | 0x00000001, 400, 390, 190, 25, ventana1, (HMENU)Obtenercategoria, GetModuleHandle(NULL), 0);

                Salirmenu = CreateWindowEx(0, "button", ("Salir"), WS_VISIBLE | WS_CHILD | 0x00000001, 400, 450, 190, 25, ventana1, (HMENU)Salir, GetModuleHandle(NULL), 0);

                AgregaralaLista = CreateWindowEx(0, "button", ("Agregar"), WS_VISIBLE | WS_CHILD | 0x00000001, 400, 420, 190, 25, ventana1, (HMENU)Agregaralalista, GetModuleHandle(NULL), 0);
                break;

            }

            /*else if(LOWORD(wParam)== IDEliminarobjetos){
                Eliminardelalista = CreateWindowEx(0, "EDIT", 0, WS_VISIBLE | WS_CHILD | 0x00000001, 400, 10, 190, 25, ventana1, (HMENU)eliminarl, GetModuleHandle(NULL), 0);
                int gwtstat = 0;
                char *t = &elimn[0];
                gwtstat = GetWindowText(Eliminardelalista,t,20);
            }*/

            else if(LOWORD(wParam)== Agregaralalista){
                int gwtstat = 0;
                char *t = &nombre[0];
                gwtstat = GetWindowText(botonnombre,t,20);

                int gwtstat2 = 0;
                char *t2 = &marca[0];
                gwtstat2 = GetWindowText(botonmarca,t2,20);

                int gwtstat3 = 0;
                char *t3 = &nSerie[0];
                gwtstat3 = GetWindowText(botonSer,t3,20);

                int gwtstat4 = 0;
                char *t4 = &precio[0];
                gwtstat4 = GetWindowText(botonprecio,t4,20);

                int gwtstat5 = 0;
                char *t5 = &cantidad[0];
                gwtstat5 = GetWindowText(botoncantidad,t5,20);

                int gwtstat6 = 0;
                char *t6 = &categoria[0];
                gwtstat6 = GetWindowText(botoncategoria,t6,20);

                string s;
                string s2;
                string s3;
                int s4;
                int s5;
                string s6;

                std::string aux(t);
                std::string aux2(t2);
                std::string aux3(t3);
                std::string aux4(t4);
                std::string aux5(t5);
                std::string aux6(t6);

                int auxp1;
                int auxc1;

                auxp1 = std::stoi(aux4);
                auxc1 = std::stoi(aux5);
                
                LProductos.agregar(aux,aux2,aux3,auxp1,auxc1,aux6);
                LProductos.imprime();

                /*Producto nProducto = Producto(aux,aux2,aux3,auxp1,auxc1,aux6);
                LProductos.agregar2(nProducto);*/
                break;
            }
            
            else if(LOWORD(wParam)== Salir){
                PostQuitMessage(0);
            }

            else if(LOWORD(wParam)== IDModificarobjetos){
                MessageBox(NULL, "Modificar.", "Modificar Objetos", MB_OKCANCEL | MB_DEFBUTTON2);
                break;
            }

            else if(LOWORD(wParam)== IDEliminarobjetos){
                MessageBox(NULL, "Eliminar.", "Eliminar Objetos", MB_OKCANCEL | MB_DEFBUTTON2);
                break;
            }

            else if(LOWORD(wParam)== IDLogout){
                PostQuitMessage(0);
            }

            else if(LOWORD(wParam)== IDCancelar){
                PostQuitMessage(0);
            }
            LProductos.imprime();

            break;

        default:  /* Tratamiento por defecto para mensajes que no especificamos */

            return DefWindowProc (ventana1, mensajecomunica, wParam, lParam);

    }


return 0;

}

/*
int main(){
    // Para crear una persona (nombre, DNI, correo, direccion, telefono)
    Persona Manu = Persona("Manu","92322","jacintopichimawido25@gmail.com","idk","923121311");
    Manu.imprime();

    //Para crear un producto (nombre, marca, nSerie, precio, cantidad, categoria)
    Producto Laptop = Producto("Laptop","Lenovo","201",1200,10,"Tec");
    Laptop.imprime();

    Admin ManuAdmin = Admin("Manu","92322","jacintopichimawido25@gmail.com","idk","923121311", "29", "Manu");
    ManuAdmin.imprime();

    Cliente ManuCliente = Cliente("Manu","92322","jacintopichimawido25@mail.com","idk","923123131","29","Manu", 2000);

    //Para crear un vector vector <tipo> nombre;
    vector <Admin> VecAdmins;
    //Reserva 10 espacios (sino, al alcanzar su capacidad maxima se duplica)
    VecAdmins.reserve(10);
    //Me agrego como admin XD
    VecAdmins.push_back(ManuAdmin);
    
    //vector <Producto> VecProductos;
    // Reservasdo 100 espacios para el vector
    //VecProductos.reserve(100);
    //VecProductos.push_back(Laptop);
    ListaProductos LProductos = ListaProductos();
    //LProductos.agregar();
    //Aqui imprime la lista de productos que tenga la lista
    //LProductos.imprime();

    //LProductos.agregar();

    //LProductos.imprime();
    //Extrae elementos de un archivo txt
    LProductos.extraer();

    //LProductos.eliminar();
    LProductos.filtro();

    LProductos.imprime();

    //LProductos.modificar();

    ManuCliente.agregar(LProductos);

    ManuCliente.comprar();

    ManuCliente.imprime();
    
}*/