/* func_L39_005C7F38: p2w3 near miss 1 diff (w6), needs --as ps2as (inline float consts). Twin rac2 func_002BCF18.
   Only diff: delay slot of the first bc1f is `lwc1 $f1,0x3b88($gp)` here, retail has nop (that lwc1 sits
   in the delay of the following beqz instead). First compare reads the lui-form name, the later two the gp name. */
typedef int u128_t __attribute__((mode(TI)));
extern f32 D_001E0438_sda;
extern f32 D_L39_0024BB48;
__asm__(".extern D_L39_0024BB48, 16");
extern u8 *D_L39_00296858[];
extern s32 func_L39_005B4398(s32);
extern u8 *func_003CD108(s32);
extern u8 func_0019D510(void);

u8 *func_L39_005C7F38(u8 *a0, u8 *a1, s32 a2, s32 a3, s32 t0, s32 t1, f32 f12)
{
    u8 *p;

    if (t0 == 0)
        return 0;
    if (D_L39_0024BB48 > 0.9f && func_L39_005B4398(3) == 0)
        return 0;
    if (D_001E0438_sda > 0.95f && func_L39_005B4398(2) == 0)
        return 0;
    if (D_001E0438_sda > 1.0f && func_L39_005B4398(1) == 0)
        return 0;
    p = func_003CD108(0x10);
    if (p != 0) {
        u8 *q;
        u8 *tab;

        *(u128_t *)(p + 0x10) = *(u128_t *)a0;
        *(s32 *)(p + 4) = a2;
        p[1] = 0;
        *(f32 *)(p + 0xC) = f12;
        p[9] = 0x44;
        p[3] = 0x44;
        p[8] = func_0019D510();
        q = p + 0x20;
        tab = D_L39_00296858[0];
        p[2] = *((t1 != 3) ? tab + t1 : tab);
        *(s16 *)(p + 0xA) = t0;
        *(s16 *)(q + 0x18) = t0;
        *(f32 *)(q + 0x1C) = f12;
        *(s32 *)(q + 0x10) = a2;
        *(s32 *)(q + 0x14) = a3;
        *(s16 *)(q + 0x1A) = t1;
        *(u128_t *)q = *(u128_t *)a1;
        *(f32 *)(q + 0xC) = *(f32 *)(a0 + 8) - 0.5f;
    }
    return p;
}
