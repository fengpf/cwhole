//
// Created by fpf on 2020-04-22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct {
    char *buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

typedef enum {
    EXECUTE_SUCCESS,
    EXECUTE_DUPLICATE_KEY,
}ExecuteResult;

 InputBuffer* new_input_buffer(){
     InputBuffer *inputBuffer = (InputBuffer*)malloc(sizeof(InputBuffer));
     inputBuffer->buffer = NULL;
     inputBuffer->buffer_length = 0;
     inputBuffer->input_length = 0;
     return inputBuffer;
 }

//ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void print_prompt() {
     printf("db > ");
 }

void read_input(InputBuffer *inputBuffer){
    ssize_t bytes_read = getline(&(inputBuffer->buffer), &(inputBuffer->buffer_length), stdin);

    if (bytes_read<=0){
        printf("error read input\n");
        exit(EXIT_FAILURE);
    }

    inputBuffer->input_length = bytes_read-1;
    inputBuffer->buffer[bytes_read-1] = 0;
 }

 void close_input_buffer(InputBuffer *inputBuffer){
     free(inputBuffer->buffer);
     free(inputBuffer);
 }

int main(int argc, char *argv[]) {
    InputBuffer *inputBuffer = new_input_buffer();

    while(true){
        print_prompt();
        read_input(inputBuffer);

        if (strcmp(inputBuffer->buffer, "exit") ==0){
             close_input_buffer(inputBuffer);
            printf("bye\n");
            exit(EXIT_SUCCESS);
        } else {
            printf("Unrecognized command '%s' .\n", inputBuffer->buffer);
        }
    }
}