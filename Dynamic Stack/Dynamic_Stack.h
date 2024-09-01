/*========================Includes Sections==========================*/
#include "../STDataType.h"

/*========================Macro Declarations==================================*/

/*========================Data Type==================================*/
typedef struct node{
    struct node *Bottom;
    uint32 data ;
}Nodes;
/*========================Functions Declaratoins==================================*/
STD_ReturnType Stack_First_Node(Nodes **Top,uint32 data);
STD_ReturnType Stack_Push(Nodes **Top,uint32 data);
STD_ReturnType Stack_Pop(Nodes **Top,uint32 *data);
STD_ReturnType Stack_Top(Nodes **Top,uint32 *data);
STD_ReturnType Stack_Print(Nodes **Top);
STD_ReturnType Stack_Free(Nodes **Top);




