#include "workerfun.h"

//函数声明：

int main()
{
	u_list = mkUserList();
    l_list = mkLotteryList();
    v_list = mkVolList();

    fileread();
	volFileRead();
    sortVol();
    lotteryFileRead();
    sortLottery();

	loadView();
    
    filewrite();
    volFileWrite();
    lotteryFileWrite();

    return 0;
}