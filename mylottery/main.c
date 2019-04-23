#include "workerfun.h"

//函数声明：

int main()
{
	u_list = mkUserList();
    l_list = mkLotteryList();
    v_list = mkVolList();
    // Vol*node = mkVolNode();
    // strcpy(node->condition,"run");
    // node->bonusPool = 100000000;
    // node->vol = 1900;
    // volInsert(v_list,node);
    // volFileWrite();    

    fileread();
	volFileRead();
    
	loadView();
    return 0;
}