//
//  gameOfLife.cpp
//  Assingment2
//
//  Created by Nicolaus Nagel on 2/16/14.
//  Copyright (c) 2014 Nicolaus Nagel. All rights reserved.
//

#include "gameOfLife.h"


//this method asks user for the configuration of the simulation, then calls the user mode method
void gameOfLife::userConfig(){ //get user input incase they choose file input option
    
    
    cout<<"What configuration? Random or flat file?"<<endl;
    cin>>configuration;
    
    if(configuration == "random" || configuration == "Random")
    {
        cout<<"How many rows?"<<endl;  //check for correct input...
        cin>>userRow;
        cout<<"How many columns?"<<endl;//check for correct input...
        cin>>userColumn;
        cout<<"How dense should it be?"<<endl;
        cin>>userDensity;
        
        cout<<"Here is your random game board: "<<endl;
        cout<<endl;
        randomArr(userRow, userColumn);
        printArray();
        cout<<endl;
        userMode();
    }
    else if (configuration == "file" || configuration == "File"){
        cout<<"What is the File Path?"<<endl;
        cin>>filePath;
        fileArr(filePath);
        fileMethod();
        
    }
    else
        cout<<"Wrong input!\nProgram ending now.\n"<<endl;
}

//if user chooses the file method he will be asked for the different modes.
void gameOfLife::fileMethod(){
    int generation = 0;
    cout<<"What mode? Classic, Doughnut, or Mirror?"<<endl;
    cin>>mode;
    
    cout<<"What run option? Brief = 1 or Manual = 2?"<<endl;
    cin>>runAnswer;
    
    cout << "Please enter in a file path to the file where your next generation will print :"<<endl;
	cin >> filePath2;
    
    if(mode == "classic" && runAnswer =="1"){
        while(true){
            classico();
            outputFile();
            generation++;
            usleep(600000);
            cout<<"Generation: "<<generation<<endl;
        }
    }
    else if(mode == "doughnut" && runAnswer =="1"){
        while(true){
            doughnut();
            outputFile();
            generation++;
            usleep(600000);
            cout<<"Generation: "<<generation<<endl;
        }
    }
    else if(mode == "mirror" && runAnswer =="1"){
        while(true){
            mirror();
            outputFile();
            generation++;
            usleep(600000);
            cout<<"Generation: "<<generation<<endl;
        }
    }
    
    else if(mode == "classic" && runAnswer == "2"){
        
        while(true)
        {
            cout<<"Next Generation? y/n."<<endl;
            cin>>answer2;
            if(answer2 == "y"){
                classico();
                outputFile();
                generation++;
                cout<<"Generation: "<<generation<<endl;
                continue;
            }
            else if(answer2 == "n" || answer2 == "N"){
                break;
            }
        }
    }
    else if( mode == "doughnut" && runAnswer =="2"){
        
        while(true){
            cout<<"Next Generation? y/n"<<endl;
            cin>>answer2;
            
            if(answer2 == "y"){
                doughnut();
                outputFile();
                generation++;
                cout<<"Generation: "<<generation<<endl;
                continue;
            }
            else if(answer2 == "n" || answer2 == "N"){
                break;
            }
            
        }
        
    }
    else if(mode == "mirror" && runAnswer =="2"){
        while(true){
            cout<<"Next Generation? y/n"<<endl;
            cin>>answer2;
            
            if(answer2 == "y"){
                mirror();
                outputFile();
                generation++;
                cout<<"Generation: "<<generation<<endl;
                continue;
            }
            else if(answer2 == "n" || answer2 == "N"){
                break;
            }
        }
    }
    else{
        cout<<"Wrong input, program ending now."<<endl;
        exit(0);}
}

//method that checks for user mode, then calls mode method depending on user input
void gameOfLife::userMode(){
    int generation =0;
    
    
    cout<<"What mode? Classic, Doughnut, or Mirror?"<<endl;
    cin>>mode;
    
    cout<<"What run option? Brief = 1 or Manual = 2?"<<endl;
    cin>>runAnswer;
    
    if(mode == "classic" && runAnswer =="1"){
        while(true){
            classico();
            printArray();
            generation++; //generation counter
            usleep(600000); // puts a pause inbetween the different generations
            cout<<"Generation: "<<generation<<endl;
        }
    }
    else if(mode == "doughnut" && runAnswer =="1"){
        while(true){
            doughnut();
            printArray();
            generation++;
            usleep(600000);
            cout<<"Generation: "<<generation<<endl;
        }
    }
    else if(mode == "mirror" && runAnswer =="1"){
        while(true){
            mirror();
            printArray();
            generation++;
            usleep(600000);
            cout<<"Generation: "<<generation<<endl;
        }
    }
    
    else if(mode == "classic" && runAnswer == "2"){
        
        loop1:while(true)
        {
            cout<<"Next Generation? y/n."<<endl;
            cin>>answer2;
            if(answer2 == "y"){
                classico();
                printArray();
                generation++;
                cout<<"Generation: "<<generation<<endl;
                continue;
            }
            else if(answer2 == "n" || answer2 == "N"){
                break;
            }
            else
                goto loop1;
        }
    }
    else if( mode == "doughnut" && runAnswer =="2"){
        
        loop2: while(true)
        {
            cout<<"Next Generation? y/n"<<endl;
            cin>>answer2;
            
            if(answer2 == "y"){
                doughnut();
                printArray();
                generation++;
                cout<<"Generation: "<<generation<<endl;
                continue;
            }
            else if(answer2 == "n" || answer2 == "N"){
                break;
            }
            else
                goto loop2;
            
        }
        
    }
    else if(mode == "mirror" && runAnswer =="2"){
        loop3:while(true){
            cout<<"Next Generation? y/n"<<endl;
            cin>>answer2;
            
            if(answer2 == "y"){
                mirror();
                printArray();
                generation++;
                cout<<"Generation: "<<generation<<endl;
                continue;
            }
            else if(answer2 == "n" || answer2 == "N"){
                break;
            }
            else
                goto loop3;
        }
    }
    else{
        cout<<"Wrong input, program ending now."<<endl;
        exit(0);}
}


