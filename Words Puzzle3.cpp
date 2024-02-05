#include <iostream>
#include <cstring> //strcmp( ) 
const int ROWS = 4, COLS= 4;

bool solveWordsPuzzle(char[], char[][COLS+1]);

int main(int argc, char** argv) {
    const int wordsListRows = 2;
    char wordsPuzzle[ROWS][COLS+1] = {
	    "BXXD",
"AXEX",
"TRXX",
"FXXX"
	  };
    
    char wordsList[wordsListRows][COLS+1]={
        "BAT", "FRED"
        };
        int i = 2;
        for(int i = 0 ; i < wordsListRows ; i++){
        	if(solveWordsPuzzle(wordsList[i], wordsPuzzle)){
            std::cout <<i+1 <<". "<<wordsList[i]<<" is found"<<std::endl;
            std::cout << std::endl;
        }else{
            std::cout<< i+1 <<". "<<wordsList[i]<<" is not found" << std::endl;
            std::cout << std::endl;
        }
		}
        
        
    
    
    return 0;
}
bool solveWordsPuzzle(char word[COLS+1], char wordsPuzzle[][COLS+1]){
    bool boolean = false;
    char result[COLS+1];
    int flag = 0;
    int x = 0, y = 0;
    int size = 0;
    int x2 = 0, y2 = 0;
    int loopsCounter = 0 ;
    int i = 0;int j = 0;
    do{
    	//std::cout <<" x2 = "<< x2 <<", y2 = "<< " " <<y2 <<std::endl;
    	//cout
    	flag = 0;
    	for(i = x2 ; i < ROWS ; i++){
        for(j = y2 ; j < COLS ; j++){
        	//std::cout <<" i = "<< i <<", j = "<< " " <<j <<std::endl;
            if(word[0] == wordsPuzzle[i][j]){
            	
                x = i ; y = j;
                //std::cout << "GOT IT AT "<< x << " " << y <<std::endl;
                flag = 1;
                x2 = x ; y2 = y ;
		loopsCounter++;
                break;
            }
            y2 = 0;
        }
        if(flag == 1){
        	//std::cout << x2 << " " << y2 << std::endl;
        	break;
        }
//		else{
//            std::cout << "OOPS, word is not found, try again" << std::endl;
//        }
    }
    
    //Horizontal  Left-To-Right
    if(y < COLS-2){
    for(size = COLS - 2; size > 0 ; size--){
        int counter = 0;
        for(i = y ; i < (COLS - size) +1 ; i++){
            result[counter] = wordsPuzzle[x][i];
            counter++;
        }
        result[counter]='\0';
        if(!(strcmp(result, word))){
        	std::cout << "GOT IT !! At ( "<<x<<", "<<y<<" )" << " to ( "<< x<<", "<<i-1<<" )"<<" Horizontal  Left-To-Right"<<std::endl;
            boolean = true;
            break;
        }
    }}
    
    //Horizontal Right-To-Left
    if(y > 1){
    	for(size = COLS - 2; size < COLS ; size++){
    		int counter = 0;
    		for(i = y ; i >=(COLS-size)-2; i--){
    			result[counter] = wordsPuzzle[x][i];
    			counter++;
			}
			result[counter]='\0';
        if(!(strcmp(result, word))){
        	std::cout << "GOT IT !! At ( "<<x<<", "<<y<<" )" << " to ( "<< x<<", "<<i+1<<" )"<<" Horizontal Right-To-Left"<<std::endl;
            boolean = true;
            break;
        }
		}
	}
	
	//Vertical Up-Down 
	if(x < ROWS -2){
		
		for(int size = ROWS - 2 ; size >0 ; size--){
			
			int counter = 0 ;
			for( i = x ; i < (ROWS-size) + 1 ;i++){
		
				result[counter] = wordsPuzzle[i][y];
				counter++;
			}
			result[counter]='\0';
        if(!(strcmp(result, word))){
            boolean = true;
            std::cout << "GOT IT !! At ( "<<x<<", "<<y<<" )" << " to ( "<< i-1<<", "<<y<<" )"<<" Vertical Up-Down"<<std::endl;
            //std::cout << result << std::endl;
            break;
		}
	}
	}
	//Vertical Down-Up
	//std::cout << x << " " << y << std::endl;
	if(x > 2){
		for(int size = ROWS - 2 ; size > 0 ; size--){
			int counter = 0;
			for(int i = x ; i >= (ROWS-size) - 2 ; i--){
//				if(x==10 && y==11){
//					std::cout << wordsPuzzle[i][y] ;
//				}
				//std::cout <<std::endl;
				result[counter] = wordsPuzzle[i][y];
				counter++;
			}
			
			result[counter] = '\0';
//			if(x==10 && y==11){
//					std::cout << result << std::endl ;
//				}
			if(!(strcmp(result, word))){
            boolean = true;
            std::cout << "GOT IT !! At ( "<<x<<", "<<y<<" )" << " to ( "<< i+1<<", "<<y<<" )"<<" Vertical Down-Up"<<std::endl;
            //std::cout << result << std::endl;
            break;
		}
	}
}
  //diagonal North-East
  if(x > 1 && y < COLS-2){
  	for(int size = COLS-2 ; size > 0 ; size--){
  		int temp_x = x;
  		int counter = 0;
  		for(int i = y ; i<(ROWS-size)+1;i++){
  			result [counter] = wordsPuzzle[temp_x][i];
  			temp_x--;counter++;
		  }
		  result[counter] = '\0';
			if(!(strcmp(result, word))){
            boolean = true;
            std::cout << "GOT IT !! At ( "<<x<<", "<<y<<" )" << " to ( "<< temp_x+1<<", "<<i+1<<" )"<<" diagonal North-East"<<std::endl;
            //std::cout << result << std::endl;
            break;
	  }
  }
}

//diagonal South-east
if(x<ROWS-2 && y <COLS-2){
	for(int size = ROWS - 2 ; size > 0 ; size--){
		int temp_y = y;
		int counter = 0;
		for(i = x ; i < (ROWS-size)+1 ; i++){
			result[counter] = wordsPuzzle[i][temp_y];
			temp_y++;counter++;
		}
		 result[counter] = '\0';
			if(!(strcmp(result, word))){
            boolean = true;
            std::cout << "GOT IT !! At ( "<<x<<", "<<y<<" )" << " to ( "<< i-1<<", "<<temp_y-1<<" )"<<" diagonal South-east"<<std::endl;
            //std::cout << result << std::endl;
            break;
	}
}
}
//Diagonal North-West
if(x > 1 && y >1){
	for(int size = COLS - 2 ; size > 0 ; size--){
		int temp_y = y;
		int counter = 0; 
		for(int i = x; i>=(COLS-size)-2;i--){
			result[counter] = wordsPuzzle[i][temp_y];
			counter++;temp_y--;
		}
		result[counter] = '\0';
//			if(x==6 && y==10){
//			std::cout << result <<std::endl;
//		}
			if(!(strcmp(result, word))){
            boolean = true;
            std::cout << "GOT IT !! At ( "<<x<<", "<<y<<" )" << " to ( "<< i+1<<", "<<temp_y+1<<" )"<<" Diagonal North-West"<<std::endl;
            //std::cout << result << std::endl;
            break;
	}
}}
//Diagonal South-West
if(x<COLS-2 && y>1){
	for(int size = COLS - 2 ; size >0 ; size--){
		int temp_y = y;
		int counter = 0;
		for(int i = x ; i <(COLS-size)+1;i++){
			result[counter] = wordsPuzzle[i][temp_y];
			counter++;temp_y--;
		}
		result[counter] = '\0';
			if(!(strcmp(result, word))){
            boolean = true;
            std::cout << "GOT IT !! At ( "<<x<<", "<<y<<" )" << " to ( "<< i-1<<", "<<temp_y+1<<" )"<<" Diagonal South-West"<<std::endl;
            //std::cout << result << std::endl;
            break;
	}
}
}
if(boolean){
	break;
}else{
	x2 = (y == COLS-1) ? ++x2 :x;
    y2 = (y == COLS-1) ? 0 : ++y2;
}

	}while(loopsCounter < COLS * ROWS);
    
    
	
	return boolean; 
}

/*"NOLXYHHJTRHHNFD",
        "RXQMFRWFMRGADPJ",
        "XHBFVPAIAQULKHE",
        "GSHVXHILVUAMAWV",
        "WOMANWVTLNONPSJ",
        "ELYKFJQEOIIONAM",
        "UFFLDGCDZGHTZVF",
        "JPHYAFVLOTFNONE",
        "AASEWGZTGCUIJKB",
        "BUBQRKDQBGFLWOH",
        "ACKNYUFPIIWCYMP",
        "KSWYBWPPVRORBMQ",
        "LYOOHOHVSLCQIOM",
        "WNOFBEASBYZONSJ",
        "TENIBACNLROCSFB"
		*****************
		"BOY",
        "CABINET",
        "CLINTON",
        "DONALD",
        "GIRL",
        "HILLARY",
        "MAN",
        "TRUMP",
        "WOMAN"
		*/
