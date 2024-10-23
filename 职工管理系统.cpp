//
//  职工管理系统.cpp
//  2024.8.28_职工管理系统
//
//  Created by mac on 2024/8/28.
//

#include "workmanege_systym.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "employee.hpp"
#include "jingli.hpp"
#include "boss.hpp"
#include "worker.hpp"
#include <cstdlib>
using namespace std;
# define  wenjian0 "/Users/mac/Desktop/xcode/2024.8.28_职工管理系统/2024.8.28_职工管理系统/empfile.txt"



// 构造函数初始化
WorkManege::WorkManege(){

    ifstream fts;
    fts.open(wenjian0,ios::in);
    
    // 1、文件不存在
    if(!fts.is_open()){
        cout<<"开始创建文件"<<endl;
        this->m_emp_num=0;
        this->m_emp_arry=NULL;
        this->m_file_is_empty = true;
        fts.close();
        return;
    }
    // 2、文件存在数据为空
    char ch;
    fts>>ch;
    if (fts.eof()) {
        cout<<"文件为内容空，重新开始创建"<<endl;
        this->m_emp_num=0;
        this->m_emp_arry=NULL;
        this->m_file_is_empty = true; // 空
        fts.close();
        return;
    }else{
        // 3、文件存在数据不为空
        fts.close();
        fts.open(wenjian0,ios::in);
       //  cout<<" 人数为： "<<this->get_emp_num()<<endl;
        int num = this->get_emp_num();
        this->m_emp_num=num;
     //   cout<<"this->m_emp_num= "<<this->m_emp_num<<endl;
        
        
        this->m_emp_arry = new worker * [num];
        
        
        this->m_file_is_empty = false;
        int id;
        string  name;
        int did;
        int i=0;
        while (fts>>id >>name >>did) {
            switch (did) {
                case 1:
                {
                    worker * new_worker = new employee(id,name,did);
                    this->m_emp_arry[i]=new_worker;
                    break;
                }
                case 2:
                {
                    worker * new_worker = new jingli(id,name,did);
                    this->m_emp_arry[i]=new_worker;
                    break;
                }
                case 3:
                {
                    worker * new_worker = new boss(id,name,did);
                    this->m_emp_arry[i]=new_worker;
                    break;
                }
                default:
                    cout << "未知的职责ID: " << did << endl;
                    continue;
            }

 /*          cout<<i<<" "<<this->m_emp_arry[i]->m_id<<" "
            <<this->m_emp_arry[i]->m_name<<" "
           <<this->m_emp_arry[i]->m_deptid<<endl; 2*/
            ++i;

        }
        
    }

   
};
// 获取文件中有多少行数据,返回多少人
int WorkManege::get_emp_num(){
    ifstream fts;
    fts.open(wenjian0,ios::in);
    int id;
    string name;
    int did;
    int all=0;
    while (fts>>id && fts>>name && fts>>did) {
        ++all;
    }
    fts.close();
    return all;
}

 // 菜单展示
void  WorkManege::show_menu(){
    cout<<"*****************************"<<endl;
    cout<<"***** 欢迎使用职工管理系统 ******"<<endl;
    cout<<"**0 退出管理程序 ***************"<<endl;
    cout<<"**1 增加职工信息****************"<<endl;
    cout<<"**2 显示职工信息****************"<<endl;
    cout<<"**3 删除职工信息****************"<<endl;
    cout<<"**4 修改职工信息****************"<<endl;
    cout<<"**5 查找职工信息****************"<<endl;
    cout<<"**6 按照编号排序****************"<<endl;
    cout<<"**7 清空所有文档****************"<<endl;
    cout<<"*****************************"<<endl;
    
}
//  0- 退出系统
void WorkManege::exitsystem(){
    cout<<"0: 功能退出 ,欢迎下次使用 "<<endl;
    exit(0);
}

