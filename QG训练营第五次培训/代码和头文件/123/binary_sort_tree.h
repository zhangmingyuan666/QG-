#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
//
// Created by eke_l on 2021/4/21.
//

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int
//二叉排序树：左儿子的数小于节点 右儿子的数大于节点
typedef int ElemType;

typedef struct Node{
    ElemType value;
    struct Node *left, *right;
}Node, *NodePtr;

typedef struct BinarySortTree{
    NodePtr root;
} BinarySortTree, *BinarySortTreePtr;

typedef  struct  LinkStack
{
	NodePtr top;
	int	count;
}LinkStack;
/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr * T);//初始化树

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr * T, ElemType n);//插入节点

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr *, ElemType);//用于找到节点
Status BST_deleteNodes(NodePtr *);//用于删除节点
Status DeleteBST(NodePtr *T,int key);//用于递归
/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr, ElemType);//查找结点
NodePtr BST_search1(NodePtr pTree,int key);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr, void (*visit)(NodePtr));//带递归的先序遍历
Status BST_preorderI_1(NodePtr T, void (*visit)(NodePtr));
/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(BinarySortTreePtr, void (*visit)(NodePtr));//不带递归的先序遍历

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(BinarySortTreePtr, void (*visit)(NodePtr));//带有递归法的中序遍历
Status BST_inorderI_1(NodePtr T, void (*visit)(NodePtr));
/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(BinarySortTreePtr, void (*visit)(NodePtr));//不带有递归法的中序遍历

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(BinarySortTreePtr, void (*visit)(NodePtr));//带递归法的后序遍历

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(BinarySortTreePtr, void (*visit)(NodePtr));//不带递归法的后序遍历

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr, void (*visit)(NodePtr));
void levelorder(NodePtr bt, void (*visit)(NodePtr));
void visit(NodePtr);
void menu(void);
#endif //BINARYSORTTREE_BINARY_SORT_TREE_H
