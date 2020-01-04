#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"conio.h" 
typedef struct node
{
	char xh[11];	//学号
	char xm[10];	//姓名
	char xb[3];		//性别
	int nl;			//年龄
	char dh[12];	//电话
	char jg[30];	//籍贯
	float rxcj;		//成绩
}student;
int menu();
void add();
void display();
void dele();
void sort();
void update();
void search();

int menu()
{
	system("cls");
	char ch[2]; int num1;
	printf("学生信息管理系统\n");
	printf("---------------------\n");
	printf("1.学生信息录入\n");
	printf("2.学生信息显示\n");
	printf("3.学生信息查询\n");
	printf("4.学生信息排序\n");
	printf("5.学生信息删除\n");
	printf("6.学生信息修改\n");
	printf("0.退出管理系统\n");
	printf("---------------------\n");
	printf("请输入你的选择: ");
	//fflush(stdin);
	gets_s(ch);
	num1 = atoi(ch);   //将字符串转化为int型的数字
	return num1;
}
void add()
{
	student stu;
	FILE *fp;
	if ((fp = fopen("学生基本信息.txt", "a")) == NULL)
	{
		printf("打开文件失败！");
	}
	
	printf("请输入学生的学号:");
	scanf("%s", stu.xh);
	printf("请输入学生的姓名:");
	scanf("%s", stu.xm);
	printf("请输入学生的性别:");
	scanf("%s", stu.xb);
	printf("请输入学生的年龄:");
	scanf("%d", &stu.nl);
	printf("请输入学生的电话:");
	scanf("%s", stu.dh);
	printf("请输入学生的籍贯:");
	scanf("%s", stu.jg);
	printf("请输入学生的成绩:");
	scanf("%f", &stu.rxcj);
	fwrite(&stu, sizeof(student), 1, fp);
	fclose(fp);
	//fflush(stdin);
	getchar();
}
void display()
{
	student stu[20];
	FILE *fp;
	if ((fp = fopen("学生基本信息.txt", "r")) == NULL)
	{
		printf("打开文件失败！");
	}
	printf("输入学生的学号  姓名  性别  年龄  电话  籍贯  入学成绩:\n");
	int i, n = 0;
	for (i = 0; fread(&stu[i], sizeof(student), 1, fp); i++)
	{
		n++;
	}
	for (i = 0; i<n; i++)
	{
		printf("%s  %s  %s  %d  %s  %s  %f\n", stu[i].xh, stu[i].xm, stu[i].xb, stu[i].nl, stu[i].dh, stu[i].jg, stu[i].rxcj);
	}
	fclose(fp);
}
void main(void)
{
	int num;
	system("color F9");
	system("cls");
	system("mode con cols=100 lines=30");  //调整系统Console控制台显示的宽度和高度，高度为30个字符，宽度为100个字符
	system("title 学生信息管理系统");	   //起标题
	fflush(stdin);						   //清空输入缓冲区
	do
	{
		num = menu();
		switch (num)
		{
		case 1:add(); system("pause"); break;
		case 2:display(); system("pause"); break;
		case 3:search(); system("pause"); break;
		case 4:sort(); system("pause"); break;
		case 5:dele(); system("pause"); break;
		case 6:update(); system("pause"); break;
		case 0:printf("退出\n"); exit(1); system("pause"); break;
			exit(1); break;
		}
	} while (1);
}
void search()
{
	system("cls");
	FILE *fp;
	char delxh[11];
	student stu[45];
	char ch[2]; int num1;
	printf("\t学生信息查询\n");
	printf("\t------------------\n");
	printf("\t1.按学号查询\n");
	printf("\t2.按姓名查询\n");
	printf("\t------------------\n");
	printf("请输入你的选择:");
	gets_s(ch);
	num1 = atoi(ch);
	if (num1 == 1)
	{
		if ((fp = fopen("学生基本信息.txt", "r")) == NULL)
		{
			printf("打开文件失败！");
		}
		int i, n = 0;
		for (i = 0; fread(&stu[i], sizeof(student), 1, fp); i++)
		{
			n++;
		}
		fclose(fp);
		printf("请输入要查询的学号：");
		gets_s(delxh);
		for (i = 0; i<n; i++)
		{
			if (!strcmp(stu[i].xh, delxh))
			{
				printf("你要查询的学生为：\n");
				printf("%s %s %s %d %s %s %6.2f\n", stu[i].xh, stu[i].xm, stu[i].xb, stu[i].nl, stu[i].dh, stu[i].jg, stu[i].rxcj);
				break;
			}
		}
	}
	else if (num1 == 2)
	{
		if ((fp = fopen("学生基本信息.txt", "r")) == NULL)
		{
			printf("打开文件失败！");
		}
		int i, n = 0;
		for (i = 0; fread(&stu[i], sizeof(student), 1, fp); i++)
		{
			n++;
		}
		fclose(fp);
		printf("请输入要查询的姓名：");
		gets_s(delxh);
		for (i = 0; i<n; i++)
		{
			if (!strcmp(stu[i].xm, delxh))
			{
				printf("你要查询的学生为：\n");
				printf("%s %s %s %d %s %s %6.2f\n", stu[i].xh, stu[i].xm, stu[i].xb, stu[i].nl, stu[i].dh, stu[i].jg, stu[i].rxcj);
				break;
			}
		}
	}
}
void update()
{
	system("cls");
	FILE *fp;
	int i, j, m = 0, snum;
	student stu[45];
	char ch[2]; int num1;
	char updatexh[11];
	printf("\t学生信息修改\n");
	printf("\t------------------\n");
	printf("\t1.按学号修改\n");
	printf("\t2.按姓名修改\n");
	printf("\t------------------\n");
	printf("请输入你的选择:");
	gets_s(ch);
	num1 = atoi(ch);
	if (num1 == 1)
	{
		if ((fp = fopen("学生基本信息.txt", "ab+")) == NULL)
		{
			printf("can not open\n");
			return;
		}
		while (!feof(fp))	//检测文件是否达到哦末尾，出错或者文件指针到了文件末尾（EOF）则返回 TRUE，否则返回 FALSE。
			if (fread(&stu[m], sizeof(student), 1, fp) == 1)
				m++;
		if (m == 0)  
		{
			printf("no record!\n");
			fclose(fp);
			return;
		}
		printf("请输入要修改的学号：\n");
		gets_s(updatexh);
		for (i = 0; i<m; i++)						// strcmp(const char *s1,const char *s2)
			if (!strcmp(stu[i].xh, updatexh))		// 当s1<s2时，返回为负数；当s1=s2时，返回值= 0；当s1>s2时，返回正数。
			{
				printf("你要修改的学生为：\n");
				printf("%s %s %s %d %s %s %6.2f\n", stu[i].xh, stu[i].xm, stu[i].xb, stu[i].nl, stu[i].dh, stu[i].jg, stu[i].rxcj);
				break;
			}

		if (i<m)
		{
			printf("请输入学生的姓名:");
			scanf("%s", &stu[i].xm);
			printf("请输入学生的性别:");
			scanf("%s", &stu[i].xb);
			printf("请输入学生的年龄:");
			scanf("%d", &stu[i].nl);
			printf("请输入学生的电话:");
			scanf("%s", &stu[i].dh);
			printf("请输入学生的籍贯:");
			scanf("%s", &stu[i].jg);
			printf("请输入学生的成绩:");
			scanf("%f", &stu[i].rxcj);
		}
		else
		{
			printf("can not find!");
			getchar();
			return;
		}
		if ((fp = fopen("学生基本信息.txt", "wb")) == NULL)
		{
			printf("can not open\n");
			return;
		}
		for (j = 0; j<m; j++)//将新修改的信息写入指定的磁盘文件中
			if (fwrite(&stu[j], sizeof(student), 1, fp) != 1)	
												//如果成功，该函数返回一个 size_t 对象，表示元素的总数，
												//该对象是一个整型数据类型。如果该数字与 nmemb 参数不同，则会显示一个错误
			{
				printf("can not save!");
				_getch();	//一个不回显函数,从控制台读取一个字符，但不显示在屏幕上
			}
		fclose(fp);
		getchar();					//接收回车符，防止直接跳出
		//fflush(stdin);				//没用
		//char c = getchar();		//此处疑问，为什么用fflush(stdin) 不行，还是会直接退出程序，而用getchar(); 则不会
		//printf("---%c---", c);	//测试发现是一个回车
		

	}
	else if (num1 == 2)
	{
		if ((fp = fopen("学生基本信息.txt", "ab+")) == NULL)
		{
			printf("can not open\n");
			return;
		}
		while (!feof(fp))
			if (fread(&stu[m], sizeof(student), 1, fp) == 1)
				m++;
		if (m == 0)
		{
			printf("no record!\n");
			fclose(fp);
			return;
		}
		printf("请输入要修改的姓名：\n");
		gets_s(updatexh);
		for (i = 0; i<m; i++)
			if (!strcmp(stu[i].xm, updatexh))
			{
				printf("你要修改的学生为：\n");
				printf("%s %s %s %d %s %s %6.2f\n", stu[i].xh, stu[i].xm, stu[i].xb, stu[i].nl, stu[i].dh, stu[i].jg, stu[i].rxcj);
				break;
			}

		if (i<m)
		{
			printf("请输入学生的学号:");
			scanf("%s", &stu[i].xh);
			printf("请输入学生的性别:");
			scanf("%s", &stu[i].xb);
			printf("请输入学生的年龄:");
			scanf("%d", &stu[i].nl);
			printf("请输入学生的电话:");
			scanf("%s", &stu[i].dh);
			printf("请输入学生的籍贯:");
			scanf("%s", &stu[i].jg);
			printf("请输入学生的成绩:");
			scanf("%f", &stu[i].rxcj);
		}
		else
		{
			printf("can not find!");
			getchar();
			return;
		}
		if ((fp = fopen("学生基本信息.txt", "wb")) == NULL)
		{
			printf("can not open\n");
			return;
		}
		for (j = 0; j<m; j++)//将新修改的信息写入指定的磁盘文件中
			if (fwrite(&stu[j], sizeof(student), 1, fp) != 1)
			{
				printf("can not save!");
				_getch();
			}
		fclose(fp);
	}

}

