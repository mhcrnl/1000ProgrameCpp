          #include <stdio.h>
    #include <string.h>
    int main(void) {
        char s[10] = "ABCDE";

        strcat(s + 2, "ABCDE");
        printf("%d", s[0] - s[2]);
        return 0;
    }
