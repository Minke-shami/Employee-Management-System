//
//  职工管理系统.hpp
//  2024.8.28_职工管理系统
//
//  Created by mac on 2024/8/28.
//

#ifndef workmanege_systym_hpp
#define workmanege_systym_hpp
 
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "worker.hpp"



using namespace std;
// class worker;

// 用户沟通 职工数据维护 文件的处理

class WorkManege{
public:
    int m_emp_num; // 记录文件中的人员的个数
    worker **m_emp_arry; // 创建指向worker员工基类的数组，成员可能是普通员工，也可能是老板，也可能是经理
    bool m_file_is_empty = 1; // 设置默认值 文件为空
    
    
    
    // 构造函数
    WorkManege();
    // 成员函数
    void show_menu(); // 展示菜单
    void exitsystem(); // 0 ----退出功能
    void add_emp(); // 1 ----添加员工
    void save_emp(); // 保存文件
    int  get_emp_num(); // 获取文件中的成员数量
    void show_emp();// 2 展示员工
    void delt_emp();// 3 删除员工
    int is_exit(int i=0);// 判断职工是否存在，并返回职工的所在类数组的编号
    void modify_emp();//4 修改信息
    void search_emp();// 5 按照编号查找员工
    void sor_emp();// 6 按照从小到大排序
    void clear_emp();// 7 清除所有员工信息
    void clearScreen();// 清屏函数
    
    // 析构函数
    ~WorkManege();
 
};



















#endif /* _______hpp */
