#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Node//struct Node
{
	struct Node *Par, *Left, *Right;
	int key;
	int level;//Balance
	int high;
}Node;

void Mainoption();//option func
void BuildAVL(Node**, int*);//load AVL func
void InsertAVL(Node**, int);//insert to AVL func
void Delete(Node*);//delet from AVL func
void FreeTree(Node**, int*);//free tree func
void PrintLevelorder(Node*);//print level order func
void PrintPreorder(Node*);//print pre order func
void PrintInorder(Node*);//print in order func
void PrintPostorder(Node*);//print post order func
void printList(Node **);//print list for *CTPDLL func
Node* AVLSearch(Node**, int);//AVL search func
Node* TreeMin(Node*);//min number in AVL func
Node* TreeMax(Node*);//max number in AVL func
Node* TreeSuccessor(Node*, Node*);//successor in AVL func
void ConvertToPreorderDoublyLinkList(Node*, Node**);//*CTPDLL func
void FixAllAVLTree(Node **);//fix the Balance in all AVL tree
void PrintTableAvlTree(Node*);// print table whit the Balance
void FindMyHigh(Node*);//find the high of node
int FindMyLevel(Node*);//find the level(Balance factors) of node
Node* FixAVLTree(Node*);//fix avl tree whit func Balance factors

int main()//main func
{
	Node **Tree = (Node**)malloc(sizeof(Node));//Tree pointer
	Node *Temp = *Tree;
	Node *TempN = *Tree;
	*Tree = NULL;
	int array[] = { 11,6,4,5,8,10,19,17,43,31,49 };//array for example
	int level = 4;//level Tree
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
			printf("Building AVL: \n");
			BuildAVL(Tree, array);
			printf("Enter any number to back to main...");
			scanf("%d", &key);
			break;
		case 2:
			system("@cls||clear");
			printf("Insert new node:");
			scanf("%d", &key);
			InsertAVL(Tree, key);
			printf("Enter any number to back to main...");
			scanf("%d", &key);
			break;
		case 3:
			system("@cls||clear");
			printf("Delete node: \n");
			scanf("%d", &key);
			Delete(AVLSearch(Tree, key),Tree);
			FixAllAVLTree(Tree);
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
			printf("AVL-Search by Key:");
			scanf("%d", &key);
			Temp = AVLSearch(Tree, key);
			if (Temp != NULL)printf("the number %d found\n",key);
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
			TempN = TreeSuccessor(AVLSearch(Tree, key), Tree);
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
		case 13:
			system("@cls||clear");
			printf("Balance factors: \n");
			printf("|");
			PrintTableAvlTree(*Tree, 'K');
			printf("\n");
			printf("|");
			PrintTableAvlTree(*Tree, 'L');
			printf("\n");
			printf("Enter any number to back to main...");
			scanf("%d", &key);
			break;
		case 14://exit and free tree
			free(Tree);
			exit(1);
			break;
		}
	} while (1);
	printf("error");
}

void BuildAVL(Node **root, int *array)//load AVL func//***********
{
	for (int i = 0; i < 11; i++)
	{
		InsertAVL(root, array[i]); // insert to AVL func
	}
	printf("The AVL Tree Build successfully\n");
}

void InsertAVL(Node **root, int data)// insert to AVL func/*************
{
	Node *NewTree = (Node*)malloc(sizeof(Node));
	NewTree->key = data;
	NewTree->Left = NULL;
	NewTree->Right = NULL;
	NewTree->Par = NULL;
	NewTree->high = -1;
	Node *Temp = *root;
	//insert by Rules of AVL tree
	if (*root == NULL)*root = NewTree;
	else
	{
		while (Temp != NULL)
		{
			NewTree->Par = Temp;
			if (Temp->key > NewTree->key)
			{
				if (Temp->Left == NULL)
				{
					Temp->Left = NewTree;
					Temp = Temp->Left;
					Temp->high = Temp->Par->high + 1;
				
				}
				Temp = Temp->Left;

			}
			else
			{
				if (Temp->Right == NULL)
				{
					Temp->Right = NewTree;
					Temp = Temp->Right;
					Temp->high = Temp->Par->high + 1;
				}
				Temp = Temp->Right;
			}
		}
		FixAllAVLTree(root);//fix all avl tree whit func Balance factors
	}

	printf("%d add to the AVL Tree\n", data);
}

void Delete(Node *node,Node**root)//delete node from AVL tree by rules/***********
{
	Node*Temp = node;
	Node*TN = NULL;
	if (node == NULL)return 0;
	int key = node->key;
	if (node->Left == NULL&&node->Right == NULL)
	{
		TN = node->Par;
		if (node == TN->Right)TN->Right = NULL;
		if (node == TN->Left)TN->Left = NULL;
		free(node);
	}
	else if (node->Left == NULL)//left tree
	{
		if (Temp->Par->Left == node)
		{
			Temp->Par->Left = node->Right;
			Temp->Left->Par = node->Par;
		}
		if (Temp->Par->Right == node)
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
		TN = TreeSuccessor(node, root);
		node->key = TN->key;
		TN->key = key;
		Delete(TN, root);
	}
}

void PrintLevelorder(Node *root, int level)//level order print 
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
		printf("%d, ", root->key);
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
		printf("%d, ", root->key);
	}
}

