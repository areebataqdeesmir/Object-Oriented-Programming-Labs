#include<iostream>
using namespace std;
class display{
	double lastvalue;
	public:
	display(){
		lastvalue=0.0;
	}
     void show(double value){
     	lastvalue=value;
	 }
	 double getlastvalue() const{
	 	return lastvalue;
	 }
};

class calculator{
	display screen;
	public:
		calculator(){
		}
	 
	 void add( double a, double b){
	 	double result= a+b;
	 	screen.show( result);
	 }
	 void multiply( double a, double b){
	 	double result= a*b;
	 	screen.show( result);
	 }
	 void showpreviousresult() const{
	cout<<" Previous results are"<<screen.getlastvalue()<<endl;
	 	
	 }
};
int main(){
	calculator calc;
	calc.add( 5, 7);
	calc.multiply(3,2);
	calc.showpreviousresult();
	return 0;
}
