#ifndef _15自动读取全部数据_H
#define _15自动读取全部数据_H

#include "0.全局结构体.h"

//全局变量初始化
struct curriculum curriculum_message[MAX_RESUME] = { 0 };
struct User user_list[MAX_USER] = { 0 };
struct Job job_list[MAX_JOB] = { 0 };
struct SendRecord send_list[MAX_SEND] = { 0 };

int user_cnt = 0;
int job_cnt = 0;
int send_cnt = 0;
int now_login_uid = -1;

void load_all_data()
{
    FILE* fp = fopen("all_data.bin", "rb");
    if (!fp)return;
    fread(&user_cnt, sizeof(int), 1, fp);
    fread(user_list, sizeof(struct User), user_cnt, fp);
    fread(&job_cnt, sizeof(int), 1, fp);
    fread(job_list, sizeof(struct Job), job_cnt, fp);
    fread(&send_cnt, sizeof(int), 1, fp);
    fread(send_list, sizeof(struct SendRecord), send_cnt, fp);
    fread(curriculum_message, sizeof(struct curriculum), MAX_RESUME, fp);
    fclose(fp);
}

#endif