#ifndef _8发布招聘岗位_H
#define _8发布招聘岗位_H

#include "0.全局结构体.h"
#include "14.自动保存全部数据.h"

void publish_new_job()
{
    system("cls");
    struct Job j;
    j.jid = job_cnt + 1;
    j.publisher_uid = now_login_uid;
    getchar();

    printf("====发布新招聘岗位====\n");
    printf("请输入职位名称：");
    gets(j.title);
    printf("请输入学历要求：");
    gets(j.edu_req);
    printf("请输入薪资待遇：");
    gets(j.salary);
    printf("请输入工作内容：");
    gets(j.content);
    printf("请输入工作地点：");
    gets(j.address);

    job_list[job_cnt++] = j;
    save_all_data();

    printf("\n岗位发布成功！\n");
    system("pause");
}

#endif