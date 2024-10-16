#include<iostream>

using namespace std;
#define MAX 100
#define ERROR -1

int top, myStack[MAX];

void init(){
	top = 0;
	for (int i = 0; i < MAX; i++){
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
	top--;
	return myStack[top-1];
}

void print(){
	for (int i = 0;i < top-1; i++){
		cout << myStack[i] << " ";
	}
	cout << myStack[top-1] << endl;
}

void show(char value){
	int a;
	switch (value){
		case 'U':	cin >> a;
					push(a);
					cout << a << " "; break;
					
		case 'O':	cout << pop(); break;
		
		case 'T':	cout << peek(); break;
		
		case 'P':	print(); break;
		
		case 'N':	cout << top; break;
		}
	}
int main(){
	init();
	char c;
	cin >> c;
	while (c != 'X'){
		show(c);
		cin >> c;
	}
	
	return 0;
}