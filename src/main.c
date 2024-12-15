/*
ShangShield by Alyx Shang.
Licensed under the FSL v1.
*/

#include <stdio.h>
#include "lib/cli.h"
#include "lib/shangshield.h"

int main(int argc, char* argv[]){
    char* output = cli(argc, argv);
    printf("%s\n", output);
    return 0;
}