#include "argparse.h"


char isNumber(char *input) {
    for (int i = 0; input[i] != '\0'; i++)
        if (isalpha(input[i]))
            return 0;
    return 1;
}
