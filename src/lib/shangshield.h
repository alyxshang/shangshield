/*
ShangShield by Alyx Shang.
Licensed under the FSL v1.
*/

#define SHANGSHIELD_H
#ifndef SHANGSHIELD_H

enum str_type;
int is_digit(char subject);
int is_letter(char subject);
int is_int(const char* subject);
int str_len(const char* subject);
int convert_to_int(char* subject);
int map_char_to_digit(char subject);
int digit_distance(int one, int two);
enum str_type string_type(char subject);
int get_position_from_char(char subject);
int str_comp(const char* one, const char* two);
int security_score(const char* pwd, int letter_weight,int special_char_weight);
int isSecure(const char* pwd, int letter_weight, int special_char_weight, int cut_off);
int reduce_characters_to_number(char subject, int letter_weight, int special_char_weight);

#endif