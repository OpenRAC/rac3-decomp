/* functional: high. Draft verified against PAL asm op by op; under ps2as only an extra saved register and its shuffles differ (122 diff, VU0 scheduling). */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003AB2B0;
typedef struct { u8 *obj; u32 pad4; f32 pos[4]; } Hit_003AB2B0;
extern Hit_003AB2B0 D_L07_001E8C18;
extern u8 *D_001A71A0[4];
static __inline__ void sub_003AB2B0(V_003AB2B0 *d, V_003AB2B0 *a, V_003AB2B0 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void sub_ba_003AB2B0(V_003AB2B0 *d, V_003AB2B0 *a, V_003AB2B0 *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void add_003AB2B0(V_003AB2B0 *d, V_003AB2B0 *a, V_003AB2B0 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
void func_L07_003AB2B0(u8 *obj) {
    extern void func_003C2F58(u8 *, s32, f32 *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern void func_L01_004CB320(void);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern void func_L01_004CB358(void);
    extern f32 func_0038CF00(void *, void *);
    V_003AB2B0 start;
    V_003AB2B0 end;
    V_003AB2B0 direction;
    u8 info[0x30];
    u8 *vars = *(u8 **)(obj + 0x68);
    s32 hit;
    f32 ratio;
    u8 *m;
    func_003C2F58(obj, vars[0x533], (f32 *)&start);
    if (*(f32 *)(vars + 0x538) == 1.0f) {
        end = *(V_003AB2B0 *)(vars + 0x520);
    } else {
        sub_ba_003AB2B0(&end, (V_003AB2B0 *)(vars + 0x520), &start);
        func_0038CE20(&end, &end, *(f32 *)(vars + 0x538));
        add_003AB2B0(&end, &start, &end);
    }
    sub_003AB2B0(&direction, &end, &start);
    direction.z = 0;
    func_0038CF68(&direction, &direction, 1.0f);
    direction.z = 1.0f;
    direction.w = 5627.9248046875f;
    func_L01_00446760(info, obj, 0x10001, &direction, (f32)vars[0x44]);
    info[0x18] = 5;
    info[0x19] = 2;
    *(u16 *)(info + 0x1A) = *(u16 *)(obj + 0xAA);
    func_L01_004CB320();
    hit = func_003D3CB0(&start, &end, 0, obj, info);
    if (hit != 0) {
        m = D_L07_001E8C18.obj;
        if (m != 0 && *(s16 *)(m + 0xAA) == 0x186D && m[0x20] != 2 && m[0x20] != 5) {
            m[0x20] = 4;
        }
    }
    func_L01_004CB358();
    if (hit != 0) {
        ratio = func_0038CF00(&start, D_L07_001E8C18.pos);
        ratio /= func_0038CF00(&start, vars + 0x520);
        *(f32 *)(vars + 0x538) = ratio;
        if (ratio > 1.0f) *(f32 *)(vars + 0x538) = 1.0f;
        if (D_L07_001E8C18.obj == D_001A71A0[0]) vars[0x532] = 1;
    }
}
