#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    struct node *Forward_;
    int data ;
}node;

void FindMiddle(node **node_);
void LinkedList_First(node **node_,int data);
void LinkedList_Add(node **node_,int data);
void LinkedList_print(node **node_);
void Free_Linkedlist(node **node_);

int size ;
int main(void){
    int count;
    int flag = 1;
    int sel ;
    int value ;
    node **FirstElement ;


    while(flag){
        printf("\nWhat do you Do?\n1.Add First node     2.Add Node      3.Print all nodes       4.Find Middle       5.Exit\n");
        scanf("%i",&sel);


        switch (sel){
            case 1 : // Add First node 
                printf("Enter the data : ");
                scanf("%i",&value);
                LinkedList_First(FirstElement,value);
                break;
            case 2 :
                printf("Enter the data : ");
                scanf("%i",&value);
                LinkedList_Add(FirstElement,value);
                break;
            case 3 :  // print the whole linked list 
                LinkedList_print(FirstElement);
                break;
            case 4 :
                FindMiddle(FirstElement);
                break;
            case 5 : // Exit from the program
                printf("thank you for your effort\nGood Bye (:\n");
                flag = 0 ;
                break;
            default: // try again
                printf("Error: Invaild input!!\n"); 
                break;
        }
    }
    

    // free the memory allocation 
    Free_Linkedlist(FirstElement);
    return 0 ;
}


void LinkedList_First(node **node_,int data){
    node *temp ;
    if (node_ != NULL){
        temp = (node*)malloc(sizeof(node));
        // check if the node is allocated or not 
        if(temp == NULL){
            printf("Error: Failure in accessing the node\n");
        }
        else{
            temp->data = data ;
            temp->Forward_ = NULL;
            *node_ = temp ;
            printf("First Node is added \n");
            size = 1;
        }
    }
}

void LinkedList_Add(node **node_,int data){
    node *temp ;
    node *Traverse = *node_;
    if (node_ != NULL && *node_ != NULL){
        temp = (node*)malloc(sizeof(node));
        // check if the node is allocated or not 
        if(temp == NULL){
            printf("Error: Failure in accessing the node\n");
        }
        else{
            temp->data = data ;
            temp->Forward_ = NULL;
            while(Traverse->Forward_){
                Traverse = Traverse->Forward_;
            }
            Traverse->Forward_ = temp ;
            printf("Node is added \n");
            size++;
        }
    }
}


void FindMiddle(node **node_){
    node *Fast = *node_ ;
    node *Slow = *node_ ;
    if (node_ != NULL){
        while(Fast != NULL && Fast->Forward_ != NULL)
        {
            Fast = Fast->Forward_->Forward_;
            Slow = Slow->Forward_ ;
        }
    }
    printf("Middle Value is %i\n",Slow->data);
}

void LinkedList_print(node **node_){
    node *temp ;
    int count ;
    if (node_ != NULL && *node_ != NULL){
        temp = (node*)malloc(sizeof(node));
        // check if the node is allocated or not 
        if(temp == NULL){
            printf("Error: Failure in accessing the node\n");
        }
        else{
            // assign the address of the first node to temp to access the linked list using "temp pointer"
            temp = *node_ ;
            // Print the content of the linked list 
            for (count = 0 ; count < size ; count++){
                printf("data of position %i is %i and Addrass is %p\n",count+1 ,temp->data ,temp->Forward_);
                temp = temp->Forward_ ;
            }
        }
    }
}


void Free_Linkedlist(node **node_){
    node *temp ;
    node *temp0 ;
    int count ;
    if (node_ != NULL){
        // free the memory allocation 
        temp0 = *node_;
        for (count = 0 ; count < size ; count++){
            temp = temp0 ;
            temp0 = temp0->Forward_;
            free(temp);
        }
    }
}