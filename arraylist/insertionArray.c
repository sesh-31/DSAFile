#include <stdio.h>

int main()
{
    int i, a[50], size, num, pos;
    printf("Enter the size of the array ");
    scanf("%d", &size);
    printf("Enter the elements of the array ");

    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the data you want to insert");
    scanf("%d", &num);
    printf("Enter postion you want to insert ");
    scanf("%d", &pos);
    if(pos>size+1 || pos==-1){
        printf("Invalid position");
    }
    else{
    for (i = size - 1; i >= pos - 1; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos - 1] = num;
    size++;
    for (i = 0; i < size; i++)
    {
        printf("%d",a[i]);
    }
    }
}