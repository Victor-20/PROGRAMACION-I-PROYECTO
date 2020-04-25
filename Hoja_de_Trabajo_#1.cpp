#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<iomanip>

using namespace std;

struct cuchumatanes{
	int tipo;
	char servicio;
	float costo, costo1, costo2, costo3;
	int hectaria;
};

void venta();
void read_file();
void mp();

int main(){
	mp();
	venta();
	read_file();

}

void mp(){
	int i;
	
	do{
		system ("CLS");
		cout<<"-------------------------------------------------"<<"\n";
		cout<<"		MENU DE LA COMPAÑIA XTERMINIO S.A.			"<<"\n";
		cout<<"-------------------------------------------------"<<"\n";
		cout<<"1.-	INGRESAR FUMIGACION.						"<<"\n";
		cout<<"2.-	ABRIR ARCHIVO.								"<<"\n";
		cout<<"3.-	SALIR.										"<<"\n";
		cout<<"-------------------------------------------------"<<"\n";
		cout<<"INGRESE LA OPCION QUE DESEA: ";
		cin>>i;
		if (i==1)
			venta();
		else if (i==2)
			read_file();
		else if (i==3)
			exit (1);
	}
	while (i!=3);
}

void venta(){
	ofstream archivo;
	string nombreArchivo;
	fflush (stdin);
	cout<<"INGRESE EL NOMBRE DEL NUEVO ARCHIVO: ";
	getline (cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::app);
	if (archivo.fail()){
		cout<<"NO SE PUEDE CREAR ARCHIVO";
		exit(1);
	}
	system ("CLS");
	int tipo;
	char servicio;
	float costo, costo1, costo2,costo3;
	int hectaria;
	cout<<"------------INGRESO DE DATOS--------------"<<endl;
	cout<<"INGRESE EL NUMERO DEL TIPO DE FUMIGACION: "<<endl;
	cin>>tipo;
	if (tipo==1)
	cout<<"EL SERVICIO QUE SE VA A REALIZAR ES DE: Mala Hierba"<<endl;
	servicio='Mala Hierba';
	if (tipo==2)
	cout<<"EL SERVICIO QUE SE VA A REALIZAR ES DE: Langostas"<<endl;
	servicio='Langostas';
	if (tipo==3)
	cout<<"EL SERVICIO QUE SE VA A REALIZAR ES DE: Gusanos"<<endl;
	servicio='Gusanos';
	if (tipo==4)
	cout<<"EL SERVICIO QUE SE VA A REALIZAR ES DE: Mala Hierba, Langostas y Gusanos"<<endl;
	servicio='Mala Hierba, Langostas y Gusanos';
	cout<<"INGRESE CUANTOS HECTARIAS SE VA A FUMIGAR: "<<endl;
	cin>>hectaria;
	if (tipo==1)
	costo=10.00*hectaria;
	cout<<"EL COSTO DEL SERVICIO ES DE: "<<costo<<endl;
	if (tipo==2)
	costo=20.00*hectaria;
	cout<<"EL COSTO DEL SERVICIO ES DE: "<<costo<<endl;
	if (tipo==3)
	costo=30.00*hectaria;
	cout<<"EL COSTO DEL SERVICIO ES DE: "<<costo<<endl;
	if (tipo==4)
	costo=50.00*hectaria;
	cout<<"EL COSTO DEL SERVICIO ES DE: "<<costo<<endl;
	if (hectaria>=500)
	costo1=costo-0.05;
	cout<<"TOTAL A PAGAR: "<<costo1<<endl;
	if (costo>=1500)
	costo2=costo-0.10;
	cout<<"TOTAL A PAGAR: "<<costo2<<endl;
	if (hectaria>=500 && costo<=1500)
	costo3=costo-0.15;
	
	cout<<"TOTAL A PAGAR: "<<costo1<<endl;
	cout<<"TIPO: "<<tipo<<endl<<"SERVICIO: "<<servicio<<endl<<"HECTARIA: "<<hectaria<<endl<<"SUBTOTAL: "<<costo<<endl<<"TOTAL A PAGAR: "<<costo1<<costo2<<costo3<<endl;
	archivo<<tipo<<"\t"<<servicio<<"\t"<<hectaria<<"\t"<<costo<<"\t"<<costo1<<"\t"<<costo2<<"\t"<<costo3<<endl;
	archivo.close();
	cout<<"SE HA GUARDADO LOS DATOS"<<endl;
	exit(1);
	
	if (archivo.fail()){
			cout<<"NO SE PUEDO GRABAR LOS DATOS"<<endl;
			exit(1);
			}

}

void read_file(){
	float a,b,c,d,e=0;
	float sumatotal=0;
	float t1=0;
	float t2=0;
	float t3=0;
	float t4=0;
	ifstream archivo;
	string nombreArchivo;
	fflush (stdin);
	cout<<"INGRESE EL NOMBRE DEL ARCHIVO: ";
	getline (cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::in);
	if (archivo.fail()){
		cout<<"NO SE PUDO ABRIR EL ARCHIVO";
		exit(1);
	}
	while (archivo>>a>>b>>c>>d>>e){
		sumatotal=e+sumatotal;
		if (a==1)
		t1+=e;
		else if (a==2)
		t2+=e;
		else if (a==3)
		t3+=e;
		else if (a==4)
		t4+=e;
	}
	archivo.close();
	
	cout<<setprecision(5)<<"TOTAL DE VENTA:		"<<sumatotal<<endl;
	cout<<"LISTADO DE FUMIGACION: "<<endl;
	cout<<setprecision(5)<<"MALA HIERBA "<<t1<<"% SOBRE EL TOTAL: "<<setprecision(3)<<t1*100/sumatotal<<endl;
	cout<<setprecision(5)<<"LANGOSTAS "<<t2<<"% SOBRE EL TOTAL: "<<setprecision(3)<<t2*100/sumatotal<<endl;
	cout<<setprecision(5)<<"GUSANOS "<<t3<<"% SOBRE EL TOTAL: "<<setprecision(3)<<t3*100/sumatotal<<endl;
	cout<<setprecision(5)<<"FUMIGACION COMPLETA "<<t4<<"% SOBRE EL TOTAL: "<<setprecision(3)<<t4*100/sumatotal<<endl;

	if (archivo.fail()){
		cout<<"ERROR PARA ABRIR EL ARCHIVO"<<endl;
		exit(1);
	}
	
}
