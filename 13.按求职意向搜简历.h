#ifndef _13按求职意向搜简历_H
#define _13按求职意向搜简历_H

#include "0.全局结构体.h"

void search_resume_by_intent()
{
    system("cls");
    char key[100];
    getchar(); printf("输入求职意向关键词："); gets(key);
    for (int i = 0; i < MAX_RESUME; i++)
    {
        if (curriculum_message[i].NO != 0 && strstr(curriculum_message[i].Job_intention, key))
        {
            printf("匹配简历%d号：姓名%s 意向%s\n",
                curriculum_message[i].NO, curriculum_message[i].Name, curriculum_message[i].Job_intention);
        }
    }
    system("pause");
}

#endif