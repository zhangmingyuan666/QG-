#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "LinkStack.h"

Status initLStack(LinkStack *s)//��ʼ��ջ
{
    s->top = (LinkStackPtr)malloc(sizeof(StackNode));

    if( s->top == NULL)
    {
        printf("����ʧ��\n\n");
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


Status isEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ��
{
    if(s->count == 0)
    {
        printf("ջΪ��\n\n");
        return SUCCESS;
    }

    else
        return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e)//�õ�ջ��Ԫ��
{
    if(isEmptyLStack(s))
    {
        printf("��ջ��Ԫ��\n\n");
        return ERROR;
    }

    else
    {
        *e = s->top->data;
        return SUCCESS;
    }
}



Status clearLStack(LinkStack *s)//���ջ
{
    if(isEmptyLStack(s))
    {
        printf("�޷����\n\n");
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


Status destroyLStack(LinkStack *s)//����ջ
{
    clearLStack(s);

    s->count = -1;
    free(s->top);

    return SUCCESS;

}


Status LStackLength(LinkStack *s,int *length)//���ջ����
{
    if( isEmptyLStack(s))
    {
        printf("ջ�գ�����Ϊ0\n\n");
        return ERROR;
    }

    else
    {
        *length = s->count;
        return SUCCESS;
    }
}

Status pushLStack(LinkStack *s,ElemType data)//��ջ
{

    LinkStackPtr pNew = (LinkStackPtr)malloc(sizeof(StackNode));

    pNew->data = data;
    pNew->next = s->top;
    s->top = pNew;
    (s->count)++;
    return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)//��ջ
{
    if( isEmptyLStack(s) )
    {
        printf("ջ�գ��޷���ջ\n\n");
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
    printf("************************************\n");
    printf("����ֻҪ����ĵ�һ���ַ������־Ϳ�����������\n");
    printf("ֱ��������ַ�Ϊ�����ֻ��ߵ�һ���ַ�Ϊ��Ч���ֲſɽ���\n");
    printf("************************************\n");
    printf("��������Ĳ���:");
    printf("\n\n");
}
