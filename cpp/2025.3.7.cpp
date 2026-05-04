#include<iostream>
#include<string>
using namespace std;
class score{
	public:
		score(){
			cout<<"请输入语数英成绩"<<endl;
			cin>>a>>b>>c; 
		}
		int geta(){return a;}
		int getb(){return b;}
		int getc(){return c;}
	private:
		double a,b,c;
};
class student{
	public:
		student(){
			cout<<"输入姓名，学号："<<endl;
			cin>>a>>b;
		}
		void show(score s){
			cout<<a<<"  "<<b<<"  "<<"英语："<<s.geta()<<"中文："<<s.getb()<<"数学:"<<s.getc(); 
		}
	private:
		string a,b;
};
int main(){
	score a;
	student s;
	s.show(a);
	return 0;
}
