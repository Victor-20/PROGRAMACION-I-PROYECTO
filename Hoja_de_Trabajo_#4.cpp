#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

struct poblacion{
	int edad;
	char nombre [10];
	char genero [10];
	int peso, altura;
};

void datos();
void ver();
void mp();
void seleccionsort();

int main(){
	mp();
	datos();
	ver();
}

void mp(){
	int x;
	do{
		system ("CLS");
		cout<<"-----------------------------"<<"\n";
		cout<<"	MENU PRINCIPAL DE   	"<<"\n";
		cout<<"	 LA PROBLACION	   		"<<"\n";
		cout<<"-----------------------------"<<"\n";
		cout<<"1.-	INGRESO DE DATOS		"<<"\n";
		cout<<"2.-	LEER DATOS				"<<"\n";
		cout<<"3.-	SALIR					"<<"\n";
		cout<<"-----------------------------"<<"\n";
		cout<<"INGRESE LA OPCION QUE DESEA: ";
		cin>>x;
		if (x==1)
			datos();
		else if (x==2)
			ver();
		else if (x==3)
			exit (1);
	} while (x!=3);
}

void datos(){
	ofstream archivo;
	archivo.open("POBLACION.txt",ios::app);	
	int edad;
	char nombre [10];
	char genero [10];
	int peso, altura;
	system ("CLS");
	cout<<"--------------------------------------"<<endl;
	cout<<" **INGRESO DE DATOS DE LA POBLACION** "<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"INGRESE LA EDAD: ";
	cin>>edad;
	cout<<"INGRESE SU NOMBRE: ";
	cin>>nombre;
	cout<<"INGRESE SU GENERO: ";
	cin>>genero;
	cout<<"INGRESE SU PESO: ";
	cin>>peso;
	cout<<"INGRESE SU ALTURA: ";
	cin>>altura;
	archivo.open("POBLACION.txt",ios::app); 
		archivo<<edad<<"\t"<<nombre<<"\t"<<genero<<"\t"<<peso<<"\t"<<altura<<endl;
		cout<<"SE HA INGRESADO LOS DATOS..."<<endl;
		archivo.close();
		system ("PAUSE");
		exit (1);
}

void ver(){
ifstream archivo;
archivo.open("POBLACION.txt",ios::in);
int edad;
char nombre, genero;
int peso, altura;
cout<<" **DATOS DE LA LIBRERIA** "<<endl;
cout<<"|	EDAD	|"<<"	NOMBRE		|"<<"	GENERO	|"<<"	PESO	|"<<"	ALTURA	|"<<endl;
		while (archivo>>edad>>nombre>>genero>>peso>>altura){
			cout<<setw(2)<<edad<<"|"<<setw(2)<<nombre<<"|"<<setw(2)<<genero<<"|"<<setw(5)<<peso<<"|"<<setw(5)<<altura<<"|"<<endl;
	if (edad<5)
		cout<<edad<<" ";
	else if (edad<10)
		cout<<edad<<" ";
	else if (edad<20)
		cout<<edad<<" ";
	else if (edad<30)
		cout<<edad<<" ";
	else if (edad<40)
		cout<<edad<<" ";
	else if (edad<50)
		cout<<edad<<" ";
	else if (edad<60)
		cout<<edad<<" ";
	else if (edad<70)
		cout<<edad<<" ";
	else if (edad<80)
		cout<<edad<<" ";
	else if (edad<90)
		cout<<edad<<" ";
	else if (edad<100)
		cout<<edad<<" ";


}
}


