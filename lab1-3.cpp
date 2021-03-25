#include <stdio.h>
bool IsTherePoint(char num[])
{
    for (int i = 0; num[i] != '\0'; ++i)
    {
        if (num[i] == '.')
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char float1[110] = { 0 }, float2[110] = { 0 };
        int integer1[110] = { 0 }, integer2[110] = { 0 };
        int newinteger[110] = { 0 };
        scanf("%s %s", float1, float2);
        int num_of_integer1 = 0, num_of_integer2 = 0;
        if (IsTherePoint(float1))
        {
            for (; float1[num_of_integer1] != '.'; ++num_of_integer1)
            {
                integer1[num_of_integer1] = float1[num_of_integer1] - '0';
            }
        }
        else
        {
            for (; float1[num_of_integer1] != '\0'; ++num_of_integer1)
            {
                integer1[num_of_integer1] = float1[num_of_integer1] - '0';
            }
        };
        if (IsTherePoint(float2))
        {
            for (; float2[num_of_integer2] != '.'; ++num_of_integer2)
            {
                integer2[num_of_integer2] = float2[num_of_integer2] - '0';
            }
        }
        else
        {
            for (; float2[num_of_integer2] != '\0'; ++num_of_integer2)
            {
                integer2[num_of_integer2] = float2[num_of_integer2] - '0';
            }
        }
        for (int j = 0, k = num_of_integer1 - 1; j < k; j++, k--)
        {
            int temp = integer1[j];
            integer1[j] = integer1[k];
            integer1[k] = temp;
        }
        for (int j = 0, k = num_of_integer2 - 1; j < k; j++, k--)
        {
            int temp = integer2[j];
            integer2[j] = integer2[k];
            integer2[k] = temp;
        }
        int bit_of_newinteger = (num_of_integer1 >= num_of_integer2) ? num_of_integer1 : num_of_integer2;
        for (int j = 0; j < bit_of_newinteger; ++j)
        {
            int sum = integer1[j] + integer2[j] + newinteger[j];
            newinteger[j] = 0;
            if (sum >= 10)
            {
                sum = sum - 10;
                newinteger[j + 1] += 1;
            }
            newinteger[j] += sum;
        }
        while (newinteger[bit_of_newinteger] == 0)
        {
            bit_of_newinteger -= 1;
        }
        int decimals1[101] = { 0 }, decimals2[101] = { 0 };
        int newdecimals[110] = { 0 };
        int num_of_decimals1 = 1, num_of_decimals2 = 1;
        for (; float1[num_of_integer1 + num_of_decimals1] != '\0'; num_of_decimals1++)
        {
            decimals1[num_of_decimals1] = float1[num_of_integer1 + num_of_decimals1] - '0';
        }
        for (; float2[num_of_integer2 + num_of_decimals2] != '\0'; num_of_decimals2++)
        {
            decimals2[num_of_decimals2] = float2[num_of_integer2 + num_of_decimals2] - '0';
        }
        int bit_of_newdecimals = (num_of_decimals1 >= num_of_decimals2) ? num_of_decimals1 : num_of_decimals2;
        for (int j = bit_of_newdecimals; j > 0; j--)
        {
            int sum = decimals1[j] + decimals2[j] + newdecimals[j];
            newdecimals[j] = 0;
            if (sum >= 10)
            {
                sum = sum - 10;
                newdecimals[j - 1] += 1;
            }
            newdecimals[j] += sum;
        }
        while (newdecimals[bit_of_newdecimals] == 0)
        {
            bit_of_newdecimals -= 1;
        }
        if (newdecimals[0] != 0)
        {
            newinteger[0] = newdecimals[0] + newinteger[0];
            if (newinteger[0] >= 10)
            {
                newinteger[0] -= 10;
                int k = 1;
                newinteger[k] += 1;
                while (newinteger[k] >= 10)
                {
                    newinteger[k] -= 10;
                    newinteger[k + 1] += 1;
                    k += 1;
                }
            }
        }
        if (newinteger[bit_of_newinteger] != 0)
        {
            for (int j = 0, k = bit_of_newinteger; j < k; j++, k--)
            {
                int temp = newinteger[j];
                newinteger[j] = newinteger[k];
                newinteger[k] = temp;
            }
        }
        else
        {
            for (int j = 0, k = bit_of_newinteger - 1; j < k; j++, k--)
            {
                int temp = newinteger[j];
                newinteger[j] = newinteger[k];
                newinteger[k] = temp;
            }
            bit_of_newinteger -= 1;
        }
        if (bit_of_newinteger <= 0)
            bit_of_newinteger = 0;
        for (int j = 0; j <= bit_of_newinteger; j++)
        {
            printf("%d", newinteger[j]);
        }
        if (bit_of_newdecimals >= 1)
        {
            putchar('.');
        }
        for (int j = 1; j <= bit_of_newdecimals; j++)
        {
            printf("%d", newdecimals[j]);
        }
        printf("\n");
    }
    return 0;
}