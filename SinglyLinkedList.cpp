#include <iostream>
 
using namespace std;
 
struct Node{
    int data;
    Node* link;
};
 
class List{
    public:
        Node* first;
        Node* head;
       
        List()
        {
            first = new Node();
            first->data = 0;
            head = NULL;        
        }
           
        void Insert_atBeg(int datain)
        {
        	Node* ptr = new Node();
        	first->data++;
        	first->link = ptr;
        	ptr->data = datain;
        	ptr->link = head;
        	head = ptr;
		}
		
	void Insert_atEnd(int datain)
	{
		Node* ptr = new Node();
		ptr->data = datain;
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
	}
	
        void Insert_atPos(int data, int pos)
        {	  
	  int count = 1;
          Node* temp = head;
          
          while(temp != NULL && count < pos)
          {
          	temp = temp->link;
          	count++;
		  }
		  
		  if (temp != NULL && pos != 0)
		  {
		  	first->data++;
		  	Node* ptr = new Node();
		  	ptr->data = data;
		  	ptr->link = temp->link;
		  	temp->link = ptr;
		  }
		  else if (pos == 0)
		  {
		  	Insert_atBeg(data);
		  }
		  else
		  {
		  	cout << "Invalid position" << endl;
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
        
       void Delete_Node(int datain)
        {
        	if(Empty_List())
        	{
        		cout << "List is empty. . . " << endl;
        		return;
        	}
        	Node* ptr = head;
        	Node* itr = ptr->link;
        	if ( ( ptr->data == datain ) )
			    {
			        Node *temp = ptr;
			        head = head->link;
			        delete temp;
			        first->data--;
			    }
    		else
			    {
	                        Node* temp = new Node();
			        while ( itr != NULL && ptr->data != datain)
			        {
			            temp = ptr;
			            ptr = ptr->link;
			            itr = itr->link;
			        }
			        
			        if (ptr->data == datain)
			            {
			            	temp->link = ptr->link;
			            	delete ptr;
			            	first->data--;
			            }
			    }
	}
		bool Empty_List()
		{
			if (first->data == 0)
			{
				return true;
			}
			
			else
			{
				return false;;
			}
		}
		
		void List_Count()
		{
			cout << "The list has " << first->data << " elements." << endl;
		}
		
		void Search_List(int datain)
		{
			Node* itr = new Node();
			itr = head;
			while(itr->data != datain)
			{
				//temp = itr;
				itr = itr->link;
			}
			if (itr->data == datain)
			{
				cout << "Element found\nAddress is " << itr << "\nData contained: " << itr->data << endl;
			}
			
			else 
			{
				cout << "Element does not exist in list" << endl;
			}
		}
		
};
 
int main()
{
    List linklist;
    int key = 0, elem, pos;
    while(key != -1)
    {
    	cout << "Enter the list operations to perform" << endl;
    	cout << "1-Insert at Beginning\t2-Insert at End\t3-Insert at Pos\t4-Delete Node\n5-List Count\t6-Search List\t7-Display list\t-1 to terminate" << endl;
    	cin >> key;
    	
    	switch(key)
    	{
    		case 1:
    			cout << "Enter element to insert at beginning: ";
    			cin >> elem;
    			linklist.Insert_atBeg(elem);
    			break;
    			
    		case 2:
    			cout << "Enter element to insert at end: ";
    			cin >> elem;
    			linklist.Insert_atEnd(elem);
    			break;
    			
    		case 3:
    			cout << "Enter element and position to insert at: ";
    			cin >> elem >> pos;
    			linklist.Insert_atPos(elem, pos);
    			break;
    		
    		case 4:
    			cout << "Enter element to delete: ";
    			cin >> elem;
    			linklist.Delete_Node(elem);
    			break;
    		
    		case 5:
    			linklist.List_Count();
    			break;
    			
    		case 6: 
    			cout << "Enter element to search for: ";
    			cin >> elem;
    			linklist.Search_List(elem);
    			break;
    			
    		case 7: 
    			linklist.display();
    			break;
    			
    		default: 
    			if (key != -1)
    			{
    				cout << "No function found, try again or enter -1 to terminate" << endl;
    			}
    			else
    			{
    				cout << "Terminating sequence" << endl;
    			}
    			break;
    		}
    }
    	
}



