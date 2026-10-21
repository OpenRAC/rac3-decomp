/* US draft of func_003BFC58 (rac3-uya-decomp func_003BA748, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003BFC58 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BA748;
typedef int Q_3BA748 __attribute__((mode(TI)));
typedef struct { s8 p0[0x20]; s8 b20; } O_3BA748;
typedef struct { O_3BA748 *obj; s32 f4; u8 p8[5]; u8 b0D; u8 pE[2]; V_3BA748 v10; } B_3BA748;
typedef struct { u8 p0[4]; s32 f4; u8 b8; u8 p9; s16 h0A; f32 fC; V_3BA748 v10; B_3BA748 b; } P_3BA748;
extern s32 func_0038CB00();
extern void func_003CD250(s32);
extern void func_003C2EC0(u8 *, s32, u8 *);
extern void func_0038D000(void *, void *, void *);
void func_003BFC58(P_3BA748 *p) {
    B_3BA748 *q;
    V_3BA748 m[4];
    Q_3BA748 x, y;
    O_3BA748 *o;
    q = &p->b;
    if (p->h0A >= 0) { if (func_0038CB00(&p->h0A) != 0) { func_003CD250((s32)p); return; } }
    o = q->obj;
    if (o != 0) {
        if (o->b20 < 0) {
kill:
            func_003CD250((s32)p);
            return;
        }
        func_003C2EC0((u8 *)o, q->f4, (u8 *)m);
        func_0038D000(&p->v10, &q->v10, m);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p->v10));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m[3]));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(p->v10) : "j"(x));
        p->v10.w = 0;
    } else {
        p->v10 = q->v10;
    }
    if (D_001DA33C != 0) {
        p->f4 = (p->f4 & 0xFFFFFF) | ((s32)(*(f32 *)0x1DA3C0 * 128.0f) << 24);
    }
    p->fC = p->fC * q->v10.w;
    p->b8 = p->b8 + q->b0D;
}
/* localdecomp:end func_003BFC58 */
