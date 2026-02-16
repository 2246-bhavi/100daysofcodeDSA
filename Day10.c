//Read a string and check if it is a palindrome using two-pointer comparison.

#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int start, end;
    int ok = 1;

    printf("Enter a string: ");
    scanf("%s", s);

    start = 0;
    end = strlen(s) - 1;

    while(start < end)
    {
        if(s[start] != s[end])
        {
            ok = 0;
            break;
        }
        start++;
        end--;
    }

    if(ok == 1)
        printf("YES");
    else
        printf("NO");

    return 0;
}
