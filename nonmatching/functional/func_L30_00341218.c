/* functional: medium. Codex near-miss draft kept; 318 diff words are VU0 op ordering and regalloc; checked call sequence, packet state constants and loops against asm; uses lqc2/sqc2 inline asm only */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_00341218;
typedef struct {
    Vec_00341218 p[4];
    u32 rgba[4];
    f32 uv[8];
    unsigned long state[4];
} Packet_00341218;
extern Vec_00341218 D_L30_001E2240;
static __inline__ void sub_00341218(Vec_00341218 *d, Vec_00341218 *a, Vec_00341218 *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void add_00341218(Vec_00341218 *d, Vec_00341218 *a, Vec_00341218 *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void copy_00341218(Vec_00341218 *d, Vec_00341218 *a) {
    __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(*d) : "m"(*a) : "vf1");
}
void func_L30_00341218(void *points, int alpha, int alpha2, int count, float width, float outer, float extent, int rgb, int rgb2)
{
    extern unsigned long func_00389598(long);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003D2DA0(void *, s32, s32);
    extern void func_003A9440(long, long);
    Packet_00341218 innerPacket, outerPacket;
    Vec_00341218 cross, side, eye, segment, p0, p1, dir0, dir1, toeye, extension;
    Vec_00341218 t0, t1, cameraCopy, cameraCopy2, temp;
    Vec_00341218 *p = points;
    unsigned long texture;
    u32 color, color2;
    s32 i;
    f32 length, length0, length1, reciprocal;
    texture = func_00389598(20);
    color = rgb | (alpha << 24);
    innerPacket.state[3] = 0x8000000048UL;
    innerPacket.state[2] = 0xFF9000000260UL;
    innerPacket.state[1] = texture;
    innerPacket.state[0] = 0;
    innerPacket.rgba[3] = color;
    innerPacket.rgba[2] = color;
    innerPacket.rgba[1] = color;
    innerPacket.rgba[0] = color;
    texture = func_00389598(16);
    copy_00341218(&temp, &p[0]);
    color2 = rgb2 | (alpha2 << 24);
    outerPacket.state[3] = innerPacket.state[3];
    outerPacket.state[2] = innerPacket.state[2];
    outerPacket.state[1] = texture;
    outerPacket.state[0] = innerPacket.state[0];
    outerPacket.rgba[3] = color2;
    outerPacket.rgba[2] = color2;
    outerPacket.rgba[1] = color2;
    outerPacket.rgba[0] = color2;
    outerPacket.uv[0] = 0.0f; outerPacket.uv[1] = 0.0f;
    outerPacket.uv[2] = 0.0f; outerPacket.uv[3] = 1.0f;
    outerPacket.uv[4] = 1.0f; outerPacket.uv[5] = 0.0f;
    outerPacket.uv[6] = 1.0f; outerPacket.uv[7] = 1.0f;
    innerPacket.uv[0] = 0.0f; innerPacket.uv[1] = 0.0f;
    innerPacket.uv[2] = 0.0f; innerPacket.uv[3] = 1.0f;
    innerPacket.uv[4] = 1.0f; innerPacket.uv[5] = 0.0f;
    innerPacket.uv[6] = 1.0f; innerPacket.uv[7] = 1.0f;
    sub_00341218(&t0, &temp, &D_L30_001E2240);
    sub_00341218(&segment, &p[1], &p[0]);
    copy_00341218(&eye, &t0);
    func_0038CE90(&cross, &segment, &eye);
    length = func_0038CEA8(&cross);
    if (length == 0.0f) reciprocal = length;
    else reciprocal = 1.0f / length;
    func_0038CE20(&cross, &cross, width * reciprocal);
    add_00341218(&innerPacket.p[0], &p[0], &cross);
    sub_00341218(&innerPacket.p[1], &p[0], &cross);
    for (i = 1; i < count - 1; i++) {
        sub_00341218(&temp, &p[i], &D_L30_001E2240);
        copy_00341218(&t1, &p[i]);
        copy_00341218(&eye, &temp);
        sub_00341218(&segment, &p[i+1], &t1);
        func_0038CE90(&cross, &segment, &eye);
        length = func_0038CEA8(&cross);
        if (length == 0.0f) reciprocal = length;
    else reciprocal = 1.0f / length;
        func_0038CE20(&cross, &cross, width * reciprocal);
        add_00341218(&innerPacket.p[2], &p[i], &cross);
        sub_00341218(&innerPacket.p[3], &p[i], &cross);
        if (i == 1) innerPacket.rgba[1] = innerPacket.rgba[0] = rgb;
        else if (i == 2) innerPacket.rgba[1] = innerPacket.rgba[0] = color;
        func_003D2DA0(&innerPacket, 0, 0);
        *(u128_t *)&innerPacket.p[0] = *(u128_t *)&innerPacket.p[2];
        *(u128_t *)&innerPacket.p[1] = *(u128_t *)&innerPacket.p[3];
    }
    for (i = 0; i < count - 1; i++) {
        copy_00341218(&temp, &p[i]);
        sub_00341218(&temp, &temp, &D_L30_001E2240);
        copy_00341218(&cameraCopy, &D_L30_001E2240);
        copy_00341218(&dir0, &temp);
        sub_00341218(&dir1, &p[i+1], &cameraCopy);
        length0 = func_0038CEA8(&dir0);
        length1 = func_0038CEA8(&dir1);
        if (length1 < length0) {
            if (length1 == 0.0f) *(u128_t *)&dir1 = *(u128_t *)&dir0;
            else func_0038CE20(&dir1, &dir1, length0 / length1);
        } else {
            if (length0 == 0.0f) *(u128_t *)&dir0 = *(u128_t *)&dir1;
            else func_0038CE20(&dir0, &dir0, length1 / length0);
        }
        add_00341218(&p0, &D_L30_001E2240, &dir0);
        add_00341218(&p1, &D_L30_001E2240, &dir1);
        sub_00341218(&segment, &p1, &p0);
        func_0038CE20(&extension, &segment, extent);
        sub_00341218(&p0, &p0, &extension);
        copy_00341218(&cameraCopy2, &D_L30_001E2240);
        add_00341218(&p1, &p1, &extension);
        sub_00341218(&toeye, &cameraCopy2, &p0);
        func_0038CE90(&cross, &toeye, &segment);
        length = func_0038CEA8(&cross);
        if (length == 0.0f) reciprocal = length;
    else reciprocal = 1.0f / length;
        func_0038CE20(&side, &cross, outer * reciprocal);
        add_00341218(&outerPacket.p[0], &p0, &side);
        sub_00341218(&outerPacket.p[1], &p0, &side);
        add_00341218(&outerPacket.p[2], &p1, &side);
        sub_00341218(&outerPacket.p[3], &p1, &side);
        if (i == 0) outerPacket.rgba[1] = outerPacket.rgba[0] = rgb2;
        else if (i == 1) outerPacket.rgba[1] = outerPacket.rgba[0] = color2;
        func_003D2DA0(&outerPacket, 0, 0);
    }
    func_003A9440(71, 0x5360B);
}
