/*
 implement bfs dfs recursion
 */

#include <stdio.h>
#include <stdlib.h>

#define max 20

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
int visited[max];
node que[max];
int top=-1;
int pos=-1;

void init_visited(){
	int i;
	for(i=0; i<max;i++)
		visited[i]=0;
}

void disp_visited(){
	int i;
	for(i=0; i<max;i++)
		printf("%d", visited[i]);
	printf("\n %d %d\n", top, pos);
}


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

void display_adj(node curn){
	edge cure;
	if(visited[curn->name]!=1){
		printf("%d ", curn->name);
		visited[curn->name]=1;
	}
			
	cure=curn->edges;
			
	if(cure!=NULL){	
		while(cure!=NULL){
			if(visited[cure->dest->name]!=1){
			printf("%d ", cure->dest->name);
			visited[cure->dest->name]=1;
			pos++;
			que[pos]=cure->dest;
			cure=cure->nextedge;
			
		}
		else cure=cure->nextedge;
		}
	}
	else return;
		
}

	
void bfs(node n){
	display_adj(n);
	top++;
	n=que[top];
	if(top>pos) return;
	bfs(n);
}


void dfs(node n){
	node next;
	edge e;

	printf("%d ", n->name);
	visited[n->name]=1;

	e=n->edges;
			
	while(e!=NULL){
		next=e->dest;
		e=e->nextedge;
		if(visited[next->name]!=1)
			dfs(next);
	}
}


int main(){
	
	insert_node(1);
	insert_node(2);
	insert_node(3);
	insert_node(4);
	insert_node(5);
	insert_node(6);
	insert_node(7);
	insert_node(8);
	insert_node(9);
	
	insert_edge(1,2,1);	
	insert_edge(1,4,1);
	insert_edge(1,5,1);
	insert_edge(2,3,1);
	insert_edge(2,5,1);
	insert_edge(3,6,1);
	insert_edge(4,7,1);
	insert_edge(5,6,1);
	insert_edge(7,5,1);
	insert_edge(7,8,1);
	insert_edge(8,9,1);
	
	
	
	init_visited();
	display();
	printf("\n\n\n");
	bfs(start);
	init_visited();
	printf("\n\n\n");
	dfs(start);
	return 0;
	
}
/*
 * 
1=(1)-2=>(1)-4=>(1)-5=>NULL
2=(1)-3=>(1)-5=>NULL
3=(1)-6=>NULL
4=(1)-7=>NULL
5=(1)-6=>NULL
6=NULL
7=(1)-5=>(1)-8=>NULL
8=(1)-9=>NULL
9=NULL



1 2 4 5 3 7 6 8 9 


1 2 3 6 5 4 7 8 9 

* 
* */

