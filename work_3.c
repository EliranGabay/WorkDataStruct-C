#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Node//struct Node
{
	struct Node *Par, *Left,*Right;
	int key;
}Node;

void Mainoption();//option func
void BuildBST(Node**, int*);//load bst func
void InsertBST(Node**, int);//insert to bst func
void Delete(Node*);//delet from bst func
void FreeTree(Node**, int*);//free tree func
void PrintLevelorder(Node*);//print level order func
void PrintPreorder(Node*);//print pre order func
void PrintInorder(Node*);//print in order func
void PrintPostorder(Node*);//print post order func
void printList(Node **);//print list for *CTPDLL func
Node* BSTSearch(Node**, int);//bst search func
Node* TreeMin(Node*);//min number in bst func
Node* TreeMax(Node*);//max number in bst func
Node* TreeSuccessor(Node*,Node*);//successor in bst func
void ConvertToPreorderDoublyLinkList(Node*,Node**);//*CTPDLL func

int main()//main func
{
	Node **Tree = (Node**)malloc(sizeof(Node));//Tree pointer
	Node *Temp = *Tree;
	Node *TempN = *Tree;
	*Tree = NULL;
	int array[] = { 11,6,4,5,8,10,19,17,43,31,49 };//array for example
	int level = 4;//level Tree
	BuildBST(Tree, array);//default tree
	int key;
	do
	{
		int choice;
		system("@cls||clear");//clear screen
		Mainoption();//option func
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)//case of option
		{
		case 1:
			system("@cls||clear");
			*Tree = NULL;
			printf("Building BST: \n");
			BuildBST(Tree, array);
			printf("Enter any number to back to main...");
			scanf("%d", &key);
			break;
		case 2:
			system("@cls||clear");
			printf("Insert new node:");
			scanf("%d", &key);
			InsertBST(Tree, key);
			printf("Enter any number to back to main...");
			scanf("%d", &key);
			break;
		case 3:
			system("@cls||clear");
			printf("Delete node: \n");
			scanf("%d", &key);
			Delete(BSTSearch(Tree, key));
			printf("The number %d deleted\n", key);
			printf("Enter any number to back to main...");
			scanf("%d", &key);
			break;
		case 4:
			system("@cls||clear");
			printf("Print Levelorder: \n");
			Temp = *Tree;
			for (int i = 1; i <= 4; i++)
			{
				PrintLevelorder(Temp, i);
			}
			printf("\nEnter any number to back to main...");
			scanf("%d", &key);
			break;
		case 5:
			system("@cls||clear");
			printf("Print Preorder: \n");
			Temp = *Tree;
			PrintPreorder(Temp);
			printf("\nEnter any number to back to main...");
			scanf("%d", &key);
			break;
		case 6:
			system("@cls||clear");
			printf("Print Inorder: \n");
			Temp = *Tree;
			PrintInorder(Temp);
			printf("\nEnter any number to back to main...");
			scanf("%d", &key);
			break;
		case 7:
			system("@cls||clear");
			printf("Print Postorder: \n");
			Temp = *Tree;
			PrintPostorder(Temp);
			printf("\nEnter any number to back to main...");
			scanf("%d", &key);
			break;
		case 8:
			system("@cls||clear");
			printf("BST-Search by Key:");
			scanf("%d", &key);
			Temp = BSTSearch(Tree, key);
			if (Temp != NULL)printf("the number %d found\n");
			printf("Enter any number to back to main...");
			scanf("%d", &key);
			break;
		case 9:
			system("@cls||clear");
			printf("Print Tree-Minimum: \n");
			Temp = *Tree;
			TempN = TreeMin(Temp);
			printf("the min number is %d\n", TempN->key);
			printf("Enter any number to back to main...");
			scanf("%d", &key);
			break;
		case 10:
			system("@cls||clear");
			printf("Print Tree-Maximum: \n");
			Temp = *Tree;
			TempN = TreeMax(Temp);
			printf("the max number is %d\n", TempN->key);
			printf("Enter any number to back to main...");
			scanf("%d", &key);
			break;
		case 11:
			system("@cls||clear");
			printf("Print Tree-Successor Key:");
			scanf("%d", &key);
			TempN = TreeSuccessor(BSTSearch(Tree, key), Tree);
			if (TempN != NULL)printf("the Successor is: %d\n", key);
			else printf(" the number not found or does not have Successor\n");
			printf("Enter any number to back to main...");
			scanf("%d", &key);
			break;
		case 12:
			system("@cls||clear");
			printf("Convert to preorder doubly link list: \n");
			ConvertToPreorderDoublyLinkList(Temp, NULL);
			printList(Tree);
			printf("Enter any number to back to main...");
			scanf("%d", &key);
			break;
		case 13://exit and free tree
			FreeTree(Tree,array);
			exit(1);
			break;
		}
	} while (1);
	printf("error");
}

void BuildBST(Node **root, int *array)//load bst func
{
	for (int i = 0; i < 11; i++)
	{
		InsertBST(root, array[i]); // insert to bst func
	}
	printf("The BST Tree Build successfully\n");
}

