#include "common.h"

/* declared by functions of L39_005DA870.c, which this file was cut from */
extern void func_003E82F8(s32);
extern void func_L01_00517190(s32, s32);
extern void func_L01_005170B8(s32, s32);

/* localdecomp:start func_L39_005DADF8 */
extern unsigned char D_L39_00243690[8];
extern int D_L39_00243698[2];
extern unsigned char D_L39_00243668[8];
extern int D_L39_00243670[2];
extern int D_L39_00243680[2];
extern char D_L39_002B5780[][24];
extern char D_L39_00243740[];
extern char D_L39_00243748[];
extern int func_00120048(char *, char *, ...);

void func_L39_005DADF8(int a, int b, int idx)
{
    if (D_L39_00243690[idx])
        D_L39_00243698[idx] = 0;
    D_L39_00243690[idx] = 0;
    if (D_L39_00243668[idx]) {
        D_L39_00243670[idx] = a;
        D_L39_00243680[idx] = b;
    }
    if (a == 0 && b == 0)
        func_00120048(D_L39_002B5780[idx], D_L39_00243740);
    else
        func_00120048(D_L39_002B5780[idx], D_L39_00243748, a, b);
}
/* localdecomp:end func_L39_005DADF8 */

INCLUDE_ASM("asm/levels", func_L39_005DAEB8);

/* localdecomp:start func_L39_005DB0E0 */
extern int D_L39_00243698[2];
extern u8 D_L39_00243690[8];
extern s32 D_L39_002436A8[2];
void func_L39_005DB0E0(s32 a0, s32 a1, f32 a2) {
    f32 *p;
    D_L39_00243690[a1] = 1;
    p = &((f32 *)&D_L39_00243698)[a1];
    *p = 1.0f - a2;
    if (*p > 1.0f) {
        *p = 1.0f;
    }
    if (*p < 0.0f) {
        *p = 0.0f;
    }
    D_L39_002436A8[a1] = a0;
}
/* localdecomp:end func_L39_005DB0E0 */

/* localdecomp:start func_L39_005DB148 */
extern f32 D_L39_002436C0[2];
extern s32 D_L39_002436D0[2];

void func_L39_005DB148(s32 a0, f32 a1)
{
    f32 *p;

    p = &D_L39_002436C0[a0];
    *p = 1.0f - a1;
    if (*p > 1.0f) {
        *p = 1.0f;
    }
    if (*p < 0.0f) {
        *p = 0.0f;
    }
    D_L39_002436D0[a0] = 2;
}
/* localdecomp:end func_L39_005DB148 */

/* localdecomp:start func_L39_005DB1A8 */
typedef struct {
    u8 pad0[0x12];
    u16 h12;
    u8 pad14[0x6C];
} S_005DB1A8;
extern S_005DB1A8 D_L39_0049C890[];
extern s32 D_001D7FD8_sda[2];
extern void func_003E82F8(s32);
extern s32 func_L01_00516D60(s32, s32);
extern void func_L01_00517190(s32, s32);
extern void func_L01_005170B8(s32, s32);

void func_L39_005DB1A8(s32 *a0, s32 a1)
{
    s32 vals[9];
    u8 flags[9];
    s32 n = 0;
    s32 i;
    s32 m;
    s32 k;
    s32 j;
    s32 start;
    s32 end;
    S_005DB1A8 *e = D_L39_0049C890;

    for (m = 0; m < 16 && n < 9; m++) {
        if (a0[m] != 0) {
            vals[n] = e[m].h12;
            flags[n] = a0[m] == 2;
            n++;
        }
    }
    if (n != 0) {
        func_003E82F8(a1);
        for (i = 0; i <= 16; i++)
            func_L01_00516D60(0x2001B + i, 0);
        func_L01_00516D60(0x20019, n & 1);
        func_L01_00516D60(0x2001A, (n ^ 1) & 1);
        start = 9 - n;
        end = n + 7;
        k = start;
        for (; k <= end; k += 2) {
            func_L01_00516D60(0x2001B + k, 1);
            j = (k - start) >> 1;
            func_L01_00517190(0x2001B + k, vals[j]);
            if (flags[j])
                func_L01_005170B8(0x2001B + k, 0x70D04040);
            else
                func_L01_005170B8(0x2001B + k, 0x706EC8FF);
        }
        D_001D7FD8_sda[a1] = 100;
    }
}
/* localdecomp:end func_L39_005DB1A8 */
