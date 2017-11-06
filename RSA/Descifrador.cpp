#include"Cifrador.h"
int main(){
	RSA rsa;
	cout<<"Ingrese la llave privada"<<endl;
	cin>>rsa.llave_privada.first;
	cin>>rsa.llave_privada.second;
	RSA_descifrador descifrador(rsa.llave_privada);
	cout<<"Preprocessing complete"<<endl;
	cout<<"Ingrese el cifrado"<<endl;
	rsa.cifrado=ingresar_cifrado();
	descifrador.set_cifrado(rsa.cifrado);
	cout<<"Cifrado Ingresado"<<endl;
	descifrador.descifrar();
	rsa.mensaje=descifrador.get_mensaje();
	cout<<"El mensaje es:"<<endl;
	imprimir_mensaje(rsa.mensaje);
}
