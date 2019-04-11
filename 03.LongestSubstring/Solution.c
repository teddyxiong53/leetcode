#include <stdio.h>

int lengthOfLongestSubstring(char *s)
{
    int len = strlen(s);
    int *set = (int *)malloc(128 * sizeof(int));
    memset(set, 0, 128 * sizeof(int));
    int i = 0, j = 0;
    int maxlen = 0;
    while (i < len && j < len)
    {
        if (!set[s[j]])
        {
            set[s[j++]] = 1;
            if (j - i >= maxlen)
            {
                maxlen = j - i;
            }
        }
        else
        {
            set[s[i++]] = 0;
        }
    }

    return maxlen;
}

int main()
{
    printf("length:%d\n", lengthOfLongestSubstring("abcabcbb"));
}