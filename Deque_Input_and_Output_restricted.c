#include <stdio.h>
#include <stdlib.h>

void dummy()
{
    //dummy changes for learning of github desktop
}

void comment()
{
    //This is create to learn branching in git
}
void comment2()
{
    //This Function I made to learn branching in github , I made second branch name comment2
}


void betaTag()
{
    // Learning beta tag in github
}

void UndoCommit()
{
    //Learning git commit --ammend
}

struct node
{
    struct node *prev;
    int info;
    struct node *next;
};
static int item, option;
struct node *left = NULL;
struct node *right = NULL;
void inputdeque(void);
void outputdeque(void);
void insertright();
void insertleft();
//void deleteright();
// void deleteleft();
void displaydeque();

int main()
{
    int x;
    char ch;
    do
    {
        printf("\n***--------MENU--------***\n");
        printf("Press 1.For Input Restricted Dequeue:\n");
        printf("Press 2.For Output Restricted Dequeue:\n");
        printf("Enter Your Choice:\n");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            inputdeque();
            break;
        case 2:
            outputdeque();
            break;
        }
    } while (x <= 2);
}
void inputdeque()
{
    do
    {
        printf("* Input Restricted Dequeue *\n");
        printf("1.To Insert At Right\n");
        printf("2.To Delete From Left\n");
        printf("3.To Delete From Right\n");
        printf("4.To Dispaly Input restricted\n");
        printf("5.To Quit\n");
        printf("Enter Your Choice\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insertright();
            break;
            /*case 2:
                deleteleft();
                break;
            case 3:
                deleteright();
                break;*/
        case 4:
            displaydeque();
            break;
        }
    } while (option <= 4);
}

void outputdeque()
{
    do
    {
        printf("* Output Restricted Dequeue Operation*\n");
        printf("1.To Insert At Right\n");
        printf("2.To Insert At Left\n");
        printf("3.To Delete From Left\n");
        printf("4.To Display\n");
        printf("5.To Quit\n");
        printf("Enter Your Choice\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insertright();
            break;
        case 2:
            insertleft();
            break;
            /*case 3:
                deleteleft();
                break;*/
        case 4:
            displaydeque();
            break;
        }
    } while (option <= 4);
}
void insertleft()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Overflow\n");
        exit(0);
    }
    else
    {
        printf("Enter item you want to insert\n");
        scanf("%d", &item);
        newnode->info = item;
        if (left == NULL && right == NULL)
        {
            right = newnode;
            left = newnode;
            newnode->next = right;
            newnode->prev = right;
        }
        else
        {
            newnode->prev = left;
            newnode->next = right;
            right->prev = newnode;
            left->next = newnode;
            left = newnode;
        }
    }
}

void insertright()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Overflow\n");
        exit(0);
    }
    
    
    printf("Enter item you want to insert\n");
    scanf("%d", &item);
    newnode->info = item;
    if (right == NULL && left == NULL)
    {
        right = newnode;
        left = newnode;
        newnode->next = right;
        newnode->prev = left;
    }
    else
    {
        newnode->next= left;
        newnode->prev= right;
        right->next = newnode;
        left->prev = newnode;
        right = newnode;
    }
    
}

void displaydeque()
{
    struct node *temp;
    if (left == NULL && right == NULL)
    {
        printf("Underflow\n");
        exit(0);
    }
    
    printf("Item = %d\n", left->info);
    temp = left->next;

    while (temp != left)
    {
        printf("Item = %d\n", temp->info);
        temp = temp->next;
    }
    
}
