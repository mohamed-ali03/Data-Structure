#include "Dynamic_Stack.h"

STD_ReturnType status ;
uint32 count ;


/*==========================main Function===============================*/
int main(void){
    Nodes **stack_Top;
    uint32 sel ;
    uint32 value ;
    uint32 Flag = 1;

while(Flag){
    printf("\nWhat do you need : \n1.Create Stack     2.Push Value    3.Pop Value     4.Git Top      5.Print Stack      6.Size Of Stack     7.Free Stack    8.Exit\n");
    scanf("%i",&sel);
    switch (sel){
        case 1 : 
            printf("Please Enter the Initial Value\n");
            scanf("%i",&value);
            status = Stack_First_Node(stack_Top,value);
            break;
        case 2 :
            printf("Please Enter the Pushed Value\n");
            scanf("%i",&value);
            status = Stack_Push(stack_Top,value);
            break;
        case 3 :
            status = Stack_Pop(stack_Top,&value);
            printf("Poped Value is %i \n",value);
            break;
        case 4 :
            status = Stack_Top(stack_Top,&value);
            printf("Top Value is %i \n",value);
            break;
        case 5 :
            status = Stack_Print(&stack_Top);
            break;
        case 6 :
            printf("Size of Stack is %i\n",count);
            break;
        case 7 :
            status = Stack_Free(stack_Top);
            break;
        case 8 :
            Flag = 0 ;
            break;
        default :
            printf("Invaild Input !!\n");
            break;
    }
}


    return 0 ;
}


/*==========================Assistant Functions===============================*/


STD_ReturnType Stack_First_Node(Nodes **Top,uint32 data){
    STD_ReturnType status = RET_OK;
    Nodes *temp = (Nodes*)malloc(sizeof(Nodes));
    if(NULL == *Top){
        printf("NULL Pointer\n");
        status = RET_NOT_OK;
    }
    else{
        temp->data = data;
        temp->Bottom = NULL;
        count = 1 ;
        *Top = temp ;
        printf("First Node is created Successfully (:\n");
    }
    return 0 ;
}
STD_ReturnType Stack_Push(Nodes **Top,uint32 data){
    STD_ReturnType status = RET_OK;
    Nodes *temp ;
    if(NULL == *Top){
        printf("NULL Pointer\n");
        status = RET_NOT_OK;
    }
    else{
        temp= (Nodes*)malloc(sizeof(Nodes));
        if(temp == NULL){
            printf("Full Stack!!\n");
            status = RET_NOT_OK;
        }
        else{
            temp->Bottom = *Top;
            temp->data = data ;
            count++;
            *Top = temp ;
            printf("Node is pushed successfully(:\n");
        }
    }
    return 0 ;
}
STD_ReturnType Stack_Pop(Nodes **Top,uint32 *data){
    STD_ReturnType status = RET_OK;
    Nodes *temp;
    if(NULL == *Top){
        printf("Empty Stack!!\n");
        status = RET_NOT_OK;
    }
    else{
        temp = *Top ;
        *data = temp->data;
        *Top = (*Top)->Bottom;
        count--;
        free(temp);
        printf("Node is poped successfully (:\n");
    }
    return 0 ;
}
STD_ReturnType Stack_Top(Nodes **Top,uint32 *data){
    STD_ReturnType status = RET_OK;
    if(NULL == *Top){
        printf("NULL Pointer\n");
        status = RET_NOT_OK;
    }
    else{
        *data = (*Top)->data ;
    }
    return 0 ;
}

STD_ReturnType Stack_Print(Nodes **Top){
    STD_ReturnType status = RET_OK;
    Nodes *temp ;
    uint32 i ;
    if(NULL == *Top){
        printf("NULL Pointer\n");
        status = RET_NOT_OK;
    }
    else{
        if(count == 0 ){
            printf("Empty Stack!!\n");
        }
        else{
            temp = (*Top)->Bottom;
            for(i = count ; i <= 0 ; i--){
                printf("Value of Position %i is %i\n",i+1 ,temp->data);
                temp = temp->Bottom;
            }
        }
    }
    return 0 ;
}

STD_ReturnType Stack_Free(Nodes **Top){
    STD_ReturnType status = RET_OK;
    Nodes *temp ;
    uint32 i ;
    if(NULL == *Top){
        printf("NULL Pointer\n");
        status = RET_NOT_OK;
    }
    else{
        if(count == 0 ){
            printf("Empty Stack!!\n");
        }
        else{
            for(i = count ; i >= 0 ; i--){
                if(temp != NULL){
                    temp = (*Top)->Bottom;
                    free((*Top));
                    (*Top) = temp ;
                }
                else{
                    break;
                }
                
            }
        }
    }
    return 0 ;
}

