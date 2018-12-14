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
	//growTree(head);
	//growTree(head);
	//makeChildren(head->child[0]);
	//makeChildren(head->child[1]);
	//do{
	//	flag(head);
	//	adapta = adaptr = 0;
	//	adapt(head);
	//	printf("I have added %d nodes and removed %d nodes\n",adapta,adaptr);
	//}while(adapta + adaptr != 0);
	//destroyTree(head);
	//make a tree
	makeChildren(head); 
	writeTree(head);
	return 0;	
}

