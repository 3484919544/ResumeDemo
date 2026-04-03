#ifndef _7管理员功能_H
#define _7管理员功能_H

#include "0.全局结构体.h"
#include "14.自动保存全部数据.h"

// 判断管理员账号是否重复
int adminAccIsExist(char* acc)
{
    for (int i = 0; i < admin_cnt; i++)
    {
        if (strcmp(admin_list[i].admin_acc, acc) == 0)
            return 1;
    }
    return 0;
}

// 添加管理员账号
void addNewAdmin()
{
    system("cls");
    if (admin_cnt >= MAX_ADMIN)
    {
        printf("管理员账号数量已达上限！\n");
        system("pause");
        return;
    }

    char newAcc[20], newPwd[20];
    printf("===== 添加新管理员 =====\n");
    printf("请设置新管理员账号：");
    scanf("%s", newAcc);

    if (adminAccIsExist(newAcc))
    {
        printf("该管理员账号已存在！\n");
        system("pause");
        return;
    }

    printf("请设置新管理员密码：");
    scanf("%s", newPwd);

    // 存入数组
    strcpy(admin_list[admin_cnt].admin_acc, newAcc);
    strcpy(admin_list[admin_cnt].admin_pwd, newPwd);
    admin_cnt++;

    save_all_data(); //同步保存
    printf("新管理员账号添加成功！\n");
    system("pause");
}

// 管理员主菜单
void adminMenu()
{
    while (1)
    {
        system("cls");
        printf("========== 管理员后台 ==========\n");
        printf("1.查看所有普通用户账号密码\n");
        printf("2.修改普通用户密码\n");
        printf("3.删除普通用户(级联删简历)\n");
        printf("4.添加新管理员账号\n");  //新增功能
        printf("0.退出管理员后台\n");
        printf("================================\n");
        printf("请选择[0-4]：");

        int op;
        while (scanf("%d", &op) != 1 || op < 0 || op>4)
        {
            while (getchar() != '\n');
            printf("选择错误，请重新选择[0-4]：");
        }

        switch (op)
        {
        case 1: {
            system("cls");
            if (user_cnt == 0) { printf("暂无普通用户！\n"); system("pause"); break; }
            for (int i = 0; i < user_cnt; i++)
            {
                printf("用户ID：%d\n账号(身份证)：%s\n密码：%s\n身份：%s\n-----\n",
                    user_list[i].uid, user_list[i].id_card, user_list[i].pwd,
                    user_list[i].role == 1 ? "求职者" : "招聘者");
            }
            system("pause");
            break;
        }
        case 2: {
            system("cls");
            if (user_cnt == 0) { printf("暂无用户！\n"); system("pause"); break; }
            char tar[40]; printf("输入要修改的用户身份证："); scanf("%s", tar);
            int idx = -1;
            for (int i = 0; i < user_cnt; i++) if (strcmp(user_list[i].id_card, tar) == 0) { idx = i; break; }
            if (idx == -1) { printf("用户不存在！\n"); system("pause"); break; }
            char np[20]; printf("输入新密码："); scanf("%s", np);
            strcpy(user_list[idx].pwd, np);
            save_all_data();
            printf("修改成功！\n");
            system("pause");
            break;
        }
        case 3: {
            system("cls");
            if (user_cnt == 0) { printf("暂无用户！\n"); system("pause"); break; }
            char tar[40]; printf("输入要删除的用户身份证："); scanf("%s", tar);
            int idx = -1;
            for (int i = 0; i < user_cnt; i++) if (strcmp(user_list[i].id_card, tar) == 0) { idx = i; break; }
            if (idx == -1) { printf("用户不存在！\n"); system("pause"); break; }

            //级联删除该用户所有简历
            int delUid = user_list[idx].uid;
            for (int i = 0; i < MAX_RESUME; i++)
            {
                if (curriculum_message[i].belong_uid == delUid)
                    memset(&curriculum_message[i], 0, sizeof(curriculum_message[i]));
            }
            //删除普通用户
            for (int i = idx; i < user_cnt - 1; i++) user_list[i] = user_list[i + 1];
            user_cnt--;
            save_all_data();
            printf("用户及关联信息全部删除！\n");
            system("pause");
            break;
        }
        case 4:
            addNewAdmin();
            break;
        case 0:
            return;
        }
    }
}

// 管理员登录（支持所有已添加的管理员账号）
void adminLogin()
{
    system("cls");
    char acc[20], pwd[20];
    printf("===== 管理员登录 =====\n");
    printf("账号："); scanf("%s", acc);
    printf("密码："); scanf("%s", pwd);

    int ok = 0;
    for (int i = 0; i < admin_cnt; i++)
    {
        if (strcmp(admin_list[i].admin_acc, acc) == 0
            && strcmp(admin_list[i].admin_pwd, pwd) == 0)
        {
            ok = 1; break;
        }
    }
    if (ok)
    {
        printf("管理员验证通过！\n");
        system("pause");
        adminMenu();
    }
    else
    {
        printf("账号或密码错误！\n");
        system("pause");
    }
}

#endif