void dele()
{
	system("cls");
	FILE *fp;
	char delxh[11];
	student stu[45];
	char ch[2]; int num1;
	printf("\t学生信息删除\n");
	printf("\t------------------\n");
	printf("\t1.按学号删除\n");
	printf("\t2.按姓名删除\n");
	printf("\t------------------\n");
	printf("请输入你的选择:");
	gets_s(ch);
	num1 = atoi(ch);
	if (num1 == 1)
	{
		if ((fp = fopen("学生基本信息.txt", "r")) == NULL)
		{
			printf("打开文件失败！");
		}
		int i, j, n = 0;
		for (i = 0; fread(&stu[i], sizeof(student), 1, fp); i++)
		{
			n++;
		}
		fclose(fp);
		printf("请输入要删除的学号：");
		gets_s(delxh);
		for (i = 0; i<n; i++)
		{
			if (!strcmp(stu[i].xh, delxh))
			{
				printf("你要删除的学生为：\n");
				printf("%s %s %s %d %s %s %6.2f\n", stu[i].xh, stu[i].xm, stu[i].xb, stu[i].nl, stu[i].dh, stu[i].jg, stu[i].rxcj);
				break;
			}
		}
		if (i == n)
		{
			printf("你要删除的学生没有找到！\n");
		}
		else
		{
			char ch;
			printf("你是否删除(y/n)？\n");
			ch = getchar();
			getchar();
			if (ch == 'y' || ch == 'Y')
			{
				for (j = i; j<n; j++)
					stu[j] = stu[j + 1];
				n--;
				if ((fp = fopen("学生基本信息.txt", "w")) == NULL)
				{
					printf("打开文件失败！");
				}
				else
				{
					for (i = 0; i<n; i++)
					{
						fwrite(stu, sizeof(student), 1, fp);
					}
					fclose(fp);
					printf("删除成功！\n");
				}
			}
		}

	}
	if (num1 == 2)
	{
		if ((fp = fopen("学生基本信息.txt", "r")) == NULL)
		{
			printf("打开文件失败！");
		}
		int i, j, n = 0;
		for (i = 0; fread(&stu[i], sizeof(student), 1, fp); i++)
		{
			n++;
		}
		fclose(fp);
		printf("请输入要删除的姓名：");
		gets_s(delxh);
		for (i = 0; i<n; i++)
		{
			if (!strcmp(stu[i].xm, delxh))
			{
				printf("你要删除的学生为：\n");
				printf("%s %s %s %d %s %s %6.2f\n", stu[i].xh, stu[i].xm, stu[i].xb, stu[i].nl, stu[i].dh, stu[i].jg, stu[i].rxcj);
				break;
			}
		}
		if (i == n)
		{
			printf("你要删除的学生没有找到！\n");
		}
		else
		{
			char ch;
			printf("你是否删除(y/Y)？\n");
			ch = getchar();
			getchar();
			if (ch == 'y' || ch == 'Y')
			{
				for (j = i; j<n; j++)
					stu[j] = stu[j + 1];
				n--;
				if ((fp = fopen("学生基本信息.txt", "w")) == NULL)
				{
					printf("打开文件失败！");
				}
				else
				{
					for (i = 0; i<n; i++)
					{
						fwrite(&stu, sizeof(student), 1, fp);
					}
					fclose(fp);
					printf("删除成功！\n");
				}
			}
		}

	}
}






