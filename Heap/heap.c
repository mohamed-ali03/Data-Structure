#include "heap.h"
uint32 size = 0  ;


int main(void){
    uint32 si ;
    uint32 sel ;
    uint32 value ;
    uint8 flag = 'T' ;
    
    printf("Enter the size of the Heap : ");
    scanf("%i",&si);
    
    uint32 array [si];
    while(flag = 'T'){
        printf("\nWhat Do you Do?\n1.Insert Value   2.Show Elments      3.Exit\n");
        scanf("%i",&sel);

        switch(sel){
            case 1 :
                printf("Please Enter the value : ");
                scanf("%i",&value);
                insert(array,value);
                break;
            case 2 : 
                Print(array);
                break;
            case 3 :
                printf("\nGood Bye\n");
                break;
            default :
                printf("Invaild Input!!\n");
                break;
        }

    }

    insert(array,10);
    insert(array,20);
    insert(array,30);
    insert(array,40);
    insert(array,50);
    insert(array,60);
    Print(array);
    return 0 ;
}


/*====================================================Asisstant Functoins====================================================================*/
void Swap(uint32 *x ,uint32 *y){
    uint32 temp ;
    temp = *x ;
    *x = *y ;
    *y = temp ;
}

void heap (uint32 arr[],uint32 size , uint32 i){
    uint32 largest ;
    uint32 left_node ;
    uint32 Right_node;
    if(size == 1){
        printf("There is one value only \n");
    }
    else {
        largest = i;
        left_node = 2*i + 1 ;
        Right_node = 2*i +2 ;
        if(left_node < size && arr[left_node] > arr[i]){
            largest = left_node;
        }

        if(Right_node < size && arr[Right_node]>arr[i]){
            largest = Right_node;
        }

        if (largest != i){
            Swap(&arr[largest],&arr[i]);
            heap(arr,size,largest);
        }
    }
}


void insert (uint32 arr[],uint32 data){
    sint32 i =0;
    if (size == 0 ){
        arr[0] = data;
        size++;
    }
    else{
        arr[size] = data ;
        size++;
        for (i = size/2 -1 ; i >=0 ; i--){
            heap(arr,size,i);
        }
    }
}


void Print(uint32 arr[]){
    uint32 i ;
    for(i = 0 ; i < size ; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}