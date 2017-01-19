#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "menu_fun.h"
#include "file_fun.h"
#include "ifo_fun.h"

stu s[STU_NUM+1];

int stu_count = 0;
int file_saved = 1;

void ifo_input(void)
{
	int j;
	char ch;
	
	file_saved = 0;
	
	do
	{
		ifo_print();
		
		printf("\n\t\t**************����Ҫ��ӵļ�¼**************\n");
		
		printf("\t\t����ѧ�ţ�");
		gets(s[stu_count+1].num);
		
		printf("\t\t����������");
		gets(s[stu_count+1].name);
		
		s[stu_count+1].sum = 0;
		
		for (j=1; j<SCORE_NUM+1; j++)
		{
			printf("\t\t����ɼ�%d��",j);
			scanf("%f", &s[stu_count+1].score[j]);
			
			s[stu_count+1].sum += s[stu_count+1].score[j];
		}
		
		s[stu_count+1].ave = s[stu_count+1].sum/SCORE_NUM;
		
		s[stu_count].next = &s[stu_count+1];
		
		stu_count++;
		
		s[stu_count].next = NULL; 
		
		ifo_print(); 
		
		getchar();
  		printf("\n\t�Ƿ������Ӽ�¼(Y/N)��");
        scanf("%c", &ch);
		getchar();
		
    }while ('Y'==ch || 'y'==ch);
      
	menu();
}

void ifo_delete(void)
{
	int j,flag;
	char ch;
	char del_num[NUM_SIZE];
	stu *p, *pt;
		
	do
	{
		ifo_print();
		 
		printf("\n\t\t**************����Ҫɾ����ѧ��**************\n");
		printf("\t\t����ѧ�ţ�");
		
		gets(del_num);
		
		p = s[0].next;
		pt = &s[0];
		
		flag = 0;
		
		while (stu_count != 0 && p != NULL)
		{
			if (strcmp(p->num, del_num) == 0)
			{
				pt->next = p->next;	
				stu_count--;
				
				flag = 1;
				file_saved = 0;
				
				break;
			}
			
			pt = p;	
			p = p->next;
		}
		
		ifo_print(); 
		
		if (!flag)
			printf("\n\t��û�и�ѧ����Ϣ��\n");	
		
  		printf("\n\t�Ƿ����ɾ����¼(Y/N)��");
        scanf("%c", &ch);
		getchar();
    }while ('Y'==ch || 'y'==ch);
    
	menu();
}

void ifo_modify(void)
{
	int j,flag;
	char ch;
	char modify_num[NUM_SIZE];
	stu *p;
	
	do
	{
		ifo_print();
		 
		printf("\n\t\t**************����Ҫ�޸ĵ�ѧ��**************\n");
		printf("\t\t����ѧ�ţ�");
		
		gets(modify_num);
		
		p = s[0].next;
		
		flag = 0;
		
		while (stu_count != 0 && p != NULL)
		{
			if (strcmp(p->num, modify_num) == 0)
			{	
					system("cls");
					
					ifo_print_title();
					ifo_print_stu(p, 1);
					
					printf("\n\t\t**************����Ҫ�޸ĵ���Ϣ**************\n");
					
					printf("\t\t����ѧ�ţ�");
					gets(p->num);
		
					printf("\t\t����������");
					gets(p->name);
		
					p->sum = 0;
		
					for (j=1; j<SCORE_NUM+1; j++)
					{
						printf("\t\t����ɼ�%d��",j);
						scanf("%f", &p->score[j]);
			
						p->sum += p->score[j];
					}
		
					p->ave = p->sum/SCORE_NUM;
					
					ifo_print();
					
					printf("\n\t�޸���Ϣ�ɹ���\n");
					
					flag = 1;
					file_saved = 0;
					
					break; 
			}
				
			p = p->next;	 			
		}
		if (!flag)
			printf("\n\t��û�и�ѧ����Ϣ��\n");	
		
  		printf("\n\t�Ƿ�����޸�(Y/N)��");
        scanf("%c", &ch);
		getchar();
    }while ('Y'==ch || 'y'==ch);
    
	menu();
}

