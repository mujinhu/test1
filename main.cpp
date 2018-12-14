#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"treeStructure.h" 
#include"buildTree.h"
#include"writeTree.h"
#include"nodeValue.c"
int main(int argc, char **argv){
	Node *head;
	//make the head node
	head=makeNode(0.0,0.0, 0);
	//make a tree
	makeChildren(head);
	growTree(head);
	removeChildren(head);
	writeTree(head);
	return 0;	
}

