
#include <stdio.h>
#include <string.h>
int push(char *stk, int *top, char in, int check)
{
    if (check == *top)
    {
        printf("overflow..!!");
        return 0;
    }
    int temp = *top;
    stk[++temp] = in;
    *top = *top + 1;
    return *top;
}
char pop(char *stk, int *top, int check)
{
    if (check == *top)
    {
        printf("Underflow..!!");
        return '0';
    }
    int temp = *top;
    *top = *top - 1;
    return stk[temp];
}
int len(char *str)
{
int i=0;
while(str[i]!='\0')
i++;
return i+1;
}
int isUnderFlow(int top, int length)
{
    if (top == length)
    {
        return -1;
    }
    return 1;
}
int isOverFlow(int top, int bottom)
{
    if (top == bottom)
    {
        return -1;
    }
    return 1;
}
int main(char argv, char *argc[])
{

    FILE *fp;
    fp = fopen(argc[1], "r");
    int t;
    fscanf(fp, "%d", &t);
    printf("Input \t Output\n");
    printf("			\n");
    while (t--)
    {
        int top1 = -1, top2;
        int sts = 0;
        int length = 0;
        char name[100];
        fscanf(fp, "%s", name);
        length = _strlen(name);
        char arrStack[length * 2];
        top2 = length - 1;
        printf("%s\t", name);
        for (int i = 0; i < length; i++)
        {
            if ((name[i] >= 'a' && name[i] < 'z') || (name[i] >= 'A' && name[i] <= 'Z'))
            {
                push(arrStack, &top1, name[i], length);
            }
            else
            {
                sts = 1;
                break;
            }
        }
        if (sts == 1)
        {
            printf("Name cant have special character or number..!!\n");
            continue;
        }
        while (top1 != -1)
        {
            push(arrStack, &top2, pop(arrStack, &top1, -1), length * 2);
        }
        while (top2 != length - 1)
        {
            push(arrStack, &top1, pop(arrStack, &top2, length - 1), length);
        }
        while (top1 != -1)
        {
            printf("%c", pop(arrStack, &top1, -1));
        }
        printf("\n");
    }
}
