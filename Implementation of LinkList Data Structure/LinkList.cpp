#include<iostream>
using namespace std;

//class
class node{
	public:
		int data;
		node* next;            
	node(int value)			 	 
	{
		data=value;
		next=NULL;
	}
};

//ye function list k end/tail main value insert kare gaa
void insertAtEnd(node* &head, int value)
{
	  node* n=new node(value);
	  if(head==NULL)
	  {
	  	head=n;
	  	return;
	  }
	  node* temp=head;
	  while(temp->next!=NULL){
	  	temp=temp->next;
	  }
	  temp->next=n;
}
//ye function list k head/start main value insert kare ga
void insertAtHead(node* &head, int value)
{
	node* n=new node(value);
	n->next=head;
	head=n;
}
//ye function value search kare ga jo user input de ga or jis index pai value hoga wo return kare ga

bool search(node* head,int key){
	node* temp=head;
	if(temp!=NULL){
	while(temp!=NULL){
		if(temp->data==key){
			return true;
		}
		temp=temp->next;
	}
	return false;
	}
	else{
		cout<<"List is Empty.."<<endl;
	}
}

//ye function head ki delete kre ga
void deleteHead(node* &head)
{
	node* todelete=head;
	head=head->next;
	delete todelete;
	cout<<"Head is delete"<<endl;
}
//ye function mid or end se value delete kre ga
void deletion(node* &head, int value)
{
	//agar head khali hai
	if(head==NULL)
	{
		cout<<"Head is empty.."<<endl;
		return;
	}
	node* temp=head;
	while(temp->next->data!=value)
	{
		temp=temp->next;
	}
	node* todelete=temp->next;
	temp->next=temp->next->next;
	delete todelete;
	cout<<"Value is deleted from the list.."<<endl;
}
//ye function list k elements print kare ga
void Display(node* head)
{
	node* temp=head;
	cout<<"DATA IN THE LIST :"<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
int main()
{
	int choice,v;
	node* head=NULL;
	cout<<"PRESS 1 TO INSERT IN LINKED LIST AT THE END.."<<endl;
	cout<<"PRESS 2 TO INSERT IN LINKED LIST AT THE HEAD.."<<endl;
	cout<<"PRESS 3 TO SEARCH ELEMENT IN LINKED LIST.."<<endl;
	cout<<"PRESS 4 TO DELETE ELEMENT FROM LINKED LIST.."<<endl;
	cout<<"PRESS 5 TO DELETE HEAD OF THE LIST.."<<endl;
	cout<<"PRESS 6 TO DISPLAY LINKED LIST.."<<endl;
	cout<<"PRESS 7 TO EXIT..."<<endl;
    do
    {
    	cout<<"ENTER CHOICE 1 TO 6 :"<<endl;
    	cin>>choice;
    	switch(choice)
    	{
    		case 1:
    			{
    				cout<<"Enter value to insert at End..: ";
    				cin>>v;
    				insertAtEnd(head,v);
    				break;
				}
			case 2:
				{
					cout<<"Enter value to insert at Head..: ";
    				cin>>v;
					insertAtHead(head,v);
					break;
				}
		   case 3:
		   	{
		   		cout<<"Enter the value to search from link list..: ";
		   		cin>>v;
		   		int f;
		   		f=search(head,v);
		   		if(f==0){
		   			cout<<"Element not Found"<<endl;
				   }
				   else{
				   	cout<<"Element Found"<<endl;
				   }
		   		break;
		    }
		    case 4:
		    	{
		    	cout<<"Enter the value to delete from link list..: ";
		   		cin>>v;
		   		deletion(head,v);
		   		break;
				}
			case 5:
				{
				deleteHead(head);
		   		break;	
				}
			case 6:
				{
					Display(head);
					break;
				}
			case 7:
				{
					cout<<"EXIT"<<endl;
					break;
				}
				default:
				{
					cout<<"INVALID CHOICE.."<<endl;
				}
		}
	}
	while(choice!=7);
 return 0;	
}
