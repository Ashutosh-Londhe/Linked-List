#include <iostream>
#include <limits>

using namespace std;

class node
{
                 int data;
                 node *next;
public:
                 node()
                {
                       this->data = 0;
                       this->next = NULL;
                }
                node(int _data)
               {
                       this->data = _data;
                       this->next = NULL;
                }
                void print()
                {
                       cout<<"\n data: "<<this->data;
                }
                friend class list;
};

class list
{
                node *head;
public:
                list()
                {
                       head = NULL;
                }

                bool isEmpty()
                {
                       return (this->head == NULL);
                }

                void addfirst(int data)
                {
                       node *obj = new node(data);
                       if(isEmpty())
                      {
                             this->head = obj;
                      }
                      else
                      {
                             obj->next = head;
                             head = obj;
                      }
                }//End of addfirst function



                void addlast(int data)
                {
                      node *obj = new node(data);
                      if(isEmpty())
                      {
                              this->head = obj;
                      }
                      else
                      {
                              node *current = this->head;
                              while(current->next != NULL)
                                        current = current->next;
                              current->next = obj;
                      }
                }//End of addlast function
    
                void reverselist(node **head_ref)
                {
		      if(!isEmpty())
		      {	
		       	  node *current = *head_ref;
                      	  node *next=NULL, *prev=NULL;
                          while(current != NULL)
                          {
                              next = current->next;
                              current->next = prev;
                              prev = current;
                              current = next;
                          }
                          *head_ref = prev;
		      }
		      else
		      {
			  cout<<"\n List is empty....";
		      }
                }//End of reverselist function

                node* reverseKElement(node *head_ref, int k)
                {
                 	if(!isEmpty())
			{
			    node *current = head_ref;
                            node *next=NULL, *prev=NULL;
                            int count = 0;

                            //Reverse first k nodes on the linked list
                            while(current != NULL && count < k)
                            {
                                 next = current->next;
                                 current->next = prev;
                                 prev = current;
                                 current = next;
                                 count++;
                            }

                            /* current OR next is k+1th node in linked list. Call recursively reverse for list 
                               starting from current node*/
                               if(current != NULL)
                                     head_ref->next = reverseKElement(current, k);
                               /* OR if(next != NULL)
                                       head_ref->next = reverseKElement(next, k);  */

                            //prev is new head of the list
                            return prev;
			}
			else
                        {
                            cout<<"\n List is empty....";
                        }
                }//End of reverseKElement function

                void ispalindrome()
                {
                     int result = 0;
                     node *fast_ptr = this->head;
                     node *slow_ptr = this->head;
                     node *prev_of_slow_ptr = this->head;
                     node *mid = NULL, *second_half = NULL;

                     if(!isEmpty())
                     {
                             //Find middle of list
                             while(fast_ptr != NULL && fast_ptr->next != NULL)
                             {
                                       fast_ptr =  fast_ptr->next->next;
                                       prev_of_slow_ptr = slow_ptr;
                                       slow_ptr = slow_ptr->next;
                             }

                             /* if fast_ptr is null then our list contain even element and not_null when our list 
                                 contain odd element.
                                 For odd element we need to skip middle element and store it somewhere for
                                 restoring original list*/
                             if(fast_ptr != NULL)
                             {
                                       mid = slow_ptr;
                                       slow_ptr = slow_ptr->next;
                             }

                             //Reverse the second half of the list
                             second_half = slow_ptr;
                             prev_of_slow_ptr->next = NULL;      //terminate first half
                             reverselist(&second_half);

                             result = comparelist(this->head, second_half);

                             reverselist(&second_half);          //Reverse again to get original list back

                             if(mid != NULL)
                             {
                                       prev_of_slow_ptr->next = mid;
                                       mid->next = second_half;
                             }
                             else
                             {
                                       prev_of_slow_ptr->next = second_half;
                             }
			     if(result == 1)
				 cout<<"\n List is Palindrome";
                             else
                                 cout<<"\n List is NOT Palindrome";
                     }
		     else
		     {
			  cout<<"\n List is empty....";
		     }	
                     
                }//End of ispalindrome function

                int comparelist(node *head1, node *head2)
                {
                     while(head1!=NULL && head2!=NULL)
                     {
                             if(head1->data == head2->data)
                             {
                                       head1 = head1->next;
                                       head2 = head2->next;
                             }
                             else
                             {
                                       return 0;
                             }
                     }
                     return 1;
                }//End of comparelist function

                node* gethead()
                {
                     return this->head;
                }

                node** getheadadd()
                {
                     return &this->head;
                }

                void sethead(node *_head)
                {
                     this->head = _head;
                }

                void print()
                {
                     if(isEmpty())
                    {
                             cout<<"\n List is empty";
                    }
                    else
                    {
                             cout<<"\n List is: ";
                             node *obj = head;
                             while(obj != NULL)
                             {
                                       cout<<obj->data<<"->";
                                       obj = obj->next;
                              }
                              cout<<"NULL";
                    }
                }//End of print function
 };  //End of class list

int acceptData()
{
    int data;
    cout<<"\n Enter data (integer): ";
    cin>>data;
    if(cin.fail())
    {
	    cin.clear();
    	    cin.ignore(numeric_limits<streamsize>::max(),'\n');
	    cout<<"\n Please enter integer numbers only";
	    return -11011;
    }
    return data;
}// End of acceptData function


int menuList()
{
    int choice;
    cout<<"\n 0. Exit";
    cout<<"\n 1. Add First";
    cout<<"\n 2. Add Last";
    cout<<"\n 3. Check Palindrome/not";
    cout<<"\n 4. Reverse complete list";
    cout<<"\n 5. Reverse k elements";
    cout<<"\n 6. Print List";
    cout<<"\n Enter your choice: ";
    cin>>choice;
    return choice;
}//End of menuList function

int main()
{
    int choice, data, k;
    list List;
    while((choice = menuList()) !=0)
    {
        switch(choice)
        {
            case 1:   data = acceptData();
                           List.addfirst(data);
                           break;
            case 2:    data = acceptData();
		       	   if(data != -11011)
                           	List.addlast(data);
                           break;
            case 3:    List.ispalindrome(); 
                           break;
            case 4:    List.reverselist(List.getheadadd());
                           break;
            case 5:    cout<<"\n Enter size of group to be reversed: ";
                           cin>>k;
                           List.sethead(List.reverseKElement(List.gethead(), k));
                           break;
            case 6:    List.print();
                           break;
        }
    }

    return 0;
}//End of main function

