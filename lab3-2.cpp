#include <cstdio>
#include <cstdlib>
#include <cstring>
const char nanjing[11] = "Nanjing";
int strlength(const char str[]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}
bool IsTheSameTwoStr(const char str1[], const char str2[]){
    if(strlength(str1) != strlength(str2)){
        return false;
    }
    else{
        int length = strlength(str1);
        for(int i = 0; i < length; ++i){
            if(str1[i] != str2[i]){
                return false;
            }
        }
        return true;
    }
}
struct Student
{
    int id;
    char name[11];
    int age;
    char birthplace[11];
    double score;
};
void StrSWap(char str1[], char str2[], int len2)
{
    for (int i = 0; i < len2; ++i)
    {
        char temp = str1[i];
        str1[i] = str2[i];
        str2[i] = temp;
    }
}
void convert_file(const char *src, const char *dst)
{
    FILE *fptr;
    FILE *taget;
    if ((fptr = fopen(src, "r")) == nullptr || (taget = fopen(dst, "ab+")) == nullptr)
    {
        //printf("You are a sb.\n");
        exit(-1);
    }
    Student kid = {0, "0", 0, "0", 0.};
    while ((fscanf(fptr, "%d %s %d %s %le", &kid.id, kid.name, &kid.age, kid.birthplace, &kid.score)) != EOF)
    {
        fwrite(&kid, sizeof(Student), 1, taget);
    }
    if (fclose(fptr) != 0 || fclose(taget) != 0)
    {
        //printf("You are a sb, again.\n");
        exit(-1);
    }
    return;
}

void modify_file(const char *src, const char *dst)
{
    FILE *fptr;
    FILE *taget;
    if ((fptr = fopen(src, "rb")) == nullptr || (taget = fopen(dst, "ab+")) == nullptr)
    {
        //printf("You are a sb.\n");
        exit(-1);
    }
    Student kids[110];
    int i = 0;
    while (feof(fptr) == 0)
    {
        (fread(&kids[i], sizeof(Student), 1, fptr));
        ++i;
    }
    i = i - 1;
    for (int j = 0; j < i; ++j)
    {
        if (IsTheSameTwoStr(kids[j].birthplace,nanjing))
        {
            kids[j].id = kids[j].id % 10000000 + 170000000;
        }
    }
    for (int j = 0; j < i; ++j)
    {
        int max_index = j;
        for (int k = j + 1; k < i; k++)
        {
            if (kids[k].score > kids[max_index].score)
            {
                max_index = k;
            }
            else if (kids[k].score == kids[max_index].score && kids[k].id < kids[max_index].id)
            {
                max_index = k;
            }
        }
        if (max_index != j)
        {
            int temp_id = kids[j].id;
            int temp_age = kids[j].age;
            double temp_score = kids[j].score;

            kids[j].id = kids[max_index].id;
            kids[j].age = kids[max_index].age;
            kids[j].score = kids[max_index].score;

            kids[max_index].id = temp_id;
            StrSWap(kids[max_index].name, kids[j].name, 11);
            kids[max_index].age = temp_age;
            StrSWap(kids[max_index].birthplace, kids[j].birthplace, 11);
            kids[max_index].score = temp_score;
        }
    }
    for (int j = 0; j < i; j++)
    {

        fwrite(&kids[j], sizeof(Student), 1, taget);
    }
    if (fclose(fptr) != 0 || fclose(taget) != 0)
    {
        //printf("fool.\n ");
        exit(-1);
    }
    return;
}

void print_file(const char *src)
{
    FILE *fptr;
    if ((fptr = fopen(src, "rb")) == nullptr)
    {
        //printf("You are a sb.\n");
        exit(-1);
    }
    Student kids[110];
    int i = 0;
    while (feof(fptr) == 0)
    {
        (fread(&kids[i], sizeof(Student), 1, fptr));
        ++i;
    }
    i = i - 1;
    for (int j = 0; j < i; ++j)
    {
        printf("%d %s %d %s %.1f\n", kids[j].id, kids[j].name, kids[j].age, kids[j].birthplace, kids[j].score);
    }
    if(fclose(fptr) != 0){
        //printf("sb again.\n");
        exit(-1);
    }
    return ;
}

int main()
{   
    convert_file("student.txt", "tring.txt");
    modify_file("tring.txt", "another.txt");
    print_file("tring.txt");
    puts("\n");
    print_file("another.txt");
    return 0;
}
