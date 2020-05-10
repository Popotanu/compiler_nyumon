#include <stdio.h>
#include <stdlib.h>

/* 簡単のため入力はコマンドの第一引数として与える
 * 通常はファイルとして入力を与える
 * */
int main(int argc, char **argv) {
  if(argc != 2) {
    fprintf(stderr, "wrong number of argments\n");
    return 1;
  }

  printf(".intel_syntax noprefix\n");
  printf(".global main\n");
  printf("main:\n");
  printf("  mov rax, %d\n", atoi(argv[1]));
  printf("  ret\n");
  return 0;
}
