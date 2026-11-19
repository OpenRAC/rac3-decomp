/* functional: high. 128-bit quad copies as aligned struct copies. */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V_0200;
extern u8 *D_L39_0024B850;
extern u8 D_L39_0024DE80[];
extern u8 *func_L01_003F34E0(s32 a, s32 b);
extern void func_00382E10(void *obj, s32 flag);
extern void func_L01_003F5FC0(void *a, void *b, void *c);

void func_L39_00570200(s32 idx, V_0200 *pa, V_0200 *pb, s32 mode, s32 val, s32 val2) {
    V_0200 sp0, sp10, sp20, sp30;
    u8 *obj, *p, *s17, *s20, *hero;

    obj = func_L01_003F34E0(idx, 5);
    p = *(u8 **)(D_L39_0024B850 + (*(s16 *)(obj + 0x84) << 5) + 0x1C);
    hero = D_L39_0024DE80 + idx * 0x460;
    sp0 = *pa;
    sp10 = *pb;
    sp20 = *(V_0200 *)hero;
    sp30 = *(V_0200 *)(hero + 0x10);
    func_00382E10(obj, mode == 4);
    s17 = *(u8 **)(obj + 0x70);
    *(u8 *)(obj + 0x7D) = 1;
    s20 = s17 + 0xE0;
    *(V_0200 *)(obj + 0x30) = sp0;
    *(V_0200 *)hero = sp0;
    *(V_0200 *)(obj + 0x40) = sp10;
    *(V_0200 *)(s17 + 0x80) = sp0;
    *(V_0200 *)(s17 + 0x90) = sp10;
    *(s32 *)(s20 + 0x40) = val2;
    *(u8 *)(obj + 0x88) = mode;
    *(u8 *)(p + 0x20) = 0;
    if (mode != 2) {
        if (mode != 3) return;
        *(s32 *)(s20 + 0x48) = 0;
        *(f32 *)(s20 + 0x44) = 1.0f;
        *(V_0200 *)(obj + 0x30) = sp20;
        *(V_0200 *)(obj + 0x40) = sp30;
        *(V_0200 *)(s17 + 0x110) = *(V_0200 *)(hero + 0x190);
        func_L01_003F5FC0(s17 + 0xFC, &sp20, hero + 0x190);
    }
    *(s32 *)(s20 + 4) = val;
    *(s32 *)(s17 + 0xE0) = val;
}
