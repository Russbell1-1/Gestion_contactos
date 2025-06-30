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

void mostrarContactos(contactoEmail contactos[],int n){
	for(int i=0;i<n;i++){
		cout<<"Nombre: "<<contactos[i].nombre<<endl;
		cout<<"Sexo: "<<contactos[i].sexo<<endl;
		cout<<"Edad: "<<contactos[i].edad<<endl;
		cout<<"Telefono: "<<contactos[i].telefono<<endl;
		cout<<"Email: "<<contactos[i].email<<endl;
		cout<<"Nacionalidad: "<<contactos[i].nacionalidad<<endl<<endl;
	}
}

string obtenerDominio(string correo){
	int pos=correo.find('@');
	if(pos!=-1)return correo.substr(pos+1);
	return "";
}

void mostrarOrdenadoPorDominio(contactoEmail contactos[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(obtenerDominio(contactos[i].email)>obtenerDominio(contactos[j].email)){
				contactoEmail temp=contactos[i];
				contactos[i]=contactos[j];
				contactos[j]=temp;
			}
		}
	}
	mostrarContactos(contactos,n);
}

int main(){
	contactoEmail contactos[100];
	int n=0,op;
	do{
		cout<<"1. Agregar contacto\n2. Eliminar contacto\n3. Mostrar contactos\n4. Mostrar ordenado por servidor\nOpcion: ";
		cin>>op;
		switch(op){
			case 1:agregarContacto(contactos,n);break;
			case 2:eliminarContacto(contactos,n);break;
			case 3:mostrarContactos(contactos,n);break;
			case 4:mostrarOrdenadoPorDominio(contactos,n);break;
		}
	}while(true);
	return 0;
}