// prints the array
void gameOfLife::printArray(){
    
    for(int r = 0; r <userRow; r++){
            cout<<arr[r]<<endl;
        }
}

//method that switches the main game board with the updated one and prints it out,
void gameOfLife::switchBoard(){
    for (int r=0; r<userRow; r++){
            arr[r] = arr1[r];
    }
}

//method that outputs the array into a new file
void gameOfLife::outputFile(){
    
    ofstream write(filePath2.c_str());
    cout<< userRow;
    
	write << userRow << endl;
	write << userColumn << endl;
	for (int r = 0; r < userRow; r++) {
		write << arr[r] << endl;
	}
	cout << "file output successfully" << endl;
    write.close();
}


//method to find array through file path
void gameOfLife::fileArr(string filepath){
    string line;
	int readf = 0, height = 0, width = 0, incrementation = 0;
	ifstream userFile(filepath.c_str());
    
	if (userFile.is_open()) {
		while (!userFile.eof()) {
			getline(userFile, line);
			if (readf == 0) {
				height = atoi(line.c_str());
                cout<<height;
				userRow = height;
				arr = new char*[height];
				arr1 = new char*[height];
			} else if (readf == 1) {
				width = atoi(line.c_str());
				userColumn = width;
				for (int i = 0; i < height; i++) {
					arr[i] = new char[width];
					arr1[i] = new char[width];
				}
			} else
				for (int i = 0; i < line.length(); i++) {
					arr[incrementation][i] = line[i];
					arr1[incrementation][i] = line[i];
				}
            incrementation++;
            readf++;
        }
        
        userFile.close();
    }
    else
        cout << "Unable to open file"<<endl;

}

//creation of array according to user input
void gameOfLife::randomArr(int userRow, int userColumn){
    
    int userPercent = userDensity *100;//converts user input to percentage

    int r,c;
    // creation of the main board
    arr = new char*[userRow];
    arr1 = new char*[userRow];
    for(int i = 0; i < userRow; ++i){
        arr[i] = new char[userColumn];
        arr1[i] = new char[userColumn];
    }

    for(r = 0; r < userRow;r++)
    {
        for(c = 0; c < userColumn; c++)
        {
            density = (rand()%100 +1); //calcultation of density for a number between 0 and 1
            if(density <= userPercent){
                arr[r][c] = 'X';
                arr1[r][c] = 'X';
                
            }
            else if (density > userPercent)
            {
                arr[r][c] = '-';
                arr1[r][c] = '-';
                
            }
          
        }
    }
    
}


//method for the classic mode
void gameOfLife::classico(){
    int neighbors = 0;
    int r, c;
    
    for(r = 0; r < userRow; r++){
        
        for(c = 0;c<userColumn;c++){
            
            for (int checkH = -1; checkH < 2; ++checkH){
				for (int checkW = -1; checkW < 2; ++checkW){
					if (r + checkH < 0||c + checkW < 0||r+checkH >userRow-1 ||c+checkW >userColumn-1){
						//if the position is out of bound, then continue
						continue;}
                    else if (checkH == 0 && checkW == 0){
						//if the position is the same as the checking then ignore it move on to the next one
						continue;}
                    else {
						//if the position is a - then don't count
						if (arr[checkH + r][checkW + c] == '-'){
							continue;}
                        else if (arr[checkH + r][checkW + c] == 'X'){
							//if the position is a + count it
							neighbors++;}
					}
                }
            }
        
            
            if (arr[r][c] == 'X')
            {
                if (neighbors <= 1){
                    arr1[r][c] = '-';}
                else if (neighbors == 2){
                    arr1[r][c] = 'X';}
                else if (neighbors == 3){
                    arr1[r][c] = 'X';}
                else if (neighbors >= 3){
                    arr1[r][c] = '-';}
            }
            else if (arr[r][c] == '-'){
                if (neighbors <= 1) {
                    arr1[r][c] = '-';}
                else if (neighbors == 2){
                    arr1[r][c] = '-';}
                else if (neighbors == 3){
                    arr1[r][c] = 'X';}
                else if (neighbors >= 3){
                    arr1[r][c] = '-';}
            
            }
            neighbors = 0;
        }
    }
    switchBoard();

}


