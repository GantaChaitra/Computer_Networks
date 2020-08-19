#include <stdio.h>
#include <string.h>

int main(){
    char given_flag[10] = {'0','1','1','1','1','1','1','0'};
    char input_string[20];
    char final_suffix_string[20];
    int i,j = 0,count,length_of_string;

    printf("Enter the string: ");
    scanf("%s",input_string);

    length_of_string = strlen(input_string);
    count = 0;

    
    for(i = 0;i < length_of_string;i++){
        if(input_string[i] == '1'){
            count++;
        }
        
        else{
            count = 0;
        }
        final_suffix_string[j] = input_string[i];
        j++;

        if(count == 5 && input_string[i+1] == '1'){
            final_suffix_string[j] = '0';
            j++;
            count = 0;

        }
    }

    

    final_suffix_string[j] = '\0';
    printf("%s %s %s",given_flag,final_suffix_string,given_flag);
    return 0;

}
