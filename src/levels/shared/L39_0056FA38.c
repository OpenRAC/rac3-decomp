#include "common.h"

/* declared by functions of L39_0056F820.c, which this file was cut from */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x200];
    u8 b200[0x30];
    u128_t q230;
    u8 p240[0x2A0 - 0x240];
    s16 h2A0;
    u8 p2A2[0x2C0 - 0x2A2];
    f32 f2C0;
    u8 p2C4[0x460 - 0x2C4];
} E_0056F820;
extern E_0056F820 D_L39_0024DE80[];

INCLUDE_ASM("asm/levels", func_L39_0056FA38);
