#include "..\GlobalTypes.h"
#include "IntCmp.c"
#include "IntFunctions.c"
#include <stdio.h>
#include <stdlib.h>


int main() {
  ijolInt *a;
  ijolInt *b;
  bool n;
  InitInt(&a);
  InitInt(&b);


  n++;
  printf("Test %u\n", n);
  printf("A = ");
  SetInt(&a, "-0");
  PrintInt(&a);
  printf("B = ");
  SetInt(&b, "0");
  PrintInt(&b);

  printf(": A == B:\n");
  if (ijolIntEqual(&a, &b))
    printf("   Sim\n");
  else
    printf("   Nao\n");

  printf(": A != B:\n");
  if (ijolIntInequal(&a, &b))
    printf("   Sim\n");
  else
    printf("   Nao\n");

  printf(": A > B:\n");
  if (ijolIntGreater(&a, &b))
    printf("   Sim\n");
  else
    printf("   Nao\n");

  printf(": A >= B:\n");
  if (ijolIntGreaterEqual(&a, &b))
    printf("   Sim\n");
  else
    printf("   Nao\n");

  printf(": A < B:\n");
  if (ijolIntLesser(&a, &b))
    printf("   Sim\n");
  else
    printf("   Nao\n");

  printf(": A <= B:\n");
  if (ijolIntLesserEqual(&a, &b))
    printf("   Sim\n");
  else
    printf("   Nao\n");

  printf(": A || B:\n");
  if (ijolIntOr(&a, &b))
    printf("   Sim\n");
  else
    printf("   Nao\n");

  printf(": A && B:\n");
  if (ijolIntAnd(&a, &b))
    printf("   Sim\n");
  else
    printf("   Nao\n");

  printf(": !A:\n");
  if (ijolIntNot(&a))
    printf("   Sim\n");
  else
    printf("   Nao\n");

printf("signed: A == B:\n");
  if (ijolIntsEqual(&a, &b))
    printf("   Sim\n");
  else
    printf("   Nao\n");

printf("signed: A != B:\n");
  if (ijolIntsInequal(&a, &b))
    printf("   Sim\n");
  else
    printf("   Nao\n");

printf("signed: A > B:\n");
  if (ijolIntsGreater(&a, &b))
    printf("   Sim\n");
  else
    printf("   Nao\n");

printf("signed: A >= B:\n");
  if (ijolIntsGreaterEqual(&a, &b))
    printf("   Sim\n");
  else
    printf("   Nao\n");

printf("signed: A < B:\n");
  if (ijolIntsLesser(&a, &b))
    printf("   Sim\n");
  else
    printf("   Nao\n");

printf("signed: A <= B:\n");
  if (ijolIntsLesserEqual(&a, &b))
    printf("   Sim\n");
  else
    printf("   Nao\n");



  EndInt(&a);
  EndInt(&b);
  printf("\nfim >:)");
}
