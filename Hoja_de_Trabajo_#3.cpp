#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

void ingreso_datos();
void archivo();
void eliminar();
void modificar();
void mp();

int main (){
	mp();
	ingreso_datos();
	archivo();
	eliminar();
	modificar();
	
}

void mp(){
	int x;
	do{
		system ("CLS");
		cout<<"-------------------------------------"<<"\n";
		cout<<"**MENU PRINCIPAL DE LA LIBRERIA**	"<<"\n";
		cout<<"-------------------------------------"<<"\n";
		cout<<"1.-	INGRESO DE DATOS DEL MES		"<<"\n";
		cout<<"2.-	LEER ARCHIVO					"<<"\n";
		cout<<"3.-	ELIMINAR DATOS					"<<"\n";
		cout<<"4.-	MODIFICAR DATOS					"<<"\n";
		cout<<"5.-	SALIR							"<<"\n";
		cout<<"-------------------------------------"<<"\n";
		cout<<"INGRESE LA OPCION QUE DESEA: ";
		cin>>x;
		if (x==1)
			ingreso_datos();
		else if (x==2)
			archivo();
		else if (x==3)
			eliminar();
		else if (x==4)
			modificar();
		else if (x==5)
			exit (1);
	}while (x!=5);
}

void ingreso_datos(){
	int i;
	int vector_dia[30];
	char modelo [10];
	char mes [10];
	int cantidad;
	float s1,s2,s3,s4;
	ofstream archivo;
	fflush (stdin);
	archivo.open("LIBRERIA.txt",ios::app);
	cout<<"------------------------------"<<"\n";
	cout<<" MENU DE LOS MODELOS"	  <<"\n";
	cout<<"------------------------------"<<"\n";
	cout<<"MODELO#1...............Q.10.00"<<"\n";
	cout<<"MODELO#2...............Q.15.00"<<"\n";
	cout<<"MODELO#3...............Q.18.50"<<"\n";
	cout<<"MODELO#4...............Q.25.00"<<"\n";
	cout<<"------------------------------"<<"\n";
	cout<<"INGRESO DE DATOS DEL MES DE: ";
	cin>>mes;
	cout<<"------------------------------"<<"\n";
	for (i+=1; i<=30; i++){	
		cout<<"DIA: "<<vector_dia[i]<<endl;
		cout<<"INGRESE EL MODELO QUE DESEA: ";
		cin>>modelo;
		cout<<"INGRESE LA CANTIDA DE MODELOS QUE DESEA: ";
		cin>>cantidad;
		if (modelo [10]='MODELO#1'){
		s1=cantidad*10.00;
		cout<<"EL TOTAL ES DE Q."<<s1<<endl;}
		else if (modelo [10]='MODELO#2'){
		s2=cantidad*15.00;
		cout<<"EL TOTAL ES DE Q."<<s2<<endl;}
		else if (modelo [10]='MODELO#3'){
		s3=cantidad*18.50;
		cout<<"EL TOTAL ES DE Q."<<s3<<endl;}
		else if(modelo [10]='MODELO#4'){
		s4=cantidad*25.00;
		cout<<"EL TOTAL ES DE Q."<<s4<<endl;}
	}
	try {
		archivo.open("LIBRERIA.txt",ios::app);
		archivo<<mes<<"\t"<<vector_dia<<"\t"<<modelo<<"\t"<<cantidad<<"\t"<<s1<<"\t"<<s2<<"\t"<<s3<<"\t"<<s4<<endl;
		cout<<"SE HA INGRESADO LOS DATOS...";
		archivo.close();	
	}
	catch(exception x){
		cout<<"NO SE PUEDE INTRODUCIR DATOS"<<endl;
		system ("PAUSE");
	}
}

