#include <stdio.h>

int code();
//int decode();
// 
int main(int argc, char *argv[]) {
//
//    int mode;
//    sscanf(argv[1], "%d", &mode);
//
//    if (mode) {
//        decode();
//    } else {
//        code();
//    }
//
   return 0;
}


// Функция кодирования -- срабатывает, если на вход подается 0
// переводит буквы в 16-ричную систему

int code() {

   char first_char;
   char current_char;

   first_char = getchar();

   while ((current_char = getchar()) != '\n') {
       if ((first_char != ' ') && (current_char != ' ')) {
           printf("n/a");
           return 1;
       }

       if (first_char != ' ') {
           printf("%X", first_char);
       }

       if (first_char == ' ') {
           printf("%c", first_char);
       }

       first_char = current_char;
   }

   return 0;
}

// Функция декодирования -- срабатывает, если на вход подается 1
// переводит из 16-ричной системы в символы

//int decode() {
// 
// 
//     return 0;
// }
