#include <bits\stdc++.h>
#define SPACING 5
using namespace std;
class Tree
{
	public:
		int data;
		Tree * left;
		Tree * right;
		
	Tree()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
	
	Tree(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

class BST
{
	public:
		Tree * root;
		
	BST()
	{
		root = NULL;
		}
			
	//INSERTING A VARIABLE IN TREE
	void insert_v(Tree * r)
	{
		if(root == NULL)
		{
			root = r;
			cout<<"INSERTED SUCESSFULLY (as root node)"<<endl;
		}
		else
		{
			Tree * ptr = root;
			while(ptr!=NULL)
			{
				if((r->data <= ptr->data) and ptr->left == NULL)
				{
					ptr->left = r;
					cout<<"INSERTED SUCESSFULLY (as left child)"<<endl;
					break;
				}
				else if(r->data>ptr->data and ptr->right == NULL)
				{
					ptr->right = r;
					cout<<"INSERTED SUCESSFULLY (as right child)"<<endl;
					break;
				}
				else if(r->data <= ptr->data)
				{
					ptr = ptr->left;
				}
				else
				{
					ptr = ptr->right;
				}
			}
		}
	}
	
	//PRINTING THE DATA TREE IN 2D FORM
	void print2D(Tree * r,int space)
	{
		if(r == NULL)
		{
			return;
		}
		space = space + SPACING;
		print2D(r->right,space);
		cout<<"\n";
		for(int i = SPACING;i<space;i++)
		{
			cout<<" ";
		}
		cout<< r->data <<endl;
		print2D(r->left,space);
	}
	//PRINTING PREORDER
	void pre_o(Tree * r)
	{
		if(r == NULL)
		{
			return;
		}
		cout<<r->data<<",";
		pre_o(r->left);
		pre_o(r->right);
	}
	//PRINTING INORDER
	void in_o(Tree * r)
	{
		if(r == NULL)
		{
			return;
		}
		in_o(r->left);
		cout<<r->data<<",";
		in_o(r->right);
	}	
	//PRINTING POSTORDER
	void pos_o(Tree * r)
	{
		if(r == NULL)
		{
			return;
		}
		pos_o(r->left);
		pos_o(r->right);
		cout<<r->data<<",";
	}
	//SEARCHING A DATA
	bool search(Tree * r,int val)
	{
		if(r == NULL)
		return false;
		Tree * ptr = r;
		while(ptr!=NULL)
		{
			if(ptr->data == val)
			return true;
			else if(val < ptr->data)
			ptr = ptr->left;
			else
			ptr = ptr->right;
		}
		return false;
	}
	//FINDING THE HEIGHT OF TREE
	int height(Tree * r)
	{
		if(r == NULL)
		return -1;
		int lh = height(r->left);
		int rh = height(r->right);
		if(lh > rh)
		return (lh+1);
		else
		return (rh+1);
	}
};

int main()
{
	BST b;
	int d,option;
	do
	{
		//cout<<"       >>BINARY SEARCH TREE<<"<<endl;
		cout<<"Choose the option accordingly"<<endl;
		cout<<"0. Exist"<<endl;
		cout<<"1. Insert data"<<endl;
		cout<<"2. Print data in 2D form"<<endl;
		cout<<"3. Print the tree data"<<endl;
		cout<<"4. Print Height"<<endl;
		cout<<"5. Search a data"<<endl;
		Tree * t = new Tree();
		cin>>option;
		switch(option)
		{
			
			case 1:
				cout<<"Enter the data you want to insert"<<endl;
				cin>>d;
				cout<<"PROCESSING..."<<endl;
				t->data = d;
				b.insert_v(t);
			    break;
			case 2:
				cout<<"The data is here"<<endl;
				b.print2D(b.root,5);
				break;
			case 0:
				break;
			case 3:
				cout<<"pre_order"<<"[";
				b.pre_o(b.root);
				cout<<"]"<<endl;
				cout<<"in_order "<<"[";
				b.in_o(b.root);
				cout<<"]"<<endl;
				cout<<"pos_order"<<"[";
				b.pos_o(b.root);
				cout<<"]"<<endl;
				break;
			case 4:
				cout<<"The height of the tree is: "<<b.height(b.root)<<endl;
				break;
			case 5:
				cout<<"Enter the value that you want to search"<<endl;
				cin>>d;
				if(b.search(b.root,d))
				cout<<"The data entered is present in the Tree"<<endl;
				else
				cout<<"The data entered is not present in the Tree"<<endl;
		}
	}while(option!=0);
}
