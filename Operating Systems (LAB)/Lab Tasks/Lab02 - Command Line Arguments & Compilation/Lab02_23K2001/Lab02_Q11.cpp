#include<iostream>
using namespace std;

int main(int argv, char *argc[]){
	int arr[argv];
	int sum = 0;
	for(int i = 1;i<argv;i++)
		sum = sum + atoi(argc[i]);
		
	cout<<"The sum of arguments passed is : "<<sum<<endl;
	return 0;
}
