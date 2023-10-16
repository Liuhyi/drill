//
// Created by Administrator on 2023/8/27.
//
#include <windows.h>
#include<assert.h>
#include <stdio.h>
#include <stdlib.h>
#define INITIAL_SIZE 3
#define MAX_NAME 40
#define MAX_GENDER 6
#define MAX_PHONE 20
#define MAX_ADDRESS 50
#define INCREMENT_SIZE 2

enum operator_list{
    EXIT,
    ADD,
    DEL,
    MODIFY,
    DISPLAY,
    SORT,
    FIND
};

typedef struct contact_info{
    char name[MAX_NAME];
    char gender[MAX_GENDER];
    int age;
    char phone[MAX_PHONE];
    char address[MAX_ADDRESS];
} contact;

typedef struct contacts_info{
    contact* members;
    size_t count;
    size_t capacity;
} contacts_info;

void operator_menu();
void initialize_contacts(contacts_info* contacts);
int add_contact(contacts_info* contacts);
void display_contacts(const contacts_info* contacts);
int save_contacts(const contacts_info* contacts);
int del_contact(contacts_info* contacts);
int find_contact_by_name(contacts_info* contacts, const char* name);
void find_contact(contacts_info* contacts);
int modify_contact(contacts_info* contacts);
int sort_contacts(contacts_info* contacts);
void destory_contacts(contacts_info* contacts);


int main(){
    int operator = -1;
    contacts_info contacts;
    initialize_contacts(&contacts);
    while(operator)
    {
        operator_menu();
        printf("��ѡ��Ҫִ�еĲ���:");
        scanf("%d", &operator);
        while(getchar() != '\n');
        switch (operator) {
            case ADD:
                add_contact(&contacts);
                break;
            case DEL:
                del_contact(&contacts);
                break;
            case MODIFY:
                modify_contact(&contacts);
                break;
            case DISPLAY:
                display_contacts(&contacts);
                break;
            case SORT:
                sort_contacts(&contacts);
                break;
            case FIND:
                find_contact(&contacts);
                break;
            case EXIT:
                save_contacts(&contacts);
                destory_contacts(&contacts);
                printf("�����˳�");
                Sleep(2000);
                break;
            default:
                printf("��������,����������\n");
                break;
        }


    }
    return 0;
}

int custom_strcmp(const char* front , const char* back)
{
    while((*front == *back) && *front)
    {
        front++;
        back++;
    }
    return *front - *back;
}

int find_contact_by_name(contacts_info* contacts, const char* name)
{
    for(int i = 0; i < contacts->count; i++)
    {
        if(custom_strcmp(name, contacts->members[i].name) == 0)
            return i;
    }
    return -1;

}

int modify_contact(contacts_info* contacts)
{
    if(contacts -> count == 0)
    {
        printf("ͨѶ¼Ϊ��,�޷��޸�,���������ϵ��\n");
        return -1;
    }
    char name[MAX_NAME];
    printf("������Ҫ�޸���ϵ�˵�����:");
    scanf("%s",name);
    int pos = find_contact_by_name(contacts, name);
    if (pos == -1)
    {
        printf("��ϵ�˲�����\n");
        return -1;
    }
    else
    {
        printf("������������ϵ������:");
        scanf("%s", contacts->members[pos].name);
        while(getchar() != '\n');
        printf("������������ϵ���Ա�:");
        scanf("%s", contacts->members[pos].gender);
        while(getchar() != '\n');
        printf("������������ϵ������:");
        scanf("%d", &contacts->members[pos].age);
        while(getchar() != '\n');
        printf("������������ϵ�˵绰:");
        scanf("%s", contacts->members[pos].phone);
        while(getchar() != '\n');
        printf("������������ϵ��סַ:");
        scanf("%s", contacts->members[pos].address);
        while(getchar() != '\n');
        printf("�޸ĳɹ�\n");
        return 0;
    }

}
int rasie_capacity(contacts_info* contacts)
{
    assert(contacts);
    if(contacts->count == contacts->capacity)
    {
        contact* data = (contact*)realloc(contacts->members,(contacts->capacity + INCREMENT_SIZE) * sizeof(contact));
        if(data == NULL)
        {
            perror("���ݴ���:\n");
            return 1;
        }
        else
        {
            contacts->members = data;
            contacts->capacity = contacts->capacity + INCREMENT_SIZE;
        }
    }
    return 0;
}

