#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern u8 *func_003AB218(u8 *);
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/remnants", func_003AD328);

/* localdecomp:start func_003AD3F0 */
void *func_003AD3F0(u8 *p) {
    s32 i;
    s32 *q = (s32 *)(p + 0x30);
    for (i = 3; i != -1; i--) {
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
        q += 4;
    }
    return p;
}
/* localdecomp:end func_003AD3F0 */

typedef struct { u8 p0[0x18]; f32 f18; s32 f1C; s32 f20; f32 f24; s8 b28; u8 p29[3]; s32 f2C; u8 p30[0x50]; s32 f80; s32 f84; } S_3A7E80;
extern u8 func_003AD538_003AD428[];
extern u8 func_003AD570_003AD428[];
/* localdecomp:start func_003AD428 */
typedef void (*Set5_3AD428)(void *, s32, f32, f32, f32, f32, f32);
typedef void (*Set2_3AD428)(void *, s32, f32, f32);

void func_003AD428(S_3A7E80 *o)
{
    f32 v;
    o->f18 = 0;
    o->b28 = 0;
    v = o->f18;
    o->f2C = 0;
    o->f80 = 0;
    o->f24 = 0.005f;
    ((Set5_3AD428)func_003AD538_003AD428)(o, 0, v, v, v, v, v);
    ((Set5_3AD428)func_003AD538_003AD428)(o, 1, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    o->f84 = 2;
    ((Set2_3AD428)func_003AD570_003AD428)(o, 0, v, v);
    o->f20 = 0;
    o->f1C = 1;
}
/* localdecomp:end func_003AD428 */

LINKER_REMNANT("asm/remnants", func_003AD4E0);

/* localdecomp:start func_003AD4E8 */
void func_003AD4E8(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x2C) = value;
}
/* localdecomp:end func_003AD4E8 */

LINKER_REMNANT("asm/remnants", func_003AD4F0);

/* localdecomp:start func_003AD500 */
typedef struct {
    char pad_0[0x18];   /* Offset 0x00 down to 0x18 */
    f32 float_field;    /* Offset 0x18 - Targeted by lwc1/swc1 */
    char pad_1C[0xC];   /* Padding from 0x1C to 0x28 */
    char byte_flag;     /* Offset 0x28 - Targeted by sb $v0, 0x28($a0) */
} InitContext;

void func_003AD500(InitContext* ctx) {
    // 0: lui $at, 0x3f80
    // 4: mtc1 $at, $f1
    register f32 constant_one __asm__("$f1") = 1.0f;

    // FENCE 1: Blocks 'li $v0, 1' from climbing to offset 0:
    __asm__ __volatile__ ("");

    // 8: li $v0, 1
    ctx->byte_flag = 1;

    // c: lwc1 $f0, 0x18($a0)
    (void)((volatile InitContext*)ctx)->float_field;

    // MEMORY CLOBBER FENCE:
    // This tells ee-gcc that all previous memory actions (the lwc1 load) must be 
    // completely processed and finalized before any subsequent memory instructions 
    // are evaluated. This forces 'sb' perfectly down to offset 10:!
    __asm__ __volatile__ ("" : : : "memory");

    // 18: swc1 $f1, 0x18($a0)
    ctx->float_field = constant_one;
}
/* localdecomp:end func_003AD500 */

/* localdecomp:start func_003AD520 */
void func_003AD520(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x80) = value;
}
/* localdecomp:end func_003AD520 */

/* localdecomp:start func_003AD528 */
u8 func_003AD528(void *p, u8 value) {
    u8 old = *((u8 *)p + 0x28);
    *((u8 *)p + 0x28) = value;
    return old;
}
/* localdecomp:end func_003AD528 */

/* localdecomp:start func_003AD538 */
typedef struct { u8 pad[0x30]; f32 m[4][4]; f32 v[4]; } S_3A7F90;
void func_003AD538(S_3A7F90 *p, s32 i, f32 a, f32 b, f32 c, f32 d, f32 e) {
    p->m[i][0] = b;
    p->m[i][1] = c;
    p->m[i][2] = d;
    p->m[i][3] = e;
    p->v[i] = a;
}
/* localdecomp:end func_003AD538 */

/* localdecomp:start func_003AD570 */
typedef struct { f32 a[3]; f32 b[3]; } V_7FC8;
void func_003AD570(V_7FC8 *s, s32 i, f32 x, f32 y) {
    s->a[i] = x; s->b[i] = y;
}
/* localdecomp:end func_003AD570 */

/* localdecomp:start func_003AD588 */
void func_003AD588(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x84) = value;
}
/* localdecomp:end func_003AD588 */

/* localdecomp:start func_003AD590 */
void func_003AD590(u8 *p, s32 a) {
    *(s32 *)(p + 0x1C) = a;
    if (p[0x28] == 0) {
        if (a == 1) *(f32 *)(p + 0x18) = 0.0f;
        else *(f32 *)(p + 0x18) = 1.0f;
        p[0x28] = 1;
    }
}
/* localdecomp:end func_003AD590 */

/* localdecomp:start func_003AD5D0 */
void func_003AD5D0(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x20) = value;
}
/* localdecomp:end func_003AD5D0 */

/* localdecomp:start func_003AD5D8 */
void func_003AD5D8(void *p, f32 value) {
    *(f32 *)((u8 *)p + 0x24) = value;
}
/* localdecomp:end func_003AD5D8 */

LINKER_REMNANT("asm/remnants", func_003AD5E0);

/* func_003AD608: from the US C of func_003A8060 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */

/* Retail reaches these two globals with lui/addiu, not through $gp: an unsized array is
   never small data, so it always gets lui (docs/wiki/Matching-Patterns.md, "Globals: gp vs lui"). */
extern s32 D_001D8118[];
extern s32 D_001D8100[];

/* localdecomp:start func_003AD608 */
u8 *func_003AD608(u8 *p) {
    u8 *q;
    u8 *a, *b, *c;
    s32 i;
    func_003AB218(p);
    func_003AB218(p + 0x3C);
    func_003AB218(p + 0x78);
    func_003AB9B8(p + 0xD0);
    func_003AB738(p + 0x110);
    func_003AB218(p + 0x140);
    func_003AB218(p + 0x17C);
    func_003AB9B8(p + 0x1D0);
    func_003AB738(p + 0x210);
    func_003AB218(p + 0x244);
    func_003AB218(p + 0x280);
    q = p + 0x2BC;
    for (i = 7; i != -1; i--) { func_003AB218(q); q += 0x3C; }
    func_003AB218(p + 0x49C);
    func_003AB218(p + 0x4D8);
    func_003AB218(p + 0x514);
    func_003AB218(p + 0x550);
    func_003AB218(p + 0x58C);
    func_003AB738(p + 0x5C8);
    func_003AB738(p + 0x5F8);
    func_003AB218(p + 0x628);
    q = p + 0x664;
    for (i = 7; i != -1; i--) { func_003AB738(q); q += 0x30; }
    func_003AD3F0(p + 0x7E8);
    func_003AD3F0(p + 0x870);
    func_003AD3F0(p + 0x8F8);
    func_003AD3F0(p + 0x980);
    func_003AD3F0(p + 0xA08);
    func_003AD3F0(p + 0xA90);
    func_003AAB68(p + 0xB18);
    *(u8 **)(p + 0xB18) = (u8 *)D_001D8118;
    func_003AAB68(p + 0xB1C);
    *(u8 **)(p + 0xB1C) = (u8 *)D_001D8100;
    return p;
}
/* localdecomp:end func_003AD608 */

LINKER_REMNANT("asm/remnants", func_003AD7D0);