//method for the mirror mode
void gameOfLife::mirror(){
    
    int r,c;
    int neighbors = 0;
    
    for(r =0; r<userRow; r++){
        for(c=0;c<userColumn;c++){
            for(int checkH =-1; checkH < 2; ++checkH){
                for(int checkW = -1; checkW <2; ++checkW){
                    if(checkH == 0 && checkW == 0)
                        continue;
                    if(r + checkH < 0 || c + checkW < 0|| r + checkH > userRow - 1 || c + checkW > userColumn - 1)
                    {
                        int NumCheckOne = 0, numCheckTwo = 0;
						if (r + checkH < 0) {
							NumCheckOne = userRow - 1;
						} else if (r + checkH > userRow - 1) {
							NumCheckOne = 0;
						} else {
							NumCheckOne = r + checkH;
						}
                        
						//check for the width
						if (c + checkW < 0) {
							numCheckTwo = userColumn - 1;
						} else if (c + checkW > userColumn - 1) {
							numCheckTwo = 0;
						} else {
							numCheckTwo = c + checkW;
						}
                        
						if (arr[NumCheckOne][numCheckTwo] == 'X') {
							neighbors++;
						} else if (arr[NumCheckOne][numCheckTwo] == '-') {
							continue;
						}

                    }
                    else {
						//if the position is a - then don't count
						if (arr[checkH + r][checkW + c] == '-') {
							continue;
						}
                        else if (arr[checkH + r][checkW + c] == 'X') {
							//if the position is a + count it
							neighbors++;
						}
					}
				}
			}
            if (arr[r][c] == 'X') {
				if (neighbors <= 1) {
					arr1[r][c] = '-';
				} else if (neighbors == 2) {
					arr1[r][c] = 'X';
				} else if (neighbors == 3) {
					arr1[r][c] = 'X';
				} else if (neighbors >= 3) {
					arr1[r][c] = '-';
				}
			}
            else if (arr[r][c] == '-') {
				if (neighbors <= 1) {
					arr1[r][c] = '-';
				} else if (neighbors == 2) {
					arr1[r][c] = '-';
				} else if (neighbors == 3) {
					arr1[r][c] = 'X';
				} else if (neighbors >= 3) {
					arr1[r][c] = '-';
				}
			}
			neighbors = 0;
                        
        }
    }
    switchBoard();
}

//method for the doughnut mode
void gameOfLife::doughnut(){
    int r,c;
    int neighbors = 0;
    
    for(r =0; r<userRow; r++){
        for(c=0;c<userColumn;c++){
            for(int checkH =-1; checkH < 2; ++checkH){
                for(int checkW = -1; checkW <2; ++checkW){
                    if(checkH == 0 && checkW == 0)
                        continue;
                    if(r+ checkH < 0 ||c+checkW<0 || r+checkH > userRow -1|| c+checkW > userRow-1)
                    {
                        
                        int NumCheckOne = 0, numCheckTwo = 0;
						if (r + checkH < 0) {
							NumCheckOne = userRow - 1;
						} else if (r + checkH > userRow - 1) {
							NumCheckOne = 0;
						} else {
							NumCheckOne = r + checkH;
						}
                        
						
						if (c + checkW < 0) {
							numCheckTwo = userColumn - 1;
						} else if (c + checkW > userColumn - 1) {
							numCheckTwo = 0;
						} else {
							numCheckTwo = c + userColumn;
						}
                        
						if (arr[NumCheckOne][numCheckTwo] == 'X') {
							neighbors++;
						} else if (arr[NumCheckOne][numCheckTwo] == '-') {
							continue;
						}
                        
					}
                    else
                    {
						if (arr[checkH + r][checkW + c] == '-'){
							continue;
						}
                        else if (arr[checkH + r][checkW + c] == 'X'){
							neighbors++;
						}
					}
				}
			}
            if (arr[r][c] == 'X') {
				if (neighbors <= 1) {
					arr1[r][c] = '-';
				} else if (neighbors == 2) {
					arr1[r][c] = 'X';
				} else if (neighbors == 3) {
					arr1[r][c] = 'X';
				} else if (neighbors >= 3) {
					arr1[r][c] = '-';
				}
			}
            else if (arr[r][c] == '-') {
				if (neighbors <= 1) {
					arr1[r][c] = '-';
				} else if (neighbors == 2) {
					arr1[r][c] = '-';
				} else if (neighbors == 3) {
					arr1[r][c] = 'X';
				} else if (neighbors >= 3) {
					arr1[r][c] = '-';
				}
			}
			neighbors = 0;
        }
    }
    switchBoard();
}

    

                        
                        
                        
                        
                        
                        
                        
                        


    
    

    
    
    
    
    
    
    
    
    
    
    
    
    

















