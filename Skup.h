#pragma once
#ifndef _skup_h_
#define _skup_h_
#include<string>
#include<iostream>
using namespace std;


class Skup {
	struct node
	{
		char znak;
		node* left,*right;
		int pos=0;
		node* createBST(node* root,const char* zn, int size) {
			int start = 0;
			return createBSTrec(zn, &start, 0, size - 1, size);
		}

		node* createBSTrec(const char* zn, int* start, int low, int high, int size) {

			if (*start >= size || low > high) {
				//throw new GNeispravanNizZnakova();
				return nullptr;
			}
			node* root = newNode(zn[*start]);
			*start = *start + 1;

			if (low == high)
				return root;

			int i;
			for (i = low; i <= high; ++i){
				if (zn[i] > root->znak)
					break;
			}
			root->left = createBSTrec(zn, start, *start, i-1, size);
			root->right = createBSTrec(zn, start, i, high, size);
			return root;
		}

		node(char zn) {
			znak = zn;
			left = right = nullptr;
		}

		node* newNode(char n) { 
			return new node(n);
		}

		bool uSkupu(char zn,node* r) {
			node* curr = r;
			while (curr) {
				if (zn == curr->znak) return true;
				else if (zn < curr->znak) {
					curr = curr->left;
				}
				else {
					curr = curr->right;
				}
			}
			return false;
		}

		node* addNode(node* r,const char zn) {
			node* curr = r;
			node* pom=nullptr;
			while (curr) {
				if (zn == curr->znak) return r;
				else if (zn < curr->znak) {
					if (!curr->left) pom = curr;
					curr = curr->left;
				}
				else {
					if (!curr->right) pom = curr;
					curr = curr->right;
				}
			}
			curr = newNode(zn);
			return r;
		}
		void printInorder(ostream& it,node* node)
		{
			if (node == NULL)
				return;
			printInorder(it,node->left);
			it << node->znak << " ";
			printInorder(it,node->right);
		}

		char* getArray(node* node,char* temp,int* br) {
			if (node == NULL)
				return nullptr;
			getArray( node->left,temp,br);
			temp[*br] = node->znak;
			*br = *br + 1;
			getArray(node->right, temp, br);
			return temp;
		}

		void BSTtoArray(node* root, char* A)
		{
			//static int pos = 0;
			if (root == NULL) return;

			BSTtoArray(root->left, A);
			
			A[pos++]=root->znak;
			BSTtoArray(root->right, A);
		}
		void clear() { pos = 0; }
		int treeSize(node* root) {
			if (root == NULL) return 0;
			else
				return treeSize(root->left) + treeSize(root->right) + 1;
		}
	};

	node* root;
	//char* temp;
	//int size=0;

public:
	Skup(const string& niska) {
		this->root = nullptr;
		string x;
		//int size = sizeof(niska) / sizeof(niska[0]);
		int size = niska.length();
		char *temp = new char[size];
		int br = 0,br2=0,i;
		//if (niska.length() == 0) throw new GNemaDuzinu();
		for (i = 0; i < niska.length() - 1; i++) {
			for (int j = i + 1; j < niska.length(); j++) {
				if (niska[i] == niska[j]) br++;
			}
			if (br == 0) temp[br2++] = niska[i]; //niz znakova od kojeg treba napraviti stablo(bst)
			br = 0;
		}
		if (i == niska.length() - 1) {
			temp[br2++] = niska[i];
			temp[br2] = '\0';
		}
		//try
		root=root->createBST(root,temp,size);
		//catch(){}
	}

	Skup(const Skup&) = delete;
	Skup& operator=(const Skup&) = delete;

	void operator+=(char zn) {
		root->addNode(root, zn);
	}

	bool operator()(char zn) {
		return root->uSkupu(zn,root);
	}

	char* getZnakove(char* temp) {
		int br = 0;
		//this->root
		temp = new char[this->root->treeSize(this->root)];
		this->root->BSTtoArray(this->root,temp);
		return temp;
	}

	node* getRoot() const { return this->root; }

	int gettreeSize(node* root) {
		if (root == NULL) return 0;
		else
			return gettreeSize(root->left) + gettreeSize(root->right) + 1;
	}

	friend ostream& operator<<(ostream& it, Skup& s) {
		return it;
	}

};
#endif // !_skup_h_

