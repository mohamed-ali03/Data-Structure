#include "Stack_Based_Array.h"

Nodes stack_arr = {.top = 0};
STD_ReturnType status ;

/*==========================main Function===============================*/
int main(void){
    uint32 sel ;
    uint32 value ;
    uint32 Flag ;

while(Flag){
    printf("\nWhat do you need : \n1.Initialize the stack     2.Push Value    3.Pop Value     4.Git Top      5.Print Stack    6.Exit\n");
    scanf("%i",&sel);
    switch (sel){
        case 1 : 
            printf("Please Enter the Initial Value\n");
            scanf("%i",&value);
            status = Stack_Init(&stack_arr,value);
            break;
        case 2 :
            printf("Please Enter the Pushed Value\n");
            scanf("%i",&value);
            status = Stack_Push(&stack_arr,value);
            break;
        case 3 :
            status = Stack_Pop(&stack_arr,&value);
            printf("Poped Value is %i \n",value);
            break;
        case 4 :
            status = Stack_Top(&stack_arr,&value);
            printf("Top Value is %i \n",value);
            break;
        case 5 :
            status = Stack_Print(&stack_arr);
            break;
        case 6 :
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

STD_ReturnType Stack_Init(Nodes *stack_ ,uint32 Init_Data){
    STD_ReturnType status = RET_OK ;
    uint32 count ;
    if (NULL == stack_){
        status = RET_NOT_OK ;
    }
    else{
        for (count = 0 ; count < ARRAY_SIZE ;count++){
            stack_-> arr[count]= Init_Data;
        }
        printf("Stack is initialized successfully\n");
    }
    return status ;
}

STD_ReturnType Stack_Push(Nodes *stack_ ,uint32 Data){
    STD_ReturnType status = RET_OK ;
    if (NULL == stack_){
        status = RET_NOT_OK ;
    }
    else{
        if (stack_->top >= ARRAY_SIZE -1){
            printf("Stack is Full \n");
        }
        else {
            stack_->arr[stack_->top] = Data ;
            stack_->top ++;
            printf("Data is added successfully\n");
        }
    }
    return status ;
}
STD_ReturnType Stack_Pop(Nodes *stack_ ,uint32 *Data){
    STD_ReturnType status = RET_OK ;
    if (NULL == stack_ && NULL == Data){
        status = RET_NOT_OK ;
    }
    else{
        if (stack_->top <= -1 ){
            printf("Stack is Empty\n");
        }
        else {
            *Data = stack_->arr[stack_->top];
            stack_->top --;
            printf("Data is Removed successfully\n");
        }
    }
    return status ;
}
STD_ReturnType Stack_Top(Nodes *stack_ ,uint32 *Data){
    STD_ReturnType status = RET_OK ;
    if (NULL == stack_&& NULL == Data){
        status = RET_NOT_OK ;
    }
    else{
        if(stack_->top <= -1 || stack_->top >= ARRAY_SIZE -1){
            printf("Top is out of range");
        }
        else{
            *Data = stack_->arr[stack_->top];
        }
    }
    return status ;
}
STD_ReturnType Stack_Print(Nodes *stack_){
    STD_ReturnType status = RET_OK ;
    uint32 count;
    if (NULL == stack_){
        status = RET_NOT_OK ;
    }
    else{
        for(count = stack_->top ; count <= 0  ;count--){
            printf("Data of position %i is %i \n",count+1 ,stack_->arr[count]);
        }
    }
    return status ;
}