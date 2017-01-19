#include <stdio.h>
#include <windows.h>
#include "menu_fun.h"
#include "ifo_fun.h"

void menu(void)
{
    int ch;
    void (*fun[])(void)={ifo_exit, ifo_input, ifo_delete, ifo_modify, ifo_search, ifo_view, ifo_sort, ifo_stats, ifo_reload, ifo_save};

	menu_print();

    printf("\n\t\t��ѡ��");

	while (scanf("%d", &ch),ch<0 || ch>=FUN_NUM)
	{
		while (getchar()!='\n');
		printf("\n\t\t��������,���������룺");
	}

	getchar();

	fun[ch]();

	return;
}

void menu_print(void)
{	
	int i=0;
	
    system("cls");

	printf("\t\t*************ѧ���ɼ�����ϵͳ*************\n\n");
	printf("\t\t\t\t%d.��Ϣ¼��\n\n", ++i);
    printf("\t\t\t\t%d.��Ϣɾ��\n\n", ++i);	
    printf("\t\t\t\t%d.��Ϣ�޸�\n\n", ++i);
    printf("\t\t\t\t%d.��Ϣ��ѯ\n\n", ++i);
	printf("\t\t\t\t%d.��Ϣ���\n\n", ++i);
    printf("\t\t\t\t%d.��Ϣ����\n\n", ++i);
    printf("\t\t\t\t%d.��Ϣͳ��\n\n", ++i);
    printf("\t\t\t\t%d.��������\n\n", ++i);
    printf("\t\t\t\t%d.�����ļ�\n\n", ++i);
	printf("\t\t************* �˳�ϵͳ������0 ************\n");

	return;
}

void menu_sort(int *sort_ch, int *sort_op, int *num)
{	
	*num = menu_sort_print();
	
	printf("\n\t\t�������ѡ��"); 
	
	while (scanf("%d", sort_ch),*sort_ch<1 || *sort_ch>*num)
	{
		while (getchar()!='\n');
		printf("\n\t\t��������,���������룺");
	}
	
	printf("\n\t\t����/����(1/0)��");
 	while (scanf("%d", sort_op),*sort_op!=1 && *sort_op!=0)
	{
		while (getchar()!='\n');
		printf("\n\t\t��������,���������룺");
	}
}

int menu_sort_print(void)
{
	int i;
	
	system("cls");
	printf("\t\t*****************�����ֶ�******************\n\n");
	for (i=1; i<SCORE_NUM+1; i++)
		printf("\t\t\t\t%d.�ɼ�%d\n\n",i,i);
    printf("\t\t\t\t%d.�ܷ�\n\n",i);	
    printf("\t\t\t\t%d.ƽ����\n\n",++i);
	printf("\t\t*******************************************\n");

	return i;
}

void menu_stats(int *stats_ch, int *num)
{
	*num = menu_stats_print();
	
	printf("\n\t\t�������ѡ��"); 
	
	while (scanf("%d", stats_ch),*stats_ch<1 || *stats_ch>*num)
	{
		while (getchar()!='\n');
		printf("\n\t\t��������,���������룺");
	}
}

int menu_stats_print(void)
{
	int i;
	
	system("cls");
	printf("\t\t*************ѧ���ɼ�ͳ��*************\n\n");
	for (i=1; i<SCORE_NUM+1; i++)
		printf("\t\t\t\t%d.�ɼ�%d���\n\n",i,i);
    printf("\t\t\t\t%d.�ܷ����\n\n",i);	
    printf("\t\t\t\t%d.ƽ�������\n\n",++i);
    printf("\t\t\t\t%d.�������˵�\n\n",++i);
	printf("\t\t**************************************\n");
	
	return i;
}
