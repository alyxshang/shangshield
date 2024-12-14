/*
ShangShield by Alyx Shang.
Licensed under the FSL v1.
*/

#include "shangshield.h"

char* cli(int argc, char* argv[]){
    char* result = "";
    if (argc == 5){
        if (argv[1] != "" && 
            is_int(argv[2]) == 0 &&
            is_int(argv[3]) == 0 &&
            is_int(argv[4]) == 0
        ){
            int cut_off = argv[4];
            const char* pwd = argv[1];
            int letter_weight = convert_to_int(argv[2]);
            int special_char_weight = convert_to_int(argv[3]);
            int score = security_score(
                pwd, 
                letter_weight, 
                special_char_weight
            );
            int security_status = is_secure(pwd,
                letter_weight,
                special_char_weight,
                cut_off
            );
                        
        }
        else {
            result = "Invalid arguments supplied.";
        }
    }
    else {
        result = "Invalid usage.";
    }
    return result;
}