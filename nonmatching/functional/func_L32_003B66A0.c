/* functional: high. Draft (claimed 2 diff under ps2as, ~227 with the stock check here; structure only) verified line by line against PAL asm: all gp globals (DEF18..DEF68), the collision-bounce block (0.74f, D_L32_001E9980 +0x18/+0x24), the four func_L03_0034B148(f32,s32,s32) calls (third arg a1->0x8 explicit). Needs -mvu0-use-vf0-vf2 and --as ps2as to compile like the file. */

typedef int u128_t __attribute__((mode(TI)));
extern f32 D_L32_001DEF44;
extern f32 D_L32_001DEF4C;
extern f32 D_L32_001DEF48;
extern f32 D_L32_001DEF1C;
extern f32 D_L32_001DEF64;
extern f32 D_L32_001DEF60;
extern f32 D_L32_001DEF58;
extern f32 D_L32_001DEF68;
extern s32 D_L32_001DEF30;
extern s32 D_L32_001DEF2C;
extern s32 D_L32_001DEF28;
extern s32 D_L32_001DEF24;
extern f32 D_L32_001DEF20;
extern f32 D_L32_001DEF50;
extern f32 D_L32_001DEF18;
extern u8 D_L32_001E9980[];
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_L03_0034B148(s32, s32, f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

void func_L32_003B66A0(u8 *a0, u8 *a1) {
    u8 *p;
    u8 *q;
    f32 f20, f21, f22, f23, f24, f25, f26, f27;
    f32 fs, fz;
    u16 v;
    f32 vC[4];
    f32 vA[4];
    f32 vB[4];
    if (a1 != 0) {
        p = *(u8 **)a1;
        q = *(u8 **)(a1 + 4);
        if (p != 0) if (q != 0) {
            v = *(u16 *)(a1 + 0xE);
            f25 = (f32)(v & 0xFF);
            f26 = D_L32_001DEF44 * (f32)*(s16 *)(a1 + 8) * (f32)(v >> 8) * 0.00390625f;
            f27 = func_003C4088(D_L32_001DEF4C, D_L32_001DEF48, (f32)*(u8 *)(a1 + 0xC) * 0.00390625f);
            if (*(u16 *)(a1 + 0xA) & 1) {
                f21 = 0.0f;
                f24 = 1.0f;
                f23 = func_0038DAB8(func_0038DB48(func_003824E0(-D_L32_001DEF1C, D_L32_001DEF1C)), 3.1415927f);
                f22 = func_003824E0(D_L32_001DEF64, D_L32_001DEF60);
                f20 = func_0038DB48(func_003824E0(f21, 6.2831855f));
                func_003C2F58(p, 0, a0 + 0x10);
                vA[0] = func_0038D098(f20) * D_L32_001DEF58;
                vA[2] = func_0038D0B0(f20) * D_L32_001DEF58;
                vA[1] = f21;
                vec_add_ab(a0 + 0x10, a0 + 0x10, vA);
                *(f32 *)(a0 + 0x14) += D_L32_001DEF68;
                vB[0] = func_0038D098(f23) * f22;
                vB[2] = func_0038D0B0(f23) * f22;
                *(f32 *)(a1 + 0x10) = vB[0];
                vB[1] = f21;
                *(f32 *)(a1 + 0x14) = vB[2];
                *(s32 *)(a1 + 0x18) = func_0038DBD8(func_003824E0(f21, f24), D_L32_001DEF30, D_L32_001DEF2C);
                *(s32 *)(a1 + 0x1C) = func_0038DBD8(func_003824E0(f21, f24), D_L32_001DEF28, D_L32_001DEF24);
            }
            *(f32 *)(a1 + 0x14) += D_L32_001DEF20;
            *(u128_t *)vC = *(u128_t *)(a0 + 0x10);
            vC[0] += *(f32 *)(a1 + 0x10);
            vC[2] += *(f32 *)(a1 + 0x14);
            if (func_003D3CB0(a0 + 0x10, vC, 1, p, 0) != 0) {
                u8 *g = D_L32_001E9980;
                if (*(s32 *)(g + 0x18) != 0) {
                    f32 z = vC[2];
                    f32 d = *(f32 *)(a1 + 0x10) * 0.74f;
                    vC[0] = *(f32 *)(a0 + 0x10) + d;
                    vC[2] = (*(f32 *)(a0 + 0x14) <= *(f32 *)(g + 0x24)) ? z - d : z + d;
                }
            }
            *(u128_t *)(a0 + 0x10) = *(u128_t *)vC;
            fs = f25 + f26;
            fz = 0.0f;
            *(f32 *)(a0 + 0xC) = func_003C4088(D_L32_001DEF50, f27, func_L03_0034B148(*(s16 *)(a0 + 0xA), *(s16 *)(a1 + 8), fz));
            *(s32 *)(a0 + 4) = func_0038DBD8(func_L03_0034B148(*(s16 *)(a0 + 0xA), *(s16 *)(a1 + 8), fz), *(s32 *)(a1 + 0x18), *(s32 *)(a1 + 0x1C));
            *(s32 *)(a0 + 4) = (*(s32 *)(a0 + 4) & 0xFFFFFF) + ((s32)(func_L03_0034B148(*(s16 *)(a1 + 8) - *(s16 *)(a0 + 0xA), *(s16 *)(a1 + 8), D_L32_001DEF18) * 128.0f) << 24);
            *(u8 *)(a0 + 8) = (s32)func_003C4088(f25, fs, func_L03_0034B148(*(s16 *)(a0 + 0xA), *(s16 *)(a1 + 8), fz));
        }
    }
}
