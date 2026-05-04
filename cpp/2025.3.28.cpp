#include<iostream>
using namespace std;
class container{
	public:
		void seta(int x,int y=0){
			a=x;
			b=y;
		}
	virtual void show()=0;
	protected:
		int a,b;
};
class sphere:public container{
	public:
		void show(){
			cout<<"表面积："<<4*3.14*a*a<<endl;
			cout<<"体积："<<(4/3.0)*3.14*a*a*a<<endl;
		}
};
class cylinder:public container{
	public:
		void show(){
			cout<<"表面积："<<2*3.14*a*b + 2*3.14*a*a<<endl;
			cout<<"体积："<<3.14*a*a*b<<endl;
		}
};
class cube:public container{
	public:
		void show(){
			cout<<"表面积："<<a*a*6<<endl;
			cout<<"体积："<<a*a*a<<endl;
		}
};
int main(){
	container *p;
	sphere a;
	cylinder b;
	cube c;
	a.seta(10);
	b.seta(10,10);
	c.seta(10);
	p=&a;
	p->show();
	p=&b;
	p->show();
	p=&c;
	p->show();
	return 0;
}
