#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

int main()
{
    SqStack st;
    int sizes, choice, data, val ,length, d;
    st.top = -2;
    do{
        show();

        do//������֤�û��Ƿ��������
        {
            d=scanf("%d",&choice);
            fflush(stdin);//��ֹ��������ʱ��sanf��ִ��
            if(d==1)
            {
                printf("");
            }

            else
            {
                printf("����������û���õ��ޣ�\n\n");
            }

        }while(d!=1);

        system("cls");

        switch(choice)
        {
        case 1://��ʼ��ջ
            printf("����������Ҫ��ջ�Ĵ�С:");
            scanf("%d", &sizes);
            if( initStack(&st, sizes) )
                printf("��ʼ���ɹ�\n\n");

            else
                printf("��ʼ��ʧ��\n\n");

            break;

        case 2://�Ƿ�Ϊ��ջ
            if( st.top == -2)
                printf("ջ������\n\n");

            else if( isEmptyStack(&st) )
                printf("�Ѿ��ǿյ���\n\n");

            else
                printf("�����ǿյ�\n\n");

            break;

        case 3:
            if( st.top == -2)
                printf("ջ�����ڣ�û��ջ��\n\n");

            else if( isEmptyStack(&st) )
                printf("�Ѿ��ǿյ���,û��ջ��\n\n");

            else
            {
                getTopStack(&st, &val);
                printf("ջ����Ԫ����%d\n\n", val);
            }

            break;

        case 4://���ջ
            if( st.top == -2)
                printf("ջ�����ڣ��޷����\n\n");

            else if( isEmptyStack(&st) )
                printf("ջ�գ��������\n\n");

            else
            {
                if( clearStack(&st))
                    printf("��ճɹ�\n\n");

                else
                    printf("���ʧ��\n\n");
            }

            break;

        case 5://��������
            if( st.top == -2)
                printf("ջ�����ڣ��޷�����\n\n");

            else
            {
                if( destroyStack(&st))
                    printf("���ٳɹ�\n\n");

                else
                    printf("����ʧ��\n\n");
            }

            break;

        case 6:
            if( st.top == -2)
                printf("ջ�����ڣ��޷���ѯ����\n\n");

            else if( isEmptyStack(&st) )
                printf("ջ�գ��޷���ѯ����\n\n");

            else
            {
                if( stackLength(&st, &length) )
                {
                    printf("ջ�ĳ����ǣ�%d\n\n", length);
                }

                else
                    printf("�޷���ѯ\n\n");
            }

            break;
        case 7://��ջ
            if( st.top == -2)
                printf("ջ�����ڣ��޷�����\n\n");

            else
            {
            printf("������������ջ��ֵ:");

            do//������֤�û��Ƿ��������
            {
            d=scanf("%d",&data);
            fflush(stdin);//��ֹ��������ʱ��sanf��ִ��
            if(d==1)
            {
                printf("");
            }

            else
            {
                printf("����������û���õ��ޣ�\n\n");
            }

            }while(d!=1);


                if( pushStack(&st, data) )
                    printf("��ջ�ɹ�\n\n");

                else
                    printf("��ջʧ��\n\n");
            }
            break;

        case 8://��ջ
            if( st.top == -2)
                printf("ջ�����ڣ��޷���ջ\n\n");

            else if( isEmptyStack(&st) )
                printf("ջ�գ��޷���ջ\n\n");

            else
            {
                if( popStack(&st, data) )
                    printf("��ջ�ɹ�,��ջ��Ԫ����%d\n\n", data);

                else
                    printf("��ջʧ��\n\n");
            }
            break;

        case 9:
            break;

        default:
            {
                 printf("���ڸ�ʲô��������ʵ������Ҳ��������?\n\n");
                break;
            }
        }

    }while(choice!=9);

    return 0;
}
