#include <iostream>
using namespace std;


            //CREATING THE DATA STRUCTURE
            struct ListNode {
              int data;
              struct ListNode *link;
            };
            struct ListNode *head=NULL;

            //CREATES BLUEPRINT OF A NODE
            struct ListNode* CreateNode()
            {
              struct ListNode *n1;
              n1 = (struct ListNode*)malloc(sizeof(ListNode));
              return n1;
            }

//INSERTION AT THE START 
void InsertNodeStart(){
  struct ListNode *temp, *t;
  temp = CreateNode();
  cout<<"Enter a number :";
  cin>>temp->data;
  temp->link=NULL;
  if(head==NULL){
    head = temp;
  }
  else{
    t = head;
    head = temp;
    temp->link = t;
  }
}

//INSERTION AT NTH POSITION
void InsertNodeNth(int n){
  struct ListNode *temp, *t1, *t2;
  temp = CreateNode();
  cout<<"Enter a number to be inserted at "<<n<<" th position :";
  cin>>temp->data;
  temp->link=NULL;

  t1 = head;
  t1 = t1->link;
  t2 = head;
  for(int i=0;i<n-1;i++){
    t1 = t1->link;
    t2 = t2->link;
  }
  t2->link = temp;
  temp->link = t1;
}

//INSERTION AT THE END
void InsertNodeEnd(){
  struct ListNode *temp, *t; 
  temp = CreateNode();
  cout<<"Enter a number :";
  cin>>temp->data;
  temp->link=NULL;
  
  if(head==NULL){
    head = temp;
  }
  else{
    t = head;
    while(t->link!=NULL){
      t = t->link;
    }
    t->link = temp;
  }

}

//DELETION AT THE BEGINING
void DeleteNodeStart(){
  struct ListNode *t;
  if(head==NULL){
    cout<<"List is empty";
  }
  else{
    t = head;
    head = head->link;
    free(t); 
  }
}

//DELETION AT NTH POSITION
void DeleteNodeNth(int n){
  if(head==NULL){
    cout<<"List is empty";
  }
  else{
    struct ListNode *t1, *t2;
    t1 = head;
    t1 = t1->link;
    t2 = head;
    for(int i=0;i<n-1;i++){
      t1 = t1->link;
      t2 = t2->link;
    }
    t2->link = t1->link;
    free(t1);
  }
}

//DELETION AT THE END
void DeleteNodeEnd(){
  struct ListNode *t1, *t2;
  if(head==NULL){
    cout<<"List is empty";
  }
  else{
    t1 = head;
    t1 = t1->link;
    t2 = head;
    while(t1->link!=NULL){
      t1 = t1->link;
      t2 = t2->link;
    }
    t2->link = NULL;
    free(t1);
  }
}

//TRAVERSING ALL NODES AND EXTRACTING THEIR DATA
void TraverseNodes(){
  if(head==NULL){
    cout<<"Linked list is null";
  }
  else{
    struct ListNode *t;
    t = head;
    while(t!=NULL){
      cout<<t->data<<" ";
      t = t->link;
    }
  }
}

int main(){

  int choice, n1, n2;
  while(1){
  cout<<endl<<"Enter 1 for insertion at the begining "<<endl;
  cout<<"Enter 2 for insertion at the nth position "<<endl;
  cout<<"Enter 3 for insertion at the end "<<endl;
  cout<<"Enter 4 for deletion at the begining "<<endl;
  cout<<"Enter 5 for deletion at the nth position "<<endl;
  cout<<"Enter 6 for insertion at the end "<<endl;
  cout<<"Enter 7 for full travarsel "<<endl;
  cout<<"Selected choice : ";
  cin>>choice;

  switch(choice){
    case 1:
      InsertNodeStart();
      break;
    case 2:
      cout<<"Enter the position where u wanna insert a node : ";
      cin>>n1;
      InsertNodeNth(n1);
      break;
    case 3:
      InsertNodeEnd();
      break;
    case 4:
      DeleteNodeStart();
      break;
    case 5:
      cout<<"Enter the position where u wanna delete a node : ";
      cin>>n2;
      DeleteNodeNth(n2);
      break;
    case 6:
      DeleteNodeEnd();
      break;
    case 7:
      TraverseNodes();
      break;
    default:
      exit(0);
    }
  }
  return 0;
}