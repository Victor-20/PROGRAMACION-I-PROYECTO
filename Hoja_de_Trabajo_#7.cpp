#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<iomanip>

using namespace std;
struct producto{		//DEFINICION DE LA VARIABLES A UTILIZAR EN ARCHIVO//
	int codemp;
	string codigo;
	string articulo;
	string nombre;
	int minimo;
	int actual;
	string proveedor;
	float precio;
};

void insertar_datos_archivo();
void read_file();
void articulo (producto & ingreso);
void mp();

int main(){
	producto datos;
	mp();
	read_file();
	
	cout<<"MENU PRINCIPAL"<<endl;
	cout<<datos.articulo<<"\n";
	cout<<datos.codemp<<endl;
}

void articulo (producto& ingreso){
	ofstream archivo;
	string nombreArchivo;
	fflush(stdin);
	cout<<"INGRESE EL NOMBRE DEL ARCHIVO: ";
	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::app);
	if (archivo.fail())
	{
		cout<<"NO SE PUEDE ABRIR EL ARCHIVO";
		exit (1);
	}
	system("CLS");
	int minimo, actual, codemp;
	string proveedor;
	float precio;
	string nombre;
	
	cout<<"INGRESE EL CODIGO DEL ARTICULO: "<<endl;
	cin>>codemp;ingreso.codemp;
	fflush(stdin);
	cout<<"INGRESE EL NOMBRE DEL ARTICULO: "<<endl;
	getline(cin,nombre,'\n');ingreso.nombre;
	cout<<"INGRESE EL NIVEL MINIMO DE ARTICULO QUE OBTENIDO: "<<endl;
	cin>>minimo;
	cout<<"INGRESE EL NIVEL ACTUAL DE ARTICULO QUE TENEMOS: "<<endl;
	cin>>actual;
	cout<<"INGRESE EL NOMBRE DEL PROVEEDOR: "<<endl;
	cin>>proveedor;
	cout<<"INGRESE EL PRECIO DEL ARTICULO: "<<endl;
	cin>>precio;
	cout<<"-------------------------------------"<<endl;
	
	if(actual<minimo)
	{
		cout<<"PEDIR: "<<nombre;
	}
	ingreso.codemp= codemp;
	ingreso.nombre= nombre;
	ingreso.minimo= minimo;
	ingreso.actual= actual;
	ingreso.proveedor = proveedor;
	ingreso.precio= precio;
	archivo<<codemp<<"\t"<<nombre<<"\t"<<minimo<<"\t"<<actual<<"\t"<<proveedor<<"\t"<<precio<<endl;
	archivo.close();
	exit(1);
}

void mp(){
	int i;
	producto datos;
	
	do {
		system ("CLS");
		cout<<"-----------------------"<<"\n";
		cout<<"MENU PRINCIPAL"<<"\n";
		cout<<"-----------------------"<<"\n";
		cout<<"1-	INGRESAR ARTICULO"<<"\n";
		cout<<"2-	LEER ARCHIVO"<<"\n";
		cout<<"3-	REPORTE"<<"\n";
		cout<<"4-	SALIR"<<"\n";
		cout<<"-----------------------"<<"\n";
		cout<<"SELECCIONE LA OPCION QUE DESEA: ";
		cin>>i;
		if (i==1)
			articulo (datos);
		else if (i==2)
			read_file();
		else if (i==3)
			read_file();
		else if (i==4);
			exit(1);
		}
		 while (i!=4);
 }


void read_file(){
	ifstream archivo;
	string nombreArchivo;
	fflush(stdin);
	cout<<"INDIQUE EL NOMBRE DEL ARCHIVO: ";
	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::in);
	if (archivo.fail()){
		cout<<"NO SE PUEDE ABRIR EL ARCHIVO!!!";
		exit(1);
	}


int lineas;
string s;
while (getline(archivo,s))
lineas++;

archivo.close();
system("CLS");
cout<<"LINEAS: "<<lineas<<endl;
producto recordset[lineas];

archivo.open(nombreArchivo.c_str(),ios::in);
if (archivo.fail()){
	cout<<"NO SE PUDO ABRIL EL ARCHIVO!!!";
	exit(1);
}

for (int i=0; i<lineas; i++)
{
	getline(archivo, recordset[i].nombre,',');
}

for (int i=0; i<lineas; i++)
	cout<<recordset[i].codemp<<" "<<recordset[i].nombre<<" "<<recordset[i].minimo<<" "<<recordset[i].actual<<" "<<recordset[i].proveedor<<" "<<recordset[i].precio;

archivo.close();
system ("PAUSE");
exit(1);
}

void insertar_datos_archivo(){
	cout<<"INSERTANDO DATOS\n\n";
	system("PAUSE");
	system("CLS");
}
	
