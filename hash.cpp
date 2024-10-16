#include<iostream>
#include<string>
#define SIZE 10
using namespace std;

class HashTable{
	public:
		int Hashkey[SIZE];
		string Hashdata[SIZE];
	
	HashTable(){
		for (int i = 0; i < SIZE; i++){
			Hashkey[i] = -1;
			Hashdata[i] = "NULL";
		}
	}
	
	void add_double_hash(int key, string data){
		int fx = SIZE - (key % SIZE);
		for (int i = 0; i < SIZE; i++){
			int hash = (key + (i * fx)) % SIZE;
			if (Hashkey[hash] == -1){
				Hashkey[hash] = key;
				Hashdata[hash] = data;
				return;
			}
		}
	}
	
	string search_double_hash(int key){
		int fx = SIZE - (key % SIZE);
		for (int i = 0;i < SIZE; i++){
			int hash = (key + (i * fx)) % SIZE;
			if (Hashkey[hash] == key){
				return Hashdata[hash];
			}
			if (Hashkey[hash] == -1){
				return "NONE";
			}
		}
	}
	
	void add_linear(int key, string data){ // collision handle
		for(int i = 0; i < SIZE; i++){
			int hash = (key + i) % SIZE;
			if (Hashkey[hash] == -1){
				Hashkey[hash] = key;
				Hashdata[hash] = data;
				break; 
			}
		}
	}
	
	string search_linear(int key){
		for (int i = 0;i < SIZE; i++){
			int hash = (key + i) % SIZE;
			if (Hashkey[hash] == key){
				return Hashdata[hash];
			}
			if(Hashkey[hash] == -1){
				return "NONE";
			}
		}
	}
	
	void add_quadratic(int key, string data){ // collision handle
		for(int i = 0; i < SIZE; i++){
			int hash = (key + (i * i)) % SIZE;
			if (Hashkey[hash] == -1){
				Hashkey[hash] = key;
				Hashdata[hash] = data;
				break; 
			}
		}
	}
	
	string search_quadratic(int key){
		for (int i = 0;i < SIZE; i++){
			int hash = (key + (i * i)) % SIZE;
			if (Hashkey[hash] == key){
				return Hashdata[hash];
			}
			if(Hashkey[hash] == -1){
				return "NONE";
			}
		}
	}
	
	void addEasy(int key, string data){ // no collision
		int i = key % SIZE;
		if (Hashkey[i] == key){
			cout << "Same key!" << endl;
			return;
		}
		Hashkey[i] = key;
		Hashdata[i] = data;
	}
	
	string searchEasy(int key){
		int i = key % SIZE;
		if (Hashkey[i] == key){
			return Hashdata[i];
		}else{
			return NULL;
		}
	}
	
	void printEasy(){
		for (int i = 0; i < SIZE; i++){
			cout << "(" << Hashkey[i] << "," << Hashdata[i] << ")" << endl;
		}
	}
};

int main(){
	HashTable h;
//	h.addEasy(1, "Hello");
//	h.addEasy(2, "Hale");
//	h.addEasy(1, "WOOha");
//	
//	h.add_linear(11, "as");
//	h.add_quadratic(21, "Haha");
//	
//	h.add_double_hash(31, "MUHAHA");
//	cout << h.search_double_hash(31) << endl;
	h.printEasy();
	return 0;
}