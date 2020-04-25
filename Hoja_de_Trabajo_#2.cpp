#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<iomanip>

using namespace std;

struct zona{
	char nombre;
	char categoria;
	int edad;
};

void datos();
void read_file();
void mp();

int main(){
	mp();
	read_file();
	datos();
}

void mp(){
	int i;
	
	do{
		system ("CLS");
		cout<<"-------------------------------------------------"<<"\n";
		cout<<"MENU PRINCIPAL ESTADISTICA POBLACIONAL DE LA ZONA"<<"\n";
		cout<<"-------------------------------------------------"<<"\n";
		cout<<"1.-	INGRESO DE DATOS.							"<<"\n";
		cout<<"2.-	ABRIR ARCHIVO.								"<<"\n";
		cout<<"3.-	SALIR.										"<<"\n";
		cout<<"-------------------------------------------------"<<"\n";
		cout<<"INGRESE LA OPCION QUE DESEA: ";
		cin>>i;
		if (i==1)
			datos();
		else if (i==2)
			read_file();
		else if (i==3)
			exit (1);
	}
	while (i!=3);
}

void datos(){
	ofstream archivo;
	string nombreArchivo;
	fflush (stdin);
	cout<<"INGRESE EL NOMBRE DEL NUEVO ARCHIVO: ";
	getline (cin, nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::app);
	if (archivo.fail()){
		cout<<"NO SE PUEDE CREAR EL ARCHIVO";
		exit (1);
	}
	system ("CLS");
	string nombre;
	char categoria;
	int edad;
	cout<<"-----------INGRESO DE DATOS---------------"<<endl;
	cout<<"INGRESE SU NOMBRE: ";
	getline (cin, nombre);
	cout<<"INGRESE SU EDAD: ";
	cin>>edad;
	if (edad<=12){
		categoria='Niños';
		cout<<"Entra en la categoria de: NIÑOS"<<endl;
	}
	else if (edad>=13 && edad<=29){
		categoria='Jovenes';
		cout<<"Entra en la categoria de: JOVENES"<<endl;
	}
	else if (edad>=30 && edad<=59){
		categoria='Adultos';
		cout<<"Entra en la categoria de: ADULTOS"<<endl;
	}
	else if (edad>=60){
		categoria='Adultos Mayores';
		cout<<"Entra en la categoria de: ADULTOS MAYORES"<<endl;
	}
	else {
		cout<<"ERROR"<<endl;
	}
	archivo<<nombre<<"\t"<<edad<<"\t"<<categoria<<endl;
	cout<<"SE HA GUARDADO LOS DATOS"<<endl;
	exit (1);
	
	if (archivo.fail()){
		cout<<"NO SE HA GUARDADO LOS DATOS"<<endl;
		exit (1);
	}
}

void read_file(){
	int edad;
	float a,b,c,d,e=0;
	float sumatotal=0;
	float e1=0;
	float e2=0;
	float e3=0;
	float e4=0;
	ifstream archivo;
	string nombreArchivo;
	fflush (stdin);
	cout<<"INGRESE EL NOMBRE DEL ARCHIVO: ";
	getline (cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::in);
	if (archivo.fail()){
		cout<<"NO SE PUEDE ABRIR EL ARCHIVO";
		exit (1);
	}
	while (archivo>>a>>b>>c>>d>>e){
		sumatotal=e+sumatotal;
		if (edad<=12)
		e1+=e;
		else if (edad>=13 && edad<=29)
		e2+=e;
		else if (edad<=30 && edad<=59)
		e3+=e;
		else if (edad>=60)
		e4+=e;
	}
	archivo.close();
	cout<<"TOTAL DE INGRESADOS: "<<sumatotal;
	cout<<"--------------------------------"<<endl;
	cout<<"CATEGORIAS DE LOS HABITANTES	   "<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"NIÑOS:				"<<e1<<endl;
	cout<<"JOVENES:				"<<e2<<endl;
	cout<<"ADULTOS:				"<<e3<<endl;
	cout<<"ADULTOS MAYORES:		"<<e4<<endl;
	
	if (archivo.fail()){
		cout<<"ERROR PARA ABRIR EL ARCHIVO";
		exit (1);
	}
}

