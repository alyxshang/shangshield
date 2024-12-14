/*
ShangShield by Alyx Shang.
Licensed under the FSL v1.
*/

#include <stdio.h>
#include "shangshield.h"

int main(int argc, char* argv[]){
    const char* output = cli(argc, argv);
    printf("%s\n", output);
}