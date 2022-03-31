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
 void len(ListNode *head){//求表长 
 	ListNode *p;
 	if(head==NULL){
 		printf("链表为空"); 
	 }else{
	 	p=head->next;
 	int number=0;
 	while(p){
 		number++;
 		p=p->next;
	 }
	 printf("表长为%d",number);
	 } 
	 getchar();	 getchar();
 }
int  remove(ListNode *head){//删除数据 
 	int n; 
 	printf("请输入要删除第几个结点");
 	scanf("%d",&n);
	ListNode *p;
	p=head;
	for(int i=1;i<n;i++){
		if(p==NULL){
			printf("删除失败");
			return 1; 
		}
		p=p->next;
	}
	ListNode *del=p->next;//记住被删除的结点 p指向的指针域 
	p->next=p->next->next;//p的指针域指向下下个结点 
	printf("删除后的链表为");
	p=head->next;
	while(p){
		printf("%d",p->data);
		p=p->next;
	}
	free(del);//释放被删除的结点的空间 
	getchar();	getchar();
 }
 int insert(ListNode *head){//插入数据 
 	int n;	ListNode *p,*s;
	 printf("请输入要插入的位置");
	scanf("%d",&n);
	s=(struct node*)malloc(sizeof(struct node));
	if(s==NULL||head==NULL){
		printf("插入失败"); 
		return 1; 
	}	p=head;
	printf("输入要插入的数");
	scanf("%d",&s->data); 
	for(int i=1;i<n;i++){
		if(p==NULL){
			printf("插入无效");
		}
		p=p->next;
	}//循环到要插入的位置 s是要插入的结点 
	s->next=p->next;//s的指针域指向p的指针域 
	p->next=s;//p的指针域指向s 
	printf("插入后的链表为");
	p=head->next;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
	getchar(); 
	getchar();
 } 
void search(ListNode *head){//访问数据 
	int n;
	ListNode *p;
	p=head;
	printf("请输入要访问的第n个元素");
	scanf("%d",&n);
	int i=0; 
	while(p->next&&i<n){//从第一个往后循环n次 
	p=p->next;
	i++;
}
	if(i==n){
		printf("%d",p->data);
	}else{
		printf("超出范围");
	}
	getchar(); 
	getchar(); 
 }
