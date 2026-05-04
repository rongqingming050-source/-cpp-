#include<iostream>
#include<string>
const int N=3;
using namespace std;
class student{
	public:
		student(){
			cout<<"请输入学生的学号，姓名，成绩："<<endl;
			cin>>a>>b>>c;
		}
		void show(){
			cout<<a<<"  "<<b<<"  "<<c<<endl;
		}
		int get(){
			return c;
		}
	private:
		int a,c;
		string b;
};
int add(student s[]){
	int a=0;
	for(int i=0;i<N;i++){
		a=a+s[i].get();
	}
	return a;
}
int main(){
	student s[N];
	cout<<endl<<"学生信息为："<<endl;
	for(int i=0;i<N;i++){
		s[i].show();
	} 
	int sum;
	double ave;
	sum=add(s);
	ave=sum*1.0/N;
	cout<<N<<"个学生的总分："<<sum<<endl;
	cout<<N<<"个学生的平均分为："<<ave<<endl;
	return 0; 
}
