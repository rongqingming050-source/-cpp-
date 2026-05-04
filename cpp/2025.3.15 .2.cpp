#include<iostream>
#include<string>
using namespace std;
class student{
	protected:
		string no,name;
		int score;
	public:
	    student(string n,string nam,int s){
	    	no=n,name=nam,score=s;
		}
		student(){
			cout<<"请输入学号，名字，成绩："<<endl;
			cin>>no>>name;
			cin>>score;
		}
		void print(){
			cout<<"学号："<<no<<" "<<"名字："<<name<<" "<<"成绩："<<score<<endl;
		} 
		~student(){
			cout<<"~student  "<<"学号："<<no<<" "<<"名字："<<name<<" "<<"成绩："<<score<<endl;
		}
};
class Ustudent:public student{
	protected:
		string major;
	public:
		Ustudent(string x,string y,int z,string m):student(x,y,z){
			major=m;
		}
		Ustudent(){
			cout<<"请输入专业："<<endl;
			cin>>major;
		}
		void print(){
			student::print();
			cout<<"专业："<<major<<endl; 
		}
		~Ustudent(){
			cout<<"~Ustudent "<<"专业："<<major<<endl;
		}
};
int main(){
	Ustudent s("1001","张三",95,"信息"),t;
	s.print();
	t.print();
	return 0;
}

