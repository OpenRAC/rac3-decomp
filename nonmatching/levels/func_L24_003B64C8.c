/* func_L24_003B64C8: level 24 near miss. 81 differences after a statement-order hill climb from 94: the whole setup is a long interleaved store run (constants preloaded into $f0-$f5, then stores scheduled around func_L24_0041FCB0 and func_L24_0043B968); also needs func_L24_003B64C8's earlier K&R declaration in L24_003B6050.c, which is not committed */
typedef int vu0_q __attribute__((mode(TI)));

__asm__(".extern D_L24_001DE800, 4");
extern f32 D_L24_001DE800;
extern s32 D_L24_001DD584;
extern f32 D_L24_001DD580;
extern f32 D_L24_001DD57C;
extern u8 *func_L24_0041FCB0(s32, s32);
extern void func_L24_0043B968(void *, void *);
extern void func_L24_004411A8(f32, f32, f32, f32);
extern void func_L24_0042BAC0(void *, s32, s32);

s32 func_L24_003B64C8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *e;
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
    e = func_L24_0041FCB0(0x1B5C, 0x80);
    *(u8 **)(p + 0x8DC) = e;
    func_L24_0043B968(e, a0);
    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * D_L24_001DE800;
    *(s32 *)(p + 0x8F0) = 0x4096006B;
    *(s32 *)(p + 0x8F4) = 0x450030;
    *(f32 *)(p + 0x8E8) = 2.0f;
    *(f32 *)(p + 0x8E4) = 2.0f;
    e = *(u8 **)(p + 0x8DC);
    *(f32 *)(e + 0x2C) = *(f32 *)(*(u8 **)(e + 0x24) + 0x24) * 0.300000012f * D_L24_001DE800;
    *(u16 *)(a0 + 0x34) &= 0xFFBE;
    *(u16 *)(a0 + 0x34) |= *(u16 *)(*(u8 **)(a0 + 0x24) + 0x44) & 0x1000;
    *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
    e = *(u8 **)(p + 0x8DC);
    *(u16 *)(e + 0x34) &= 0xFFBE;
    e = *(u8 **)(p + 0x8DC);
    *(u16 *)(e + 0x34) |= *(u16 *)(*(u8 **)(e + 0x24) + 0x44) & 0x1000;
    e = *(u8 **)(p + 0x8DC);
    *(s32 *)(e + 0x98) = *(s32 *)(*(u8 **)(e + 0x24) + 0x10);
    *(s32 *)(p + 0x90C) = D_L24_001DD584;
    *(f32 *)(p + 0x930) = D_L24_001DD580;
    func_L24_004411A8(D_L24_001DD57C, D_L24_001DD57C, 0.50265485f, 0.50265485f);
    *(vu0_q *)(p + 0x940) = *(vu0_q *)(a0 + 0x10);
    func_L24_0042BAC0(a0, 1, -1);
    return 0;
}
