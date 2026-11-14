#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_0032F598);

INCLUDE_ASM("asm/levels", func_L07_0032F988);

INCLUDE_ASM("asm/levels", func_L07_0032FDC8);

INCLUDE_ASM("asm/levels", func_L07_003303B0);

INCLUDE_ASM("asm/levels", func_L07_003304C0);

/* localdecomp:start func_L07_00330748 */
extern u8 D_001A4BE0[];
extern s32 D_00142668[];
extern void func_L07_00331890(void *);
extern s32 func_L07_003338C0(s32, s32);
extern s32 func_00382468(s32);
extern void func_L01_00456230(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L07_00330748(u8 *a0, s32 a1) {
    u8 *d;
    u8 *p;

    d = *(u8 **)(a0 + 0x68);
    d[0x9F] = 0;
    d[0x9E] = a1;
    func_L07_00331890(a0);
    d[0xA8] = 4;
    d[0xAA] = func_L07_003338C0(d[0x9E], d[0x9F]);
    p = D_001A4BE0;
    *(s32 *)(p + 0x2850) = D_00142668[0];
    d[0xDE] = p[0x2850];
    d[0xDF] = p[0x2850];
    *(s32 *)(d + 0xC0) = 0;
    *(s32 *)(d + 0xC4) = 0;
    *(s32 *)(d + 0xC8) = 0;
    *(s32 *)(d + 0xCC) = 0;
    *(s16 *)(d + 0xD4) = 0;
    *(s16 *)(d + 0xD2) = 0;
    *(s16 *)(d + 0xD0) = 0;
    *(s16 *)(d + 0xD6) = 0;
    *(s16 *)(d + 0xD8) = func_00382468(0x3E8) + 0x7D0;
    if (*(s32 *)(d + 0xE0) & 1) {
        *(s32 *)(d + 0xE0) = 3;
    } else {
        *(s32 *)(d + 0xE0) = 0;
    }
    func_L01_00456230(a0, 0);
    func_L01_004450F0(a0, 2, -1);
}
/* localdecomp:end func_L07_00330748 */

INCLUDE_ASM("asm/levels", func_L07_00330828);

INCLUDE_ASM("asm/levels", func_L07_003309A0);

INCLUDE_ASM("asm/levels", func_L07_00330AA0);

/* localdecomp:start func_L07_00330F30 */
extern u8 D_001426E0[];
extern u8 D_001A74A9[];
extern s32 D_00142848[];
extern void func_L01_003F1760(void);
extern void func_L01_004450F0(void *, s32, s32);
void func_L07_00330F30(u8 *arg0) {
    D_001A74A9[0] = 0;
    if (D_001426E0[0xE3] != 0) {
        D_00142848[0] = D_001426E0[0xE3] - 1;
        D_001426E0[0xE3] = 0;
    }
    func_L01_003F1760();
    func_L01_004450F0(arg0, 8, -1);
}
/* localdecomp:end func_L07_00330F30 */

/* localdecomp:start func_L07_00330F98 */
extern void func_L07_003328D0(s32);
extern void func_L01_004AA760(s32, s32);
extern void func_L01_004596E8(s32, void (*)(void));
extern void func_L07_003332B8(void);
extern s32 D_L07_001D7B20;

void func_L07_00330F98(s32 arg0) {
    void (*deflt)(void);

    func_L07_003328D0(arg0);
    func_L01_004AA760(0, arg0);
    func_L01_004AA760(1, arg0);
    func_L01_004AA760(2, arg0);
    deflt = func_L07_003332B8;
    D_L07_001D7B20 = -1;
    func_L01_004596E8(0, deflt);
    func_L07_00331890(arg0);
}
/* localdecomp:end func_L07_00330F98 */

/* localdecomp:start func_L07_00331008 */
typedef struct {
    u8 p00[0x1C];
    u8 f1C;
    u8 f1D;
} S_00331008;

typedef struct {
    s16 arr[1];
} T_00331008;

extern s32 *func_L07_00333918(void *);
extern void func_L07_003310E8(u8 *, void *);
extern s32 D_001A71A4[];

s32 func_L07_00331008(u8 *arg0, void *arg1) {
    S_00331008 *r;
    T_00331008 *q;
    s32 base;
    s16 v;

    base = *(s32 *)(arg0 + 0x68);
    r = (S_00331008 *)func_L07_00333918(arg1);
    if (r->f1C == 3) {
        return 1;
    }
    if (D_001A71A4[0] == 0x74) {
        if (r->f1C == 1) {
            func_L07_003310E8(arg0, arg1);
        }
        return 0;
    }
    if (r->f1C == 1) {
        return 1;
    }
    q = (T_00331008 *)(base + 0x90);
    v = q->arr[r->f1D];
    if (v == -1) {
        r->f1C = 1;
        return 1;
    }
    if (v > 0) {
        r->f1C = 1;
        q->arr[r->f1D] -= 1;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L07_00331008 */

/* localdecomp:start func_L07_003310E8 */
extern s32 *func_L07_00333918(void *);

void func_L07_003310E8(u8 *arg0, void *arg1) {
    s32 *r = func_L07_00333918(arg1);

    if (*(u8 *)((u8 *)r + 0x1C) == 1) {
        s16 *q = (s16 *)(*(s32 *)(arg0 + 0x68) + 0x90);
        s16 *p = q + *(u8 *)((u8 *)r + 0x1D);

        if (*p != -1) {
            *p += 1;
        }
    }
    *(u8 *)((u8 *)r + 0x1C) = 0;
}
/* localdecomp:end func_L07_003310E8 */

INCLUDE_ASM("asm/levels", func_L07_00331158);

/* localdecomp:start func_L07_00331288 */
extern void func_L07_003312E8(s32, s32);

void func_L07_00331288(s32 a0)
{
    s32 i;

    for (i = 0; i < 6; i++) {
        if (i < 3 || i > 4) {
            func_L07_003312E8(a0, i);
        }
    }
}
/* localdecomp:end func_L07_00331288 */

INCLUDE_ASM("asm/levels", func_L07_003312E8);
