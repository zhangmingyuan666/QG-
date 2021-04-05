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

        do//用于验证用户是否胡乱输入
        {
            d=scanf("%d",&choice);
            fflush(stdin);//防止错误输入时，sanf不执行
            if(d==1)
            {
                printf("");
            }

            else
            {
                printf("你乱输入是没有用的噢！\n\n");
            }

        }while(d!=1);

        system("cls");

        switch(choice)
        {
        case 1://初始化栈
            if( initLStack(&st) )
                printf("初始化成功\n\n");

            else
                printf("初始化失败\n\n");

            break;

        case 2://是否为空栈
            if( st.count == -1)
            {
                printf("栈堆不存在\n\n");
            }

            else
            {
                if( isEmptyLStack(&st) )
                    printf("\n");

                else
                    printf("栈不为空\n\n");
            }

            break;

        case 3://得到栈顶元素
            if( st.count == -1)
            {
                printf("栈堆不存在\n\n");
            }

            else
            {
                if( getTopLStack(&st, &data) )
                    printf("此时的栈顶元素是%d\n\n", data);

                else
                    printf("输出失败\n\n");
            }

            break;

        case 4://清空栈
             if( st.count == -1)
            {
                printf("栈堆不存在\n\n");
            }

            else
            {
                if( clearLStack(&st) )
                    printf("栈已经清空了\n\n");

                else
                    printf("清空失败\n\n");
            }

            break;

        case 5://销毁链表
            if( st.count == -1)
            {
                printf("栈堆不存在\n\n");
            }

            else
            {
                if( destroyLStack(&st) )
                    printf("销毁成功\n\n");

                else
                    printf("销毁失败\n\n");
            }

            break;

        case 6://计算栈的长度
            if( st.count == -1)
            {
                printf("栈堆不存在\n\n");
            }

            else
            {
                if( LStackLength(&st, &data))
                {
                    printf("栈的长度为%d", data);
                }

                else
                    printf("计算失败\n\n");
            }


            break;



        case 7://入栈
            if( st.count == -1)
            {
                printf("栈堆不存在\n\n");
            }

            else
            {
                printf("你想入栈的元素是:");

                do//用于验证用户是否胡乱输入
                {
                    d=scanf("%d",&data);
                    fflush(stdin);//防止错误输入时，sanf不执行

                    if(d==1)//用于判断在输入正确的时候是否要显示
                    {
                        printf("");
                    }

                    else
                    {
                        printf("你乱输入是没有用的噢！\n\n");
                        show();
                    }
                }while(d!=1);

                if( pushLStack(&st, data) )
                {
                    printf("入栈成功\n\n");
                }
                else
                {
                    printf("入栈失败\n\n");
                }
            }
            break;

        case 8://出栈
            if( st.count == -1)
            {
                printf("栈堆不存在\n\n");
            }



            else
            {
                if( popLStack(&st, &data) )
                {
                    printf("出栈成功,出栈的元素是：%d\n\n", data);
                }
                else
                {
                    printf("出栈失败\n\n");
                }
            }
            break;

        case 9:
            break;

        default:
            printf("你在干什么，你在现实生活里也是这样吗?\n\n");

            break;
        }
    }while(choice!=9);

    return 0;
}
