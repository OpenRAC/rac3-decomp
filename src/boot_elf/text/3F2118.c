#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void **func_003F25C0(void **);
/* --- end of declarations from other files --- */

/* declarations of 3F1FB0.c's earlier functions */
extern s32 func_003EDEB0();
extern void func_003EDEF8();
extern s32 func_003EDEB0(void *, s32);
extern char D_001D9670[];
extern void func_003EE0A8();
extern s32 func_003F2738();
extern void func_003EE0A8(void *, f32 *);

/* localdecomp:start func_003F2118 */
/* from frontbin's twin (already C) */
void func_003F2118(u8 *p, f32 *a) {
    *(f32 *)(p + 0x10) = a[0] + (a[2] - a[0]) * 0.5f;
    *(f32 *)(p + 0x14) = a[1] + (a[3] - a[1]) * 0.5f;
}
/* localdecomp:end func_003F2118 */

/* localdecomp:start func_003F2158 */
typedef struct {
    void *vt0; void *vt4; s32 (**vt)(); u8 pad0[0x4]; f32 f10, f14, f18, f1C; u8 pad20[0x18]; s32 f38; f32 f3C; s32 f40; s32 f44;
} O_3EC7D8;
extern f32 D_001D9688[], D_001D968C[], D_001D9690_003F2158[], D_001D9694_003F2158[], D_001D9698_003F2158[], D_001D969C_003F2158[];
extern s32 func_003EDEB0();
extern void func_003EE0A8();
extern s32 func_003AC190();
extern void func_003AA6D8(void *, s32, f32, f32, f32, f32, f32);
void func_003F2158(O_3EC7D8 *o, s32 a) {
    f32 b[4];
    s32 p;
    f32 x, y;
    if (o->f44 == 0) return;
    o->vt[8](o, a, b, 1);
    if (func_003EDEB0(o, 0x100) != 0) {
        f32 x, y;
        f32 c;
        f32 d;
        f32 e;
        s32 fl;
        s32 k = o->f40;
        p = func_003AC190(o->f44, k);
        x = o->f10; y = o->f14; fl = o->f38; c = o->f18; d = o->f1C; e = o->f3C;
        if (p == 0) return;
        func_003AA6D8((void *)p, fl, (x + D_001D9690_003F2158[0]) * D_001D9698_003F2158[0], (y + D_001D9694_003F2158[0]) * D_001D969C_003F2158[0], c * D_001D9688[0], d * D_001D968C[0], e);
    } else {
        s32 k;
        f32 c;
        f32 d;
        f32 e;
        s32 fl;
        func_003EE0A8(o, b);
        x = b[0] + (b[2] - b[0]) * 0.5f;
        y = b[1] + (b[3] - b[1]) * 0.5f;
        k = o->f40;
        p = func_003AC190(o->f44, k);
        fl = o->f38; c = o->f18; d = o->f1C; e = o->f3C;
        if (p == 0) return;
        func_003AA6D8((void *)p, fl, (x + D_001D9690_003F2158[0]) * D_001D9698_003F2158[0], (y + D_001D9694_003F2158[0]) * D_001D969C_003F2158[0], c * D_001D9688[0], d * D_001D968C[0], e);
    }
}
/* localdecomp:end func_003F2158 */

typedef struct { u8 p0[0x10]; f32 f10; f32 f14; f32 f18; f32 f1C; u8 p1[0x1C]; f32 f3C; s32 f40; u8 *f44; } O_3EC960;
extern s32 func_003AC190(u8 *, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003F22E0);

/* localdecomp:start func_003F2500 */
s32 func_003F2500(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))((u8 *)p + 0x34);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003F2500 */

/* localdecomp:start func_003F2530 */
extern char D_001D9670[];
extern s32 func_003F2738();
void func_003F2530(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D9670; if (f & 1) func_003F2738(p); }
/* localdecomp:end func_003F2530 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003F2560);

/* localdecomp:start func_003F25A0 */
void func_003F25A0(s32 *p, s32 a, s32 b, s32 c) {
    p[1] = b;
    p[2] = c;
    p[3] = a;
    p[6] = 0;
    p[4] = 0;
    p[5] = 0;
}
/* localdecomp:end func_003F25A0 */

/* localdecomp:start func_003F25C0 */
extern u8 D_001D9840[];
void **func_003F25C0(void **p) { p[1] = 0; p[0] = D_001D9840; p[2] = 0; p[3] = 0; p[6] = 0; p[4] = 0; p[5] = 0; return p; }
/* localdecomp:end func_003F25C0 */
