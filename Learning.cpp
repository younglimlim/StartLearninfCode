#include<cstdio>
#include<cstdlib>
const long long int length = 100000;
static long long int counter = 1;
int compare(const void *num1, const void *num2){
    ++counter;
    return *(int*)num1 - *(int*)num2;
}
int main(){
    long long int array[length] = {0};
    int amount = 0;
    scanf("%d", &amount);
    for(int i = 0; i < amount; ++i){
        scanf("%lld", &array[i]);
    }
    qsort(array, amount, sizeof(long long int), compare);
    for(int i = 0; i < amount; ++i){
        printf("%lld ", array[i]);
    }
    printf("\n%lld", counter);
    return 0;
}