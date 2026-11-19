/* functional: high. Per-frame setup of the particle effect at object p: registers func_003C09E8 (func_00389D60(cb, p)), gets p's basis vectors into a stack block (func_003C2EC0), sets the fade flag D_001DA33C=0 / factor D_001DA340=1.0, measures d1 = |basis| and d2 = |(p+0x10) - D_00222400| (xyz): if d2/d1 > 20 sets D_001DA33C=1 and D_001DA340 = max(1 - (d2/d1 - 20)/40, 0); then twice (rings D_001D8E40[0], [1]) builds a vector via func_0038D028 and calls func_003BF988(p, vec, {0, 0, func_003824E0(0.007f, 0.015f), w unset}). The unset 4th lane of the {0,0,r} vector is left uninitialised as in retail (stack garbage); the first vector's w comes from p+0x10's w as retail's vsub.xyz keeps it. Written from the PAL asm (no draft). */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003C0720;
typedef struct { u8 p0[0x10]; V4_003C0720 v10; } O_003C0720;
extern u8 D_001DA33C;
extern f32 D_001DA340;
extern V4_003C0720 D_00222400;
extern V4_003C0720 D_001D8E40[];
extern void func_003C09E8();
extern void func_00389D60(void *, void *);
extern void func_003C2EC0(void *, s32, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038D028(void *, void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_003BF988(void *, void *, void *);

void func_003C0720(O_003C0720 *p)
{
    V4_003C0720 basis[4];
    V4_003C0720 diff;
    V4_003C0720 vec;
    V4_003C0720 rnd;
    f32 d1, d2, ratio, v;
    s32 i;

    func_00389D60(func_003C09E8, p);
    func_003C2EC0(p, 0, basis);
    D_001DA33C = 0;
    D_001DA340 = 1.0f;
    d1 = func_0038CEA8(basis);
    diff.x = p->v10.x - D_00222400.x;
    diff.y = p->v10.y - D_00222400.y;
    diff.z = p->v10.z - D_00222400.z;
    diff.w = p->v10.w;
    d2 = func_0038CEA8(&diff);
    ratio = d2 / d1;
    if (20.0f < ratio) {
        v = 1.0f - (ratio - 20.0f) / 40.0f;
        D_001DA33C = 1;
        D_001DA340 = v;
        if (v < 0.0f) {
            D_001DA340 = 0.0f;
        }
    }
    for (i = 0; i < 2; i++) {
        func_0038D028(&vec, &D_001D8E40[i], basis);
        rnd.x = 0.0f;
        rnd.y = 0.0f;
        rnd.z = func_003824E0(0.007f, 0.015f);
        func_003BF988(p, &vec, &rnd);
    }
}
