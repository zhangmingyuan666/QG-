#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "LinkStack.h"

Status initLStack(LinkStack *s)//初始化栈
{
    s->top = (LinkStackPtr)malloc(sizeof(StackNode));

    if( s->top == NULL)
    {
        printf("分配失败\n\n");
        exit(-1);
        return ERROR;
    }

    else
    {
        s->top->next = NULL;
        s->count = 0;
        return SUCCESS;
    }
}


Status isEmptyLStack(LinkStack *s)//判断栈是否为空
{
    if(s->count == 0)
    {
        printf("栈为空\n\n");
        return SUCCESS;
    }

    else
        return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e)//得到栈顶元素
{
    if(isEmptyLStack(s))
    {
        printf("无栈顶元素\n\n");
        return ERROR;
    }

    else
    {
        *e = s->top->data;
        return SUCCESS;
    }
}



Status clearLStack(LinkStack *s)//清空栈
{
    if(isEmptyLStack(s))
    {
        printf("无法清空\n\n");
        return ERROR;
    }

    else
    {
        LinkStackPtr p;

        while( s->top->next != NULL)
        {
            p=s->top;
            s->top = s->top->next;
            free(p);
            (s->count)--;
        }

        return SUCCESS;
    }

}


Status destroyLStack(LinkStack *s)//销毁栈
{
    clearLStack(s);

    s->count = -1;
    free(s->top);

    return SUCCESS;

}


Status LStackLength(LinkStack *s,int *length)//检测栈长度
{
    if( isEmptyLStack(s))
    {
        printf("栈空，长度为0\n\n");
        return ERROR;
    }

    else
    {
        *length = s->count;
        return SUCCESS;
    }
}

Status pushLStack(LinkStack *s,ElemType data)//入栈
{

    LinkStackPtr pNew = (LinkStackPtr)malloc(sizeof(StackNode));

    pNew->data = data;
    pNew->next = s->top;
    s->top = pNew;
    (s->count)++;
    return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)//出栈
{
    if( isEmptyLStack(s) )
    {
        printf("栈空，无法出栈\n\n");
        return ERROR;
    }

    else
    {
        LinkStackPtr p = s->top;
        *data = p->data;
        s->top = s->top->next;

        free(p);
        (s->count)--;
        return SUCCESS;
    }
}

void show(void)
{
    printf("************************************\b");
    printf("请输入你需要的操作:\n");
    printf("1.初始化栈\n");
    printf("2.判断栈是否为空\n");
    printf("3.得到栈顶元素\n");
    printf("4.清空栈\n");
    printf("5.销毁栈\n");
    printf("6.检测栈的长度\n");
    printf("7.入栈\n");
    printf("8.出栈\n");
    printf("9.退出\n");
    printf("************************************\n");
    printf("附：只要输入的第一个字符是数字就可以正常进行\n");
    printf("直到输入的字符为纯数字或者第一个字符为有效数字才可进行\n");
    printf("************************************\n");
    printf("请输入你的操作:");
    printf("\n\n");
}
