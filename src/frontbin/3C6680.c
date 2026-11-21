#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C6680(void *, void *, s32, s32, void *, void *, void *, void *, void *, void *, void *);
/* --- end of declarations from other files --- */

typedef int Q_3C1130 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C1130;
typedef struct { f32 v[3]; } F3_3C1130;
typedef struct { u8 p0[0x10]; V_3C1130 f10; u8 p20[0x14]; u16 f34; u8 p36[0x8A]; u8 fC0[0x30]; V_3C1130 fF0; } O_3C1130;
typedef struct {
    V_3C1130 f0; V_3C1130 f10; V_3C1130 f20; u8 p30[0x18];
    f32 f48[3]; f32 f54[3]; f32 f60[3]; f32 f6C[3]; f32 f78[3]; f32 f84[3]; f32 f90[3]; f32 f9C[3];
} C_3C1130;
extern const F3_3C1130 D_001D91F0;
extern const F3_3C1130 D_001D9200;
extern const F3_3C1130 D_001D9210;
extern const F3_3C1130 D_001D9220;
extern const F3_3C1130 D_001D9230;
extern const F3_3C1130 D_001D9240;
extern void func_0038D000(void *, void *, void *);
extern f32 func_00382538(void);
/* localdecomp:start func_003C6680 */
void func_003C6680(void *o_, void *c_, s32 pos_, s32 dir_, void *amp_, void *rate_, void *k48_, void *k54_, void *k6C_, void *k60_, void *k78_) {
    O_3C1130 *o = o_;
    C_3C1130 *c = c_;
    V_3C1130 *pos = (V_3C1130 *)pos_;
    V_3C1130 *dir = (V_3C1130 *)dir_;
    f32 *amp = amp_, *rate = rate_, *k48 = k48_, *k54 = k54_, *k6C = k6C_, *k60 = k60_, *k78 = k78_;
    F3_3C1130 l0, l10, l20, l30, l40, l50, l60;
    s32 i;
    l0 = D_001D91F0;
    l10 = D_001D9200;
    l20 = D_001D9210;
    l30 = D_001D9220;
    l40 = D_001D9230;
    l50 = D_001D9220;
    l60 = D_001D9240;
    o->f34 |= 0x100;
    if (pos != 0) {
        func_0038D000(c, pos, o->fC0);
        __asm__(
            "lqc2 $vf1, %1\n"
            "lqc2 $vf2, %2\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            : "=m"(c->f0) : "m"(c->f0), "m"(o->f10));
        *(Q_3C1130 *)&c->f10 = *(Q_3C1130 *)pos;
    } else {
        *(Q_3C1130 *)&c->f0 = *(Q_3C1130 *)&o->f10;
    }
    if (dir != 0) {
        *(Q_3C1130 *)&c->f20 = *(Q_3C1130 *)dir;
    } else {
        *(Q_3C1130 *)&c->f20 = *(Q_3C1130 *)&o->fF0;
    }
    if (amp == 0) amp = l50.v;
    if (rate == 0) rate = l60.v;
    if (k78 == 0) k78 = l30.v;
    if (k60 == 0) k60 = l40.v;
    if (k48 == 0) k48 = l0.v;
    if (k54 == 0) k54 = l10.v;
    if (k6C == 0) k6C = l20.v;
    for (i = 0; i < 3; i++) {
        c->f78[i] = k78[i];
        c->f48[i] = k48[i];
        c->f60[i] = k60[i];
        c->f54[i] = k54[i];
        c->f6C[i] = k6C[i];
        c->f84[i] = func_00382538();
        c->f9C[i] = amp[i];
        c->f90[i] = rate[i] * 0.017453292f * 0.020000001f;
    }
}
/* localdecomp:end func_003C6680 */
