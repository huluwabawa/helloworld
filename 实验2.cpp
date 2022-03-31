#include<stdio.h>
#include<windows.h>
#define  datatype  int
#define MAXSIZE 30
typedef struct array{
datatype data[MAXSIZE];
int  length;
}sqlist;

typedef struct  node{
	datatype data;
	struct node *next;
}ListNode,*LinkList ;
 void len(ListNode *head){//��� 
 	ListNode *p;
 	if(head==NULL){
 		printf("����Ϊ��"); 
	 }else{
	 	p=head->next;
 	int number=0;
 	while(p){
 		number++;
 		p=p->next;
	 }
	 printf("��Ϊ%d",number);
	 } 
	 getchar();	 getchar();
 }
int  remove(ListNode *head){//ɾ������ 
 	int n; 
 	printf("������Ҫɾ���ڼ������");
 	scanf("%d",&n);
	ListNode *p;
	p=head;
	for(int i=1;i<n;i++){
		if(p==NULL){
			printf("ɾ��ʧ��");
			return 1; 
		}
		p=p->next;
	}
	ListNode *del=p->next;//��ס��ɾ���Ľ�� pָ���ָ���� 
	p->next=p->next->next;//p��ָ����ָ�����¸���� 
	printf("ɾ���������Ϊ");
	p=head->next;
	while(p){
		printf("%d",p->data);
		p=p->next;
	}
	free(del);//�ͷű�ɾ���Ľ��Ŀռ� 
	getchar();	getchar();
 }
 int insert(ListNode *head){//�������� 
 	int n;	ListNode *p,*s;
	 printf("������Ҫ�����λ��");
	scanf("%d",&n);
	s=(struct node*)malloc(sizeof(struct node));
	if(s==NULL||head==NULL){
		printf("����ʧ��"); 
		return 1; 
	}	p=head;
	printf("����Ҫ�������");
	scanf("%d",&s->data); 
	for(int i=1;i<n;i++){
		if(p==NULL){
			printf("������Ч");
		}
		p=p->next;
	}//ѭ����Ҫ�����λ�� s��Ҫ����Ľ�� 
	s->next=p->next;//s��ָ����ָ��p��ָ���� 
	p->next=s;//p��ָ����ָ��s 
	printf("����������Ϊ");
	p=head->next;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
	getchar(); 
	getchar();
 } 
void search(ListNode *head){//�������� 
	int n;
	ListNode *p;
	p=head;
	printf("������Ҫ���ʵĵ�n��Ԫ��");
	scanf("%d",&n);
	int i=0; 
	while(p->next&&i<n){//�ӵ�һ������ѭ��n�� 
	p=p->next;
	i++;
}
	if(i==n){
		printf("%d",p->data);
	}else{
		printf("������Χ");
	}
	getchar(); 
	getchar(); 
 }
ListNode * tailcreatelist(ListNode *head){//β�巨�������� 
	struct node *p,*s;
	int len;
	head=(struct node*)malloc(sizeof(struct node));
		if(head==NULL){
		printf("��������ʧ��");
			getchar();getchar();
			return NULL;
	}
 	s=head;
 	printf("������Ҫ������������");
 	scanf("%d",&len);
	for(int i=0;i<len;i++){
		p=(struct node*)malloc(sizeof(struct node));
		if(p==NULL){
		printf("����ʧ��");
			getchar();getchar();return NULL;
		}
	 	scanf("%d",&p->data);
	 	p->next=NULL;//p��ָ����ָ��� 
	 	s->next=p;//s��ָ����ָ��p��� 
	 	s=p;	//s�ƶ���p��λ�� 
	} 
	if(s->next!=NULL){//���һ��һ��Ҫָ��� 
		s->next=NULL;
	} 
	
	p=head->next;
 	while(p){
 		printf("%d  ",p->data);
 		p=p->next;
	 }
	 getchar(); 
	 getchar();
	 return head;
 }
ListNode *  headcreatelist(ListNode *head){ //ͷ�巨�������� 
	struct node *p;
	int len; 
		head=(struct node*)malloc(sizeof(struct node));
	head->next=NULL;
	if(head==NULL){
		printf("��������ʧ��");
			getchar();getchar();
			return NULL;
	}
	printf("������Ҫ������������"); 
	scanf("%d",&len);
	for(int i=0;i<len;i++){
	p=(struct node*)malloc(sizeof(struct node));
	if(p==NULL){
		printf("����ʧ��");
			getchar();getchar();return NULL;
	}
	scanf("%d",&p->data);
	p->next=head->next;//p��ָ����ָ��headָ���ָ���� 
	head->next=p;//head��ָ����ָ��p��㡣 
	}
	while(p){
	printf("%d   ",p->data);
	p = p->next;
	}
	getchar();getchar();
	return head;
}
void list(){//��������˵� 
	LinkList l;
	while(1){
	system("cls");
	printf(" ##############################\n");
	printf("#   1----ǰ�彨������        #\n");
	printf("#   2----��彨������        #\n");
	printf("#   3----���ʵ�i��Ԫ��       #\n");
	printf("#   4----����                #\n");
	printf("#   5----ɾ��                #\n");
	printf("#   6----�����Ա�ı�      #\n");
	printf("#   0----�˳�                #\n");
	printf(" ##############################\n");
	int choice;
	scanf("%d",&choice);
	switch(choice){
		case 1:l=headcreatelist(l);break;
		case 2:l=tailcreatelist(l);break;
		case 3:search(l);break;
		case 4:insert(l);break;
		case 5:remove(l);break; 
		case 6:len(l);break;
		case 0:exit(0);break;
	}
	}
}
void len_arr(sqlist *l){//��� 
	if(l!=NULL){
	printf("��Ϊ%d",l->length);
 		
	}else{
		printf("��Ϊ��"); 
	}
 	getchar();getchar();
 }
