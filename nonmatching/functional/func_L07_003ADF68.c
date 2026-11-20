/* functional: high. Checked against level_07 context; compiles, near-identical to retail (diff only in frame size/small-data gp use for D_L07_001D66B0). Vector add and 16-byte copy written as plain float ops (xyz add keeps w). Constants verified from PAL asm: 42.0 divisor in state 9 (NTSC draft had 50.0). */
extern u8 D_L07_001D66B0[];

extern void func_L07_003AE410(u8 *);
extern void func_L07_003AE618(u8 *);
extern s32 func_0038CB00(u8 *);
extern void func_L07_003AEAA0(u8 *, s32);
extern void func_L07_003AF010(u8 *, void *, void *);
extern void func_L01_003B2DC8();
extern void func_L07_003AEF78(u8 *, void *);
extern void func_L07_003AF0B0(u8 *, void *, f32);
extern void func_L07_003AF2B8(u8 *, s32, f32);
extern s32 func_L07_003AED20(u8 *);
extern void func_L07_003AED80(u8 *);
extern s32 func_L07_00331008(u8 *, u8 *);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L03_0032FAF0(void *, void *, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451FE0(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);
extern void func_L07_003315B0(u8 *);
extern s32 func_003A52A0(s32, s32, void *);

void func_L07_003ADF68(u8 *obj) {
    u8 *s;
    f32 tmp[4];

    if (obj[0x20] == 0) {
        func_L07_003AE410(obj);
    }
    func_L07_003AE618(obj);
    s = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 1:
        break;
    case 2:
        if (func_0038CB00(s + 0x24E) != 0) {
            func_L07_003AEAA0(obj, 3);
        }
        break;
    case 3:
        func_L07_003AEAA0(obj, 4);
        /* fall through */
    case 4:
        func_L07_003AF010(obj, s + 0x260, func_L01_003B2DC8);
        if (func_L01_0040E570(obj + 0x10, *(u8 **)(s + 0x240) + 0x10) < 484.0f) {
            s[0x25E] = 1;
            func_L07_003AEAA0(obj, 6);
        }
        break;
    case 6:
        func_L07_003AED80(obj);
        if (func_L07_00331008(*(u8 **)(s + 0x240), obj) != 0) {
            func_L07_003AEAA0(obj, 7);
        }
        break;
    case 7:
        if (func_L07_003AED20(obj) != 0) {
            func_L03_0032FAF0(tmp, s + 0x220, *(f32 *)(s + 0x254), 2.5f);
            func_L07_003AF010(obj, tmp, func_L07_003AEF78);
            if (func_L01_0040E570(obj + 0x10, s + 0x220) < 9.0f) {
                func_L07_003AEAA0(obj, 8);
            }
        }
        break;
    case 8:
        func_L07_003AF010(obj, obj + 0x10, func_L01_003B2DC8);
        if (func_L07_003AED20(obj) != 0) {
            if (obj[0x60] & 2) {
                func_L07_003AEAA0(obj, 9);
            }
        }
        break;
    case 9:
        func_L07_003AF010(obj, obj + 0x10, func_L01_003B2DC8);
        *(f32 *)(obj + 0x48) = 1.0f - (f32) * (s16 *)(s + 0x284) / 42.0f;
        if (func_L07_003AED20(obj) != 0) {
            if (func_0038CB00(s + 0x284) != 0) {
                func_L07_003AEAA0(obj, 10);
            }
        }
        break;
    case 10:
        if (func_L07_003AED20(obj) != 0) {
            func_L07_003AEF78(obj, s + 0x220);
            func_L07_003AF0B0(obj, D_L07_001D66B0, 0.0f);
            func_L07_003AF2B8(obj, 0, 0.0f);
            if (func_L01_0040E570(obj + 0x10, s + 0x220) > 225.0f) {
                func_L07_003AEAA0(obj, 7);
            }
        }
        break;
    case 14:
        *(f32 *)(obj + 0xF8) = func_0038DAB8(*(f32 *)(obj + 0xF8), 0.5026548504829407f);
        {
            f32 *p = (f32 *)(obj + 0x10);
            f32 *q = (f32 *)(s + 0xD0);
            p[0] = p[0] + q[0];
            p[1] = p[1] + q[1];
            p[2] = p[2] + q[2];
            tmp[0] = p[0]; tmp[1] = p[1]; tmp[2] = p[2]; tmp[3] = p[3];
        }
        tmp[2] = tmp[2] + 0.8f;
        if (func_0038CB00(s + 0x284) != 0 || func_L01_003FB640(tmp, 0, obj, 0.9f) != 0) {
            func_L01_003303B8(obj + 0x10, 0, 5, 0xA, 0xA, 3, 0x14, 0, 0.3f, 0.0f, (f32)s[0x135], 1.0f,
                              0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                              0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_00451FE0(obj, 0x1F, D_L07_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23,
                              1.0f, 1.0f, 0, 3);
            func_L07_003315B0(obj);
            func_003A52A0(2, 0, obj);
        }
        break;
    }
}
