#include "Queue.h"

STD_ReturnType status ;
uint32 count ;


/*==========================main Function===============================*/
int main(void){
    Nodes **Queue_Top;
    uint32 sel ;
    uint32 value ;
    uint32 Flag = 1;

while(Flag){
    printf("\nWhat do you need : \n1.Create Queue     2.Add Value    3.Remove Value     4.Git First     5.Git End     6.Print Queue      7.Size Of Queue     8.Free Queue    9.Exit\n");
    scanf("%i",&sel);
    switch (sel){
        case 1 : 
            printf("Please Enter the Initial Value\n");
            scanf("%i",&value);
            status = Queue_First_Node(Queue_Top,value);
            break;
        case 2 :
            printf("Please Enter the Added Value\n");
            scanf("%i",&value);
            status = Queue_Add(Queue_Top,value);
            break;
        case 3 :
            status = Queue_Remove(Queue_Top,&value);
            printf("Removed Value is %i \n",value);
            break;
        case 4 :
            status = Queue_First(Queue_Top,&value);
            printf("First Value is %i \n",value);
            break;
        case 5 :
            status = Queue_End(Queue_Top,&value);
            printf("First Value is %i \n",value);
            break;
        case 6 :
            status = Queue_Print(&Queue_Top);
            break;
        case 7 :
            printf("Size of Queue is %i\n",count);
            break;
        case 8 :
            status = Queue_Free(Queue_Top);
            break;
        case 9 :
            printf("Good Bye (:\n\n");
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


STD_ReturnType Queue_First_Node(Nodes **First,uint32 data){
    STD_ReturnType status = RET_OK;
    Nodes *temp = (Nodes*)malloc(sizeof(Nodes));
    if(NULL == First){
        printf("NULL Pointer\n");
        status = RET_NOT_OK;
    }
    else{
        temp->data = data;
        temp->end = NULL ;
        count = 1;
        *First= temp ;
        printf("First Node is created Successfully (:\n");
    }
    return 0 ;
}
STD_ReturnType Queue_Add(Nodes **First,uint32 data){
    STD_ReturnType status = RET_OK;
    Nodes *temp ;
    Nodes *temp_1;
    if(NULL == First){
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
            temp->data = data;
            temp->end = NULL;
            temp_1 = *First;
            while(temp_1->end){
                temp_1 = temp_1->end;
            }
            temp_1->end = temp;
            count++;
            printf("Node is pushed successfully(:\n");
        }
    }
    return 0 ;
}
STD_ReturnType Queue_Remove(Nodes **First,uint32 *data){
    STD_ReturnType status = RET_OK;
    Nodes *temp;
    if(NULL == First){
        printf("Empty Stack!!\n");
        status = RET_NOT_OK;
    }
    else{
        temp = *First ;
        *data = temp->data;
        *First = (*First)->end;
        count--;
        free(temp);
        printf("Node is poped successfully (:\n");
    }
    return 0 ;
}
STD_ReturnType Queue_First(Nodes **First,uint32 *data){
    STD_ReturnType status = RET_OK;
    if(NULL == First){
        printf("NULL Pointer\n");
        status = RET_NOT_OK;
    }
    else{
        *data = (*First)->data ;
    }
    return 0 ;
}

STD_ReturnType Queue_End(Nodes **First,uint32 *data){
    STD_ReturnType status = RET_OK;
    Nodes *temp_1;
    if(NULL == First){
        printf("NULL Pointer\n");
        status = RET_NOT_OK;
    }
    else{
        temp_1 = *First;
        while(temp_1->end){
            temp_1 = temp_1->end;
        }
        *data = temp_1->data;
    }
    return 0 ;
}

STD_ReturnType Queue_Print(Nodes **First){
    STD_ReturnType status = RET_OK;
    Nodes *temp ;
    uint32 i ;
    if(NULL == First){
        printf("NULL Pointer\n");
        status = RET_NOT_OK;
    }
    else{
        if(count == 0 ){
            printf("Empty Stack!!\n");
        }
        else{
            temp = (*First)->end;
            for(i = 0 ; i < count ; i++){
                printf("Value of Position %i is %i\n",i+1 ,temp->data);
                temp = temp->end;
            }
        }
    }
    return 0 ;
}

STD_ReturnType Queue_Free(Nodes **First){
    STD_ReturnType status = RET_OK;
    Nodes *temp ;
    uint32 i ;
    if(NULL == First){
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
                    temp = (*First)->end;
                    free((*First));
                    (*First) = temp ;
                }
                else{
                    break;
                }
                
            }
        }
    }
    return 0 ;
}

