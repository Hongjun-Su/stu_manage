#include <stdio.h>
#include <windows.h>
#include "menu_fun.h"
#include "ifo_fun.h"

void menu(void)
{
    int ch;
    void (*fun[])(void)={ifo_exit, ifo_input, ifo_delete, ifo_modify, ifo_search, ifo_view, ifo_sort, ifo_stats, ifo_reload, ifo_save};

	menu_print();

    printf("\n\t\t请选择：");

	while (scanf("%d", &ch),ch<0 || ch>=FUN_NUM)
	{
		while (getchar()!='\n');
		printf("\n\t\t输入有误,请重新输入：");
	}

	getchar();

	fun[ch]();

	return;
}

void menu_print(void)
{	
	int i=0;
	
    system("cls");

	printf("\t\t*************学生成绩管理系统*************\n\n");
	printf("\t\t\t\t%d.信息录入\n\n", ++i);
    printf("\t\t\t\t%d.信息删除\n\n", ++i);	
    printf("\t\t\t\t%d.信息修改\n\n", ++i);
    printf("\t\t\t\t%d.信息查询\n\n", ++i);
	printf("\t\t\t\t%d.信息浏览\n\n", ++i);
    printf("\t\t\t\t%d.信息排序\n\n", ++i);
    printf("\t\t\t\t%d.信息统计\n\n", ++i);
    printf("\t\t\t\t%d.重新载入\n\n", ++i);
    printf("\t\t\t\t%d.保存文件\n\n", ++i);
	printf("\t\t************* 退出系统请输入0 ************\n");

	return;
}

void menu_sort(int *sort_ch, int *sort_op, int *num)
{	
	*num = menu_sort_print();
	
	printf("\n\t\t输入你的选择："); 
	
	while (scanf("%d", sort_ch),*sort_ch<1 || *sort_ch>*num)
	{
		while (getchar()!='\n');
		printf("\n\t\t输入有误,请重新输入：");
	}
	
	printf("\n\t\t升序/降序(1/0)：");
 	while (scanf("%d", sort_op),*sort_op!=1 && *sort_op!=0)
	{
		while (getchar()!='\n');
		printf("\n\t\t输入有误,请重新输入：");
	}
}

int menu_sort_print(void)
{
	int i;
	
	system("cls");
	printf("\t\t*****************排序字段******************\n\n");
	for (i=1; i<SCORE_NUM+1; i++)
		printf("\t\t\t\t%d.成绩%d\n\n",i,i);
    printf("\t\t\t\t%d.总分\n\n",i);	
    printf("\t\t\t\t%d.平均分\n\n",++i);
	printf("\t\t*******************************************\n");

	return i;
}

void menu_stats(int *stats_ch, int *num)
{
	*num = menu_stats_print();
	
	printf("\n\t\t输入你的选择："); 
	
	while (scanf("%d", stats_ch),*stats_ch<1 || *stats_ch>*num)
	{
		while (getchar()!='\n');
		printf("\n\t\t输入有误,请重新输入：");
	}
}

int menu_stats_print(void)
{
	int i;
	
	system("cls");
	printf("\t\t*************学生成绩统计*************\n\n");
	for (i=1; i<SCORE_NUM+1; i++)
		printf("\t\t\t\t%d.成绩%d情况\n\n",i,i);
    printf("\t\t\t\t%d.总分情况\n\n",i);	
    printf("\t\t\t\t%d.平均分情况\n\n",++i);
    printf("\t\t\t\t%d.返回主菜单\n\n",++i);
	printf("\t\t**************************************\n");
	
	return i;
}
