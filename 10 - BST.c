#include<stdio.h>
#include<stdlib.h>
struct BSL
{
	int info;
	struct BSL *lptr,*rptr;
};

typedef struct BSL node;
node *root=NULL;

void Inorder(node *root)
{
	if(root!=NULL)
	{
		Inorder(root->lptr);
		printf("%d\n",root->info);
		Inorder(root->rptr);
	}
}

void Preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d\n",root->info);
		Preorder(root->lptr);
	    Preorder(root->rptr);
	}
}

void Postorder(node *root)
{
	if (root!=NULL)
	{
		Postorder(root->lptr);
		Postorder(root->rptr);
		printf("%d\n",root->info);
	}
}

node *insert(node *root,int key)
{
	if(root==NULL)
	{
		root=(node*)malloc(sizeof(node));
		root->lptr=root->rptr=NULL;
		root->info=key;
		return root;
	}
	if(key<root->info)
	{
		root->lptr=insert(root->lptr,key);
	}
	else if(key>root->info)
	{
		root->rptr=insert(root->rptr,key);
	}
	else if (key==root->info)
	{
		printf("\n Duplicate are not allowed");
	}
	return root;
}

node *search(node *root,int key)
{
	while(root!=NULL)
	{
		if(key<root->info)
		{
			search(root->lptr,key);
		}
		else if(key>root->info)
		{
			search(root->rptr,key);
		}
		else
		{
			printf("\n Element found is:%d",root->info);
			return root;
		}
		return 0;
	}
}

int main()
{
	int key,ch,i,n;
	while(1)
	{
		printf("\n 1.insert\n 2.Search\n 3.Inorder\n 4.Preorder\n 5.postorder\n 6.Exit\n");
		printf("Enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\n Enter the value of n:");
			       scanf("%d",&n);
			       for (i=0;i<n;i++)
				   {
				   	scanf("%d",&key);
				   	root=insert(root,key);
				   }
				   break;
		    case 2:printf("\n Enter the element to search:");
			       scanf("%d",&key);
				   root=search(root,key);
				   break;
			case 3:printf("\n Inorder Traversal:\n");
			       Inorder(root);
			       break;
			case 4:printf("\n Preorder Traversal:\n");
				   Preorder(root);
				   break;
			case 5:printf("\n Postorder traversal:\n");
		           Postorder(root);
				   break;
			case 6:exit(0);
			
			default:printf("\n Invalid Case");
			break;									   
	   }
	}
}
