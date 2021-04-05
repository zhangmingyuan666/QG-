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

Status isEmptyStack(SqStack *s)//�ж�ջ�Ƿ�Ϊ��
{
    if(s->top == -1)
        return SUCCESS;

    else
        return ERROR;

}


Status getTopStack(SqStack *s,ElemType *e) //�õ�ջ��Ԫ��
{
    *e = s->elem[s->top];
        return SUCCESS;
}

Status clearStack(SqStack *s)//���ջ
{
    s->top    = -1;
    return SUCCESS;
}

Status destroyStack(SqStack *s)//����ջ
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

Status stackLength(SqStack *s,int *length)//���ջ����
{
    if(isEmptyStack(s))
    {
        printf("ջ�գ�û�г���\n\n");
        return ERROR;
    }

    else
    {
        *length = s->top + 1;
        return SUCCESS;
    }
}

Status pushStack(SqStack *s,ElemType data)//��ջ
{
    if( s->top == s->size)
    {
        printf("ջ����������ʧ��\n\n");
        return ERROR;
    }

    s->top += 1;
    s->elem[s->top] = data;
    return SUCCESS;
}


Status popStack(SqStack *s,ElemType *data)//��ջ
{
    if( isEmptyStack(s) )
    {
        printf("ջ�Ѿ��ǿյ���,�޷�����\n\n");
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
    printf("����������Ҫ�Ĳ���:\n");
    printf("1.��ʼ��ջ\n");
    printf("2.�ж�ջ�Ƿ�Ϊ��\n");
    printf("3.�õ�ջ��Ԫ��\n");
    printf("4.���ջ\n");
    printf("5.����ջ\n");
    printf("6.���ջ�ĳ���\n");
    printf("7.��ջ\n");
    printf("8.��ջ\n");
    printf("9.�˳�\n");
    printf("************************************");
    printf("��������Ĳ���:");
    printf("\n\n");
}
