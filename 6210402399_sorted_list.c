#include <stdio.h>
#include <stdlib.h>

typedef struct box 
{
    long num;
    struct box *next;
} Box;

Box *build_box(long x);
void rearrange(Box **starter,Box *coming);


int main()
{
    long n;
    Box *starter = NULL;
    Box *another;
    Box *standin;
    while(1)
    {
        scanf("%d",&n);
        if(n == -1)
        {
            break;
        }
        another = build_box(n);
        rearrange(&starter,another);
    }
    for(standin = starter ; standin ; standin = standin->next)
    {
        printf("%d\n",standin->num);
    }
}


Box *build_box(long n)
{
    Box *point;
    point = (Box *)malloc(sizeof(Box));
    point->num = n;
    point->next = NULL;
    return point;
}

void rearrange(Box **starter,Box *coming)
{
    Box *standin;

    if(*starter == NULL || (*starter)->num >= coming->num)
    {
        coming->next = *starter;
        *starter = coming;
    }
    else
    {
        for(standin = *starter ; standin->next != NULL && ((standin->next)->num < coming->num) ; standin = standin->next);
        coming->next = standin->next;
        standin->next = coming;
    }
}


