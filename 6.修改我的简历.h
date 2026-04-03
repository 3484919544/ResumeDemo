#ifndef _6修改我的简历_H
#define _6修改我的简历_H

#include "0.全局结构体.h"
#include "14.自动保存全部数据.h"

// 校验手机号11位
int is_phone_11(char* phone);
/*
{
    return strlen(phone) == 11;
}*/

void modify_my_resume()
{
    system("cls");
    int i;
    int count = 0;
    int select_idx[MAX_RESUME];

    // ============== 列出当前用户所有简历（完整信息） ==============
    printf("===================== 我的全部简历 =====================\n");
    for (i = 0; i < MAX_RESUME; i++)
    {
        if (curriculum_message[i].belong_uid == now_login_uid && curriculum_message[i].NO != 0)
        {
            count++;
            select_idx[count] = i;

            printf("\n----------------- 第 %d 份简历 -----------------\n", count);
            printf("简历编号：%d\n", curriculum_message[i].NO);
            printf("身份证号：%s\n", curriculum_message[i].ID_NO);
            printf("姓名：%s\n", curriculum_message[i].Name);
            printf("出生日期：%d年%d月%d日\n", curriculum_message[i].year, curriculum_message[i].month, curriculum_message[i].day);
            printf("性别：%s\n", curriculum_message[i].Sex);
            printf("民族：%s\n", curriculum_message[i].Nation);
            printf("政治面貌：%s\n", curriculum_message[i].Politic_counte);
            printf("手机号：%lld\n", curriculum_message[i].Phone_number);
            printf("毕业院校：%s\n", curriculum_message[i].University);
            printf("学历：%s\n", curriculum_message[i].Educational_background);
            printf("求职意向：%s\n", curriculum_message[i].Job_intention);
            printf("实习经历：%s\n", curriculum_message[i].Internship_experience);
            printf("技能证书：%s\n", curriculum_message[i].Skills_certificate);
        }
    }

    if (count == 0)
    {
        printf("\n你还没有任何简历！\n");
        system("pause");
        return;
    }

    printf("\n========================================================\n");
    printf("0. 返回上一级菜单\n");
    printf("请选择要修改的简历编号：");

    int choice;
    while (scanf("%d", &choice) != 1 || choice < 0 || choice > count)
    {
        while (getchar() != '\n');
        printf("输入错误！请输入 [0~%d]：", count);
    }

    if (choice == 0)
    {
        printf("返回菜单...\n");
        system("pause");
        return;
    }

    // 定位到选中的简历
    int idx = select_idx[choice];
    system("cls");

    // ==================== 修改菜单（可修改项从 1 开始） ====================
    while (1)
    {
        printf("===================================================\n");
        printf("\t\t简历信息（可修改）\n");
        printf("===================================================\n");

        // 不可修改（只显示）
        printf("简历编号：%d（不可修改）\n", curriculum_message[idx].NO);
        printf("身份证号：%s（不可修改）\n", curriculum_message[idx].ID_NO);
        // printf("===================================================\n");

         // 可修改项 从 1 开始编号
        printf("1. 姓名：%s\n", curriculum_message[idx].Name);
        printf("2. 出生日期：%d年%d月%d日\n", curriculum_message[idx].year, curriculum_message[idx].month, curriculum_message[idx].day);
        printf("3. 性别：%s\n", curriculum_message[idx].Sex);
        printf("4. 民族：%s\n", curriculum_message[idx].Nation);
        printf("5. 政治面貌：%s\n", curriculum_message[idx].Politic_counte);
        printf("6. 手机号：%lld\n", curriculum_message[idx].Phone_number);
        printf("7. 毕业院校：%s\n", curriculum_message[idx].University);
        printf("8. 学历：%s\n", curriculum_message[idx].Educational_background);
        printf("9. 求职意向：%s\n", curriculum_message[idx].Job_intention);
        printf("10. 实习经历：%s\n", curriculum_message[idx].Internship_experience);
        printf("11. 技能证书：%s\n", curriculum_message[idx].Skills_certificate);

        printf("===================================================\n");
        printf("0. 保存并退出修改\n");
        printf("请选择要修改的项目[1-11]：");

        int op;
        while (scanf("%d", &op) != 1 || op < 0 || op > 11)
        {
            while (getchar() != '\n');
            printf("\n输入错误！请输入 [0-11]：");
        }

        if (op == 0)
        {
            save_all_data();
            printf("\n已保存！返回菜单...\n");
            system("pause");
            break;
        }

        getchar();
        switch (op)
        {
        case 1: printf("姓名："); gets(curriculum_message[idx].Name); break;
        case 2: printf("生日(xxxx-xx-xx)："); scanf("%d-%d-%d", &curriculum_message[idx].year, &curriculum_message[idx].month, &curriculum_message[idx].day); break;
        case 3: printf("1.男 2.女："); int s; scanf("%d", &s); strcpy(curriculum_message[idx].Sex, s == 1 ? "男" : "女"); break;
        case 4: printf("民族："); gets(curriculum_message[idx].Nation); break;
        case 5: printf("1.群众 2.团员 3.党员："); int p; scanf("%d", &p);
            if (p == 1) strcpy(curriculum_message[idx].Politic_counte, "群众");
            else if (p == 2) strcpy(curriculum_message[idx].Politic_counte, "共青团员");
            else strcpy(curriculum_message[idx].Politic_counte, "中共党员"); break;
        case 6:
        {
            char phone_str[20];
            while (1) {
                printf("手机号（11位）："); gets(phone_str);
                if (is_phone_11(phone_str)) { curriculum_message[idx].Phone_number = atoll(phone_str); break; }
                printf("必须11位！\n");
            }
            break;
        }
        case 7: printf("毕业院校："); gets(curriculum_message[idx].University); break;
        case 8: printf("学历："); gets(curriculum_message[idx].Educational_background); break;
        case 9: printf("求职意向："); gets(curriculum_message[idx].Job_intention); break;
        case 10: printf("实习经历："); gets(curriculum_message[idx].Internship_experience); break;
        case 11: printf("技能证书："); gets(curriculum_message[idx].Skills_certificate); break;
        }

        printf("\n修改成功！\n");
        system("pause");
    }
}

#endif