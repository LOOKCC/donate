#include "donate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct college_info* create_college(struct college_info temp, struct college_info* head){//form zero to create a colllege
    if(head != NULL){//make sure no college
        return head;
    }
    struct college_info* college_new = (struct  college_info*)malloc(sizeof(struct college_info));//apply space
    college_new->class_head = NULL;//set information
    college_new->next = NULL;
    strcpy(college_new->college_name,temp.college_name);
    strcpy(college_new->person_name,temp.person_name);
    strcpy(college_new->phone_number,temp.phone_number);
    head = college_new;
    return head;
}
struct college_info* create_class(struct class_info temp_info, struct college_info* head,int n){//form zero to create a class
    struct college_info* temp = head;//find position
    for(int i = 0; i < n ; ++i){
        temp = temp->next;
    }
    if(temp->class_head != NULL){//make sure no class
        return head;
    }
    struct class_info* class_new = (struct  class_info*)malloc(sizeof(struct class_info));//apply space
    strcpy(class_new->class_ID , temp_info.class_ID);//set information
    class_new->grade = temp_info.grade;
    class_new->person_number = temp_info.person_number;
    strcpy( class_new->college_name , temp_info.college_name);
    strcpy(class_new->counselor , temp_info.counselor);
    class_new->student_head = NULL;
    class_new->next = NULL;
    temp->class_head = class_new;
    return head;
}
struct college_info* create_student(struct student_info temp_info, struct college_info* head,int n1,int n2){
    struct college_info* college_temp = head;//find position
    for(int i = 0; i < n1; ++i){
        college_temp = college_temp->next;
    }
    struct class_info* class_temp = college_temp->class_head;
    for(int i = 0; i < n2; ++i){
        class_temp = class_temp->next;
    }
    if(class_temp->student_head != NULL){//make sure no student
        return head;
    }
    struct student_info* student_new = (struct student_info*)malloc(sizeof(struct student_info));//apply space
    strcpy(student_new->name , temp_info.name);//set information
    strcpy(student_new->ID , temp_info.ID);
    student_new->gender = temp_info.gender;
    student_new->age = temp_info.age;
    student_new->money = temp_info.money;
    student_new->next = NULL;
    class_temp->student_head = student_new;
    return head;
}
void modify(struct college_info* head){//count and save every college's class_number and every class's student_number
    struct college_info* college_temp = head;
    while(college_temp != NULL){
        college_temp->total_class = class_length(college_temp->class_head);
        struct class_info* class_temp = college_temp->class_head;
        while(class_temp != NULL){
            class_temp->total_student = student_length(class_temp->student_head);
            class_temp = class_temp->next;
        }
        college_temp = college_temp->next;
    }
}

