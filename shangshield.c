/*
ShangShield by Alyx Shang.
Licensed under the FSL v1.
*/

#include "shangshield.h"

enum str_type {
    Number,
    Letter,
    SpecialChar
};

int is_int(const char* subject){
    int result = 0;
    for (int i = 0; i < str_len(subject); i++){
        enum str_type char_type = string_type(subject[i]);
        if (char_type == Number){}
        else {
            result = 1;
        }
    }
    return result;
}

int convert_to_int(char* subject){
    int i = 0;
    int result = 0;
    while (subject[i] >= '0' && subject[i] <= '9') {
        result = result * 10 + map_char_to_digit(subject[i]);
        i++;
    }
}

int map_char_to_digit(char subject){
    int result = 0;
    if (subject == '0'){}
    else if (subject == '1'){
        result = 1;
    }
    else if (subject == '2'){
        result = 2;
    }
    else if (subject == '3'){
        result = 3;
    }
    else if (subject == '4'){
        result = 4;
    }
    else if (subject == '5'){
        result = 5;
    }
    else if (subject == '6'){
        result = 6;
    }
    else if (subject == '7'){
        result = 7;
    }
    else if (subject == '8'){
        result = 8;
    }
    else if (subject == '9'){
        result = 9;
    }
    else {}
    return result;
}

int digit_distance(
    int one,
    int two
) {
    int result = 0;
    if (one < two) {
        result = (one -two)*(-1);
    }
    else {
        result = one-two;
    }
    return result;
}

int str_len(const char* subject){
    int result = 0;
    while (*subject != '\0'){
        subject++;
        result++;
    }
    return result;
}

int get_position_from_char(
    char subject
) {
    int result = 0;
    const char* alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < str_len(alphabet); i++){
        if (alphabet[i] == subject){
            result = i + 1;
        }
        else {}
    }
    return result;
}

int is_letter(char subject) {
   int result = 1;
    const char* alphabet = "abcefghijklmnopqrstuvwxyz";
    for (int i = 0; i < str_len(alphabet);i++){
        if (alphabet[i] == subject){
            result = 0;
        }
        else {}
    }
    return result;
}

int is_digit(char subject) {
    int result = 1;
    const char* alphabet = "1234567890";
    for (int i = 0; i < str_len(alphabet);i++){
        if (alphabet[i] == subject){
            result = 0;
        }
        else {}
    }
    return result;
}

enum str_type string_type(char subject) {
    enum str_type char_type ;
    if (is_letter(subject) == 0){
        char_type = Letter;
    }
    else if (is_digit(subject) == 0){
        char_type = Number;
    }
    else {
        char_type = SpecialChar;
    }
    return char_type;
}

int reduce_characters_to_number(
    char subject,
    int letter_weight,
    int special_char_weight
) {
    int result = 0;
    enum str_type char_type = string_type(subject);
    if (char_type == Letter){
        int pos = get_position_from_char(subject);
        result = pos * letter_weight;
    }
    else if (char_type == Number){
        result = map_char_to_digit(subject);
    }
    else {
        result = special_char_weight;
    }
    return result;
}

int security_score(
    const char* pwd, 
    int letter_weight,
    int special_char_weight
){
    int score = 0;
    int last_idx = str_len(pwd) - 1;
    for (int i = 0; i < str_len(pwd); i++){
        char curr_char = pwd[i];
        int next_char_idx;
        if (i == last_idx){
            next_char_idx = i - 1;
        }
        else {
            next_char_idx = i + 1;
        }
        char next_char = pwd[next_char_idx];
        int curr_char_score = reduce_characters_to_number(
            curr_char,
            letter_weight,
            special_char_weight
        );
        int next_char_score = reduce_characters_to_number(
            next_char,
            letter_weight,
            special_char_weight
        );
        int distance = digit_distance(curr_char_score, next_char_score);
        score = score + distance;           
    }
    return score;
}

int is_secure(
    const char* pwd,
    int letter_weight,
    int special_char_weight,
    int cut_off
){
    int score = security_score(
        pwd,
        letter_weight,
        special_char_weight
    );
    int result = 1;
    if (score < cut_off){}
    else {
        result = 0;
    }
    return result;
}