#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define  head printf("���\t����\t\t�ƺ�\t\t���ڿγ�\t�γ�ʱ��\t������Ϣ\t���мƷ�\t������\n");  
#define out 	printf("%-8d%-16s%-16s%-16s%-16d%-16s%-16d%-8.2f\n",te[i].num,te[i].name,te[i].age,te[i].course,te[i].hour,te[i].science,te[i].cent,te[i].work);
struct teacher//���ſκö��ʱ��������Ϣ�Ǻö�� 
{	int num;//��� 
	char name[10];
	char age[10];//���� 
	int hour;//���ſεĿ�ʱ 
	char course[20];//���ſ� 
	char science[30];
	int cent;//������Ϣ�Ʒ� 
	double  work;

}te[100];
int OpenFile()//��ȡ���� 
{int i=0,cnt=0;
FILE *fp=NULL;
fp=fopen("C:\\Users\\HUAWEI\\Desktop\\teacher.txt","r+");
if(fp==NULL)
{
	printf("���ļ�ʧ��");
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
void save(int cnt)//���� 
{
	FILE * fp;
	int i;
	printf("��ʼ�����¼.....\n");

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
		printf("��������");
		scanf("%d",&num);
		for(int j=0;j<cnt;j++)
		{
			if(te[j].num==num)
			{
				printf("�ñ���Ѿ�����");
				scanf("%d",&num);
				j=-1; 
			}
		 } 
		 te[i].num=num;
		 getchar();
		 printf("�������ʦ����");
		 gets(te[i].name);
		 printf("�������ʦ�ƺ�");
		 gets(te[i].age);
		 printf("�������ʦ���̿γ�");
		 gets(te[i].course);
		 printf("�������ʦ�γ�ʱ��");
		 scanf("%d",&te[i].hour);
		 getchar(); 
		 printf("�����������Ϣ");
		 gets(te[i].science);
		 printf("��������мƷ�(1~10��)"); 
		 scanf("%d",&te[i].cent);
		
		  te[i].work=0.8*te[i].hour+10*te[i].cent;
		 cnt++;i++;int n;
		
		 printf("�Ƿ������� 1.���� 2.�˳�");
		 scanf("%d",&n);
		 if(n!=1){
		 	break;
		 }
		 
	}
	save(cnt);
	return cnt;
}
int Location(int num,int cnt)//��ȡ��ַ 
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
	printf("������Ҫ�޸ĵı�ţ�");
	scanf("%d",&num);
	p=Location(num,cnt);
	if(p==-1)
	{
		printf("�޸�ʧ�ܣ���¼�����ڣ�"); 
	}
	else
	{i=p;
		printf("��������"); 
		 scanf("%d",&te[i].num);
		 getchar();
		 printf("�������ʦ����");
		 gets(te[i].name);
		 printf("�������ʦ�ƺ�");
		 gets(te[i].age);
		 printf("������γ�");
		 gets(te[i].course); 
		 printf("�������ʦ�γ�ʱ��");
		 scanf("%d",&te[i].hour);
		 getchar();
		 printf("�����������Ϣ");
		 gets(te[i].science);
		 printf("��������мƷ�(1~10��)"); 
		 scanf("%d",&te[i].cent);
		 te[i].work=0.8*te[i].hour+10*(te[i].cent);
	}
	getchar();printf("��������������˵�....");getchar();
	save(cnt); 
}
 void output(int cnt){
	int i=0; 
	double average=0,sum=0; 
	for(i=0;i<cnt;i++){
	sum+=te[i].work;
	}
	average=(double)(sum/i);
printf("���н�ʦ������:%.2f��ʱ \n��ʦƽ��������%.2fʱ\n",sum,average);
printf("��ʦ���˹�����ͳ��(0.8����ʱ+10�����мƷ�)\n");
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
	printf("��ʼɾ����¼.....");
	printf("������Ҫɾ���ı�ţ�");
	scanf("%d",&num);
	p=Location(num,cnt);
	if(p==-1)
	{
		printf("ɾ��ʧ�ܣ���ʦ��Ϣ�����ڣ�"); 
	}
	else
	{
		i=p;
		printf("Ҫɾ���Ľ�ʦ��Ϣ���£�\n\n");
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
void Query(int cnt)//��ѯ
{
	int num,i,choice,p,querycnt=0;
	char name[13];
	printf("��ʼ��ѯ��¼.....");
	printf("��ѡ���ѯ��ʽ��(1 �����  2 ������):");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("������Ҫ��ѯ�ı�ţ�");
		scanf("%d",&num);
		p=Location(num,cnt);
		if(p==-1)
		{
			printf("��ѯʧ�ܣ���¼�����ڣ�"); 
		}
		else
		{
			i=p;
			printf("��ѯ�ɹ���Ҫ��ѯ�Ľ�ʦ��Ϣ���£�\n");
			head;
			out; 
		}
	}
	else
	{
		getchar();
		printf("������Ҫ��ѯ�Ľ�ʦ��");
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
			printf("��ѯʧ�ܣ���ѯ�Ľ�ʦ�����ڡ�");
		}
		
	}	
	
	getchar();
	getchar();
}
 void sort(int cnt){
int i,j,n;
teacher t;
printf("1(�����),2(��������)");
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
 }printf("����ɹ�");
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
 printf("����ɹ�");
 
}
else{
	printf("�������");
}
getchar(); 
getchar(); 
}
 Menu(int cnt)
 {int n;
 	while(1)
 	{ 
 printf("         ��ʦ����������ϵͳ\n");
printf("1.��ʦ��Ϣ¼��         2.��ѯ��ʦ������\n");
printf("3.��ʦ��Ϣ�޸�         4.��ʦ������ͳ�ƽ�����\n");
printf("5.ɾ����ʦ��Ϣ         6.��ʦ��Ϣ����\n");	
printf("0.�˳�ϵͳ\n");
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
