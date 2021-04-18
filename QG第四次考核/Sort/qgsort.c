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
        max = i;//Ĭ�ϵ�һ��Ԫ��������

        for(j = i+1; j<n ;j++){//��Ϊj��i�����Ԫ�� ���Ե�һ������i+1
            if(a[j] > a[max]){
                max = j;//�˴�j��ֵ��û�иı�
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
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int m = mid;
	int i = begin;
	int j = mid + 1;
	int n = end;
	int k = 0;//k���������Ԫ��



	while(i <= m && j <= n){//����һ���ȵ��߽�
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
	//��������һ�� ˵���Ѿ���һ���������Ѿ������˱߽磬��ô��һ��ʣ�µ�Ԫ�ض�����С��Ԫ�� ֱ�Ӽ���Ԫ�صĺ��漴��
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
	//�˴��ǰ�temp���鸳ֵ��a����
	for(i = 0; i<k; i++){
		a[begin + i] = temp[i];
	}

}

/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp)
{
    if(begin < end)
    {
        int mid = (begin + end)/2;

        MergeSort(a, begin ,mid ,temp);//�������ĵݹ�
        MergeSort(a, mid+1 ,end ,temp);//�ұ�����ĵݹ�
        MergeArray(a, begin,mid, end, temp);//�ٽ������������к�����
    }
}



/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
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
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end){
    //FindPos�������ڲ�ѯ��һ��ϵ��
    int val = a[begin];

    while(begin < end){
        while(begin < end && a[end] <= val){//�Ӻ��濪ʼ��������ֵС��value�����һֱ��ǰָ
            --end;
        }

        a[begin] = a[end];

        while(begin<end && a[begin]>=val){//��ǰ�濪ʼָ�����ǰ���ֵС�ں����ֵ�� ����ֵ
            ++begin;
        }

        a[end] = a[begin];
    }
    a[begin] = val;//���ѵ�һ���洢��ֵ�����м䣬��ʱ��ߵ�ֵȫ����value,�ұߵ�ֵȫС��value

    return begin;
}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */

void CountSort(int *a, int size , int max)
{
    if(size < 2)
        return;

    int temp1[max+1];//�Ȱ���ʱ�������������
	memset(temp1, 0 ,sizeof(temp1));//����������г�ʼ����CSDN�ҵ� Ҳ��֪��Ϊɶ���Ӳ��У�

	int i, j ,k;

    for( i=0; i<size ;i++)
    {
        temp1[a[i]]++;//�ڴ˴�����ʱ������ĵ�����������
    }
    i=0;//iд������ͦ���ǵ�

    for(j=0; j<max+1;j++)
    {
        //j���ڱ���һ��������

        for(k=0 ;k<temp1[j];k++)
        {//k���ڱ����temp[j]�����м���j
            a[i++]=j;
        }
    }

}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */

 void menu(){
    printf("-------------------------\n");
    printf("������Ҫִ�����������\n");
    printf("1.  100*100k����\n");
    printf("2.  �����ݲ���\n");
    printf("3.  �˳�\n");
    printf("-------------------------\n");
    printf("��Ҫѡ��Ĳ����ǣ�");}
