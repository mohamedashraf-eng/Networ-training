
/*
    Author: Mohamed Ashraf (Wx)
    Date: 31/9/2021
    Type: Database for items.
*/

#include "Wx_C_DB.h"

void data(uint8_t);

int main(void)
{
  uint8_t c = 0;

  printf("id\tipv4\t\tipv6\n\n");
  data(c);
  printf("\n\n");
  c++;


  return 0;
}


void data(uint8_t counter)
{
  char Code[20] = "WxG1D4GxM";

  (DxM->id) = counter;
  printf("%d",(DxM->id));
  printf("\t");
  (DxM->ipv4) = Ipv4_gen();
  printf("\t");
  (DxM->ipv6) = Ipv6_gen();
  printf("\t");

  for(uint8_t i = 0; (Code[i] != '\0'); i++)
    {(DxM->code[i]) = Code[i];}

  printf("\n \nCode: %s%d\n",(DxM->code),counter);
  printf("IP_ID: %d",IP_ID);
  IP_ID++;
}
