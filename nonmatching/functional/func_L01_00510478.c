/* functional: medium. Fixed the inverted slope test (retail's bc1tl delay-slot load runs when len <= 0.8727). Near-miss draft (85 diff, frame size 0xb0 vs 0xc0 and FP register allocation); VU0 add sequences kept as one asm block per retail sequence. */
/* localdecomp:start func_L01_00510478 */
extern D_001A4BE0_t D_001A4BE0;
extern Vec4 D_L01_001EAA40;
extern f32 D_L01_001EAA20[];
static __inline__ void add_00510478(Vec4 *d, Vec4 *a, Vec4 *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void add2_00510478(Vec4 *d, Vec4 *a, Vec4 *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void sub_00510478(Vec4 *d, Vec4 *a, Vec4 *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
f32 func_L01_00510478(f32 time, f32 gravity, f32 height) {
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_0044A850(void *, void *);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern f32 func_L01_00511848(Vec4 *);
    extern f32 func_L01_005114B0(f32 *);
    extern s32 func_L01_004461B8(f32, f32, f32, f32 *, f32 *);
    Vec4 delta, direction, curve, start;
    f32 root0, root1, root2, root3, root4, root5;
    f32 half, b, c;
    u8 *hero = (u8 *)&D_001A4BE0;
    switch (hero[0x25F4]) {
    case 0:
        if (height < 0.0f) {
            func_0038CE20(&delta, hero + 0xF0, time);
            delta.f[2] -= (time*time + time)*0.5f*gravity;
            add_00510478(&delta, &delta, (Vec4 *)(hero+0x80));
            direction = *(Vec4 *)(hero+0x80);
            func_L01_0044A850(&direction, &delta);
            direction = *(Vec4 *)(hero+0x80);
            if (func_003D3CB0(&direction, &delta, 0x22, 0, 0)) {
                if (func_L01_00511848(&D_L01_001EAA40) <= 0.87266463f)
                    height = *((f32 *)&D_L01_001EAA40-6);
            }
        }
        if (height > 0.0f) {
            half = gravity * -0.5f;
            if (func_L01_004461B8(half, *(f32 *)(hero+0xF8)-half,
                    *(f32 *)(hero+0x88)-height, &root0, &root1) > 0 && root0 > 0.0f)
                return root0;
        }
        break;
    case 1:
        direction = *(Vec4 *)(hero+0x2C0);
        func_0038CF68(&direction, &direction, gravity);
        func_0038CE20(&direction, &direction, -1.0f);
        func_0038CE20(&delta, hero+0xF0, time);
        func_0038CE20(&curve, &direction, (time*time+time)*0.5f*gravity);
        add_00510478(&delta, &curve, &delta);
        add2_00510478(&delta, (Vec4 *)(hero+0x80), &delta);
        start = *(Vec4 *)(hero+0x80);
        func_L01_0044A850(&start, &delta);
        if (func_003D3CB0(hero+0x80, &delta, 0x22, 0, 0)) {
            half=gravity*-0.5f;
            b=func_L01_005114B0((f32 *)(hero+0xF0))-half;
            c=func_L01_005114B0((f32 *)(hero+0x80));
            c-=func_L01_005114B0(D_L01_001EAA20);
            if (func_L01_004461B8(half,b,c,&root2,&root3)>0 && root2>0.0f)
                return root2;
        }
        break;
    case 2:
        curve.f[0]=100.0f; curve.f[1]=100.0f; curve.f[2]=100.0f;
        sub_00510478(&direction,(Vec4 *)(hero+0x80),&curve);
        func_0038CF68(&direction,&direction,gravity);
        func_0038CE20(&direction,&direction,-1.0f);
        func_0038CE20(&delta,hero+0xF0,time);
        func_0038CE20(&curve,&direction,(time*time+time)*0.5f*gravity);
        add_00510478(&delta,&curve,&delta);
        add2_00510478(&delta,(Vec4 *)(hero+0x80),&delta);
        start=*(Vec4 *)(hero+0x80);
        func_L01_0044A850(&start,&delta);
        if (func_003D3CB0(hero+0x80,&delta,0x22,0,0)) {
            half=gravity*-0.5f;
            b=func_L01_005114B0((f32 *)(hero+0xF0))-half;
            c=func_L01_005114B0((f32 *)(hero+0x80));
            c-=func_L01_005114B0(D_L01_001EAA20);
            if (func_L01_004461B8(half,b,c,&root4,&root5)>0 && root4>0.0f)
                return root4;
        }
        break;
    }
    return time;
}
/* localdecomp:end func_L01_00510478 */
