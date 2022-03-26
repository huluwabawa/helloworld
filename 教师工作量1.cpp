#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define  head printf("编号\t姓名\t\t称号\t\t教授课程\t课程时长\t科研信息\t科研计分\t工作量\n");  
#define out 	printf("%-8d%-16s%-16s%-16s%-16d%-16s%-16d%-8.2f\n",te[i].num,te[i].name,te[i].age,te[i].course,te[i].hour,te[i].science,te[i].cent,te[i].work);
struct teacher//哪门课好多课时，科研信息记好多分 
{	int num;//编号 
	char name[10];
	char age[10];//级别 
	int hour;//这门课的课时 
	char course[20];//哪门课 
	char science[30];
	int cent;//科研信息计分 
	double  work;

}te[100];
int OpenFile()//获取人数 
{int i=0,cnt=0;
FILE *fp=NULL;
fp=fopen("C:\\Users\\HUAWEI\\Desktop\\teacher.txt","r+");
if(fp==NULL)
{
	printf("打开文件失败");
	exit(0);
	}
	while(!feof(fp)) 
	{
		if(fread(&te[i],sizeof(struct teacher),1,fp)==0)
		{
break;
		}
	i++;		  
	}
		cnt=i;
	return cnt;	
}
void save(int cnt)//保存 
{
	FILE * fp;
	int i;
	printf("开始保存记录.....\n");

	fp=fopen("C:\\Users\\HUAWEI\\Desktop\\teacher.txt","r+");
		for(i=0;i<cnt;i++)
		{
			fwrite(&te[i],sizeof(struct teacher),1,fp);
		}
		fclose(fp);
	
	
}
int addteacher(int cnt)
{
	int i=0,num;
	while(true){
		printf("请输入编号");
		scanf("%d",&num);
		for(int j=0;j<cnt;j++)
		{
			if(te[j].num==num)
			{
				printf("该编号已经存在");
				scanf("%d",&num);
				j=-1; 
			}
		 } 
		 te[i].num=num;
		 getchar();
		 printf("请输入教师姓名");
		 gets(te[i].name);
		 printf("请输入教师称号");
		 gets(te[i].age);
		 printf("请输入教师所教课程");
		 gets(te[i].course);
		 printf("请输入教师课程时长");
		 scanf("%d",&te[i].hour);
		 getchar(); 
		 printf("请输入科研信息");
		 gets(te[i].science);
		 printf("请输入科研计分(1~10分)"); 
		 scanf("%d",&te[i].cent);
		
		  te[i].work=0.8*te[i].hour+10*te[i].cent;
		 cnt++;i++;int n;
		
		 printf("是否继续添加 1.继续 2.退出");
		 scanf("%d",&n);
		 if(n!=1){
		 	break;
		 }
		 
	}
	save(cnt);
	return cnt;
}
int Location(int num,int cnt)//获取地址 
{
	int i,p=-1;
	for(i=0;i<cnt;i++)
	{
		if(num==te[i].num)
		{
			p=i;
			break;
		}
	}
	return p;
save(cnt);

}
void modify(int cnt)
{
	int num,i,p; 
	printf("请输入要修改的编号：");
	scanf("%d",&num);
	p=Location(num,cnt);
	if(p==-1)
	{
		printf("修改失败，记录不存在，"); 
	}
	else
	{i=p;
		printf("请输入编号"); 
		 scanf("%d",&te[i].num);
		 getchar();
		 printf("请输入教师姓名");
		 gets(te[i].name);
		 printf("请输入教师称号");
		 gets(te[i].age);
		 printf("请输入课程");
		 gets(te[i].course); 
		 printf("请输入教师课程时长");
		 scanf("%d",&te[i].hour);
		 getchar();
		 printf("请输入科研信息");
		 gets(te[i].science);
		 printf("请输入科研计分(1~10分)"); 
		 scanf("%d",&te[i].cent);
		 te[i].work=0.8*te[i].hour+10*(te[i].cent);
	}
	getchar();printf("按任意键返回主菜单....");getchar();
	save(cnt); 
}
 void output(int cnt){
	int i=0; 
	double average=0,sum=0; 
	for(i=0;i<cnt;i++){
	sum+=te[i].work;
	}
	average=(double)(sum/i);
printf("所有教师工作量:%.2f课时 \n教师平均工作量%.2f时\n",sum,average);
printf("教师个人工作量统计(0.8×课时+10×科研计分)\n");
head;
for(i=0;i<cnt;i++){
out;
}
getchar();
getchar();
}
int deleteteacher(int cnt) 
{
	int i,num,p;
	printf("开始删除记录.....");
	printf("请输入要删除的编号：");
	scanf("%d",&num);
	p=Location(num,cnt);
	if(p==-1)
	{
		printf("删除失败，教师信息不存在，"); 
	}
	else
	{
		i=p;
		printf("要删除的教师信息如下：\n\n");
	head;
out;
		for(;i<cnt-1;i++)
		{
			te[i]=te[i+1];
		}
		cnt--;	
	}
	getchar(); getchar();
	save(cnt);
		return cnt;
}
void Query(int cnt)//查询
{
	int num,i,choice,p,querycnt=0;
	char name[13];
	printf("开始查询记录.....");
	printf("请选择查询方式：(1 按编号  2 按姓名):");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("请输入要查询的编号：");
		scanf("%d",&num);
		p=Location(num,cnt);
		if(p==-1)
		{
			printf("查询失败，记录不存在，"); 
		}
		else
		{
			i=p;
			printf("查询成功，要查询的教师信息如下：\n");
			head;
			out; 
		}
	}
	else
	{
		getchar();
		printf("请输入要查询的教师：");
		gets(name);
		for(i=0;i<cnt;i++)
		{
			if(strcmp(name,te[i].name)==0)
			{
				if(querycnt==0)
				{
					head;
				}
				out; 
		}
				querycnt++;	
			}
		
		if(querycnt==0)
		{
			printf("查询失败，查询的教师不存在。");
		}
		
	}	
	
	getchar();
	getchar();
}
 void sort(int cnt){
int i,j,n;
teacher t;
printf("1(按编号),2(按工作量)");
scanf("%d",&n);
if(n==1){
for(i=0;i<cnt;i++){
 for(j=0;j<cnt-i-1;j++){
 	if(te[j].num>te[j+1].num){
	 t=te[j];
	 te[j]=te[j+1];
	 te[j+1]=t;
	 }
	 }
 }printf("排序成功");
} 	
else if(n==2){
for(i=0;i<cnt;i++){
 for(j=0;j<cnt-i-1;j++){
 	if(te[j].work>te[j+1].work){
	 t=te[j];
	 te[j]=te[j+1];
	 te[j+1]=t;
	 }
	 }
 }	
 printf("排序成功");
 
}
else{
	printf("输入错误");
}
getchar(); 
getchar(); 
}
 Menu(int cnt)
 {int n;
 	while(1)
 	{ 
 printf("         教师工作量管理系统\n");
printf("1.教师信息录入         2.查询教师工作量\n");
printf("3.教师信息修改         4.教师工作量统计结果输出\n");
printf("5.删除教师信息         6.教师信息排序\n");	
printf("0.退出系统\n");
scanf("%d",&n);
switch(n)
{   case 0:exit(0);break;
	case 1:cnt=addteacher(cnt);break;
	case 3:modify(cnt);break;
	case 4:output(cnt);break;
	case 5:cnt=deleteteacher(cnt);break;
	case 2: Query(cnt);break;
	case 6:sort(cnt);break;
	
}
system("cls");
}

}
int main()
{ 
int count=0;
count=OpenFile();
Menu(count);
	
	return 0;
}
