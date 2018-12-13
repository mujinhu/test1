#include "math.h"

double nodeValue( Node *node, double time );
double value( double x, double y, double time );
void addChildren( Node *parent );
void flag(Node *node);
int leaf(Node *node);
int children(Node *node);
void adjust(Node *node);


// Evaluate function at centre of quadtree node
double nodeValue( Node *node, double time ) {

  int level = node->level;
  double x = node->xy[0];
  double y = node->xy[1];

  double h = pow(2.0,-level);

  return( value( x+0.5*h, y+0.5*h, time ) );
}

// Data function
double value( double x, double y, double time ) {

  return( 2.0*exp(-8.0*(x-time)*(x-time)) - 1.0 ) ;
}

// Add children
void addChildren( Node *parent ) {

  double x = parent->xy[0];
  double y = parent->xy[1];
  int level = parent->level;
  double hChild = pow(2.0,-(level+1));

  parent->child[0] = makeNode( x,y, level+1 );
  parent->child[1] = makeNode( x+hChild,y, level+1 );
  parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
  parent->child[3] = makeNode( x,y+hChild, level+1 );

  return;
}

// Set flag
void flag(Node *node){
	int i;
	if(nodeValue(node,0.0)>0.5){
		node->flag=1;
	}
	else if(nodeValue(node,0.0)<-0.5){
		node->flag=-1;
	}
	else{
		node->flag=0;
	}
	for(i=0;i<4;i++){
		if(node->child[i]!=NULL){
			flag(node->child[i]);
		}
	}
}

//Judge whether it is a leaf node
int leaf(Node *node){
	int i;
	for(i=0;i<4;i++){
		if(node->child[i]!=NULL){
			return 0;
		}
	}
	return 1;
}

//Judge it is not a leaf node and all children have flag=-1
int children(Node *node){
	int i;
	int count=0;
	for(i=0;i<4;i++){
		if(node->child[i]!=NULL){
			count = count + node->child[i]->flag;
		}
	}
	if(count==-4){
		return 1;	
	}
	return 0;
}

// Adjust the tree
int addn = 0;
int remn = 0;

void adjust(Node *node){
	int i;
	if(leaf(node) && node->flag==1){
		addChildren(node);
		addn = addn + 4;
		return;
	}
	else if(children(node)){
		removeChildren(node);
		remn = remn + 4;
		return;
	}
	for(i=0;i<4;i++){
		if(node->child[i]!=NULL)
			adjust(node->child[i]);
	}
}





