#include "common.h"

/* localdecomp:start func_L05_00355AE8 */
s32 func_L05_00355AE8(u8 *obj) {
    s32 r = 0;
    u8 c;
    if ((u32)(obj[66] - 11) < 3 || (c = obj[67], c == 12) || c == 13 || c == 11) r = 1;
    return r;
}
/* localdecomp:end func_L05_00355AE8 */

LINKER_REMNANT("asm/levels", func_L05_00355B28);

/* localdecomp:start func_L05_00355B30 */
s32 func_L05_00355B30(u8 *a0) {
    s32 r = 0;
    if ((u32)(a0[66] - 18) < 2 || a0[67] == 19 || a0[67] == 18) {
        if (a0[66] != 20) {
            r = a0[67] != 20;
        }
    }
    return r;
}
/* localdecomp:end func_L05_00355B30 */

INCLUDE_ASM("asm/levels", func_L05_00355B80);

LINKER_REMNANT("asm/levels", func_L05_00355BD0);

INCLUDE_ASM("asm/levels", func_L05_00355BD8);

/* localdecomp:start func_L05_00355C48 */
extern void func_L05_0035AB28(f32);

void func_L05_00355C48(void) {
    func_L05_0035AB28(0.5f);
}
/* localdecomp:end func_L05_00355C48 */

/* localdecomp:start func_L05_00355C70 */
extern void func_L05_0035AB28(f32);

void func_L05_00355C70(void) {
    func_L05_0035AB28(2.0f);
}
/* localdecomp:end func_L05_00355C70 */

INCLUDE_ASM("asm/levels", func_L05_00355C98);

/* localdecomp:start func_L05_00355D00 */
extern s32 func_L05_00355B30(u8 *a0);
typedef int u128_354CC8 __attribute__((mode(TI)));
typedef struct { u8 pad[0x3DA]; s16 x3DA; } V_354CC8;
typedef struct { u8 pad[0x10]; u128_354CC8 pos; u8 pad20[0x48]; V_354CC8 *x68; } O_354CC8;
extern void func_0038CF00(u128_354CC8 *, u128_354CC8 *);
extern void func_0038CF38(u128_354CC8 *, u128_354CC8 *);
void func_L05_00355D00(O_354CC8 *o, u128_354CC8 *v) {
    u128_354CC8 t = *v;
    if (o->x68->x3DA != 0 || ((s32 (*)(O_354CC8 *))func_L05_00355B30)(o) != 0) {
        func_0038CF00(&o->pos, &t);
    } else {
        func_0038CF38(&o->pos, &t);
    }
}
/* localdecomp:end func_L05_00355D00 */

/* localdecomp:start func_L05_00355D60 */
extern void func_0038CF38(u128_354CC8 *, u128_354CC8 *);
extern void func_0038CF00(u128_354CC8 *, u128_354CC8 *);
extern s32 func_L05_00355B30(u8 *a0);
typedef struct {
    u8 pad0[0x3DA];
    s16 h3DA;
} S_354D28b;

typedef struct {
    u8 pad0[0x10];
    f32 v10[4];
    u8 pad20[0x68 - 0x20];
    S_354D28b *p68;
} S_354D28;


void func_L05_00355D60(S_354D28 *a0, S_354D28 *a1) {
    if (a0->p68->h3DA != 0 || ((s32 (*)(S_354D28 *a0))func_L05_00355B30)(a0) != 0) {
        ((void (*)(f32 *a0, f32 *a1))func_0038CF00)(a0->v10, a1->v10);
    } else {
        ((void (*)(f32 *a0, f32 *a1))func_0038CF38)(a0->v10, a1->v10);
    }
}
/* localdecomp:end func_L05_00355D60 */
