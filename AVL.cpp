#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    
    Node(int item) {
        key = item;
        left = right = NULL;
        height = 1;
    }
};

int getHeight(Node* root){
	if (root == NULL) return 0;
	return root->height;
}

int updateHeight(Node* root){
	if (root == NULL) return 0;
	
	int hL = getHeight(root->left);
	int hR = getHeight(root->right);
	int max = (hL > hR) ? hL : hR;
	root->height = max+1;
	return root->height;
}

bool checkAVLBalance(Node* root){
	if (root == NULL) return true;
	
	int hL = getHeight(root->left);
	int hR = getHeight(root->right);
	if (hL - hR >= -1 && hL-hR <=1) return true;
	
	return false;
}

Node* rotateRight(Node* root){
	Node* leftChild = root->left;
	root->left = leftChild->right;
	leftChild->right = root;
	updateHeight(root);
	updateHeight(leftChild);
	return leftChild;        // as a new root
}

Node* rotateLeft(Node* root){
	Node* rightChild = root->right;
	root->right = rightChild->left;
	rightChild->left = root;
	updateHeight(root);
	updateHeight(rightChild);
	return rightChild;       // as a new root;
	
}

Node* reBalance(Node* root){
	int hL = getHeight(root->left);
	int hR = getHeight(root->right);
	if (hL > hR) {
		if (getHeight(root->left->left) >= getHeight(root->left->right)){
			// Single Right rotation
//			cout << "Right rotation: " << root->key << endl;
			root = rotateRight(root);
		}
		else {
			// Double Left-Right rotation
//			cout << " Left-Right rotation: " << root->key << endl;
			root->left = rotateLeft(root->left);
			root = rotateRight(root);
		}
	} 
	else {
		if (getHeight(root->right->right) >= getHeight(root->right->left)){
			// Single Left rotation
			root = rotateLeft(root);
		}
		else {
			// Single Left rotation
			root->right = rotateRight(root->right);
			root = rotateLeft(root);
		}
	}
	return root;
}

int searchMax(Node* root){
	if (root->left != NULL) return searchMax(root->left);
	return root->key;

}


Node* deleteNode(Node* root, int key) {
	if(root == NULL) return root;
	if(key < root->key){
		root->left = deleteNode(root->left, key);
	}else if(key > root->key){
		root->right = deleteNode(root->right, key);
	}else{
		//case 1
		if(root->left == NULL && root->right == NULL){
			delete root; root = NULL; return root;
		}
		//case 2
		else if(root->left == NULL){
			Node *temp = root->right; delete root; root = NULL; return temp;
		}else if(root->right == NULL){
			Node *temp = root->left; delete root; root = NULL; return temp;
		}
		//case 3
		else if(root->left != NULL && root->right != NULL){
			int temp = searchMax(root->right);
			root->key = temp; root->right = deleteNode(root->right, temp);
		}
	}
	updateHeight(root);
	if (!checkAVLBalance(root)) {
		root = reBalance(root);
	}
	return root;
}


// function to search a key in a BST
Node* search(Node* root, int key) {
  
    // Base Cases: root is null or key 
    // is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

Node* insert2(Node* root, int key) {
  
  	// Base case: root is null
	if (root == NULL) return new Node(key);
	
	if (key < root->key) {
		root->left = insert2(root->left, key);
	} else {
		root->right = insert2(root->right, key);
	}
	
	updateHeight(root);
	if (!checkAVLBalance(root)) {
		root = reBalance(root);
	}
	return root;
}

void inorder(Node *root){
	if (root == NULL) return;
	
	inorder(root->left);
	cout << root->key << "(" << root->height << ")  ";
	inorder(root->right);
}

void preorder(Node *root){
	if (root == NULL) return;
	
	cout << root->key << "  ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node *root){
	if (root == NULL) return;
	
	postorder(root->left);
	postorder(root->right);
	cout << root->key << "  ";
}

int main(){
	Node *root = NULL;
	int x;
	char c;
	cin >> c;
	while(c != 'e'){
		if(c == 'a'){
			cin >> x; root = insert2(root, x);
		}else if(c == 'p'){
			preorder(root);
		}else if(c == 'd'){
			cin >> x; root = deleteNode(root, x);
		}
		cin >> c;
	}
	return 0;
}