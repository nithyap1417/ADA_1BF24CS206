#include <stdio.h>

void printPerm(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int getMobile(int a[], int dir[], int n)
{
    int i, mobile = 0;

    for(i = 0; i < n; i++)
    {
        if(dir[i] == -1 && i != 0 && a[i] > a[i - 1])
        {
            if(a[i] > mobile)
                mobile = a[i];
        }

        if(dir[i] == 1 && i != n - 1 && a[i] > a[i + 1])
        {
            if(a[i] > mobile)
                mobile = a[i];
        }
    }

    return mobile;
}

int main()
{
    int n, i, j;

    printf("Enter n: ");
    scanf("%d", &n);

    int a[n], dir[n];

    for(i = 0; i < n; i++)
    {
        a[i] = i + 1;
        dir[i] = -1;      // -1 = LEFT, 1 = RIGHT
    }

    printPerm(a, n);

    while(1)
    {
        int mobile = getMobile(a, dir, n);

        if(mobile == 0)
            break;

        int pos;
        for(i = 0; i < n; i++)
        {
            if(a[i] == mobile)
            {
                pos = i;
                break;
            }
        }

        if(dir[pos] == -1) // move left
        {
            int temp = a[pos];
            a[pos] = a[pos - 1];
            a[pos - 1] = temp;

            temp = dir[pos];
            dir[pos] = dir[pos - 1];
            dir[pos - 1] = temp;

            pos--;
        }
        else // move right
        {
            int temp = a[pos];
            a[pos] = a[pos + 1];
            a[pos + 1] = temp;

            temp = dir[pos];
            dir[pos] = dir[pos + 1];
            dir[pos + 1] = temp;

            pos++;
        }

        for(i = 0; i < n; i++)
        {
            if(a[i] > mobile)
                dir[i] = -dir[i];
        }

        printPerm(a, n);
    }

    return 0;
}