void find_contact(contacts_info* contacts)
{
    if(contacts -> count == 0)
    {
        printf("ͨѶ¼Ϊ��,�޷���ѯ,���������ϵ��\n");
        return;
    }
    char name[MAX_NAME];
    printf("������Ҫ������ϵ�˵�����:");
    scanf("%s",name);
    int pos = find_contact_by_name(contacts, name);
    if (pos == -1)
    {
        printf("��ϵ�˲�����\n");
    }
    else
    {
        printf("%-10s\t%-9s\t%-9s\t%-20s\t%-30s\n","�� ��:","�Ա�:","����:","�绰:","סַ:");
        printf("%-10s\t%-9s\t%-9d\t%-20s\t%-30s\n",
               contacts->members[pos].name,
               contacts->members[pos].gender,
               contacts->members[pos].age,
               contacts->members[pos].phone,
               contacts->members[pos].address
        );
        printf("���ҳɹ�\n");
    }
}
void initialize_contacts(contacts_info* contacts)
{
    assert(contacts);
    contacts->members = (contact*)calloc(INITIAL_SIZE, sizeof (contact));
    if(contacts->members == NULL)
    {
        perror("��ʼ��ʧ��:");
        exit(-1);
    }
    contacts-> count = 0;
    contacts-> capacity = INITIAL_SIZE;
    FILE* read = fopen("contacts_list.txt", "r");
    if(read && fgetc(read) != EOF)
    {
        while(fgetc(read) != '\n');
        while((fscanf(read,"%s%s%d%s%s\n", contacts->members[contacts->count].name,
                  contacts->members[contacts->count].gender,
                  &(contacts->members[contacts->count].age),
                  contacts->members[contacts->count].phone,
                  contacts->members[contacts->count].address)) != EOF)
        {
            contacts->count++;
            rasie_capacity(contacts);

        }

    }

}

void operator_menu()
{
 printf("**********************************************************************\n");
 printf("****************  1,�����ϵ��            2,ɾ����ϵ��********************\n");
 printf("****************  3,�޸���ϵ��            4,��ʾ������ϵ��*****************\n");
 printf("****************  5,������ϵ��            6,������ϵ��********************\n");
 printf("************************ 0,�˳����� ************************************\n");
 printf("**********************************************************************\n");
}


int add_contact(contacts_info* contacts)
{
    rasie_capacity(contacts);
    printf("��������ϵ������:");
    scanf("%s", contacts->members[contacts->count].name);
    while(getchar() != '\n');
    printf("��������ϵ���Ա�:");
    scanf("%s", contacts->members[contacts->count].gender);
    while(getchar() != '\n');
    printf("��������ϵ������:");
    scanf("%d", &contacts->members[contacts->count].age);
    while(getchar() != '\n');
    printf("��������ϵ�˵绰:");
    scanf("%s", contacts->members[contacts->count].phone);
    while(getchar() != '\n');
    printf("��������ϵ��סַ:");
    scanf("%s", contacts->members[contacts->count].address);
    while(getchar() != '\n');
    contacts->count++;
    printf("��ӳɹ�\n");
    return 1;
}

void display_contacts(const contacts_info* contacts)
{
    if(contacts->count == 0)
    {
        printf("ͨѶ¼Ϊ��\n");
        return;
    }
    printf("%-10s\t%-9s\t%-9s\t%-20s\t%-30s\n","�� ��:","�Ա�:","����:","�绰:","סַ:");
    for (int i = 0; i < contacts->count; i++)
    {
        printf("%-10s\t%-9s\t%-9d\t%-20s\t%-30s\n",
                                                           contacts->members[i].name,
                                                           contacts->members[i].gender,
                                                           contacts->members[i].age,
                                                           contacts->members[i].phone,
                                                           contacts->members[i].address
        );
    }
}

