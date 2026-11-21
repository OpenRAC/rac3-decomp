/* functional: high. Projectile/particle mover: NTSC-U draft re-derived against PAL asm (extra (n*5+2)/6 step on the travel count, PAL callees); VU0 vadd.xyz kept as inline asm per the COP2 rule; compiles at level_05, bytes differ in scheduling. */
typedef int Quad_3CA628 __attribute__((mode(TI)));
extern s32 func_L01_004561B8(void), func_0038CAD0(void *);
extern void func_003C2880(void *);
extern f32 func_0038CEA8(void *), func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern u8 D_L05_001D66B0[];
extern void func_L01_004CB320(void), func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern u8 *D_L05_001EA6D8[];
extern Quad_3CA628 D_L05_001EA6E0[];
extern void func_L05_003CB090(void *), func_L05_003CAE70(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L05_003CA8F0(void *);
void func_L05_003CA628(u8 *obj) {
    struct { Quad_3CA628 old, dest, work[3]; } collision;
    u8 *sub;
    u8 *hit;
    s32 result;
    s32 n;
    f32 len;
    collision.old = *(Quad_3CA628 *)(obj + 0x10);
    sub = *(u8 **)(obj + 0x68);
    if (!obj[0x20]) {
        if (!func_L01_004561B8()) {
            __asm__("lqc2 $vf1, 16(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 16(%0)"
                : : "r"(obj), "r"(sub) : "vf1", "vf2", "memory");
        }
        if (func_0038CAD0(sub + 0x24)) {
            func_003C2880(obj);
            return;
        }
        if (!*(s32 *)(sub + 0x30)) {
            if (func_0038CEA8(sub) > *(f32 *)(sub + 0x20)) {
                __asm__("lqc2 $vf2, 0(%2)\n\tlqc2 $vf1, 16(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(collision.dest) : "r"(obj), "r"(sub) : "vf1", "vf2");
            } else {
                func_0038CF68(&collision.dest, sub, *(f32 *)(sub + 0x20));
                __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, 16(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "+m"(collision.dest) : "r"(obj) : "vf1", "vf2");
            }
            func_L01_00446760(collision.work, obj, 0x10001, D_L05_001D66B0, *(f32 *)(sub + 0x34));
            func_L01_004CB320();
            result = func_003D3CB0(obj + 0x10, &collision.dest, 16, obj, collision.work);
            if (result && (hit = D_L05_001EA6D8[0]) && *(s16 *)(hit + 0xAA) == 0x186D && hit[0x20] != 2 && hit[0x20] != 5) hit[0x20] = 4;
            func_L01_004CB358();
            if (result) {
                *(s32 *)(sub + 0x30) = 1;
                *(Quad_3CA628 *)(sub + 0x10) = D_L05_001EA6E0[0];
                len = func_0038CF00(obj + 0x10, sub + 0x10);
                len = len / func_0038CEA8(sub);
                n = (s32)len;
                n = (n * 5 + 2) / 6;
                *(s32 *)(sub + 0x24) = n;
                *(f32 *)(sub + 0x28) = 1.0f / (f32)n;
                if (!D_L05_001EA6D8[0]) func_L05_003CB090(obj);
                else func_L05_003CAE70(sub + 0x10);
            }
        }
        func_L01_00404A10(func_L05_003CA8F0, obj);
    }
    if (*(f32 *)(obj + 0x10) < 2.0f || *(f32 *)(obj + 0x10) > 1021.0f ||
        *(f32 *)(obj + 0x14) < 2.0f || *(f32 *)(obj + 0x14) > 1021.0f ||
        *(f32 *)(obj + 0x18) < 2.0f || *(f32 *)(obj + 0x18) > 1021.0f) func_003C2880(obj);
}
