#include "common.h"

/* localdecomp:start func_L39_005DA870 */
typedef struct { s32 v[3]; } S_005DA870;
extern S_005DA870 D_L39_00243710;
extern S_005DA870 D_L39_00243720;
extern S_005DA870 D_L39_00243730;
extern u8 D_001D7F58_sda[4];
extern f32 D_001D7FA8_sda;
__asm__(".extern D_L39_00241120, 16");
extern s32 *D_L39_00241120;
extern void func_003E82F8(s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_L01_005169C8(s32, f32);
extern void func_L01_00517190(s32, s32);
extern void func_L01_005170B8(s32, s32);
extern s32 func_00392A18(void);
extern s32 func_L39_00611AC8(s32, s32, s32);

void func_L39_005DA870(s32 a0, s32 a1, s32 a2, s32 a3) {
    S_005DA870 A = D_L39_00243710;
    S_005DA870 B = D_L39_00243720;
    S_005DA870 C = D_L39_00243730;
    if (a3 >= 0) {
        func_003E82F8(a3);
    }
    if (a0 < 0) {
        if (D_001D7F58_sda[a3] == 0) {
            func_L01_00516AA0(0x20014, 1, 1);
            func_L01_00516AA0(0x20015, 1, 1);
            func_L01_00516AA0(0x20016, 1, 1);
            if (*D_L39_00241120 == 1) {
                func_L39_00611AC8(0x20004, func_00392A18(), 0x62);
                func_L39_00611AC8(0x20003, func_00392A18(), 0x63);
                func_L01_005169C8(0x20003, 1.0f);
                func_L01_005169C8(0x20004, 1.0f);
            }
            func_L01_00516AA0(0x20010, 1, 0);
            func_L01_00516AA0(0x20011, 1, 0);
            func_L01_00516AA0(0x20012, 1, 0);
            func_L01_00516AA0(0x20007, 1, 0);
            func_L01_00516AA0(0x20008, 1, 0);
            func_L01_00516AA0(0x20009, 1, 0);
            func_L01_00516AA0(0x2000A, 1, 0);
            D_001D7F58_sda[a3] = 1;
        }
    } else {
        func_L01_00517190(A.v[a2], a0);
        if (a1 != 0) {
            func_L01_005170B8(A.v[a2], C.v[a2]);
        } else {
            func_L01_005170B8(A.v[a2], B.v[a2]);
        }
        if (a0 == 0) {
            func_L01_00516AA0(A.v[a2], 1, 0);
        } else {
            if (D_001D7F58_sda[a3] != 0) {
                func_L01_00516AA0(0x20014, 1, 0);
                func_L01_00516AA0(0x20015, 1, 0);
                func_L01_00516AA0(0x20016, 1, 0);
                func_L01_00516AA0(0x20017, 1, 0);
                func_L01_00516AA0(0x20018, 1, 0);
                if (*D_L39_00241120 == 1) {
                    func_L39_00611AC8(0x20004, func_00392A18(), 0x1F);
                    func_L39_00611AC8(0x20003, func_00392A18(), 0x20);
                    func_L01_005169C8(0x20003, D_001D7FA8_sda);
                    func_L01_005169C8(0x20004, D_001D7FA8_sda);
                }
                func_L01_00516AA0(0x20010, 1, 1);
                func_L01_00516AA0(0x20011, 1, 1);
                func_L01_00516AA0(0x20012, 1, 1);
                func_L01_00516AA0(0x20007, 1, 1);
                func_L01_00516AA0(0x20008, 1, 1);
                func_L01_00516AA0(0x20009, 1, 1);
                func_L01_00516AA0(0x2000A, 1, 1);
                D_001D7F58_sda[a3] = 0;
            }
            func_L01_00516AA0(A.v[a2], 1, 1);
        }
    }
}
/* localdecomp:end func_L39_005DA870 */

INCLUDE_ASM("asm/levels", func_L39_005DAC98);

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

INCLUDE_ASM("asm/levels", func_L39_005DB370);

INCLUDE_ASM("asm/levels", func_L39_005DB618);

INCLUDE_ASM("asm/levels", func_L39_005DB700);

INCLUDE_ASM("asm/levels", func_L39_005DB800);
