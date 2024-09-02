#include "Double_LinkedList.h"

STD_ReturnType status ;
uint32 count ;


/*==========================main Function===============================*/
int main(void){
    Nodes **Double_LL;
    char Bool ;
    uint32 sel ;
    uint32 value ;
    uint32 Flag = 1;

    printf("\n--Welcome to Double Linked List Operations--\nDo you need to create a node(Y/N)?");
    scanf("%c",&Bool);

    if(Bool == 'Y' || Bool == 'y'){
        // git the first node information 
        printf("Please enter the first node data : ");
        scanf("%i",&value);
        status = Double_LL_First_Node(Double_LL,value);

        // another operations 
        while(Flag){
            printf("\nWhat do you need : \n1.Add Value(Begin)\n2.Remove Value(Begin)\n3.Add Value(end)\n4.Remove Value(end)\n5.Git First\n6.Git End\n7.Print Forward\n8.Print Backward\n9.Size Of Double Linked list\n10.Free Double Linked list\n11.Exit\n");
            scanf("%i",&sel);

            switch (sel){
                case 1 :
                    printf("Please Enter the added value : ");
                    scanf("%i",&value);
                    status = Double_LL_Add_Begin(Double_LL,value);
                    break; 
                case 2 :
                    status = Double_LL_Remove_Begin(Double_LL,&value);
                    printf("the Removed Value is %i \n",value);
                    break; 
                case 3 :
                    printf("Please Enter the added value : ");
                    scanf("%i",&value);
                    status = Double_LL_Add_End(Double_LL,value);
                    break; 
                case 4 :
                    status = Double_LL_Remove_End(Double_LL,&value);
                    printf("The Removed Value is %i \n",value);
                    break; 
                case 5 : 
                    status = Double_LL_First(Double_LL,&value);
                    printf("The First Value is %i \n",value);
                    break; 
                case 6 :
                    status = Double_LL_End(Double_LL,&value);
                    printf("The End Value is %i \n",value);
                    break; 
                case 7 :
                    status = Double_LL_Print_Forward(Double_LL);
                    break;
                case 8 :
                    status = Double_LL_Print_Backward(Double_LL);
                    break;
                case 9 :
                    printf("size of the Double linked list is %i\n",count);
                    break;
                case 10 :
                    status = Double_LL_Free(Double_LL);
                    Flag = 0 ;
                    break;
                case 11 :
                    Flag = 0 ;
                    printf("\nGood Bye(:\n");
                    break; 
                default:
                    printf("Invaild Input !!\n");
            }
        }
    }  
    else{
        printf("\nGood Bye(:\n");
    } 

    return 0 ;
}


/*==========================Assistant Functions===============================*/


STD_ReturnType Double_LL_First_Node(Nodes **node_,uint32 data){
    STD_ReturnType status = RET_OK ;
    Nodes *temp ;
    if (node_ == NULL){
        printf("NULL Pointer!!\n");
        status = RET_NOT_OK ;
    }
    else {
        temp = (Nodes*)malloc(sizeof(Nodes));
        if (temp == NULL)
        {
            printf("NULL Pointer!!\n");
            status = RET_NOT_OK ;
        }
        else {
            temp->after = NULL ;
            temp->before= NULL ;
            temp->data  = data ;
            count =1 ;
            *node_ = temp ;
            printf("First node is added Successfully(:\n");
        }
    }
    return 0 ;
}

STD_ReturnType Double_LL_Add_Begin(Nodes **node_,uint32 data){
    STD_ReturnType status = RET_OK ;
    Nodes *temp ;
    Nodes *Traverse;
    if (node_ == NULL){
        status = RET_NOT_OK ;
    }
    else {
        temp = (Nodes*)malloc(sizeof(Nodes));
        if (temp == NULL)
        {
            printf("NULL Pointer!!\n");
            status = RET_NOT_OK ;
        }
        else {
            // move to the most right node
            Traverse = (*node_);
            while(Traverse->before){
                Traverse = Traverse->before;
            }
            // put the address of th new node in the *before of its previous node
            Traverse->before = temp;
            // insert the data to the node 
            temp->data = data ;
            temp->before = NULL ;
            // make it point to its previous node 
            temp->after = Traverse;
            count++;
            printf("Node is added Successfully(:\n");
        }
    }
    return 0 ;
}
STD_ReturnType Double_LL_Add_End(Nodes **node_,uint32 data){
    STD_ReturnType status = RET_OK ;
    Nodes *temp ; 
    Nodes *Traverse ;
    if (node_ == NULL){
        status = RET_NOT_OK ;
    }
    else {
        temp = (Nodes*)malloc(sizeof(Nodes));
        if (temp == NULL)
        {
            printf("NULL Pointer!!\n");
            status = RET_NOT_OK ;
        }
        else {
            // move to the most right node
            Traverse = (*node_);
            while(Traverse->after){
                Traverse = Traverse->after;
            }
            // put the address of th new node in the *after of its previous node
            Traverse->after = temp;
            // insert the data to the node 
            temp->data = data ;
            temp->after = NULL ;
            // make it point to its previous node 
            temp->before = Traverse;
            count++;
            printf("Node is added Successfully(:\n");
        } 

    }
    return 0 ;
}

