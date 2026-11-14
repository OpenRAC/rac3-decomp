/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_0046E860, the NTSC-U twin of func_L01_00471FB0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_0046A938.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0046E860 */
/* Needs -mvu0-use-vf0-vf2 (vec_* helpers) beyond the PAL file's flags. */
typedef struct {
    vu0_v4 vel;
    s32 w10;
    s32 w14;
} Sub_0046E860;

typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    s16 h0A;
    u8 pad0C[4];
    vu0_v4 pos;
    Sub_0046E860 s20;
} Obj_0046E860;

extern f32 D_L01_001E2A48[];
extern s32 D_L01_001E0334;
extern s32 D_001E0334_sda;
__asm__(".extern D_001E0334_sda, 4");
extern vu0_v4 D_L01_001E0340;
extern s32 D_L01_001DFBC0;
extern vu0_v4 D_L01_001E2A70;

extern s32 func_003883C8(void *);
extern void func_003C7CE0(void *);
extern void func_L01_004C6EC8(void *, void *);
extern f32 func_00388978(f32);
extern void func_003886E8(void *, void *, f32);

void func_L01_0046E860(Obj_0046E860 *o) {
    Sub_0046E860 *s;
    vu0_v4 tmp;
    s32 n;
    s32 w;
    f32 d;

    s = &o->s20;
    d = o->pos.z - D_L01_001E2A48[0];
    if (d < -7.0f || (s->w14 != 0 && func_003883C8(&o->h0A) != 0)) {
        n = s->w10 - 1;
        s->w10 = n;
        if (n <= 0) {
            func_003C7CE0(o);
            D_001E0334_sda = D_L01_001E0334 - 1;
            return;
        }
        o->w4 = (o->w4 & 0xFFFFFF) + (n << 24);
    } else {
        w = o->w4;
        if ((w >> 24) < s->w10) {
            o->w4 = w + 0x1000000;
        }
    }
    if (((s32)o & 0x80) == 0) {
        o->b8 = o->b8 + 2;
    } else {
        o->b8 = o->b8 - 2;
    }
    vec_add_ba(&o->pos, &o->pos, &s->vel);
    vec_add_ab(&o->pos, &o->pos, &D_L01_001E0340);
    func_L01_004C6EC8(&o->pos, &o->pos);
    if (s->w14 == 0) {
        n = o->h0A;
        d = func_00388978((f32)(D_L01_001DFBC0 & (n - 1)) / (f32)n * 6.2831855f);
        func_003886E8(&tmp, &D_L01_001E2A70, d * 0.016666668f);
        vec_add_ba(&o->pos, &tmp, &o->pos);
    }
}
/* localdecomp:end func_L01_0046E860 */
