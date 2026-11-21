/* functional: medium. 561 words differ; all loops, delay-slot stores, packet layout (pos 0, col 0x40, uv 0x50, tags 0x70-0x88), clamp logic and 20 float constants traced from asm. Uncertain: types of D_L01_001DD7xx vars (floats assumed), D_L01_0028E440 addressed in bytes (rows of 0x140), own typedefs needed because this file's context has none */
typedef int s128_364180 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) S_364180;
static __inline__ void qv_sub(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(S_364180 *)d) : "m"(*(S_364180 *)a), "m"(*(S_364180 *)b) : "vf1", "vf2");
}
typedef struct {
    S_364180 pos[4];
    s32 col[4];
    f32 uv[8];
    unsigned long w70, w78, w80, w88;
} Pkt_00364180;
extern s32 D_L01_001DD760, D_L01_001DD764, D_L01_001DD768, D_L01_001DD76C, D_L01_001DD770;
extern f32 D_L01_001DD77C;
extern f32 D_L01_001DD780;
extern f32 D_L01_001DD784;
extern f32 D_L01_001DD7AC, D_L01_001DD7B0;
extern s32 D_L01_001DD7B4;
extern f32 D_L01_001DD7B8, D_L01_001DD7BC, D_L01_001DD7C0, D_L01_001DD7C4, D_L01_001DD7C8, D_L01_001DD7CC;
extern f32 D_L01_001DD7D0, D_L01_001DD7D4;
extern f32 D_L01_001DD7DC;
extern s32 D_001D673C;
extern u8 *D_001A71A0[];
extern u8 D_00142647[];
extern u8 D_L01_002C5600[];
extern s16 D_L01_001E1B10[];
extern f32 D_L01_001E1B30[];
extern u8 D_L01_001E29C0[];
extern u8 D_L01_001E2DC0[];
extern u8 D_L01_0028E440[];
extern S_364180 D_L01_0028E3A0[];
extern S_364180 D_L01_0028E3B0[];
extern S_364180 D_L01_0028E3D0[];
extern S_364180 D_L01_0028E3E0[];
void func_L01_00364180(void) {
    extern unsigned long func_00389598(s32);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_0038CE68(void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    extern void func_003A9440(s32, unsigned long);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_L01_00363E68(void *, s32, f32, f32, f32, f32);
    extern s32 func_0038DC20(void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    extern void func_0038D328(void *, void *);
    extern void func_L01_003660B0(void *, void *, s32, s32, f32, f32, f32, f32, f32, f32);
    Pkt_00364180 p;
    S_364180 a, b, nrm, view, rot, dir;
    s128_364180 mat[4];
    f32 phase, u, unext, uprev, v, vnew, t;
    s32 j, k, k1, i, color, base, val;

    p.w78 = func_00389598(D_L01_001DD770);
    phase = D_L01_001DD77C;
    p.w80 = 0x8000000260UL;
    p.w88 = (unsigned long)D_L01_001DD760 | ((unsigned long)D_L01_001DD764 << 2) | ((unsigned long)D_L01_001DD768 << 4) | ((unsigned long)D_L01_001DD76C << 6) | 0x8000000000UL;
    p.w70 = 0;
    t = phase + 0.0010000000474974513f;
    D_L01_001DD77C = t;
    if (7.0f < t) {
        D_L01_001DD77C = t - 7.0f;
    }
    u = phase + 0.30000001192092896f;
    for (j = 1; j < 10; j++) {
        v = D_L01_001DD780;
        t = v + D_L01_001DD784;
        D_L01_001DD780 = t;
        if (7.0f < t) {
            D_L01_001DD780 = t - 7.0f;
        }
        base = ((D_L01_002C5600 + D_00142647[0] * 0xF0)[1] < 2) ? 0x404040 : 0x406080;
        unext = u + 0.30000001192092896f;
        for (k = 0; k < 20; k++) {
            k1 = (k + 1) % 20;
            p.pos[0] = *(S_364180 *)(D_L01_0028E440 + j * 0x140 + k * 16);
            p.pos[1] = *(S_364180 *)(D_L01_0028E440 + j * 0x140 + k1 * 16);
            p.pos[2] = *(S_364180 *)(D_L01_0028E440 + (j - 1) * 0x140 + k * 16);
            p.pos[3] = *(S_364180 *)(D_L01_0028E440 + (j - 1) * 0x140 + k1 * 16);
            qv_sub(&a, &p.pos[0], &p.pos[1]);
            qv_sub(&b, &p.pos[2], &p.pos[1]);
            func_0038CE90(&nrm, &b, &a);
            qv_sub(&view, &p.pos[1], D_L01_001E29C0);
            if (0.0f <= func_0038CE68(&nrm, &view)) {
                v = v + 0.05000000074505806f;
            } else {
                vnew = v + 0.05000000074505806f;
                uprev = u - 0.30000001192092896f;
                val = D_L01_001E1B10[j];
                for (i = 0; i < 2; i++) {
                    if (!(-1 < val)) {
                        val = 0;
                    }
                    if (!(val < 0x21)) {
                        val = 0x20;
                    }
                    color = (val << 24) | base;
                    p.col[i * 2 + 1] = color;
                    p.col[i * 2] = color;
                    val = (s16)D_L01_001E1B10[j - 1];
                }
                if (j == 1) {
                    p.col[2] = 0x20404040;
                    p.col[3] = 0x20404040;
                } else if (j == 9) {
                    p.col[0] = 0x404040;
                    p.col[1] = 0x404040;
                }
                p.uv[5] = v;
                p.uv[1] = v;
                p.uv[0] = u;
                p.uv[6] = uprev;
                p.uv[2] = u;
                p.uv[3] = vnew;
                p.uv[4] = uprev;
                p.uv[7] = vnew;
                v = vnew;
                func_003D2DA0(&p, 0, 0);
            }
        }
        u = unext;
    }
    func_003A9440(0x47, 0x5360BUL);
    t = D_L01_001DD7DC + 1.0f;
    D_L01_001DD7DC = t;
    if (30.0f < t && D_001D673C == 0) {
        D_L01_001DD7B8 = func_0038DAB8(D_L01_001DD7B8, func_003824E0(-1.5f, -3.0f) * 0.01745329238474369f);
        D_L01_001DD7BC = func_0038DAB8(D_L01_001DD7BC, func_003824E0(-3.5f, -6.0f) * 0.01745329238474369f);
        D_L01_001DD7C0 = func_0038DAB8(D_L01_001DD7C0, func_003824E0(-1.5f, -6.5f) * 0.01745329238474369f);
        D_L01_001DD7C4 = func_0038DAB8(D_L01_001DD7C4, func_003824E0(-3.5f, -6.0f) * 0.01745329238474369f);
        D_L01_001DD7C8 = func_0038DAB8(D_L01_001DD7C8, func_003824E0(-4.5f, -6.0f) * 0.01745329238474369f);
        D_L01_001DD7CC = func_0038DAB8(D_L01_001DD7CC, func_003824E0(-5.0f, -8.0f) * 0.01745329238474369f);
        t = D_L01_001DD7D0 - 0.00800000037997961f;
        D_L01_001DD7D0 = t;
        if (t < 0.699999988079071f) {
            D_L01_001DD7D0 = 1.7000000476837158f;
        }
        t = D_L01_001DD7D4 - 0.00800000037997961f;
        D_L01_001DD7D4 = t;
        if (t < 0.699999988079071f) {
            D_L01_001DD7D4 = 1.7000000476837158f;
        }
        if (0.4000000059604645f < func_0038CE68(D_L01_001E2DC0, D_001A71A0[0] + 0xC0)) {
            func_L01_00363E68(D_L01_0028E3B0, 0x36, 0.699999988079071f, 0.0f, D_L01_001DD7B8, 0.800000011920929f);
            func_L01_00363E68(D_L01_0028E3B0, 0x36, 0.699999988079071f, 0.0f, D_L01_001DD7BC, 0.800000011920929f);
        }
        a = *(S_364180 *)D_L01_0028E3E0;
        a.w = 0.5f;
        if (func_0038DC20(&a, 96.0f) > 0) {
            func_L01_00363E68(D_L01_0028E3D0, 0x36, 1.0f, 0.0f, D_L01_001DD7C0, 0.800000011920929f);
            func_L01_00363E68(D_L01_0028E3D0, 0x36, 1.0f, 0.0f, D_L01_001DD7C4, 0.800000011920929f);
            func_L01_00363E68(D_L01_0028E3E0 + 1, 0x36, 1.399999976158142f, 0.0f, D_L01_001DD7C8, 0.800000011920929f);
            func_L01_00363E68(D_L01_0028E3E0 + 1, 0x36, 1.399999976158142f, 0.0f, D_L01_001DD7CC, 0.800000011920929f);
        }
    }
    D_L01_001DD7AC = func_0038DAB8(D_L01_001DD7AC, func_003824E0(-1.0f, -2.0f) * 0.01745329238474369f);
    D_L01_001DD7B0 = func_0038DAB8(D_L01_001DD7B0, func_003824E0(-2.0f, -4.0f) * 0.01745329238474369f);
    if (D_L01_001E1B10[1] > 0x20) {
        s32 jj = 1;
        do {
            f32 *angle = &D_L01_001E1B30[jj];
            f32 s;
            f32 rnd;
            *angle = func_0038DAB8(*angle, func_003824E0(17.0f, 25.0f) * 0.01745329238474369f);
            qv_sub(&dir, &D_L01_0028E3A0[jj], &D_L01_0028E3A0[jj - 1]);
            func_0038CF68(&dir, &dir, 1.0f);
            rot.x = 0.0f;
            rot.y = func_0038D160(func_0038CED8(&dir), dir.z) + -1.5707963705062866f;
            rot.z = func_0038D160(dir.x, dir.y);
            rot.w = 1.0f;
            func_0038D328(mat, &rot);
            s = (f32)jj * 0.17000000178813934f + 0.3499999940395355f;
            jj++;
            rnd = func_003824E0(40.0f, 150.0f);
            func_L01_003660B0(&D_L01_0028E3A0[jj - 1], mat, D_L01_001DD7B4, 0x20604040, *angle, s, 15.0f, 35.0f, D_L01_001DD7AC, rnd);
        } while (jj < 10 && D_L01_001E1B10[jj] > 0x20);
    }
}
