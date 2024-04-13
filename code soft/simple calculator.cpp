#include <iostream>

using namespace std;

int main()
{
	float num1;
	float num2;
	int choose;
	cout<<"Welcome Have A Nice Day"<<endl;
	cout<<"Please choose the operation "<<endl;
	cout<<"Addition : 1"<<endl;
	cout<<"Substraction : 2"<<endl;
	cout<<"Multiplication : 3"<<endl;
	cout<<"Division : 4"<<endl;
	cin>>choose;
	cout<<"Enter a First number : ";
	cin>>num1;
	cout<<"Enter a Second number : ";
	cin>>num2;
	switch(choose)
	{
		case 1:
			cout<<"Addition of Two Number is : "<<(num1+num2)<<endl;
			break;
		case 2:
			cout<<"Substraction of Two Number is : "<<(num1-num2)<<endl;
			break;
		case 3:
			cout<<"Multiplication of Two Number is : "<<(num1*num2)<<endl;
			break;
		case 4:
			cout<<"Division of Two Number is : "<<(num1/num2)<<endl;
			break;
		default:
			cout<<"Invalid Choose";
	}
	return 0;
}