bool save(struct college_info* head,char* college_file_name,char* class_file_name,char*  student_file_name){
    modify(head);
    FILE* college_file = fopen(college_file_name,"wb");//open file to save college_info
    FILE* class_file = fopen(class_file_name,"wb");//open file to save class_info
    FILE* student_file = fopen(student_file_name,"wb");//open file to save student_info
    if(!(college_file && class_file && student_file)){//make sure the file is open
        return false;
    }else{
        struct college_info* college_temp = head;
        while(college_temp != NULL){//save the information
            fwrite(college_temp, sizeof(college_info), 1, college_file);
            struct class_info* class_temp = college_temp->class_head;
            while(class_temp != NULL){
                fwrite(class_temp, sizeof(class_info), 1, class_file);
                struct student_info* student_temp = class_temp->student_head;
                while(student_temp != NULL){
                    fwrite(student_temp, sizeof(student_info), 1, student_file);
                    student_temp = student_temp->next;
                }
                class_temp = class_temp->next;
            }
            college_temp = college_temp->next;
        }
    }
    fclose(college_file);
    fclose(class_file);
    fclose(student_file);
    return true;
}
struct college_info* load(struct college_info* head,char* college_file_name,char* class_file_name,char*  student_file_name){
    FILE* college_file = fopen(college_file_name,"rb");//open file to read college_info
    FILE* class_file = fopen(class_file_name,"rb");//open file to read class_info
    FILE* student_file = fopen(student_file_name,"rb");//open file to read student_info
    struct college_info* college_end = NULL;
    if(!(college_file && class_file && student_file)){//make sure file is open
        return NULL;
    }else{
        while(true){//read the information
            struct college_info* college_new = (struct  college_info*)malloc(sizeof(struct college_info));
            if(fread(college_new, sizeof(college_info), 1, college_file) != 1){
                break;
            }
            if(college_end == NULL){
                college_end = college_new;
                head = college_end;
                college_new->next = NULL ;
                college_new->class_head = NULL;
            }else{
                college_end->next = college_new;
                college_end = college_new;
                college_new->next = NULL ;
                college_new->class_head = NULL;
            }
            struct class_info* class_end = NULL;
            for(int i = 0;i < college_new->total_class;++i){
                struct class_info* class_new = (struct class_info*)malloc(sizeof(struct class_info));
                fread(class_new, sizeof(class_info), 1, class_file);
                if(class_end == NULL){
                    class_end = class_new;
                    college_new->class_head = class_end;
                    class_new->next = NULL;
                    class_new->student_head = NULL;
                }else{
                    class_end->next = class_new;
                    class_end = class_new;
                    class_new->next = NULL;
                    class_new->student_head = NULL;
                }
                struct student_info* student_end = NULL;
                for(int j = 0; j < class_new->total_student; ++j){
                    struct student_info* student_new = (struct student_info*)malloc(sizeof(struct student_info));
                    fread(student_new, sizeof(student_info), 1, student_file);
                    if(student_end == NULL){
                        student_end = student_new;
                        class_new->student_head = student_end;
                        student_new->next = NULL;
                    }else{
                        student_end->next = student_new;
                        student_end = student_new;
                        student_new->next = NULL;
                    }
                }
            }
        }
    }
    fclose(college_file);
    fclose(class_file);
    fclose(student_file);
    return head;
}

