#ifndef _2求职者菜单_H
#define _2求职者菜单_H

#include "0.全局结构体.h"
#include "4.录入简历.h"
#include "5.查看我的简历.h"
#include "6.修改我的简历.h"
#include "7.删除我的简历.h"
#include "9.查看所有岗位.h"
#include "10.按要求搜索岗位.h"
#include "11.投递简历.h"

void job_seeker_main()
{
    while (1)
    {
        system("cls");
        printf("====求职者功能菜单====\n");
        printf("1 录入我的简历\n");
        printf("2 查看我的简历\n");
        printf("3 修改我的简历\n");
        printf("4 删除我的简历\n");
        printf("5 查看全部招聘岗位\n");
        printf("6 按关键词搜岗位\n");
        printf("7 投递简历到岗位\n");
        printf("0 返回上级主菜单\n");
        printf("======================\n");
        printf("请选择[0-7]：");

        int op;
        while (scanf("%d", &op) != 1 || op < 0 || op > 7)
        {
            while (getchar() != '\n');
            printf("\n选择错误!  请重新选择[0-7]：");
        }

        switch (op)
        {
        case 0: return;//退回登录主菜单
        case 1: input_my_resume(); break;
        case 2: show_my_resume(); break;
        case 3: modify_my_resume(); break;
        case 4: del_my_resume(); break;
        case 5: show_all_job(); break;
        case 6: search_job_by_key(); break;
        case 7: send_resume_to_job(); break;
        default:printf("无效操作！\n"); system("pause"); break;
        }
    }
}
#endif