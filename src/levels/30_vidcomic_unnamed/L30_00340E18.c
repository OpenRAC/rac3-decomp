#include "common.h"

/* localdecomp:start func_L30_00340E18 */
/* log: first draft (sq_ra class: checked with --flags=-fno-opt-stack, the 20 save-slot diffs aside)
 *  29 diff (9 body) -> stack args s1/s3 s32 (lw+sb) -> floats after a2 in the signature: 24 (4 body)
 *  -> a1's store before m[0x30]: 20 diff, all of them save/restore slots (body exact). */
typedef int Q_00340E18 __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern f32 func_00382538(void);

typedef struct {
    s32 f0;
    s32 f4;
    u8 pad8[4];
    s16 hC;
    s16 hE;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    void *f20;
    void *f24;
    u8 b28;
    u8 b29;
    u8 b2A;
    u8 b2B;
    s32 f2C;
} P_00340E18;

u8 *func_L30_00340E18(void *pos, void *a1, void *a2,
                      f32 f12, f32 f13, f32 f14, f32 f15,
                      u8 a3, u8 a4, s16 a5, s16 a6, s32 a7, s32 s0, s32 s1, s32 s2, s32 s3) {
    u8 *m = func_003C24B0(0x11AC, 0x80);
    if (m != 0) {
        P_00340E18 *pv = *(P_00340E18 **)(m + 0x68);
        pv->f4 = s0;
        pv->b2A = s1;
        pv->f2C = s2;
        pv->b28 = a3;
        pv->b2B = s3;
        pv->b29 = a4;
        pv->f10 = f12;
        pv->f14 = f13;
        pv->f18 = f14;
        pv->f1C = f15;
        pv->hC = a5;
        pv->hE = a6;
        pv->f0 = a7;
        *(void **)(m + 0xB8) = a1;
        m[0x30] = 0xFF;
        m[0x20] = 0;
        pv->f20 = a2;
        pv->f24 = pos;
        *(Q_00340E18 *)(m + 0x10) = *(Q_00340E18 *)pos;
        *(f32 *)(m + 0xF0) = func_00382538();
        *(f32 *)(m + 0xF4) = func_00382538();
        *(f32 *)(m + 0xF8) = func_00382538();
        m[0x20] = 0;
    }
    return m;
}
/* localdecomp:end func_L30_00340E18 */
