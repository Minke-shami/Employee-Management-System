//
//  main.cpp
//  2024.8.28_职工管理系统
//
//  Created by mac on 2024/8/28.
//

#include <iostream>
#include "workmanege_systym.hpp"
#include "employee.hpp"
#include "worker.hpp"
#include "jingli.hpp"
#include "boss.hpp"
#include <cstdlib>

using namespace std;


int main() {
    cout<<"第一步导航到.cpp 的文件目录，将所有需要的.cpp源文件进行合成一个linux执行文件"<<endl;
    cout<<"g++ -std=c++11 -o myprogram main.cpp boss.cpp employee.cpp jingli.cpp    职工管理系统.cpp"<<endl;
    cout<<"第二步运行"<<endl;
    cout<<"./myprogram"<<endl;
    
    
    WorkManege wm;
    int  choise=0;
    
    while (true) {
        wm.show_menu();
        cout<<"请输入你的选择： " ;
        cin>>choise;
        cout<<endl;
        switch (choise) {
            case 0:  
                wm.exitsystem();
                break;
            case 1:
                wm.add_emp();
                break;
            case 2:
                wm.show_emp();
                break;
            case 3:
                wm.delt_emp();
                break;
            case 4:
                wm.modify_emp();
                break;
            case 5:
                wm.search_emp();
                break;
            case 6:
                wm.sor_emp();
                break;
            case 7:
                wm.clear_emp();
                break;
            default:
                break;
        }

    }
    
    

    
    
    
    
    
    
    return 0;
}
