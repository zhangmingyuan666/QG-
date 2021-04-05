#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "LinkStack.h"
#include <windows.h>
int main()
{
    ElemType choice , data, d;
    LinkStack st;
    st.count = -1;

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
            if( initLStack(&st) )
                printf("��ʼ���ɹ�\n\n");

            else
                printf("��ʼ��ʧ��\n\n");

            break;

        case 2://�Ƿ�Ϊ��ջ
            if( st.count == -1)
            {
                printf("ջ�Ѳ�����\n\n");
            }

            else
            {
                if( isEmptyLStack(&st) )
                    printf("\n");

                else
                    printf("ջ��Ϊ��\n\n");
            }

            break;

        case 3://�õ�ջ��Ԫ��
            if( st.count == -1)
            {
                printf("ջ�Ѳ�����\n\n");
            }

            else
            {
                if( getTopLStack(&st, &data) )
                    printf("��ʱ��ջ��Ԫ����%d\n\n", data);

                else
                    printf("���ʧ��\n\n");
            }

            break;

        case 4://���ջ
             if( st.count == -1)
            {
                printf("ջ�Ѳ�����\n\n");
            }

            else
            {
                if( clearLStack(&st) )
                    printf("ջ�Ѿ������\n\n");

                else
                    printf("���ʧ��\n\n");
            }

            break;

        case 5://��������
            if( st.count == -1)
            {
                printf("ջ�Ѳ�����\n\n");
            }

            else
            {
                if( destroyLStack(&st) )
                    printf("���ٳɹ�\n\n");

                else
                    printf("����ʧ��\n\n");
            }

            break;

        case 6://����ջ�ĳ���
            if( st.count == -1)
            {
                printf("ջ�Ѳ�����\n\n");
            }

            else
            {
                if( LStackLength(&st, &data))
                {
                    printf("ջ�ĳ���Ϊ%d", data);
                }

                else
                    printf("����ʧ��\n\n");
            }


            break;



        case 7://��ջ
            if( st.count == -1)
            {
                printf("ջ�Ѳ�����\n\n");
            }

            else
            {
                printf("������ջ��Ԫ����:");

                do//������֤�û��Ƿ��������
                {
                    d=scanf("%d",&data);
                    fflush(stdin);//��ֹ��������ʱ��sanf��ִ��

                    if(d==1)//�����ж���������ȷ��ʱ���Ƿ�Ҫ��ʾ
                    {
                        printf("");
                    }

                    else
                    {
                        printf("����������û���õ��ޣ�\n\n");
                        show();
                    }
                }while(d!=1);

                if( pushLStack(&st, data) )
                {
                    printf("��ջ�ɹ�\n\n");
                }
                else
                {
                    printf("��ջʧ��\n\n");
                }
            }
            break;

        case 8://��ջ
            if( st.count == -1)
            {
                printf("ջ�Ѳ�����\n\n");
            }



            else
            {
                if( popLStack(&st, &data) )
                {
                    printf("��ջ�ɹ�,��ջ��Ԫ���ǣ�%d\n\n", data);
                }
                else
                {
                    printf("��ջʧ��\n\n");
                }
            }
            break;

        case 9:
            break;

        default:
            printf("���ڸ�ʲô��������ʵ������Ҳ��������?\n\n");

            break;
        }
    }while(choice!=9);

    return 0;
}
