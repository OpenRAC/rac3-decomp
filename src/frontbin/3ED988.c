#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003F2380();
extern s32 func_003EDBD8();
extern void func_003EDC80();
extern void func_003EDB78();
extern s32 func_003EDAF8();
extern void func_003EDB40();
/* --- end of declarations from other files --- */

typedef struct { u8 p0[8]; void *f8; u8 pC[4]; s32 f10, f14, f18, f1C; f32 f20, f24; s32 f28; } O_3E8420;
extern u8 D_001D96D8[];
extern void **func_003E70E8();
/* localdecomp:start func_003ED988 */
extern void func_003EDAD0(void *, s32, s32);
extern void func_003EDB08(void *, s32, s32);
extern void func_003EDB68(void *, f32, f32);
extern void func_003EDB90(void *, f32, f32);
O_3E8420 *func_003ED988(O_3E8420 *p) {
    func_003E70E8(p);
    p->f8 = D_001D96D8;
    p->f28 = 0x80808080;
    p->f10 = 0;
    p->f14 = 0;
    p->f18 = 0;
    p->f1C = 0;
    p->f20 = 0;
    p->f24 = 0;
    func_003EDAD0(p, 1, 1);
    func_003EDAD0(p, 2, 0);
    func_003EDAD0(p, 4, 1);
    func_003EDAD0(p, 8, 1);
    func_003EDAD0(p, 0x20, 0);
    func_003EDAD0(p, 0x10, 0);
    func_003EDAD0(p, 0x40, 0);
    func_003EDAD0(p, 0x80, 0);
    func_003EDAD0(p, 0x100, 0);
    func_003EDB08(p, 3, 3);
    func_003EDB68(p, 0.5f, 0.5f);
    func_003EDB90(p, 1.0f, 1.0f);
    p->f28 = 0x40000000;
    p->f20 = 0.005f;
    p->f24 = 0.005f;
    return p;
}
/* localdecomp:end func_003ED988 */

LINKER_REMNANT("asm/remnants", func_003EDAC8);

/* localdecomp:start func_003EDAD0 */
void func_003EDAD0(void *p, s32 mask, s32 set) {
    if (set != 0) {
        *(s32 *)((u8 *)p + 0xC) |= mask;
    } else {
        *(s32 *)((u8 *)p + 0xC) &= ~mask;
    }
}
/* localdecomp:end func_003EDAD0 */

/* localdecomp:start func_003EDAF8 */
s32 func_003EDAF8(void *p, s32 mask) {
    return (*(s32 *)((u8 *)p + 0xC) & mask) != 0;
}
/* localdecomp:end func_003EDAF8 */

/* localdecomp:start func_003EDB08 */
void func_003EDB08(void *p, s32 a, s32 b) {
    *(u32 *)((u8 *)p + 0xC) = (((*(u32 *)((u8 *)p + 0xC) & ~0x600) | (a << 9)) & ~0x1800) | (b << 11);
}
/* localdecomp:end func_003EDB08 */

/* localdecomp:start func_003EDB40 */
void func_003EDB40(void *p, s32 *a, s32 *b) {
    *a = (*(u32 *)((u8 *)p + 0xC) >> 9) & 3;
    *b = (*(u32 *)((u8 *)p + 0xC) >> 11) & 3;
}
/* localdecomp:end func_003EDB40 */

/* localdecomp:start func_003EDB68 */
void func_003EDB68(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x10) = x;
    *(f32 *)((u8 *)p + 0x14) = y;
}
/* localdecomp:end func_003EDB68 */

/* localdecomp:start func_003EDB78 */
void func_003EDB78(void *a0, f32 *a1, f32 *a2) {
    *a1 = *(f32 *)((u8 *)a0 + 0x10);
    *a2 = *(f32 *)((u8 *)a0 + 0x14);
}
/* localdecomp:end func_003EDB78 */

/* localdecomp:start func_003EDB90 */
void func_003EDB90(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x18) = x;
    *(f32 *)((u8 *)p + 0x1C) = y;
}
/* localdecomp:end func_003EDB90 */

/* localdecomp:start func_003EDBA0 */
s32 func_003EDBA0(void) {
    return 1;
}
/* localdecomp:end func_003EDBA0 */

/* localdecomp:start func_003EDBA8 */
s32 func_003EDBA8(s32 p, s32 k) {
    if (k == 1) {
        return 1;
    }
    return func_003E7100(p, k);   /* defined earlier in text.c */
}
/* localdecomp:end func_003EDBA8 */

/* localdecomp:start func_003EDBD8 */
typedef struct V_3E8670 { u8 pad[0x14]; s32 (*fn)(void *, s32); } V_3E8670;
typedef struct { u8 pad[8]; V_3E8670 *vt; } O_3E8670;
extern s32 func_003EDAF8();
s32 func_003EDBD8(O_3E8670 *a, s32 b) {
    if (func_003EDAF8(a, 1) != 0) return a->vt->fn(a, b);
    return 0;
}
/* localdecomp:end func_003EDBD8 */

/* localdecomp:start func_003EDC30 */
typedef struct { u8 pad[0x18]; void (*fn)(void *, s32); } V_3E86C8;
typedef struct { u8 pad[8]; V_3E86C8 *vt; } S_3E86C8;
extern s32 func_003EDAF8();
void func_003EDC30(S_3E86C8 *a, s32 b) {
    if (func_003EDAF8(a, 1)) a->vt->fn(a, b);
}
/* localdecomp:end func_003EDC30 */

/* localdecomp:start func_003EDC80 */
extern void func_003E7218(void);
extern void func_003E7238(void);
extern s32 func_003EDAF8(void *, s32);
void func_003EDC80(void *arg0, s32 arg1) {
    if (func_003EDAF8(arg0, 1) != 0) {
        (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x1C))(arg0, arg1);
    }
    if (func_003EDAF8(arg0, 0x4000) != 0) {
        func_003E7238();
        func_003E7218();
    }
}
/* localdecomp:end func_003EDC80 */

/* localdecomp:start func_003EDCF0 */
void func_003EDCF0(void *a, f32 *b) {
}
/* localdecomp:end func_003EDCF0 */

/* localdecomp:start func_003EDCF8 */
extern char D_001D9670[];
void func_003EDCF8(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D9670; if (f & 1) func_003F2380(p); }
/* localdecomp:end func_003EDCF8 */

LINKER_REMNANT("asm/remnants", func_003EDD28);

extern f32 D_001D9698;
extern f32 D_001D969C;
extern void func_003A9500(s32, s32, s32, s32);
/* localdecomp:start func_003EDD40 */
extern f32 D_001D9698_003F1DA0[], D_001D969C_003F1DA0[];
extern void func_003A9500(s32, s32, s32, s32);
void func_003EDD40(f32 a, f32 b, f32 c, f32 d) {
    func_003A9500((s32)(a * D_001D9698_003F1DA0[0]), (s32)(c * D_001D9698_003F1DA0[0]), (s32)(b * D_001D969C_003F1DA0[0]), (s32)(d * D_001D969C_003F1DA0[0]));
}
/* localdecomp:end func_003EDD40 */
