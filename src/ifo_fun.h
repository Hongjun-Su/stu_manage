#define STRING_SIZE 80
#define NUM_SIZE 20
#define NAME_SIZE 8
#define SCORE_NUM 3
#define STU_NUM 80

typedef struct student{
    char num[NUM_SIZE];
    char name[NAME_SIZE];
    float score[SCORE_NUM+1];
    float sum;
    float ave;
    struct student *next;   
}stu; 

stu* ifo_score_max(int score_ch, stu *p, stu **p_ptr);

stu* ifo_score_min(int score_ch, stu *p, stu **p_ptr);

float ifo_score_ave(int score_ch, stu *p);

void ifo_print_title(void);

void ifo_print_stu(stu *p, int num);

void ifo_print_stats(int stats_ch);

stu* ifo_score_pass(int score_ch, int limit, stu *p);

stu* ifo_score_fail(int score_ch, int limit, stu *p);

void ifo_print(void);

void ifo_input(void);

void ifo_delete(void);

void ifo_modify(void);

void ifo_search(void);

void ifo_view(void);

void ifo_sort(void);
 
void ifo_stats(void);

void ifo_reload(void);

void ifo_save(void);

void ifo_exit(void);
 
