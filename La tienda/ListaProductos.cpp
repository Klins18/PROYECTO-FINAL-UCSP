#include "Producto.h"
#include "ListaProductos.h"
#include <vector>
#include <cstdlib>
#include <fstream>

ListaProductos::ListaProductos(){
    vector <Producto> VecProductos;
}

void ListaProductos::imprime(){
    cout << "Lista de Productos: " << endl;
    for (int i = 0; i < VecProductos.size();i++){
        VecProductos.at(i).imprime();
    }
}

void ListaProductos::agregar(string anombre, string amarca, string anSerie, int aPrecio, int aCantidad, string acategoria){
    /*cout << "Que producto desea agregar? " << endl;
    cout << "Introduzcalo en el siguiente orden " << endl;
    cout << "Nombre, Marca, nªSerie, Precio, Cantidad, Categoria" << endl;
    cout << "Nombre: " << endl;
    cin >> nnombre,
    cout << "Marca: " << endl;
    cin >> marca;
    cout << "nº de Serie: " << endl;
    cin >> nSerie;
    cout << "Precio: " << endl;
    cin >> Precio;
    cout << "Cantidad: " << endl;
    cin >> Cantidad;
    cout << "Categoria: " << endl;
    cin >> Categoria;
    cout << "Producto: " << nnombre << marca << nSerie << Precio << Cantidad << Categoria << endl;
    cout << "Es esto correcto?" << endl;
    string r;
    cin >> r;
    if (r == "si"){
        
        string linea;
        string texto;
        // Lee el archivo de texto (Si es que no existe lo crea)
        ifstream archivo("Productos.txt");
        //Lee todo el archivo y lo almacena en la variable texto
        while (getline(archivo, linea)){
            texto=texto+linea+"\n";
        }
        archivo.close();
        
        //Agrega a texto los datos del nuevo producto y reescribe texto en el archivo
        ofstream archivo2("Productos.txt");
        archivo2 << texto << nnombre <<" "<< marca << " " << nSerie <<" "<< Precio << " " << Cantidad << " " << Categoria;

        archivo2.close();*/

        nnombre = anombre;
        marca = amarca;
        nSerie = anSerie;
        Precio = aPrecio;
        Cantidad = aCantidad;
        Categoria = acategoria;

        string linea;
        string texto;

        ifstream archivo("Productos.txt");
        while (getline(archivo,linea)){
            texto = texto + linea+"\n";
        }
        archivo.close();

        ofstream archivo2("Productos.txt");
        archivo2 << texto << nnombre<< " " << marca << " "  << nSerie << " "  << Precio << " "  << Cantidad << " "  << Categoria;

        /*Producto nProducto = Producto(nnombre,marca,nSerie,Precio,Cantidad,Categoria);
        VecProductos.push_back(nProducto);*/
        cout << endl;
    
}

void ListaProductos::eliminar(int i){

    string linea;
    string texto;

    ifstream archivo("Productos.txt");
    while (getline(archivo,linea)){
        texto = texto + linea+"\n";
    }
    archivo.close();
    ofstream archivo2("Productos.txt");
    archivo2 << texto;

    /*cout << "Que Producto desea eliminar? " << endl;
    cout << "Introduzca el indice del objeto: " << endl;
    int r;
    cin >> r;
    for (int i = 0; i < VecProductos.size(); i++){
        if (i == r){
            VecProductos.erase(VecProductos.begin()+i);
        }
    }
    cout << endl;*/
}

void ListaProductos::modificar(){
    if (!(VecProductos.empty())){
        cout << "Que producto desea modificar? " << endl;
        cout << "Introduzca el indice del objeto " << endl;
        int r;
        string re;
        cin >> r;
        for (int i = 0; i < VecProductos.size(); i++){
            if (i == r){
                VecProductos.at(i).imprime();
                cout << "Que desea modificar del producto?" << endl;
                cout << "nombre, marca, nSerie, precio, cantidad, categoria, todo" << endl;
                cin >> re;
                if (re == "nombre"){
                    cout << "Introduzca el nuevo nombre: " << endl;
                    cin >> re;
                    VecProductos.at(i).setnombre(re);
                    VecProductos.at(i).imprime();
                }
                if (re == "marca"){
                    cout << "Introduzca la nueva marca: " << endl;
                    cin >> re;
                    VecProductos.at(i).setmarca(re);
                    VecProductos.at(i).imprime();
                }
                if (re == "nSerie"){
                    cout << "Introduzca el nuevo nº de serie" << endl;
                    cin >> re;
                    VecProductos.at(i).setnSerie(re);
                    VecProductos.at(i).imprime();
                }
                if (re == "precio"){
                    cout << "Introduzca el nuevo precio: " << endl;
                    cin >> r;
                    VecProductos.at(i).setprecio(r);
                    VecProductos.at(i).imprime();
                }
                if (re == "cantidad"){
                    cout << "Introduzca la nueva cantidad: " << endl;
                    cin >> r;
                    VecProductos.at(i).setcantidad(r);
                    VecProductos.at(i).imprime();
                }
                if (re == "Categoria"){
                    cout << "Introduzca la nueva categoria: " << endl;
                    cin >> re;
                    VecProductos.at(i).setcategoria(re);
                    VecProductos.at(i).imprime();
                }
                if (re == "todo"){
                    cout << "Introduzca el nuevo nombre: " << endl;
                    cin >> re;
                    VecProductos.at(i).setnombre(re);
                    cout << endl;
                    cout << "Introduzca la nueva marca: " << endl;
                    cin >> re;
                    VecProductos.at(i).setmarca(re);
                    cout << endl;
                    cout << "Introduzca el nuevo nº de serie" << endl;
                    cin >> re;
                    VecProductos.at(i).setnSerie(re);
                    cout << endl;
                    cout << "Introduzca el nuevo precio: " << endl;
                    cin >> r;
                    VecProductos.at(i).setprecio(r);
                    cout << endl;
                    cout << "Introduzca la nueva cantidad: " << endl;
                    cin >> r;
                    VecProductos.at(i).setcantidad(r);
                    cout << endl;
                    cout << "Introduzca la nueva categoria: " << endl;
                    cin >> re;
                    VecProductos.at(i).setcategoria(re);
                    cout << endl;
                    VecProductos.at(i).imprime();
                }
            }
        }
    }
    else{
        cout << "La lista esta vacia" << endl;
    }
    
}

void ListaProductos::filtro(){
    cout << "Que categoria desea ver?" << endl;
    cout << "Intrduzca el tipo de categoria que quiera ver: \n Tecnologico: Tec\n Plantas: Plant \n Comida: Com" << endl;
    string r;
    cin >> r;
    for (int i = 0; i < VecProductos.size(); i++){
        if(r == VecProductos.at(i).getcategoria()){
            VecProductos.at(i).imprime();
        }
    }
}

void ListaProductos::extraer(){
    string linea;
    // Lee el archivo de texto (Si es que no existe lo crea)
    ifstream archivo("Productos.txt");
    //Lee todo el archivo y lo almacena en la variable texto
    while (getline(archivo, linea)){
        while(archivo >> nnombre >> marca >> nSerie >> Precio >> Cantidad >> Categoria){
            Producto nProducto = Producto(nnombre,marca,nSerie,Precio,Cantidad,Categoria);
            VecProductos.push_back(nProducto);
        };
        }
    archivo.close();
}

void ListaProductos::agregar2(Producto x){
    /*VecProductos.push_back(x);
    cout << endl;*/
}