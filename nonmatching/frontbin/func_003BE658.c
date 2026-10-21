/* US draft of func_003BE658 (rac3-uya-decomp func_003B9160, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003BE658 */
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
extern void *func_003CD108(s32);
extern s32 func_00382468(s32);
extern u8 *D_002FCF20[];
extern void func_003BE590();
P_3B9160 *func_003BE658(u128_3B9160 *v, f32 *pos, s32 n, s32 a3, s32 t0, s32 t1, s32 t2,
                        f32 f0, f32 f1, f32 f2) {
    P_3B9160 *p = func_003CD108(0x61);
    Q_3B9160 *q;
    if (p != 0) {
        p->v10 = *v;
        p->b1 = 0;
        p->fC = f0;
        p->x4 = (t1 << 24) | a3;
        p->b9 = 0x44;
        p->b3 = 0x48;
        p->b8 = func_00382468(0xFF);
        p->b2 = *D_002FCF20[0];
        p->hA = n;
        q = &p->q;
        q->x = pos[0];
        q->y = pos[1];
        q->z = pos[2];
        q->f1C = func_003BE590;
        q->fC = f2;
        q->b15 = t0;
        q->f10 = (f1 - f0) / n;
        q->b14 = (t2 - t1) / n;
    }
    return p;
}
/* localdecomp:end func_003BE658 */
