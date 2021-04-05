#include "malloc.h"
#include "stdio.h"
#include "stdlib.h"
#include "SqStack.h"

Status initStack(SqStack *s,int sizes)
{
    s->elem = (int *)malloc(sizeof(int) * sizes);
    s->top = -1;
    s->size = sizes-1;
}

Status isEmptyStack(SqStack *s)//判断栈是否为空
{
    if(s->top == -1)
        return SUCCESS;

    else
        return ERROR;

}


Status getTopStack(SqStack *s,ElemType *e) //得到栈顶元素
{
    *e = s->elem[s->top];
        return SUCCESS;
}

Status clearStack(SqStack *s)//清空栈
{
    s->top    = -1;
    return SUCCESS;
}

Status destroyStack(SqStack *s)//销毁栈
{
    if(s->elem != NULL)
    {
        s->size = 0;
        free(s->elem);
        s->elem = NULL;
        s->top = -2;
        return SUCCESS;
    }
}

Status stackLength(SqStack *s,int *length)//检测栈长度
{
    if(isEmptyStack(s))
    {
        printf("栈空，没有长度\n\n");
        return ERROR;
    }

    else
    {
        *length = s->top + 1;
        return SUCCESS;
    }
}

Status pushStack(SqStack *s,ElemType data)//入栈
{
    if( s->top == s->size)
    {
        printf("栈已满，插入失败\n\n");
        return ERROR;
    }

    s->top += 1;
    s->elem[s->top] = data;
    return SUCCESS;
}


Status popStack(SqStack *s,ElemType *data)//出栈
{
    if( isEmptyStack(s) )
    {
        printf("栈已经是空的了,无法插入\n\n");
        return ERROR;
    }

    else
    {
        s->top -= 1;
        return SUCCESS;
    }
}

void show(void)
{
    printf("************************************");
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
    printf("************************************");
    printf("请输入你的操作:");
    printf("\n\n");
}
