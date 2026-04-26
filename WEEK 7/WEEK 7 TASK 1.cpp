#include<iostream>
#include<string>
using namespace std;
class calculator{
	public:
	double add ( double a, double b){
		return a+b;
	}
	
	double multiply( double a , double b){
		return a*b;
	}
};
class student{
	calculator *calculator;
	public:
	student( calculator *c){
		calculator =c;
	}
	void addition ( double a, double b){
		cout<<"Result are"<<calc->add( a, b);
	}
	
	void multiplication( double a, double b){
		cout<<"Results are"<<calc->multiply (a , b);
	}
};
 int main(){
 	calculator c1;
 	student s1(&c1);
  	student s2(&c1);
	
	s1.addition(8,3);
	s1.multiplication(6,7);
	
	s2.addition(4,3);
	s2.multiplication(2,4);
	return 0;
 }
