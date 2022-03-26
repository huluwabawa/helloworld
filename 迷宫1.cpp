#include<stdio.h>
#include<malloc.h> 
#include <stdlib.h>
#include<windows.h>
typedef  struct node
{ int row;
int col;
struct node *next;
}NODE;
typedef struct 
{
	struct node *top;
	int cnt;
}StackList;
StackList *create_stack(){
	StackList *S;
	S=(StackList*)malloc(sizeof(StackList));
	if(S==NULL){
		printf("创建失败");exit(1); 
	}
	S->top=NULL;
	S->cnt=0;
	return S;
}
void 	Push_Stack(StackList *S,int x,int y){
	NODE *p;
	p=(NODE *)malloc(sizeof(NODE));
	if(p!=NULL){
		p->row=x;
		p->col=y;
		p->next=S->top;
		S->top=p;
		S->cnt++;
	}
} 
 void  Pop_Stack(StackList *S)
{
if (S->top != NULL)
{
NODE *s,*p;
s = S->top;
p=s->next;
free(s);
S->top = p;
S->cnt--;
}
}
int main(){
	int a[6][6]={{1,1,1,1,1,1},
				{1,0,1,1,1,1},
				{1,0,0,0,1,1},
				{1,0,0,0,0,1},
				{1,1,1,1,0,1},
				{1,1,1,1,1,1}};
	StackList  *S;	
	S=create_stack();
	int row=1;
	int col=1;
	int m=4;
	int n=4;
	int opx,opy;
	Push_Stack(S,row,col);
	NODE *p;
	while(S->top!=NULL){
		p=S->top;
		 opx=p->row;
		 opy=p->col;
		 if(opx==m&&opy==n){
		 	break;
		 }else if(a[opx-1][opy]==0){//上 
		 		Push_Stack(S,opx-1,opy);
		 		a[opx-1][opy]=2;
		 }
		 else if(a[opx][opy+1]==0){//右 
		 	Push_Stack(S,opx,opy+1);
		 		a[opx][opy+1]=2;
		 }
		  else if(a[opx+1][opy]==0){//下 
		 	Push_Stack(S,opx+1,opy);
		 		a[opx+1][opy]=2;
		 } else if(a[opx][opy-1]==0){//左 
		 	Push_Stack(S,opx,opy-1);
		 		a[opx][opy-1]=2;
		 }else{
		 	Pop_Stack(S);
		 	a[opx][opy]=3;
		 }
	}
	p=S->top;
	for(int i=0;i<S->cnt;i++){
		   printf("（%d，%d）\n", p->row, p->col);
p = p->next;//p每次循环完指向后继结点
	}
	if(S->cnt==0){
		printf("此迷宫不通路"); 
	}
	return 0;	
}
