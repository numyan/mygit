#include "../lib/workerfun.h"

//函数声明：

int main()
{
    system("sl");
	u_list = mkUserList();
    l_list = mkLotteryList();
    v_list = mkVolList();

    fileread();
	volFileRead();
    sortVol();
    lotteryFileRead();
    sortLottery();

	loadView();

    return 0;
}
