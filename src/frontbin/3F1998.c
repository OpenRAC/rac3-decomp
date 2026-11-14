#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void *func_003F1CA8();
extern void **func_003F2208(void **);
extern s32 func_003EDBA8(s32, s32);
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/nonmatchings/text", func_003F1998);

/* localdecomp:start func_003F1BF8 */
s32 func_003F1BF8(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))(*(u8 **)((u8 *)p + 0x2C) + 0x8);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003F1BF8 */

/* localdecomp:start func_003F1C28 */
s32 func_003F1C28(s32 p, s32 k) {
    if (k != 3) {
        return func_003EDBA8(p, k);
    }
    return 1;
}
/* localdecomp:end func_003F1C28 */

LINKER_REMNANT("asm/remnants", func_003F1C58);

/* localdecomp:start func_003F1CA8 */
extern void func_003EDAD0(void *, s32, s32);
extern void func_003ED988(void);
extern u8 D_001D97F8[];
void *func_003F1CA8(void *arg0)
{
  func_003ED988();
  *((s32 *) (((u8 *) arg0) + 0x2C)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x30)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x44)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x40)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x34)) = 0;
  *((s32 **) (((u8 *) arg0) + 8)) = D_001D97F8;
  *((f32 *) (((u8 *) arg0) + 0x14)) = (*((f32 *) (((u8 *) arg0) + 0x10)) = 0.5f);
  *((s32 *) (((u8 *) arg0) + 0x38)) = 0x60F00000;
  *((f32 *) (((u8 *) arg0) + 0x18)) = 1.0f;
  *((f32 *) (((u8 *) arg0) + 0x1C)) = 1.0f;
  func_003EDAD0(arg0, 0x100, 1);
  return arg0;
}
/* localdecomp:end func_003F1CA8 */

/* localdecomp:start func_003F1D28 */
extern s32 D_001D97F0_g;
extern s32 func_003EDBA8(s32, s32);
s32 func_003F1D28(s32 p, s32 k) {
    if (k != D_001D97F0_g) return func_003EDBA8(p, k);
    return 1;
}
/* localdecomp:end func_003F1D28 */

/* localdecomp:start func_003F1D58 */
extern s32 D_001D97F0_g;
s32 func_003F1D58(void) {
    return D_001D97F0_g;
}
/* localdecomp:end func_003F1D58 */

INCLUDE_ASM("asm/nonmatchings/text", func_003F1D60);

/* localdecomp:start func_003F1DA0 */
typedef struct {
    void *vt0; void *vt4; s32 (**vt)(); u8 pad0[0x4]; f32 f10, f14, f18, f1C; u8 pad20[0x18]; s32 f38; f32 f3C; s32 f40; s32 f44;
} O_3EC7D8;
extern f32 D_001D9688[], D_001D968C[], D_001D9690_003F1DA0[], D_001D9694_003F1DA0[], D_001D9698_003F1DA0[], D_001D969C_003F1DA0[];
extern s32 func_003EDAF8();
extern void func_003EDCF0();
extern s32 func_003ABDD8();
extern void func_003AA320(void *, s32, f32, f32, f32, f32, f32);
void func_003F1DA0(O_3EC7D8 *o, s32 a) {
    f32 b[4];
    s32 p;
    f32 x, y;
    if (o->f44 == 0) return;
    o->vt[8](o, a, b, 1);
    if (func_003EDAF8(o, 0x100) != 0) {
        f32 x, y;
        f32 c;
        f32 d;
        f32 e;
        s32 fl;
        s32 k = o->f40;
        p = func_003ABDD8(o->f44, k);
        x = o->f10; y = o->f14; fl = o->f38; c = o->f18; d = o->f1C; e = o->f3C;
        if (p == 0) return;
        func_003AA320((void *)p, fl, (x + D_001D9690_003F1DA0[0]) * D_001D9698_003F1DA0[0], (y + D_001D9694_003F1DA0[0]) * D_001D969C_003F1DA0[0], c * D_001D9688[0], d * D_001D968C[0], e);
    } else {
        s32 k;
        f32 c;
        f32 d;
        f32 e;
        s32 fl;
        func_003EDCF0(o, b);
        x = b[0] + (b[2] - b[0]) * 0.5f;
        y = b[1] + (b[3] - b[1]) * 0.5f;
        k = o->f40;
        p = func_003ABDD8(o->f44, k);
        fl = o->f38; c = o->f18; d = o->f1C; e = o->f3C;
        if (p == 0) return;
        func_003AA320((void *)p, fl, (x + D_001D9690_003F1DA0[0]) * D_001D9698_003F1DA0[0], (y + D_001D9694_003F1DA0[0]) * D_001D969C_003F1DA0[0], c * D_001D9688[0], d * D_001D968C[0], e);
    }
}
/* localdecomp:end func_003F1DA0 */

typedef struct { u8 p0[0x10]; f32 f10; f32 f14; f32 f18; f32 f1C; u8 p1[0x1C]; f32 f3C; s32 f40; u8 *f44; } O_3EC960;
extern s32 func_003ABDD8(u8 *, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003F1F28);

/* localdecomp:start func_003F2148 */
s32 func_003F2148(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))((u8 *)p + 0x34);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003F2148 */

/* localdecomp:start func_003F2178 */
extern char D_001D9670[];
extern s32 func_003F2380();
void func_003F2178(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D9670; if (f & 1) func_003F2380(p); }
/* localdecomp:end func_003F2178 */

LINKER_REMNANT("asm/remnants", func_003F21A8);

/* localdecomp:start func_003F21E8 */
void func_003F21E8(s32 *p, s32 a, s32 b, s32 c) {
    p[1] = b;
    p[2] = c;
    p[3] = a;
    p[6] = 0;
    p[4] = 0;
    p[5] = 0;
}
/* localdecomp:end func_003F21E8 */

/* localdecomp:start func_003F2208 */
extern u8 D_001D9840[];
void **func_003F2208(void **p) { p[1] = 0; p[0] = D_001D9840; p[2] = 0; p[3] = 0; p[6] = 0; p[4] = 0; p[5] = 0; return p; }
/* localdecomp:end func_003F2208 */