int  remove_arr(sqlist *l){//ɾ������ 
 	printf("������Ҫɾ����λ��");
 	int n;
 	scanf("%d",&n);
 	if((n>l->length)){//ɾ����λ�ò��ܴ���˳���ĳ��� 
		printf("ɾ��ʧ��"); 
		getchar();getchar();return 1;
	} 
	for(int i=n-1;i<l->length;i++){
		l->data[i]=l->data[i+1];//�����Ԫ����ǰ�ƶ� 
	} 
	l->length--;
	printf("ɾ�����˳���");
	for(int i=0;i<l->length;i++) {
		printf("%d",l->data[i]);
	}
	getchar();getchar();
 }
int  insert_arr(sqlist *l){//�������� 
	int n;
	printf("������Ҫ�����λ��");
	scanf("%d",&n);
	if((l->length==MAXSIZE)||((n>l->length+1)||(n<=0))){
		printf("����ʧ��"); /*�жϲ����λ�ò��ܴ���˳����ȼ�1 
							n����С�ڵ���0�������ж�˳�����û���� 
							*/ 
		getchar();getchar();return 1;
	} 
	printf("������Ҫ�����ֵ");
	int number;
	scanf("%d",&number); 
	for(int i=l->length-1;i>=n-1;i--){
		l->data[i+1]=l->data[i];//ÿһ����������ƶ� 
	}
	l->data[n-1]=number;
	l->length++;
	printf("������˳���");
	for(int i=0;i<l->length;i++){
		printf("%d",l->data[i]);
	} 
	getchar();getchar();
}
int search_arr(sqlist *l){//�������� 
	if(l==NULL){	//�ж�˳����Ƿ�Ϊ�գ���ֹû�д�����û�д����ɹ�˳��� 
		printf("����ʧ��");
	 	getchar();	getchar();
	 	return 1; 
	}
 	printf("������Ҫ���ʵĵ�i��Ԫ��");
	 int n;
	 scanf("%d",&n);
	 if((n>l->length)||(n<=0)){//��������ݲ��ܴ������ݵ���󳤶�Ҳ����С��0 
	 	printf("����ʧ��");
	 	getchar();	getchar();
	 	return 1; 
	 }
 	printf("%d",l->data[n-1]);
 	getchar();	getchar();
}
sqlist *initarr(sqlist *l){ //����˳��� 
	l=(sqlist*)malloc(sizeof(sqlist));
	if(l==NULL){ //�ж�����Ŀռ��Ƿ�ɹ� 
		printf("����˳���ʧ��");
		exit(0);
	}
	l->length=0;//��ʼ������ 
	int n;
	printf("������˳���Ĵ�С");
	scanf("%d",&n);
	if((n>MAXSIZE)||(n<=0)){
		printf("����ʧ��");
	}
	 for(int i=0;i<n;i++){
	 	scanf("%d",&l->data[i]);
	 	l->length++;
	 }//�������ݵ�˳��� 
	 for(int i=0;i<n;i++){
	 	printf("%d  ",l->data[i]);
	 }//��˳�����˳��� 
	 getchar();getchar();
	 return l;
}
 void array(){
	sqlist *l;
	while(1){system("cls");//�������� 
	printf(" ##############################\n");
	printf("#   1----����˳���          #\n");
	printf("#   2----���ʵ�i��Ԫ��       #\n");
	printf("#   3----����                #\n");
	printf("#   4----ɾ��                #\n");
	printf("#   5----�����Ա�ı�      #\n");
	printf("#   0----�˳�                #\n");
	printf(" ##############################\n");
	int choice;
	scanf("%d",&choice);
	switch(choice){
		case 1:l=initarr(l);break; 
		case 2:search_arr(l);break;
		case 3:insert_arr(l);break;
		case 4:remove_arr(l);break;
		case 5:len_arr(l);break;
		case 0:exit(0);break;
	}	
	}
	
}
void menu(){
 	printf(" *****************************\n");
 	printf("*  1-------˳���           *\n");
 	printf("*  2-------��  ��           *\n");
 	printf("*  0-------��  ��           *\n");
 	printf(" *****************************\n");
 	int choice;
 	scanf("%d",&choice);
 	switch(choice){
 		case 1:array();break;
 		case 2:list();break;
 		case 0:exit(0);break;
	 }
}
int main(){
	menu();
} 
