#include<iostream>
using namespace std;
struct tree
{
	int data;
	tree*left;
	tree*right;
};
class BST
{
	public:
		tree *root,*loc,*par,*suc,*parsuc,*ptr,*save;
		BST()
		{
			root=NULL;
		}
		void createbst(int);
		
		void inorder(tree *);
		void preorder(tree *);
		void postorder(tree *);
		void deletenode(int);
		void casea(tree *,tree *);
		void caseb();
		void search(int);
		int depth(tree *);
		void printLeafNodes(tree *);
		void mirror_tree(tree*);
};
void BST::createbst(int x)
{
	tree *newnode,*ptr,*parent;
	newnode=new tree;
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{
		root=newnode;
	}
	else
	{
		ptr=root;
		while(ptr!=NULL)
		{
			parent=ptr;
			if(x>ptr->data)
			{
				ptr=ptr->right;
			}
			else
			{
				ptr=ptr->left;
			}
		}
		if(x>parent->data)
		{
			parent->right=newnode;
		}
		else
		{
			parent->left=newnode;
		}
	}
}
void BST::casea(tree *loc,tree *par)
{
	tree *child;
	if(loc->left==NULL && loc->right==NULL)
	{
		child=NULL;
	}
	else if(loc->left!=NULL)
	{
		child=loc->left;
	}
	else
	{
		child=loc->right;
	}
	if(par!=NULL)
	{
		if(loc==par->left)
		{
			par->left=child;
		}
		else
		{
			par->right=child;
		}
	}
	else
	{
		root=child;
	}
}
void BST::caseb()
{
	tree *suc,*parsuc,*ptr,*save;
	ptr=loc->right;
	save=loc;
	while(ptr->left!=NULL)
	{
		save=ptr;
		ptr=ptr->left;
	}
	suc=ptr;
	parsuc=save;
	casea(suc,parsuc);
	if(par!=NULL)
	{
		if(loc==par->left)
		{
			par->left=suc;
		}
		else
		{
			par->right=suc;
		}
	}
	else
	{
		root=suc;
	}
	suc->left=loc->left;
	suc->right=loc->right;
}
void BST::deletenode(int x)
{
	// tree *loc,*par;
	loc=root;
	while(loc!=NULL && x!=loc->data)
	{
		par=loc;
		if(x<loc->data)
		{
			loc=loc->left;
		}
		else
		{
			loc=loc->right;
		}
	}
	if(loc==NULL)
	{
		cout<<"\n "<<x<<" not found.";
	}
	if(loc->right!=NULL && loc->left!=NULL)
	{
		caseb();
	}
	else
	{
		casea(loc,par);
	}
	delete loc;
}
void BST::search(int x)
{
	if(root==NULL)
	{
		cout<<"\n tree is empty";
		return;
	}
	ptr=root;
	while(ptr!=NULL)
	{
		if(ptr->data==x)
		{
			cout<<x<<" is found.";
			break;
		}
		else if(x<ptr->data)
		{
			ptr=ptr->left;
		}
		else
		{
			ptr=ptr->right;
		}
	}
	if(ptr==NULL)
	{
		cout<<x<<" is not found";
	}
}
int BST::depth(tree *ptr)
{
	if(ptr==NULL)
	{
		return 0;
	}
	int lh=depth(ptr->left);
	int rh=depth(ptr->right);
	return (max(lh,rh)+1);
}
void BST::inorder(tree *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		cout<<ptr->data<<" ";
		inorder(ptr->right);
	}
}
void BST::preorder(tree *ptr)
{
	if(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
void BST::postorder(tree *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout<<ptr->data<<" ";
	}
}
void BST::printLeafNodes(tree *ptr)
{
	if(ptr == NULL)
	{
		return;
	}
	/* If root is leaf node, print data */if(ptr -> left == NULL && ptr -> right == NULL)
	{
		cout<<ptr -> data << " ";
		return;
	}
	/* If there exists left child, recursively call left s*/
	if(ptr->left)
	printLeafNodes(ptr -> left);
	
	/* If there exists right child, recursively call right subtree */
	if(ptr->right)
	printLeafNodes(ptr -> right);
}
void BST::mirror_tree(tree* ptr)
{
	tree* temp;
	if(ptr!=NULL)
	{
		temp = ptr->left;
		ptr->left = ptr->right;
		ptr->right = temp;
		mirror_tree(ptr->left);
		mirror_tree(ptr->right);
	}
	else
		return ;
}
int main()
{
	int ch,x,h;
	BST t=BST();
	do
	{
		cout<<"\n1. Insertion into Binary search tree";
		cout<<"\n2. Traversals";
		cout<<"\n3. Deletion from binary search tree";
		cout<<"\n4. Search";
		cout<<"\n5. Depth of a tree";
		cout<<"\n6. Print Leaf nodes";
		cout<<"\n7. Mirror of tree";
		cout<<"\n8. Exit.";
		cout<<"\n Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n Enter data to insert: ";
				cin>>x;
				t.createbst(x);
				break;
			case 2:
				cout<<"\n Inorder:";
				t.inorder(t.root);
				cout<<"\n Preorder:";
				t.preorder(t.root);
				cout<<"\n Postorder:";
				t.postorder(t.root);
				break;
			case 3:
				cout<<"\n enter data to delete: ";
				cin>>x;
				t.deletenode(x);
				break;
			case 4: 
				cout<<"\n enter data to search: ";
				cin>>x;
				t.search(x);
				break;				
			case 5:
				x=t.depth(t.root);
				cout<<"\n Depth of a tree:" <<x;
				break;
			case 6:
				t.printLeafNodes(t.root);
				break;
			case 7:
				t.mirror_tree(t.root);
				cout<<"\n Inorder display of mirror tree: ";
				t.inorder(t.root);
				break;
		}
	}
	while(ch!=8);
	return 0;
}