int save_contacts(const contacts_info* contacts)
{
    char next;
    printf("�Ƿ񱣴��޸�:y/n\n");
    scanf("%c", &next);
    while(getchar() != '\n');
    if(next == 'y')
    {
        FILE* file = fopen("contacts_list.txt", "w");
        if(file)
        {
            fprintf(file,"%-20s%-20s%-20s%-20s%-30s\n","����:","�Ա�:","����:","�绰:","סַ:");
            for(int i = 0; i < contacts->count; i++)
            {
                fprintf(file,"%-20s%-20s%-20d%-20s%-30s\n", contacts->members[i].name,
                        contacts->members[i].gender,
                        contacts->members[i].age,
                        contacts->members[i].phone,
                        contacts->members[i].address);
            }
            printf("�ļ��ѱ�����contacts_list.txt\n");
        }
        else
        {
            perror("�ļ���ʧ��:");
            return 1;
        }
    }
    return 0;
}

int del_contact(contacts_info* contacts)
{
    assert(contacts);
    if (contacts->count == 0)
    {
        printf("����Ϊ��,�޷�ɾ��,���������ϵ��");
        return -1;
    }
    else
    {   char name[MAX_NAME];
        printf("������Ҫɾ����ϵ�˵�����:");
        scanf("%s",name);
        while(getchar() != '\n');
        int pos = find_contact_by_name(contacts, name);
        if(pos == -1)
        {
            printf("��ϵ�˲�����\n");
            return -1;
        }
        else
        {
            for (int i = pos;i < contacts->count - 1; i++)
            {
                contacts->members[i] = contacts->members[i+1];
            }
            contacts->count--;
            printf("ɾ���ɹ�\n");
            return 0;
        }
    }
}

int name_ascend( void* front , void* back)
{
    return custom_strcmp(((contact*)front)->name,((contact*)back)->name);
}

int name_descend(void* front1 , void* back1)
{
    return custom_strcmp(((contact*)back1)->name,((contact*)front1)->name);
}

int age_asend( void* front , void* back)
{
    return ((contact*)front)->age - ((contact*)back)->age;
}

int age_descend( void* front , void* back)
{
    return ((contact*)back)->age - ((contact*)front)->age;
}

void swap(char* element1, char* element2, int width)
{
    while (width--) {
        char temp = *element1;
        *element1 = *element2;
        *element2 = temp;
        element1++;
        element2++;
    }
}


void bubble_qsort(void* base, int size, int width, int (*compare) (void* element1, void* element2))
{
    for (int i = 0; i < size-1; i++)
    {
        int flag = 1;
        for ( int j = 0; j < size -1-i; j++)
        {
            if (compare((char*)base + j * width, (char*)base + (j+1) * width) > 0)
            {
                swap((char*)base + j * width, (char*)base + (j+1) * width, width);
                flag = 0;
            }
        }
        if (flag)
        {
            break;
        }
    }

}

int sort_contacts(contacts_info* contacts)
{
    if(contacts -> count == 0)
    {
        printf("ͨѶ¼Ϊ��,�޷�����,���������ϵ��\n");
        return -1;
    }
    int flag = -1;
    while(flag)
    {
        printf("1:��������\n");
        printf("2:��������\n");
        printf("3:���併��\n");
        printf("4:��������\n");
        printf("0:�˳�����\n");
        printf("��ѡ��ʲô����:\n");
        scanf("%d", &flag);
        while(getchar() != '\n');
        switch(flag)
        {
            case 0:
                break;
            case 1:
                bubble_qsort(contacts->members, contacts->count, sizeof(contact), name_descend);
                display_contacts(contacts);
                break;
            case 2:
                bubble_qsort(contacts->members, contacts->count, sizeof(contact), name_ascend);
                display_contacts(contacts);
                break;
            case 3:
                bubble_qsort(contacts->members, contacts->count, sizeof(contact), age_descend);
                display_contacts(contacts);
                break;
            case 4:
                bubble_qsort(contacts->members, contacts->count, sizeof(contact), age_asend);
                display_contacts(contacts);
                break;
            default:
                printf("��������,����������\n");
                break;
        }
    }
}

void destory_contacts(contacts_info* contacts)
{
    assert(contacts);
    free(contacts->members);
    contacts->members = NULL;
}