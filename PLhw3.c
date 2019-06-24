#include<stdio.h>
#include<string.h>
#include<stdlib.h>     
#include <math.h>  

char *fourMore="";
char *sixtLast="";

char *substring(char *string, int position, int length){
   char *pointer;
   int c;
   pointer = malloc(length+1);
   if (pointer == NULL){
      printf("aloc\n");
      exit(1);
   }
   for (c = 0 ; c < length ; c++){
      *(pointer+c) = *(string+position-1);      
      string++;  
   }
   *(pointer+c) = '\0';
    return pointer;
}
char *smallFour(char *ptr){
    if(*ptr == '.'){ return "....";}
    else if(*ptr == '*'){ return "****";}
    else if(*ptr == 'x'){ return "xxxx";}
    else if(*ptr == 'o'){ return "oooo";}
    else return "SmaF";
}
char *twoMaker(char *ptr){
    if(*ptr == '.'){ return "........";}
    else if(*ptr == '*'){ return "********";}
    else if(*ptr == 'x'){ return "xxxxxxxx";}
    else if(*ptr == 'o'){ return "oooooooo";}
    else if(*ptr == 'y'){ return "yyyyyyyy";}
    else if(*ptr == 'z'){ return "zzzzzzzz";}
    else if(*ptr == 't'){ return "tttttttt";}
    else if(*ptr == 'a'){ return "aaaaaaaa";}
    else if(*ptr == 'b'){ return "bbbbbbbb";}
    else if(*ptr == 'c'){ return "cccccccc";}
    else if(*ptr == 'd'){ return "dddddddd";}
    else return "twoM";
}
char *bigFour(char *ptr){
    if(*ptr == '.'){ return "................";}
    else if(*ptr == '*'){ return "****************";}
    else if(*ptr == 'x'){ return "xxxxxxxxxxxxxxxx";}
    else if(*ptr == 'o'){ return "oooooooooooooooo";}
    else if(*ptr == 'y'){ return "yyyyyyyyyyyyyyyy";}
    else if(*ptr == 'z'){ return "zzzzzzzzzzzzzzzz";}
    else if(*ptr == 't'){ return "tttttttttttttttt";}
    else if(*ptr == 'a'){ return "aaaaaaaaaaaaaaaa";}
    else if(*ptr == 'b'){ return "bbbbbbbbbbbbbbbb";}
    else if(*ptr == 'c'){ return "cccccccccccccccc";}
    else if(*ptr == 'd'){ return "dddddddddddddddd";}
    else return "bigF";
}

char *regulator(char *ptr,int imp){
    char *ret="";
    if(strlen(ptr)==4) {ret= ptr;} 
    else if(strlen(ptr)==1){ 
        if(imp==0){ ret= smallFour(ptr);}
        else if(imp==1){ ret= bigFour(ptr);}
    }
    else if(strlen(ptr)==2){ ret= twoMaker(ptr); }
    else if(strlen(ptr)==5){ fourMore = smallFour(substring(ptr,5,strlen(ptr)));
       ret = substring(ptr,1,4);
    }
    else if(strlen(ptr)>5){ret = substring(ptr,1,4);}  
    else ret= "regM";

    return ret;
}

int squareCheck (int x){
        float z= sqrt(x*4);
        if (z ==(int)z) return 1; 
        else return 0;
}

int pluscheck(char *girdi){
    int sel ;
    char *param ="++";
   char *ptr = strstr(girdi, param);

	if (ptr != NULL){sel=1;}
	else{sel=0;}
	
    return sel;
}

