//
//  main.cpp
//  Assingment2
//
//  Created by Nicolaus Nagel on 2/16/14.
//  Copyright (c) 2014 Nicolaus Nagel. All rights reserved.
//



#include "gameOfLife.h"

int main(int argc, const char * argv[])
{
    
    string answer1;
    gameOfLife test;
    
    loop:while(true){
        cout<<"Would you like to start the program? y/n"<<endl;
        cin>>answer1;
        if(answer1 == "y"){
            test.userConfig();
        }
        else if (answer1 == "n"){
            cout<<"Program ending now"<<endl;
            exit(0);
        }
        else{
            cout<<"Wrong input"<<endl;
            goto loop;
        }
    }
}

