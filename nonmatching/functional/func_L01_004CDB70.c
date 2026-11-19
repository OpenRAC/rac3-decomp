/* functional: high. No draft; written from asm. 43 diff words (scheduling of the global load / branch order only); gp-unsized D_ name per lui/lw in asm */
extern s32 D_L01_001D55E8[];
extern void func_0038E150(s32);
extern s32 func_L01_00412708(u8 *, s32);
extern s32 func_L01_00412750(u8 *, s32);

void func_L01_004CDB70(u8 *obj, s32 mode, s32 w, f32 x, f32 y) {
    u8 *buf = obj + 0x88;
    s32 saved;

    **(f32 **)(obj + 0x0) = x;
    *(f32 *)(*(u8 **)(obj + 0x0) + 4) = y;
    obj[0x187] = 0;
    *(u8 **)(obj + 0x1B8) = buf;
    saved = D_L01_001D55E8[0];
    *(s32 *)(obj + 0x1A4) = mode;
    *(s32 *)(obj + 0x198) = w;
    func_0038E150(1);
    if (*(s32 *)(obj + 0x1A4) == 1) {
        *(s32 *)(obj + 0x1B4) = func_L01_00412708(buf, -1);
    } else if (*(s32 *)(obj + 0x1A4) == 0) {
        *(s32 *)(obj + 0x1B4) = func_L01_00412750(buf, -1);
    }
    func_0038E150(saved);
    *(s32 *)(obj + 0x190) = 1;
    **(f32 **)(obj + 0x4) = 1.0f;
}
