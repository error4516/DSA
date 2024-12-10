#include<iostream>
using namespace std;
struct node 
{
	int data;
	struct node *next;
}*newnode,*head,*ptr,*pre;
void insertbeg(int item)
{
	newnode=new node;
	newnode->data=item;
	newnode->next=head;
	head=newnode;
}
void insertend(int item)
{
	newnode=new node;
	newnode->data=item;
	if(head==NULL)
	{
		newnode->next=head;
		head=newnode;
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
	}
}
void insertloc(int item,int l)
{
	int c=0;
	newnode=new node;
	newnode->data=item;
	if(l==1)
	{
		newnode->next=head;
		head=newnode;
	}
	else
	{
	 	ptr=head;
	 	while(ptr!=NULL)
	 	{
	 		c++;
	 		if(l==c)
	 		{
	 			break;
	 		}
	 		else
	 		{
	 			pre=ptr;
	 			ptr=ptr->next;
	 		}
	 	}
	 	newnode->next=ptr;
	 	pre->next=newnode;
	 }
}
void display()
{
	ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"->";
		ptr=ptr->next;
	}
	cout<<"NULL";
}
void deletebeg()
{
	ptr=head;
	head=head->next;
	cout<<"\n deleted node is "<<ptr->data;
	delete ptr;
	cout<<"\n Linked List after deletion: \n";
	display();
}
void deletend()
{
	ptr=head;
	while(ptr->next!=NULL)
	{
		pre=ptr;
		ptr=ptr->next;
	}
	pre->next=NULL;
	cout<<"\n deleted node is "<<ptr->data;
	delete ptr;
	cout<<"\n Linked List after deletion: \n";
	display();
	
}
void deleteatloc(int l)
{
	int c=0;
	if(l==1)
	{
		ptr=head;
		head=head->next;
		cout<<"\n deleted node is "<<ptr->data;
		delete ptr;
		cout<<"\n Linked List after deletion: \n";
		display();
	}
	else
	{
		
		ptr=head;
		while(ptr!=NULL)
		{
			c++;
			
			if(l==c)
			{
				break;
			}
			else
			{
				pre=ptr;
				ptr=ptr->next;
			}
		}
		pre->next=ptr->next;
		cout<<"\n deleted node is "<<ptr->data;
		delete ptr;
		cout<<"\n Linked List after deletion: \n";
		display();
	}
	
}
void count()
{
	ptr=head;
	int c=0;
	while(ptr!=NULL)
	{
		c++;
		ptr=ptr->next;
	}
	cout<<"\n Total number of Nodes: ="<<c;
}
void search(int key)
{
    int c=0;
    ptr=head;
    while(ptr!=NULL)
    {
    	c++;
    	if(ptr->data==key)
    	{
    		cout<<"\n"<<key<<" is found at location "<<c;
    		break;
    	}
    	else
    	{
    		ptr=ptr->next;
    	}
    }
    if(ptr==NULL)
    {
    	cout<<"\n"<<key<<" not found.";
    }
}
int main()
{
	int item,l,ch;
	do
	{
		cout<<"\n 1. Insertion at beginning";
		cout<<"\n 2. Insertion at end";
		cout<<"\n 3. Insertion at location";
		cout<<"\n 4. Display";
		cout<<"\n 5. Delete first node.";
		cout<<"\n 6. Delete last node.";
		cout<<"\n 7. Delete node at specified location";
		cout<<"\n 8. Search for an element.";
		cout<<"\n 9. Count total nodes";
		cout<<"\n 10. Exit";
		cout<<"\n enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1: 
				cout<<"\n enter data to insert";
				cin>>item;
				insertbeg(item);
				break;
			case 2:
			        cout<<"\n enter data to insert";
				cin>>item;
				insertend(item);
				break;
			case 3:
				cout<<"\n enter data to insert";
				cin>>item;
				cout<<"\n enter location at which you want to insert";
				cin>>l;
				insertloc(item,l);
				break;
			case 4:
				display();
				break;
			case 5:
			        deletebeg();
			        break;
			case 6:
				deletend();
				break;
			case 7:
				cout<<"\n enter location to delete:";
				cin>>l;
				deleteatloc(l);
				break;
			case 8:
				cout<<"\n enter data to search:";
				cin>>item;
				search(item);
				break;
			case 9:
				count();
				break;
		}
	}while(ch!=10);
}