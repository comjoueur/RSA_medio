#include<NTL/ZZ.h>
#include<vector>
using namespace std;
using namespace NTL;
ZZ Random_prime(long long b=2048){
	ZZ a=RandomPrime_ZZ(b);
	return a;
}
ZZ Eucli(ZZ a,ZZ b){
	if(b>a){
		ZZ tmp=a;
		a=b;
		b=tmp;
	}
	if(b==ZZ(0)) return a;
	else return Eucli(b,a%b);
}
ZZ Div_mod(ZZ a,ZZ b,ZZ m=ZZ(0),ZZ x1=ZZ(1),ZZ x2=ZZ(0),ZZ y1=ZZ(0),ZZ y2=ZZ(1),bool t=1,ZZ d=ZZ(0)){
	if(t) {m=Eucli(a,b);d=b;}
	if(b==m) return y1%d;
	ZZ c=a/b;
	return Div_mod(b,a%b,m,y1,y2,x1-(c*y1),x2-(c*y2),0,d);
}
ZZ Expo_mod(ZZ a,ZZ b,ZZ c){
	if(b==ZZ(0))return ZZ(1);
	ZZ d=Expo_mod(a,b/2,c);
	if(b%ZZ(2)==0)  return (d*d)%c;
	else  return (((d*d)%c)*a)%c;
}
vector<ZZ>Bloque(vector<ZZ>vec){
	vector<ZZ>nuevo;
	for(int i=0;i<vec.size();i++){
		int j=0;
		ZZ u=ZZ(0);
		for(j=0;j<10 and i+j<vec.size();j++){
			u=u*ZZ(1543)+ZZ(vec[i+j]);
		}
		nuevo.push_back(u);
		i+=j-1;
	}
	return nuevo;
}
vector<ZZ> Desbloque(vector<ZZ>vec){
	vector<ZZ>nuevo;
	for(int i=0;i<vec.size();i++){
		vector<ZZ>res;
		while(vec[i]>ZZ(0)){ 
			res.push_back(vec[i]%ZZ(1543));
			vec[i]/=ZZ(1543);
		}
		for(int j=res.size()-1;j>=0;j--)nuevo.push_back(res[j]);
	}
	return nuevo;
}
vector<ZZ> caracter(string p){
	vector<ZZ>nuevo;
	for(int i=0;i<p.size();i++) nuevo.push_back(ZZ(int(p[i])));
	return nuevo;
}
string numero(vector<ZZ>n){
	string u;
	for(int i=0;i<n.size();i++) {
		int y=conv<int>(n[i]);
		u+=char(y);
	}
	return u;
}
string ingresar_mensaje(){
	string t;
	getline(cin,t);
	string oracion;
	getline(cin,oracion);
	string h;
	int k=0;
	while(oracion[k]!='\0')h+=oracion[k++];
	return h;
}
vector<ZZ> ingresar_cifrado(){
	string h=ingresar_mensaje();
	ZZ x=ZZ(0);
	vector<ZZ>cifrado;
	for(int i=0;i<h.size();i++){
		if(h[i]!=' '){
			int y=h[i];
			y-=48;
			x=x*ZZ(10)+ZZ(y);
		}
		if(h[i]==' ' or i==h.size()-1){
			cifrado.push_back(x);
			x=ZZ(0);
		}
	}
	return cifrado;
}
void imprimir_cifrado(vector<ZZ>cifrado){
	for(int i=0;i<cifrado.size();i++){
		cout<<cifrado[i];
		if(i==cifrado.size()-1)cout<<endl;
		else cout<<" ";
	}
}
void imprimir_mensaje(string mensaje){
	cout<<mensaje<<endl;
}
