// BalanceFactor (bf) = HeightLefTree - HeightRightTree

#include <stdio.h>
#include <stdlib.h>

typedef struct node_n{
	int data;
	struct node_n *right, *left;
	int ht;
	int bf;
}node;

node *root;


void display(node *n){
	if(n==NULL)
		return;
	printf("data = %d, height = %d, bf = %d\n", n->data, n->ht, n->bf);
}
 
int height(node *n);


// method to find the required element 
//==========================================================
void find(int d, node **parent, node **locn){
	
	node *ptr, *temp;
	
	if(root == NULL)
	{
		*locn=NULL;
		*parent=NULL;
		return;
	}
	
	if(d == root->data)
	{
		*locn=root;
		*parent=NULL;
		return;
	}
	
	//to reach end
	if(d < root->data)
		temp = root->left;
	else if(d > root->data)
		temp = root->right;	
	
	ptr = root;	
	
	while(temp!=NULL){
		if(temp->data == d){
			*parent = ptr; 
			*locn = temp;
			return;
		}
		ptr = temp;
		if(d < temp->data){
			temp=temp->left;
		}
		else if(d > temp->data){
			temp = temp->right;
		}
		
	}
	
	*locn=NULL;
	*parent = ptr;
	
}



//====================================================

void insert(int d){
	
	node *temp, *parent, *locn;
	find(d, &parent, &locn);
	
	if(locn!=NULL)
	{
		printf("\n Item already present.");
		return;
	}
	temp = (node *)malloc(sizeof(node));
			temp->data = d;
			temp->right = NULL;
			temp->left = NULL;
			temp->ht = 0;
			temp->bf = 0;
	
		if(parent==NULL){
			root = temp;
		}
		else{
			
			
			if(d < parent->data)
				parent->left=temp;
			else
			parent->right=temp;
		}
		
}

//height calculation ---------------------------------------------------
int left_height(node *n){
	
	if(n == NULL)
		return -1;
	else{
		return height(n->left) + 1;
		
	}
	
		
}

int right_height(node *n){
	
	if(n == NULL)
		return -1;
	else{
		return height(n->right) + 1;
		
	}
	
}

int height(node *n){
	if(n==NULL)
		return -1;
	
	int lht, rht;
	n->ht=0;
	lht = left_height(n);
	n->ht = 0;
	rht = right_height(n);
	
	if(lht>rht){
		n->ht = lht;
		return n->ht;
	}
	else{
		n->ht = rht;
		return n->ht;
	}
}
//----------------------------------------------------------------------

void balance_factor(node *n){
	int lht, rht;
	
	if(n == NULL)
		return;
		
	lht = height(n->left);
	rht = height(n->right);
	
	n->bf = lht-rht;
	
}

void postorder_init(node *n){
	if(n == NULL)
		return;
	n->ht = height(n);
	postorder_init(n->left);
	postorder_init(n->right);
	balance_factor(n);
}

void postorder(node *n){
	if(n == NULL)
		return;
	postorder(n->left);
	postorder(n->right);
	display(n);
}




int main(){
	FILE *fp;
	int num;
	printf("\ndo u want to insert elements in the bst(yes - 1)\n");
	/*
	int ch;
	int info;
	scanf("%d", &ch);

	while(ch==1){
		printf("\nenter element to be inserted: ");
		scanf("%d", &info);
		insert(info);
		printf("\ndo u want to insert more elements in the bst(yes - 1)\n");
	
		scanf("%d", &ch);
	
	}
	
	*/
	fp = fopen("ip_AVL2.txt", "r");
	
	while(fscanf(fp, "%d", &num) > 0) {
        insert(num);
    }
    
    fclose(fp);
	
	
	printf("root height %d\n",height(root));
	
		
	postorder_init(root);
	postorder(root);
	
	if(root->bf <= 1 && root->bf >=-1)
		printf("tree is balanced AVL tree\n");
	else
		printf("tree is not balanced AVL tree!!! make it balanced for God's sake\n");
	 
}
	


	



