#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "binary_sort_tree.h"

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr * T)//��ʼ����
{
    *T = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));

    (*T)->root = NULL;

    return 1;
}

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr * T, ElemType n)//����ڵ�
{
    NodePtr p = (NodePtr)malloc(sizeof(Node));
    if(BST_search(*T, n))
    {
        printf("�����Ѿ������������ �޷�����");
        return 0;
    }
    p->value = n;
    p->right = NULL;
    p->left = NULL;

    if(((*T)->root) == NULL)
    {
        (*T)->root = p;
        printf("%d", (*T)->root->value);
        return 1;
    }

    NodePtr q=(*T)->root ,parent;
    do{
        parent=q;

        if(parent->value>n)
            q=parent->left;
        else
            q=parent->right;
    }while(q!=NULL);

    if(parent->value>n)
        parent->left=p;
    else
        parent->right=p;


    return 1;
}

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr T, ElemType n)
{
    NodePtr p = BST_search1(T->root,n);
    if(p == NULL)
    {
        printf("���Ҳ���%d���Ԫ��\n");
        return 0;
    }
    else
    {
        printf("���ҵĵ�%d���Ԫ��");
        return 1;
    }
}

NodePtr BST_search1(NodePtr pTree,ElemType key)
{
	if(!pTree || pTree->value == key)	//���ҵ�ʱ���ص�pTreeΪ��Ԫ�ؽڵ㣬û���ҵ�ʱΪNULL
		return pTree;
	else if(key < pTree->value)			//���keyС�ڵ�ǰ�ڵ��ֵ���������������еݹ����
		return BST_search1(pTree->left,key);
	else								//���key���ڵ�ǰ�ڵ��ֵ���������������еݹ����
		return BST_search1(pTree->right,key);
}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr * T, ElemType key)//ɾ���ڵ�
{
    DeleteBST(&(*T)->root, key);
}

Status DeleteBST(NodePtr *T,int key)
{
    if((*T) == NULL)
    {
        printf("���� �޷�ɾ��\n\n");
        return 0;
    }

    else
    {
        if(key == (*T)->value)
        {
            return BST_deleteNodes(T);//ִ��ɾ������
        }

        else if(key < (*T)->value)
        {
            return DeleteBST(&((*T)->left),key);
        }

        else
        {
            return DeleteBST(&((*T)->right),key);
        }
    }
}




Status BST_deleteNodes(NodePtr * T)//����ɾ���ڵ�
{

    NodePtr p = NULL,s = NULL;

    if((*T)->left == NULL)
    {
        p = (*T);
        (*T) = (*T)->right;
        free(p);
    }

    else if((*T)->right == NULL)
    {
        p = (*T);
        (*T) = (*T)->left;
        free(p);
    }

    else//������� ��b���ӽڵ���ҽڵ�����ұߴ�������ڵ�
    {
        p = (*T);
        s = (*T)->left;
        while(s->right != NULL)
        {
            p = s;
            s = s->right;
        }

       (*T)->value = s->value;

        if(p!=(*T))//������һ�β�̫�� Ϊʲôp�п��ܲ�����*Tګ

        {
            p->right = s->left;
        }
        else
        {
            p->left = s->left;
        }

        free(s);

    }
    return 1;
}


void visit(NodePtr P)
{
    printf("%d\t", P->value);
}

Status BST_preorderI(BinarySortTreePtr T, void (*visit)(NodePtr))//���ݹ���������
{
    BST_preorderI_1(T->root,visit);

    return 1;
}

Status BST_preorderI_1(NodePtr T, void (*visit)(NodePtr))
{
    if(T!=NULL)
    {
        visit(T);
        BST_preorderI_1(T->left,visit);
        BST_preorderI_1(T->right,visit);
    }
}

Status BST_inorderI(BinarySortTreePtr T, void (*visit)(NodePtr))
{
    BST_inorderI_1(T->root,visit);

    return 1;
}
Status BST_inorderI_1(NodePtr T, void (*visit)(NodePtr))
{
    if(T!=NULL)
    {

        BST_inorderI_1(T->left,visit);
        visit(T);
        BST_inorderI_1(T->right,visit);
    }
}

Status BST_postorderI(BinarySortTreePtr T, void (*visit)(NodePtr))
{
    BST_postorderI_1(T->root,visit);

    return 1;
}

Status BST_postorderI_1(NodePtr T, void (*visit)(NodePtr))
{
    if(T!=NULL)
    {
        BST_postorderI_1(T->left,visit);
        BST_postorderI_1(T->right,visit);
        visit(T);
    }
}


/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */

void menu(void)
{
    printf("************************************\b");
    printf("����������Ҫ�Ĳ���:\n");
    printf("1.��ʼ�����������ʼ�������ܣ�\n");
    printf("2.��������\n");
    printf("3.��������\n");
    printf("4.ɾ������\n");
    printf("5.�ݹ�ǰ�����\n");
    printf("6.�ݹ��������\n");
    printf("7.�ݹ�������\n");
    printf("8.����ǰ�����\n");
    printf("9.�����������\n");
    printf("10.������������\n");
    printf("11.�������\n");
    printf("12.�˳�����\n");
    printf("************************************\n");
    printf("��������Ĳ���:");
    printf("\n\n");
}

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr T, void (*visit)(NodePtr))
{
    levelorder(T->root,visit);
    return 1;
}

void levelorder(NodePtr bt, void (*visit)(NodePtr))
{
    NodePtr q[100];

    ElemType front = 0, rear = 0;
    NodePtr p;
    if(bt == NULL)
        return;

    q[rear] = bt;//q[0]һ��ʼ������Ϊ����
    rear = (rear + 1) % 100;
    while(front!=rear)
    {
        p = q[front];
        front = (front + 1) % 100;
        visit(p);
        if(p->left != NULL)
        {
            q[rear]=p->left;
            rear = (rear + 1) % 100;
        }

        if(p->right != NULL)
        {
            q[rear]=p->right;
            rear=(rear+1)%100;
        }
    }
    printf("\n");
}
