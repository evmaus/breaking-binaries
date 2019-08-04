
#include <stdio.h>
#include <string.h>

void hello(char* toGreet) {
  char buffer[100];
  strcpy(buffer, toGreet);
  printf("Hello %s \n", buffer);
}

int main(int argc, char** argv) {
  if (argc <= 1) {
    printf("Who to greet? \n");
    return 0;
  }
  hello(argv[1]);
  return 0;
}