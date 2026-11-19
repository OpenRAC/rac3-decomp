/* functional: high. From PAL near-miss draft; every block, offset (0x30 hp, 0x34 max hp, 0x47, 0x5E/0x60, 0x66C-0x676, 0x67C, 0x190) and call argument (incl. 456C98 and 451FE0 integer/float order) checked vs PAL asm. Relies on D_L07_001D66B0 declared in the file context. 158 diff = scheduling. */
typedef struct { u8 b[16]; } Hit_003B3160;
void func_L07_003B3160(u8 *m) {
    extern s32 func_L01_00447490(void *, s32, s32);
    extern f32 func_L01_004474E8(void *, s32);
    extern void func_003A52A0(s32, s32, void *);
    extern void func_L01_00459BE8(void *, s32, f32);
    extern void func_003C4A40(void *, void *);
    extern s32 func_L07_003A2380(u8, s32, u8, s16);
    extern s32 func_00382468(s32);
    extern void func_L01_0044ABD0(void *, void *);
    extern void func_L01_0044E820(void *, s32);
    extern void func_L01_00459C50(s32);
    extern void func_L01_0043B9E8(void *, s32, s32, s32);
    extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32);
    extern void func_L07_003A2450(void);
    extern void func_L07_003315B0(void *);
    extern void func_L01_00456BD0(void *, s32);
    extern s32 func_L07_00333D20(s32);
    extern void func_L01_00456C98(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    extern void func_L07_003B4DF8(u8 *);
    extern void func_L02_003FB148(s32, s32, f32);
    extern void func_L07_003B46E8(void *);
    extern s32 func_0038CB00(void *);
    u8 *p = *(u8 **)(m + 0x68);
    u8 *hit;
    f32 amount, previous;
    Hit_003B3160 saved;
    if (m[0x20] == 1) return;
    hit = p + 0x70;
    amount = func_L01_004474E8(m, func_L01_00447490(m, -1, 0));
    m[0xA8] = 255;
    if ((*(u16 *)(m + 0x34) & 0x4000) && amount > 0.0f) {
        func_003A52A0(7, 0, m);
        previous = *(f32 *)(p + 0x30);
        *(f32 *)(p + 0x30) = previous - amount;
        func_L01_00459BE8(m, p[0x47], amount);
        p[0x77] = 255;
        if (p[0x47] != 9 && p[0x47] != 25) p[0x676] = 0;
        func_003C4A40(m, hit);
        if (*(f32 *)(p + 0x30) < previous - (f32)*(s16 *)(p + 0x34) * 0.1f && *(s16 *)(p + 0x670) == 0) {
            func_L07_003A2380(20, (s32)m, 0, 100);
            *(s16 *)(p + 0x670) = func_00382468(125) + 250;
        }
    }
    func_L01_0044ABD0(m, hit);
    if (*(s16 *)(p + 0x70) == 0) func_L01_0044E820(m, *(s32 *)(p + 0x67C));
    if (*(f32 *)(p + 0x30) <= 0.0f) {
        if (p[0x676]) func_L01_00459C50(8);
        saved = *(Hit_003B3160 *)(p + 0x70);
        func_L01_0043B9E8(m, saved.b[4], saved.b[5], saved.b[6]);
        func_L01_00451FE0(m, 0x3FFF, D_L07_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 255, 180, 0, 0, 35, 0, 3);
        func_L07_003A2450();
        func_L07_003A2380(81, (s32)m, 0, 100);
        func_L07_003315B0(m);
    } else if (p[0x5E]) {
        func_L07_003315B0(m);
        p[0x5E] = 0;
    } else if (p[0x60]) {
        func_L07_003315B0(m);
        p[0x60] = 0;
    } else {
        s32 animation;
        func_L01_00456BD0(m, 3);
        animation = func_L07_00333D20(*(s32 *)(p + 0x190));
        func_L01_00456C98(m, 0.0f, 0.0f, 1.0f, animation, 0, 0, 0, 0, 1, 0, 0, 0);
        func_L07_003B4DF8(m);
        func_L02_003FB148(6, 0, *(f32 *)(p + 0x30) / (f32)*(s16 *)(p + 0x34));
        func_L07_003B46E8(m);
        func_0038CB00(p + 0x66C);
        func_0038CB00(p + 0x66E);
        func_0038CB00(p + 0x670);
    }
}
