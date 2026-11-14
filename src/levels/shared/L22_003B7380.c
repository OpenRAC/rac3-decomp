#include "common.h"

typedef struct {
    u8 p0[4];
    s32 n[16];
    s32 b[16];
    s32 a[16];
    u8 p1[0x188 - 0xC4];
} Rec188;

INCLUDE_ASM("asm/levels", func_L22_003B7380);

INCLUDE_ASM("asm/levels", func_L22_003B7A70);

INCLUDE_ASM("asm/levels", func_L22_003B7C20);

/* localdecomp:start func_L22_003B8100 */
/* PAL port of the NTSC-U match src/us/levels/func_L22_003B6840.c */
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_00381FF0(s32);
extern void func_L22_003B7A70(s32);

void func_L22_003B8100(u8 *a0) {
    u8 *p;
    s32 i;

    p = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 0x14 || a0[0x20] == 0x12 || a0[0x20] == 0x13) {
        func_L01_00516AA0(0x120094, 1, 0);
        func_L22_003B7A70(func_00381FF0(0x15F3));
    } else if (a0[0x20] == 0x15) {
        func_L01_00516AA0(0x12008E, 1, 0);
        func_L01_00516AA0(0x12008D, 1, 0);
        for (i = 0; i < 0x10; i++) {
            func_L01_00516AA0(0x120044 + i, 1, 0);
            func_L01_00516AA0(0x120055 + i, 1, 0);
            func_L01_00516AA0(0x120066 + i, 1, 0);
            func_L01_00516AA0(0x120077 + i, 1, 0);
            func_L01_00516AA0(0x120000 + i, 1, 0);
            func_L01_00516AA0(0x120011 + i, 1, 0);
            func_L01_00516AA0(0x120022 + i, 1, 0);
            func_L01_00516AA0(0x120033 + i, 1, 0);
        }
        func_L01_00516AA0(0x120094, 1, 1);
    } else if (a0[0x20] == 0x17 || a0[0x20] == 0x1A) {
        func_L01_00516AA0(0x12008E, 1, 1);
        func_L01_00516AA0(0x12008D, 1, 0);
        func_L22_003B7A70(func_00381FF0(*(s32 *)(p + 0x4AC)));
    } else if (a0[0x20] == 0x16) {
        func_L01_00516AA0(0x12008E, 1, 0);
        func_L01_00516AA0(0x12008D, 1, 1);
        if (*(u16 *)(a0 + 0x96) >= 26) {
            func_L01_00516AA0(0x120094, 1, 0);
        }
        func_L22_003B7A70(func_00381FF0(*(s32 *)(p + 0x4AC)));
    } else if (a0[0x20] == 0x18 || a0[0x20] == 0x19) {
        func_L01_00516AA0(0x120094, 1, 0);
        func_L22_003B7A70(func_00381FF0(*(s32 *)(p + 0x4AC)));
    }
}
/* localdecomp:end func_L22_003B8100 */

/* localdecomp:start func_L22_003B83A0 */
/* PAL port of the NTSC-U match src/us/levels/func_L22_003B6AE0.c */


extern void func_L01_00436660(void *, s32, s32);
extern void func_L01_00448248(void *, s32, s32);
extern void func_L22_003B7C20(s32, s32, s32, f32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern u8 D_L22_002A21B0[];
extern Rec188 D_L22_002BA430[];
extern s32 D_L22_001E1FB8;
__asm__(".extern D_L22_001E1FB8, 16");
extern s32 D_L22_001E1FC0[2];
__asm__(".extern D_L22_001E1FC0, 64");
extern s32 D_L22_001E2000[2];
__asm__(".extern D_L22_001E2000, 64");
extern s32 D_L22_001E2040[2];
__asm__(".extern D_L22_001E2040, 64");
extern s32 D_L22_001E2080;
__asm__(".extern D_L22_001E2080, 16");
extern s32 D_L22_001E2084;
__asm__(".extern D_L22_001E2084, 16");
extern f32 D_L22_001DE4F0;
__asm__(".extern D_L22_001DE4F0, 4");
extern f32 D_L22_001DE4F4;
__asm__(".extern D_L22_001DE4F4, 4");

void func_L22_003B83A0(u8 *obj) {
    u8 *p;
    Rec188 *rec;
    s32 i;

    p = *(u8 **)(obj + 0x68);
    if (obj[0x20] == 0x16 || obj[0x20] == 0x17 || obj[0x20] == 0x1A || obj[0x20] == 0x14 || obj[0x20] == 0x19) {
        func_L01_00436660(D_L22_002A21B0, 2, 0);
    }
    if (obj[0x20] == 0x18 && *(u16 *)(obj + 0x96) >= 100) {
        func_L01_00436660(D_L22_002A21B0, 2, 0);
    }
    if (obj[0x20] == 0x15 || obj[0x20] == 0x16 || obj[0x20] == 0x1A || obj[0x20] == 0x17) {
        rec = &D_L22_002BA430[*(s32 *)(p + (*(s32 *)(p + 0x498) << 2) + 0x4C0)];
        for (i = 0; rec->n[i] > 0; i++) {
            if (rec->a[i] == 0 && D_L22_001E2084 < 0 && D_L22_001E1FB8 >= i && (D_L22_001E2080 == 0 || i < D_L22_001E1FB8)) {
                func_L01_00448248(&D_L22_001E1FC0[i], rec->b[i], 1);
                func_L01_00448248(&D_L22_001E2000[i], rec->b[i], 1);
            }
            func_L22_003B7C20(i + 0x120044, rec->n[i], i == D_L22_001E2084,
                              (f32)(rec->b[i] - *(s32 *)(p + 0x49C)) / 225.0f + 0.5f,
                              (f32)(rec->b[i] + rec->a[i] - *(s32 *)(p + 0x49C)) / 225.0f + 0.5f, D_L22_001DE4F4);
            if (D_L22_001E1FB8 >= i) {
                func_L22_003B7C20(i + 0x120000, D_L22_001E2040[i], i == D_L22_001E2084,
                                  (f32)(D_L22_001E1FC0[i] - *(s32 *)(p + 0x49C)) / 225.0f + 0.5f,
                                  (f32)(D_L22_001E2000[i] - *(s32 *)(p + 0x49C)) / 225.0f + 0.5f, D_L22_001DE4F0);
            } else {
                func_L01_00516AA0(i + 0x120000, 1, 0);
                func_L01_00516AA0(i + 0x120011, 1, 0);
                func_L01_00516AA0(i + 0x120022, 1, 0);
                func_L01_00516AA0(i + 0x120033, 1, 0);
            }
        }
    }
}
/* localdecomp:end func_L22_003B83A0 */
