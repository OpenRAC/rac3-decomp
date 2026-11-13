#include "common.h"

/* localdecomp:start func_L30_0034EDE0 */
typedef struct { u8 pad[0x10]; u8 x10[0x9A]; s16 xAA; } M_34EDE0;
typedef struct { u8 pad[0x10]; u8 x10[0x10]; } O_34EDE0;
__asm__(".extern D_L30_001DD5E8, 4");
__asm__(".extern D_L30_001DF2C0, 4");
extern f32 D_L30_001DD5E8;
extern s32 D_L30_001DF2C0;
extern M_34EDE0 *D_L30_001E1280[4] __attribute__((section(".sdata")));
extern s32 D_L30_001E1290[4] __attribute__((section(".sdata")));
extern M_34EDE0 *D_L30_001ED080[];
extern f32 func_0038CF00(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D4D00(s32, s32, f32, s32, s32);

M_34EDE0 *func_L30_0034EDE0(O_34EDE0 *o) {
    f32 best = D_L30_001DD5E8;
    M_34EDE0 *res = 0;
    s32 found = 0;
    s32 i;
    s32 j;
    s32 n;
    M_34EDE0 *m;

    for (i = 0; i < 4; i++) {
        if (D_L30_001E1280[i] != 0
            && func_0038CF00(o->x10, D_L30_001E1280[i]->x10) < best
            && D_L30_001E1290[i] >= D_L30_001DF2C0 - 10
            && func_003D3CB0(o->x10, D_L30_001E1280[i]->x10, 2, o, 0) == 0) {
            res = D_L30_001E1280[i];
            found = 1;
            best = func_0038CF00(o->x10, res->x10);
        }
    }
    if (found) {
        return res;
    }
    {
        n = func_003D4D00((s32)o->x10, 1, D_L30_001DD5E8, (s32)o, 0);
        for (j = 0; j < n; j++) {
            m = D_L30_001ED080[j];
            if (m != 0 && m->xAA == 0x1946
                && func_0038CF00(o->x10, m->x10) < best
                && func_003D3CB0(o->x10, m->x10, 2, o, 0) == 0) {
                res = m;
                best = func_0038CF00(o->x10, m->x10);
                found = 1;
            }
        }
    }
    return found ? res : 0;
}
/* localdecomp:end func_L30_0034EDE0 */

INCLUDE_ASM("asm/levels", func_L30_0034EFB8);

/* localdecomp:start func_L30_0034F1A8 */
#include "vu0.h"
typedef int u128_34F1A8 __attribute__((mode(TI)));
typedef struct { f32 x0; u8 pad4[4]; f32 x8; u8 padC[4]; s32 x10; f32 x14; s32 x18; f32 x1C; } V_34F1A8;
typedef struct { u8 pad[0x10]; u128_34F1A8 pos; u8 pad20[0x10]; u8 x30; u8 pad31[0x34 - 0x31]; u16 x34; u8 pad36[0x68 - 0x36]; V_34F1A8 *x68; u8 pad6C[0x98 - 0x6C]; s32 x98; } O_34F1A8;
__asm__(".extern D_L30_001DD5FC, 4");
__asm__(".extern D_L30_001DD608, 4");
__asm__(".extern D_L30_001DD614, 4");
__asm__(".extern D_L30_001DD618, 4");
extern f32 D_L30_001DD5FC;
extern s32 D_L30_001DD608;
extern f32 D_L30_001DD614;
extern f32 D_L30_001DD618;
extern u128_34F1A8 D_L30_001E9020_0034F1A8;
extern void *func_003C24B0_0034F1A8(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L30_0034DB30(O_34F1A8 *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);

O_34F1A8 *func_L30_0034F1A8(u128_34F1A8 *pos, f32 ang) {
    O_34F1A8 *o = func_003C24B0_0034F1A8(0x1678, 0x80);
    V_34F1A8 *v;

    if (o == 0) {
        return 0;
    }
    o->pos = *pos;
    o->x30 = 255;
    v = o->x68;
    qzero(v);
    v->x0 = func_0038D098(ang) * D_L30_001DD614;
    v->x8 = (func_0038D0B0(ang) + D_L30_001DD618) * D_L30_001DD614;
    v->x10 = 0;
    v->x14 = ang;
    v->x18 = D_L30_001DD608;
    v->x1C = ang;
    if (func_L30_0034DB30(o) != 0) {
        o->pos = D_L30_001E9020_0034F1A8;
        v->x10++;
        func_003A52A0(0, 0, o);
        v->x0 *= -D_L30_001DD5FC;
    }
    o->x98 = 0;
    o->x34 = (o->x34 | 0x41) & ~0x1000;
    func_L01_004AA7E8(o, 1);
    func_L01_004450F0(o, 0, -1);
    return o;
}
/* localdecomp:end func_L30_0034F1A8 */

INCLUDE_ASM("asm/levels", func_L30_0034F2D8);

INCLUDE_ASM("asm/levels", func_L30_0034F5D8);

INCLUDE_ASM("asm/levels", func_L30_0034F998);

INCLUDE_ASM("asm/levels", func_L30_0034FC30);

INCLUDE_ASM("asm/levels", func_L30_0034FE30);
