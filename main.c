#define _CRT_SECURE_NO_WARNINGS
#include "15.自动读取全部数据.h"
#include "1.用户登录注册.h"

int main()
{
    load_all_data();
    while (1)
    {
        system("cls");
        printf("====求职招聘系统总菜单====\n");
        printf("1 账号登录\n");
        printf("2 账号注册\n");
        printf("3 退出系统\n");
        printf("==========================\n");
        printf("请选择[1-3]：");

        int op;
        while (scanf("%d", &op) != 1 || op < 1 || op > 3)
        {
            while (getchar() != '\n');
            printf("\n选择错误! 请重新选择[1-3]：");
        }

        switch (op)
        {
        case 1: login(); break;
        case 2: register_user(); break;
        case 3: printf("退出系统成功！\n"); return 0;
        default: printf("无效选项！\n"); system("pause"); break;
        }
    }
}