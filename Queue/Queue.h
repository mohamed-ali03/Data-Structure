/*========================Includes Sections==========================*/
#include "../STDataType.h"

/*========================Macro Declarations==================================*/

/*========================Data Type==================================*/
typedef struct node{
    struct node *end;
    uint32 data ;
}Nodes;
/*========================Functions Declaratoins==================================*/
STD_ReturnType Queue_First_Node(Nodes **First,uint32 data);
STD_ReturnType Queue_Add(Nodes **First,uint32 data);
STD_ReturnType Queue_Remove(Nodes **First,uint32 *data);
STD_ReturnType Queue_First(Nodes **First,uint32 *data);
STD_ReturnType Queue_End(Nodes **First,uint32 *data);
STD_ReturnType Queue_Print(Nodes **First);
STD_ReturnType Queue_Free(Nodes **First);




