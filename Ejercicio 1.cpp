#include<iostream>
#include<string>
using namespace std;

struct contactoEmail{
	string nombre,sexo,telefono,email,nacionalidad;
	int edad;
};

void eliminarContacto(contactoEmail contactos[],int &n){
	if(n==0)return;
	string correo;
	cout<<"Ingrese el email del contacto a eliminar: ";
	cin>>correo;
	for(int i=0;i<n;i++){
		if(contactos[i].email==correo){
			for(int j=i;j<n-1;j++){
				contactos[j]=contactos[j+1];
			}
			n--;
			break;
		}
	}
}

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
		cout<<"1. Agregar contacto\n2. Eliminar un contacto\nOpcion: ";
		cin>>op;
		switch(op){
			case 1:agregarContacto(contactos,n);break;
			case 2:eliminarContacto(contactos,n);break;
		}
	}while(true);
	return 0;
}