Node* AVLSearch(Node **root, int key)//search in AVL tree by value/************
{
	Node *Temp = *root;
	while (Temp != NULL)
	{
		if (Temp->key == key)return Temp;
		if (Temp->key > key)
		{
			Temp = Temp->Left;
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
	while (root->Left != NULL)
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

Node* TreeSuccessor(Node*node, Node**root)//found the successor number in AVL tree by rules
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
	printf("1. Load AVL\n2. Insert new node\n3. Delete node\n4. Print Levelorder\n5. Print Preorder\n6. Print Inorder\n7. Print Postorder\n8. AVL-Search Key\n");
	printf("9. Print Tree-Minimum\n10. Print Tree-Maximum\n11. Print Tree-Successor by Key\n12.Convert to preorder doubly link list\n13. Print Balance factors\n14.Exit\n");
}

void FixAllAVLTree(Node **root)//fix the Balance in all AVL tree
{
	int* PT = (int*)malloc(sizeof(int));
	*PT = 0;
	FindMyLevel(*root, PT);//find the level(Balance factors) of node
	while (*PT != 0)
	{
		if (*root == AVLSearch(root, *PT))*root = FixAVLTree(AVLSearch(root, *PT));
		else
		{
			Node *tempN = AVLSearch(root, *PT);
			tempN = tempN->Par;
			if (tempN->Left == AVLSearch(root, *PT))tempN->Left = FixAVLTree(AVLSearch(root, *PT));//fix avl tree whit func Balance factors
			if (tempN->Right == AVLSearch(root, *PT))tempN->Right = FixAVLTree(AVLSearch(root, *PT));//fix avl tree whit func Balance factors
		}
		FindMyHigh(*root);//find the high of node
		*PT = 0;
		FindMyLevel(*root, PT);//find the level(Balance factors) of node
	}
}

void PrintTableAvlTree(Node *root,char choice)
{
	if (root != NULL&&choice=='K')
	{
		PrintTableAvlTree(root->Left,'K');
		printf("%3i |", root->key);
		PrintTableAvlTree(root->Right,'K');
	}
	if (root != NULL&&choice == 'L')
	{
		PrintTableAvlTree(root->Left, 'L');
		printf("%3i |", root->level);
		PrintTableAvlTree(root->Right, 'L');
	}
}

int FindMyLevel(Node *root,int* problemTree)//fill the level AVL tree
{
	int TempL = 0;
	int TempR = 0;
	if (root->Left != NULL)
	{
		int temp = FindMyLevel(root->Left, problemTree);//return the high of the sub tree
		if (temp > TempL)TempL = temp;
	}
	if (root->Right != NULL)
	{
		int temp=FindMyLevel(root->Right, problemTree);//return the high of the sub tree
		if (temp > TempR)TempR = temp;
	}
	if (root->Left == NULL &&root->Right == NULL)
	{
		root->level = 0;
		return root->high;//return the high of the sub tree
	}
	if (TempL == 0)//do the func of AVL tree for level 
	{
		root->level = (TempL - (TempR - (root->high)));
		if ((root->level == 2 || root->level == -2)&&(*problemTree==0))*problemTree = (root->key);
		return TempR;
	}
	else if (TempR == 0)
	{
		root->level = ((TempL - (root->high)) - TempR);
		if ((root->level == 2 || root->level == -2) && (*problemTree == 0))*problemTree = (root->key);
		return TempL;
	}
	else
	{
		root->level = (TempL - TempR);
		if ((root->level == 2 || root->level == -2) && (*problemTree == 0))*problemTree = (root->key);
		return (TempL > TempR ? TempL : TempR);
	}
}

void FindMyHigh(Node *root)//find the high of node
{
	if (root->Par == NULL)root->high = 0;
	else root->high = (root->Par->high)+ 1;
	if(root->Left!=NULL)FindMyHigh(root->Left);
	if (root->Right != NULL)FindMyHigh(root->Right);
	return 0;
}

Node* FixAVLTree(Node* root)//fix avl tree whit func Balance factors
{
	Node* temp;
	if (root->level == -2)
	{
		if (root->Right->level == 1)//RL
		{
			//part 1
			temp = root->Right->Left;
			root->Right->Left = temp->Right;
			temp->Right = root->Right;
			temp->Par = root;
			root->Right->Par = temp;
			root->Right = temp;
			//part 2
			temp = root;
			root = root->Right;
			root->Par = temp->Par;
			temp->Right = root->Left;
			if (temp->Right != NULL)temp->Right->Par = temp;
			root->Left = temp;
			temp->Par = root;
		}
		else//RR
		{
			temp = root;
			root = root->Right;
			root->Par = temp->Par;
			temp->Right = root->Left;
			if (temp->Right != NULL)temp->Right->Par = temp;
			root->Left = temp;
			temp->Par = root;
		}
	}
	if (root->level == 2)
	{
		if (root->Left->level == -1)//LR
		{
			//part 1
			temp = root->Left->Right;
			root->Left->Right = temp->Left;
			temp->Left = root->Left;
			temp->Par = root;
			root->Left->Par = temp;
			root->Left = temp;
			//part 2
			temp = root;
			root = root->Left;
			root->Par = temp->Par;
			temp->Left = root->Right;
			if (temp->Left != NULL)temp->Left->Par = temp;
			root->Right = temp;
			temp->Par = root;
		}
		else//LL
		{
			temp = root;
			root = root->Left;
			root->Par = temp->Par;
			temp->Left = root->Right;
			if(temp->Left!=NULL)temp->Left->Par = temp;
			root->Right = temp;
			temp->Par = root;
		}
	}
	return root;
}
