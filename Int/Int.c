#include "..\GlobalTypes.h"
#include "IntCmp.c"
#include "IntFunctions.c"
#include <stdio.h>
#include <stdlib.h>


int main() {
  ijolInt *a;
  InitInt(&a);
  printf("A = ");
  SetInt(&a, "-1234567890123456787");
  PrintInt(&a);
  ijolInt *b;
  InitInt(&b);
  printf("B = ");
  SetInt(&b, "-1234567890123456789");
  PrintInt(&b);

  printf("A == B:\n");
  if (ijolIntsEqual(&a, &b))
    printf("   Sim\n");
  else
    printf("   Nao\n");

  printf("A != B:\n");
  if (ijolIntsInequal(&a, &b))
    printf("   Sim\n");
  else
    printf("   Nao\n");

  EndInt(&a);
  EndInt(&b);
  printf("\nfim >:)");
}
