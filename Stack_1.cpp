#include<iostream>
#include<string.h>
using namespace std;

#define MAX 100
#define ERROR -1

int top, myStack[MAX];

void init(){
	top = 0;
	for (int i = 0;i < MAX; i++){
		myStack[i] = 0;
	}
}

void push(int value){
	if (top == MAX){
		return;
	}
	myStack[top] = value;
	top++;
}

int pop(){
	if (top == 0){
		return ERROR;
	}
	top--;
	return myStack[top];
}

int peek(){
	if (top == 0){
		return ERROR;
	}
	return myStack[top-1];
}
void print(){
	for (int i = 0; i <= top-1; i++){
		cout << myStack[i] << " ";
	}
	cout << endl;
}

void func(char a){
	int x;
	switch(a){
		case 'U':
			cin >> x;
			push(x);
			break;
		case 'O':
			cout << pop() << endl;
			break;
		case 'T':
			cout << mystack[top-1] << endl;
			break;
		case 'P':
			print();
			break;
		case 'N':
			cout << top << endl;
	}
}

int main(){
	init();
	char a;
	cin >> a;
	while (a != 'X'){
		func(a);
		cin >> a;
	}
	
}