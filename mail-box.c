#include<stdio.h>
#include<stdlib.h>

#define stacksize 5

struct mail
{
    char sender[50];
    char subject[50];
    char date[10];
    char body[500];
};

struct stack
{
    struct mail s[stacksize];
    int top;
};

void readmail(struct mail *p)
{
    scanf("%s%s%s%s",p->sender,p->subject,p->date,p->body);
}

void displaydetailedmail(struct mail p)
{
    printf("Sender : %s\nSubject : %s\nDate : %s\nBody : %s\n",p.sender,p.subject,p.date,p.body);
}

void displaymail(struct mail p)
{
    printf("Sender : %s Subject : %s Date : %s\n",p.sender,p.subject,p.date);
}

void push(struct stack *stk,struct mail data)
{
    stk->top=stk->top+1;
    stk->s[stk->top]=data;
}

int isfull(struct stack stk)
{
    if(stk.top==stacksize-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty(struct stack stk)
{
    if(stk.top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct mail stacktop(struct stack stk)
{
    struct mail data;
    data=stk.s[stk.top];
    return data;
};

struct mail pop(struct stack *stk)
{
    struct mail data;
    data=stk->s[stk->top];
    stk->top=stk->top-1;
    return data;
};

int main()
{
    struct mail data;
    int ch;
    struct stack stk;
    stk.top= -1;
    do
    {
        printf("Enter choicr 1-push,2-pop,3-stacktop,4-displaystack,5-exit\n");
        scanf("%d",&ch);
        if(ch!=1&&ch!=2&&ch!=3&&ch!=4&&ch!=5)
        {
            printf("Invalid choice\n");
        }
        else
        {
            switch(ch)
            {
                case 1:if(isfull(stk))
                {
                    printf("Stack overflow\n");
                }
                else
                {
                    printf("Enter mail\n");
                    readmail(&data);
                    push(&stk,data);
                }
                break;
                case 2:if(isempty(stk))
                {
                    printf("Stack underflow\n");
                }
                else
                {
                    data=pop(&stk);
                    displaymail(data);
                }
                break;
                case 3:if(isempty(stk))
                {
                    printf("Stack underflow\n");
                }
                else
                {
                    data=stacktop(stk);
                    displaymail(data);
                }
                break;
                case 4:if(isempty(stk))
                {
                    printf("Stack underflow\n");
                }
                else
                {
                    for(int i=stk.top;i>=0;i--)
                    {
                        displaydetailedmail(stk.s[i]);
                        printf("\n");
                    }
                }
                break;
                case 5:break;
                default:printf("Invalid choice\n");
            }
        }
    }while(ch!=5);
    return 0;
}
