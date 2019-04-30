#include "../lib/snake.h"

static char user[16]="";

 int snake(char user[])
 {
     int again = 0;
    
     do
     {
//printf("\033[2J");
         int flag = 0;
again = 0;


         Init_str();
         Init_snake();
         Init_food();
         Display();


         Wait_game();
         while(1)
         {
             flag = Snake_move() ;
     if(flag == EAT_BODY)
     {
GameOver();
     }
             reDisplay();
             Delay();
             
         }
     }while( again == 1);


 }


void PrintRule()
{
    printf("**************************************************\n");
    printf("* 游戏规则：【@】表示蛇头，【$】表示食物，【#】  *\n");
    printf("* 表示蛇的身体。每吃到一个食物蛇的身体加长一个， *\n");
    printf("* 吃到蛇身或撞到墙，则游戏结束                   *\n");
    printf("* 按wsad可以控制蛇移动方向，分别表示上下左右方向 *\n");
    printf("* 请按wsad键开始游戏                             *\n");
    printf("**************************************************\n");
}


void GameOver()
{
    releaseSnake();
    printf("Game Over!!!\n");
    printf("SCORE:%d\n",(grade-1)*2000+(snake_length-1)*100);
    printf("\n按任意键+回车返回，ESC+回车继续\n");
    //while(getchar() != '\n');
    if(getch() == '\e')
    {
        while(getchar() != '\n');
        snake(user);
    }
    while(getchar() != '\n');
    system("clear");
    userView(user);
}



void releaseSnake()
{
    Snake *p = head;
    while(head != NULL) 
    {
p = head;
head = head->next;
free(p);
    }
}


int isUpgrade()
{
    return snake_length == SNAKELEN ? 1:0;
}


void Delay()
{
    unsigned long int tick1 = clock();
    char ch;
    while(1000*(clock() - tick1 )/CLOCKS_PER_SEC <= speed)
    {
ch = control();
ch = tolower(ch);
if(ch == UP)
{
    if(dc != DOWN)
    {    
dc = ch;
        break;
    }
}
else if(ch == DOWN)
{
    if(dc != UP)
    { 
dc = ch ;
break;
    }
}
else if( ch == LEFT)
{
    if(dc != RIGHT)
    {
dc = ch;
break;
    }
}
else if(ch == RIGHT)
{
    if(dc != LEFT)
    { 
dc = ch;
break;
    }
}
    }
}


void addBody(int x, int y)
{
    Snake *p = (Snake *)malloc(sizeof(Snake));
    if(p == NULL)
    {
printf("Error!!!Apply Snake *p failed\n");
exit(1);
    }
    p->place.row = x;
    p->place.col = y;
    p->next = head->next;
    head->next = p;
    snake_length ++;
    
}


void foodShow()
{
    str[food.row][food.col] = FOOD;
}


void snakeShow()
{
    Snake *p = head;
    while(p != NULL)
    {
if(p == head)
    str[p->place.row][p->place.col] = SNAKE_HEAD ; 
else
    str[p->place.row][p->place.col] = SNAKE_BODY ; 
p = p->next; 
    }
}


void reDisplay()
{
    Init_str();
    foodShow();
    snakeShow(); 
    Display(); 
}


int Snake_move()
{
    int x = head->place.row;
    int y = head->place.col;
    switch(dc)
    {
case UP :
    if(dc != DOWN )
moveToUp();
    break;
case DOWN :
    if(dc != UP )
moveToDown();
    break;
case LEFT :
    if(dc != RIGHT )
moveToLeft();
    break;
case RIGHT :
    if(dc != LEFT)
moveToRight();
    break;
    }
    bodyDc = dc;
    int i = head->place.row;
    int j = head->place.col;
    if(str[i][j] == SNAKE_BODY )
    {
return EAT_BODY;
    }
    else if(str[i][j] == FOOD )
    {
addBody(x,y);
Init_food();
return EAT_FOOD;
    }
    else if(str[i][j] == ' ')
    {
moveBody(x,y);
return EAT_SPACE;
    }
}