struct college_info* Change_college(struct college_info temp_info,struct college_info* head, int nco){
    int now = 0;
    struct college_info* temp = head;
    while(nco >  now){//find the position
        temp = temp-> next;
        now++;
    }
    strcpy(temp->college_name,temp_info.college_name);//change information
    strcpy(temp->person_name,temp_info.person_name);
    strcpy(temp->phone_number,temp_info.phone_number);
    return head;
}
struct college_info* Change_class(struct class_info temp_info ,struct college_info* head,  int nco, int ncl){
    int now_co = 0;
    int now_cl = 0;
    struct college_info* college_temp = head;
    while(nco > now_co){//find position
        college_temp = college_temp->next;
        now_co++;
    }
    struct class_info* class_temp = college_temp->class_head;
    while(ncl > now_cl){
        class_temp = class_temp->next;
        now_cl++;
    }
    strcpy(class_temp->class_ID , temp_info.class_ID);//change information
    class_temp->grade = temp_info.grade;
    class_temp->person_number = temp_info.person_number;
    strcpy(class_temp->college_name , temp_info.college_name);
    strcpy(class_temp->counselor,temp_info.counselor);
    return head;
}
struct college_info* Change_student(struct student_info temp_info ,struct college_info* head, int nco,  int ncl, int nst){
    int now_co = 0;
    int now_cl = 0;
    int now_st = 0;
    struct college_info* college_temp = head;
    while(nco > now_co){//find position
        college_temp = college_temp->next;
        now_co++;
    }
    struct class_info* class_temp = college_temp->class_head;
    while(ncl > now_cl){
        class_temp = class_temp->next;
        now_cl++;
    }
    struct student_info* student_temp = class_temp->student_head;
    while(nst > now_st){
        student_temp = student_temp->next;
        now_st++;
    }
    strcpy(student_temp->name,temp_info.name);//change information
    strcpy(student_temp->ID,temp_info.ID);
    student_temp->gender = temp_info.gender;
    student_temp->age = temp_info.age;
    student_temp->money = temp_info.money;
    return head;
}
struct college_info* Insert_college(struct college_info temp_info,struct college_info* head, int nco){
    int now = 0;
    struct college_info* temp = head;
    while(nco  >  now){//find podition
        temp = temp-> next;
        now++;
    }
    struct college_info* college_new = (struct  college_info*)malloc(sizeof(struct college_info));
    strcpy(college_new->college_name,temp_info.college_name);//set infotmation
    strcpy(college_new->person_name,temp_info.person_name);
    strcpy(college_new->phone_number,temp_info.phone_number);
    college_new->class_head = NULL;
    college_new->next = temp->next;//insert
    temp->next = college_new;
    return head;
}
struct college_info* Insert_class(struct class_info temp_info,struct college_info* head, int nco, int ncl){
    int now_co = 0;
    int now_cl = 0;
    struct college_info* college_temp = head;
    while(nco > now_co){//find position
        college_temp = college_temp->next;
        now_co++;
    }
    struct class_info* class_temp = college_temp->class_head;
    while(ncl > now_cl){
        class_temp = class_temp->next;
        now_cl++;
    }
    struct class_info* class_new = (struct  class_info*)malloc(sizeof(struct class_info));
    strcpy(class_new->class_ID , temp_info.class_ID);//set information
    class_new->grade = temp_info.grade;
    class_new->person_number = temp_info.person_number;
    strcpy( class_new->college_name , temp_info.college_name);
    strcpy(class_new->counselor , temp_info.counselor);
    class_new->student_head = NULL;
    class_new->next = class_temp->next;//insert
    class_temp->next = class_new;
    return head;
}
struct college_info* Insert_student(struct student_info temp_info,struct college_info* head, int nco, int ncl, int nst){
    int now_co = 0;
    int now_cl = 0;
    int now_st = 0;
    struct college_info* college_temp = head;
    while(nco > now_co){//find position
        college_temp = college_temp->next;
        now_co++;
    }
    struct class_info* class_temp = college_temp->class_head;
    while(ncl > now_cl){
        class_temp = class_temp->next;
        now_cl++;
    }
    struct student_info* student_temp = class_temp->student_head;
    while(nst > now_st){
        student_temp = student_temp->next;
        now_st++;
    }
    struct student_info* student_new = (struct student_info*)malloc(sizeof(struct student_info));
    strcpy(student_new->name , temp_info.name);//set information
    strcpy(student_new->ID , temp_info.ID);
    student_new->gender = temp_info.gender;
    student_new->age = temp_info.age;
    student_new->money = temp_info.money;
    student_new->next =  student_temp->next;//insert
    student_temp->next = student_new;
    printf("insert over.\n");
    return head;
}
struct college_info* delete_college(struct college_info* head, int nco){
    struct college_info* temp = head, *pre = head;
    if(nco == 0){//if node is head node
        head = head->next;
    }
    else{//if node is not head node
        while(nco > 1){//find position
            temp = temp-> next;
            pre = pre->next;
            nco--;
        }
        temp = temp->next;
        pre->next = temp->next;
    }
    struct class_info* class_temp = temp->class_head;
    struct class_info* class_now;
    while(class_temp != NULL){//delete  class
        class_now = class_temp;
        class_temp = class_temp->next;
        struct student_info* student_temp = class_now->student_head;
        struct student_info* student_now;
        while(student_temp != NULL){//deldete student
            student_now = student_temp;
            student_temp = student_temp->next;
            free(student_now);
        }
        free(class_now);
    }
    free(temp);
    return head;
}
struct college_info* delete_class(struct college_info* head, int nco, int ncl){
    struct college_info* college_temp = head;
    while(nco > 0){//find position
        college_temp = college_temp->next;
        nco--;
    }
    struct class_info* class_temp = college_temp->class_head, *class_pre = college_temp->class_head;
    if(ncl == 0){//if node is head node
        college_temp->class_head= college_temp->class_head->next;
    }else{//if node  is not head node
        while(ncl  > 1){//find position
            class_temp = class_temp->next;
            class_pre = class_pre->next;
            ncl--;
        }
        class_temp = class_temp->next;
        class_pre->next = class_temp->next;
    }

