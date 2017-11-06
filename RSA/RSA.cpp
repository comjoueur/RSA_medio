#include<NTL/ZZ.h>
#include<vector>
using namespace std;
using namespace NTL;
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
ZZ Random_prime(long long b=2048){
	ZZ a=RandomPrime_ZZ(b);
	return a;
}
ZZ Random(long long b=2048){
	ZZ a=RandomBits_ZZ(b);
	return a;
}
ZZ Coprime(ZZ a){
	ZZ e;
	do {e=Random_prime(13);}
	while(Eucli(e,a)!=1);
	return e;
}
vector<ZZ>Bloque(vector<ZZ>vec){
	vector<ZZ>nuevo;
	for(int i=0;i<vec.size();i++){
		int j=0;
		ZZ u=ZZ(0);
		for(j=0;j<10 and i+j<vec.size();j++){
			u=u*ZZ(1543)+ZZ(vec[i+j]);
			cout<<i+j<<" ";
		}
		nuevo.push_back(u);
		i+=j-1;
	}
	cout<<endl;
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
void imprimir(vector<ZZ>vec){
	for(int i=0;i<vec.size();i++)cout<<vec[i]<<" ";cout<<endl;
}
int main(){
	ZZ a=Random_prime();
	ZZ b=Random_prime();
	ZZ n=a*b;
	ZZ r=(a-1)*(b-1);
	ZZ e=Coprime(r);
	ZZ d=Div_mod(e,r);
	string p;
	cin>>p;
	imprimir(caracter(p));
	imprimir(Bloque(caracter(p)));
	imprimir(Desbloque(Bloque(caracter(p))));
	cout<<numero(Desbloque(Bloque(caracter(p))))<<endl;
	ZZ x=ZZ(54);
	ZZ cifrado=Expo_mod(x,e,n);
	cout<<cifrado<<endl;
	ZZ descifrado=Expo_mod(cifrado,d,n);
	cout<<descifrado<<endl;
}
