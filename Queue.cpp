#include<iostream>
using namespace std;
#define MAX 15

int array[MAX],head,tail;

int getNumberofElement(){
	return (tail < head) ? (tail + MAX) - head : tail - head;
}

bool isFull(){
	int numberofElement = getNumberofElement();
	if (numberofElement == MAX-1){
		return true;
	}else{
		return false;
	}
}

void init(){
	if(isFull()){
		return;
	}
	head = 0;
	tail = 0;
}

void enqueue(int x){
	array[tail] = x;
	tail = (tail+1) % MAX;
}

bool isEmpty(){
	int numberofElement = getNumberofElement();
	if (numberofElement == 0){
		return true;
	}else{
		return false;
	}
}

int dequeue(){
	if (isEmpty()){
		return -1;
	}
	int x = array[head];
	head = (head+1) % MAX;
	return x;
}
void print(){
	//cout << "head : " << head << endl;
	//cout << "tail : " << tail << endl;
	int numberofElement = getNumberofElement();
	for (int i = head,n=0; i < numberofElement;n++){
		cout << array[i] << " ";
		i = (i + 1) % MAX;
	}
	cout << endl;
}

void show(char a){
	int z;
	switch (a){
		case 'e':
			cin >> z;
			enqueue(z);
			break;
		case 'd':
			cout << dequeue() << endl;
			break;
		case 'p':
			print();
			break;
		case 'n':
			cout << getNumberofElement() << endl;
			break;
		case 's':
			cout << array[head] << " " << array[tail-1] << endl;
	}
}
int main(){
	init();
	char a;
	cin >> a;
	while (a != 'x'){
		show(a);
		cin >> a;
	}
	return 0;
}