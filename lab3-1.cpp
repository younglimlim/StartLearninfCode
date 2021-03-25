#include<cstdio>
#include<cstdlib>
int StrCmp(char lhs[], char rhs[]){
    int i = 0;
    while(lhs[i] != '\n' && rhs[i] != '\n'){
        if(lhs[i] < rhs[i]){
            return -1;
        }
        else if(lhs[i] > rhs[i]){
            return 1;
        }
        ++i;
    }
    if(lhs[i] == '\n' && rhs[i] == '\n'){
        return 0;
    }
    else if(lhs[i] == '\n' && rhs[i] != '\n'){
        return -1;
    }
    else {
        return 1;
    }
}
void StrSWap(char str1[], char str2[], int len2){
    for(int i = 0; i < len2; ++i){
        char temp = str1[i];
        str1[i] = str2[i];
        str2[i] = temp;
    }

}
char* UpperToLower(char * str){
    int i = 0;
    while(str[i] !='\0'){
        if(str[i] >= 'A' && str[i] <='Z'){
            str[i] = str[i] + 'a' - 'A';
        }
        ++i;
    }
    return str;
}
char *LowerToUpper(char * str){
    int i = 0;
    while(str[i] !='\0'){
        if(str[i] >= 'a' && str[i] <='z'){
            str[i] = str[i] + 'A' - 'a';
        }
        ++i;
    }
    return str;
}
void merge_file(const char *src1, const char *src2, const char *dst) //merge two difference files to the third file
{
    FILE * fptr1;
    FILE * fptr2;
    FILE* taget;
    char word[13] = {0};
    if((fptr1 = fopen(src1, "r")) == nullptr || (fptr2 = fopen(src2, "r")) == nullptr || (taget = fopen(dst, "a+")) == nullptr ) {
        //printf("you are sb.\n");
        exit(-1);
    }
    while((fgets(word, 13, fptr1)) != nullptr ){
        fputs(word, taget);
    }
    while((fgets(word, 13, fptr2)) != nullptr){
        fputs(word, taget);
    }
    if(fclose(fptr1) != 0 || fclose(fptr2) != 0 || fclose(taget) != 0){
        exit(0);
    }
    return ;

}
void upper_file(const char *src, const char *dst) {
    FILE * fptr;
    FILE* taget;
    char word[13] = {0};
    if((fptr = fopen(src, "r")) == nullptr  || (taget = fopen(dst, "a+")) == nullptr ) {
        //printf("big sb.\n");
        exit(-1);
    }
    while((fgets(word, 13, fptr)) != nullptr ){
        fputs(LowerToUpper(word), taget);
    }
    if(fclose(fptr) != 0 || fclose(taget) != 0){
        exit(0);
    }
    return ;
}//change the letter from lower to upper case;
void lower_file(const char *src, const char *dst) {
    FILE * fptr;
    FILE* taget;
    char word[13] = {0};
    if((fptr = fopen(src, "r")) == nullptr  || (taget = fopen(dst, "a+")) == nullptr ) {
        //printf("you are sb, too.\n");
        exit(-1);
    }
    while((fgets(word, 13, fptr)) != nullptr ){
        fputs(UpperToLower(word), taget);
    }
    if(fclose(fptr) != 0 || fclose(taget) != 0){
        exit(0);
    }
    return ;
}// the contrary of the last function
void sort_inc_file(const char *src, const char *dst) {
    char list[110][14] = {0};
    FILE *fptr;
    FILE *taget;
    if((fptr = fopen(src, "r")) == nullptr || (taget = fopen(dst, "a+")) == nullptr){
        printf("you become a sb again.\n");
        exit(0);
    }
    int i = 0;
    while((fgets(list[i], 13, fptr)) != nullptr){
        i++;
    }
    for(int j = 0; j < i; ++j){
        int min_index = j;
        for(int k = j + 1;  k < i; ++k){
            if(StrCmp(list[k], list[min_index]) < 0){
                min_index = k;
            }
        }
        StrSWap(list[j], list[min_index], 13);
    }
    for(int j = 0; j < i; ++j){
        fputs(list[j], taget);
    }
    if(fclose(fptr) != 0 || fclose(taget) != 0){
        exit(0);
    }
    return ;
}// 
void sort_dec_file(const char *src, const char *dst) {
     char list[110][14] = {0};
    FILE *fptr;
    FILE *taget;
    if((fptr = fopen(src, "r")) == nullptr || (taget = fopen(dst, "a+")) == nullptr){
        printf("you become a sb again\n");
        exit(0);
    }
    int i = 0;
    while((fgets(list[i], 13, fptr)) != nullptr){
        i++;
    }
    for(int j = 0; j < i; ++j){
        int min_index = j;
        for(int k = j + 1;  k < i; ++k){
            if(StrCmp(list[k], list[min_index]) > 0){
                min_index = k;
            }
        }
        StrSWap(list[j], list[min_index], 13);
    }
    for(int j = 0; j < i; ++j){
        fputs(list[j], taget);
    }
    if(fclose(fptr) != 0 || fclose(taget) != 0){
        exit(0);
    }
    return ;
}



int main(){
    //merge_file("A.txt", "B.txt", "C.txt");
    //upper_file("A.txt", "D.txt");
    //lower_file("B.txt", "E.txt");
    sort_inc_file("A.txt", "C.txt");
    sort_inc_file("B.txt", "D.txt");
    sort_dec_file("C.txt", "E.txt");
    sort_dec_file("B.txt", "F.txt");
    return 0;
}





