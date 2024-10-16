#include<iostream>
#include<queue>
using namespace std;

struct Node{
	int key;
	Node *right, *left;
	Node(int value){
		key = value;
		right = left = NULL;
	}	
};

int searchMax(Node *root){
	if(root->left != NULL) return searchMax(root->left);
	return root->key;
}

Node *insert(Node *root, int key){
	if(root == NULL) return new Node(key);
	
	if(key < root->key){
		root->left = insert(root->left, key);
	}else{
		root->right = insert(root->right, key);
	}
	return root;
}

Node *deleteNode(Node *root, int key){
	if(root == NULL){
		cout << "Empty" << endl; return root;
	}
	
	if(key < root->key){
		root->left = deleteNode(root->left, key);
	}else if(key > root->key){
		root->right = deleteNode(root->right, key);
	}else{
		//case 1 if has no Child
		if(root->left == NULL && root->right == NULL){
			delete root; root = NULL; return root;
		}
		//case 2 if has 1 Child
		else if(root->left == NULL){
			Node *temp = root->right; delete root; return temp;
		}
		else if(root->right == NULL){
			Node *temp = root->left; delete root; return temp;
		}
		//case 3 if has 2 Child
		else if(root->left != NULL && root->right != NULL){
			int temp = searchMax(root->right);
			root->key = temp;
			root->right = deleteNode(root->right, temp);
		}
	}
	return root;
}

void preorder(Node *root){
	if(root == NULL) return;
	
	cout << root->key << ",";
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node *root){
	if(root == NULL) return;
	
	inorder(root->left);
	cout << root->key << ",";
	inorder(root->right);
}

void postorder(Node *root){
	if(root == NULL) return ;
	
	postorder(root->left);
	postorder(root->right);
	cout << root->key << ","; 
}

void showBFS(Node *root){
	if(root == NULL) return;
	
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node *current = q.front(); q.pop();
		if(current == NULL){
			if(!q.empty()){
				cout << "|"; q.push(NULL);
			}
		}else{
			cout << current->key << ",";
			if(current->left != NULL) q.push(current->left);
			if(current->right != NULL) q.push(current->right);
		}
	}
	cout << "|";
}

int main(){
	Node *root = NULL;
	int x;
	char c;
	cin >> c;
	while(c != 'x'){
		if(c == 'a'){
			cin >> x; root = insert(root, x);
		}else if(c == 'd'){
			cin >> x; root = deleteNode(root, x);
		}else if(c == 'b'){
			showBFS(root); cout << endl;
		}else if(c == 'i'){
			inorder(root); cout << endl;
		}else if(c == 'p'){
			preorder(root); cout << endl;
		}else if(c == 't'){
			postorder(root); cout << endl;
		}
		cin >> c;
	}
	return 0;
}