#include <stdio.h>
#include <stdlib.h>
#include "primetest.h"
#include "primebench.h"
#include "docopt.c"

int main(int argc, char *argv[]) {

  DocoptArgs args = docopt(argc, argv, /* help */ 1, /* version */ "0.1 ALPHA");

    printf("Arguments\n");
    printf("    s == %s\n", args.startnum);
    printf("    e == %s\n", args.endnum);
    printf("Flags\n");
    printf("    --help == %s\n", args.help ? "true" : "false");
    printf("    --verbose == %s\n", args.verbose ? "true" : "false");
    printf("    --version == %s\n", args.version ? "true" : "false");
    printf("Options\n");
    printf("    --threads == %s\n", args.threads);

  return 0;
}

