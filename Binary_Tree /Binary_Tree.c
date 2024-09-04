#include "Binary_Tree.h"
static STD_ReturnType CreateNode(Nodes **nodeCreated ,uint32 data);
uint32 size = 0 ;


int main(void){
    Nodes *BTree = NULL ;
    uint32 value;
    uint8 dec ;
    uint32 sel ;
    bool_ flag = True;
    STD_ReturnType status = RET_OK ;


    printf("Do you need a Binary Search Tree(Y/N)? ");
    scanf("%c",&dec);

    if (dec == 'y' || dec == 'Y'){
        while(flag){
            printf("What Do you need?\n1.Add Node       2.Print All Nodes       3.Exit\n");
            scanf("%i",&sel);
            switch (sel){
                case 1 :
                    printf("Enter the data : ");
                    scanf("%i",&value);
                    status = Binary_Tree_Add(&BTree,value);
                    break; 
                case 2 :
                    Binary_Tree_Print(&BTree);
                    break;
                case 3 :
                    flag = False ;
                    printf("\nGood Bye \n\n");
                    break;
                default :
                    printf("Invaild Input!!\n");
                    break;
            }
        }
    }
    else{
        printf("\n========Good Bye=======\n\n");
    }

    return 0 ;
}

/*======================================Asisstant Functions===================================================*/

STD_ReturnType Binary_Tree_Grand(Nodes **node_obj,uint32 data){
    STD_ReturnType status =  RET_OK;
    Nodes *temp ;
    if (node_obj == NULL ){
        status =  RET_NOT_OK;
    }
    else{
        status = CreateNode(&temp,data);
        *node_obj = temp ;
    }
    return status ;
}

STD_ReturnType Binary_Tree_Add(Nodes **node_obj,uint32 data){
    STD_ReturnType status =  RET_OK;
    if (node_obj == NULL || *node_obj == NULL){
        status =  RET_NOT_OK;
    }
    else{
        if ((*node_obj) == NULL){
            status = CreateNode(node_obj,data);
            return status;
        }

        if(data < (*node_obj)->data){
            status = Binary_Tree_Add(&((*node_obj)->Left),data);
        }
        else {
            status = Binary_Tree_Add(&((*node_obj)->Right),data);
        }
    }
    return status ;
}


STD_ReturnType Binary_Tree_Print(Nodes **node_obj){
    STD_ReturnType status =  RET_OK;
    if (node_obj == NULL || *node_obj == NULL){
        status =  RET_NOT_OK;
    }
    else{
        Binary_Tree_Print(&((*node_obj)->Left));
        printf("%d ",(*node_obj)->data);
        Binary_Tree_Print(&((*node_obj)->Right));
    }
    return status ;
}



static STD_ReturnType CreateNode(Nodes **nodeCreated ,uint32 data){
    STD_ReturnType status = RET_OK;
    *nodeCreated =(Nodes*)malloc(sizeof(Nodes));
    if (nodeCreated == NULL){
        status =  RET_NOT_OK;
    }
    else {
        (*nodeCreated)->data = data;
        (*nodeCreated)->Left = NULL;
        (*nodeCreated)->Right = NULL;
        size++;
        printf("Root is added Successfully (:\n");
    }
    return status ;
}