STD_ReturnType Double_LL_Remove_Begin(Nodes **node_,uint32 *data){
    STD_ReturnType status = RET_OK ;
    Nodes *temp ;
    if (node_ == NULL && data == NULL){
        status = RET_NOT_OK ;
    }
    else {
        // move to the most right node
        temp = (*node_);
        while(temp->before){
            temp = temp->before;
        }
        // return data
        *data = temp->data;
        // move to the previous node
        temp = temp->after;
        if(temp->before){
            // free the removed location node
            free(temp->before); 
        }
        // write null in the *before 
        temp->before = NULL;
        count--;
        printf("Node is Removed Successfully(:\n");
    }
    return 0 ;
}
STD_ReturnType Double_LL_Remove_End(Nodes **node_,uint32 *data){
    STD_ReturnType status = RET_OK ;
    Nodes *temp ;
    if (node_ == NULL && data == NULL){
        status = RET_NOT_OK ;
    }
    else {
        // move to the most Lift node
        temp = (*node_);
        while(temp->after){
            temp = temp->after;
        }
        // return data
        *data = temp->data;
        // move to the previous node
        temp = temp->before;
        if(temp->after){
            // free the removed location node
            free(temp->after);
        }
        // write null in the *before 
        temp->after = NULL;
        count--;
        printf("Node is Removed Successfully(:\n");
    }
    return 0 ;
}

STD_ReturnType Double_LL_First(Nodes **node_,uint32 *data){
    STD_ReturnType status = RET_OK ;
    Nodes *temp ;
    if (node_ == NULL && data == NULL){
        status = RET_NOT_OK ;
    }
    else {
        // move to the most Right node
        temp = (*node_);
        while(temp->before){
            temp = temp->before;
        }
        // return the data 
        *data = temp->data;
    }
    return 0 ;
}
STD_ReturnType Double_LL_End(Nodes **node_,uint32 *data){
    STD_ReturnType status = RET_OK ;
    Nodes *temp;
    if (node_ == NULL && data == NULL){
        status = RET_NOT_OK ;
    }
    else {
        // move to the most lift node
        temp = (*node_);
        while(temp->after){
            temp = temp->after;
        }
        // return the data 
        *data = temp->data;
    }
    return 0 ;
}

STD_ReturnType Double_LL_Print_Forward(Nodes **node_){
    STD_ReturnType status = RET_OK ;
    Nodes *temp ;
    uint32 i = 0;
    if (node_ == NULL){
        status = RET_NOT_OK ;
    }
    else {
        // move to the most Right node
        temp = (*node_);
        while(temp->before){
            temp = temp->before;
        }
        // print the data in forward order 
        while(temp){
            printf("Data in position %i : %i\n",i,temp->data);
            i++;
            temp = temp->after;
        }
    }
    return 0 ;
}
STD_ReturnType Double_LL_Print_Backward(Nodes **node_){
    STD_ReturnType status = RET_OK ;
    Nodes *temp ;
    uint32 i = count;
    if (node_ == NULL){
        status = RET_NOT_OK ;
    }
    else {
        // move to the most Lift node
        temp = (*node_);
        while(temp->after){
            temp = temp->after;
        }
        // print the data in Backward order 
        while(temp){
            printf("Data in position %i : %i\n",i,temp->data);
            i--;
            temp = temp->before;
        }
    }
    return 0 ;
}

STD_ReturnType Double_LL_Free(Nodes **node_){
    STD_ReturnType status = RET_OK ;
    Nodes *temp;
    Nodes *free_point;
    if (node_ == NULL){
        status = RET_NOT_OK ;
    }
    else {
        // move to the most Right node
        temp = (*node_);
        while(temp->before){
            temp = temp->before;
        }
        // Free all nodes
        while(temp){
            free_point = temp ;
            temp = temp->before;
            free(free_point);
        }
        printf("The Double LL is freed successfully(:\n");
    }
    return 0 ;
}