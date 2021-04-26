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
                    printf("��ʼ���ɹ�\n\n");
                }
                else
                {
                    printf("��ʼ��ʧ��\n\n");
                }
                break;
            case 2:
                printf("�����������ѯ������:");
                scanf("%d", &val);
                if(BST_search(T, 2))
                {
                    printf("���ҳɹ�\n\n");
                }
                else{
                    printf("����ʧ��\n\n");
                }
                break;

            case 3:
                printf("������������������:");
                scanf("%d", &val);
                if(BST_insert(&T, val))
                {
                    printf("����ɹ�\n\n");
                }
                else
                {
                    printf("����ʧ��\n\n");
                }
                break;

            case 4:
                printf("����������ɾ�������֣�");
                scanf("%d", &val);

                if(BST_delete(&T,val))
                {
                    printf("ɾ���ɹ�\n\n");
                }
                else
                {
                    printf("ɾ��ʧ��\n\n");
                }
                break;

            case 5:
                BST_preorderI(T,visit);//�������
                printf("\n");
                break;

            case 6:
                BST_inorderI(T,visit);//�������
                printf("\n");
                break;

            case 7:
                BST_postorderI(T,visit);//�������
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
                printf("��Ҫ������\n");
        }

    }while(choice!=12);

    return 0;
}
