#include<iostream>
#include<cstdlib>
using namespace std;
class time{
	public:
		time(int a=0,int b=0,int c=0){
			h=a,m=b,s=c;
			cout<<"请输入时，分和秒："<<endl<<h<<" "<<m<<" "<<s<<endl;
			if(h<0||m<0||s<0){
				cout<<"输入出错"<<endl;
				cout<<"0"<<":"<<"0"<<":"<<"0"<<endl;
			} 
		}
		void show(){
			cout<<endl;
			cout<<h<<":"<<m<<":"<<s<<endl;
		}
		void increase(int x,int y,int z){
			s=s+z;
			m=m+s/60+y;
			h=h+m/60+x;
			s=s%60;
			m=m%60;
			}
	private:
		int h,m,s;
};
int main(){
	time t1,t2(1,59,59),t3(-1,-1,-1);
	t1.show();
	t2.show();
	
	t2.increase(0,0,1);
	t2.show();
	
	t2.increase(12,100,100);
	t2.show();
	return 0;
}
