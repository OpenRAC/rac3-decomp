/* near miss (level 3, Starship Phoenix): flags/layout: the C matches with --as ps2as (check.py says MATCH) but cannot be linked yet: the build stops with `§.rodata would be at 0x002BE0A0 and at 0x002BE1A0` because L03_0039E470.c's jump tables must sit next to each other and the table of the assembly function func_L03_003A1158 (a 20-diff near miss) lies between this table and func_L03_0039ECA0's; it can be integrated once func_L03_003A1158 is C too */
#include "common.h"

/* localdecomp:start func_L03_003A17D8 */
typedef struct S_003A17D8 { char pad0[0x20]; unsigned char state; char pad21[0x47]; int *p68; } S_003A17D8;
extern void func_L03_003A1A78(S_003A17D8 *);
extern int func_L03_003A1CD8(S_003A17D8 *);
extern int func_00382380();
extern void func_L01_00456230(void *, int);
extern void func_L03_0032CED0(void *);
extern void func_L01_004450F0(S_003A17D8 *, int, int);
extern void func_L01_005003D0(int, int);
extern int func_L01_00452560(int, int, int, int, int, int, int);
extern unsigned char D_0014271D[];
__asm__(".extern D_0014271D, 16");
extern int D_00142C1C[];
__asm__(".extern D_00142C1C, 16");
extern char D_001A4C60[];
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern int D_L03_002D09B0[];
extern char *D_001D52FC_sda;
__asm__(".extern D_001D52FC_sda, 4");
extern float D_L03_001DF2D0;
__asm__(".extern D_L03_001DF2D0, 16");
extern float D_L03_001DF2D8;
__asm__(".extern D_L03_001DF2D8, 16");
extern float D_001DF2D0_sda;
__asm__(".extern D_001DF2D0_sda, 4");
extern float D_001DF2D8_sda;
__asm__(".extern D_001DF2D8_sda, 4");

void func_L03_003A17D8(S_003A17D8 *a) {
    int *s;
    char *e;
    func_L03_003A1A78(a);
    s = a->p68;
    if (D_0014271D[0] != 0) {
        if ((D_00142C1C[0] & 0x20000000) == 0) {
            if (func_00382380(D_001A4C60, s[1], 0) != 0) {
                e = D_L03_001DF99C + (s[2] << 8);
                func_L01_00456230(e, 1);
                (*(void (**)(char *))(e + 0x64))(e);
            }
        }
    }
    switch (a->state) {
    case 1:
        if (func_L03_003A1CD8(a) != 0) { func_L01_004450F0(a, 2, -1); }
        return;
    case 2:
        func_L01_00452560(0, 12, 0xA24, 1, 0, 0, 0);
        if (D_L03_002D09B0[0] == 12 && (*(int *)(D_001D52FC_sda + 0x1A4) & 0x10)) {
            func_L01_004450F0(a, 5, -1);
            return;
        }
        if (func_L03_003A1CD8(a) != 0) return;
        func_L01_004450F0(a, 1, -1);
        return;
    case 3: {
        float f = D_L03_001DF2D0 - 0.12000000476837158f;
        D_001DF2D0_sda = f;
        if (f < 0.0f) {
            D_001DF2D0_sda = 0.0f;
            func_L01_005003D0(0, 1);
            func_L01_004450F0(a, 1, -1);
        }
        return;
    }
    case 4:
        return;
    case 5: {
        float f = D_L03_001DF2D0 + 0.12000000476837158f;
        D_001DF2D0_sda = f;
        if (1.0f <= f) {
            D_L03_001DF2D0 = 1.0f;
            func_L01_004450F0(a, 6, -1);
        }
        return;
    }
    case 6:
        func_L03_0032CED0(D_L03_001DF99C + (s[0] << 8));
        func_L01_004450F0(a, 1, -1);
        return;
    case 7: {
        float f = D_L03_001DF2D0 - 0.12000000476837158f;
        D_001DF2D0_sda = f;
        if (f <= 0.0f) {
            func_L01_005003D0(0, 1);
            D_L03_001DF2D0 = 0.0f;
            func_L01_004450F0(a, 1, -1);
        }
        return;
    }
    case 8: {
        float f = D_L03_001DF2D8 - 0.036000002f;
        D_001DF2D8_sda = f;
        if (f <= 0.0f) {
            func_L01_005003D0(0, 1);
            D_L03_001DF2D8 = 0.0f;
            func_L01_004450F0(a, 1, -1);
        }
        return;
    }
    }
}
/* localdecomp:end func_L03_003A17D8 */