void sort()
{
	student stu[45];
	FILE *fp;
	if ((fp = fopen("学生基本信息.txt", "r")) == NULL)
	{
		printf("排序前的数据！\n");
	}
	printf("输入学生的学号  姓名  性别  年龄  电话  籍贯  入学成绩:\n");
	int i, n = 0;
	for (i = 0; fread(&stu[i], sizeof(student), 1, fp); i++)
	{
		n++;
	}
	for (i = 0; i<n; i++)
	{
		printf("%s  %s  %s  %d  %s  %s  %f\n", stu[i].xh, stu[i].xm, stu[i].xb, stu[i].nl, stu[i].dh, stu[i].jg, stu[i].rxcj);
	}
	fclose(fp);
	int j;
	student temp;
	for (i = 0; i<n - 1; i++)
		for (j = 0; j<n - 1 - i; j++)
			if (stu[j].rxcj<stu[j + 1].rxcj)
			{
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
	printf("\n\n排序后的数据！\n");
	printf("输入学生的学号  姓名  性别  年龄  电话  籍贯  入学成绩:\n");
	for (i = 0; i<n; i++)
	{
		printf("%s  %s  %s  %d  %s  %s  %f\n", stu[i].xh, stu[i].xm, stu[i].xb, stu[i].nl, stu[i].dh, stu[i].jg, stu[i].rxcj);
	}
	FILE *fp1;
	if ((fp1 = fopen("学生基本信息.txt", "w")) == NULL)
	{
		printf("打开文件失败!");
	}
}