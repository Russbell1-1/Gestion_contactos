#include<iostream>
#include<string>
using namespace std;

struct contactoEmail{
	string nombre,sexo,telefono,email,nacionalidad;
	int edad;
};

void agregarContacto(contactoEmail contactos[],int &n){
	if(n<100){
		cout<<"Nombre completo: ";
		getline(cin>>ws,contactos[n].nombre);
		cout<<"Sexo: ";
		getline(cin,contactos[n].sexo);
		cout<<"Edad: ";
		cin>>contactos[n].edad;
		cout<<"Telefono: ";
		cin>>contactos[n].telefono;
		cout<<"Email: ";
		cin>>contactos[n].email;
		cout<<"Nacionalidad: ";
		cin>>contactos[n].nacionalidad;
		n++;
	}
}

int main(){
	contactoEmail contactos[100];
	int n=0,op;
	do{
		cout<<"1. Agregar contacto\nOpcion: ";
		cin>>op;
		switch(op){
			case 1:agregarContacto(contactos,n);break;
		}
	}while(true);
	return 0;
}
