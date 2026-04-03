#ifndef _10按要求搜索岗位_H
#define _10按要求搜索岗位_H

#include "0.全局结构体.h"

void search_job_by_key()
{
    system("cls");
    int sel;

    // 搜索菜单
    printf("==== 岗位搜索 ====\n");
    printf("1 按职位名称搜索\n");
    printf("2 按学历要求搜索\n");
    printf("3 按岗位ID搜索\n");
    printf("0 返回上一级菜单\n");
    printf("===================\n");
    printf("请选择[0-3]：");

    // 输入错误判断
    while (scanf("%d", &sel) != 1 || sel < 0 || sel > 3)
    {
        while (getchar() != '\n');
        printf("\n选择错误，请重新选择[0-3]：");
    }

    // switch case 结构
    switch (sel)
    {
    case 0:
        return; // 返回菜单

    case 1:
    {
        // 按职位搜索
        char key[100];
        getchar();
        printf("\n请输入职位关键词：");
        gets(key);

        int flag = 0;
        printf("\n===== 搜索结果 =====\n");
        for (int i = 0; i < job_cnt; i++)
        {
            if (strstr(job_list[i].title, key) != NULL)
            {
                flag = 1;
                printf("=============================================\n");
                printf("岗位ID：%d\n", job_list[i].jid);
                printf("职位：%s\n", job_list[i].title);
                printf("学历要求：%s\n", job_list[i].edu_req);
                printf("薪资待遇：%s\n", job_list[i].salary);
                printf("工作内容：%s\n", job_list[i].content);
                printf("工作地点：%s\n", job_list[i].address);
                printf("=============================================\n\n");
            }
        }
        if (!flag) printf("未找到匹配岗位！\n");
        break;
    }

    case 2:
    {
        // 按学历搜索
        char key[100];
        getchar();
        printf("\n请输入学历关键词：");
        gets(key);

        int flag = 0;
        printf("\n===== 搜索结果 =====\n");
        for (int i = 0; i < job_cnt; i++)
        {
            if (strstr(job_list[i].edu_req, key) != NULL)
            {
                flag = 1;
                printf("=============================================\n");
                printf("岗位ID：%d\n", job_list[i].jid);
                printf("职位：%s\n", job_list[i].title);
                printf("学历要求：%s\n", job_list[i].edu_req);
                printf("薪资待遇：%s\n", job_list[i].salary);
                printf("工作内容：%s\n", job_list[i].content);
                printf("工作地点：%s\n", job_list[i].address);
                printf("=============================================\n\n");
            }
        }
        if (!flag) printf("未找到匹配岗位！\n");
        break;
    }

    case 3:
    {
        // 按岗位ID搜索
        int id;
        printf("\n请输入岗位ID：");
        while (scanf("%d", &id) != 1)
        {
            while (getchar() != '\n');
            printf("请输入有效数字：");
        }

        int flag = 0;
        printf("\n===== 搜索结果 =====\n");
        for (int i = 0; i < job_cnt; i++)
        {
            if (job_list[i].jid == id)
            {
                flag = 1;
                printf("=============================================\n");
                printf("岗位ID：%d\n", job_list[i].jid);
                printf("职位：%s\n", job_list[i].title);
                printf("学历要求：%s\n", job_list[i].edu_req);
                printf("薪资待遇：%s\n", job_list[i].salary);
                printf("工作内容：%s\n", job_list[i].content);
                printf("工作地点：%s\n", job_list[i].address);
                printf("=============================================\n\n");
                break;
            }
        }
        if (!flag) printf("未找到该ID对应的岗位！\n");
        break;
    }

    default:
        printf("无效选项！\n");
        break;
    }

    printf("\n按回车键返回...");
    getchar();
}

#endif