void moveBody(int x,int y)
{
    Snake *p = head ,*pre = NULL;
    if(head->next != NULL)
    {
while(p->next != NULL)
{   
    pre = p;
    p = p->next; 
}
if(pre != head)
{
    p->place.row = x;
    p->place.col = y;
    p->next = head->next;
    head->next = p;
    pre->next  = NULL ;    
}
else
{
    p->place.row = x;
    p->place.col = y;
}
    }
}
void moveToRight()
{
    int i = head->place.row;
    int j = head->place.col;
    dc = RIGHT ;
    if(str[i][j+1] != '|')
    {
j++ ;
    }
    else  
    {
GameOver();
    }
    head->place.row = i;
    head->place.col = j;
}
void moveToLeft()
{
    int i = head->place.row;
    int j = head->place.col;
    dc = LEFT ;
    if(str[i][j-1] != '|')
    {
j-- ;
    }
    else  
    {
GameOver();
    }
    head->place.row = i;
    head->place.col = j;
}
void moveToUp()
{
    int i = head->place.row;
    int j = head->place.col;
    dc = UP ;
    if(str[i-1][j] != '-')
    {
i-- ;
    }
    else  
    {
GameOver();
    }
    head->place.row = i;
    head->place.col = j;
}
void moveToDown()
{
    int i = head->place.row;
    int j = head->place.col;
    dc = DOWN ;
    if(str[i+1][j] != '-')
    {
i++ ;
    }
    else  
    {
GameOver();
    }
    head->place.row = i;
    head->place.col = j;
}

void Wait_game()
 {
     char ch ;
     do
     {
         ch = getch();
         ch = tolower(ch);
     }while(ch != UP && ch != DOWN && ch != LEFT && ch != RIGHT );
     dc = ch;
     bodyDc = dc;
 }


 void Init_food()
 {
     unsigned long int seed = time(NULL);
     srand(seed+1);
     while(1)
     {
food.row = rand() % ( ROW_MAX - 2) + 1;
food.col = rand() % ( COL_MAX - 2) + 1;
Snake *p = head;
int flag = 1;
while(p != NULL)
{
    if(food.row == p->place.row && food.col == p->place.col)
    {
flag = 0;
break;
    }
    p = p->next;
}
if(flag == 1)
     break;
     }
     str[food.row][food.col] = FOOD;
 }


 void Init_str()
 {
     int i,j;
     for(i=0;i<ROW_MAX;i++)
     {
for(j=0;j < COL_MAX;j++)
{
     if(i == 0 || i == ROW_MAX-1)
str[i][j]='-';
    else
     {
if(j == 0 || j == COL_MAX-1)
     str[i][j]='|';
else
     str[i][j]=' ' ;
     }
}
     }


 }
 




 void Display()
 {
     int i,j;
     system("clear");
     PrintRule(); 
     for(i=0;i < ROW_MAX ;i++)
     {
printf("\r");
for(j=0;j < COL_MAX ;j++)
     printf("%c",str[i][j]);
printf("\n");
     }
 }


 void Init_snake()
 {
     unsigned long int seed = time(NULL);
     srand(seed);
     head = (Snake *)malloc(sizeof(Snake));
     if(head == NULL)
     {
printf("Apply snake head failed!!!\n");
exit(1);
      }
     else
     {
head->place.row = rand() % ( ROW_MAX - 2) + 1;
head->place.col = rand() % ( COL_MAX - 2) + 1;
head->next = NULL;
str[head->place.row][head->place.col] = SNAKE_HEAD ;
snake_length ++ ;
     }


 }
 
/***********   about string handle function  ***********/
int control()
{
int flag = tty_set();
int key = 0;

if(kbhit())
key = getchar();
if(flag == 0)
tty_reset();
return key;
}
static inline int tty_reset()
{
if(tcsetattr(STDIN_FILENO,TCSANOW,&ori_attr) != 0)
return -1;
return 0;
}


static inline int tty_set()
{
if(tcgetattr(STDIN_FILENO,&ori_attr))
return -1;
memcpy(&cur_attr,&ori_attr,sizeof(cur_attr));
cur_attr.c_lflag &= ~ICANON;
cur_attr.c_lflag &= ~ECHO;
cur_attr.c_cc[VMIN] = 1;
cur_attr.c_cc[VTIME] = 0;


if(tcsetattr(STDIN_FILENO,TCSANOW,&cur_attr) != 0)
return -1;
return 0;
}
static inline int kbhit()
{
fd_set rfds;
struct timeval tv;
int retval;


FD_ZERO(&rfds);
FD_SET(0,&rfds);


tv.tv_sec = 0;
tv.tv_usec = 0;


retval = select(1,&rfds,NULL,NULL,&tv);


if(retval == -1)
{
perror("select()");
return 0;
}
else if(retval)
return 1;
else
return 0;


}



