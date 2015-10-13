#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* string;
} String;

String* newString(char stringData[]) {
    String* string = malloc(sizeof(String));
    string->string = malloc(sizeof(char) * (strlen(stringData) + 1));
    strcpy(string->string, stringData);
    return string;
}

void deleteString(String* this) {
    free(this->string);
    free(this);
}

// インスタンスメソッド
void String_show(String* this) {
    printf("%s\n", this->string);
}
int Strng_getLength(String* this) {
    return strlen(this->string);
}

int main() {
    String* a = newString("あいうえお");
    String_show(a);
    deleteString(a);
    return 0;
}
