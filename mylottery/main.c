#include "workerfun.h"

//函数声明：

int main()
{
	u_list = mkUserList();
    l_list = mkLotteryList();
    v_list = mkVolList();

    
    fileread();
	volFileRead();
    
	loadView();
    return 0;
}