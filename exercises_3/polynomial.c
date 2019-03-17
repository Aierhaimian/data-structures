#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrNode;

struct Node
{
    int coefficient;
    int exponent;
    PtrNode next;
};

typedef PtrNode Polynomial;

int addPolynomial(const Polynomial p1, const Polynomial p2, Polynomial p)
{
    Polynomial l1, l2, l;
    l1 = p1;
    l2 = p2;
    l = p;
    while(l1->next != NULL && l2-> next != NULL)
    {
        if(l1->next->exponent == l2->next->exponent)
        {
            PtrNode node;
            node = (PtrNode)malloc(sizeof(PtrNode));
            if(node == NULL)
                return -1;
            node->coefficient = l1->next->coefficient + l2->next->coefficient;
            node->exponent = l1->exponent;
            node->next = l->next;
            l->next = node;
            l = node;

            l1 = l1->next;
            l2 = l2->next;
        }else if(l1->next->exponent > l2->next->exponent)
        {
            PtrNode node;
            node = (PtrNode)malloc(sizeof(PtrNode));
            if(node == NULL)
                return -1;
            node->coefficient = l1->next->coefficient;
            node->exponent = l1->next->exponent;
            node->next = l->next;
            l->next = node;
            l = node;

            l1 = l1->next;
        }else
        {
            PtrNode node;
            node = (PtrNode)malloc(sizeof(PtrNode));
            if(node == NULL)
                return -1;
            node->coefficient = l2->next->coefficient;
            node->exponent = l2->next->exponent;
            node->next = l->next;
            l->next = node;
            l = node;

            l2 = l2->next;
        }
    }

    while(l1->next != NULL)
    {
        PtrNode node;
        node = (PtrNode)malloc(sizeof(PtrNode));
        if(node == NULL)
            return -1;
        node->coefficient = l1->next->coefficient;
        node->exponent = l1->next->exponent;
        node->next = l->next;
        l->next = node;
        l = node;

        l1 = l1->next;
    }

    while(l2->next != NULL)
    {
        PtrNode node;
        node = (PtrNode)malloc(sizeof(PtrNode));
        if(node == NULL)
            return -1;
        node->coefficient = l2->next->coefficient;
        node->exponent = l2->next->exponent;
        node->next = l->next;
        l->next = node;
        l = node;

        l2 = l2->next;
    }

    return 0;
}

int multPolynomial(const Polynomial p1, const Polynomial p2, Polynomial p)
{
   return 0; 
}


int main()
{
    return 0;
}
