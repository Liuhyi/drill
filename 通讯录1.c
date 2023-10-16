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
        printf("请选择要执行的操作:");
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
                printf("即将退出");
                Sleep(2000);
                break;
            default:
                printf("输入有误,请重新输入\n");
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
        printf("通讯录为空,无法修改,请先添加联系人\n");
        return -1;
    }
    char name[MAX_NAME];
    printf("请输入要修改联系人的姓名:");
    scanf("%s",name);
    int pos = find_contact_by_name(contacts, name);
    if (pos == -1)
    {
        printf("联系人不存在\n");
        return -1;
    }
    else
    {
        printf("请重新输入联系人姓名:");
        scanf("%s", contacts->members[pos].name);
        while(getchar() != '\n');
        printf("请重新输入联系人性别:");
        scanf("%s", contacts->members[pos].gender);
        while(getchar() != '\n');
        printf("请重新输入联系人年龄:");
        scanf("%d", &contacts->members[pos].age);
        while(getchar() != '\n');
        printf("请重新输入联系人电话:");
        scanf("%s", contacts->members[pos].phone);
        while(getchar() != '\n');
        printf("请重新输入联系人住址:");
        scanf("%s", contacts->members[pos].address);
        while(getchar() != '\n');
        printf("修改成功\n");
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
            perror("增容错误:\n");
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
        printf("通讯录为空,无法查询,请先添加联系人\n");
        return;
    }
    char name[MAX_NAME];
    printf("请输入要查找联系人的姓名:");
    scanf("%s",name);
    int pos = find_contact_by_name(contacts, name);
    if (pos == -1)
    {
        printf("联系人不存在\n");
    }
    else
    {
        printf("%-10s\t%-9s\t%-9s\t%-20s\t%-30s\n","姓 名:","性别:","年龄:","电话:","住址:");
        printf("%-10s\t%-9s\t%-9d\t%-20s\t%-30s\n",
               contacts->members[pos].name,
               contacts->members[pos].gender,
               contacts->members[pos].age,
               contacts->members[pos].phone,
               contacts->members[pos].address
        );
        printf("查找成功\n");
    }
}
void initialize_contacts(contacts_info* contacts)
{
    assert(contacts);
    contacts->members = (contact*)calloc(INITIAL_SIZE, sizeof (contact));
    if(contacts->members == NULL)
    {
        perror("初始化失败:");
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
 printf("****************  1,添加联系人            2,删除联系人********************\n");
 printf("****************  3,修改联系人            4,显示所有联系人*****************\n");
 printf("****************  5,排序联系人            6,查找联系人********************\n");
 printf("************************ 0,退出程序 ************************************\n");
 printf("**********************************************************************\n");
}


int add_contact(contacts_info* contacts)
{
    rasie_capacity(contacts);
    printf("请输入联系人姓名:");
    scanf("%s", contacts->members[contacts->count].name);
    while(getchar() != '\n');
    printf("请输入联系人性别:");
    scanf("%s", contacts->members[contacts->count].gender);
    while(getchar() != '\n');
    printf("请输入联系人年龄:");
    scanf("%d", &contacts->members[contacts->count].age);
    while(getchar() != '\n');
    printf("请输入联系人电话:");
    scanf("%s", contacts->members[contacts->count].phone);
    while(getchar() != '\n');
    printf("请输入联系人住址:");
    scanf("%s", contacts->members[contacts->count].address);
    while(getchar() != '\n');
    contacts->count++;
    printf("添加成功\n");
    return 1;
}

void display_contacts(const contacts_info* contacts)
{
    if(contacts->count == 0)
    {
        printf("通讯录为空\n");
        return;
    }
    printf("%-10s\t%-9s\t%-9s\t%-20s\t%-30s\n","姓 名:","性别:","年龄:","电话:","住址:");
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
    printf("是否保存修改:y/n\n");
    scanf("%c", &next);
    while(getchar() != '\n');
    if(next == 'y')
    {
        FILE* file = fopen("contacts_list.txt", "w");
        if(file)
        {
            fprintf(file,"%-20s%-20s%-20s%-20s%-30s\n","姓名:","性别:","年龄:","电话:","住址:");
            for(int i = 0; i < contacts->count; i++)
            {
                fprintf(file,"%-20s%-20s%-20d%-20s%-30s\n", contacts->members[i].name,
                        contacts->members[i].gender,
                        contacts->members[i].age,
                        contacts->members[i].phone,
                        contacts->members[i].address);
            }
            printf("文件已保存在contacts_list.txt\n");
        }
        else
        {
            perror("文件打开失败:");
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
        printf("容量为零,无法删除,请先添加联系人");
        return -1;
    }
    else
    {   char name[MAX_NAME];
        printf("请输入要删除联系人的姓名:");
        scanf("%s",name);
        while(getchar() != '\n');
        int pos = find_contact_by_name(contacts, name);
        if(pos == -1)
        {
            printf("联系人不存在\n");
            return -1;
        }
        else
        {
            for (int i = pos;i < contacts->count - 1; i++)
            {
                contacts->members[i] = contacts->members[i+1];
            }
            contacts->count--;
            printf("删除成功\n");
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
        printf("通讯录为空,无法排序,请先添加联系人\n");
        return -1;
    }
    int flag = -1;
    while(flag)
    {
        printf("1:姓名降序\n");
        printf("2:姓名升序\n");
        printf("3:年龄降序\n");
        printf("4:年龄升序\n");
        printf("0:退出排序\n");
        printf("请选择按什么排序:\n");
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
                printf("输入有误,请重新输入\n");
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