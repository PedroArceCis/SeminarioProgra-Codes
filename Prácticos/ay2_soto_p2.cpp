#include<iostream>
using namespace std;

struct node{
	int entero;
	node *p1;
	node *p2;
};


struct node* newNode(){
	node *a;
	a = new node;
	a -> p1 = NULL;
	a -> p2 = NULL;
	return a;
};

//void insertNode(*root,int number){

//}






int main(){






	return 0;
}