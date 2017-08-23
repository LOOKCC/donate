#ifndef DONATE_H
#define DONATE_H

//#define N 3
const int N = 3;
struct college_info
{
    char college_name[30];
    char person_name[20];
    char phone_number[20];
    float total_donate;
    int total_student;

    struct college_info* next;
    struct class_info* class_head;
};
struct  class_info
{
    char class_ID[10];
    int grade;
    int person_number;
    char college_name[30];
    char counselor[30];
    float total_donate;
    int total_student;

    struct class_info* next;
    struct student_info* student_head;
};
struct student_info
{
    char name[20];
    char ID[11];
    char gender;
    int age;
    float money;

    struct student_info* next;
};

//create and save
struct college_info* create_with_console();
struct college_info* create_with_file(char* filename);
void save (struct college_info* head);
//print
void print(struct college_info* head);
//change
struct college_info* Change_college(struct college_info temp_info ,struct college_info* head, int nco);
struct college_info* Change_class(struct class_info temp_info ,struct college_info* head,  int nco, int ncl);
struct college_info* Change_student(struct student_info temp_info, struct college_info* head, int nco,  int ncl, int nst);
//insert
struct college_info* Insert_college(struct college_info temp_info,struct college_info* head, int nco);
struct college_info* Insert_clsss(struct class_info temp_info,struct college_info* head, int nco, int ncl);
struct college_info* Insert_student(struct student_info temp_info,struct college_info* head, int nco, int ncl, int nst);
//delete
struct college_info* delete_college(struct college_info* head, int nco);
struct college_info* delete_class(struct college_info* head, int nco, int ncl);
struct college_info* delete_student(struct college_info* head, int nco, int ncl,int nst);
//search
void search_college(struct college_info* head, char* college_name, int position[]);
void search_class(struct college_info* head, char* college_name, char* class_ID, int position);
void search_student(struct college_info* head, char* college_name, char* class_ID, char* name, int position[]);
//length
int college_length(struct college_info* head);
int class_length(struct class_info* head);
int student_length(struct student_info* head);
//count
void class_donate_total(struct class_info* head);
void college_donate_total(struct college_info* head);
void donate_total(struct college_info* head);
void class_student_total(struct class_info* head);
void college_student_total(struct college_info* head);
void student_total(struct college_info* head);
//sort
void college_donate_sort(struct college_info* head);
void class_donate_sort(struct class_info* head);
void college_student_sort(struct college_info* head);
void class_student_sort(struct class_info* head);
void sort_donate_all(struct college_info* head);
void sort_student_all(struct college_info* head);
#endif // DONATE_H
