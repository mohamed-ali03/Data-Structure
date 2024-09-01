/*========================Includes Sections==========================*/
#include "../STDataType.h"

/*========================Macro Declarations==================================*/
#define ARRAY_SIZE          5 
/*========================Data Type==================================*/

// linked list to implement the stack based on array 
typedef struct nodes{
    uint32 arr[ARRAY_SIZE];
    uint32 top;
}Nodes;

/*========================Functions Declaratoins==================================*/
STD_ReturnType Stack_Init(Nodes *stack_ ,uint32 Init_Data);
STD_ReturnType Stack_Push(Nodes *stack_ ,uint32 Data);
STD_ReturnType Stack_Pop(Nodes *stack_ ,uint32 *Data);
STD_ReturnType Stack_Top(Nodes *stack_ ,uint32 *Data);
STD_ReturnType Stack_Print(Nodes *stack_);


