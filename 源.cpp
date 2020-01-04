#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"conio.h" 
typedef struct node
{
	char xh[11];	//ѧ��
	char xm[10];	//����
	char xb[3];		//�Ա�
	int nl;			//����
	char dh[12];	//�绰
	char jg[30];	//����
	float rxcj;		//�ɼ�
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
	printf("ѧ����Ϣ����ϵͳ\n");
	printf("---------------------\n");
	printf("1.ѧ����Ϣ¼��\n");
	printf("2.ѧ����Ϣ��ʾ\n");
	printf("3.ѧ����Ϣ��ѯ\n");
	printf("4.ѧ����Ϣ����\n");
	printf("5.ѧ����Ϣɾ��\n");
	printf("6.ѧ����Ϣ�޸�\n");
	printf("0.�˳�����ϵͳ\n");
	printf("---------------------\n");
	printf("���������ѡ��: ");
	//fflush(stdin);
	gets_s(ch);
	num1 = atoi(ch);   //���ַ���ת��Ϊint�͵�����
	return num1;
}
void add()
{
	student stu;
	FILE *fp;
	if ((fp = fopen("ѧ��������Ϣ.txt", "a")) == NULL)
	{
		printf("���ļ�ʧ�ܣ�");
	}
	
	printf("������ѧ����ѧ��:");
	scanf("%s", stu.xh);
	printf("������ѧ��������:");
	scanf("%s", stu.xm);
	printf("������ѧ�����Ա�:");
	scanf("%s", stu.xb);
	printf("������ѧ��������:");
	scanf("%d", &stu.nl);
	printf("������ѧ���ĵ绰:");
	scanf("%s", stu.dh);
	printf("������ѧ���ļ���:");
	scanf("%s", stu.jg);
	printf("������ѧ���ĳɼ�:");
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
	if ((fp = fopen("ѧ��������Ϣ.txt", "r")) == NULL)
	{
		printf("���ļ�ʧ�ܣ�");
	}
	printf("����ѧ����ѧ��  ����  �Ա�  ����  �绰  ����  ��ѧ�ɼ�:\n");
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
	system("mode con cols=100 lines=30");  //����ϵͳConsole����̨��ʾ�Ŀ�Ⱥ͸߶ȣ��߶�Ϊ30���ַ������Ϊ100���ַ�
	system("title ѧ����Ϣ����ϵͳ");	   //�����
	fflush(stdin);						   //������뻺����
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
		case 0:printf("�˳�\n"); exit(1); system("pause"); break;
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
	printf("\tѧ����Ϣ��ѯ\n");
	printf("\t------------------\n");
	printf("\t1.��ѧ�Ų�ѯ\n");
	printf("\t2.��������ѯ\n");
	printf("\t------------------\n");
	printf("���������ѡ��:");
	gets_s(ch);
	num1 = atoi(ch);
	if (num1 == 1)
	{
		if ((fp = fopen("ѧ��������Ϣ.txt", "r")) == NULL)
		{
			printf("���ļ�ʧ�ܣ�");
		}
		int i, n = 0;
		for (i = 0; fread(&stu[i], sizeof(student), 1, fp); i++)
		{
			n++;
		}
		fclose(fp);
		printf("������Ҫ��ѯ��ѧ�ţ�");
		gets_s(delxh);
		for (i = 0; i<n; i++)
		{
			if (!strcmp(stu[i].xh, delxh))
			{
				printf("��Ҫ��ѯ��ѧ��Ϊ��\n");
				printf("%s %s %s %d %s %s %6.2f\n", stu[i].xh, stu[i].xm, stu[i].xb, stu[i].nl, stu[i].dh, stu[i].jg, stu[i].rxcj);
				break;
			}
		}
	}
	else if (num1 == 2)
	{
		if ((fp = fopen("ѧ��������Ϣ.txt", "r")) == NULL)
		{
			printf("���ļ�ʧ�ܣ�");
		}
		int i, n = 0;
		for (i = 0; fread(&stu[i], sizeof(student), 1, fp); i++)
		{
			n++;
		}
		fclose(fp);
		printf("������Ҫ��ѯ��������");
		gets_s(delxh);
		for (i = 0; i<n; i++)
		{
			if (!strcmp(stu[i].xm, delxh))
			{
				printf("��Ҫ��ѯ��ѧ��Ϊ��\n");
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
	printf("\tѧ����Ϣ�޸�\n");
	printf("\t------------------\n");
	printf("\t1.��ѧ���޸�\n");
	printf("\t2.�������޸�\n");
	printf("\t------------------\n");
	printf("���������ѡ��:");
	gets_s(ch);
	num1 = atoi(ch);
	if (num1 == 1)
	{
		if ((fp = fopen("ѧ��������Ϣ.txt", "ab+")) == NULL)
		{
			printf("can not open\n");
			return;
		}
		while (!feof(fp))	//����ļ��Ƿ�ﵽŶĩβ����������ļ�ָ�뵽���ļ�ĩβ��EOF���򷵻� TRUE�����򷵻� FALSE��
			if (fread(&stu[m], sizeof(student), 1, fp) == 1)
				m++;
		if (m == 0)  
		{
			printf("no record!\n");
			fclose(fp);
			return;
		}
		printf("������Ҫ�޸ĵ�ѧ�ţ�\n");
		gets_s(updatexh);
		for (i = 0; i<m; i++)						// strcmp(const char *s1,const char *s2)
			if (!strcmp(stu[i].xh, updatexh))		// ��s1<s2ʱ������Ϊ��������s1=s2ʱ������ֵ= 0����s1>s2ʱ������������
			{
				printf("��Ҫ�޸ĵ�ѧ��Ϊ��\n");
				printf("%s %s %s %d %s %s %6.2f\n", stu[i].xh, stu[i].xm, stu[i].xb, stu[i].nl, stu[i].dh, stu[i].jg, stu[i].rxcj);
				break;
			}

		if (i<m)
		{
			printf("������ѧ��������:");
			scanf("%s", &stu[i].xm);
			printf("������ѧ�����Ա�:");
			scanf("%s", &stu[i].xb);
			printf("������ѧ��������:");
			scanf("%d", &stu[i].nl);
			printf("������ѧ���ĵ绰:");
			scanf("%s", &stu[i].dh);
			printf("������ѧ���ļ���:");
			scanf("%s", &stu[i].jg);
			printf("������ѧ���ĳɼ�:");
			scanf("%f", &stu[i].rxcj);
		}
		else
		{
			printf("can not find!");
			getchar();
			return;
		}
		if ((fp = fopen("ѧ��������Ϣ.txt", "wb")) == NULL)
		{
			printf("can not open\n");
			return;
		}
		for (j = 0; j<m; j++)//�����޸ĵ���Ϣд��ָ���Ĵ����ļ���
			if (fwrite(&stu[j], sizeof(student), 1, fp) != 1)	
												//����ɹ����ú�������һ�� size_t ���󣬱�ʾԪ�ص�������
												//�ö�����һ�������������͡������������ nmemb ������ͬ�������ʾһ������
			{
				printf("can not save!");
				_getch();	//һ�������Ժ���,�ӿ���̨��ȡһ���ַ���������ʾ����Ļ��
			}
		fclose(fp);
		getchar();					//���ջس�������ֱֹ������
		//fflush(stdin);				//û��
		//char c = getchar();		//�˴����ʣ�Ϊʲô��fflush(stdin) ���У����ǻ�ֱ���˳����򣬶���getchar(); �򲻻�
		//printf("---%c---", c);	//���Է�����һ���س�
		

	}
	else if (num1 == 2)
	{
		if ((fp = fopen("ѧ��������Ϣ.txt", "ab+")) == NULL)
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
		printf("������Ҫ�޸ĵ�������\n");
		gets_s(updatexh);
		for (i = 0; i<m; i++)
			if (!strcmp(stu[i].xm, updatexh))
			{
				printf("��Ҫ�޸ĵ�ѧ��Ϊ��\n");
				printf("%s %s %s %d %s %s %6.2f\n", stu[i].xh, stu[i].xm, stu[i].xb, stu[i].nl, stu[i].dh, stu[i].jg, stu[i].rxcj);
				break;
			}

		if (i<m)
		{
			printf("������ѧ����ѧ��:");
			scanf("%s", &stu[i].xh);
			printf("������ѧ�����Ա�:");
			scanf("%s", &stu[i].xb);
			printf("������ѧ��������:");
			scanf("%d", &stu[i].nl);
			printf("������ѧ���ĵ绰:");
			scanf("%s", &stu[i].dh);
			printf("������ѧ���ļ���:");
			scanf("%s", &stu[i].jg);
			printf("������ѧ���ĳɼ�:");
			scanf("%f", &stu[i].rxcj);
		}
		else
		{
			printf("can not find!");
			getchar();
			return;
		}
		if ((fp = fopen("ѧ��������Ϣ.txt", "wb")) == NULL)
		{
			printf("can not open\n");
			return;
		}
		for (j = 0; j<m; j++)//�����޸ĵ���Ϣд��ָ���Ĵ����ļ���
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
	printf("\tѧ����Ϣɾ��\n");
	printf("\t------------------\n");
	printf("\t1.��ѧ��ɾ��\n");
	printf("\t2.������ɾ��\n");
	printf("\t------------------\n");
	printf("���������ѡ��:");
	gets_s(ch);
	num1 = atoi(ch);
	if (num1 == 1)
	{
		if ((fp = fopen("ѧ��������Ϣ.txt", "r")) == NULL)
		{
			printf("���ļ�ʧ�ܣ�");
		}
		int i, j, n = 0;
		for (i = 0; fread(&stu[i], sizeof(student), 1, fp); i++)
		{
			n++;
		}
		fclose(fp);
		printf("������Ҫɾ����ѧ�ţ�");
		gets_s(delxh);
		for (i = 0; i<n; i++)
		{
			if (!strcmp(stu[i].xh, delxh))
			{
				printf("��Ҫɾ����ѧ��Ϊ��\n");
				printf("%s %s %s %d %s %s %6.2f\n", stu[i].xh, stu[i].xm, stu[i].xb, stu[i].nl, stu[i].dh, stu[i].jg, stu[i].rxcj);
				break;
			}
		}
		if (i == n)
		{
			printf("��Ҫɾ����ѧ��û���ҵ���\n");
		}
		else
		{
			char ch;
			printf("���Ƿ�ɾ��(y/n)��\n");
			ch = getchar();
			getchar();
			if (ch == 'y' || ch == 'Y')
			{
				for (j = i; j<n; j++)
					stu[j] = stu[j + 1];
				n--;
				if ((fp = fopen("ѧ��������Ϣ.txt", "w")) == NULL)
				{
					printf("���ļ�ʧ�ܣ�");
				}
				else
				{
					for (i = 0; i<n; i++)
					{
						fwrite(stu, sizeof(student), 1, fp);
					}
					fclose(fp);
					printf("ɾ���ɹ���\n");
				}
			}
		}

	}
	if (num1 == 2)
	{
		if ((fp = fopen("ѧ��������Ϣ.txt", "r")) == NULL)
		{
			printf("���ļ�ʧ�ܣ�");
		}
		int i, j, n = 0;
		for (i = 0; fread(&stu[i], sizeof(student), 1, fp); i++)
		{
			n++;
		}
		fclose(fp);
		printf("������Ҫɾ����������");
		gets_s(delxh);
		for (i = 0; i<n; i++)
		{
			if (!strcmp(stu[i].xm, delxh))
			{
				printf("��Ҫɾ����ѧ��Ϊ��\n");
				printf("%s %s %s %d %s %s %6.2f\n", stu[i].xh, stu[i].xm, stu[i].xb, stu[i].nl, stu[i].dh, stu[i].jg, stu[i].rxcj);
				break;
			}
		}
		if (i == n)
		{
			printf("��Ҫɾ����ѧ��û���ҵ���\n");
		}
		else
		{
			char ch;
			printf("���Ƿ�ɾ��(y/Y)��\n");
			ch = getchar();
			getchar();
			if (ch == 'y' || ch == 'Y')
			{
				for (j = i; j<n; j++)
					stu[j] = stu[j + 1];
				n--;
				if ((fp = fopen("ѧ��������Ϣ.txt", "w")) == NULL)
				{
					printf("���ļ�ʧ�ܣ�");
				}
				else
				{
					for (i = 0; i<n; i++)
					{
						fwrite(&stu, sizeof(student), 1, fp);
					}
					fclose(fp);
					printf("ɾ���ɹ���\n");
				}
			}
		}

	}
}






void sort()
{
	student stu[45];
	FILE *fp;
	if ((fp = fopen("ѧ��������Ϣ.txt", "r")) == NULL)
	{
		printf("����ǰ�����ݣ�\n");
	}
	printf("����ѧ����ѧ��  ����  �Ա�  ����  �绰  ����  ��ѧ�ɼ�:\n");
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
	printf("\n\n���������ݣ�\n");
	printf("����ѧ����ѧ��  ����  �Ա�  ����  �绰  ����  ��ѧ�ɼ�:\n");
	for (i = 0; i<n; i++)
	{
		printf("%s  %s  %s  %d  %s  %s  %f\n", stu[i].xh, stu[i].xm, stu[i].xb, stu[i].nl, stu[i].dh, stu[i].jg, stu[i].rxcj);
	}
	FILE *fp1;
	if ((fp1 = fopen("ѧ��������Ϣ.txt", "w")) == NULL)
	{
		printf("���ļ�ʧ��!");
	}
}