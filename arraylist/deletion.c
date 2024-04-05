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

    printf("Enter postion you want to delete ");
    scanf("%d", &pos);
    if(pos>size || pos<=0){
        printf("Invalid position");
    }
    else{
    for (i = pos - 1; i<size-1; i++)
    {
        a[i] = a[i + 1];
    }
    size--;
    for (i = 0; i < size; i++)
    {
        printf("%d",a[i]);
    }
    }
}
