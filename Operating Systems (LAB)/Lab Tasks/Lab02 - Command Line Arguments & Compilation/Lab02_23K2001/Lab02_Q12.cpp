#include<iostream>
using namespace std;

int main(int argv, char *argc[]){
	int c = 0;
	for(int i=0;argc[1][c]!='\0';i++)
		c++;
	for(int i=0;i<c;i++){
		if(argc[1][i]!=argc[1][c-i-1]){
			cout<<"This string is not a palindrome"<<endl;
			return 0;
		}
	}
	cout<<"This string is a palindrome!"<<endl;	
	return 0;
}
