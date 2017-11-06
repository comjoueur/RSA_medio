#include"Cifrador.h"
int main(){
	RSA rsa;
	CalculoRSA cal;
	rsa.llave_publica=cal.get_llave_publica();
	rsa.llave_privada=cal.get_llave_privada();
	RSA_cifrador c(rsa.llave_publica);
	RSA_descifrador d(rsa.llave_privada);
	c.set_mensaje("hola");
	c.cifrar();
	vector<ZZ>cifrado=c.get_cifrado();
	d.set_cifrado(cifrado);
	d.descifrar();
	string p=d.get_mensaje();
	cout<<p<<endl;
}
