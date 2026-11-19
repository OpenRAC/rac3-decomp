#include "common.h"

/* declared by functions of L39_0050F5B8.c, which this file was cut from */
typedef struct {
    u8 *a;
    u32 b;
} P_0050F5B8;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    P_0050F5B8 pr;
    s32 f14;
    s32 f18;
    s32 f1C;
} A_0050F5B8;
typedef struct {
    s32 flags;
    s32 (*handler)(A_0050F5B8 *, void *);
    s32 f8;
    s32 tag;
    char *name;
} I_0050F5B8;
typedef struct O_0050F5B8 {
    s32 (**vt)(struct O_0050F5B8 *, s32 *, s32 *);
    u8 *f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
} O_0050F5B8;
extern s32 func_L39_0050FDC8(s32 *, s32 *, s32 *, P_0050F5B8 *, s32, s32);
extern void func_L39_0050D780(s32 *);
extern s32 func_L39_00510008(s32 *, I_0050F5B8 *, void **, s32, s32, O_0050F5B8 *, s32, P_0050F5B8 *, s32 *);

INCLUDE_ASM("asm/levels", func_L39_0050FDC8);

INCLUDE_ASM("asm/levels", func_L39_00510008);
