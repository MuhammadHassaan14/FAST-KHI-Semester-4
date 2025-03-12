#include<iostream>
using namespace std;

int main(int argv, char *argc[]) {
	int num1 = atoi(argc[1]);
        int num2 = atoi(argc[3]);
        char op = argc[2][0];

        switch (op) {
            case '+': 
              cout << "Result: " << num1 + num2 << endl; 
              break;
            case '-': 
              cout << "Result: " << num1 - num2 << endl; 
              break;
            case '*': 
              cout << "Result: " << num1 * num2 << endl; 
              break;
            case '/': 
                if (num2 == 0)
                    cout << "Error: Division by zero!" << endl;
                else
                  cout << "Result: " << num1 / num2 << endl; 
                break;
            default: 
                cout << "Error: Invalid operator. Use +, -, *, /" << endl;
                return 1;
        }
	    return 0;
}
