#include<iostream>
#define MAX 20
#include<limits.h>
using namespace std;
int arr[MAX], count;
void print();
void init(){
	count = 0;
	for (int i = 0;i < MAX; i++){
		arr[i] = INT_MAX;
	}
}

int parentOf(int i){
	return i / 2;
}

int leftChild(int  i){
	return i * 2;
}
int rightChild(int i){
	return i * 2 + 1;
}

void swap(int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void insert(int value){
	count++;
	arr[count] = value;
	
	int temp = count;
	int parent = parentOf(temp);
	
	while(arr[parent] < arr[temp]){
		swap(temp,parent);
		temp = parent;
		parent = parentOf(temp);
	}
}

int remove(){
	int maximum = arr[1];
	arr[1] = arr[count];
	count--;
	int temp = 1;
	while(leftChild(temp) <= count){
		int max = leftChild(temp);
		int rightChild = max+1;
		if(rightChild <= count){
			if(arr[rightChild] > arr[max]){
				max = rightChild;
			}
		}
		
		if (arr[temp] >= arr[max]){
			break;
		}
		swap(temp,max);
		temp = max;
	}
	return maximum;
}

void print(){
	for (int i = 1;i <= count; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	init();
	int x;
	char c;
	cin >> c;
	while (c != 'e'){
		if (c == 'a'){
			cin >> x; insert(x);
		}else if(c == 'p'){
			print();
		}else if (c == 'd'){
			cout << remove() << endl;
		}
		cin >> c;
	}
	
	return 0;
}