    struct student_info* student_temp = class_temp->student_head;
    struct student_info* student_now;
    while(student_temp != NULL){//delete student
        student_now = student_temp;
        student_temp = student_temp->next;
        free(student_now);
    }
    free(class_temp);
    return head;
}
struct college_info* delete_student(struct college_info* head, int nco, int ncl,int nst){
    struct college_info* college_temp = head;
    while(nco > 0){//find position
        college_temp = college_temp->next;
        nco--;
    }
    struct class_info* class_temp = college_temp->class_head;
    while(ncl > 0){
        class_temp = class_temp->next;
        ncl--;
    }
    struct student_info* student_temp = class_temp->student_head, *student_pre = class_temp->student_head;
    if(nst == 0){//if node is head node
        class_temp->student_head = class_temp->student_head->next;
    }
    else{//if node is not head node
        while(nst > 1){//find position
            student_temp = student_temp->next;
            student_pre = student_pre->next;
            nst--;
        }
        student_temp = student_temp->next;//delete
        student_pre->next = student_temp->next;
    }
    free(student_temp);
    return head;
}
struct college_info* delete_all(struct college_info* head){
    int n = college_length(head);
    for(int i = 0; i < n; ++i){
        delete_college(head,0);
    }
    return NULL;
}

bool search_CS_class(struct college_info* head,int grade,char* class_ID){
    struct college_info* temp_college = head;
    while(temp_college != NULL){
        if(strcmp(temp_college->college_name,"CS") == 0){//college must be CS
            struct class_info* temp_class = temp_college->class_head;
            while(temp_class != NULL){
                if(strcmp(temp_class->class_ID,class_ID) == 0&& temp_class->grade == grade){//class_ID and grade is sure
                    return true;
                }
                temp_class = temp_class->next;
            }
        }
        else{
            temp_college = temp_college->next;
        }
    }
    return false;
}

