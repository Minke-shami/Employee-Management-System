//
//  employee.cpp
//  2024.8.28_职工管理系统
//
//  Created by mac on 2024/8/28.
//

#include "employee.hpp"
#include <iostream>
using namespace std;


// 构造函数的初始化
employee:: employee(int id , string name, int d_id){
    this->m_id=id;
    this->m_name=name;
    this->m_deptid=d_id;

};


// 显示普通员工信息的说明
 void employee::showinfo() {
     cout<<" 职工编号是： "<< this->m_id << " ";
     cout<<" 职工姓名是： "<< this->m_name<< " ";
     cout<<" 职工岗位是： "<< this->getdeptname()<< " ";
     cout<<" 职工任务是： "<< " 好好打工，踏实上进 "<< endl;
};

// 显示普通员工职责的说明
string employee:: getdeptname(){
    
    return "普通员工";
};