int main(){   
    int quadNum = 0;
    int kareli=1;
    const int size = 500;
    char commands[]="";
    char *girdi=(char *) malloc(size * sizeof(char));
    scanf("%s",girdi);
    
    int important = pluscheck(girdi);
    //printf("%d\n",important);
    if(strlen(girdi)==1){
       return printf("%s\n", girdi);
    }else {
        if(strlen(girdi)>5 && strlen(girdi)<=30){quadNum=4;}
        else if(strlen(girdi)>30 && strlen(girdi)<=50){quadNum=8;}
        else if(strlen(girdi)>50){quadNum=16;}
        char parameter[]="+";
        char *ptr = strtok(girdi, parameter);
        char *command[size];
        char *kuadBas[size];
        while(ptr != NULL){

            char *point = regulator(ptr,important);
            //printf("%s-------%lu----%s\n",ptr,strlen(ptr),point );
            if(strlen(point)==4){
                command[kareli-1]=malloc(4);
                strcpy(command[kareli-1],point);
                kareli++;
                
            }else if(strlen(point)==8){
                char *kel = substring(point,5,strlen(point));
                for(int i=0;i<2;i++){
                    command[kareli-1]=malloc(4);
                    strcpy(command[kareli-1],kel);
                    kareli++;
                }
            }else if(strlen(point)==16){
                char *kel = substring(point,13,strlen(point));
                for(int i=0;i<4;i++){
                    command[kareli-1]=malloc(4);
                    strcpy(command[kareli-1],kel);
                    kareli++;
                }
                important =0;
            }else {printf("mEWh");}
            
    		
    		ptr = strtok(NULL, parameter);
        }
        
        
        
        
        if(kareli>2){command[kareli-1]=malloc(4);strcpy(command[kareli-1],fourMore);}
            //sixtLast
        
        if(kareli==2){int i=0;printf("%c%c\n%c%c\n",command[i][0],command[i][1],command[i][3],command[i][2]);}
        
        
        if(quadNum==4){
            for(int i=0;i<quadNum && kareli!=2;i++){
                for(int j=0;j<quadNum/2 && i<quadNum/2;j++){
                        if(i%2==0){printf("%c%c",command[j][0],command[j][1]);}
                        else {printf("%c%c",command[j][3],command[j][2]);}
                }
                for(int t=quadNum-1;t>=quadNum/2 && i>=quadNum/2;t--){
                        if(i%2==0){printf("%c%c",command[t][0],command[t][1]);}
                        else {printf("%c%c",command[t][3],command[t][2]);}  
                }
                printf("\n");
            }
        }
        
        else if(quadNum==8){
            int j=0;
            for(int i=0;i<quadNum/4 && kareli!=2;i++){
                    printf("%c%c%c%c%c%c%c%c\n",command[j][0],command[j][1],command[j+1][0],command[j+1][1],command[j+3][0],command[j+3][1],command[j+2][0],command[j+2][1]);
                    printf("%c%c%c%c%c%c%c%c\n",command[j][3],command[j][2],command[j+1][3],command[j+1][2],command[j+3][3],command[j+3][2],command[j+2][3],command[j+2][2]);
                    if(j!=kareli-2)j=j+4;
            }
                printf("%c%c%c%c%c%c%c%c\n",command[j+4][0],command[j+4][1],command[j+5][0],command[j+5][1],command[j][0],command[j][1],command[j+1][0],command[j+1][1]);
                printf("%c%c%c%c%c%c%c%c\n",command[j+4][3],command[j+4][2],command[j+5][3],command[j+5][2],command[j][3],command[j][2],command[j+1][3],command[j+1][2]);  
                printf("%c%c%c%c%c%c%c%c\n",command[j+7][0],command[j+7][1],command[j+6][0],command[j+6][1],command[j+3][0],command[j+3][1],command[j+2][0],command[j+2][1]);
                printf("%c%c%c%c%c%c%c%c\n",command[j+7][3],command[j+7][2],command[j+6][3],command[j+6][2],command[j+3][3],command[j+3][2],command[j+2][3],command[j+2][2]);
            
        }
        else if(quadNum==16){
            for(int i=0;i<64;i++){
                printf("-----%d\n",i);
                printf("%c%c\n",command[i][0],command[i][1]);
                printf("%c%c\n",command[i][3],command[i][2]);
            }
            
        }
        
        free(girdi);
        return 0;
    }
}