ListNode * tailcreatelist(ListNode *head){//尾插法建立链表 
	struct node *p,*s;
	int len;
	head=(struct node*)malloc(sizeof(struct node));
		if(head==NULL){
		printf("创建链表失败");
			getchar();getchar();
			return NULL;
	}
 	s=head;
 	printf("请输入要创建的链表长度");
 	scanf("%d",&len);
	for(int i=0;i<len;i++){
		p=(struct node*)malloc(sizeof(struct node));
		if(p==NULL){
		printf("创建失败");
			getchar();getchar();return NULL;
		}
	 	scanf("%d",&p->data);
	 	p->next=NULL;//p的指针域指向空 
	 	s->next=p;//s的指针域指向p结点 
	 	s=p;	//s移动到p的位置 
	} 
	if(s->next!=NULL){//最后一个一定要指向空 
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
ListNode *  headcreatelist(ListNode *head){ //头插法建立链表 
	struct node *p;
	int len; 
		head=(struct node*)malloc(sizeof(struct node));
	head->next=NULL;
	if(head==NULL){
		printf("创建链表失败");
			getchar();getchar();
			return NULL;
	}
	printf("请输入要创建的链表长度"); 
	scanf("%d",&len);
	for(int i=0;i<len;i++){
	p=(struct node*)malloc(sizeof(struct node));
	if(p==NULL){
		printf("创建失败");
			getchar();getchar();return NULL;
	}
	scanf("%d",&p->data);
	p->next=head->next;//p的指针域指向head指向的指针域 
	head->next=p;//head的指针域指向p结点。 
	}
	while(p){
	printf("%d   ",p->data);
	p = p->next;
	}
	getchar();getchar();
	return head;
}
void list(){//链表二级菜单 
	LinkList l;
	while(1){
	system("cls");
	printf(" ##############################\n");
	printf("#   1----前插建立链表        #\n");
	printf("#   2----后插建立链表        #\n");
	printf("#   3----访问第i个元素       #\n");
	printf("#   4----插入                #\n");
	printf("#   5----删除                #\n");
	printf("#   6----求线性表的表长      #\n");
	printf("#   0----退出                #\n");
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
void len_arr(sqlist *l){//求表长 
	if(l!=NULL){
	printf("表长为%d",l->length);
 		
	}else{
		printf("表为空"); 
	}
 	getchar();getchar();
 }
int  remove_arr(sqlist *l){//删除数据 
 	printf("请输入要删除的位置");
 	int n;
 	scanf("%d",&n);
 	if((n>l->length)){//删除的位置不能大于顺序表的长度 
		printf("删除失败"); 
		getchar();getchar();return 1;
	} 
	for(int i=n-1;i<l->length;i++){
		l->data[i]=l->data[i+1];//后面的元素向前移动 
	} 
	l->length--;
	printf("删除后的顺序表");
	for(int i=0;i<l->length;i++) {
		printf("%d",l->data[i]);
	}
	getchar();getchar();
 }
int  insert_arr(sqlist *l){//插入数据 
	int n;
	printf("请输入要插入的位置");
	scanf("%d",&n);
	if((l->length==MAXSIZE)||((n>l->length+1)||(n<=0))){
		printf("插入失败"); /*判断插入的位置不能大于顺序表长度加1 
							n不能小于等于0，还有判断顺序表有没有满 
							*/ 
		getchar();getchar();return 1;
	} 
	printf("请输入要插入的值");
	int number;
	scanf("%d",&number); 
	for(int i=l->length-1;i>=n-1;i--){
		l->data[i+1]=l->data[i];//每一个数据向后移动 
	}
	l->data[n-1]=number;
	l->length++;
	printf("插入后的顺序表");
	for(int i=0;i<l->length;i++){
		printf("%d",l->data[i]);
	} 
	getchar();getchar();
}
int search_arr(sqlist *l){//查找数据 
	if(l==NULL){	//判断顺序表是否为空，防止没有创建或没有创建成功顺序表 
		printf("查找失败");
	 	getchar();	getchar();
	 	return 1; 
	}
 	printf("请输入要访问的第i个元素");
	 int n;
	 scanf("%d",&n);
	 if((n>l->length)||(n<=0)){//输入的数据不能大于数据的最大长度也不能小于0 
	 	printf("查找失败");
	 	getchar();	getchar();
	 	return 1; 
	 }
 	printf("%d",l->data[n-1]);
 	getchar();	getchar();
}
sqlist *initarr(sqlist *l){ //创建顺序表 
	l=(sqlist*)malloc(sizeof(sqlist));
	if(l==NULL){ //判断申请的空间是否成功 
		printf("创建顺序表失败");
		exit(0);
	}
	l->length=0;//初始化长度 
	int n;
	printf("请输入顺序表的大小");
	scanf("%d",&n);
	if((n>MAXSIZE)||(n<=0)){
		printf("创建失败");
	}
	 for(int i=0;i<n;i++){
	 	scanf("%d",&l->data[i]);
	 	l->length++;
	 }//输入数据到顺序表 
	 for(int i=0;i<n;i++){
	 	printf("%d  ",l->data[i]);
	 }//按顺序输出顺序表 
	 getchar();getchar();
	 return l;
}
 void array(){
	sqlist *l;
	while(1){system("cls");//清屏函数 
	printf(" ##############################\n");
	printf("#   1----建立顺序表          #\n");
	printf("#   2----访问第i个元素       #\n");
	printf("#   3----插入                #\n");
	printf("#   4----删除                #\n");
	printf("#   5----求线性表的表长      #\n");
	printf("#   0----退出                #\n");
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
 	printf("*  1-------顺序表           *\n");
 	printf("*  2-------链  表           *\n");
 	printf("*  0-------退  出           *\n");
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
