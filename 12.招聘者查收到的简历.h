#ifndef _12招聘者查收到的简历_H
#define _12招聘者查收到的简历_H

#include "0.全局结构体.h"

void check_receive_resume()
{
    system("cls");
    int flag = 0;
    printf("==============================================================\n");
    printf("\t\t\t 你收到的简历投递（完整信息）\n");
    printf("==============================================================\n");

    // 遍历所有投递记录
    for (int i = 0; i < send_cnt; i++)
    {
        // 只显示当前招聘者自己发布岗位收到的简历
        if (send_list[i].to_jid >= 1 && send_list[i].to_jid <= job_cnt &&
            job_list[send_list[i].to_jid - 1].publisher_uid == now_login_uid)
        {
            int resume_no = send_list[i].resume_no;
            // 找到对应简历
            for (int j = 0; j < MAX_RESUME; j++)
            {
                if (curriculum_message[j].NO == resume_no && curriculum_message[j].NO != 0)
                {
                    flag = 1;
                    printf("【岗位ID：%d】收到的 %d 号简历\n", send_list[i].to_jid, curriculum_message[j].NO);
                    printf("==============================================================\n");
                    printf("姓名：%s\n", curriculum_message[j].Name);
                    printf("出生年月日：%d年%d月%d日\n", curriculum_message[j].year, curriculum_message[j].month, curriculum_message[j].day);
                    printf("性别：%s\n", curriculum_message[j].Sex);
                    printf("民族：%s\n", curriculum_message[j].Nation);
                    printf("政治面貌：%s\n", curriculum_message[j].Politic_counte);
                    printf("手机号：%lld\n", curriculum_message[j].Phone_number);
                    printf("毕业院校：%s\n", curriculum_message[j].University);
                    printf("学历：%s\n", curriculum_message[j].Educational_background);
                    printf("身份证号：%s\n", curriculum_message[j].ID_NO);
                    printf("求职意向：%s\n", curriculum_message[j].Job_intention);
                    printf("实习经历：%s\n", curriculum_message[j].Internship_experience);
                    printf("技能证书：%s\n", curriculum_message[j].Skills_certificate);
                    printf("==============================================================\n\n");
                }
            }
        }
    }

    if (!flag)
        printf("暂无收到的简历投递！\n");

    system("pause");
}

#endif