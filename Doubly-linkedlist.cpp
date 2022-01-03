#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

class Node
{
  public:
   int key;
   int data;
   Node* prev;
   Node* next;
   
   Node()
   {
       key = 0;
       data = 0;
       prev = NULL;
       next = NULL;
   }
   Node(int k,int d)
   {
       key = k;
       data = d;
   }
};

class Doublell
{
  public:
  Node * head;
  Node * tail;
  
  Doublell()
  {
      head = NULL;
      tail = NULL;
  }
  
  Doublell(Node *n)
  {
      head = n;
      tail = n;
  }
  
  //checking whether key exist and returning if
  Node* check(int k)
  {
    Node * ptr = head;
    Node * temp = NULL;
    
    while(ptr!=NULL)
    {
        if(ptr->key==k)
        {
            temp = ptr;
        }
        ptr = ptr->next;
        
    }
    return temp;
  }
  
  //Inserting an element at the start
  void insert_b(Node * n)
  {
      if(check(n->key)!=NULL)
      {
          cout<<"Entered key already exist try entering the other key"<<endl;
      }
      else
      {
          if(head==NULL)
          {
              head = n;
              tail = n;
              cout<<"Inserted at the biggning"<<endl;
          }
          else
          {
              head->prev = n;
              n->next = head;
              head = n;
              cout<<"Inserted at the biggning"<<endl;
          }
      }
  }
  //Insertion of the element at the end using tail
  void insert_e(Node * n)
  {
      if(check(n->key)!=NULL)
      {
          cout<<"Entered key already exist try entering the other key"<<endl;
      }
      else
      {
          if(tail==NULL)
          {
              tail = n;
              head = n;
              cout<<"Inserted at the end i.e as head"<<endl;
          }
          else
          {
              Node * ptr = tail;
              ptr -> next = n;
              n -> prev = ptr;
              tail = n;
          }
      }
  }
   //Insertion of the element inbetween
   void insert_between(int k,Node * n)
   {
     Node * ptr = check(k);
     Node * temp = NULL;
     if(ptr!=NULL)
     {
        if(head==NULL)
        {
            cout<<"There is no element in list try again"<<endl;
        }
        else
        {
        	n->next = ptr->next;
        	n->prev = ptr;
        	ptr->next = n;
        }
     }
   }
     
    //function for printing the list
    void print()
    {
        if(head == NULL)
        {
            cout<<"No element in the list for printing"<<endl;
        }
        else
        {
            Node * ptr =head;
            if(ptr->next==NULL)
            {
                cout<<"("<<ptr->key<<","<<ptr->data<<")"<<endl;
            }
            else
            {
                while(ptr->next!=NULL)
                {
                    cout<<"("<<ptr->key<<","<<ptr->data<<")"<<"<-->";
                    ptr = ptr->next;
                }
                cout<<"("<<ptr->key<<","<<ptr->data<<")"<<endl;
            }
        }
    }
    //Function for deleting the data
    void delete_d(int k)
    {
    	Node * ptr = check(k);
    	Node * temp;
    	Node * prev_e = head;
    	Node * current_e = head->next;
    	if(ptr == NULL)
    	{
    		cout<<"no such element/Key exist"<<endl;
		}
		else
		{
			current_e = ptr->next;
			prev_e = ptr->prev;
			
			prev_e->next = current_e;
			current_e->prev = prev_e;
			delete ptr;
			cout<<"Node Deleted succesfully"<<endl;
		}
	}
};






int main()
{
    int key1,k,d;
    int option;
    Doublell du;
    do
    {
    	
        cout<<"Enter the valid option to exicute the following functions as mentioned"<<endl;
        cout << "1.insert_b" <<endl;
        cout << "2.insert_e" <<endl;
        cout << "3.insert_between" <<endl;
        cout << "4.delete_e"<<endl;
        cout << "5.print" <<endl;
        cin>>option;
        Node * n1 = new Node();
        
        switch(option)
        {
            case 1:
            {
                cout<<"Preparing for inserting the element at the biggning..."<<endl;
                cout<<"Enter the key and data to insert"<<endl;
                cin>>k;
                cin>>d;
                n1->key = k;
                n1->data = d;
                du.insert_b(n1);
//                getch();
                break;
            }
            case 2:
            {
                cout<<"Preparing for inserting the element at the end..."<<endl;
                cout<<"Enter the key and data to insert"<<endl;
                cin>>k;
                cin>>d;
                n1->key = k;
                n1->data = d;
                du.insert_e(n1);
//                getch();
                break;
            }
            case 3:
            {
                cout<<"Enter the key after the node should be inserted"<<endl;
                cin>>key1;
                cout<<"Preparing for inserting the element..."<<endl;
                cout<<"Enter the key and data to insert"<<endl;
                cin>>k;
                cin>>d;
                n1->key = k;
                n1->data = d;
                du.insert_between(key1,n1);
//                getch();
                break;
            }
            case 4:
            	{
            		cout<<"Enter the key to delete"<<endl;
            		cin>>key1;
            		du.delete_d(key1);
//            		getch();
					break;
				}
            case 5:
            {
                du.print();
//                getch();
                break;
            }
            default:
            	{
            		cout<<"Enter the vali option"<<endl;
				}
        }
    }while(option!=0);
    
    return 0;
}