void InsertBST(Node **root, int data)// insert to bst func
{
	Node *NewTree = (Node*)malloc(sizeof(Node));
	NewTree->key = data;
	NewTree->Left = NULL;
	NewTree->Right = NULL;
	NewTree->Par = NULL;
	Node *Temp =*root;
	//insert by Rules of bst tree
	if (*root == NULL)*root = NewTree;
	else
	{
		while (Temp!=NULL)
		{
			NewTree->Par = Temp;
			if (Temp->key > NewTree->key)
			{
				if (Temp->Left == NULL)
				{
					Temp->Left = NewTree;
					Temp = Temp->Left;
				}
				Temp = Temp->Left;
			}
			else
			{
				if (Temp->Right == NULL)
				{
					Temp->Right = NewTree;
					Temp = Temp->Right;
				}
				Temp = Temp->Right;
			}
		}
	}
	printf("%d add to the BST Tree\n", data);
}

void FreeTree(Node **root,int *array)//free all tree func
{
	for (int i = 10; i >=0; i--)
	{
		free(BSTSearch(root, array[i]));//use bstSearch func
	}
	printf("The tree was successfully released\n");
}

void Delete(Node *node)//delete node from bst tree by rules
{
	Node*Temp = node;
	Node*TN = NULL;
	if (node == NULL)return 0;
	int key=node->key;
	if (node->Left == NULL&&node->Right == NULL)free(node);
	else if (node->Left == NULL)//left tree
	{
		if (Temp->Par->Left ==node)
		{
			Temp->Par->Left = node->Right;
			Temp->Left->Par = node->Par;
		}
		if (Temp->Par->Right==node)
		{
			Temp->Par->Right = node->Right;
			Temp->Right->Par = node->Par;
		}
		free(node);
	}
	else if (node->Right == NULL)//right tree
	{
		if (Temp->Par->Left == node)
		{
			Temp->Par->Left = node->Left;
			Temp->Left->Par = node->Par;
		}
		if (Temp->Par->Right == node)
		{
			Temp->Par->Right = node->Left;
			Temp->Right->Par = node->Par;
		}
		free(node);
	}
	else//else
	{
		TN = TreeSuccessor(node, node);
		node->key = TN->key;
		TN->key = key;
		Delete(TN);
	}
}

void PrintLevelorder(Node *root,int level)//level order print 
{
	if (root != NULL)
	{
		if (level == 1)printf("%d, ", root->key);
		else
		{
			PrintLevelorder(root->Left, level - 1);
			PrintLevelorder(root->Right, level - 1);
		}
	}
}

void PrintPreorder(Node *root)//pre order print 
{
	if (root != NULL)
	{
		printf("%d, ",root->key);
		PrintPreorder(root->Left);
		PrintPreorder(root->Right);
	}
}

void PrintInorder(Node *root)//in order print 
{
	if (root != NULL)
	{
		PrintInorder(root->Left);
		printf("%d, ", root->key);
		PrintInorder(root->Right);
	}
}

void PrintPostorder(Node *root)//post order print 
{
	if (root != NULL)
	{
		PrintPostorder(root->Left);
		PrintPostorder(root->Right);
		printf("%d, ",root->key);
	}
}

Node* BSTSearch(Node **root, int key)//search in bst tree by value
{
	Node *Temp = *root;
	while (Temp!=NULL)
	{
		if (Temp->key == key)return Temp;
		if (Temp->key > key)
		{
			Temp=Temp->Left;
		}
		else
		{
			Temp = Temp->Right;
		}
	}
	printf("The number does not exist ");
	return NULL;
}

Node* TreeMin(Node*root)//found the min number in the tree
{
	while (root->Left!=NULL)
	{
		root = root->Left;
	}
	return root;
}

Node* TreeMax(Node*root)//found the max number in tree
{
	while (root->Right != NULL)
	{
		root = root->Right;
	}
	return root;
}

Node* TreeSuccessor(Node*node,Node**root)//found the successor number in bst tree by rules
{
	if (node == NULL)return NULL;
	if (TreeMax(*root) == node)return node;
	if (node->Right != NULL)
	{
		return(TreeMin(node->Right));
	}
	else
	{
		while (node->Par->Left != node)
		{
			node = node->Par;
		}
		return node->Par;
	}
}

void ConvertToPreorderDoublyLinkList(Node *root)//CTPDLL
{
	while (root != NULL) {//run on the tree and twice Location
		if (root->Left != NULL) {
			Node *prev = root->Left;
			while (prev->Right != NULL) {
				prev = prev->Right;
			}
			prev->Right = root->Right;
			root->Right = root->Left;
			root->Left = NULL;
		}
		root = root->Right;
	}
}

void printList(Node **root)//print the list for CTPDLL
{
	Node *node = *root;
	printf("the list is: ");
	while (node != NULL)
	{
		printf("%d", node->key);
		if (node->Right != NULL)printf("<->");
		node = node->Right;
	}
	printf("\n");
}

void Mainoption()//option print
{
	printf("1. Load BST\n2. Insert new node\n3. Delete node\n4. Print Levelorder\n5. Print Preorder\n6. Print Inorder\n7. Print Postorder\n8. BST-Search Key\n");
	printf("9. Print Tree-Minimum\n10. Print Tree-Maximum\n11. Print Tree-Successor by Key\n12.Convert to preorder doubly link list\n13. Exit\n");
}