void ifo_search(void)
{
	int j,flag;
	char ch;
	char search_num[NUM_SIZE];
	stu *p;
		
	do
	{
		system("cls");

		printf("\t\t**************����Ҫ��ѯ��ѧ��**************\n");
		printf("\t\t����ѧ�ţ�");
		
		scanf("%s", search_num);
		
		p = s[0].next;
		
		flag = 0;
		
		while (stu_count != 0 && p != NULL)
		{
			if (strcmp(p->num, search_num) == 0)
			{
					system("cls");
					
					ifo_print_title();
					ifo_print_stu(p, 1);
					
					flag = 1;
					
					break; 
			}
				
			p = p->next;	 			
		}
		if (!flag)
			printf("\n\t��û�и�ѧ����Ϣ��\n");		
			
		getchar();
  		printf("\n\t�Ƿ������ѯ(Y/N)��");
        scanf("%c", &ch);
		getchar();
    }while ('Y'==ch || 'y'==ch);
    
	menu();
}

void ifo_view(void)
{
	ifo_print();
	
	printf("\n\t��������������˵�...");
	system("pause>nul");
	
	menu(); 
}

void ifo_sort(void)
{
	int i=1;
	int num;
	int sort_ch, sort_op;
	stu *p=s[0].next, *pt=&s[0], *p_ptr=NULL, *p_find=NULL; 
	
	stu* (*score_sort[])(int, stu*, stu**)={ifo_score_max, ifo_score_min};

	menu_sort(&sort_ch, &sort_op, &num);
	
	file_saved = 0;
		
	while (stu_count != 0 && p != NULL && i<stu_count)
	{
		p_find = (*score_sort[sort_op])(sort_ch, p, &p_ptr);
		
		if (p_ptr != &s[0])
		{
			p_ptr->next = p_find->next;
		
			p_find->next = pt->next;
		
			pt->next = p_find;
		}
		
		pt = p_find;	
			
		p = p_find->next;
			
		i++;
	}
	
	ifo_view();
}

void ifo_stats(void)
{
	int num;
	int stats_ch;
	
	menu_stats(&stats_ch, &num);
	
	if (stats_ch == num)
		menu();
	else
		ifo_print_stats(stats_ch);
}

void ifo_print_stats(int stats_ch)
{
	stu *p=s[0].next,*p_max, *p_min, *p_find;
	int n_pass=0, n_fail=0;
	int limit;
	
	if (stats_ch == SCORE_NUM+1)
		limit = SCORE_NUM*60;
	else
		limit = 60;
		
	system("cls");
	
	printf("\t----------------------------��߷�----------------------------\n\n");
	p_max =  ifo_score_max(stats_ch, p, NULL);
	ifo_print_title();
	ifo_print_stu(p_max,1);
	
	printf("\n\n\t----------------------------��ͷ�----------------------------\n\n");
	p_min =  ifo_score_min(stats_ch, p, NULL);
	ifo_print_title();
	ifo_print_stu(p_min,1);
	
	printf("\n\n\t---------------------------��������---------------------------\n\n");
	ifo_print_title();
	while (p != NULL)
	{	
		p_find =  ifo_score_pass(stats_ch, limit, p);
		
		if (p_find != NULL)
		{
			ifo_print_stu(p_find,1); 
			n_pass++;
		}
		
		p = p->next;
	}	
	
	p = s[0].next;
	
	printf("\n\n\t--------------------------����������--------------------------\n\n");
	ifo_print_title();
	while (p != NULL)
	{
		p_find =  ifo_score_fail(stats_ch, limit, p);
		
		if (p_find != NULL)
		{
			ifo_print_stu(p_find,1); 
			n_fail++;
		}
		
		p = p->next;
	}	
	
	printf("\n\t����������%d\n", n_pass);
	printf("\t������������%d\n", n_fail);
	printf("\t�༶ƽ���֣�%.2f\n", ifo_score_ave(stats_ch, s[0].next));
	
	printf("\n\t�����������...");
	system("pause>nul");
	
	ifo_stats(); 
}

void ifo_print(void)
{
	stu *p=s[0].next;
	int j;
	
	system("cls");
		
	printf("\t---------------------��ǰ����ѧ����¼:%3d---------------------\n\n",stu_count);
	
	ifo_print_title();
		
	ifo_print_stu(p, stu_count);		
}

void ifo_print_title(void)
{
	int j;
	
	printf("\t\tѧ��\t  ����\t");
		
	for (j=1;j<SCORE_NUM+1; j++)
		printf("  �ɼ�%d\t",j);
	
	printf("  �ܷ�\tƽ����\t");
	
	printf("\n\n");	
}

void ifo_print_stu(stu *p, int num)
{
	int i=1, j;

	while (stu_count != 0 && p != NULL && i <= num && i <= stu_count)
	{
		printf("%20s",p->num);
		printf("%10s",p->name);
		
		printf(" ");
		
		for (j=1;j<SCORE_NUM+1; j++)
			printf("%8.2f",p->score[j]);
		
		printf("%8.2f",p->sum);
		printf("%7.2f",p->ave);
		
		printf("\n");
			
		p = p->next;
			
		i++;
	}
}

