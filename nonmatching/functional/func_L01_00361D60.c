/* functional: high. Uses file-context D_L01_ names (gp-relative vs lui addressing differs from retail so 138 words differ, same addresses); layout of stack packet (colors 0x40, uv 0x50, tags 0x70-0x88, mat 0x90, offset 0xC0) verified against asm */
typedef struct { u8 pad0[0x25C0]; u8 *moby; } Game_00361D60;
extern Game_00361D60 D_001A4BE0_00361D60;
void func_L01_00361D60(void *m) {
    extern unsigned long func_00389598(s32);
    extern void func_003C5180(void *, s128 *, s32);
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    struct {
        s128 pos[4];
        s32 colors[4];
        f32 uv[8];
        unsigned long w70, w78, w80, w88;
        s128 mat[3];
        s128 offset;
        f32 *pu;
        f32 *pv;
    } v;
    u8 *p = *(u8 **)((u8 *)m + 0x68);
    s32 color;
    s32 i, next, j, uvindex;
    s16 *indices;
    s128 *dst;
    f32 *pu, *pv;
    v.w78 = func_00389598(D_L01_001DD744);
    v.w88 = (unsigned long)D_L01_001DD730 | ((unsigned long)D_L01_001DD734 << 2) | ((unsigned long)D_L01_001DD738 << 4) | ((unsigned long)D_L01_001DD73C << 6) | ((unsigned long)D_L01_001DD740 << 32);
    v.w80 = 0xFF9000000260;
    qzero(&v.mat[0]);
    qzero(&v.mat[1]);
    qzero(&v.mat[2]);
    v.w70 = 0;
    ((f32 *)&v.mat[0])[0] = *(f32 *)(p + 0x24);
    ((f32 *)&v.mat[1])[1] = *(f32 *)(p + 0x24);
    ((f32 *)&v.mat[2])[2] = *(f32 *)(p + 0x24) * 0.125f;
    color = D_L01_001DD748 + (*(s32 *)(p + 0x20) << 24);
    v.colors[0] = v.colors[1] = v.colors[2] = v.colors[3] = color;
    func_003C5180(p, &v.offset, 1);
    func_0038CE20(&v.offset, &v.offset, 0.25f);
    v.pu = &v.uv[0];
    v.pv = &v.uv[1];
    for (i = 0; i < 64; i = next) {
        next = i + 1;
        indices = D_L01_002B3080[i];
        pv = v.pv; pu = v.pu;
        dst = v.pos;
        for (j = 3; j >= 0; j--) {
            uvindex = indices[1];
            func_0038CE20(dst, (s128 *)&D_L01_002B2B80[indices[0]], D_L01_001DD704);
            {
                f32 u = D_L01_002B3480[uvindex][0];
                f32 w = D_L01_002B3484[uvindex][0];
                *pu = u;
                *pv = w;
            }
            func_0038D000(dst, dst, v.mat);
            pu += 2; pv += 2;
            indices += 2;
            func_0038D000(dst, dst, D_001A4BE0_00361D60.moby + 0xC0);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0\n\tlqc2 $vf2, %0\n\tlqc2 $vf1, %3\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*dst) : "m"(*dst), "m"(*(s128 *)p), "m"(v.offset) : "vf1", "vf2");
            dst++;
        }
        func_003D2DA0(&v, 0, 0);
    }
}
