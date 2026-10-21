#include "common.h"

typedef void (*fn_3A2780)(u8 *);

INCLUDE_ASM("asm/levels", func_L01_0039E1B0);

LINKER_REMNANT("asm/levels", func_L01_0039F0F0);

INCLUDE_ASM("asm/levels", func_L01_0039F0F8);

INCLUDE_ASM("asm/levels", func_L01_0039FBD0);

INCLUDE_ASM("asm/levels", func_L01_0039FEB0);

INCLUDE_ASM("asm/levels", func_L01_003A0528);

INCLUDE_ASM("asm/levels", func_L01_003A0710);

INCLUDE_ASM("asm/levels", func_L01_003A0778);

INCLUDE_ASM("asm/levels", func_L01_003A33C0);

INCLUDE_ASM("asm/levels", func_L01_003A39A0);

/* localdecomp:start func_L01_003A3EC8 */

extern fn_3A2780 *func_L01_0043B548(s32, s32);
extern void func_L01_003A4810(u8 *);
extern void func_003C2880(u8 *);

void func_L01_003A3EC8(u8 *a0, s32 a1) {
    u8 *pv = *(u8 **)(a0 + 104);
    fn_3A2780 *tbl;
    if (*(s32 *)(pv + 576) != 0) {
        tbl = func_L01_0043B548(6625, 108);
        tbl[0](a0);
        if (a1 != 0) {
            tbl[1](a0);
        }
    } else if (*(s32 *)(pv + 1052) != 0) {
        func_L01_003A4810(a0);
    } else {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L01_003A3EC8 */

INCLUDE_ASM("asm/levels", func_L01_003A3F68);

INCLUDE_ASM("asm/levels", func_L01_003A4180);

INCLUDE_ASM("asm/levels", func_L01_003A4320);

INCLUDE_ASM("asm/levels", func_L01_003A43F8);

INCLUDE_ASM("asm/levels", func_L01_003A44C8);

/* localdecomp:start func_L01_003A45F0 */
void func_L01_003A45F0(u8 *a) {
    *(s32 *)(*(u8 **)(a + 0x68) + 0x3B8) = 0;
}
/* localdecomp:end func_L01_003A45F0 */

/* localdecomp:start func_L01_003A4600 */
extern u8 *func_L01_00449050(u8 *);
extern void func_003C3A10(u8 *, s32, s32, s32);

void func_L01_003A4600(u8 *m, u8 *other) {
    u8 *v = *(u8 **)(m + 104);
    u8 *r = func_L01_00449050(m);
    s32 *s = *(s32 **)(other + 104);
    u8 *rv = *(u8 **)(*(u8 **)(r + 8) + 104);

    *(s32 *)(v + 720) = s[0];
    if (0.0f < ((f32 *)s)[1]) {
        *(f32 *)(v + 724) = ((f32 *)s)[1];
    }
    *(s32 *)(v + 728) = s[2];
    if (0.0f < ((f32 *)s)[3]) {
        *(f32 *)(v + 732) = ((f32 *)s)[3];
    }
    *(s32 *)(v + 748) = s[4];
    *(s32 *)(v + 760) = s[5];
    *(s32 *)(v + 764) = s[6];
    *(s32 *)(v + 936) = s[7];
    *(s32 *)(v + 944) = s[8];
    *(s32 *)(v + 960) = s[23];
    *(s32 *)(v + 968) = s[10];
    *(s32 *)(v + 972) = s[11];
    *(s32 *)(v + 976) = s[26];
    *(s32 *)(v + 1040) = s[29];
    *(s32 *)(v + 1044) = s[30];
    *(s32 *)(v + 1060) = s[34];
    *(s32 *)(v + 948) = *(s32 *)(rv + 120);
    if (m[67] != 0) {
        func_003C3A10(m, 0, 0, 0);
    }
}
/* localdecomp:end func_L01_003A4600 */

INCLUDE_ASM("asm/levels", func_L01_003A4708);

/* localdecomp:start func_L01_003A4720 */
extern void func_L01_003A3EC8_003A4720(u8 *a0, s32 a1);
extern void func_L01_003A4720(void *p);
extern void func_L01_003A4720(void *);

 
void func_L01_003A4720(void *p) {
    ((void (*)(void *, s32))func_L01_003A3EC8_003A4720)(p, 0);
}
/* localdecomp:end func_L01_003A4720 */

INCLUDE_ASM("asm/levels", func_L01_003A4740);

INCLUDE_ASM("asm/levels", func_L01_003A4810);

INCLUDE_ASM("asm/levels", func_L01_003A4910);

/* localdecomp:start func_L01_003A4938 */
extern s32 D_L01_001DE2C0;
extern s32 D_L01_001DE2E0;
s32 *func_L01_003A4938(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 5:
        *a2 = 12;
        return &D_L01_001DE2E0;
    case 1:
        *a2 = 28;
        return &D_L01_001DE2C0;
    }
    return 0;
}
/* localdecomp:end func_L01_003A4938 */
