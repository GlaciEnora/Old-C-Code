
#include <iostream>
 
using namespace std;
 
struct Node{
    int data;
    Node* link;
};
 
class Stack{
    public:
        Node* first;
        Node* head;
        
        Stack()
        {
        	first = new Node();
        	first->data = 0;
        	head = NULL;
        }
        
        void stackPush(int n)
        {
        	
		Node* ptr = new Node();
		ptr->data = n;
		ptr->link = NULL;
		first->data++;
		if (head == NULL)
		{
			head = ptr;
		}
		else 
		{
			Node* temp = head;
			while (temp->link != NULL)
			{
				temp = temp->link;
			}
		temp->link = ptr;
		}
		cout << n << " has been pushed into stack" << endl;
        }
        
        void stackPop()
        {
        	Node* temp = head;
		if (emptyStack())
		{
			cout << "Stack underflow" << endl;
		}
		
		else 
		{
			while(temp->link!=NULL)
			{
				temp = temp->link;
			}
			cout << temp->data << " has been popped from the stack" << endl;
			delElem(temp->data);
			
			first->data--;
		}
	}
		
        
       void stackTop()
       {
       		Node* temp = head;
       		while(temp->link!=NULL)
			{
				temp = temp->link;
			}
		cout << "Top location: " << temp << "\nTop data: " << temp->data << endl;
	}
		
	void delElem(int datain)
        {
        	Node* ptr = head;
        	Node* temp = new Node();
 	        while ( ptr->link != NULL && ptr->data != datain)
		        {
		            temp = ptr;
		            ptr = ptr->link;
		        }
		        
		        if (ptr->data == datain)
		            {
		            	temp->link = ptr->link;
		            	delete ptr;
		            	first->data--;
		            }
	}
	
	void display()
        {
            Node* temp = head;
            while(temp != NULL)
            {
                cout << temp << "->" << temp->data << endl;
                temp = temp->link;
            }
        }
        
        bool emptyStack()
        {
        	if(first->data == 0)
        	{	
        		return true;
        	}
        	else
        	{
        		return false;
        	}
        }
        
        bool fullStack()
        {
        	Node* Nnode = new Node();
        	if (Nnode == NULL)
        	{
        		return true;
        	}
        	else
        	{
        		return false;
        	}
        }
};

int main()
{
	class Stack stk;
	int key=0, elem;
	
	while(key != -1)
	{
		cout << "Enter the option to perform on stack: " << endl;
		cout << "1-Push, 2-Pop, 3-StackTop, 4-display, -1 to exit" << endl;
		cin >> key;
		
		switch(key)
		{
			case 1:
				cout << "Enter the element to push into stack: ";
				cin >> elem;
				stk.stackPush(elem);
				break;
				
			case 2:
				stk.stackPop();
				break;
				
			case 3: 
				stk.stackTop();
				break;
			
			case 4: 
				stk.display();
				break;
			
			default:
				if (key!= -1)
				{
					cout << "Invalid key, try again" ;
					break;
				}
				
				else
				{
					cout << "Ending process. . . .";
					break;
				}
				
		}
	}

	cout << "\n\nTerminating program. . . . ";
	
	return 0;
}

