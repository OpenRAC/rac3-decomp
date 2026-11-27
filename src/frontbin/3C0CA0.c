#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_00381FF0(s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_00381FF0();
extern void func_003C0CC8(s32);
extern void func_003BBA08(s32, s32);
extern void func_003BC408();
extern s32 func_003BDD38();
extern void func_003BE308();
extern s32 func_003BDD38(void);
extern void func_003BE308(void *);
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_003C2880(s32 p);
typedef int u128_t __attribute__((mode(TI)));
extern void func_003C2DC0(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C2EC0();
extern void func_003C2DC0();
extern void func_003C0CC0(void);
extern void func_003C2D88();
extern void func_003C29B0();
extern void func_003BDCB0(s32, s32 *, s32);
extern void func_003BDE20();
extern void func_003BDE20(s32);


/* localdecomp:start func_003C0CA0 */
extern void func_003A8220(void *);
extern u8 D_0031D130[];
 
void func_003C0CA0(void) {
    func_003A8220(D_0031D130);
}
/* localdecomp:end func_003C0CA0 */

/* localdecomp:start func_003C0CC0 */
extern u8 D_001D8D20;
void func_003C0CC0(void) {
    D_001D8D20 = 0;
}
/* localdecomp:end func_003C0CC0 */

/* localdecomp:start func_003C0CC8 */
extern s32 D_002D2018[];
extern s32 func_11BB58(void *, s32, s32);
extern u8 D_001D8D20;
void func_003C0CC8(s32 a0) {
    D_001D8D20 = 1;
    func_11BB58(D_002D2018, a0, 0x40);
}
/* localdecomp:end func_003C0CC8 */

/* localdecomp:start func_003C0CF8 */
typedef struct { s32 f0; u8 p4[0x4C]; u8 f50; u8 f51; } S_BB7E8;
typedef struct { s32 a; s32 b; } P_BB7E8;
typedef struct { u8 p[0x68]; s32 f68; } T_BB7E8;
extern S_BB7E8 D_002D2008_003C0CF8[];
extern T_BB7E8 D_00227580[];
extern P_BB7E8 D_0037FA58[];
extern s32 D_0037FA60[];
extern s32 D_0037FA64[];
extern s32 D_001D9030;
extern u8 D_001D9034[];
extern s32 D_0022D8B0[];
extern s32 D_00225700_003C0CF8[];
extern s32 func_003BB7B8();
extern void func_003BC588();
extern void func_003A56F8();
extern void func_003C0F00();
s32 func_003C0CF8(void) {
    s32 r, a, s, tmp;
    s32 *p;
    u8 *d;
    s32 t;
    S_BB7E8 *g;
    g = D_002D2008_003C0CF8;
    g->f50 = 0;
    g->f51 = 0;
    r = func_003BB7B8();
    if (D_001D8D20) {
        D_001D8D20 = 0;
    } else {
        d = (u8 *)g + 0x10;
        if ((u32)(r - 1) < 2 || r == 4 || r == 8 || r == 0x1B || r == 0x1C || r == 9 || r == 0x1D
            || r == 5 || r == 0xD || r == 0x17 || r == 0xA || r == 0x12 || r == 0xE) {
            if (r > 0) a = D_0037FA58[r % 60].b;
            else a = D_0037FA64[0];
        } else {
            if (r > 0) a = D_0037FA58[r % 60].a;
            else a = D_0037FA60[0];
        }
        func_11BB58(d, func_00381FF0(a), 0x40);
    }
    func_003BBA08(1, 0);
    func_003BC408(5, &D_001D9030);
    func_003BDCB0(4, (s32 *)D_001D9034, D_001D9030);
    s = D_00227580[0].f68;
    func_003BC588(r, &tmp, s);
    D_002D2008_003C0CF8[0].f0 = s;
    s = s + tmp;
    D_00227580[0].f68 = s;
    func_003BDE20(func_003BDD38());
    func_003BE308(func_003C0F00);
    { s32 i = 0; while (D_0022D8B0[i]) { D_0022D8B0[i] = 0; i++; } }
    func_003A56F8(D_00225700_003C0CF8[0x15]);
    func_003C0CA0();
    return 1;
}
/* localdecomp:end func_003C0CF8 */

/* localdecomp:start func_003C0F00 */
extern void func_003C1280_003C0F00();
void func_003C0F00(u8 *p) {
    s32 ok = 0;
    switch (*(s16 *)(p + 0xAA)) {
    case 0x1E03:
        *(u16 *)(p + 0x34) |= 1;
        *(void **)(p + 0x64) = func_003C1280_003C0F00;
        ok = 1;
        break;
    case 0xD54:
        *(void **)(p + 0x64) = 0;
        ok = 1;
        break;
    }
    if (ok) *(u16 *)(p + 0x34) &= ~2;
    else *(u16 *)(p + 0x34) |= 2;
}
/* localdecomp:end func_003C0F00 */
