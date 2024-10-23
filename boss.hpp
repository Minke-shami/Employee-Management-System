//
//  boss.hpp
//  2024.8.28_职工管理系统
//
//  Created by mac on 2024/8/28.
//

#ifndef boss_hpp
#define boss_hpp
#include "worker.hpp"

#include <iostream>
using namespace std;

// worker 的派生类
class boss:public worker{
public:
    // 构造函数
    boss(int id , string name, int d_id);
    
    
    // 集成虚函数的声明
    virtual void showinfo() override;
    virtual string getdeptname() override;

};

#endif /* boss_hpp */
