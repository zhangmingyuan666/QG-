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
            printf("请输入你需要的栈的大小:");
            scanf("%d", &sizes);
            if( initStack(&st, sizes) )
                printf("初始化成功\n\n");

            else
                printf("初始化失败\n\n");

            break;

        case 2://是否为空栈
            if( st.top == -2)
                printf("栈不存在\n\n");

            else if( isEmptyStack(&st) )
                printf("已经是空的了\n\n");

            else
                printf("并不是空的\n\n");

            break;

        case 3:
            if( st.top == -2)
                printf("栈不存在，没有栈顶\n\n");

            else if( isEmptyStack(&st) )
                printf("已经是空的了,没有栈顶\n\n");

            else
            {
                getTopStack(&st, &val);
                printf("栈顶的元素是%d\n\n", val);
            }

            break;

        case 4://清空栈
            if( st.top == -2)
                printf("栈不存在，无法清空\n\n");

            else if( isEmptyStack(&st) )
                printf("栈空，不用清空\n\n");

            else
            {
                if( clearStack(&st))
                    printf("清空成功\n\n");

                else
                    printf("清除失败\n\n");
            }

            break;

        case 5://销毁链表
            if( st.top == -2)
                printf("栈不存在，无法销毁\n\n");

            else
            {
                if( destroyStack(&st))
                    printf("销毁成功\n\n");

                else
                    printf("销毁失败\n\n");
            }

            break;

        case 6:
            if( st.top == -2)
                printf("栈不存在，无法查询长度\n\n");

            else if( isEmptyStack(&st) )
                printf("栈空，无法查询长度\n\n");

            else
            {
                if( stackLength(&st, &length) )
                {
                    printf("栈的长度是：%d\n\n", length);
                }

                else
                    printf("无法查询\n\n");
            }

            break;
        case 7://入栈
            if( st.top == -2)
                printf("栈不存在，无法插入\n\n");

            else
            {
            printf("请输入你想入栈的值:");

            do//用于验证用户是否胡乱输入
            {
            d=scanf("%d",&data);
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


                if( pushStack(&st, data) )
                    printf("入栈成功\n\n");

                else
                    printf("入栈失败\n\n");
            }
            break;

        case 8://出栈
            if( st.top == -2)
                printf("栈不存在，无法出栈\n\n");

            else if( isEmptyStack(&st) )
                printf("栈空，无法出栈\n\n");

            else
            {
                if( popStack(&st, data) )
                    printf("出栈成功,出栈的元素是%d\n\n", data);

                else
                    printf("出栈失败\n\n");
            }
            break;

        case 9:
            break;

        default:
            {
                 printf("你在干什么，你在现实生活里也是这样吗?\n\n");
                break;
            }
        }

    }while(choice!=9);

    return 0;
}
