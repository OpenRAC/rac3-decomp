/* functional: high. Checked vs asm: arg registers (pos,velocity,duration,color,delta,alpha0,alpha1,f12..f14), offsets 0x1,0x2,0x3,0x4,0x8,0x9,0xA,0xC,0x10(quad),0x20.. (velocity, gravity 0x2C, delta 0x35, scale step 0x30, alpha step 0x34, callback 0x3C). 37 words differ (schedule). Integer division by duration has no guard in retail; a host build must not trap on duration==0 (PS2 gives lo=+-1). */
typedef int u128_3B9160 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, fC, f10;
    u8 b14, b15;
    u8 pad16[6];
    void *f1C;
} Q_3B9160;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 x4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    u128_3B9160 v10;
    Q_3B9160 q;
} P_3B9160;
extern void *func_003CD4C0(s32);
extern s32 func_00382848(s32);
extern u8 *D_002FCF20[];
extern void func_003BE948();
/* returns the new particle (P_3B9160) or 0 */
P_3B9160 *func_003BEA10(Q_3B9160 *pos, f32 *velocity, s32 duration,
    s32 color, s32 delta, s32 alpha0, s32 alpha1, f32 scale0, f32 scale1, f32 gravity) {
    P_3B9160 *p;
    Q_3B9160 *q;
    p = func_003CD4C0(0x61);
    if (p) {
        u128_3B9160 position = *(u128_3B9160 *)pos;
        p->b1 = 0;
        p->fC = scale0;
        p->v10 = position;
        p->b9 = 0x44;
        p->b3 = 0x48;
        p->x4 = (alpha0 << 24) | color;
        p->b8 = func_00382848(255);
        p->b2 = D_002FCF20[0][0];
        p->hA = duration;
        q = &p->q;
        q->x = velocity[0];
        q->y = velocity[1];
        q->z = velocity[2];
        q->fC = gravity;
        q->b15 = delta;
        q->f10 = (scale1 - scale0) / duration;
        q->b14 = (alpha1 - alpha0) / duration;
        q->f1C = func_003BE948;
    }
    return p;
}
