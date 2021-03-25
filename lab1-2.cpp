#include<stdio.h>
int strlength(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

int main(){
    int n = 0;
    char word[101] = { 0 };
    int steps = 0;
    int memory_index[101] = {0};
    char memory_vowel[101] = {0};
    char moving_vowel[101] = {0};
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%s", word);
        scanf("%d", &steps);
        int length = strlength(word);
        int k = 0;
        for(int j = 0; j < length; ++j){
            if(word[j] == 'a' || word[j] == 'e' || 
                word[j] == 'i' || word[j] == 'o' || 
                    word[j] == 'u')
            {
                memory_vowel[k] = word[j];
                memory_index[k] = j;
                k += 1;
            }
        }
        for(int j = 0; j < k; ++j){
            moving_vowel[(j + steps) % k] = memory_vowel[j];
        }
        for(int j = 0; j < k; ++j){
            word[memory_index[j]] = moving_vowel[j];
        }
        puts(word);
    }
    return 0;
}