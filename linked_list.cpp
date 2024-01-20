#include<stdio.h>
#include<stdlib.h>
typedef struct node *Linked;
struct node
{
    int value;
    Linked next;
};
Linked Create_Node(int k)
{
    Linked new_node = (Linked)malloc(sizeof(struct node));
    new_node->value = k;
    new_node->next = NULL;
    return new_node;
}
void inSert_first(Linked &fi,Linked &la,int k)
{
    Linked new_node = Create_Node(k);
    if(fi == NULL) // it mean's la = NULL
    {
        fi = la = new_node;
    }
    new_node->next = fi;
    fi = new_node;
    return;
}
void inSert_last(Linked &fi,Linked &la,int k)
{
    Linked new_node = Create_Node(k);
    if(la == NULL) // it mean's fi = NULL
    {
        fi = la = new_node;
    }
    la->next = new_node; // thang tiep theo cua la(old) se la new_node
    la = new_node; // gan la(moi) la new_node
    return;
}
void printMonitor(Linked NodE)
{
    while(NodE != NULL)
    {
        printf("%d ",NodE->value);
        NodE = NodE->next;
    }
    return;
}
int main()
{
    int n;
    scanf("%d",&n);
    Linked fi = NULL;
    Linked la = NULL;
    for(int i=1;i<=n;++i)
    {
        int k;
        scanf("%d",&k);
        inSert_last(fi,la,k);
    }
    Linked a = fi;
    printMonitor(a);
    printf("\n");
    printMonitor(a);
    return 0;
}

