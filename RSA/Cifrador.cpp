#include "Cifrador.h"
int main(){
	RSA rsa;
	cout<<"Ingrese la llave publica"<<endl;
	cin>>rsa.llave_publica.first;
	cin>>rsa.llave_publica.second;
	RSA_cifrador cifrador(rsa.llave_publica);
	cout<<"Preprocessing complete"<<endl;
	cout<<"Ingrese el mensaje"<<endl;
	cifrador.set_mensaje(ingresar_mensaje());
	cout<<"Mensaje_Ingresado"<<endl;
	cifrador.cifrar();
	rsa.cifrado=cifrador.get_cifrado();
	cout<<"El cifrado es"<<endl;
	imprimir_cifrado(rsa.cifrado);
}
