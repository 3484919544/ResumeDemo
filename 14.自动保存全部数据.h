#ifndef _14自动保存全部数据_H
#define _14自动保存全部数据_H

#include "0.全局结构体.h"

void save_all_data()
{
    FILE* fp = fopen("all_data.bin", "wb");
    fwrite(&user_cnt, sizeof(int), 1, fp);
    fwrite(user_list, sizeof(struct User), user_cnt, fp);
    fwrite(&job_cnt, sizeof(int), 1, fp);
    fwrite(job_list, sizeof(struct Job), job_cnt, fp);
    fwrite(&send_cnt, sizeof(int), 1, fp);
    fwrite(send_list, sizeof(struct SendRecord), send_cnt, fp);
    fwrite(curriculum_message, sizeof(struct curriculum), MAX_RESUME, fp);
    fclose(fp);
}

#endif