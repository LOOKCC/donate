#include "donate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct college_info* create_with_console(){
	int college_count ;
	int college_now = 0;
	printf("%s\n","Please input the colege numbers:" );
	scanf("%d",&college_count);
	struct college_info* college_head = NULL, *college_end = NULL;
	while(college_count > college_now ){
		struct college_info* college_new = (struct  college_info*)malloc(sizeof(struct college_info)); 
		printf("college begin:\n");
		scanf("%s",college_new->college_name);
		scanf("%s",college_new->person_name);
		scanf("%s",college_new->phone_number);
		printf("college over\n");


		int class_count;
		int class_now = 0;
		printf("%s\n","Please input the class numbers:" );
		scanf("%d",&class_count);
		struct class_info* class_head = NULL, *class_end = NULL;
		while(class_count > class_now ){
			struct class_info* class_new = (struct  class_info*)malloc(sizeof(struct class_info)); 
			printf("class begin\n");
			scanf("%s",class_new->class_ID);
			scanf("%d",&class_new->grate);
			scanf("%d",&class_new->person_number);
			scanf("%s",class_new->college_name);
			scanf("%s",class_new->counselor);
			printf("class over\n");


			int student_count;
			int student_now = 0;
			printf("%s\n","Please input the student numbers:" );
			scanf("%d", &student_count);
			struct student_info* student_head = NULL, *student_end = NULL;
			while(student_count >student_now){
				struct student_info* student_new = (struct student_info*)malloc(sizeof(struct student_info));
				printf("student begin:\n");
				scanf("%s",student_new->name);
				scanf("%s",student_new->ID);
				getchar();
				scanf("%c",&student_new->gender);
				scanf("%d",&student_new->age);
				scanf("%f",&student_new->money);
				printf("student over:\n");
				if(student_now == 0){
					student_head = student_new;
					student_end = student_new;
					student_end->next = NULL;
				}
				else{
					student_end->next = student_new;
					student_end = student_new;
					student_end->next = NULL;
				}
				student_now++;
			}
			class_new->student_head = student_head;

			if(class_now == 0){
				class_head = class_new;
				class_end = class_new ;
				class_end->next = NULL;
			}
			else{
				class_end->next = class_new;
				class_end = class_new;
				class_end ->next = NULL;
			}
			class_now++;
		}
		college_new->class_head = class_head;

		if(college_now == 0){
			college_head = college_new;
			college_end = college_new;
			college_end->next = NULL;
		} 
		else{
			college_end->next = college_new;
			college_end = college_new;
			college_end->next = NULL;

		}
		college_now ++;	
	}
	return college_head;
}

