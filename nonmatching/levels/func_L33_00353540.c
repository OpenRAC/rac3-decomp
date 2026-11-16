/* func_L33_00353540: 160 diff with --as ps2as (NEEDS-FLAGS: default assembler gives $gp loads for 0x40C90FDB), but the instruction stream is the same as retail except two register names: retail keeps (f32)(h&0xFF) in $f25 and the lerp result g in $f26, mine swaps them, which also shifts epilogue scheduling (beql vs beqz). Tried: variable order, hw local, u16/u32/s32 hw, one=1.0f local (fixes the hoisted constant). VU0 block is plain asm lqc2/vadd.xyz/sqc2. */
INCLUDE_ASM("asm/levels", func_L33_00353540);

#if 0
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_L03_0034B148(f32, s32, s32);
extern f32 D_L33_001DDBF4;
__asm__(".extern D_L33_001DDBF4, 4");
extern f32 D_L33_001DDBF8;
__asm__(".extern D_L33_001DDBF8, 4");
extern f32 D_L33_001DDBFC;
__asm__(".extern D_L33_001DDBFC, 4");
extern f32 D_L33_001DDC00;
__asm__(".extern D_L33_001DDC00, 4");
extern f32 D_L33_001DDC08;
__asm__(".extern D_L33_001DDC08, 4");
extern f32 D_L33_001DDC10;
__asm__(".extern D_L33_001DDC10, 4");
extern f32 D_L33_001DDBE4;
__asm__(".extern D_L33_001DDBE4, 4");
extern f32 D_L33_001DDBD0;
__asm__(".extern D_L33_001DDBD0, 4");
extern s32 D_L33_001DDBE0;
__asm__(".extern D_L33_001DDBE0, 4");
extern s32 D_L33_001DDBDC;
__asm__(".extern D_L33_001DDBDC, 4");
extern s32 D_L33_001DDBD8;
__asm__(".extern D_L33_001DDBD8, 4");
extern s32 D_L33_001DDBD4;
__asm__(".extern D_L33_001DDBD4, 4");

void func_L33_00353540(u8 *a, u8 *b) {
    u8 *c;
    u16 hw;
    f32 one, k, e, g, h, r, x, ang, rad;
    f32 t[4] __attribute__((aligned(16)));

    if (b == 0) {
        return;
    }
    c = *(u8 **)b;
    if (c != 0 && *(s32 *)(b + 4) != 0) {
        hw = *(u16 *)(b + 0xE);
        k = D_L33_001DDBF4 * (f32)*(s16 *)(b + 8) * (f32)(hw >> 8) * 0.00390625f;
        e = (f32)(hw & 0xFF);
        g = func_003C4088(D_L33_001DDBFC, D_L33_001DDBF8, (f32)*(u8 *)(b + 0xC) * 0.00390625f);
        if (*(u16 *)(b + 0xA) & 1) {
            one = 1.0f;
            ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
            rad = func_003824E0(0.0f, *(f32 *)(c + 0xC) * 0.00048828125f);
            t[0] = func_0038D098(ang) * rad;
            t[2] = func_0038D0B0(ang) * rad;
            t[1] = 0.0f;
            __asm__ __volatile__(
                "lqc2 $vf2, 0(%0)\n"
                "lqc2 $vf1, 0x10(%1)\n"
                "vadd.xyz $vf1, $vf1, $vf2\n"
                "sqc2 $vf1, 0x10(%2)\n"
                : : "r"(t), "r"(c), "r"(a) : "memory");
            *(f32 *)(a + 0x14) += func_003824E0(-D_L33_001DDC10, D_L33_001DDC10);
            *(f32 *)(b + 0x14) = func_003824E0(0.0f, D_L33_001DDC08);
            *(s32 *)(b + 0x18) = func_0038DBD8(D_L33_001DDBE0, D_L33_001DDBDC, func_003824E0(0.0f, one));
            *(s32 *)(b + 0x1C) = func_0038DBD8(D_L33_001DDBD8, D_L33_001DDBD4, func_003824E0(0.0f, one));
        }
        *(f32 *)(b + 0x14) += D_L33_001DDBE4;
        h = e + k;
        *(f32 *)(a + 0x18) += *(f32 *)(b + 0x14);
        x = func_L03_0034B148(0.0f, *(s16 *)(a + 0xA), *(s16 *)(b + 8));
        *(f32 *)(a + 0xC) = func_003C4088(D_L33_001DDC00, g, x);
        x = func_L03_0034B148(0.0f, *(s16 *)(a + 0xA), *(s16 *)(b + 8));
        *(s32 *)(a + 4) = func_0038DBD8(*(s32 *)(b + 0x18), *(s32 *)(b + 0x1C), x);
        x = func_L03_0034B148(D_L33_001DDBD0, *(s16 *)(b + 8) - *(s16 *)(a + 0xA), *(s16 *)(b + 8));
        *(s32 *)(a + 4) = (*(s32 *)(a + 4) & 0xFFFFFF) + ((s32)(x * 128.0f) << 24);
        x = func_L03_0034B148(0.0f, *(s16 *)(a + 0xA), *(s16 *)(b + 8));
        *(s8 *)(a + 8) = (s32)func_003C4088(e, h, x);
    }
}
#endif
