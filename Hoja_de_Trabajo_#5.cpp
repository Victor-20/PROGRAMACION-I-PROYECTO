#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<iomanip>

using namespace std;

void datos();
void abrir_archivo();
void mp();

struct trabajadores{
	int codigo[10];
	char nombre;
	char puesto;
	char departamento;
	float salario;
	
};

int main (){
	mp();
	datos();
	abrir_archivo();
}

void mp(){
	int a;
	do{
		system ("CLS");
		cout<<"-----------------------------"<<"\n";
		cout<<"MENU PRINCIPAL"<<"\n";
		cout<<"-----------------------------"<<"\n";
		cout<<"1.-	INGRESAR EMPLEADO"<<"\n";
		cout<<"2.-	LEER ARCHIVO"<<"\n";
		cout<<"3.-	SALIR"<<"\n";
		cout<<"-----------------------------"<<"\n";
		cout<<"INGRESE LA OPCION QUE DESEA: ";
		cin>>a;
		if (a==1)
			datos();
		else if (a==2)
			abrir_archivo();
		else if (a==3)
			exit (1);
	}while (a!=3);
}

void datos(){
	ofstream archivo;
	archivo.open("EMPLEADOS_NUEVOS.txt",ios::app);
	int codigo[10];
	char nombre;
	char puesto;
	char departamento;
	float salario;
	int total;
	cout<<"-----------------------------"<<endl;
	cout<<" INGRESO DE DATOS..."<<endl;
	cout<<"-----------------------------"<<endl;
	for(int i=0; i>30; i++){
	cout<<"INGRESE EL CODIGO: ";
	cin>>codigo[i];
	cin.ignore();
	cout<<"INGRESE EL NOMBRE: ";
	cin>>nombre;
	cin.ignore();
	cout<<"INGRESE EL PUESTO: ";
	cin>>puesto;
	cin.ignore();
	cout<<"INGRESE EL DEPARTAMENTO: ";
	cin>>departamento;
	cin.ignore();
	cout<<"INGRESE EL SALARIO: Q.";
	cin>>salario;
	cin.ignore();
}
try{
	archivo.open("EMPLEADOS_NUEVOS.txt",ios::app);
	archivo<<codigo<<"\t"<<nombre<<"\t"<<puesto<<"\t"<<departamento<<"\t"<<salario<<endl;
	archivo.close();
	
}
catch (exception &X){
	cout<<"NO SE HA PODIDO INGRESAR LOS DATOS..."<<endl;
	exit(1);
}

}

void abrir_archivo(){
	ifstream archivo;
	archivo.open("EMPLEADOS_NUEVOS.txt",ios::in);
	int codigo[10];
	char nombre;
	char puesto;
	char departamento;
	float salario;
	cout<<"DATOS DEL ARCHIVO..."<<endl;
	cout<<"CODIGO |"<<"	NOMBRE	|"<<" PUESTO	|"<<" DEPARTAMENTO	|"<<" SALARIO	|"<<endl;
	while (archivo>>codigo>>nombre>>puesto>>departamento>>salario){
	cout<<setw(03)<<codigo<<"|"<<setw(10)<<nombre<<"|"<<setw(10)<<puesto<<"|"<<setw(15)<<departamento<<"|"<<setw(15)<<endl;	
	archivo.close();
	
	nombre * departamento;
	departamento= new nombre;
	
	departamento->nombre= "NUEVOS EMPLEADOS";
	departamento->codigo=1;
	departamento->salario=2500.00;
	
	cout<<"BASE DE DATOS: |"<<departamento->codigo <<"|"<<departamento->nombre<<"|"<<departamento->salario<<endl;
	delete departamento;
	}

	system ("PAUSE");
	}


