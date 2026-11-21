/* functional: high. Uses the file's raw VU0 asm style. */
/* localdecomp:start func_L01_00474680 */
typedef int Q_00474680 __attribute__((mode(TI)));
typedef union { Q_00474680 q; f32 f[4]; } Vec_00474680;
typedef struct { f32 x, y, z; s16 life; } Sub_00474680;
typedef struct {
    u8 type, flags, texture, render;
    u32 rgba;
    u8 spin, render2;
    s16 life;
    u32 end_rgba;
    Vec_00474680 pos;
    Vec_00474680 vel;
    Sub_00474680 sub;
} Part_00474680;
extern u8 *D_L01_00221204[];
Part_00474680 *func_L01_00474680(Q_00474680 *pos, Q_00474680 *velocity,
    s32 life, s32 rgba, s32 end_rgba, s32 spin, s32 texture,
    f32 width, f32 drag, f32 speed, f32 scale) {
    extern Part_00470258 *func_L01_004618E0(s32);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    Q_00474680 temp;
    u8 *p;
    u8 *s;
    p = (u8 *)func_L01_004618E0(0x77);
    if (p != 0) {
        *(u32 *)(p+4) = rgba;
        *(u32 *)(p+12) = end_rgba;
        p[9] = 0x22;
        p[3] = 0x48;
        p[1] = 3;
        p[2] = D_L01_00221204[0][texture];
        *(f32 *)(p+0x30) = func_0038CEA8(velocity);
        s = p + 0x30;
        *(Q_00474680 *)(p+0x10) = *pos;
        func_0038CF68(&temp, velocity, speed);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*(Q_00474680 *)(p+0x20)) : "m"(*pos), "m"(temp) : "vf1", "vf2");
        *(f32 *)(p+0x2c) = drag;
        p[8] = spin;
        *(f32 *)(p+0x1c) = width;
        *(s16 *)(p+10) = life;
        *(s16 *)(s+12) = life;
        *(f32 *)(s+4) = width;
        *(f32 *)(s+8) = scale;
    }
    return (Part_00474680 *)p;
}
/* localdecomp:end func_L01_00474680 */
