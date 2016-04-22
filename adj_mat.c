/*  ADJ MAT of undirected graph
 * create
 * display
 * insert node
 * delete node
 * insert edge
 * delete edge
 */

#include <stdio.h>
#include <stdlib.h>
 
#define max 50

int adjm[max][max];
int num;

void init_mat(){
	int i, j;
	for(i=0; i< max; i++)
		for(j=0; j < max; j++)
			adjm[i][j]=0;
}


void insert_edge(int src, int dest){
	if(src<=num && dest<=num && src>0 && dest>0)
		adjm[src][dest]=1;
	else
		printf("invalid source or destination\n");
}


void delete_edge(int src, int dest){
	if(adjm[src][dest]==0){
		printf("edge doesnt exists\n");
		return;
	}
	if(src<=num && dest<=num && src>0 && dest>0)
		adjm[src][dest]=0;
	else
		printf("invalid source or destination\n");
	
}


void insert_node(){
	if(++num>=max){
		printf("not able to expand anymore, use adjacency list for such expansions!!!\n");
		--num;
		return;
	}
}

void delete_node(int n){
	int i;
	if(n>=max){
		printf("invalid node...\n");
		return;
	}
	if(num==0){
		printf("no nodes\n");
		return;
	}
	if(n==max-1){
		
		for(i=1;i<=n;++i)
			adjm[i][n]=0;
		for(i=1;i<=n;++i)
			adjm[n][i]=0;
		return;
	
	}
	
	for(i=1;i<=n;++i)
		adjm[i][n]=adjm[i][n+1];
	for(i=1;i<=n;++i)
		adjm[n][i]=adjm[n+1][i];
	num--;
		
}

void display(){
	int i, j;
	for(i=1; i<=num; i++){
		for(j=1;j<=num;j++)
			printf("%d    ", adjm[i][j]);
		printf("\n");
	}
}



int main()
{
	int ch, s, d;
	printf("enter the number of nodes of the undirected graph\n");
	scanf("%d", &num);
	
	if(num>0 && num<max){
		init_mat();
		while(1){
		printf("\n 1* display\n 2* insert node\n 3* delete node\n 4* insert edge\n 5* delete edge\n 0* EXIT\nenter choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: display();
					break;
			case 2: insert_node();
					break;
			case 3: printf("enter the node to be deleted: ");
					scanf("%d", &s);
					delete_node(s);
					break;
			case 4: printf("enter the source and destination: ");
					scanf("%d", &s);
					scanf("%d", &d);
					insert_edge(s, d);
					break;
			case 5: printf("enter the source and destination: ");
					scanf("%d", &s);
					scanf("%d", &d);
					delete_edge(s, d);
					break;
			case 0:
			default: exit(0);
				
	}
	}
	}
	else
		printf("invalid number of nodes");
	
	return 0;
}

 
