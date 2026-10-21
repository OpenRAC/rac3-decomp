/* US draft of func_003BF658 (rac3-uya-decomp func_003BF568, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003BF658 */
/* PROVISIONAL, VU0 j-constraint form. One statement (the lqc2 of a) is volatile: it keeps the 0.0027f constant load from being scheduled before it, as in retail. */
typedef int Q_3B9DA8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9DA8;
typedef struct {
    u8 pad0[0x10];
    V4_3B9DA8 v10;
    V4_3B9DA8 v20;
    V4_3B9DA8 v30;
} S_3B9DA8;
extern void func_003CD608(s32);
void func_003BF658(S_3B9DA8 *p) {
    V4_3B9DA8 *q = &p->v30;
    f32 w = q->w;
    V4_3B9DA8 v, d, a;
    Q_3B9DA8 x, y, z, c;
    if (w < p->v10.z || p->v10.x < 0.0f || p->v10.y < 0.0f || 1024.0f < p->v10.x || 1024.0f < p->v10.y) {
        func_003CD608((s32)p);
        return;
    }
    *(Q_3B9DA8 *)&v = *(Q_3B9DA8 *)q;
    v.w = 0.0f;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(Q_3B9DA8 *)&p->v20));
    __asm__("sqc2 %1, %0" : "=m"(*(Q_3B9DA8 *)&a) : "j"(x));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(Q_3B9DA8 *)&v));
    __asm__("lqc2 %0, %1" : "=j"(c) : "m"(*(Q_3B9DA8 *)&v));
    __asm__("sqc2 %1, %0" : "=m"(*(Q_3B9DA8 *)&d) : "j"(y));
    __asm__ __volatile__("lqc2 %0, %1" : "=j"(y) : "m"(*(Q_3B9DA8 *)&a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(y), "j"(c));
    __asm__("sqc2 %1, %0" : "=m"(*(Q_3B9DA8 *)&p->v20) : "j"(x));
    __asm__(
        "lqc2 $vf1, %0\n"
        "lqc2 $vf2, %1\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %0\n"
        : "+m"(*(Q_3B9DA8 *)&p->v10) : "m"(*(Q_3B9DA8 *)&d), "m"(*(Q_3B9DA8 *)&p->v20));
    q->z -= 0.00272222236f;
    q->w = w;
}
/* localdecomp:end func_003BF658 */
