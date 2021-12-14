
/*
    Author: Mohamed Ashraf (Wx)
    Date: 31/9/2021
    Type: Database for items.
*/

// HEADER GUARDS: DB_H
#ifndef __Wx_C_DB_H__
#define __Wx_C_DB_H__

// HEADER LIBRARIES USED:
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <string.h>

//==================================================

/*****************************************************
*                    FUNCTION DECLARED               *
******************************************************/
//IPv4 GENERATOR FUNCTION:
uint8_t Ipv4_gen();

//IPv6 GENERATOR FUNCTION:
uint8_t Ipv6_gen();
void Ipv6_Print(void); // PRINTING IPv6.


/*****************************************************
*                  STRUCTRED DATA                    *
******************************************************/

// Main ID to increment IP's DATA:
uint16_t IP_ID = 0;

// IP System Structe:
typedef struct
{
  uint16_t id;
  uint8_t  ipv4;
  uint16_t ipv6;

  char code[20];

}WxDRONES;

WxDRONES DronexM[1];
WxDRONES *DxM = DronexM;

/*****************************************************
*                  IPvX HANDLE FUNCTIONS             *
******************************************************/

// IPv4 Structe:
typedef struct
{
  uint8_t
  // NETWORK PART:
      PANB[2],
      SASB : 8,
 //HOST PART:
      HB   : 8;

  /*
    IPv4 MAP:

    IPv4 =  [00000000]:[00000000]:[00000000]:[00000000] - 255:255:255:255
    <=============================IPv4==============================>

    * Provider-Assigned-Network-Bits [PANB]:16bits
    * Self-Assigned Subnet-Bits [SASB]:8bits
    * Host-Bits [HB]:8bits

    |TYPE:        [PANB]         [SASB]     [HB]    |
    |DATA:  Byte_1  : Byte_2  :  Byte_3  :  Byte_4  |
    |BITS:   [8]    :  [8]   :   [8]   :   [8]      |

    4xByte_ROW
    0.0.0.0
    <==============================================================>
  */
}IPv4;

IPv4 ipv4[1];
IPv4 *i4 = ipv4;

//========== IPv6 ===========

// IPv6 Structe:
typedef struct
{
// NETWORK PART:  00.00:00.00:00.00:00.00 (64 Bits-size) (00 = 8 bits)

  //Global_ID:  00.00:00.00:00.00 (x48bits)
  uint8_t
      Prefix_L : 7,
      GID_BIT  : 1,
      GID_bytes[5];
      // (Prefix_L + GID_BIT  + [0]) -> (16-Bits).
      // [1][2] -> (16-Bits).
      //[3][4] -> (16-Bits).

  //SASB: 00.00:00.00 (16-Bits).
  uint8_t SASB_bytes[2];
    //[0] -> (8-Bits).
    //[1] -> (8-Bits).

//HOST PART: (64 Bits-size)
  //Combined ID:  00.00:00.00 . . . (x64-bit)
  // (16-16-16-16-16-16-16-16) Bits
  uint8_t HB_Bytes[8];

  /*
    IPv6 MAP:
    IPv4 =  [00.00:00.00:00.00:00.00:00.00:00.00] . . (x64bit)
    =============================IPv6==============================

    * Provider-Assigned-Network-Bits [PANB]:48bits
    * Self-Assigned Subnet-Bits [SASB]:16bits
    * Host-Bits [HB]:64bits

    |TYPE:         [PANB]              [SASB]          [HB]      |
    |DATA: Prefix_L  : Global_ID  :  Subnet_ID  :  Combined_CID  |
    |BITS:   [7]     :    [41]    :     [16]    :      [64]      |

    (64 - 64) => 128 Bits-size of data.
    ==============================================================
  */
}IPv6;

IPv6  ipv6[1];
IPv6 *i6  = ipv6;


/*****************************************************
*                  DATA HANDLE FUNCTIONS             *
******************************************************/

//Ipv4 FUNCTION:
uint8_t Ipv4_gen()
{
  srand(time(NULL));

  //PANB section:
  for(uint8_t i = 0; (i < 2); i++)
    {
      (i4[IP_ID].PANB[i]) = rand();
      printf("%d:",(i4[IP_ID].PANB[i]));
    }//end for.

  //SASB section:
  (i4[IP_ID].SASB) = rand();
  printf("%d:",(i4[IP_ID].SASB));

  //HB section:
  (i4[IP_ID].HB)   = rand();
  printf("%d",(i4[IP_ID].HB));

  return 0;
} // end Ipv4_gen.

// IPv6 GENERATOR:
uint8_t Ipv6_gen()
{
  srand(time(NULL));

  //Global_ID section:
  //  2 BYTES (PREFIX_L + GID_BIT + GID_BYTES[0]):
  // TOTAL 2-BYTES.
  (i6[IP_ID].Prefix_L) = rand();
  printf("%x",i6[IP_ID].Prefix_L);

  (i6[IP_ID].GID_BIT)  = rand();
  printf("%x",i6[IP_ID].GID_BIT);

  (i6[IP_ID].GID_bytes[0]) = rand();
  printf("%x:",(i6[IP_ID].GID_bytes[0]));

  //  2 BYTES (GID_BYTES[1] + GID_BYTES[2]):
  //  2 BYTES (GID_BYTES[3] + GID_BYTES[4]):
  // TOTAL 4-BYTES.
  for(uint8_t i = 1; (i <= 4); i++)
    {
      (i6[IP_ID].GID_bytes[i]) = rand();
      printf("%x",(i6[IP_ID].GID_bytes[i]));

      if( (i%2 == 0) ) {printf(":");}
    }//end for.

  //SASB section:
  //  2 BYTES (SASB_bytes[0] + SASB_bytes[1]):
  // TOTAL 2-BYTES.
  for(uint8_t j = 1; (j <= 2); j++)
    {
      (i6[IP_ID].SASB_bytes[j-1]) = rand();
      printf("%x",(i6[IP_ID].SASB_bytes[j-1]));

      if( (j%2 == 0) ) {printf(":");}
    }//end for.

  //HB section:
  //  2 BYTES (HB_Bytes[0] + HB_Bytes[1]):
  //  2 BYTES (HB_Bytes[2] + HB_Bytes[3]):
  //  2 BYTES (HB_Bytes[4] + HB_Bytes[5]):
  //  2 BYTES (HB_Bytes[6] + HB_Bytes[7]):
  // TOTAL 8-BYTES.
  for(uint8_t k = 1; (k <= 8); k++)
    {
      (i6[IP_ID].HB_Bytes[k-1]) = rand();
      printf("%x",(i6[IP_ID].HB_Bytes[k-1]));

      if( (k%2 == 0) && (k != 8) )
      {printf(":");}
    }//end for.

  return 0;
} // end Ipv6_gen.


#endif
