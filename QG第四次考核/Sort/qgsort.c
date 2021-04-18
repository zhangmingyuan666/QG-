# include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include "qgsort.h"

void insertSort(int *a,int n)
{
    int i = 0;
    int j = 0;
    int max;
    int temp;

    for(i=0 ;i<n; i++)
    {
        max = i;//默认第一个元素是最大的

        for(j = i+1; j<n ;j++){//因为j是i后面的元素 所以第一个就是i+1
            if(a[j] > a[max]){
                max = j;//此处j的值并没有改变
            }
        }

        if(a[i] < a[max]){
            temp = a[max];
            a[max]  = a[i];
            a[i] =temp;
        }
    }
}

/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int m = mid;
	int i = begin;
	int j = mid + 1;
	int n = end;
	int k = 0;//k是新数组的元素



	while(i <= m && j <= n){//看哪一个先到边界
		if(a[i] >= a[j]){
			temp[k] = a[i];
			k += 1;
			i += 1;
		}

		else{
			temp[k] = a[j];
			k += 1;
			j += 1;
		}
	}
	//当到达这一步 说明已经有一部分数组已经到达了边界，那么另一组剩下的元素都是最小的元素 直接加在元素的后面即可
	while(i <= m){
		temp[k] = a[i];
		i += 1;
		k += 1;
	}

	while(j <= n){
		temp[k] = a[j];
		j += 1;
		k += 1;
	}
	//此处是把temp数组赋值给a数组
	for(i = 0; i<k; i++){
		a[begin + i] = temp[i];
	}

}

/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp)
{
    if(begin < end)
    {
        int mid = (begin + end)/2;

        MergeSort(a, begin ,mid ,temp);//左边有序的递归
        MergeSort(a, mid+1 ,end ,temp);//右边有序的递归
        MergeArray(a, begin,mid, end, temp);//再将两个有序数列合起来
    }
}



/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end){
    int pos;

    if(begin < end)
    {
        pos = Partition(a, begin, end);
        QuickSort_Recursion(a, begin, pos-1);
        QuickSort_Recursion(a, pos+1, end);
    }
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end){
    //FindPos函数用于查询第一个系数
    int val = a[begin];

    while(begin < end){
        while(begin < end && a[end] <= val){//从后面开始如果后面的值小于value则后面一直往前指
            --end;
        }

        a[begin] = a[end];

        while(begin<end && a[begin]>=val){//从前面开始指，如果前面的值小于后面的值了 交换值
            ++begin;
        }

        a[end] = a[begin];
    }
    a[begin] = val;//最后把第一个存储的值给到中间，此时左边的值全大于value,右边的值全小于value

    return begin;
}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */

void CountSort(int *a, int size , int max)
{
    if(size < 2)
        return;

    int temp1[max+1];//先把暂时的数组给定义了
	memset(temp1, 0 ,sizeof(temp1));//对于数组进行初始化（CSDN找的 也不知道为啥不加不行）

	int i, j ,k;

    for( i=0; i<size ;i++)
    {
        temp1[a[i]]++;//在此处对暂时的数组的底数进行设置
    }
    i=0;//i写在外面挺机智的

    for(j=0; j<max+1;j++)
    {
        //j用于遍历一个个数组

        for(k=0 ;k<temp1[j];k++)
        {//k用于辨别在temp[j]里面有几个j
            a[i++]=j;
        }
    }

}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */

 void menu(){
    printf("-------------------------\n");
    printf("请问您要执行哪项操作：\n");
    printf("1.  100*100k测试\n");
    printf("2.  大数据测试\n");
    printf("3.  退出\n");
    printf("-------------------------\n");
    printf("你要选择的操作是：");}
