#include<stdio.h>
char dictionary[100][10] = { 0 };
char symble[7] = "XXXXXX";
int strlength(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

char* SelectSort(char* str, int n){
    for(int i = 0; i < n; ++i){
        int min_index = i;
        for(int j = i + 1; j < n; ++j){
            if(str[j] < str[min_index]){
                min_index = j;//可以更改了吗？
            }
        }
        if(min_index != i){
            char temp = str[i];
            str[i] = str[min_index];
            str[min_index] = temp;
        }
    }
    return str;
}

char* StrCopy(char* fake, const char *aim){
    int i = 0;
    for(; aim[i] != '\0'; ++i){
        fake[i] = aim[i];
    }
    fake[i] = '\0';
    return fake;
}

void StrSWap(char str1[], char str2[], int len2){
    for(int i = 0; i <= len2; ++i){
        char temp = str1[i];
        str1[i] = str2[i];
        str2[i] = temp;
    }

}

bool CompareTwoStr(char str1[], char str2[])
{
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0'){
        if((int)str1[i] < (int)str2[i]){
            return true;
        }
        else if ((int)str1[i] > (int)str2[i]){
            return false;
        }
        i++;
    }
    if(str1[i] == '\0'){
        return true;
    }
    else return false;
}

bool IsTheSameTwoStr(char str1[], char str2[]){
    if(strlength(str1) != strlength(str2)){
        return false;
    }
    else{
        int length = strlength(str1);
        char copy1[10] = { 0 };
        char copy2[10] = { 0 };
        char* fake1 = &copy1[0];
        char* fake2 = &copy2[0];
        fake1 = SelectSort(StrCopy(fake1, str1), length);
        fake2 = SelectSort(StrCopy(fake2, str2), length);
        for(int i = 0; i < length; ++i){
            if(fake1[i] != fake2[i]){
                return false;
            }
        }
        return true;
    }
}


int main(){
    char jumble[10] = {0};
    int i = 0;
    do
    {
        scanf("%s", dictionary[i]);
        i += 1;
    }
    while(!IsTheSameTwoStr(dictionary[i - 1], symble));
    for(int j = 0; j < i - 1; ++j){
        int min_index = j;
        for(int k = j + 1; k < i - 1; ++k){
            if(CompareTwoStr(dictionary[k], dictionary[min_index])){
                min_index = k;
            }
        }
        if(strlength(dictionary[j]) <= strlength(dictionary[min_index])){
            StrSWap(dictionary[j], dictionary[min_index], strlength(dictionary[min_index]));
        }
        else
            StrSWap(dictionary[min_index], dictionary[j], strlength(dictionary[j]));

    }

    while(scanf("%s", jumble)){
        if(IsTheSameTwoStr(jumble, symble)){
            break;
        }
        bool flag = false;
        for(int j = 0; j < i - 1; ++j){
            if(IsTheSameTwoStr(jumble, dictionary[j])){
                puts(dictionary[j]);
                flag = true;
            }
        }
        if(!flag){
            puts("NOT A VALID WORD");
        }
        puts("******");
    }
    return 0;
}