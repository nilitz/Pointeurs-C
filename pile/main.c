#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "stack.h"

/*-------------------------------------------*/

Stack new_stack(void)
{
    return NULL;
}

/*-------------------------------------------*/

Bool is_empty_stack(Stack st)
{
    if (st == NULL)
    {
        return TRUE;     
    }

    return FALSE;
}

/*-------------------------------------------*/

Stack push_stack(Stack st, int x)
{
    StackElement *element;

    element = malloc(sizeof(*element));

    if (element == NULL)
    {
        fprintf(stderr, "Probleme allocation dynamique");
        exit(EXIT_FAILURE);
    }

    element -> value = x;
    element -> next = st;

    return element;
}

/*-------------------------------------------*/

Stack clear_stack(Stack st)
{
    while(is_empty_stack(st))
    {
        st = pop_stack(st);
    }
    return new_stack();
}

/*-------------------------------------------*/

void print_stack(Stack st)
{
    if (is_empty_stack(st))
    {
        printf("\nRien a afficher, la pile est vide.\n");
    return;
    }

    while (!is_empty_stack(st))
    {
        printf("[%d]\n", st -> value);
        st = st -> next;
    }
}

/*-------------------------------------------*/

Stack pop_stack(Stack st)
{
    StackElement *element;

    if(is_empty_stack(st))
    {
        return new_stack();
    }
    
    element = st ->next;
    free(st);

    return element;
}

/*-------------------------------------------*/

int top_stack(Stack st)
{
    if (is_empty_stack(st))
    {
        printf("\nPas de sommet, la pile est vide.\n");
        return 0;
    }
    return st -> value;
}

/*-------------------------------------------*/

int stack_lenght(Stack st)
{
    int length = 0;

    while (!is_empty_stack(st))
    {
        length++;
        st = st -> next;
    }

    return length;
}

/*-------------------------------------------*/

int main(void)
{
    Stack sta = new_stack();
    print_stack(sta);
    printf("Taille de la pile : %d\n", stack_lenght(sta));

    printf("\n ------------------------ \n");

    sta = push_stack(sta, 14);
    sta = push_stack(sta, 47);
    sta = push_stack(sta, 59);
    sta = push_stack(sta, 17);
    sta = push_stack(sta, 33);
    print_stack(sta);
    printf("Sommet actuel : %d\n", top_stack(sta));
    printf("Taille de la pile : %d\n", stack_lenght(sta));

    printf("\n ------------------------ \n");

    sta = pop_stack(sta); 
    print_stack(sta);
    printf("Sommet actuel : %d\n", top_stack(sta));
    printf("Taille de la pile : %d\n", stack_lenght(sta));

    printf("\n ------------------------ \n");

    sleep(10);

    return 0;
}
