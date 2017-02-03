#include <stdio.h>
#include <stdlib.h>
#include "file_fun.h"
#include "ifo_fun.h"
#include "menu_fun.h"

extern stu s[];
extern int stu_count;
extern int file_saved;

void file_load(void)
{
    file_read("stu.dat");
    
    file_saved = 1; 
}

void file_save(void)
{
    printf("\033c");

    if (0==file_write("stu.dat"))
    {
        printf("文件保存成功！");

        file_saved = 1;
    }
    else
    {
        printf("文件保存失败！\n");
    }
}

//将文件中的数据读入内存 
int file_read(char *file_name)
{
    FILE *fp;
    int i, j;
    
    if ((fp=fopen(file_name,"r"))==NULL)
        return -1;
    
    s[1].num[0] = '\0';
    
    for (i=1; i<STU_NUM+1 && !feof(fp); i++)
    {   
        fscanf(fp,"%s\t",s[i].num);
        
        fscanf(fp,"%s\t",s[i].name);
        
        s[i].sum = 0;
        
        for (j=1; j<SCORE_NUM+1; j++)
        {
            fscanf(fp,"%f\t",&s[i].score[j]);
            
            s[i].sum += s[i].score[j];
        }
            
        s[i].ave = s[i].sum/SCORE_NUM;
    }
    
    stu_count = i-1;

    if (s[1].num[0] == '\0')
    {
        stu_count=0;
        s[0].next = NULL;
    }
    
    for (i=0; i<stu_count; i++)
        s[i].next = &s[i+1];
            
    s[stu_count].next = NULL;
    
    fclose(fp);
    
    return 0;
}

//将内存中的数据写回文件 
int file_write(char *file_name)
{
    FILE *fp;
    stu *p=s[0].next;
    int j;
    
    if((fp=fopen(file_name,"w"))==NULL)
        return -1; 
        
    while (stu_count != 0 && p != NULL)
    {
        fprintf(fp,"%s\t",p->num);
        fprintf(fp,"%s\t",p->name);
        
        for (j=1;j<SCORE_NUM+1; j++)
            fprintf(fp,"%.2f\t",p->score[j]);
            
        p = p->next;
        
        if (p != NULL)
            fprintf(fp,"\n");
    }
            
    fclose(fp);
    
    return 0;
} 
