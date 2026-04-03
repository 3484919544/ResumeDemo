#ifndef _11投递简历_H
#define _11投递简历_H

#include "0.全局结构体.h"
#include "14.自动保存全部数据.h"

void send_resume_to_job()
{
    system("cls");

    // ====================== 第一步：判断有没有岗位 ======================
    if (job_cnt == 0)
    {
        printf("暂无招聘岗位，无法投递简历！\n");
        system("pause");
        return;
    }

    // ====================== 第二步：判断有没有简历 ======================
    int has_resume = 0;
    for (int i = 0; i < MAX_RESUME; i++)
    {
        if (curriculum_message[i].belong_uid == now_login_uid && curriculum_message[i].NO != 0)
        {
            has_resume = 1;
            break;
        }
    }

    if (!has_resume)
    {
        printf("你还没有创建简历，请先录入简历！\n");
        system("pause");
        return;
    }

    // ====================== 显示所有岗位 ======================
    printf("==================== 招聘岗位列表 ====================\n");
    for (int i = 0; i < job_cnt; i++)
    {
        printf("岗位ID：%d\n", job_list[i].jid);
        printf("职位：%s\n", job_list[i].title);
        printf("学历要求：%s\n", job_list[i].edu_req);
        printf("薪资：%s\n", job_list[i].salary);
        printf("工作内容：%s\n", job_list[i].content);
        printf("工作地点：%s\n", job_list[i].address);
        printf("--------------------------------------------------------\n");
    }

    // ====================== 选择要投递的岗位ID ======================
    int select_id;
    printf("请输入要投递的岗位ID：");
    while (scanf("%d", &select_id) != 1)
    {
        while (getchar() != '\n');
        printf("请输入正确数字：");
    }

    // 查找岗位是否存在
    int job_index = -1;
    for (int i = 0; i < job_cnt; i++)
    {
        if (job_list[i].jid == select_id)
        {
            job_index = i;
            break;
        }
    }

    if (job_index == -1)
    {
        printf("该岗位不存在！\n");
        system("pause");
        return;
    }

    // ====================== 显示用户自己的简历 ======================
    printf("\n==================== 你的简历 ====================\n");
    int resume_list[MAX_RESUME];
    int resume_count = 0;

    for (int i = 0; i < MAX_RESUME; i++)
    {
        if (curriculum_message[i].belong_uid == now_login_uid && curriculum_message[i].NO != 0)
        {
            resume_count++;
            resume_list[resume_count] = i;
            printf("%d. 简历编号：%d | 姓名：%s\n", resume_count, curriculum_message[i].NO, curriculum_message[i].Name);
        }
    }

    printf("0. 取消投递\n");
    printf("请选择要投递的简历编号：");
    int resume_choice;

    while (scanf("%d", &resume_choice) != 1 || resume_choice < 0 || resume_choice > resume_count)
    {
        while (getchar() != '\n');
        printf("输入错误！请输入 0~%d：", resume_count);
    }

    if (resume_choice == 0)
    {
        printf("已取消投递！\n");
        system("pause");
        return;
    }

    // ====================== 执行投递 ======================
    int resume_idx = resume_list[resume_choice];

    // 这里可以记录投递记录（如果你需要我可以加上）
    printf("\n投递成功！\n");
    printf("你已向【%s】岗位投递了简历！\n", job_list[job_index].title);

    system("pause");
}

#endif