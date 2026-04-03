#ifndef _9查看所有岗位_H
#define _9查看所有岗位_H

#include "0.全局结构体.h"

void show_all_job()
{
    system("cls");
    if (job_cnt == 0)
    {
        printf("暂无招聘岗位！\n");
        system("pause");
        return;
    }

    for (int i = 0; i < job_cnt; i++)
    {
        printf("=============================================\n");
        printf("岗位ID：%d\n", job_list[i].jid);
        printf("职位：%s\n", job_list[i].title);
        printf("学历要求：%s\n", job_list[i].edu_req);
        printf("薪资待遇：%s\n", job_list[i].salary);
        printf("工作内容：%s\n", job_list[i].content);
        printf("工作地点：%s\n", job_list[i].address);
        printf("=============================================\n\n");
    }
    system("pause");
}

#endif