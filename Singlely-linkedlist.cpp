#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class Node
{
public:
  int key;
  int data;
  Node *next;

    Node ()
  {
    key = 0;
    data = 0;
    next = NULL;
  }
  Node (int k, int d)
  {
    key = k;
    data = d;
  }
};

class Singlell
{
public:
  Node * head;
  Singlell ()
  {
    head = NULL;
  }
  Singlell (Node * n)
  {
    head = n;
  }
  //Checking whether node exist using key
  Node *n_exist (int k)
  {
    Node *temp = NULL;
    Node *ptr = head;
    while (ptr != NULL)
      {
	if (ptr->key == k)
	  {
	    temp = ptr;
	  }
	ptr = ptr->next;

      }
    return temp;
  }
  //Inserting the node at the bigging of the list
  void insert_b (Node * n)
  {
    if (n_exist (n->key) != NULL)
      {
	cout << "Node key already exist enter a valid one" << endl;
      }
    else
      {
	if (head == NULL)
	  {
	    head = n;
	    cout << "Node added at the bigging" << endl;
	  }
	else
	  {
	    n->next = head;
	    head = n;
	    cout << "Node added at the bigging" << endl;
	  }
      }
  }
  //insert the node at the ending 
  void insert_e (Node * n)
  {
    if (n_exist (n->key) != NULL)
      {
	cout << "Node key already exist enter a valid one" << endl;
      }
    else
      {

	if (head == NULL)
	  {
	    head = n;
	    cout << "Node added at the end" << endl;
	  }
	else
	  {
	    Node *ptr = head;
	    while (ptr->next != NULL)
	      {
		ptr = ptr->next;
	      }
	    ptr->next = n;
	    cout << "Node added at the end" << endl;
	  }
      }
  }
  //Inserting the Node at the bigning
  void insert_between (int k, Node * n)
  {
    Node *ptr = n_exist (k);
    if (ptr == NULL)
      {
	cout << "No key exist try again" << endl;
      }
    else
      {
	if (n_exist (n->key) != NULL)
	  {
	    cout << "Node key already exist enter a valid one" << endl;
	  }
	else
	  {
	    n->next = ptr->next;
	    ptr->next = n;
	    cout << "Element inserted inbetween" << endl;

	  }
      }
  }
  //Dislinking the link of an Element
  void delete_e (int k)
  {
    Node * ptr = NULL;
    Node * temp = NULL;
    Node * prev_e = head;
    Node * current_e = head->next;
    while (current_e != NULL)
      {
	if (current_e->key == k)
	  {
	    temp = current_e;
	    current_e = NULL;
	  }
	else
	  {
	    prev_e = prev_e->next;
	    current_e = current_e->next;
	  }
      }
	if (temp != NULL)
	  {
	    prev_e->next = temp->next;
	    cout << "Node deleted" << endl;
	  }
	else
	  {
	    cout << "There is no key as you enterd. Enter the valid one" <<
	      endl;
	  }
      

    //   if(head == NULL)
    //   {
    //       cout<<"There is no element in the list to delete"<<endl;
    //   }
    //   else
    //   {
    //       while(prev_e != ptr)
    //       {
    //          prev_e = prev_e ->next;
    //          current_e = current_e->next;
    //       }
    //       prev_e->next = current_e;
    //       ptr -> next = NULL;
    //       cout<<"Node deleted"<<endl;
    //   }
  }
  void print_e()
  {
      Node * ptr = head;
      if(ptr == NULL)
      {
          cout<<"Linked list is Empty"<<endl;
      }
      else if(ptr ->next == NULL)
      {
          cout<<"("<<ptr->key<<","<<ptr->data<<")"<<endl;
      }
      else
      {
          while(ptr->next!=NULL)
          {
              cout<<"("<<ptr->key<<","<<ptr->data<<")"<<"-->"<<endl;
              ptr = ptr->next;
          }
          cout<<"("<<ptr->key<<","<<ptr->data<<")"<<endl;
      }
  }
};

int
main ()
{
  Singlell s;
  int k, key1, d;
  int option;

  do
    {
      system ("cls");
      cout << "Select the option according to the function use" << "\n" <<
	"Choose option 0 to exist the screen" << endl;
      cout << "1.insert_b" << endl;
      cout << "2.insert_e" << endl;
      cout << "3.insert_between" << endl;
      cout << "4.delete" <<endl;
      cout << "5.print" <<endl;
      cin >> option;
      Node *n1 = new Node ();
      switch (option)
	{
	case 1:
	  {
	    cout <<
	      "Preparing for inserting...please enter the values of key and data"
	      << endl;
	    cin >> k;
	    cin >> d;
	    n1->key = k;
	    n1->data = d;
	    s.insert_b (n1);
	    break;
	  }
	case 2:
	  {
	    cout <<
	      "Preparing for inserting at the end...please enter the values of key and data"
	      << endl;
	    cin >> k;
	    cin >> d;
	    n1->key = k;
	    n1->data = d;
	    s.insert_e (n1);
	    break;
	  }
	case 3:
	  {
	    cout <<
	      "Enter the key value after where the eleement should be inserted"
	      << endl;
	    cin >> key1;
	    cout <<
	      "Preparing for inserting inbetween...please enter the values of key and data"
	      << endl;
	    cin >> k;
	    cin >> d;
	    n1->key = k;
	    n1->data = d;
	    s.insert_between (key1, n1);
	    break;
	  }
	  case 4:
	  {
	      cout<<"Enter the key to delete"<< endl;
	      cin>>key1;
	      cout<<"Prepearing to delete the element you entered..."<< endl;
	      s.delete_e (key1);
	      break; 
	  }
	  case 5:
	  {
	      cout<<"The elements in the list are : "<<endl;
	      s.print_e();
	      break;
	  }
	default:
	  {
	    cout << "Bmsdk enter the valid one" << endl;
	  }
	}


    }
  while (option != 0);
  return 0;
}
