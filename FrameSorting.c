#include<stdio.h>
#include<string.h>
#define frameSize 3
#define maxFrames 127

char str[frameSize * maxFrames];
struct frame{                                              
    char text[frameSize];
    int seq_no;
}fr[maxFrames], shuf_ary[maxFrames];

int assign_seq_no();
void generate(int *random_ary, const int limit);
void shuffle(const int no_frames);
void sort(const int no_frames);

int main(){
    int no_frames,i;
    printf("Enter the message: ");
    gets(str);
    no_frames = assign_seq_no();
    shuffle(no_frames);
    sort(no_frames);
    printf("\n\nAFTER SORTING\n");
    for(i=0;i<no_frames;i++){
        printf("%s",shuf_ary[i].text);
    }
    printf("\n\n");
}

int assign_seq_no(){                          
    int k=0,i,j; 
    for(i=0; i < strlen(str); k++){
        fr[k].seq_no = k;
        for(j=0; j < frameSize && str[i]!='\0'; j++){
            fr[k].text[j] = str[i++];
        }
    }
printf("\nAfter assigning sequence numbers:\n");
for(i=0; i < k; i++){
    printf("%d:%s ",i,fr[i].text);
}
return k; 
}

void generate(int *random_ary, const int limit){ 
int r, i=0, j;
while(i < limit){
        r = random() % limit;
        for(j=0; j < i; j++){
            if( random_ary[j] == r )
            break;
        }
        if(i == j) 
            random_ary[i++] = r;
    } 
}

void shuffle(const int no_frames){ 
    int i, k=0, random_ary[no_frames];
    generate(random_ary, no_frames);
    for(i=0; i < no_frames; i++){
        shuf_ary[i] = fr[random_ary[i]];
    }
    printf("\n\nAFTER SHUFFLING:\n");
    for(i=0; i < no_frames; i++){
        printf("%d:%s ",shuf_ary[i].seq_no,shuf_ary[i].text);
    }
}

void sort(const int no_frames){ 
    struct frame temp;
    for(int i=0; i < no_frames-1 ; i++){
        for(int j=0; j < no_frames-1-i; j++){
            if(shuf_ary[j].seq_no > shuf_ary[j+1].seq_no){
                temp = shuf_ary[j];
                shuf_ary[j] = shuf_ary[j+1];
                shuf_ary[j+1] = temp;
                
            }
        }
    }
}

