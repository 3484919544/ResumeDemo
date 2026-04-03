#ifndef _1用户登录注册_H
#define _1用户登录注册_H

#include "0.全局结构体.h"
#include "2.求职者菜单.h"
#include "3.招聘者菜单.h"

// 检查身份证是否已存在
int is_id_exist(char* id)
{
    for (int i = 0; i < user_cnt; i++)
    {
        if (strcmp(user_list[i].id_card, id) == 0)
        {
            return 1;
        }
    }
    return 0;
}

// 检查身份证是否 18 位
int is_id_18(char* id)
{
    return strlen(id) == 18;
}

// ====================== 登录菜单 ======================
void login()
{
    while (1)
    {
        system("cls");
        int op;
        printf("===== 用户登录 =====\n");
        printf("1.登录\n");
        printf("2.返回主菜单\n");
        printf("====================\n");
        printf("请选择：");

        // 输入校验
        while (scanf("%d", &op) != 1 || op < 1 || op > 2)
        {
            while (getchar() != '\n');
            printf("\n选择错误，请输入 1 或 2：");
        }

        switch (op)
        {
        case 1:
        {
            system("cls");
            char input_id[40], input_pwd[20];
            printf("===== 登录 =====\n");
            printf("输入 0 返回上一级\n");
            printf("=================\n");

            printf("请输入身份证号：");
            scanf("%s", input_id);

            if (strcmp(input_id, "0") == 0)
            {
                system("pause");
                break;
            }

            // 18位校验
            while (!is_id_18(input_id))
            {
                printf("必须18位！重新输入[0返回]：");
                scanf("%s", input_id);
                if (strcmp(input_id, "0") == 0)
                {
                    system("pause");
                    goto end_login;
                }
            }

            printf("请输入密码：");
            scanf("%s", input_pwd);

            int ok = 0;
            for (int i = 0; i < user_cnt; i++)
            {
                if (strcmp(user_list[i].id_card, input_id) == 0 &&
                    strcmp(user_list[i].pwd, input_pwd) == 0)
                {
                    now_login_uid = user_list[i].uid;
                    printf("登录成功！\n");
                    system("pause");

                    if (user_list[i].role == JOB_SEEKER)
                        job_seeker_main();
                    else
                        recruiter_main();

                    ok = 1;
                    break;
                }
            }

            if (!ok)
            {
                printf("账号或密码错误！\n");
                system("pause");
            }
            break;
        }
        case 2:
            printf("返回主菜单...\n");
            system("pause");
            return;
        default:
            break;
        }
    }
end_login:;
}

// ====================== 注册菜单 ======================
void register_user()
{
    while (1)
    {
        system("cls");
        int op;
        printf("===== 用户注册 =====\n");
        printf("1.注册\n");
        printf("2.返回主菜单\n");
        printf("====================\n");
        printf("请选择：");

        // 输入校验
        while (scanf("%d", &op) != 1 || op < 1 || op > 2)
        {
            while (getchar() != '\n');
            printf("\n选择错误，请输入 1 或 2：");
        }

        switch (op)
        {
        case 1:
        {
            system("cls");
            struct User u;
            char temp_id[40];

            printf("===== 注册 =====\n");
            printf("输入 0 返回上一级\n");
            printf("=================\n");

            printf("请输入18位身份证号：");
            scanf("%s", temp_id);

            if (strcmp(temp_id, "0") == 0)
            {
                system("pause");
                break;
            }

            // 18位校验
            while (!is_id_18(temp_id))
            {
                printf("必须18位！重新输入[0返回]：");
                scanf("%s", temp_id);
                if (strcmp(temp_id, "0") == 0)
                {
                    system("pause");
                    goto end_reg;
                }
            }

            // 重复判断
            if (is_id_exist(temp_id))
            {
                printf("该身份证已注册！\n");
                system("pause");
                break;
            }

            strcpy(u.id_card, temp_id);
            printf("请输入密码：");
            scanf("%s", u.pwd);

            int role;
            printf("1.求职者 2.招聘者：");
            while (scanf("%d", &role) != 1 || role < 1 || role > 2)
            {
                while (getchar() != '\n');
                printf("只能输入 1 或 2：");
            }
            u.role = role;
            u.uid = user_cnt + 1;

            user_list[user_cnt++] = u;
            save_all_data();
            printf("注册成功！\n");
            system("pause");
            break;
        }
        case 2:
            printf("返回主菜单...\n");
            system("pause");
            return;
        default:
            break;
        }
    }
end_reg:;
}

#endif