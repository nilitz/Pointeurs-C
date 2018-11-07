#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "code.h"


void create_player(Player *p)
{
    strcpy((*p).username, "Link");
    (*p).HP = 89;
    (*p).MP = 56;
}


int main(void)
{
    int a;
    Player p1 = {"", 0, 0};

    Player tableau_de_joueurs[4];
    tableau_de_joueurs[0].HP = 110;
    strcpu(tableau_de_joueurs[2].username, "Batman");

    create_player(&p1);

    printf("Name : %s\n", p1.username);
    printf("HP : %d | MP : %d\n", p1.HP, p1.MP);

 
    scanf("%d", &a);
    return 0; 
}
