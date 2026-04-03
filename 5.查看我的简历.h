#ifndef _5查看我的简历_H
#define _5查看我的简历_H

#include "0.全局结构体.h"

void show_my_resume()
{
    system("cls");
    int flag = 0;
    for (int i = 0; i < MAX_RESUME; i++)
    {
        // 只显示当前登录用户自己的简历
        if (curriculum_message[i].NO != 0 && curriculum_message[i].belong_uid == now_login_uid)
        {
            flag = 1;
            printf("====================================================================\n");
            printf("\t\t\t\t我的 %d 号简历\n", curriculum_message[i].NO);
            printf("====================================================================\n");
            printf("【0】身份证号码：%s\n", curriculum_message[i].ID_NO);
            printf("【1】姓名：%s\n", curriculum_message[i].Name);
            printf("【2】出生年月：%d年%d月%d日\n", curriculum_message[i].year, curriculum_message[i].month, curriculum_message[i].day);
            printf("【3】性别：%s\n", curriculum_message[i].Sex);
            printf("【4】民族：%s\n", curriculum_message[i].Nation);
            printf("【5】政治面貌：%s\n", curriculum_message[i].Politic_counte);
            printf("【6】联系电话：%lld\n", curriculum_message[i].Phone_number);
            printf("【7】毕业院校：%s\n", curriculum_message[i].University);
            printf("【8】学历：%s\n", curriculum_message[i].Educational_background);
            printf("【10】求职意向：%s\n", curriculum_message[i].Job_intention);
            printf("【11】实习经验：%s\n", curriculum_message[i].Internship_experience);
            printf("【12】技能证书：%s\n", curriculum_message[i].Skills_certificate);
            printf("====================================================================\n\n");
        }
    }
    if (!flag)
        printf("暂无个人简历！\n");
    system("pause");
}

#endif