  
   /* Help of this program we are learning how to
   delete all odd key nodes of linked list.*/

/*include header file*/
#include<stdio.h>
#include<stdlib.h>


/*Structure of linked list*/
struct Node{

  int data;// linked list data 
  struct Node*next;// pointer field
  
};

/* Function declaration section here */
void insert_data(struct Node**,int);
void show_data(struct Node*);
void remove_node(struct Node**);
void delete_odd(struct Node**);

/*Help of this function create new linked list node. 
And there are inserted this element on end position of given linked list*/
void insert_data(struct Node**root,int value){

  /* create new memory block using malloc function. */
  struct Node*temp=NULL,*new_node=(struct Node*)malloc(sizeof(struct Node));
  
  /* check new create memory are allocate or not. */
  if(new_node)
  {   

      /*Assign data and next pointer value to newly created node.*/
    new_node->data=value;
    new_node->next=NULL;

    if(*root==NULL){
      /*When linked list are empty. Insert first node*/
      *root=new_node;
    }
    else{
      /*When linked list are not empty*/

      /*linked list first node address assign on temp pointer*/
      temp=*root;
      
      /*This will loop find last node of exist linked list*/
      while(temp->next){
        /*move temp pointer on next memory block*/
        temp=temp->next;  
      }
      
      /*assign this newly created node on end of list*/
      temp->next=new_node;
      
    }         
  }
  else
  {
    /* When malloc function not create memory block then. */
    printf("\n Memory overflow please try again..!");
  }
}


/* Help of this function showing all element of single linked list */
void show_data(struct Node*temp){
  if(temp==NULL){
    /*linked list are empty*/
    printf("Empty linked List\n");
  }
  else
  {
    /*When linked list are not empty*/
    printf("linked list :");
    while(temp)
    {
      /*print linked list data*/
      printf("%d  ",temp->data);

      /*move next memory block*/
      temp=temp->next;
    }
    
  }
}
/*Help of this function removing all linked list element.*/
void remove_node(struct Node**root){

  if(*root){

    struct Node*temp=*root;
    
    while(temp){

      /*Moving root pointer to on next memory block.*/
      *root=temp->next;

      /*before removing that linked node assign
       next pointer value are null.*/
      temp->next=NULL;
      
      /*Free linked list node element*/
      free(temp);
      
      temp=*root;
    }
    printf("\n\n Free nodes of linked linked \n");
  }
  else{
    /* When linked list is empty */
    printf("\n linked list is empty \n");
  }
  
}

/*delete Odd nodes in given linked list*/
void delete_odd(struct Node **root ){
  if(*root==NULL) {
    /*When given linked list are empty.*/
    printf("\n No element in this linked list.");
  }
  else
  {
   struct Node*temp=*root,*helper=*root;
      /*Find and remove given linked list node*/
      while(temp){
          /*Odd nodes*/
        if(temp->data%2!=0){
          /*Remove first node of linked list*/
          if(temp == *root){
            helper=temp;
            /*assign address of next node memory block*/
            *root=(*root)->next;
            temp=*root;
            /*Before delete node assign that
           next pointer value is NULL*/
            helper->next=NULL;
          /*Free node*/
            free(helper);
            helper=NULL;
        }
        else{
      
          helper->next=temp->next;
          temp->next=NULL;
          /*Free node*/
          free(temp);
          temp=helper->next;
        } 
      }else{
      helper=temp;
      /*assign address of next node memory block*/
      temp=temp->next;  
    }
  
    }  
  }
}


int main(){
  /* start program execution are here */
  struct Node*root=NULL;
  printf("\n Case 1: Empty Linked list \n  ");

  /*show_data functions showing data on list*/
  show_data(root);
  
  printf("\n case 2: When linked list are not empty \n ");
  
    /* Assume that following data are inserted */

  /* 10--->15--->20--->25--->30--->7--->4--->11--->10-->NULL */
 
  insert_data(&root,10);
  insert_data(&root,15);
  insert_data(&root,20);
  insert_data(&root,25);
  insert_data(&root,30);
  insert_data(&root,7);
  insert_data(&root,4);
  insert_data(&root,11);
  insert_data(&root,10);

  printf("\n Before delete Odd key nodes \n");
 /*show_data functions showing all nodes of linked list*/
  show_data(root);
  delete_odd(&root);
  printf("\n After delete Odd key nodes \n");  
  show_data(root);


  /*removing linked list node*/
  remove_node(&root);
  
  /*end execution*/
}