float ifo_score_ave(int score_ch, stu *p)
{
	float sum=0, ave;
	
	while (p != NULL)
	{
		if (score_ch <= SCORE_NUM)
			sum += p->score[score_ch];
		else if (score_ch == SCORE_NUM+1)
			sum += p->sum;
		else if (score_ch == SCORE_NUM+2)
			sum += p->ave;
		
		p = p->next; 
	}
	
	ave = sum/stu_count;
	
	return ave;	
}

stu* ifo_score_max(int score_ch, stu *p, stu **p_ptr)
{
	stu *p_max=p, *pt=&s[0];

	if (p_ptr != NULL)
		*p_ptr = pt;
	
	while (p != NULL)
	{
		if (score_ch <= SCORE_NUM && p_max->score[score_ch] < p->score[score_ch])
		{
			p_max = p;
			
			if (p_ptr != NULL)
				*p_ptr = pt;
		}
		else if (score_ch == SCORE_NUM+1 && p_max->sum < p->sum)
		{
			p_max = p;
			
			if (p_ptr != NULL)
				*p_ptr = pt;
		}
		else if (score_ch == SCORE_NUM+2 && p_max->ave < p->ave)
		{
			p_max = p;
			
			if (p_ptr != NULL)
				*p_ptr = pt;
		}
		
		pt = p;
		p = p->next; 
	}
	
	return p_max;	
}

stu* ifo_score_min(int score_ch, stu *p, stu **p_ptr)
{
	stu *p_min=p, *pt=&s[0];

	if (p_ptr != NULL)
		*p_ptr = pt;
	
	while (p != NULL)
	{
		if (score_ch <= SCORE_NUM && p_min->score[score_ch] > p->score[score_ch])
		{
			p_min = p;
			
			if (p_ptr != NULL)
				*p_ptr = pt;
		}
		else if (score_ch == SCORE_NUM+1 && p_min->sum > p->sum)
		{
			p_min = p;
			
			if (p_ptr != NULL)
				*p_ptr = pt;
		}
		else if (score_ch == SCORE_NUM+2 && p_min->ave > p->ave)
		{
			p_min = p;
			
			if (p_ptr != NULL)
				*p_ptr = pt;
		}
		
		pt = p;
		p = p->next; 
	}
	
	return p_min;	
}

stu* ifo_score_pass(int score_ch, int limit, stu *p)
{
	if (p != NULL)
	{
		if (score_ch <= SCORE_NUM && p->score[score_ch] >= limit)
			return p;
		else if (score_ch == SCORE_NUM+1 && p->sum >= limit)
			return p;
		else if (score_ch == SCORE_NUM+2 && p->ave >= limit)
			return p;
	}
	
	return NULL;
}

stu* ifo_score_fail(int score_ch, int limit, stu *p)
{
	if (p != NULL)
	{
		if (score_ch <= SCORE_NUM && p->score[score_ch] < limit)
			return p;
		else if (score_ch == SCORE_NUM+1 && p->sum < limit)
			return p;
		else if (score_ch == SCORE_NUM+2 && p->ave < limit)
			return p;
	}
	
	return NULL;
}

void ifo_reload(void)
{
	char ch;
	
	if (!file_saved) 
	{
		printf("\n\t\t��ǰ���ݲ�δ���棡�Ƿ�ȷ��(Y/N)��");
	
		scanf("%c", &ch);
		getchar();

		if ('Y'==ch || 'y'==ch)
		{
			file_load();
	
			system("cls");
	
			printf("��������ɹ�����������������˵�..."); 
	
			system("pause>nul");
		}
	}
	
	menu(); 
}

void ifo_save(void)
{
	char ch;
	
	printf("\n\t\t�Ƿ�ȷ��(Y/N)��");
	scanf("%c", &ch);
	getchar();
	
	if ('Y'==ch || 'y'==ch)
	{
		file_save();
		
		printf("��������������˵�..."); 
		system("pause>nul"); 
	}
	
	menu();
}

void ifo_exit(void)
{
	char ch;
	 
 	if (!file_saved)
	{
		printf("\n\t\t�Ƿ񱣴��ļ�(Y/N)��");
		scanf("%c", &ch);
		getchar();
		
		if ('Y'==ch || 'y'==ch)
		{
			file_save();
		
			printf("��������˳�..."); 
			system("pause>nul"); 
		}
	}
	
	return;	
}