struct college_info* create_with_file(char* filename){
	FILE* info;
	info = fopen(filename, "r");
	if(info == NULL){
		printf("can't open the file.\n");
	}
	int college_count ;
	int college_now = 0;
	//printf("%s\n","Please input the colege numbers:" );
	fscanf(info,"%d",&college_count);
	struct college_info* college_head = NULL, *college_end = NULL;
	while(college_count > college_now ){
		struct college_info* college_new = (struct  college_info*)malloc(sizeof(struct college_info)); 
		//printf("college begin:\n");
		fscanf(info,"%s",college_new->college_name);
		fscanf(info,"%s",college_new->person_name);
		fscanf(info,"%s",college_new->phone_number);
		//printf("college over\n");


		int class_count;
		int class_now = 0;
		//printf("%s\n","Please input the class numbers:" );
		fscanf(info,"%d",&class_count);
		struct class_info* class_head = NULL, *class_end = NULL;
		while(class_count > class_now ){
			struct class_info* class_new = (struct  class_info*)malloc(sizeof(struct class_info)); 
			//printf("class begin\n");
			fscanf(info,"%s",class_new->class_ID);
			fscanf(info,"%d",&class_new->grate);
			fscanf(info,"%d",&class_new->person_number);
			fscanf(info,"%s",class_new->college_name);
			fscanf(info,"%s",class_new->counselor);
			//printf("class over\n");


			int student_count;
			int student_now = 0;
			//printf("%s\n","Please input the student numbers:" );
			fscanf(info,"%d", &student_count);
			struct student_info* student_head = NULL, *student_end = NULL;
			while(student_count >student_now){
				struct student_info* student_new = (struct student_info*)malloc(sizeof(struct student_info));
				//printf("student begin:\n");
				fscanf(info,"%s",student_new->name);
				fscanf(info,"%s",student_new->ID);
				fscanf(info,"%c",&student_new->gender);
				fscanf(info,"%d",&student_new->age);
				fscanf(info,"%f",&student_new->money);
				//printf("student over\n");
				if(student_now == 0){
					student_head = student_new;
					student_end = student_new;
					student_end->next = NULL;
				}
				else{
					student_end->next = student_new;
					student_end = student_new;
					student_end->next = NULL;
				}
				student_now++;
			}
			class_new->student_head = student_head;

			if(class_now == 0){
				class_head = class_new;
				class_end = class_new ;
				class_end->next = NULL;
			}
			else{
				class_end->next = class_new;
				class_end = class_new;
				class_end ->next = NULL;
			}
			class_now++;
		}
		college_new->class_head = class_head;

		if(college_now == 0){
			college_head = college_new;
			college_end = college_new;
			college_end->next = NULL;
		} 
		else{
			college_end->next = college_new;
			college_end = college_new;
			college_end->next = NULL;

		}
		college_now ++;	
	}
	return college_head;
}
void print(struct college_info* head){
	struct college_info* college_temp;
	struct class_info* class_temp;
	struct student_info* student_temp;
	college_temp = head;
	while(college_temp!=NULL){
		printf("college: \n");
		printf("college_name: %s ",college_temp->college_name);
		printf("person_name: %s ",college_temp->person_name);
		printf("phone_number: %s\n",college_temp->phone_number);
		printf("		class: \n");
		class_temp = college_temp->class_head;
		while(class_temp!=NULL){
			printf("		class_ID: %s ",class_temp->class_ID);
			printf("grate: %d ",class_temp->grate);
			printf("person_number: %d ",class_temp->person_number);
			printf("college_name: %s ",class_temp->college_name);
			printf("counselor: %s\n",class_temp->counselor);
			printf("			student: \n");
			student_temp = class_temp->student_head;
			while(student_temp!=NULL){
				printf("			name: %s ",student_temp->name);
				printf("ID: %s ",student_temp->ID);
				printf("genter: %c ",student_temp->gender);
				printf("age: %d ",student_temp->age);
				printf("money: %f\n",student_temp->money);
				student_temp = student_temp->next;
			}
			class_temp = class_temp->next;
		}
		college_temp = college_temp->next;
	}
}
void save (struct college_info* head){
	FILE* info_save;
	info_save = fopen("info_save","wb");
	if(info_save == NULL){
		printf("can't open the file.\n");
	}

	struct college_info* college_temp;
	struct class_info* class_temp;
	struct student_info* student_temp;
	college_temp = head;
	while(college_temp!=NULL){
		printf("college: \n");
		printf("college_name: %s ",college_temp->college_name);
		printf("person_name: %s ",college_temp->person_name);
		printf("phone_number: %s\n",college_temp->phone_number);
		printf("		class: \n");
		class_temp = college_temp->class_head;
		while(class_temp!=NULL){
			printf("		class_ID: %s ",class_temp->class_ID);
			printf("grate: %d ",class_temp->grate);
			printf("person_number: %d ",class_temp->person_number);
			printf("college_name: %s ",class_temp->college_name);
			printf("counselor: %s\n",class_temp->counselor);
			printf("			student: \n");
			student_temp = class_temp->student_head;
			while(student_temp!=NULL){
				printf("			name: %s ",student_temp->name);
				printf("ID: %s ",student_temp->ID);
				printf("genter: %c ",student_temp->gender);
				printf("age: %d ",student_temp->age);
				printf("money: %f\n",student_temp->money);
				student_temp = student_temp->next;
			}
			class_temp = class_temp->next;
		}
		college_temp = college_temp->next;
	}
}
struct college_info* change_college(struct college_info* head, int nco){
	int now = 1;
	struct college_info* temp = head;
	while(nco >  now){
		temp = temp-> next;
		now++;
	} 
	printf("Please input college name: \n");
	scanf("%s",temp->college_name);
	printf("Please input college's person name: \n");
	scanf("%s",temp->person_name);
	printf("Please input phone_number: \n");
	scanf("%s",temp->phone_number);
	printf("change over.\n");
	return head;
}
struct college_info* change_class(struct college_info* head,  int nco, int ncl){
	int now_co = 1;
	int now_cl = 1;
	struct college_info* college_temp = head;
	while(nco > now_co){
		college_temp = college_temp->next;
		now_co++;
	}
	struct class_info* class_temp = college_temp->class_head;
	while(ncl > now_cl){
		class_temp = class_temp->next;
		now_cl++;
	}
	printf("Please input class_ID: \n");
	scanf("%s",class_temp->class_ID);
	printf("Please input grade: \n");
	scanf("%d",&class_temp->grade);
	printf("Please input person_number: \n");
	scanf("%d",&class_temp->person_number);
	printf("Please input college_name: \n");
	scanf("%s",class_temp->college_name);
	printf("Please input counselor: \n")
	scanf("%s",class_temp->counselor);
	printf("change over.\n");
	return head;
}
struct college_info* change_student(struct college_info* head, int nco,  int ncl, int nst){
	int now_co = 1;
	int now_cl = 1;
	int now_st = 1;
	struct college_info* college_temp = head;
	while(nco > now_co){
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
	printf("Please input name: \n");
	scanf("%s",student_temp->name);
	printf("Please input ID: \n");
	scanf("%s",student_temp->ID);
	printf("Please input gender: \n");
	scanf("%c",&student_temp->gender);
	printf("Please input age: \n");
	scanf("%d",&student_temp->age);
	printf("Please input money: \n")
	scanf("%f",&student_temp->money);
	printf("change over.\n");	
	return head;
}
struct college_info* insert_college(struct college_info* head, int nco){
	int now = 1;
	struct college_info* temp = head;
	while(nco - 1 >  now){
		temp = temp-> next;
		now++;
	} 	
	struct college_info* college_new = (struct  college_info*)malloc(sizeof(struct college_info)); 
	printf("Please input college name: \n");
	scanf("%s",college_new->college_name);
	printf("Please input college's person name: \n");
	scanf("%s",college_new->person_name);
	printf("Please input phone_number: \n");
	scanf("%s",college_new->phone_number);
	college_new->class_head = NULL;
	college_new->next = temp->next;
	temp->next = college_new;
	printf("insert over.\n");
	return head;
}
struct college_info* insert_calss(struct college_info* head, int nco, int ncl){
	int now_co = 1;
	int now_cl = 1;
	struct college_info* college_temp = head;
	while(nco > now_co){
		college_temp = college_temp->next;
		now_co++;
	}
	struct class_info* class_temp = college_temp->class_head;
	while(ncl - 1 > now_cl){
		class_temp = class_temp->next;
		now_cl++;
	}
	struct class_info* class_new = (struct  class_info*)malloc(sizeof(struct class_info)); 
	printf("Please input class_ID: \n");
	scanf("%s",class_new->class_ID);
	printf("Please input grade: \n");
	scanf("%d",&class_new->grade);
	printf("Please input person_number: \n");
	scanf("%d",&class_new->person_number);
	printf("Please input college_name: \n");
	scanf("%s",class_new->college_name);
	printf("Please input counselor: \n")
	scanf("%s",class_new->counselor);
	class_new->student_head = NULL;
	class_new->next = class_temp->next;
	class_temp->next = class_new;
	printf("insert over.\n");
	return head;
}
struct college_info* insert_student(struct college_info* head, int nco, int ncl, int nst){
	int now_co = 1;
	int now_cl = 1;
	int now_st = 1;
	struct college_info* college_temp = head;
	while(nco > now_co){
		college_temp = college_temp->next;
		now_co++;
	}
	struct class_info* class_temp = college_temp->class_head;
	while(ncl > now_cl){
		class_temp = class_temp->next;
		now_cl++;
	}
	struct student_info* student_temp = class_temp->student_head;
	while(nst - 1> now_st){
		student_temp = student_temp->next;
		now_st++;
	}
	struct student_info* student_new = (struct student_info*)malloc(sizeof(struct student_info));
	printf("Please input name: \n");
	scanf("%s",student_new->name);
	printf("Please input ID: \n");
	scanf("%s",student_new->ID);
	printf("Please input gender: \n");
	scanf("%c",&student_new->gender);
	printf("Please input age: \n");
	scanf("%d",&student_new->age);
	printf("Please input money: \n");
	scanf("%f",&student_new->money);
	student_new->next =  student_temp->next;
	student_temp->next = student_new;
	printf("insert over.\n");	
	return head;
}
struct college_info* delete_college(struct college_info* head, int nco){
	int now = 1;
	struct college_info* temp = head, *pre = head;
	while(nco - 1>  now){
		temp = temp-> next;
		pre = pre->next;
		now++;
	}
	temp = temp->next;
	pre->next = temp->next;
	free(temp);
	return head;
}
struct college_info* delete_class(struct college_info* head, int nco, int ncl){
	int now_co = 1;
	int now_cl = 1;
	struct college_info* college_temp = head;
	while(nco > now_co){
		college_temp = college_temp->next;
		now_co++;
	}
	struct class_info* class_temp = college_temp->class_head, *class_pre = college_temp->class_head;
	while(ncl - 1 > now_cl){
		class_temp = class_temp->next;
		class_pre = class_pre->next;
		now_cl++;
	}
	class_temp = class_temp->next;
	class_pre->next = class_temp->next;
	free(class_temp);
	return head;
}
struct college_info* delete_student(struct college_info* head, int nco, int ncl,int nst){
	int now_co = 1;
	int now_cl = 1;
	int now_st = 1;
	struct college_info* college_temp = head;
	while(nco > now_co){
		college_temp = college_temp->next;
		now_co++;
	}
	struct class_info* class_temp = college_temp->class_head;
	while(ncl > now_cl){
		class_temp = class_temp->next;
		now_cl++;
	}
	struct student_info* student_temp = class_temp->student_head, *student_pre = class_temp->student_head;
	while(nst - 1> now_st){
		student_temp = student_temp->next;
		student_pre = student_pre->next;
		now_st++;
	}
	student_temp = student_temp->next;
	student_pre->next = student_temp->next;
	free(student_temp);
	return head;
}
void search_college(struct college_info* head, char* college_name, int position[]){
	position[0] = 1, position[1] = 0, position[2] = 0;
	struct college_info* college_temp = head;
	while(college_temp != NULL){
		if(strcmp(college_name,college_temp->college_name) == 0)
			break;
		position[0]++;
		college_temp = college_temp->next;	
	}
	if(position[0] == college_length(head) + 1){
		position[0] = 0;
		printf("Can't find. \n");
	}
}
void search_class(struct college_info* head, char* college_name, char* class_ID, int position){
	position[0] = 1, position[1] = 1, position[2] = 0;
	srtuct college_info* college_temp = head;
	while(college_temp != NULL){
		if(strcmp(college_name,college_temp->college_name) == 0)
			break;
		position[0]++;
		college_temp = college_temp->next;	
	}
	if(position[0] == college_length(head) + 1){
		position[0] = 0;
		printf("Can't find.\n");
	}else{
		struct class_info* class_temp = college_temp->class_head;
		while(class_temp != NULL){
			if(strcmp(class_ID,class_temp->class_ID) == 0)
				break;
			position[1]++;
			class_temp = class_temp->next;
		}
		if(position[1] == class_length(college_temp->class_head) + 1){
			position[1] = 0;
			printf("Can't find.\n");
		}
	}
}
void search_student(struct college_info* head, char* college_name, char* class_ID, char* name, int position[]){
	position[0] = 1, position[1] = 1, position[2] = 1;
	srtuct college_info* college_temp = head;
	while(college_temp != NULL){
		if(strcmp(college_name,college_temp->college_name) == 0)
			break;
		position[0]++;
		college_temp = college_temp->next;	
	}
	if(position[0] == college_length(head) + 1){
		position[0] = 0;
		printf("Can't find.\n");
	}else{
		struct class_info* class_temp = college_temp->class_head;
		while(class_temp != NULL){
			if(strcmp(class_ID,class_temp->class_ID) == 0)
				break;
			position[1]++;
			class_temp = class_temp->next;
		}
		if(position[1] == class_length(college_temp->class_head) + 1){
			position[1] = 0;
			printf("Can't find.\n");
		}else{
			struct student_info* student_temp = class_temp->student_head;
			while(student_temp != NULL){
				if(strcmp(name,student_temp->name) == 0)
					break;
				position[2]++;
				student_temp = student_temp->next;
			}
			if(position[2] == student_length(class_temp->student_head) + 1){
				position[2] = 0;
				printf("Can't find.\n");
			}
		}
	}
}
int college_length(struct college_info* head){
	struct college_info* temp = head;
	int count = 0;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}
int class_length(struct class_info* head){
	struct class_info* temp = head;
	int count = 0;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}	
int student_length(struct student_info* head){
	struct sstudent_info* temp = head;
	int count = 0;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}
void class_total(struct class_info* head){
	float total = 0.0f;
	struct student_info* temp = head->student_head;
	while(temp != NULL){
		total += temp->money;
		temp = temp->next;
	}
	head->total_donate = total;
}
void college_total(struct college_info* head){
	float total = 0.0f ;
	struct class_info* temp = head->class_head;
	while(temp != NULL){
		class_taotal(temp);
		total += temp->total_donate;
		temp = temp->next;
	}
	head->total_donate = total;
}
void donate_total(struct college_info* head){
	struct college_info* temp = head;
	while(temp != NULL){
		collge_donate_total(temp);
		temp = temp->next;
	}
}
void class_student_total(struct class_info* head){
	int total = 0;
	struct student_info* temp = head->student_head;
	while(temp != NULL){
		total++ ;
		temp = temp->next;
	}
	head->total_student = total;
}
void college_student_total(struct college_info* head){
	int total = 0;
	struct class_info* temp = head->class_head;
	while(temp != NULL){
		class_student_taotal(temp);
		total += temp->total_student;
		temp = temp->next;
	}
	head->total_student = total;
}
void student_total(struct college_info* head){
	struct college_info* temp = head;
	while(temp != NULL){
		collge_student_total(temp);
		temp = temp->next;
	}
}
void college_donate_sort(struct college_info* head){
	int length = college_length(head);
	struct college_info* pre = head;
	struct college_info* now = head;
	struct college_info* after = head->next;
	int flag = 1;
	for(int i = 0; i < length && flag; ++i){
		flag = 0;
		if(now->total_donate < after->total_donate){
			pre->next = after->next;
			after->next = pre;
			now = pre;
			pre = after;
			after = now->next;
			flag = 1;
		}else{
			temp = after;
			after = now->next;
		}
		while(after != NULL){
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
}
void class_donate_sort(struct class_info* head){
	int length = class_length(head);
	struct class_info* pre = head;
	struct class_info* now = head;
	struct class_info* after = head->next;
	int flag = 1;
	for(int i = 0; i < length && flag; ++i){
		flag = 0;
		if(now->total_donate < after->total_donate){
			pre->next = after->next;
			after->next = pre;
			now = pre;
			pre = after;
			after = now->next;
			flag = 1;
		}else{
			temp = after;
			after = now->next;
		}
		while(after != NULL){
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
}
void college_student_sort(struct college_info* head){
	int length = college_length(head);
	struct college_info* pre = head;
	struct college_info* now = head;
	struct college_info* after = head->next;
	int flag = 1;
	for(int i = 0; i < length && flag; ++i){
		flag = 0;
		if(now->total_student < after->total_student){
			pre->next = after->next;
			after->next = pre;
			now = pre;
			pre = after;
			after = now->next;
			flag = 1;
		}else{
			temp = after;
			after = now->next;
		}
		while(after != NULL){
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
}
void class_student_sort(struct class_info* head){
	int length = class_length(head);
	struct class_info* pre = head;
	struct class_info* now = head;
	struct class_info* after = head->next;
	int flag = 1;
	for(int i = 0; i < length && flag; ++i){
		flag = 0;
		if(now->total_student < after->total_student){
			pre->next = after->next;
			after->next = pre;
			now = pre;
			pre = after;
			after = now->next;
			flag = 1;
		}else{
			temp = after;
			after = now->next;
		}
		while(after != NULL){
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
}
void sort_donate_all(struct college_info* head){
	donate_total(head);
	struct college_info* temp = head;
	while(temp != NULL){
		class_donate_sort(temp->class_head);
		temp = temp->next;
	}
	college_donate_sort(head);
}
void sort_student_all(struct college_info* head){
	student_total(head);
	struct college_info* temp = head;
	while(temp != NULL){
		class_student_sort(temp->class_head);
		temp = temp->next;
	}
	college_student_sort(head);
}
