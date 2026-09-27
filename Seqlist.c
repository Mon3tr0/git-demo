#include <stdio.h>
#include <stdlib.h>
#define InitSize 10

typedef struct
{
    int *data;
    int Maxsize;
    int length;
} SeqList;

void Initlist(SeqList *L);
void IncreaseSize(SeqList *L, int len);
void AddList(SeqList *L, int i, int e);

int main()
{
    SeqList L;
    Initlist(&L);
    int num;
    scanf("%d", &num);
    AddList(&L, 1, num);
    printf("%d", L.data[0]);
    free(L.data);
    return 0;
}

void Initlist(SeqList *L)
{
    L->data = (int *)malloc(InitSize * sizeof(int));
    L->length = 0;
    L->Maxsize = InitSize;
}

void IncreaseSize(SeqList *L, int len)
{
    int *p = L->data;
    L->data = (int *)malloc((L->Maxsize + len) * sizeof(int));
    for (int i = 0; i < L->length; i++)
    {
        L->data[i] = p[i];
    }
    L->Maxsize = L->Maxsize + len;
    free(p);
}

void AddList(SeqList *L, int i, int e)
{
    for (int j = L->length; j >= i; j--)
    {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
}