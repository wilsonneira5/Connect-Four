/// Connect_Four.c
/// Author: Wilson Neira
/// Date: 6/29/2021
/// Connect Four Game against AI

#include <stdio.h>
#include <malloc.h>
#include <time.h>

// We will use this struct to create the Grid for our Connect Four Game
struct Grid {
    char data;
    struct Grid * up;
    struct Grid * down;
    struct Grid * left;
    struct Grid * right;
    struct Grid * upLeft;
    struct Grid * upRight;
    struct Grid * downLeft;
    struct Grid * downRight;
};

// We shall use the struct Move to keep our game record moves
struct Move {
    char data;
    struct Move * next;
};

// This function will get used to print the game record moves
void printList(struct Move *node);

// This function is used to print the Grid
void printGrid(struct Grid *node);

// This function is used to append moves to the game record moves
void append(struct Move** head_ref, char new_data)
{
    struct Move* new_node = (struct Move*) malloc(sizeof(struct Move));

    struct Move *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

// This function is used to create a new node
struct Grid* nodeCreate(char new_data)
{

    struct Grid* new_node = (struct Grid*) malloc(sizeof(struct Grid));
    new_node->data = new_data;

    return new_node;
}

// This function is used to create the grid
void gridSection(struct Grid* head, struct Grid* up, struct Grid* down, struct Grid* left, struct Grid* right,
                 struct Grid* upLeft, struct Grid* upRight, struct Grid* downLeft, struct Grid* downRight)
{
    head->up = up;
    head->down = down;
    head->left = left;
    head->right = right;
    head->upLeft = upLeft;
    head->upRight = upRight;
    head->downLeft = downLeft;
    head->downRight = downRight;
}

// The game starts here
int main() {

    // Struct to store game record moves
    struct Move *head = NULL;
    struct Move first;

    // Game Title
    printf("Connect Four!\n");


    //Printing the empty grid
    printf("    A  B  C  D  E  F  G\n");
    printf(" 6 ");
    // 6A
    struct Grid* row6 = (struct Grid*) malloc(sizeof(struct Grid));
    row6 ->data = '.';
    gridSection(row6, NULL, nodeCreate('.'), NULL, nodeCreate('.'), NULL,
                NULL, NULL, nodeCreate('.'));

    // 6B
    gridSection(row6->right, NULL, nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'), NULL,NULL, nodeCreate('.'),
                nodeCreate('.'));

    // 6C
    gridSection(row6->right->right, NULL, nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'), NULL,NULL, nodeCreate('.'),
                nodeCreate('.'));

    // 6D
    gridSection(row6->right->right->right, NULL, nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'), NULL,NULL, nodeCreate('.'),
                nodeCreate('.'));

    // 6E
    gridSection(row6->right->right->right->right, NULL, nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'), NULL,NULL, nodeCreate('.'),
                nodeCreate('.'));

    // 6F
    gridSection(row6->right->right->right->right->right, NULL, nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'), NULL,NULL, nodeCreate('.'),
                nodeCreate('.'));

    // 6G
    gridSection(row6->right->right->right->right->right->right, NULL, nodeCreate('.'),
                nodeCreate('.'),NULL, NULL,NULL,nodeCreate('.'),
                NULL);

    printGrid(row6);
    printf("\n");

    printf(" 5 ");
    // 5A
    gridSection(row6->down, nodeCreate('.'), nodeCreate('.'), NULL,
                nodeCreate('.'), NULL,nodeCreate('.'),
                NULL, nodeCreate('.'));

    // 5B
    gridSection(row6->down->right, nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'));

    // 5C
    gridSection(row6->down->right->right, nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'));

    // 5D
    gridSection(row6->down->right->right->right, nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'));

    // 5E
    gridSection(row6->down->right->right->right->right, nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'));

    // 5F
    gridSection(row6->down->right->right->right->right->right, nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'));

    // 5G
    gridSection(row6->down->right->right->right->right->right->right, nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'),NULL, nodeCreate('.'),
                NULL,nodeCreate('.'), NULL);

    printGrid(row6->down);
    printf("\n");

    printf(" 4 ");
    // 4A
    gridSection(row6->down->down, nodeCreate('.'), nodeCreate('.'), NULL,
                nodeCreate('.'), NULL,nodeCreate('.'),
                NULL, nodeCreate('.'));

    // 4B
    gridSection(row6->down->down->right, nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'));

    // 4C
    gridSection(row6->down->down->right->right, nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'));

    // 4D
    gridSection(row6->down->down->right->right->right, nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'));

    // 4E
    gridSection(row6->down->down->right->right->right->right, nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'));

    // 4F
    gridSection(row6->down->down->right->right->right->right->right, nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'),nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'),nodeCreate('.'),
                nodeCreate('.'));

    // 4G
    gridSection(row6->down->down->right->right->right->right->right->right, nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'),NULL, nodeCreate('.'),
                NULL,nodeCreate('.'), NULL);

    printGrid(row6->down->down);
    printf("\n");

    printf(" 3 ");
    // 3A
    gridSection(row6->down->down->down, nodeCreate('.'), nodeCreate('.'), NULL,
                nodeCreate('.'), NULL,nodeCreate('.'),
                NULL, nodeCreate('.'));

    // 3B
    gridSection(row6->down->down->down->right, nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'));

    // 3C
    gridSection(row6->down->down->down->right->right, nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'));

    // 3D
    gridSection(row6->down->down->down->right->right->right, nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'));

    // 3E
    gridSection(row6->down->down->down->right->right->right->right, nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'),nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'),nodeCreate('.'),
                nodeCreate('.'));

    // 3F
    gridSection(row6->down->down->down->right->right->right->right->right, nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'),nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'),nodeCreate('.'),
                nodeCreate('.'));

    // 3G
    gridSection(row6->down->down->down->right->right->right->right->right->right, nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'),NULL, nodeCreate('.'),
                NULL,nodeCreate('.'), NULL);

    printGrid(row6->down->down->down);
    printf("\n");

    printf(" 2 ");
    // 2A
    gridSection(row6->down->down->down->down, nodeCreate('.'), nodeCreate('.'), NULL,
                nodeCreate('.'), NULL,nodeCreate('.'),
                NULL, nodeCreate('.'));

    // 2B
    gridSection(row6->down->down->down->down->right, nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'));

    // 2C
    gridSection(row6->down->down->down->down->right->right, nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'));

    // 2D
    gridSection(row6->down->down->down->down->right->right->right, nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'),nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'),nodeCreate('.'),
                nodeCreate('.'));

    // 2E
    gridSection(row6->down->down->down->down->right->right->right->right, nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'),nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'),nodeCreate('.'),
                nodeCreate('.'));

    // 2F
    gridSection(row6->down->down->down->down->right->right->right->right->right, nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'),nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'),nodeCreate('.'),
                nodeCreate('.'));

    // 2G
    gridSection(row6->down->down->down->down->right->right->right->right->right->right, nodeCreate('.'),
                nodeCreate('.'),nodeCreate('.'),NULL, nodeCreate('.'),
                NULL,nodeCreate('.'), NULL);

    printGrid(row6->down->down->down->down);
    printf("\n");

    printf(" 1 ");
    // 1A
    gridSection(row6->down->down->down->down->down, nodeCreate('.'), NULL, NULL,
                nodeCreate('.'), NULL,nodeCreate('.'),NULL, NULL);

    // 1B
    gridSection(row6->down->down->down->down->down->right, nodeCreate('.'), NULL,
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),NULL, NULL);

    // 1C
    gridSection(row6->down->down->down->down->down->right->right, nodeCreate('.'), NULL,
                nodeCreate('.'),nodeCreate('.'), nodeCreate('.'),
                nodeCreate('.'),NULL, NULL);

    // 1D
    gridSection(row6->down->down->down->down->down->right->right->right, nodeCreate('.'),
                NULL,nodeCreate('.'),nodeCreate('.'),nodeCreate('.'),
                nodeCreate('.'),NULL,NULL);

    // 1E
    gridSection(row6->down->down->down->down->down->right->right->right->right, nodeCreate('.'),
                NULL,nodeCreate('.'),nodeCreate('.'),nodeCreate('.'),
                nodeCreate('.'),NULL,NULL);

    // 1F
    gridSection(row6->down->down->down->down->down->right->right->right->right->right, nodeCreate('.'),
                NULL,nodeCreate('.'),nodeCreate('.'),nodeCreate('.'),
                nodeCreate('.'),NULL,NULL);

    // 1G
    gridSection(row6->down->down->down->down->down->right->right->right->right->right->right, nodeCreate('.'),
                NULL,nodeCreate('.'),NULL, nodeCreate('.'),
                NULL,NULL, NULL);

    printGrid(row6->down->down->down->down->down);
    printf("\n");

    // Variable used in gameplay
    char YN;

    int Acounter = 0;
    int Bcounter = 0;
    int Ccounter = 0;
    int Dcounter = 0;
    int Ecounter = 0;
    int Fcounter = 0;
    int Gcounter = 0;

    int AIrand;
    char AIChoose;

    int intLet = 0;

    // Gamplay starts here
    // Decide if you want to go first or let the AI go first
    printf("\nDo you want to go first? Y or N:\n");
    scanf("%c", &YN);

    // Game loops so you have enough chances to fill up the grid or win by connecting four or losing
    for (intLet = 0; intLet < 46; intLet++) {
        char Let;

        // AI starts first with their game decision
        if((int) YN == 'N' && intLet > 0 && intLet%2 == 1)
        {
            srand(time(NULL));

            AIrand = rand()%7;

            if(AIrand == 1)
            {
                AIChoose = 'A';
            }
            else if (AIrand == 2)
            {
                AIChoose = 'B';
            }
            else if (AIrand == 3)
            {
                AIChoose = 'C';
            }
            else if (AIrand == 4)
            {
                AIChoose = 'D';
            }
            else if (AIrand == 5)
            {
                AIChoose = 'E';
            }
            else if (AIrand == 6)
            {
                AIChoose = 'F';
            }
            else if (AIrand == 7)
            {
                AIChoose = 'G';
            }

            printf("\nAI Start:\nWhere would you like to drop your disc from letter A B C D E F or G?\n");
            printf("\nAI Chooses: %c\n", AIChoose);

        }

        // You start making game decisions
        printf("\nPlayer One Start:\n");
        printf("Where would you like to drop your disc from letter A B C D E F or G?\n");
        scanf("%c", &Let);

        // AI starts second with making game decisions
        if((int) YN == 'Y' && intLet > 0 && intLet%2 == 1)
        {
            srand(time(NULL));

            AIrand = rand()%7;

            if(AIrand == 1)
            {
                AIChoose = 'A';
            }
            else if (AIrand == 2)
            {
                AIChoose = 'B';
            }
            else if (AIrand == 3)
            {
                AIChoose = 'C';
            }
            else if (AIrand == 4)
            {
                AIChoose = 'D';
            }
            else if (AIrand == 5)
            {
                AIChoose = 'E';
            }
            else if (AIrand == 6)
            {
                AIChoose = 'F';
            }
            else if (AIrand == 7)
            {
                AIChoose = 'G';
            }

            printf("\nAI Start:\nWhere would you like to drop your disc from letter A B C D E F or G?\n");
            printf("\nAI Chooses: %c\n", AIChoose);

        }

        // Append game record moves
        if((int) YN == 'N')
        {
            append(&head, AIChoose);
            append(&head, Let);
        }

        if((int) YN == 'Y')
        {
            append(&head, Let);
            append(&head, AIChoose);
        }


        // AI first to where the disc should replace the dot
        if((int) YN == 'N' && intLet%2 == 1)
        {
            if((int) AIChoose == 'A')
            {
                Acounter++;

            }

            else if((int) AIChoose == 'B')
            {
                Bcounter++;

            }

            else if((int) AIChoose == 'C')
            {
                Ccounter++;

            }

            else if((int) AIChoose == 'D')
            {
                Dcounter++;

            }

            else if((int) AIChoose == 'E')
            {
                Ecounter++;

            }

            else if((int) AIChoose == 'F')
            {
                Fcounter++;
            }

            else if((int) AIChoose == 'G')
            {
                Gcounter++;
            }

            if(Acounter == 1 && (int)row6->down->down->down->down->down->data != 'X')
            {
                row6->down->down->down->down->down->data = 'O';

            }
            else if(Acounter == 2 && (int)row6->down->down->down->down->data != 'X')
            {
                row6->down->down->down->down->data = 'O';

            }
            else if(Acounter == 3 && (int)row6->down->down->down->data != 'X')
            {
                row6->down->down->down->data = 'O';
            }
            else if(Acounter == 4 && (int)row6->down->down->data != 'X')
            {
                row6->down->down->data = 'O';
            }
            else if(Acounter == 5 && (int)row6->down->data != 'X')
            {
                row6->down->data = 'O';
            }
            else if(Acounter == 6 && (int)row6->data != 'X')
            {
                row6->data = 'O';
            }

            if(Bcounter == 1 && (int)row6->down->down->down->down->down->right->data != 'X')
            {
                row6->down->down->down->down->down->right->data = 'O';
            }
            else if(Bcounter == 2 && (int)row6->down->down->down->down->right->data != 'X')
            {
                row6->down->down->down->down->right->data = 'O';
            }
            else if(Bcounter == 3 && (int)row6->down->down->down->right->data != 'X')
            {
                row6->down->down->down->right->data = 'O';
            }
            else if(Bcounter == 4 && (int)row6->down->down->right->data != 'X')
            {
                row6->down->down->right->data = 'O';
            }
            else if(Bcounter == 5 && (int)row6->down->right->data != 'X')
            {
                row6->down->right->data = 'O';
            }
            else if(Bcounter == 6 && (int)row6->right->data != 'X')
            {
                row6->right->data = 'O';
            }

            if(Ccounter == 1 && (int)row6->down->down->down->down->down->right->right->data != 'X')
            {
                row6->down->down->down->down->down->right->right->data = 'O';
            }
            else if(Ccounter == 2 && (int)row6->down->down->down->down->right->right->data != 'X')
            {
                row6->down->down->down->down->right->right->data = 'O';
            }
            else if(Ccounter == 3 && (int)row6->down->down->down->right->right->data != 'X')
            {
                row6->down->down->down->right->right->data = 'O';
            }
            else if(Ccounter == 4 && (int)row6->down->down->right->right->data != 'X')
            {
                row6->down->down->right->right->data = 'O';
            }
            else if(Ccounter == 5 && (int)row6->down->right->right->data != 'X')
            {
                row6->down->right->right->data = 'O';
            }
            else if(Ccounter == 6 && (int)row6->right->right->data != 'X')
            {
                row6->right->right->data = 'O';
            }


            if(Dcounter == 1 && (int)row6->down->down->down->down->down->right->right->right->data != 'X')
            {
                row6->down->down->down->down->down->right->right->right->data = 'O';
            }
            else if(Dcounter == 2 && (int)row6->down->down->down->down->right->right->right->data != 'X')
            {
                row6->down->down->down->down->right->right->right->data = 'O';
            }
            else if(Dcounter == 3 && (int)row6->down->down->down->right->right->right->data != 'X')
            {
                row6->down->down->down->right->right->right->data = 'O';
            }
            else if(Dcounter == 4 && (int)row6->down->down->right->right->right->data != 'X')
            {
                row6->down->down->right->right->right->data = 'O';
            }
            else if(Dcounter == 5 && (int)row6->down->right->right->right->data != 'X')
            {
                row6->down->right->right->right->data = 'O';
            }
            else if(Dcounter == 6 && (int)row6->right->right->right->data != 'X')
            {
                row6->right->right->right->data = 'O';
            }


            if(Ecounter == 1 && (int)row6->down->down->down->down->down->right->right->right->right->data != 'X')
            {
                row6->down->down->down->down->down->right->right->right->right->data = 'O';
            }
            else if(Ecounter == 2 && (int)row6->down->down->down->down->right->right->right->right->data != 'X')
            {
                row6->down->down->down->down->right->right->right->right->data = 'O';
            }
            else if(Ecounter == 3 && (int)row6->down->down->down->right->right->right->right->data != 'X')
            {
                row6->down->down->down->right->right->right->right->data = 'O';
            }
            else if(Ecounter == 4 && (int)row6->down->down->right->right->right->right->data != 'X')
            {
                row6->down->down->right->right->right->right->data = 'O';
            }
            else if(Ecounter == 5 && (int)row6->down->right->right->right->right->data != 'X')
            {
                row6->down->right->right->right->right->data = 'O';
            }
            else if(Ecounter == 6 && (int)row6->right->right->right->right->data != 'X')
            {
                row6->right->right->right->right->data = 'O';
            }


            if(Fcounter == 1 && (int)row6->down->down->down->down->down->right->right->right->right->right->data != 'X')
            {
                row6->down->down->down->down->down->right->right->right->right->right->data = 'O';
            }
            else if(Fcounter == 2 && (int)row6->down->down->down->down->right->right->right->right->right->data != 'X')
            {
                row6->down->down->down->down->right->right->right->right->right->data = 'O';
            }
            else if(Fcounter == 3 && (int)row6->down->down->down->right->right->right->right->right->data != 'X')
            {
                row6->down->down->down->right->right->right->right->right->data = 'O';
            }
            else if(Fcounter == 4 && (int)row6->down->down->right->right->right->right->right->data != 'X')
            {
                row6->down->down->right->right->right->right->right->data = 'O';
            }
            else if(Fcounter == 5 && (int)row6->down->right->right->right->right->right->data != 'X')
            {
                row6->down->right->right->right->right->right->data = 'O';
            }
            else if(Fcounter == 6 && (int)row6->right->right->right->right->right->data != 'X')
            {
                row6->right->right->right->right->right->data = 'O';
            }


            if(Gcounter == 1 && (int)row6->down->down->down->down->down->right->right->right->right->right->right->data != 'X')
            {
                row6->down->down->down->down->down->right->right->right->right->right->right->data = 'O';
            }
            else if(Gcounter == 2 && (int)row6->down->down->down->down->right->right->right->right->right->right->data != 'X')
            {
                row6->down->down->down->down->right->right->right->right->right->right->data = 'O';
            }
            else if(Gcounter == 3 && (int)row6->down->down->down->right->right->right->right->right->right->data != 'X')
            {
                row6->down->down->down->right->right->right->right->right->right->data = 'O';
            }
            else if(Gcounter == 4 && (int)row6->down->down->right->right->right->right->right->right->data != 'X')
            {
                row6->down->down->right->right->right->right->right->right->data = 'O';
            }
            else if(Gcounter == 5 && (int)row6->down->right->right->right->right->right->right->data != 'X')
            {
                row6->down->right->right->right->right->right->right->data = 'O';
            }
            else if(Gcounter == 6 && (int)row6->right->right->right->right->right->right->data != 'X')
            {
                row6->right->right->right->right->right->right->data = 'O';
            }
        }

        // Player disc to where it should move to replace the dot
        if((int) Let == 'A')
        {
            Acounter++;
        }

        else if((int) Let == 'B')
        {
            Bcounter++;
        }

        else if((int) Let == 'C')
        {
            Ccounter++;
        }

        else if((int) Let == 'D')
        {
            Dcounter++;
        }

        else if((int) Let == 'E')
        {
            Ecounter++;
        }

        else if((int) Let == 'F')
        {
            Fcounter++;
        }

        else if((int) Let == 'G')
        {
            Gcounter++;
        }


        if(Acounter == 1 && (int)row6->down->down->down->down->down->data != 'O')
        {
            row6->down->down->down->down->down->data = 'X';

        }
        else if(Acounter == 2 && (int)row6->down->down->down->down->data != 'O')
        {
            row6->down->down->down->down->data = 'X';

        }
        else if(Acounter == 3 && (int)row6->down->down->down->data != 'O')
        {
            row6->down->down->down->data = 'X';
        }
        else if(Acounter == 4 && (int)row6->down->down->data != 'O')
        {
            row6->down->down->data = 'X';
        }
        else if(Acounter == 5 && (int)row6->down->data != 'O')
        {
            row6->down->data = 'X';
        }
        else if(Acounter == 6 && (int)row6->data != 'O')
        {
            row6->data = 'X';
        }

        if(Bcounter == 1 && (int)row6->down->down->down->down->down->right->data != 'O')
        {
            row6->down->down->down->down->down->right->data = 'X';
        }
        else if(Bcounter == 2 && (int)row6->down->down->down->down->right->data != 'O')
        {
            row6->down->down->down->down->right->data = 'X';
        }
        else if(Bcounter == 3 && (int)row6->down->down->down->right->data != 'O')
        {
            row6->down->down->down->right->data = 'X';
        }
        else if(Bcounter == 4 && (int)row6->down->down->right->data != 'O')
        {
            row6->down->down->right->data = 'X';
        }
        else if(Bcounter == 5 && (int)row6->down->right->data != 'O')
        {
            row6->down->right->data = 'X';
        }
        else if(Bcounter == 6 && (int)row6->right->data != 'O')
        {
            row6->right->data = 'X';
        }

        if(Ccounter == 1 && (int)row6->down->down->down->down->down->right->right->data != 'O')
        {
            row6->down->down->down->down->down->right->right->data = 'X';
        }
        else if(Ccounter == 2 && (int)row6->down->down->down->down->right->right->data != 'O')
        {
            row6->down->down->down->down->right->right->data = 'X';
        }
        else if(Ccounter == 3 && (int)row6->down->down->down->right->right->data != 'O')
        {
            row6->down->down->down->right->right->data = 'X';
        }
        else if(Ccounter == 4 && (int)row6->down->down->right->right->data != 'O')
        {
            row6->down->down->right->right->data = 'X';
        }
        else if(Ccounter == 5 && (int)row6->down->right->right->data != 'O')
        {
            row6->down->right->right->data = 'X';
        }
        else if(Ccounter == 6 && (int)row6->right->right->data != 'O')
        {
            row6->right->right->data = 'X';
        }


        if(Dcounter == 1 && (int)row6->down->down->down->down->down->right->right->right->data != 'O')
        {
            row6->down->down->down->down->down->right->right->right->data = 'X';
        }
        else if(Dcounter == 2 && (int)row6->down->down->down->down->right->right->right->data != 'O')
        {
            row6->down->down->down->down->right->right->right->data = 'X';
        }
        else if(Dcounter == 3 && (int)row6->down->down->down->right->right->right->data != 'O')
        {
            row6->down->down->down->right->right->right->data = 'X';
        }
        else if(Dcounter == 4 && (int)row6->down->down->right->right->right->data != 'O')
        {
            row6->down->down->right->right->right->data = 'X';
        }
        else if(Dcounter == 5 && (int)row6->down->right->right->right->data != 'O')
        {
            row6->down->right->right->right->data = 'X';
        }
        else if(Dcounter == 6 && (int)row6->right->right->right->data != 'O')
        {
            row6->right->right->right->data = 'X';
        }


        if(Ecounter == 1 && (int)row6->down->down->down->down->down->right->right->right->right->data != 'O')
        {
            row6->down->down->down->down->down->right->right->right->right->data = 'X';
        }
        else if(Ecounter == 2 && (int)row6->down->down->down->down->right->right->right->right->data != 'O')
        {
            row6->down->down->down->down->right->right->right->right->data = 'X';
        }
        else if(Ecounter == 3 && (int)row6->down->down->down->right->right->right->right->data != 'O')
        {
            row6->down->down->down->right->right->right->right->data = 'X';
        }
        else if(Ecounter == 4 && (int)row6->down->down->right->right->right->right->data != 'O')
        {
            row6->down->down->right->right->right->right->data = 'X';
        }
        else if(Ecounter == 5 && (int)row6->down->right->right->right->right->data != 'O')
        {
            row6->down->right->right->right->right->data = 'X';
        }
        else if(Ecounter == 6 && (int)row6->right->right->right->right->data != 'O')
        {
            row6->right->right->right->right->data = 'X';
        }


        if(Fcounter == 1 && (int)row6->down->down->down->down->down->right->right->right->right->right->data != 'O')
        {
            row6->down->down->down->down->down->right->right->right->right->right->data = 'X';
        }
        else if(Fcounter == 2 && (int)row6->down->down->down->down->right->right->right->right->right->data != 'O')
        {
            row6->down->down->down->down->right->right->right->right->right->data = 'X';
        }
        else if(Fcounter == 3 && (int)row6->down->down->down->right->right->right->right->right->data != 'O')
        {
            row6->down->down->down->right->right->right->right->right->data = 'X';
        }
        else if(Fcounter == 4 && (int)row6->down->down->right->right->right->right->right->data != 'O')
        {
            row6->down->down->right->right->right->right->right->data = 'X';
        }
        else if(Fcounter == 5 && (int)row6->down->right->right->right->right->right->data != 'O')
        {
            row6->down->right->right->right->right->right->data = 'X';
        }
        else if(Fcounter == 6 && (int)row6->right->right->right->right->right->data != 'O')
        {
            row6->right->right->right->right->right->data = 'X';
        }


        if(Gcounter == 1 && (int)row6->down->down->down->down->down->right->right->right->right->right->right->data != 'O')
        {
            row6->down->down->down->down->down->right->right->right->right->right->right->data = 'X';
        }
        else if(Gcounter == 2 && (int)row6->down->down->down->down->right->right->right->right->right->right->data != 'O')
        {
            row6->down->down->down->down->right->right->right->right->right->right->data = 'X';
        }
        else if(Gcounter == 3 && (int)row6->down->down->down->right->right->right->right->right->right->data != 'O')
        {
            row6->down->down->down->right->right->right->right->right->right->data = 'X';
        }
        else if(Gcounter == 4 && (int)row6->down->down->right->right->right->right->right->right->data != 'O')
        {
            row6->down->down->right->right->right->right->right->right->data = 'X';
        }
        else if(Gcounter == 5 && (int)row6->down->right->right->right->right->right->right->data != 'O')
        {
            row6->down->right->right->right->right->right->right->data = 'X';
        }
        else if(Gcounter == 6 && (int)row6->right->right->right->right->right->right->data != 'O')
        {
            row6->right->right->right->right->right->right->data = 'X';
        }

        // AI second disc move to where the disc should replace the dot
        if((int) YN == 'Y' && intLet%2 == 1)
        {
            if((int) AIChoose == 'A')
            {
                Acounter++;

            }

            else if((int) AIChoose == 'B')
            {
                Bcounter++;

            }

            else if((int) AIChoose == 'C')
            {
                Ccounter++;

            }

            else if((int) AIChoose == 'D')
            {
                Dcounter++;

            }

            else if((int) AIChoose == 'E')
            {
                Ecounter++;

            }

            else if((int) AIChoose == 'F')
            {
                Fcounter++;
            }

            else if((int) AIChoose == 'G')
            {
                Gcounter++;
            }

            if(Acounter == 1 && (int)row6->down->down->down->down->down->data != 'X')
            {
                row6->down->down->down->down->down->data = 'O';

            }
            else if(Acounter == 2 && (int)row6->down->down->down->down->data != 'X')
            {
                row6->down->down->down->down->data = 'O';

            }
            else if(Acounter == 3 && (int)row6->down->down->down->data != 'X')
            {
                row6->down->down->down->data = 'O';
            }
            else if(Acounter == 4 && (int)row6->down->down->data != 'X')
            {
                row6->down->down->data = 'O';
            }
            else if(Acounter == 5 && (int)row6->down->data != 'X')
            {
                row6->down->data = 'O';
            }
            else if(Acounter == 6 && (int)row6->data != 'X')
            {
                row6->data = 'O';
            }

            if(Bcounter == 1 && (int)row6->down->down->down->down->down->right->data != 'X')
            {
                row6->down->down->down->down->down->right->data = 'O';
            }
            else if(Bcounter == 2 && (int)row6->down->down->down->down->right->data != 'X')
            {
                row6->down->down->down->down->right->data = 'O';
            }
            else if(Bcounter == 3 && (int)row6->down->down->down->right->data != 'X')
            {
                row6->down->down->down->right->data = 'O';
            }
            else if(Bcounter == 4 && (int)row6->down->down->right->data != 'X')
            {
                row6->down->down->right->data = 'O';
            }
            else if(Bcounter == 5 && (int)row6->down->right->data != 'X')
            {
                row6->down->right->data = 'O';
            }
            else if(Bcounter == 6 && (int)row6->right->data != 'X')
            {
                row6->right->data = 'O';
            }

            if(Ccounter == 1 && (int)row6->down->down->down->down->down->right->right->data != 'X')
            {
                row6->down->down->down->down->down->right->right->data = 'O';
            }
            else if(Ccounter == 2 && (int)row6->down->down->down->down->right->right->data != 'X')
            {
                row6->down->down->down->down->right->right->data = 'O';
            }
            else if(Ccounter == 3 && (int)row6->down->down->down->right->right->data != 'X')
            {
                row6->down->down->down->right->right->data = 'O';
            }
            else if(Ccounter == 4 && (int)row6->down->down->right->right->data != 'X')
            {
                row6->down->down->right->right->data = 'O';
            }
            else if(Ccounter == 5 && (int)row6->down->right->right->data != 'X')
            {
                row6->down->right->right->data = 'O';
            }
            else if(Ccounter == 6 && (int)row6->right->right->data != 'X')
            {
                row6->right->right->data = 'O';
            }


            if(Dcounter == 1 && (int)row6->down->down->down->down->down->right->right->right->data != 'X')
            {
                row6->down->down->down->down->down->right->right->right->data = 'O';
            }
            else if(Dcounter == 2 && (int)row6->down->down->down->down->right->right->right->data != 'X')
            {
                row6->down->down->down->down->right->right->right->data = 'O';
            }
            else if(Dcounter == 3 && (int)row6->down->down->down->right->right->right->data != 'X')
            {
                row6->down->down->down->right->right->right->data = 'O';
            }
            else if(Dcounter == 4 && (int)row6->down->down->right->right->right->data != 'X')
            {
                row6->down->down->right->right->right->data = 'O';
            }
            else if(Dcounter == 5 && (int)row6->down->right->right->right->data != 'X')
            {
                row6->down->right->right->right->data = 'O';
            }
            else if(Dcounter == 6 && (int)row6->right->right->right->data != 'X')
            {
                row6->right->right->right->data = 'O';
            }


            if(Ecounter == 1 && (int)row6->down->down->down->down->down->right->right->right->right->data != 'X')
            {
                row6->down->down->down->down->down->right->right->right->right->data = 'O';
            }
            else if(Ecounter == 2 && (int)row6->down->down->down->down->right->right->right->right->data != 'X')
            {
                row6->down->down->down->down->right->right->right->right->data = 'O';
            }
            else if(Ecounter == 3 && (int)row6->down->down->down->right->right->right->right->data != 'X')
            {
                row6->down->down->down->right->right->right->right->data = 'O';
            }
            else if(Ecounter == 4 && (int)row6->down->down->right->right->right->right->data != 'X')
            {
                row6->down->down->right->right->right->right->data = 'O';
            }
            else if(Ecounter == 5 && (int)row6->down->right->right->right->right->data != 'X')
            {
                row6->down->right->right->right->right->data = 'O';
            }
            else if(Ecounter == 6 && (int)row6->right->right->right->right->data != 'X')
            {
                row6->right->right->right->right->data = 'O';
            }


            if(Fcounter == 1 && (int)row6->down->down->down->down->down->right->right->right->right->right->data != 'X')
            {
                row6->down->down->down->down->down->right->right->right->right->right->data = 'O';
            }
            else if(Fcounter == 2 && (int)row6->down->down->down->down->right->right->right->right->right->data != 'X')
            {
                row6->down->down->down->down->right->right->right->right->right->data = 'O';
            }
            else if(Fcounter == 3 && (int)row6->down->down->down->right->right->right->right->right->data != 'X')
            {
                row6->down->down->down->right->right->right->right->right->data = 'O';
            }
            else if(Fcounter == 4 && (int)row6->down->down->right->right->right->right->right->data != 'X')
            {
                row6->down->down->right->right->right->right->right->data = 'O';
            }
            else if(Fcounter == 5 && (int)row6->down->right->right->right->right->right->data != 'X')
            {
                row6->down->right->right->right->right->right->data = 'O';
            }
            else if(Fcounter == 6 && (int)row6->right->right->right->right->right->data != 'X')
            {
                row6->right->right->right->right->right->data = 'O';
            }


            if(Gcounter == 1 && (int)row6->down->down->down->down->down->right->right->right->right->right->right->data != 'X')
            {
                row6->down->down->down->down->down->right->right->right->right->right->right->data = 'O';
            }
            else if(Gcounter == 2 && (int)row6->down->down->down->down->right->right->right->right->right->right->data != 'X')
            {
                row6->down->down->down->down->right->right->right->right->right->right->data = 'O';
            }
            else if(Gcounter == 3 && (int)row6->down->down->down->right->right->right->right->right->right->data != 'X')
            {
                row6->down->down->down->right->right->right->right->right->right->data = 'O';
            }
            else if(Gcounter == 4 && (int)row6->down->down->right->right->right->right->right->right->data != 'X')
            {
                row6->down->down->right->right->right->right->right->right->data = 'O';
            }
            else if(Gcounter == 5 && (int)row6->down->right->right->right->right->right->right->data != 'X')
            {
                row6->down->right->right->right->right->right->right->data = 'O';
            }
            else if(Gcounter == 6 && (int)row6->right->right->right->right->right->right->data != 'X')
            {
                row6->right->right->right->right->right->right->data = 'O';
            }
        }

        // Print game grid with new discs from player and AI
        printf("\n    A  B  C  D  E  F  G\n");

        printf(" 6 ");
        printGrid(row6);
        printf("\n");
        printf(" 5 ");
        printGrid(row6->down);
        printf("\n");
        printf(" 4 ");
        printGrid(row6->down->down);
        printf("\n");
        printf(" 3 ");
        printGrid(row6->down->down->down);
        printf("\n");
        printf(" 2 ");
        printGrid(row6->down->down->down->down);
        printf("\n");
        printf(" 1 ");
        printGrid(row6->down->down->down->down->down);
        printf("\n");


        // Win
        // Here we will check and see if Player One has connected four discs
        //Vertical
        if(row6->down->down->down->down->down->data == 'X')
        {
            if( row6->down->down->down->down->data == 'X')
            {
                if( row6->down->down->down->data == 'X')
                {
                    if( row6->down->down->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }

            //Horizontal
            if(row6->down->down->down->down->down->right->data == 'X')
            {
                if(row6->down->down->down->down->down->right->right->data == 'X')
                {
                    if(row6->down->down->down->down->down->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->data == 'X')
        {
            if( row6->down->down->down->data == 'X')
            {
                if( row6->down->down->data == 'X')
                {
                    if( row6->down->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }

            // Horizontal
            if( row6->down->down->down->down->right->data == 'X')
            {
                if( row6->down->down->down->down->right->right->data == 'X')
                {
                    if( row6->down->down->down->down->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->data == 'X')
        {
            if( row6->down->down->data == 'X')
            {
                if( row6->down->data == 'X')
                {
                    if( row6->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
            if( row6->down->down->down->right->data == 'X')
            {
                if( row6->down->down->down->right->right->data == 'X')
                {
                    if( row6->down->down->down->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        // Horizontal
        if(row6->down->down->down->down->down->right->data == 'X')
        {
            if( row6->down->down->down->down->down->right->right->data == 'X')
            {
                if( row6->down->down->down->down->down->right->right->right->data == 'X')
                {
                    if( row6->down->down->down->down->down->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->down->right->right->data == 'X')
        {
            if( row6->down->down->down->down->down->right->right->right->data == 'X')
            {
                if( row6->down->down->down->down->down->right->right->right->right->data == 'X')
                {
                    if( row6->down->down->down->down->down->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->down->right->right->right->data == 'X')
        {
            if( row6->down->down->down->down->down->right->right->right->right->data == 'X')
            {
                if( row6->down->down->down->down->down->right->right->right->right->right->data == 'X')
                {
                    if( row6->down->down->down->down->down->right->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }





        //Vertical B
        if(row6->down->down->down->down->down->right->data == 'X')
        {
            if( row6->down->down->down->down->right->data == 'X')
            {
                if( row6->down->down->down->right->data == 'X')
                {
                    if( row6->down->down->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->data == 'X')
        {
            if( row6->down->down->down->right->data == 'X')
            {
                if( row6->down->down->right->data == 'X')
                {
                    if( row6->down->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->data == 'X')
        {
            if( row6->down->down->right->data == 'X')
            {
                if( row6->down->right->data == 'X')
                {
                    if( row6->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        // Horizontal
        if(row6->down->down->down->down->right->data == 'X')
        {
            if( row6->down->down->down->down->right->right->data == 'X')
            {
                if( row6->down->down->down->down->right->right->right->data == 'X')
                {
                    if( row6->down->down->down->down->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->data == 'X')
        {
            if( row6->down->down->down->down->right->right->right->data == 'X')
            {
                if( row6->down->down->down->down->right->right->right->right->data == 'X')
                {
                    if( row6->down->down->down->down->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->data == 'X')
        {
            if( row6->down->down->down->down->right->right->right->right->data == 'X')
            {
                if( row6->down->down->down->down->right->right->right->right->right->data == 'X')
                {
                    if( row6->down->down->down->down->right->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }





        //Vertical C
        if(row6->down->down->down->down->down->right->right->data == 'X')
        {
            if( row6->down->down->down->down->right->right->data == 'X')
            {
                if( row6->down->down->down->right->right->data == 'X')
                {
                    if( row6->down->down->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->data == 'X')
        {
            if( row6->down->down->down->right->right->data == 'X')
            {
                if( row6->down->down->right->right->data == 'X')
                {
                    if( row6->down->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->data == 'X')
        {
            if( row6->down->down->right->right->data == 'X')
            {
                if( row6->down->right->right->data == 'X')
                {
                    if( row6->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        // Horizontal 3
        if(row6->down->down->down->right->data == 'X')
        {
            if( row6->down->down->down->right->right->data == 'X')
            {
                if( row6->down->down->down->right->right->right->data == 'X')
                {
                    if( row6->down->down->down->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->data == 'X')
        {
            if( row6->down->down->down->right->right->right->data == 'X')
            {
                if( row6->down->down->down->right->right->right->right->data == 'X')
                {
                    if( row6->down->down->down->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->data == 'X')
        {
            if( row6->down->down->down->right->right->right->right->data == 'X')
            {
                if( row6->down->down->down->right->right->right->right->right->data == 'X')
                {
                    if( row6->down->down->down->right->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }


        //Vertical D
        if(row6->down->down->down->down->down->right->right->right->data == 'X')
        {
            if( row6->down->down->down->down->right->right->right->data == 'X')
            {
                if( row6->down->down->down->right->right->right->data == 'X')
                {
                    if( row6->down->down->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->data == 'X')
        {
            if( row6->down->down->down->right->right->right->data == 'X')
            {
                if( row6->down->down->right->right->right->data == 'X')
                {
                    if( row6->down->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->data == 'X')
        {
            if( row6->down->down->right->right->right->data == 'X')
            {
                if( row6->down->right->right->right->data == 'X')
                {
                    if( row6->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        // Horizontal 4
        if(row6->down->down->data == 'X')
        {
            if( row6->down->down->right->data == 'X')
            {
                if( row6->down->down->right->right->data == 'X')
                {
                    if( row6->down->down->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->right->data == 'X')
        {
            if( row6->down->down->right->right->data == 'X')
            {
                if( row6->down->down->right->right->right->data == 'X')
                {
                    if( row6->down->down->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->right->right->data == 'X')
        {
            if( row6->down->down->right->right->right->data == 'X')
            {
                if( row6->down->down->right->right->right->right->data == 'X')
                {
                    if( row6->down->down->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->right->right->right->data == 'X')
        {
            if( row6->down->down->right->right->right->right->data == 'X')
            {
                if( row6->down->down->right->right->right->right->right->data == 'X')
                {
                    if( row6->down->down->right->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }


        //Vertical E
        if(row6->down->down->down->down->down->right->right->right->right->data == 'X')
        {
            if( row6->down->down->down->down->right->right->right->right->data == 'X')
            {
                if( row6->down->down->down->right->right->right->right->data == 'X')
                {
                    if( row6->down->down->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->right->data == 'X')
        {
            if( row6->down->down->down->right->right->right->right->data == 'X')
            {
                if( row6->down->down->right->right->right->right->data == 'X')
                {
                    if( row6->down->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->right->data == 'X')
        {
            if( row6->down->down->right->right->right->right->data == 'X')
            {
                if( row6->down->right->right->right->right->data == 'X')
                {
                    if( row6->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        // Horizontal 5
        if(row6->down->data == 'X')
        {
            if( row6->down->right->data == 'X')
            {
                if( row6->down->right->right->data == 'X')
                {
                    if( row6->down->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->right->data == 'X')
        {
            if( row6->down->right->right->data == 'X')
            {
                if( row6->down->right->right->right->data == 'X')
                {
                    if( row6->down->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->right->right->data == 'X')
        {
            if( row6->down->right->right->right->data == 'X')
            {
                if( row6->down->right->right->right->right->data == 'X')
                {
                    if( row6->down->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->right->right->right->data == 'X')
        {
            if( row6->down->right->right->right->right->data == 'X')
            {
                if( row6->down->right->right->right->right->right->data == 'X')
                {
                    if( row6->down->right->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }


        //Vertical F
        if(row6->down->down->down->down->down->right->right->right->right->right->data == 'X')
        {
            if( row6->down->down->down->down->right->right->right->right->right->data == 'X')
            {
                if( row6->down->down->down->right->right->right->right->right->data == 'X')
                {
                    if( row6->down->down->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->right->right->data == 'X')
        {
            if( row6->down->down->down->right->right->right->right->right->data == 'X')
            {
                if( row6->down->down->right->right->right->right->right->data == 'X')
                {
                    if( row6->down->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->right->right->data == 'X')
        {
            if( row6->down->down->right->right->right->right->right->data == 'X')
            {
                if( row6->down->right->right->right->right->right->data == 'X')
                {
                    if( row6->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        // Horizontal 6
        if(row6->data == 'X')
        {
            if( row6->right->data == 'X')
            {
                if( row6->right->right->data == 'X')
                {
                    if( row6->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->right->data == 'X')
        {
            if( row6->right->right->data == 'X')
            {
                if( row6->right->right->right->data == 'X')
                {
                    if( row6->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->right->right->data == 'X')
        {
            if( row6->right->right->right->data == 'X')
            {
                if( row6->right->right->right->right->data == 'X')
                {
                    if( row6->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->right->right->right->data == 'X')
        {
            if( row6->right->right->right->right->data == 'X')
            {
                if( row6->right->right->right->right->right->data == 'X')
                {
                    if( row6->right->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }


        //Vertical G
        if(row6->down->down->down->down->down->right->right->right->right->right->right->data == 'X')
        {
            if( row6->down->down->down->down->right->right->right->right->right->right->data == 'X')
            {
                if( row6->down->down->down->right->right->right->right->right->right->data == 'X')
                {
                    if( row6->down->down->right->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->right->right->right->data == 'X')
        {
            if( row6->down->down->down->right->right->right->right->right->right->data == 'X')
            {
                if( row6->down->down->right->right->right->right->right->right->data == 'X')
                {
                    if( row6->down->right->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->right->right->right->data == 'X')
        {
            if( row6->down->down->right->right->right->right->right->right->data == 'X')
            {
                if( row6->down->right->right->right->right->right->right->data == 'X')
                {
                    if( row6->right->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }


        // Diagonal Forward
        if(row6->down->down->down->down->down->right->right->right->data == 'X')
        {
            if( row6->down->down->down->down->right->right->right->right->data == 'X')
            {
                if( row6->down->down->down->right->right->right->right->right->data == 'X')
                {
                    if( row6->down->down->right->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->down->right->right->data == 'X')
        {
            if( row6->down->down->down->down->right->right->right->data == 'X')
            {
                if( row6->down->down->down->right->right->right->right->data == 'X')
                {
                    if( row6->down->down->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->data == 'X')
        {
            if( row6->down->down->down->right->right->right->right->data == 'X')
            {
                if( row6->down->down->right->right->right->right->right->data == 'X')
                {
                    if( row6->down->right->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->down->right->right->data == 'X')
        {
            if( row6->down->down->down->down->right->right->right->data == 'X')
            {
                if( row6->down->down->down->right->right->right->right->data == 'X')
                {
                    if( row6->down->down->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->data == 'X')
        {
            if( row6->down->down->down->right->right->right->data == 'X')
            {
                if( row6->down->down->right->right->right->right->data == 'X')
                {
                    if( row6->down->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->data == 'X')
        {
            if( row6->down->down->right->right->right->right->data == 'X')
            {
                if( row6->down->right->right->right->right->right->data == 'X')
                {
                    if( row6->right->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        //
        if(row6->down->down->down->down->down->right->data == 'X')
        {
            if( row6->down->down->down->down->right->right->data == 'X')
            {
                if( row6->down->down->down->right->right->right->data == 'X')
                {
                    if( row6->down->down->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->data == 'X')
        {
            if( row6->down->down->down->right->right->data == 'X')
            {
                if( row6->down->down->right->right->right->data == 'X')
                {
                    if( row6->down->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->data == 'X')
        {
            if( row6->down->down->right->right->right->data == 'X')
            {
                if( row6->down->right->right->right->right->data == 'X')
                {
                    if( row6->right->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        ///

        if(row6->down->down->down->down->data == 'X')
        {
            if( row6->down->down->down->right->data == 'X')
            {
                if( row6->down->down->right->right->data == 'X')
                {
                    if( row6->down->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->data == 'X')
        {
            if( row6->down->down->right->right->data == 'X')
            {
                if( row6->down->right->right->right->data == 'X')
                {
                    if( row6->right->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        ////
        if(row6->down->down->down->data == 'X')
        {
            if( row6->down->down->right->data == 'X')
            {
                if( row6->down->right->right->data == 'X')
                {
                    if( row6->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        // Backward Diagonal

        if(row6->down->down->down->down->down->right->right->right->right->right->right->data == 'X')
        {
            if( row6->down->down->down->down->right->right->right->right->right->data == 'X')
            {
                if( row6->down->down->down->right->right->right->right->data == 'X')
                {
                    if( row6->down->down->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->right->right->data == 'X')
        {
            if( row6->down->down->down->right->right->right->right->data == 'X')
            {
                if( row6->down->down->right->right->right->data == 'X')
                {
                    if( row6->down->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->right->data == 'X')
        {
            if( row6->down->down->right->right->right->data == 'X')
            {
                if( row6->down->right->right->data == 'X')
                {
                    if( row6->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        //
        if(row6->down->down->down->down->down->right->right->right->right->right->data == 'X')
        {
            if( row6->down->down->down->down->right->right->right->right->data == 'X')
            {
                if( row6->down->down->down->right->right->right->data == 'X')
                {
                    if( row6->down->down->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->right->data == 'X')
        {
            if( row6->down->down->down->right->right->right->data == 'X')
            {
                if( row6->down->down->right->right->data == 'X')
                {
                    if( row6->down->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->data == 'X')
        {
            if( row6->down->down->right->right->data == 'X')
            {
                if( row6->down->right->data == 'X')
                {
                    if( row6->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        ///
        if(row6->down->down->down->down->down->right->right->right->right->data == 'X')
        {
            if( row6->down->down->down->down->right->right->right->data == 'X')
            {
                if( row6->down->down->down->right->right->data == 'X')
                {
                    if( row6->down->down->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->data == 'X')
        {
            if( row6->down->down->down->right->right->data == 'X')
            {
                if( row6->down->down->right->data == 'X')
                {
                    if( row6->down->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->right->right->right->data == 'X')
        {
            if( row6->down->down->down->right->right->right->right->right->data == 'X')
            {
                if( row6->down->down->right->right->right->right->data == 'X')
                {
                    if( row6->down->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->right->right->data == 'X')
        {
            if( row6->down->down->right->right->right->right->data == 'X')
            {
                if( row6->down->right->right->right->data == 'X')
                {
                    if( row6->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->down->right->right->right->data == 'X')
        {
            if( row6->down->down->down->down->right->right->data == 'X')
            {
                if( row6->down->down->down->right->data == 'X')
                {
                    if( row6->down->down->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->right->right->right->data == 'X')
        {
            if( row6->down->down->right->right->right->right->right->data == 'X')
            {
                if( row6->down->right->right->right->right->data == 'X')
                {
                    if( row6->right->right->right->data == 'X')
                    {
                        printf("\nPlayer One Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }



        // AI Win
        // Here we will check and see if the AI has connected four discs
        //Vertical
        if(row6->down->down->down->down->down->data == 'O')
        {
            if( row6->down->down->down->down->data == 'O')
            {
                if( row6->down->down->down->data == 'O')
                {
                    if( row6->down->down->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }

            //Horizontal
            if(row6->down->down->down->down->down->right->data == 'O')
            {
                if(row6->down->down->down->down->down->right->right->data == 'O')
                {
                    if(row6->down->down->down->down->down->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->data == 'O')
        {
            if( row6->down->down->down->data == 'O')
            {
                if( row6->down->down->data == 'O')
                {
                    if( row6->down->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }

            // Horizontal
            if( row6->down->down->down->down->right->data == 'O')
            {
                if( row6->down->down->down->down->right->right->data == 'O')
                {
                    if( row6->down->down->down->down->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->data == 'O')
        {
            if( row6->down->down->data == 'O')
            {
                if( row6->down->data == 'O')
                {
                    if( row6->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
            if( row6->down->down->down->right->data == 'O')
            {
                if( row6->down->down->down->right->right->data == 'O')
                {
                    if( row6->down->down->down->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        // Horizontal
        if(row6->down->down->down->down->down->right->data == 'O')
        {
            if( row6->down->down->down->down->down->right->right->data == 'O')
            {
                if( row6->down->down->down->down->down->right->right->right->data == 'O')
                {
                    if( row6->down->down->down->down->down->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->down->right->right->data == 'O')
        {
            if( row6->down->down->down->down->down->right->right->right->data == 'O')
            {
                if( row6->down->down->down->down->down->right->right->right->right->data == 'O')
                {
                    if( row6->down->down->down->down->down->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->down->right->right->right->data == 'O')
        {
            if( row6->down->down->down->down->down->right->right->right->right->data == 'O')
            {
                if( row6->down->down->down->down->down->right->right->right->right->right->data == 'O')
                {
                    if( row6->down->down->down->down->down->right->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }





        //Vertical B
        if(row6->down->down->down->down->down->right->data == 'O')
        {
            if( row6->down->down->down->down->right->data == 'O')
            {
                if( row6->down->down->down->right->data == 'O')
                {
                    if( row6->down->down->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->data == 'O')
        {
            if( row6->down->down->down->right->data == 'O')
            {
                if( row6->down->down->right->data == 'O')
                {
                    if( row6->down->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->data == 'O')
        {
            if( row6->down->down->right->data == 'O')
            {
                if( row6->down->right->data == 'O')
                {
                    if( row6->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        // Horizontal
        if(row6->down->down->down->down->right->data == 'O')
        {
            if( row6->down->down->down->down->right->right->data == 'O')
            {
                if( row6->down->down->down->down->right->right->right->data == 'O')
                {
                    if( row6->down->down->down->down->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->data == 'O')
        {
            if( row6->down->down->down->down->right->right->right->data == 'O')
            {
                if( row6->down->down->down->down->right->right->right->right->data == 'O')
                {
                    if( row6->down->down->down->down->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->data == 'O')
        {
            if( row6->down->down->down->down->right->right->right->right->data == 'O')
            {
                if( row6->down->down->down->down->right->right->right->right->right->data == 'O')
                {
                    if( row6->down->down->down->down->right->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }


        //Vertical C
        if(row6->down->down->down->down->down->right->right->data == 'O')
        {
            if( row6->down->down->down->down->right->right->data == 'O')
            {
                if( row6->down->down->down->right->right->data == 'O')
                {
                    if( row6->down->down->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->data == 'O')
        {
            if( row6->down->down->down->right->right->data == 'O')
            {
                if( row6->down->down->right->right->data == 'O')
                {
                    if( row6->down->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->data == 'O')
        {
            if( row6->down->down->right->right->data == 'O')
            {
                if( row6->down->right->right->data == 'O')
                {
                    if( row6->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        // Horizontal 3
        if(row6->down->down->down->right->data == 'O')
        {
            if( row6->down->down->down->right->right->data == 'O')
            {
                if( row6->down->down->down->right->right->right->data == 'O')
                {
                    if( row6->down->down->down->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->data == 'O')
        {
            if( row6->down->down->down->right->right->right->data == 'O')
            {
                if( row6->down->down->down->right->right->right->right->data == 'O')
                {
                    if( row6->down->down->down->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->data == 'O')
        {
            if( row6->down->down->down->right->right->right->right->data == 'O')
            {
                if( row6->down->down->down->right->right->right->right->right->data == 'O')
                {
                    if( row6->down->down->down->right->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }


        //Vertical D
        if(row6->down->down->down->down->down->right->right->right->data == 'O')
        {
            if( row6->down->down->down->down->right->right->right->data == 'O')
            {
                if( row6->down->down->down->right->right->right->data == 'O')
                {
                    if( row6->down->down->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->data == 'O')
        {
            if( row6->down->down->down->right->right->right->data == 'O')
            {
                if( row6->down->down->right->right->right->data == 'O')
                {
                    if( row6->down->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->data == 'O')
        {
            if( row6->down->down->right->right->right->data == 'O')
            {
                if( row6->down->right->right->right->data == 'O')
                {
                    if( row6->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        // Horizontal 4
        if(row6->down->down->data == 'O')
        {
            if( row6->down->down->right->data == 'O')
            {
                if( row6->down->down->right->right->data == 'O')
                {
                    if( row6->down->down->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->right->data == 'O')
        {
            if( row6->down->down->right->right->data == 'O')
            {
                if( row6->down->down->right->right->right->data == 'O')
                {
                    if( row6->down->down->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->right->right->data == 'O')
        {
            if( row6->down->down->right->right->right->data == 'O')
            {
                if( row6->down->down->right->right->right->right->data == 'O')
                {
                    if( row6->down->down->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->right->right->right->data == 'O')
        {
            if( row6->down->down->right->right->right->right->data == 'O')
            {
                if( row6->down->down->right->right->right->right->right->data == 'O')
                {
                    if( row6->down->down->right->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }


        //Vertical E
        if(row6->down->down->down->down->down->right->right->right->right->data == 'O')
        {
            if( row6->down->down->down->down->right->right->right->right->data == 'O')
            {
                if( row6->down->down->down->right->right->right->right->data == 'O')
                {
                    if( row6->down->down->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->right->data == 'O')
        {
            if( row6->down->down->down->right->right->right->right->data == 'O')
            {
                if( row6->down->down->right->right->right->right->data == 'O')
                {
                    if( row6->down->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->right->data == 'O')
        {
            if( row6->down->down->right->right->right->right->data == 'O')
            {
                if( row6->down->right->right->right->right->data == 'O')
                {
                    if( row6->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        // Horizontal 5
        if(row6->down->data == 'O')
        {
            if( row6->down->right->data == 'O')
            {
                if( row6->down->right->right->data == 'O')
                {
                    if( row6->down->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->right->data == 'O')
        {
            if( row6->down->right->right->data == 'O')
            {
                if( row6->down->right->right->right->data == 'O')
                {
                    if( row6->down->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->right->right->data == 'O')
        {
            if( row6->down->right->right->right->data == 'O')
            {
                if( row6->down->right->right->right->right->data == 'O')
                {
                    if( row6->down->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->right->right->right->data == 'O')
        {
            if( row6->down->right->right->right->right->data == 'O')
            {
                if( row6->down->right->right->right->right->right->data == 'O')
                {
                    if( row6->down->right->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }


        //Vertical F
        if(row6->down->down->down->down->down->right->right->right->right->right->data == 'O')
        {
            if( row6->down->down->down->down->right->right->right->right->right->data == 'O')
            {
                if( row6->down->down->down->right->right->right->right->right->data == 'O')
                {
                    if( row6->down->down->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->right->right->data == 'O')
        {
            if( row6->down->down->down->right->right->right->right->right->data == 'O')
            {
                if( row6->down->down->right->right->right->right->right->data == 'O')
                {
                    if( row6->down->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->right->right->data == 'O')
        {
            if( row6->down->down->right->right->right->right->right->data == 'O')
            {
                if( row6->down->right->right->right->right->right->data == 'O')
                {
                    if( row6->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        // Horizontal 6
        if(row6->data == 'O')
        {
            if( row6->right->data == 'O')
            {
                if( row6->right->right->data == 'O')
                {
                    if( row6->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->right->data == 'O')
        {
            if( row6->right->right->data == 'O')
            {
                if( row6->right->right->right->data == 'O')
                {
                    if( row6->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->right->right->data == 'O')
        {
            if( row6->right->right->right->data == 'O')
            {
                if( row6->right->right->right->right->data == 'O')
                {
                    if( row6->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->right->right->right->data == 'O')
        {
            if( row6->right->right->right->right->data == 'O')
            {
                if( row6->right->right->right->right->right->data == 'O')
                {
                    if( row6->right->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }


        //Vertical G
        if(row6->down->down->down->down->down->right->right->right->right->right->right->data == 'O')
        {
            if( row6->down->down->down->down->right->right->right->right->right->right->data == 'O')
            {
                if( row6->down->down->down->right->right->right->right->right->right->data == 'O')
                {
                    if( row6->down->down->right->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->right->right->right->data == 'O')
        {
            if( row6->down->down->down->right->right->right->right->right->right->data == 'O')
            {
                if( row6->down->down->right->right->right->right->right->right->data == 'O')
                {
                    if( row6->down->right->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->right->right->right->data == 'O')
        {
            if( row6->down->down->right->right->right->right->right->right->data == 'O')
            {
                if( row6->down->right->right->right->right->right->right->data == 'O')
                {
                    if( row6->right->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }


        // Diagonal Forward
        if(row6->down->down->down->down->down->right->right->right->data == 'O')
        {
            if( row6->down->down->down->down->right->right->right->right->data == 'O')
            {
                if( row6->down->down->down->right->right->right->right->right->data == 'O')
                {
                    if( row6->down->down->right->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->down->right->right->data == 'O')
        {
            if( row6->down->down->down->down->right->right->right->data == 'O')
            {
                if( row6->down->down->down->right->right->right->right->data == 'O')
                {
                    if( row6->down->down->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->data == 'O')
        {
            if( row6->down->down->down->right->right->right->right->data == 'O')
            {
                if( row6->down->down->right->right->right->right->right->data == 'O')
                {
                    if( row6->down->right->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->down->right->right->data == 'O')
        {
            if( row6->down->down->down->down->right->right->right->data == 'O')
            {
                if( row6->down->down->down->right->right->right->right->data == 'O')
                {
                    if( row6->down->down->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->data == 'O')
        {
            if( row6->down->down->down->right->right->right->data == 'O')
            {
                if( row6->down->down->right->right->right->right->data == 'O')
                {
                    if( row6->down->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->data == 'O')
        {
            if( row6->down->down->right->right->right->right->data == 'O')
            {
                if( row6->down->right->right->right->right->right->data == 'O')
                {
                    if( row6->right->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        //
        if(row6->down->down->down->down->down->right->data == 'O')
        {
            if( row6->down->down->down->down->right->right->data == 'O')
            {
                if( row6->down->down->down->right->right->right->data == 'O')
                {
                    if( row6->down->down->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->data == 'O')
        {
            if( row6->down->down->down->right->right->data == 'O')
            {
                if( row6->down->down->right->right->right->data == 'O')
                {
                    if( row6->down->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->data == 'O')
        {
            if( row6->down->down->right->right->right->data == 'O')
            {
                if( row6->down->right->right->right->right->data == 'O')
                {
                    if( row6->right->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        ///

        if(row6->down->down->down->down->data == 'O')
        {
            if( row6->down->down->down->right->data == 'O')
            {
                if( row6->down->down->right->right->data == 'O')
                {
                    if( row6->down->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->data == 'O')
        {
            if( row6->down->down->right->right->data == 'O')
            {
                if( row6->down->right->right->right->data == 'O')
                {
                    if( row6->right->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        ////
        if(row6->down->down->down->data == 'O')
        {
            if( row6->down->down->right->data == 'O')
            {
                if( row6->down->right->right->data == 'O')
                {
                    if( row6->right->right->right->data == 'O')
                    {
                        printf("\nAi Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        // Backward Diagonal

        if(row6->down->down->down->down->down->right->right->right->right->right->right->data == 'O')
        {
            if( row6->down->down->down->down->right->right->right->right->right->data == 'O')
            {
                if( row6->down->down->down->right->right->right->right->data == 'O')
                {
                    if( row6->down->down->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->right->right->data == 'O')
        {
            if( row6->down->down->down->right->right->right->right->data == 'O')
            {
                if( row6->down->down->right->right->right->data == 'O')
                {
                    if( row6->down->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->right->data == 'O')
        {
            if( row6->down->down->right->right->right->data == 'O')
            {
                if( row6->down->right->right->data == 'O')
                {
                    if( row6->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        //
        if(row6->down->down->down->down->down->right->right->right->right->right->data == 'O')
        {
            if( row6->down->down->down->down->right->right->right->right->data == 'O')
            {
                if( row6->down->down->down->right->right->right->data == 'O')
                {
                    if( row6->down->down->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->right->data == 'O')
        {
            if( row6->down->down->down->right->right->right->data == 'O')
            {
                if( row6->down->down->right->right->data == 'O')
                {
                    if( row6->down->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->data == 'O')
        {
            if( row6->down->down->right->right->data == 'O')
            {
                if( row6->down->right->data == 'O')
                {
                    if( row6->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        ///
        if(row6->down->down->down->down->down->right->right->right->right->data == 'O')
        {
            if( row6->down->down->down->down->right->right->right->data == 'O')
            {
                if( row6->down->down->down->right->right->data == 'O')
                {
                    if( row6->down->down->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->data == 'O')
        {
            if( row6->down->down->down->right->right->data == 'O')
            {
                if( row6->down->down->right->data == 'O')
                {
                    if( row6->down->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->right->right->right->right->right->right->data == 'O')
        {
            if( row6->down->down->down->right->right->right->right->right->data == 'O')
            {
                if( row6->down->down->right->right->right->right->data == 'O')
                {
                    if( row6->down->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->right->right->data == 'O')
        {
            if( row6->down->down->right->right->right->right->data == 'O')
            {
                if( row6->down->right->right->right->data == 'O')
                {
                    if( row6->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->down->down->right->right->right->data == 'O')
        {
            if( row6->down->down->down->down->right->right->data == 'O')
            {
                if( row6->down->down->down->right->data == 'O')
                {
                    if( row6->down->down->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }

        if(row6->down->down->down->right->right->right->right->right->right->data == 'O')
        {
            if( row6->down->down->right->right->right->right->right->data == 'O')
            {
                if( row6->down->right->right->right->right->data == 'O')
                {
                    if( row6->right->right->right->data == 'O')
                    {
                        printf("\nAI Wins!\n");
                        printf("\nGame Record");
                        printList(head);
                        return 0;
                    }
                }
            }
        }



    }

    // Print Game Record Moves
    printf("\nGame Record");
    printList(head);

    return 0;
}

void printList(struct Move *node)
{
    while (node != NULL)
    {
        printf(" %c ", node->data);
        node = node->next;
    }
}

void printGrid(struct Grid *node)
{
    while (node != NULL)
    {
        printf(" %c ", node->data);
        node = node->right;
    }
}
