#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

typedef int Q __attribute__((mode(TI)));
typedef struct {u8 pad[0x30]; Q pos; u8 tail[0x40];} Rec;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad14[0xC];
    s32 ids[8];
    u8 quads[0x80];
} P_003AD358;

/* declared by functions of L19_003ADE70.c, which this file was cut from */
extern u8 *D_L19_001DF71C_003AD358;

/* localdecomp:start func_L19_003AF080 */
#include "vu0.h"
typedef int Q_003AF080 __attribute__((mode(TI)));
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad14[0xC];
    s32 ids[8];
    Q_003AF080 quads[8];
} P_003AF080;
extern u8 *D_L19_001DF71C;
extern void func_0038CE20(void *, void *, f32);

void func_L19_003AF080(u8 *e) {
    P_003AF080 *p = *(P_003AF080 **)(e + 0x68);
    f32 t = (f32)p->f4 / (f32)p->f8;
    Q_003AF080 buf[3];
    s32 i;
    buf[0] = *(Q_003AF080 *)(D_L19_001DF71C + 0x10 + p->ids[0] * 256);
    vec_sub_ab(&buf[1], &p->quads[1], &p->quads[0]);
    func_0038CE20(&buf[2], &buf[1], (1.0f - t) * (f32)p->fC);
    for (i = 0; i < p->fC; i++) {
        u8 *tgt = D_L19_001DF71C + (p->ids[i] << 8);
        vec_sub_ab(tgt + 0x10, &p->quads[i], &buf[2]);
        if ((f32)(i + 1) / (f32)p->fC <= 1.0f - t) {
            *(u16 *)(tgt + 0x34) |= 0x41;
            *(s32 *)(tgt + 0x98) = 0;
        } else {
            *(u16 *)(tgt + 0x34) &= 0xFFBE;
            *(s32 *)(tgt + 0x98) = *(s32 *)(*(u8 **)(tgt + 0x24) + 0x10);
        }
    }
}
/* localdecomp:end func_L19_003AF080 */
