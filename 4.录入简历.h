#ifndef _4录入简历_H
#define _4录入简历_H

#include "0.全局结构体.h"
#include "14.自动保存全部数据.h"

// 获取当前登录用户的身份证号
void get_current_user_id_card(char* id_card)
{
    for (int i = 0; i < user_cnt; i++)
    {
        if (user_list[i].uid == now_login_uid)
        {
            strcpy(id_card, user_list[i].id_card);
            return;
        }
    }
}

// 校验手机号 11 位
int is_phone_11(char* phone)
{
    return strlen(phone) == 11;
}

void input_my_resume()
{
    system("cls");
    int i;

    char current_id[40];
    get_current_user_id_card(current_id);

    for (i = 0; i < MAX_RESUME; i++)
    {
        if (curriculum_message[i].NO == 0)
        {
            // 1. 简历编号（自动）
            curriculum_message[i].NO = i + 1;

            // 2. 身份证号（自动绑定）
            strcpy(curriculum_message[i].ID_NO, current_id);

            // 3. 姓名
            getchar();
            printf("姓名：");
            gets(curriculum_message[i].Name);

            // 4. 出生年月日
            printf("出生年月日(xxxx-xx-xx)：");
            scanf("%d-%d-%d", &curriculum_message[i].year, &curriculum_message[i].month, &curriculum_message[i].day);

            // 5. 性别
            int s;
            printf("1.男 2.女：");
            scanf("%d", &s);
            strcpy(curriculum_message[i].Sex, s == 1 ? "男" : "女");

            // 6. 民族
            getchar();
            printf("民族：");
            gets(curriculum_message[i].Nation);

            // 7. 政治面貌
            int p;
            printf("1.群众 2.团员 3.党员：");
            scanf("%d", &p);
            if (p == 1) strcpy(curriculum_message[i].Politic_counte, "群众");
            if (p == 2) strcpy(curriculum_message[i].Politic_counte, "共青团员");
            if (p == 3) strcpy(curriculum_message[i].Politic_counte, "中共党员");

            // 8. 手机号（11位校验）
            char phone_str[20];
            getchar();
            while (1)
            {
                printf("手机号[必须11位]：");
                gets(phone_str);
                if (is_phone_11(phone_str))
                {
                    curriculum_message[i].Phone_number = atoll(phone_str);
                    break;
                }
                printf("手机号必须11位，请重新输入！\n");
            }

            // 9. 毕业院校
            printf("毕业院校：");
            gets(curriculum_message[i].University);

            // 10. 学历
            printf("学历：");
            gets(curriculum_message[i].Educational_background);

            // 11. 求职意向
            printf("求职意向：");
            gets(curriculum_message[i].Job_intention);

            // 12. 实习经历
            printf("实习经历：");
            gets(curriculum_message[i].Internship_experience);

            // 13. 技能证书
            printf("技能证书：");
            gets(curriculum_message[i].Skills_certificate);

            // 14. 所属用户ID（自动）
            curriculum_message[i].belong_uid = now_login_uid;

            save_all_data();

            printf("\n=========================================\n");
            printf("简历录入成功！\n");
            printf("身份证号：%s\n", current_id);
            printf("=========================================\n");

            system("pause");
            return;
        }
    }
}

#endif