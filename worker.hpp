//
//  worker.hpp
//  2024.8.28_职工管理系统
//
//  Created by mac on 2024/8/28.
//

#ifndef worker_hpp
#define worker_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// 员工的基类
class worker{
public:
    int m_id;
    string m_name;
    int m_deptid;
    
    // 显示个人信息  纯虚函数，在基类中不做实现
    virtual void showinfo()=0;
    // 获取个人职责
    virtual string getdeptname()=0;
    
};







#endif /* worker_hpp */
