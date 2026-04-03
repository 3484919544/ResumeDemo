#ifndef _7删除我的简历_H
#define _7删除我的简历_H

#include "0.全局结构体.h"
#include "14.自动保存全部数据.h"

void del_my_resume()
{
    system("cls");
    int i, find = 0;
    for (i = 0; i < MAX_RESUME; i++)
    {
        if (curriculum_message[i].belong_uid == now_login_uid && curriculum_message[i].NO != 0)
        {
            memset(&curriculum_message[i], 0, sizeof(struct curriculum));
            find = 1;
            save_all_data();
            printf("已删除你的简历！\n");
            break;
        }
    }
    if (!find)printf("无简历可删！\n");
    system("pause");
}

#endif