void archivo(){
	int i;
	int vector_dia;
	char modelo;
	char mes;
	int cantidad;
	float s1,s2,s3,s4;
	float suma1,suma2,suma3,suma4;
	
	int r;
	ifstream archivo;
	fflush (stdin);
	archivo.open("LIBRERIA.txt",ios::in);
	try{
		
		cout<<"** DATOS DE LA LIBRERIA **"<<endl;
		cout<<"|	MES		|"<<"		DIA	|"<<"		MODELO		|"<<"		CANTIDAD		|"<<"		TOTAL A PAGAR		|"<<endl;
		while (archivo>>mes>>vector_dia>>modelo>>cantidad>>s1>>s2>>s3>>s4){
			cout<<setw(10)<<mes<<"|"<<setw(6)<<vector_dia<<"|"<<setw(8)<<modelo<<"|"<<setw(5)<<cantidad<<"|"<<setw(10)<<s1<<s2<<s3<<s4<<"|"<<endl;
			i++;
			suma1+=s1;
			suma2+=s2;
			suma3+=s3;
			suma4+=s4;
			cout<<"EL TOTAL RECAUDADO POR MODELO#1 ES DE Q."<<suma1;
			cout<<"EL TOTAL RECAUDADO POR MODELO#2 ES DE Q."<<suma2;
			cout<<"EL TOTAL RECAUDADO POR MODELO#3 ES DE Q."<<suma3;
			cout<<"EL TOTAL RECAUDADO POR MODELO#4 ES DE Q."<<suma4;
			if (suma1>suma2 && suma1>suma3 && suma1>suma4) 
			cout<<"EL MODELO QUE SE VENDIO FUE: MODELO#1";
			else if (suma2>suma1 && suma2>suma3 && suma2>suma4) 
			cout<<"EL MODELO QUE SE VENDIO FUE: MODELO#2";
			else if (suma3>suma2 && suma3>suma1 && suma3>suma4) 
			cout<<"EL MODELO QUE SE VENDIO FUE: MODELO#3";
			else if (suma4>suma2 && suma4>suma3 && suma4>suma1) 
			cout<<"EL MODELO QUE SE VENDIO FUE: MODELO#4";
		}
	}
    catch (exception x){
    	cout<<"ERROR EN ABRIR EL ARCHIVO"<<endl;
    	system ("PAUSE");
	}
}

void eliminar(){
	char m,mes, aux;
	int  vector_dia, flag;
	char modelo;
	int cantidad;
	float s1,s2,s3,s4;
	ifstream archivo;
	ofstream nuevo;
	remove("LIBRERIA#2.txt");
	
	archivo.open("LIBRERIA.txt",ios::in);
	nuevo.open("LIBRERIA#2.txt",ios::app);
	
	cout<<"	**INGRESE LOS DATOS QUE DESEA ELIMINAR** ";
	cout<<"INGRESE EL MES: ";
	cin>>m;
	m=toupper (m);
	cout<<"INGRESE EL DIA: ";
	cin>>aux;
	aux=toupper (aux);
	
	while (archivo>>mes>>vector_dia){
		if (aux=vector_dia){
			cout<<"REGISTRO ELIMINADO..."<<endl;
			flag=1;
		}
		else if (aux!=vector_dia){
			nuevo<<mes<<"\t"<<vector_dia<<"\t"<<modelo<<"\t"<<cantidad<<"\t"<<s1<<"\t"<<s2<<"\t"<<s3<<"\t"<<s4<<endl;
		}
	archivo.close();
	nuevo.close();
	
	if(flag==1){
		remove("LIBRERIA.txt");
		rename("LIBRERIA#2.txt","LIBRERIA.txt");
	}
	system ("PAUSE");
	}
}

void modificar(){
	ifstream archivo;
	ofstream nuevo;
	fflush (stdin);
	int vector_dia;
	char modelo,nmodelo;
	char mes;
	int cantidad;
	float s1,s2,s3,s4;
	char m, aux, resultado;
	remove ("LIBRERIA#2.txt");
	
	archivo.open("LIBRERIA.txt",ios::in);
	nuevo.open("LIBRERIA#2.txt",ios::app);
	
	cout<<" **INGRESE LOS DATOS QUE DESEA MODIFICAR** ";
	cout<<"INGRESE EL MES: ";
	cin>>m;
	m=toupper (m);
	cout<<"INGRESE EL DIA: ";
	cin>>aux;
	aux=toupper (aux);
	do{
		cout<<"INGRESE EL MODELO QUE DESEA A MODIFICAR: "<<endl;
		cin>>nmodelo;
		nmodelo=toupper(nmodelo);
		cout<<"\n\n¿ESTÁS SEGURO? SI/NO";
		cin>>resultado;
		cout<<"\n"<<endl;
		resultado= toupper(resultado);
	}
	while (resultado!='S');
	
   //leer
   while(archivo>>mes>>vector_dia>>modelo>>cantidad>>s1>>s2>>s3>>s4){
   	if (m==mes && aux==vector_dia){
   		nuevo<<mes<<"\t"<<vector_dia<<"\t"<<modelo<<"\t"<<cantidad<<"\t"<<s1<<"\t"<<s2<<"\t"<<s3<<"\t"<<s4<<endl;
   		cout<<"ARCHIVO ACTUALIZADO..."<<endl;
   		int flag=1;
	   }
	   else if (m!=mes && aux!=vector_dia){
	   	nuevo<<mes<<"\t"<<vector_dia<<"\t"<<modelo<<"\t"<<cantidad<<"\t"<<s1<<"\t"<<s2<<"\t"<<s3<<"\t"<<s4<<endl;
	   }
	archivo.close();
	nuevo.close();
   }
   int flag;
   if (flag=1){
   	remove("LIBRERIA.txt");
   	rename("LIBRERIA#2.txt", "LIBRERIA.txt");
   }
   system ("PAUSE");

}

