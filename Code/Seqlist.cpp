#include <stdio.h>
#include <stdlib.h>

#define InitSize 10
typedef struct
{
    int *data;
    int length;
    int MaxSize;
} Seqlist;

void Initlist(Seqlist *L);
void IncreaseSize(Seqlist *L, int len);
bool ListInert(Seqlist *L, int i, int e);
bool ListDelete(Seqlist *L, int i, int *e);
int GetElem(Seqlist *L, int i);
int LocateElem(Seqlist *L, int e);

int main()
{
    Seqlist L;
    Initlist(&L);
    int e = -1;
    if (ListDelete(&L, 1, &e))
    {
        printf("Deleted element: %d\n", e);
    }
    else
    {
        printf("Deletion failed. List is empty or index is out of bounds.\n");
    }
    return 0;
}

void Initlist(Seqlist *L)
{
    L->data = (int *)malloc(InitSize * sizeof(int));
    L->length = 0;
    L->MaxSize = InitSize;
}
void IncreaseSize(Seqlist *L, int len)
{
    int *p = L->data;
    L->data = (int *)malloc((L->MaxSize + len) * sizeof(int));
    for (int i = 0; i < L->length; i++)
    {
        L->data[i] = p[i];
    }
    L->MaxSize = L->MaxSize + len;
    free(p);
}
bool ListInert(Seqlist *L, int i, int e)
{
    if (i < 1 || i > L->length + 1)
    {
        return false;
    }
    if (L->length >= L->MaxSize)
    {
        return false;
    }
    for (int j = L->length; j >= i; j--)
    {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return true;
}
bool ListDelete(Seqlist *L, int i, int *e)
{
    if (i < 1 || i > L->length)
    {
        return false;
    }
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++)
    {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return true;
}
int GetElem(Seqlist *L, int i)
{
    return L->data[i - 1];
}
int LocateElem(Seqlist *L, int e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}