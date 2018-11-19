#include<stdio.h>
#include<stdlib.h>

// Binary search tree -- Arvore de busca binaria

typedef struct node{
	int val; // Value of the node
	struct node *anc; // Ancestor node
	struct node *l; // Left node;
	struct node *r; // Right node
} node;

int nodeCnt(node *root){
	// Count the number of nodes of a given tree
	int cnt = 0;
	if (root == NULL) return 0;
	cnt = nodeCnt(root->r);
	cnt += nodeCnt(root->l);
	return (cnt + 1);
}

void preOrder(node *root){
	// Print tree in pre order. Visiting root, then left subtree
	// and then right subtree
	if (root != NULL){
		printf("%d\n", root->val);
		preOrder(root->l);
		preOrder(root->r);
	}
}

void inOrder(node *root){
	// Print tree in in order. Visiting left subtree, then the root
	// and then the right subtree
	if (root != NULL){
		inOrder(root->l);
		printf("%d\n", root->val);
		inOrder(root->r);
	}
}

void posOrder(node *root){
	// Print tree in pos order. Visiting left subtree, then the right
	// subtree, then the root.
	if (root != NULL){
		posOrder(root->l);
		posOrder(root->r);
		printf("%d\n", root->val);
	}
}

int isAnc(node *p, node *q){
	// Return 1 if P is an ancestor of Q, otherwise, returns 0
	if (p == NULL) return 0;
	while (q != NULL && q != p)
		q = q->anc;

	return (p == q);
}

int lvl(node *p){
	// Return the level of a given node P
	int cont = 0;
	while (p->anc != NULL){
		p = p->anc;
		cont++;
	}
	return cont;
}

node *lca(node *p, node *q){
	// Return the last common ancestor of two given nodes
	int np = lvl(p), nq = lvl(q);
	while (np > nq){
		p = p->anc;
		np--;
	}
	while (nq > np){
		q = q->anc;
		nq--;
	}
	while (p != q){
		p = p->anc;
		q = q->anc;
	}
	return q;
}

node *search(node *root, int x){
	// Return node with val == x. If x isn't in the tree
	// return NULL
	if (root == NULL || root->val == x)
		return root;
	if (root->val > x)
		return search(root->l, x);
	return search(root->r, x);
}

node *minimal(node *root){
	// Return node with the minimal element in the tree
	if (root == NULL || root->l == NULL) return root;
	return minimal(root->l);
}

node *maximal(node *root){
	// Return node with the maximal element in the tree
	if (root == NULL || root->r == NULL) return root;
	return maximal(root->r);
}

node *insert(node *root, int x){
	// Insert an element and return the root
	if (root == NULL){
		root = malloc(sizeof(node));
		root->val = x;
		root->l = root->r = root->anc = NULL;
	}
	else if (root->val > x){
		root->l = insert(root->l, x);
		root->l->anc = root;
	}
	else if (root->val < x){
		root->r = insert(root->r, x);
		root->r->anc = root;
	}
	return root;
}

node *rmv(node *root, int x){
	// Remove node with val == x
	if (root != NULL){
		node *aux;
		if (root->val > x)
			root->l = rmv(root->l, x);
		else if (root->val < x)
			root->r = rmv(root->r, x);
		else {
			if (root->r == NULL){
				aux = root;
				root = root->l;
				free(aux);
			}
			else if (root->l == NULL){
				aux = root;
				root = root->r;
				free(aux);
			}
			else {
				aux = maximal(root->l);
				root->val = aux->val;
				root->l = rmv(root->l, aux->val);
			}
		}		
	}
	return root;
}

node *turnLeft(node *root){
	// Rotate the tree to the left
	node *aux = root->r;
	if (aux == NULL) return root;
	root->r = aux->l;
	aux->l = root;
	if (root->r != NULL) root->r->anc = root;
	aux->anc = root->anc;
	root->anc = aux;
	return root;
}

node *turnRight(node *root){
	// Rotate the tree to the right
	node *aux = root->l;
	if (aux == NULL) return root;
	root->l = aux->r;
	aux->r = root;
	if (root->l != NULL) root->l->anc = root;
	aux->anc = root->anc;
	root->anc = aux;
	return root;
}

node *insertH(node *root, int x){
	// Insert keeping 'log n' height. Make root receive this 
	if(root == NULL){
		root = malloc(sizeof(node));
		root->val = x;
		root->l = root->r = root->anc = NULL;
		root->alt = random(MAX); // Have to deal with this new atribute
		return(root);
	}

	if(root->val > x){
		root->l = insertH(root->l, x);
		if(root->l->alt > root->alt){
			root = turnRight(root);
		}
	}

	else if(root->val < x){
		root->r = insertH(root->r, x);
		if(root->r->alt > root->alt){
			root = turnLeft(root);
		}
	}

	return root;
}

int main(){
	printf("Type the number of elements in the tree: \n");
	int n;
	scanf("%d", &n);

	node *root = NULL;
	printf("Type the elements\n");
	for (int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		root = insert(root, x);
	}

	printf("\nNumber of elements in the tree: %d\n", nodeCnt(root));

	printf("\nElements in the tree:\n");
	preOrder(root);

	printf("\nSearching element 3: \n");
	node *s = search(root, 3);
	if (s == NULL) printf("Didn't find\n");
	else printf("Did find\n");

	printf("\nThe maximal element is: %d\n", maximal(root)->val);
	printf("\nThe minimal element is: %d\n", minimal(root)->val);

	printf("\nType an element to insert: \n");
	int x;
	scanf("%d", &x);
	root = insert(root, x);

	printf("\nPrinting tree with inserted value: \n");
	preOrder(root);

	printf("\nRemoving this element\n");
	root = rmv(root, x);

	printf("\nPrinting tree with removed value\n");
	preOrder(root);
}