int college_length(struct college_info* head){//conut college_number
    struct college_info* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
int class_length(struct class_info* head){//count college's class_number
    struct class_info* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
int student_length(struct student_info* head){//count class's student number
    struct student_info* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
void class_donate_total(struct class_info* head){//count class doante
    float total = 0.0f;
    struct student_info* temp = head->student_head;
    while(temp != NULL){
        total += temp->money;
        temp = temp->next;
    }
    head->total_donate = total;
}
void college_donate_total(struct college_info* head){//count college donate
    float total = 0.0f ;
    struct class_info* temp = head->class_head;
    while(temp != NULL){
        class_donate_total(temp);
        total += temp->total_donate;
        temp = temp->next;
    }
    head->total_donate = total;
}
void donate_total(struct college_info* head){//count every class and college donate
    struct college_info* temp = head;
    while(temp != NULL){
        college_donate_total(temp);
        temp = temp->next;
    }
}
void class_student_total(struct class_info* head){//count one class donate student_number
    int total = 0;
    struct student_info* temp = head->student_head;
    while(temp != NULL){
        total++ ;
        temp = temp->next;
    }
    head->total_student = total;
}
void college_student_total(struct college_info* head){//count one college donate student_number
    int total = 0;
    struct class_info* temp = head->class_head;
    while(temp != NULL){
        class_student_total(temp);
        total += temp->total_student;
        temp = temp->next;
    }
    head->total_student = total;
}
void student_total(struct college_info* head){//count all college and class doante student_number
    struct college_info* temp = head;
    while(temp != NULL){
        college_student_total(temp);
        temp = temp->next;
    }
}
struct college_info* college_donate_sort(struct college_info* head){//according donate_money sort college
    int length = college_length(head);
    int flag = 1;//make sure the sort is OK
    for(int i = 1; (i < length) && flag; ++i){
        struct college_info* pre = head;
        struct college_info* now = head;
        struct college_info* after = head->next;
        flag = 0;
        if(now->total_donate < after->total_donate){//if head node  should be move
            pre->next = after->next;
            after->next = pre;
            now = pre;
            pre = after;
            after = now->next;
            head = pre;
            flag = 1;
        }else{
            now = after;
            after = now->next;
        }
        while(after != NULL){//other nodes
            if(now->total_donate < after->total_donate){
                now->next = after->next;
                after->next = now;
                pre->next = after;
                pre = after;
                after = now->next;
                flag = 1;
            }else{
                pre = pre->next;
                now = now->next;
                after = after->next;
            }
        }
    }
    return head;
}
struct class_info* class_donate_sort(struct class_info* head){
    int length = class_length(head);
    int flag = 1;
    for(int i = 1; i < length && flag; ++i){
        struct class_info* pre = head;
        struct class_info* now = head;
        struct class_info* after = head->next;
        flag = 0;
        if(now->total_donate < after->total_donate){//if head should be move
            pre->next = after->next;//change nodes
            after->next = pre;
            now = pre;
            pre = after;
            after = now->next;
            head = pre;
            flag = 1;
        }else{
            now = after;
            after = now->next;
        }
        while(after != NULL){//other nodes
            if(now->total_donate < after->total_donate){
                now->next = after->next;//change nodes
                after->next = now;
                pre->next = after;
                pre = after;
                after = now->next;
                flag = 1;
            }else{
                pre = pre->next;
                now = now->next;
                after = after->next;
            }
        }
    }
    return head;
}
struct college_info* college_student_sort(struct college_info* head){
    int length = college_length(head);
    int flag = 1;
    for(int i = 1; (i < length) && flag; ++i){
        struct college_info* pre = head;
        struct college_info* now = head;
        struct college_info* after = head->next;
        flag = 0;
        if(now->total_student < after->total_student){//if head node should be moved
            pre->next = after->next;
            after->next = pre;
            now = pre;
            pre = after;
            after = now->next;
            head = pre;
            flag = 1;
        }else{
            now = after;
            after = now->next;
        }
        while(after != NULL){//other nodes
            if(now->total_student < after->total_student){
                now->next = after->next;
                after->next = now;
                pre->next = after;
                pre = after;
                after = now->next;
                flag = 1;
            }else{
                pre = pre->next;
                now = now->next;
                after = after->next;
            }

        }
    }
    return head;
}
struct class_info* class_student_sort(struct class_info* head){
    int length = class_length(head);
    int flag = 1;
    for(int i = 1; i < length && flag; ++i){
        struct class_info* pre = head;
        struct class_info* now = head;
        struct class_info* after = head->next;
        flag = 0;
        if(now->total_student < after->total_student){//if head should be move
            pre->next = after->next;//change nodes
            after->next = pre;
            now = pre;
            pre = after;
            after = now->next;
            head = pre;
            flag = 1;
        }else{
            now = after;
            after = now->next;
        }
        while(after != NULL){//other nodes
            if(now->total_student < after->total_student){
                now->next = after->next;//change nodes
                after->next = now;
                pre->next = after;
                pre = after;
                after = now->next;
                flag = 1;
            }else{
                pre = pre->next;
                now = now->next;
                after = after->next;
            }
        }
    }
    return head;
}
struct college_info* sort_donate_all(struct college_info* head){//sort all nodes by donate
    donate_total(head);
    struct college_info* temp = head;
    while(temp != NULL){
        temp->class_head = class_donate_sort(temp->class_head);
        temp = temp->next;
    }
    head = college_donate_sort(head);
    return head;
}
struct college_info* sort_student_all(struct college_info* head){//sort all nodes by students
    student_total(head);
    struct college_info* temp = head;
    while(temp != NULL){
        temp->class_head = class_student_sort(temp->class_head);
        temp = temp->next;
    }
    head = college_student_sort(head);
    return head;
}
