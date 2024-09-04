/*========================Includes===============================*/
#include "../STDataType.h"


/*=========================Data Type==============================*/
typedef struct node{
    uint32 data ;
    struct node *Right;
    struct node *Left;
}Nodes;

typedef enum {
    Right = 0,
    Lift ,
}Position;

typedef enum{
    False = 0 ,
    True
}bool_;

/*=========================Functions Declarations===================*/
STD_ReturnType Binary_Tree_Grand(Nodes **node_obj,uint32 data);
STD_ReturnType Binary_Tree_Add(Nodes **node_obj,uint32 data);
STD_ReturnType Binary_Tree_Print(Nodes **node_obj);
