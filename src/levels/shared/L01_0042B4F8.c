#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_0042B4F8);

INCLUDE_ASM("asm/levels", func_L01_0042C1F8);

/* localdecomp:start func_L01_0042C278 */
typedef struct {
    u8 pad0[0x58];
    s32 x58;
    s16 x5C;
    u8 pad5E[0x68 - 0x5E];
    s32 x68;
} S_004294D0;

extern S_004294D0 D_L01_001E6D80;
extern s32 D_L01_0021F5E0[];

extern void func_0011F0A0(s32);
extern s32 func_003A0760(s32, s32);
extern void func_L01_0040E2B0(s32, s32, s32);
extern void func_L01_0042D3A8(s32, s32, s32);

void func_L01_0042C278(void) {
    s32 r, d, n, start;
    s32 *e;
    s32 a, b, c, o;

    func_0011F0A0(0);
    r = func_003A0760(D_L01_001E6D80.x68, D_L01_001E6D80.x58);
    func_0011F0A0(0);
    d = 0x8E000 - r;
    if (d > 16) {
        n = D_L01_001E6D80.x58 + d;
        func_L01_0040E2B0(n, D_L01_001E6D80.x58, r);
        D_L01_001E6D80.x58 = n;
    }
    start = D_L01_0021F5E0[0];
    e = (s32 *)D_L01_001E6D80.x58;
    while ((a = *e++) >= 0) {
        b = *e++;
        c = *e;
        e += 2;
        o = 0;
        if (b != 0) {
            o = D_L01_001E6D80.x58 + b;
        }
        func_L01_0042D3A8(a, D_L01_001E6D80.x58 + c, o);
    }
    D_L01_001E6D80.x5C = D_L01_0021F5E0[0] - start;
}
/* localdecomp:end func_L01_0042C278 */

/* localdecomp:start func_L01_0042C370 */
extern S_004294D0 D_L01_001E6D80;
typedef struct {
    u8 pad[92];
    s16 count;
} State_004295C8;

extern void func_L01_0042D798(void);

void func_L01_0042C370(void) {
    while (((State_004295C8 *)&D_L01_001E6D80)[0].count > 0) {
        func_L01_0042D798();
        ((State_004295C8 *)&D_L01_001E6D80)[0].count--;
    }
}
/* localdecomp:end func_L01_0042C370 */

INCLUDE_ASM("asm/levels", func_L01_0042C3C0);

/* localdecomp:start func_L01_0042C458 */
extern S_004294D0 D_L01_001E6D80;
typedef struct { s32 v[83]; } Row004296B0;
typedef struct {
    u8 pad[37404];
    s32 base;
    u8 pad2[56];
    Row004296B0 rows[1];
} Big004296B0;
typedef struct {
    u8 pad[48];
    s32 n;
    u8 pad2[56];
    s32 h;
} Cur004296B0;
extern Big004296B0 D_00160C40;
extern void func_003A2598(s32, s32, s32);
extern void func_003A2750(s32);
s32 func_L01_0042C458(s32 i) {
    Cur004296B0 *c = &(*(Cur004296B0 *)&D_L01_001E6D80);
    Big004296B0 *b = &D_00160C40;
    s32 h = c->h;
    s32 cur = b->rows[c->n].v[i];
    s32 len = b->rows[c->n].v[i + 1] - cur;
    if (len > 0) {
        func_003A2598(h, cur + b->base, len);
        func_003A2750(0);
    }
    return 1;
}
/* localdecomp:end func_L01_0042C458 */
