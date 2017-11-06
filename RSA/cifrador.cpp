#include"Operaciones_matematicas_rsa.h"
vector<ZZ> cifrar(string palabra,ZZ e,ZZ a,ZZ b){
	ZZ n=a*b;
	ZZ r=(a-1)*(b-1);
	ZZ d=Div_mod(e,r);	
	vector<ZZ>vec=Bloque(caracter(palabra));
	for(int i=0;i<vec.size();i++)vec[i]=Expo_mod(vec[i],e,n);
	return vec;
}
string descifrar(vector<ZZ>vec,ZZ e,ZZ a,ZZ b){
	ZZ n=a*b;
	ZZ r=(a-1)*(b-1);
	ZZ d=Div_mode(e,r);
	for(int i=0;i<vec.size();i++)vec[i]=Expo_mod(vec[i],d,n);
	string palabra=numero(Desbloque(vec));
	return palabra;
}
