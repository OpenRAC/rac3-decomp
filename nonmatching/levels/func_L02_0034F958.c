/* Level 02 (Florana), PAL. 34 diff with check.py --target level_02. 34 differing lines in two parts: (a) the float constants sit in `$f1..$f7` in a different order and the byte stores at 0x1d7/0x171/0x172 do not interleave as in retail (moving them re-merges the constant 1 and gets worse); (b) the tail keeps `id` in `$a1` and loads `D_001D545C` into `$a0` in retail. Needs `@ps2as` for L02_0034C9F0.c. */
typedef int u128_t __attribute__((mode(TI)));
extern void func_L01_00456160(s32, void *);
extern void func_L01_0044FD88(void *, s32, s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L02_0034FE10(void *);
extern s32 func_003C24B0(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
typedef struct { u8 pad[0x464]; u8 spent[1]; } S_34F958;
extern S_34F958 D_00234840;
__asm__(".extern D_00234840, 16");
extern u8 D_001BBE90[];
__asm__(".extern D_001BBE90, 16");
extern s32 D_001D545C[];
__asm__(".extern D_001D545C, 16");

s32 func_L02_0034F958(void *self)
{
    u8 *a0 = self;
    u8 *p;
    s32 v;
    s32 r;
    s32 id;
    s32 one;

    p = *(u8 **)(a0 + 0x68);
    *(u128_t *)(p + 0x300) = *(u128_t *)(a0 + 0x10);
    *(s32 *)(p + 0x920) = 0;
    a0[0x30] = 0xFF;
    if (*(s32 *)(p + 0x938) != 0) {
        func_L01_00456160(*(s32 *)(p + 0x938), a0);
        *(u16 *)(*(u8 **)(p + 0x938) + 0x32) = *(u16 *)(a0 + 0x32);
    }
    p[0x1DB] = 0xFF;
    p[0x1A8] = 3;
    p[0x176] = 0;
    p[0x1D8] = 0;
    p[0x1D9] = 0;
    p[0x1DA] = 0;
    p[0x1D7] = 1;
    p[0x171] = 1;
    p[0x172] = 1;
    one = 1;
    *(s32 *)(p + 0x218) = one;
    *(s32 *)(p + 0x74) = 0;
    p[0x170] = 0x17;
    *(f32 *)(p + 0x19C) = 0.15f;
    *(f32 *)(p + 0x1B8) = 0.01f;
    *(s32 *)(p + 0x1DC) = *(s32 *)(p + 0x924);
    *(f32 *)(p + 0x70) = 1.5f;
    *(f32 *)(p + 0x78) = 0.5f;
    *(f32 *)(p + 0x7C) = 1.0f;
    *(f32 *)(p + 0x80) = 1.4835298f;
    *(f32 *)(p + 0xA0) = 0.34906584f;
    *(f32 *)(p + 0x9C) = 0.00392f;
    *(f32 *)(p + 0x190) = 0.5f;
    *(f32 *)(p + 0x194) = 0.5f;
    func_L01_0045BD78(a0, 0.0032000002f, 0.060000002f, 0.010053097f, 0.25132743f);
    *(s32 *)(p + 0xAC) = *(s32 *)(p + 0x924);
    func_L02_0034FE10(a0);
    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    if (*(s16 *)(p + 0x34) == 0) {
        *(s16 *)(p + 0x34) = 100;
        *(f32 *)(p + 0x30) = 100.0f;
    }
    p[0x39] = one;
    p[0x3E] = 3;
    p[0x3F] = 0;
    *(f32 *)(p + 0x40) = 2.0f;
    *(s32 *)(p + 0x2EC) = func_003C24B0(0x1743, 0x80);
    func_L01_00456160(*(s32 *)(p + 0x2EC), a0);
    *(u8 **)(*(u8 **)(p + 0x2EC) + 0xB8) = a0;
    func_L01_0044FD88(a0, *(s32 *)(p + 0x2EC), 0, 0);
    func_L01_004450F0(a0, 3, 0);
    if (a0[0x43] != 0xC) func_003C3A10(a0, 0xC, 0, 0);
    if (*(s32 *)(p + 0x2C0) != -1) {
        func_L01_004450F0(a0, 0x16, 7);
        *(s32 *)(a0 + 0x98) = 0;
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(a0, 1);
    }
    id = *(u16 *)(a0 + 0xB2);
    if (D_00234840.spent[(s16)id] == 0) {
        v = D_001BBE90[(D_001D545C[0] << 10) + ((s16)id >> 1)];
        if (id & 1) {
            if (((v >> 4) & 7) == 0) return 0;
        } else {
            if ((v & 7) == 0) return 0;
        }
    }
    return 1;
}
