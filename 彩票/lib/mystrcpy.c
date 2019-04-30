void myStrcpy(char *a,char *b)
{
    int i = 0;
    while(*(a + i) != '\0')
    {
        *(a+i) = '\0';
        i++;
    }
    i = 0;
    while(*(b + i) != '\0')
    {
        *(a + i) = *(b + i);
        i++;
    }
}