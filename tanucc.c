#include <stdio.h>
#include <stdlib.h>

/* 簡単のため入力はコマンドの第一引数として与える
 * 通常はファイルとして入力を与える
 * */
int main(int argc, char **argv) {
  if(argc != 2) {
    fprintf(stderr, "引数の数が正しくない\n");
    return 1;
  }

  char *p = argv[1];

  printf(".intel_syntax noprefix\n");
  printf(".global main\n");
  printf("main:\n");

  /* strtol
   * 数値を読み込んだあと、第2引数のポインタをアップデートして、
   * 読み込んだ最後の文字、の次の文字を指すよう値を更新する。
   */
  printf("  mov rax, %d\n", strtol(p, &p, 10));

  while (*p) {
    /* strtolを通っているので、*pは次の文字を指す */
    if(*p == '+') {
      p++;
      printf("  add rax, %d\n", strtol(p, &p, 10));
      continue;
    }

    if(*p == '-') {
      p++;
      printf("  sub rax, %d\n", strtol(p, &p, 10));
      continue;
    }

    fprintf(stderr, "unexpected char: %c\n", *p);
    return 1;
  }

  printf(" ret\n");
  return 0;
}
