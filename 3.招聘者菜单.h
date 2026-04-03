#ifndef _3招聘者菜单_H
#define _3招聘者菜单_H

#include "0.全局结构体.h"
#include "8.发布招聘岗位.h"
#include "12.招聘者查收到的简历.h"
#include "13.按求职意向搜简历.h"

void recruiter_main()
{
    while (1)
    {
        system("cls");
        printf("====招聘者功能菜单====\n");
        printf("1 发布招聘岗位\n");
        printf("2 按求职意向搜简历\n");
        printf("3 查看收到的投递简历\n");
        printf("0 返回上级主菜单\n");
        printf("======================\n");
        printf("请选择[0-3]：");

        int op;
        while (scanf("%d", &op) != 1 || op < 0 || op > 3)
        {
            while (getchar() != '\n');
            printf("\n选择错误，请重新选择[0-3]：");
        }

        switch (op)
        {
        case 0: return;//退回登录主菜单
        case 1: publish_new_job(); break;
        case 2: search_resume_by_intent(); break;
        case 3: check_receive_resume(); break;
        default:printf("无效操作！\n"); system("pause"); break;
        }
    }
}
#endif