/* func_L24_003B64C8: level 24 near miss, 9 differences (see nonmatching/README.md). Its place is L24_003B6050.c (-mvu0-use-vf0-vf2, @ps2as); func_L24_003B6320's block there declares it extern s32 func_L24_003B64C8(void), which must become the K&R extern s32 func_L24_003B64C8(); for this definition (func_L24_003B6320 still matches with that). */

__asm__(".extern D_L24_001DE800, 4");
extern f32 D_L24_001DE800;
extern s32 D_L24_001DD584;
__asm__(".extern D_L24_001DD584, 16");
extern f32 D_L24_001DD580;
__asm__(".extern D_L24_001DD580, 16");
extern f32 D_L24_001DD57C;
__asm__(".extern D_L24_001DD57C, 16");
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(void *, void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);

s32 func_L24_003B64C8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *e;
    s32 v584;
    f32 v580;
    f32 k;
    *(f32 *)(p + 0x70) = 0.5f;
    *(f32 *)(p + 0x74) = 0.1f;
    *(f32 *)(p + 0x78) = 0.5f;
    *(f32 *)(p + 0x7C) = 1.0f;
    *(f32 *)(p + 0x80) = 0.785398185f;
    *(f32 *)(p + 0xA0) = 0.34906584f;
    *(f32 *)(p + 0x9C) = 0.00392000005f;
    if (*(s16 *)(p + 0x34) == 0) {
        *(s16 *)(p + 0x34) = 100;
        *(f32 *)(p + 0x30) = 100.0f;
    }
    p[0x39] = 1;
    *(f32 *)(p + 0x40) = 2.0f;
    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    *(u8 **)(p + 0x8DC) = func_003C24B0(0x1B5C, 0x80);
    func_L01_00456160(*(u8 **)(p + 0x8DC), a0);
    k = D_L24_001DE800;
    v584 = D_L24_001DD584;
    v580 = D_L24_001DD580;
    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * k;
    *(s32 *)(p + 0x8F0) = 0x4096006B;
    *(s32 *)(p + 0x8F4) = 0x450030;
    *(f32 *)(p + 0x8E4) = 2.0f;
    *(f32 *)(p + 0x8E8) = 2.0f;
    {
        u8 *e0 = *(u8 **)(p + 0x8DC);
        *(f32 *)(e0 + 0x2C) = *(f32 *)(*(u8 **)(e0 + 0x24) + 0x24) * 0.300000012f * k;
    }
    *(u16 *)(a0 + 0x34) &= 0xFFBE;
    *(u16 *)(a0 + 0x34) |= *(u16 *)(*(u8 **)(a0 + 0x24) + 0x44) & 0x1000;
    *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
    {
        u8 *e1 = *(u8 **)(p + 0x8DC);
        *(u16 *)(e1 + 0x34) &= 0xFFBE;
    }
    {
        u8 *e2 = *(u8 **)(p + 0x8DC);
        *(u16 *)(e2 + 0x34) |= *(u16 *)(*(u8 **)(e2 + 0x24) + 0x44) & 0x1000;
    }
    {
        u8 *e3 = *(u8 **)(p + 0x8DC);
        *(s32 *)(e3 + 0x98) = *(s32 *)(*(u8 **)(e3 + 0x24) + 0x10);
    }
    *(s32 *)(p + 0x90C) = v584;
    *(f32 *)(p + 0x930) = v580;
    func_L01_0045BD78(a0, D_L24_001DD57C, D_L24_001DD57C, 0.50265485f, 0.50265485f);
    *(vu0_q *)(p + 0x940) = *(vu0_q *)(a0 + 0x10);
    func_L01_004450F0(a0, 1, -1);
    return 0;
}
