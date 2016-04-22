/*  ADJ LIST of weighted directed graph
 * create
 * display
 * insert node
 * delete node
 * insert edge
 * delete edge
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct Edge{
	int weight;
	struct Edge *nextedge;
	struct Node *dest;
}*edge;

typedef struct Node{
	int name;
	struct Node *next;
	edge edges;
}*node;

node start=NULL;

void insert_node(int d){
	node n=(struct Node*)malloc(sizeof(struct Node));
	node temp;
	
	n->name=d;
	n->next=NULL;
	n->edges=NULL;
	
	if(!start){
		start = n;
		return;
	}
	
	temp = start;
	if(!start->next)
		start->next=n;
	else
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next = n;
	
}
	
void insert_edge(int s, int d, int wt){
	node src, dst, temp;
	edge newedge, e;
	temp = start;
	while(temp!=NULL){
		if(temp->name == s)
			src = temp;
			
		if(temp->name == d)
			dst =temp;
		temp=temp->next;
	}
	newedge = malloc(sizeof(*newedge));
	if(!src->edges){
		
		newedge->nextedge=NULL;
		newedge->dest=dst;
		newedge->weight=wt;
		src->edges=newedge;
	}
	else{
		e=src->edges;
		while(e->nextedge!=NULL)
			e=src->edges->nextedge;
		newedge->nextedge=NULL;
		newedge->dest=dst;
		newedge->weight=wt;
		e->nextedge=newedge;
	}
	
}

void delete_node(int d){
		
	edge preve, cure;

	node temp=start, prev=NULL, curn;
	if(start){
		curn=start;
		while(curn!=NULL){
				
			cure=curn->edges;
			preve=cure;
			
			if(cure!=NULL){
				if(cure->dest->name==d){
					curn->edges=cure->nextedge;
					curn=curn->next;
					continue;
				}
				
				while(cure!=NULL){
					if(cure->dest->name==d){
						preve->nextedge=cure->nextedge;
						cure=cure->nextedge;
						curn=curn->next;
						continue;
					}
					else{
						preve=cure;
						cure=cure->nextedge;
					}
				}
		
			curn=curn->next;
			
			}
			else {
				curn=curn->next;
			}
		}
		if(start->name==d){
			start=start->next;
			return;
		}
		
		while(temp->name!=d){
			prev=temp;
			temp=temp->next;
		}
		if(temp!=NULL){
			prev->next=temp->next;
			return;
		}
	
		
	}	
	else printf("empty bro\n");
		
}

void delete_edge(int s, int d){
		
	node src, dst, temp;
	edge cure, preve;
	temp = start;
	while(temp!=NULL){
		if(temp->name == s)
			src = temp;
			
		if(temp->name == d)
			dst =temp;
		temp=temp->next;
	}
	
	cure=src->edges;
	preve=cure;
			
	if(cure!=NULL){
		if(cure->dest==dst){
			src->edges=cure->nextedge;
			return;
		}
				
		while(cure!=NULL){
			if(cure->dest==dst){
				preve->nextedge=cure->nextedge;
				cure=cure->nextedge;
				return;
			}
			else{
				preve=cure;
				cure=cure->nextedge;
			}
		}
			
	}
	
}


void display(){
	node curn;
	edge cure;
	if(start){
		curn=start;
		while(curn!=NULL){
			printf("%d=", curn->name);
			
			cure=curn->edges;
			
			if(cure!=NULL){
				
			while(cure!=NULL){
				printf("(%d)-%d=>", cure->weight, cure->dest->name);
				
				cure=cure->nextedge;
			}
			curn=curn->next;
			printf("NULL\n");
			
		}
		else {
			curn=curn->next;
			printf("NULL\n");
		}
		
		}
	
		
	}
	else printf("empty bro\n");
}



int main(){
	
	insert_node(1);
	insert_node(2);
	insert_node(3);
	insert_node(4);
	insert_edge(1,2,4);
	insert_edge(1,3,2);
	insert_edge(1,4,2);
	insert_edge(4,2,1);
	insert_edge(3,4,6);
	display();
	printf("=================================\n");
	delete_node(1);
	display();
	printf("=================================\n");
	delete_edge(3,4);
	display();
	printf("=================================\n");
	return 0;
	
}


/*
 * output:
1=(4)-2=>(2)-3=>(2)-4=>NULL
2=NULL
3=(6)-4=>NULL
4=(1)-2=>NULL
=================================
2=NULL
3=(6)-4=>NULL
4=(1)-2=>NULL
=================================
2=NULL
3=NULL
4=(1)-2=>NULL
=================================

*/



 
 
