#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "binary_sort_tree.h"

int main()
{
    int choice=0, val;
    BinarySortTreePtr T;

    do
    {
        menu();

        scanf("%d", &choice);
        system("cls");
        switch(choice)
        {
            case 1:
                if(BST_init(&T))
                {
                    printf("初始化成功\n\n");
                }
                else
                {
                    printf("初始化失败\n\n");
                }
                break;
            case 2:
                printf("请输入你想查询的数字:");
                scanf("%d", &val);
                if(BST_search(T, 2))
                {
                    printf("查找成功\n\n");
                }
                else{
                    printf("查找失败\n\n");
                }
                break;

            case 3:
                printf("请输入你想插入的数字:");
                scanf("%d", &val);
                if(BST_insert(&T, val))
                {
                    printf("插入成功\n\n");
                }
                else
                {
                    printf("插入失败\n\n");
                }
                break;

            case 4:
                printf("请输入你想删除的数字：");
                scanf("%d", &val);

                if(BST_delete(&T,val))
                {
                    printf("删除成功\n\n");
                }
                else
                {
                    printf("删除失败\n\n");
                }
                break;

            case 5:
                BST_preorderI(T,visit);//先序遍历
                printf("\n");
                break;

            case 6:
                BST_inorderI(T,visit);//中序遍历
                printf("\n");
                break;

            case 7:
                BST_postorderI(T,visit);//后序遍历
                printf("\n");
                break;

            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                BST_levelOrder(T, visit);
                break;
            case 12:

                break;

            default:
                printf("不要乱输入\n");
        }

    }while(choice!=12);

    return 0;
}