// 保存新增的信息到到文件中
void WorkManege::save_emp(){
    ofstream tfs;
    tfs.open(wenjian0,ios::out);
    for (int i=0; i<this->m_emp_num; ++i) {
        
        tfs<< this->m_emp_arry[i]->m_id<<" "
           << this->m_emp_arry[i]->m_name<<" "
        << this->m_emp_arry[i]->m_deptid<<" "<<endl;
    }
    tfs.close();
    
}
// 查看输入的员工是否存在
int WorkManege::is_exit(int i){
    
    int n=0;
    for (; n<this->m_emp_num; ) {
        if(this->m_emp_arry[n]->m_id==i){
            this->m_emp_arry[n]->showinfo();
            i=n;
            break;
        }
        ++n;
        if(n==this->m_emp_num){
            cout<<" 查无此人"<<endl;
            i=0;
        }
    }
    return i;
    
}

void WorkManege::clearScreen(){
    if (std::getenv("TERM") == nullptr) {
        setenv("TERM", "xterm-256color", 1); // 设置环境变量 TERM 为 xterm-256color
    }

    system("clear");
}


//  1- 添加员工
void WorkManege::add_emp(){
    cout<<" 输入此次添加员工的数量："<<endl;
    int addnum =0;
    cin>>addnum;
    if(addnum>0){
        int new_all;
        new_all= this->m_emp_num + addnum;
        worker **new_m_emp_arry = new worker * [new_all]; //新开辟一个更大的地址空间

        // 第一步 将原来地址空间的内容转移到新的空间内去
        // 先判断原有空间地址不为空
        if(this->m_emp_arry!=NULL){
            for (int i=0; i<this->m_emp_num; ++i) {
                new_m_emp_arry[i]= this->m_emp_arry[i];
            }
 
        }
        // 第二步 输入员工的信息,创建新的派生类中
        for (int i=0; i<addnum; i++) {
            int id;
            string name;
            int did;
            cout<<"请输入第"<<i+1<<"个员工的编号"<<endl;
            cin>>id;
            cout<<"请输入第"<<i+1<<"个员工的姓名"<<endl;
            cin>>name;
            cout<<"请输入第"<<i+1<<"个员工的职责"<<"1: 代表普通员工"<<" 2: 代表部门经理"<<" 3: 代表公司老板"<<endl;
            cin>>did;
            worker * new_worker= NULL;
            switch (did) {
                case 1:
                    new_worker= new employee(id,name,did);
                    break;
                case 2:
                    new_worker= new jingli(id,name,did);
                    break;
                case 3:
                    new_worker= new boss(id,name,did);
                    break;
                default:
                    cout<<" 输入错误，请输入1 到 3 直接的数字"<<endl;
                    break;
            }
            // 第三步 将信息存入新的地址
            new_m_emp_arry[m_emp_num+i] = new_worker;
        }
        // 第三步 释放原有的空间
        delete[] this->m_emp_arry;
        // 第四步 将新的地址空间的地址给到原有空间
        this->m_emp_arry = new_m_emp_arry;
        this->m_emp_num = new_all;
        

        // 第五步 空间中的信息保存到.txt的文件中
         this->save_emp();
        
        
        
        // 第五步 员工信息添加完成
        cout<< addnum <<" 名员工信息添加完成 "<<endl;
        this->m_file_is_empty = false;
        
        
    }else{
        cout<<" 输入有误 ，重新输入"<<endl;
    }
    system("read -p 'Press Enter to continue...' var");
    clearScreen();
}
//  2- 展示员工
void WorkManege::show_emp(){
    cout<<"               *** 员工信息列表如下 *** "<<endl;
    cout<<" "<<endl;
    for (int i=0; i<this->m_emp_num; ++i) {
        
      //  cout<<this->m_emp_arry[i]->m_id<<" ";
      //  cout<<this->m_emp_arry[i]->m_name<<" ";
       // cout<<this->m_emp_arry[i]->m_deptid<<endl;
        this->m_emp_arry[i]->showinfo();
        
        
      //  this->m_emp_arry[i]->showinfo();
    }
    cout<<" "<<endl;
    
    system("read -p 'Press Enter to continue...' var");
    clearScreen();
}
//  3- 删除员工信息
void WorkManege::delt_emp(){
    cout<<"请输入要删除员工的编号:";
    int y;
    cin>>y;
    int x=0;
    if( this->is_exit(y)){
        cout<<"请再次确认是否需要删除  要删除：输入1   不要删除 ：输入0"<<endl;
        bool sc = false;
        cin>>sc;
        if(sc){
            x=this->is_exit(y);// 将需要删除职工的位置信息传递过来
           // cout<<"this->is_exit(y)"<<this->is_exit(y)<<endl;
            // 开辟新的空间，将保留的信息传到新空间
            worker **p = new worker *[this->m_emp_num];
            for (int i=0,n=0; i<this->m_emp_num;) {
                if (i!=x) {
                    p[n]=this->m_emp_arry[i];
                    ++n;
                    ++i;
                }else{
                    ++i;
                }

            }
            delete [] this->m_emp_arry;
            this->m_emp_arry=p;
            --this->m_emp_num;
           // cout<<"this->m_emp_num  "<<this->m_emp_num<<endl;
            cout<<" 删除成功 "<<endl;
          //  this->show_emp();
            this->save_emp();
        }
   this->save_emp();
    }
    
    system("read -p 'Press Enter to continue...' var");
    clearScreen();
}
//  4- 修改员工信息
void WorkManege::modify_emp(){
    cout<<" 输入需要变更信息的员工编号: "<<endl;
    int x;
    cin>>x;
    int y=this->is_exit(x);
    if(y){
        string  name;
        int did;
        cout<<"请输入新的名字 "<<endl;
        cin>>name;
        this->m_emp_arry[y]->m_name=name;
        cout<<"请输入新的职位"<<endl;
        cin>>did;
        this->m_emp_arry[y]->m_deptid= did;
        this->save_emp();
        cout<<"修改完成"<<endl;
    }
    system("read -p 'Press Enter to continue...' var");
    clearScreen();
    
}
//  5- 查找员工信息
void WorkManege::search_emp(){
    cout<<"请输入查找员工的编号"<<endl;
    int x;
    cin>>x;
    this->is_exit(x);
    system("read -p 'Press Enter to continue...' var");
    clearScreen();

}
//  6- 排序员工信息
void WorkManege::sor_emp(){
    cout<<" 从小到大开始排序  "<<endl;
    worker *p=  NULL;
    for (int i=0; i<this->m_emp_num-1; ++i) {
        for (int n=i+1; n<this->m_emp_num; ++n) {
            if (this->m_emp_arry[i]->m_id>this->m_emp_arry[n]->m_id) {
                p=this->m_emp_arry[i];
                this->m_emp_arry[i]=this->m_emp_arry[n];
                this->m_emp_arry[n]=p;
            }
        }
    }
    system("read -p 'Press Enter to continue...' var");
    clearScreen();
     
}
//  7- 清空员工信息
void WorkManege::clear_emp(){
    
    cout<<"清再次确认是否清除,确认：按1  退出按：0"<<endl;
    bool i =false;
    cin>>i;
    if(i){
        ofstream clear(wenjian0,ios::trunc|ios::out);
        if(clear.is_open()){
            cout<< "清除成功 "<<endl;
            this->m_emp_num=0;
            delete []this->m_emp_arry;
            this->m_emp_arry=NULL;
            this->m_file_is_empty = true; // 空
            
            clear.close();
        }else{
            cout<< "文件无法打开 "<<endl;
        }
    }
    system("read -p 'Press Enter to continue...' var");
    clearScreen();
}






// 析构函数
WorkManege::~WorkManege(){
    if(this->m_emp_arry!=NULL){
        delete []this->m_emp_arry;
        this->m_emp_arry=NULL;
    }
    
    
};

