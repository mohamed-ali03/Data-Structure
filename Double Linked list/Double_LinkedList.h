/*========================Includes Sections==========================*/
#include "../STDataType.h"

/*========================Macro Declarations==================================*/

/*========================Data Type==================================*/
typedef struct node{
    struct node *before;
    struct node *after;
    uint32 data ;
}Nodes;
/*========================Functions Declaratoins==================================*/
STD_ReturnType Double_LL_First_Node(Nodes **node_,uint32 data);

STD_ReturnType Double_LL_Add_Begin(Nodes **node_,uint32 data);
STD_ReturnType Double_LL_Add_End(Nodes **node_,uint32 data);

STD_ReturnType Double_LL_Remove_Begin(Nodes **node_,uint32 *data);
STD_ReturnType Double_LL_Remove_End(Nodes **node_,uint32 *data);

STD_ReturnType Double_LL_First(Nodes **node_,uint32 *data);
STD_ReturnType Double_LL_End(Nodes **node_,uint32 *data);

STD_ReturnType Double_LL_Print_Forward(Nodes **node_);
STD_ReturnType Double_LL_Print_Backward(Nodes **node_);

STD_ReturnType Double_LL_Free(Nodes **node_);




