#ifndef _0全局结构体_H
#define _0全局结构体_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_RESUME 40000
#define MAX_JOB 1000
#define MAX_USER 1000
#define MAX_SEND 10000

//简历结构体
//简历结构体
struct curriculum
{
    int NO;                         // 简历编号（唯一标识）
    char ID_NO[40];                // 身份证号（与登录账号绑定）
    char Name[10];                  // 姓名
    int year, month, day;          // 出生年月日
    char Sex[3];                   // 性别
    char Nation[30];               // 民族
    char Politic_counte[6];        // 政治面貌
    long long Phone_number;        // 手机号码（11位）
    char University[100];          // 毕业院校
    char Educational_background[100]; // 学历
    char Job_intention[10000];     // 求职意向
    char Internship_experience[10000]; // 实习经历
    char Skills_certificate[10000];   // 技能证书
    int belong_uid;                // 所属用户ID（关联账号）
};

//用户身份
typedef enum {
    JOB_SEEKER = 1,
    RECRUITER = 2
}Role;

// 用户：身份证号作为唯一账号
struct User {
    char id_card[40];  // 【唯一标识：身份证号】
    char pwd[20];      // 密码
    Role role;         // 身份
    int uid;           // 内部编号
};

//招聘岗位
//招聘岗位
//招聘岗位
struct Job {
    int jid;                 //岗位编号
    char title[100];         //职位名称
    char edu_req[50];        //学历要求
    char salary[50];         //薪资待遇
    char content[1000];     //工作内容
    char address[100];       //工作地点
    int publisher_uid;       //发布者UID
};

//投递记录
struct SendRecord {
    int send_uid;
    int to_jid;
    int resume_no;
};

extern struct curriculum curriculum_message[MAX_RESUME];
extern struct User user_list[MAX_USER];
extern struct Job job_list[MAX_JOB];
extern struct SendRecord send_list[MAX_SEND];

extern int user_cnt;
extern int job_cnt;
extern int send_cnt;
extern int now_login_uid;

#endif