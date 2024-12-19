#include <locale.h>
#include <stdio.h>

int main(void)
{
    setlocale(LC_NUMERIC, "");
    printf("$%'.2lf\n", (double)123456789.00L);
    printf("$%'.2lf\n", (double)1234.56L);
    printf("$%'.2lf\n", (double)123.45L);

    return 0;
}
