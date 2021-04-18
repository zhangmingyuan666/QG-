# include <stdio.h>
#include <stdlib.h>
#include "qgsort.h"
#include <time.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>



int main()
{

    int choice ,max;

    do
    {

    menu();
    scanf("%d", &choice);
    clock_t start,diff;
    int * temp;
    int i;

    switch(choice)
    {
    case 1:
        srand(time(NULL));//�����
        FILE *src = fopen("1.txt","w+");

        setvbuf(src, NULL, _IONBF, 0);//���û���ģʽΪ�޻���

        for(int i = 0; i < 100; i++)
        {
            fprintf(src ,"%d\n", (rand()%100));//д�������
        }
        fclose(src);
        //�Ϸ���������д100��1~100������
        temp = (int *)malloc(sizeof(int)*100);
        int a[100];
        FILE* fpread;
        fpread = fopen("1.txt", "r");
        if (fpread == NULL)
        {
            printf("file is error.");
            return -1;
        }


		for (int j = 0; j < 100; j++)
		{
			fscanf(fpread, "%d", &a[j]);
		}

        fclose(fpread);

		for (int j = 0; j < 100; j++)
		{
			printf("%d\t",a[j]);
		}
		printf("\n");
        //���Ϸ���ȡ�洢��1.text������
        /*
        for(i = 0; i <100; i++)
        {
            a[i] = (rand() % 100);/*����100���ڵ��������*/
        /*    printf("%d\t",a[i]);
        }
        printf("\n");
        */
        max=0;

        for(i=0;i<100;i++){
            if(a[i]>max)
                max = a[i];
        }
        printf("max=%d\n", max);


        clock_t start = clock();
        for(i=0; i<100000; i++)
        {
            insertSort(a,100);
        }
        clock_t diff = clock() - start;
        printf("���������ʱ����%d ms\n", diff);


        start = clock();
        for(i=0; i<100000; i++)
        {
            MergeSort(a,0,100,temp);
        }
        diff = clock() - start;
        printf("�鲢�����ʱ����%d ms\n", diff);


        start = clock();
        for(i=0; i<100000; i++)
        {
            QuickSort_Recursion(a,0,100);
        }
        diff = clock() - start;
        printf("���������ʱ����%d ms\n", diff);

        start = clock();
        for(i=0; i<100000; i++)
        {
            CountSort(a,100,max);
        }
        diff = clock() - start;
        printf("���������ʱ����%d ms\n", diff);

        break;

    case 2:
        srand(time(NULL));//�����
        src = fopen("1.txt","w+");

        setvbuf(src, NULL, _IONBF, 0);//���û���ģʽΪ�޻���

        for(int i = 0; i < 10000; i++)
        {
            fprintf(src ,"%d\n", (rand()%100));//д�������
        }
        fclose(src);
        //�Ϸ���������д10000��1~100������
        temp = (int *)malloc(sizeof(int)*10000);
        int b[10000];
        fpread = fopen("1.txt", "r");
        if (fpread == NULL)
        {
            printf("file is error.");
            return -1;
        }


		for (int j = 0; j < 10000; j++)
		{
			fscanf(fpread, "%d", &b[j]);
		}

        fclose(fpread);
        /*
		for (int j = 0; j < 10000; j++)
		{
			printf("%d\t",b[j]);
		}
		printf("\n");
        */
		/*
        for(i = 0; i <10000; i++)
        {
            b[i] = (rand() % 100);/*����100���ڵ��������*/
        /*    printf("%d\t",b[i]);
        }
        printf("\n");
        */
        max=0;

        for(i=0;i<10000;i++)
        {
            if(b[i]>max)
                max = b[i];
        }
        printf("max=%d\n", max);



        printf("������10000�����ݵ���ʱ\n");

        start = clock();
        insertSort(b,10000);
        diff = clock() - start;
        printf("���������ʱ����%d ms\n", diff);


        start = clock();
        MergeSort(b,0,10000,temp);
        diff = clock() - start;
        printf("�鲢�����ʱ����%d ms\n", diff);


        start = clock();
        QuickSort_Recursion(b,0,10000);
        diff = clock() - start;
        printf("���������ʱ����%d ms\n", diff);


    /*
        start = clock();
        CountSort(b,10000,max);
        diff = clock() - start;
        printf("���������ʱ����%d ms\n\n", diff);
    */

    srand(time(NULL));//�����
        src = fopen("1.txt","w+");

        setvbuf(src, NULL, _IONBF, 0);//���û���ģʽΪ�޻���

        for(int i = 0; i < 50000; i++)
        {
            fprintf(src ,"%d\n", (rand()%100));//д�������
        }
        fclose(src);
        //�Ϸ���������д10000��1~100������
        temp = (int *)malloc(sizeof(int)*50000);
        int c[50000];
        fpread = fopen("1.txt", "r");
        if (fpread == NULL)
        {
            printf("file is error.");
            return -1;
        }


		for (int j = 0; j < 50000; j++)
		{
			fscanf(fpread, "%d", &c[j]);
		}

        fclose(fpread);
        /*
		for (int j = 0; j < 20000; j++)
		{
			printf("%d\t",c[j]);
		}
		printf("\n");
        */
		/*
        for(i = 0; i <10000; i++)
        {
            b[i] = (rand() % 100);/*����100���ڵ��������*/
        /*    printf("%d\t",b[i]);
        }
        printf("\n");
        */
        max=0;

        for(i=0;i<50000;i++)
        {
            if(c[i]>max)
                max = c[i];
        }
        printf("max=%d\n", max);



        printf("������50000�����ݵ���ʱ\n");

        start = clock();
        insertSort(c,50000);
        diff = clock() - start;
        printf("���������ʱ����%d ms\n", diff);


        start = clock();
        MergeSort(c,0,50000,temp);
        diff = clock() - start;
        printf("�鲢�����ʱ����%d ms\n", diff);


        start = clock();
        QuickSort_Recursion(c,0,50000);
        diff = clock() - start;
        printf("���������ʱ����%d ms\n", diff);



        start = clock();
        CountSort(c,50000,max);
        diff = clock() - start;
        printf("���������ʱ����%d ms\n\n", diff);





        srand(time(NULL));//�����
        src = fopen("1.txt","w+");

        setvbuf(src, NULL, _IONBF, 0);//���û���ģʽΪ�޻���

        for(int i = 0; i < 200000; i++)
        {
            fprintf(src ,"%d\n", (rand()%100));//д�������
        }
        fclose(src);
        //�Ϸ���������д10000��1~100������
        temp = (int *)malloc(sizeof(int)*200000);
        int d[200000];
        fpread = fopen("1.txt", "r");
        if (fpread == NULL)
        {
            printf("file is error.");
            return -1;
        }


		for (int j = 0; j < 200000; j++)
		{
			fscanf(fpread, "%d", &d[j]);
		}

        fclose(fpread);
        /*
		for (int j = 0; j < 20000; j++)
		{
			printf("%d\t",c[j]);
		}
		printf("\n");
        */
		/*
        for(i = 0; i <10000; i++)
        {
            b[i] = (rand() % 100);/*����100���ڵ��������*/
        /*    printf("%d\t",b[i]);
        }
        printf("\n");
        */
        max=0;

        for(i=0;i<200000;i++)
        {
            if(d[i]>max)
                max = d[i];
        }
        printf("max=%d\n", max);



        printf("������200000�����ݵ���ʱ\n");

        start = clock();
        insertSort(d,200000);
        diff = clock() - start;
        printf("���������ʱ����%d ms\n", diff);


        start = clock();
        MergeSort(d,0,200000,temp);
        diff = clock() - start;
        printf("�鲢�����ʱ����%d ms\n", diff);


        start = clock();
        QuickSort_Recursion(d,0,200000);
        diff = clock() - start;
        printf("���������ʱ����%d ms\n", diff);


        /*
        start = clock();
        CountSort(d,200000,max);
        diff = clock() - start;
        printf("���������ʱ����%d ms\n\n", diff);
        */
        break;
    case 3:
        break;
    default:
        printf("����ȷ����\n\n");
    }

    }while(choice!=3);
    return 0;
}
