#include "common.h"

/* localdecomp:start func_L39_006A04F8 */
void func_L39_006A04F8(u8 *o, s32 a1, s32 a2, s32 a3, u8 a4, s32 a5, s32 a6, s32 a7, u8 s0, u8 s1, u8 s2, u8 s3, u8 s4)
{
    *(u8 *)(o + 0x2C4) = s4;
    *(s32 *)(o + 0x2A8) = a2;
    *(s32 *)(o + 0x2AC) = a7;
    *(s32 *)(o + 0x2B0) = a1;
    *(u8 *)(o + 0x2B4) = a4;
    *(s32 *)(o + 0x2B8) = a3;
    *(s32 *)(o + 0x2BC) = a5;
    *(s32 *)(o + 0x2C0) = a6;
    *(u8 *)(o + 0x2C7) = s0;
    *(u8 *)(o + 0x2C5) = s1;
    *(u8 *)(o + 0x2C6) = s2;
    *(u8 *)(o + 0x2C8) = s3;
}
/* localdecomp:end func_L39_006A04F8 */

/* localdecomp:start func_L39_006A0540 */
typedef struct S_006A0540 {
    s32 f0;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 f7[0x11];
} S_006A0540;

typedef struct G_006A0540 {
    s32 f0;
    s32 f4;
    u8 pad8[0x160];
    u8 f168;
    u8 pad169[0x4DB];
    s32 f644[8];
} G_006A0540;

extern G_006A0540 D_001A5CD0;
extern s32 D_L39_00241640;
__asm__(".extern D_L39_00241640, 16");
extern s32 D_L39_00240640;
__asm__(".extern D_L39_00240640, 16");
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_L39_006A0540(void) {
    S_006A0540 s;
    s32 i;

    if (D_L39_00241640 != 0) {
        if (D_001A5CD0.f168 != 0) {
            for (i = 0; i < 7; i++) {
                s32 *p = &D_001A5CD0.f644[i];

                if (*p != -1) {
                    s.f6 = *(u8 *)(p + 8);
                    s.f0 = 0;
                    s.f5 = 0;
                    s.f4 = 0;
                    func_0014AD08(0x50, D_001A5CD0.f4, *p, D_L39_00240640, 0x20, &s);
                    *p = -1;
                }
            }
        }
    }
}
/* localdecomp:end func_L39_006A0540 */

LINKER_REMNANT("asm/levels", func_L39_006A05F0);

INCLUDE_ASM("asm/levels", func_L39_006A05F8);

LINKER_REMNANT("asm/levels", func_L39_006A0948);

/* localdecomp:start func_L39_006A0950 */
extern int D_L39_0047D628[];
extern void func_L39_00688400(char *, int);
void func_L39_006A0950(char *a0, int a1)
{
    *(int *)(a0 + 0x60) = (int)D_L39_0047D628;
    *(int *)(a0 + 0x2B0) = -1;
    *(int *)(a0 + 0x2B4) = -1;
    *(int *)(a0 + 0x2B8) = -1;
    *(int *)(a0 + 0x2BC) = -1;
    *(int *)(a0 + 0x2C4) = -1;
    *(int *)(a0 + 0x2C8) = -1;
    *(int *)(a0 + 0x2C0) = -1;
    func_L39_00688400(a0, a1);
}
/* localdecomp:end func_L39_006A0950 */
