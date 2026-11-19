/* functional: high. Based on PAL near-miss/NTSC twin structure, rechecked against PAL asm (1.2 for the stagger vector scale, constants/branches). Compiles; 245 diff lines are float literal loads, gp vs lui for D_L07_001D66B0 and code layout, not behaviour. 0x3EB2B8C2 clamp is 0.3490658. */
extern u8 D_L07_001D66B0[8];
extern u8 D_L07_001E1EC0[];
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L07_003333F8(s32, f32, f32);
extern void func_L01_00451FE0(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L07_003315B0(void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L07_003AEAA0(void *, s32);
extern void func_L01_004AAC98(s32, s32, void *, s32);
extern void func_L07_00331158(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);

void func_L07_003AE618(u8 *obj) {
    u8 *p;
    u8 *t;
    f32 f;
    f32 g;
    f32 yaw;

    p = *(u8 **)(obj + 0x68);
    if (obj[0x20] == 1 || obj[0x20] == 0xE) {
        return;
    }
    f = *(f32 *)(p + 0x120);
    t = func_L01_00447490(obj, 0x10000, 0);
    if (func_L01_00452FB0(obj, p + 0x160, 0, 0, 0) != 0) {
        func_L07_003333F8(*(s32 *)(p + 0x240), f, *(f32 *)(p + 0x120));
    }
    if (*(s32 *)(p + 0x108) == 1) {
        func_L01_00451FE0(obj, 0x1F, D_L07_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_003303B8(obj + 0x10, 0, 5, 10, 10, 3, 20, 0, 0.3f, 0.0f, 0.0f, 2.0f, 0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L07_003315B0(obj);
    } else {
        if (*(f32 *)(p + 0x120) <= 0.0f) {
            if (t != 0 && 0.0f < func_0038CE68(t + 0x10, t + 0x10)) {
                g = -func_0038D160(func_0038CED8(t + 0x10), *(f32 *)(t + 0x18));
                if (0.34906587f < g) {
                    g = 0.34906587f;
                } else if (g < 0.0f) {
                    g = 0.0f;
                }
                yaw = func_0038D160(*(f32 *)(t + 0x10), *(f32 *)(t + 0x14));
                func_00382760(p + 0xD0, 1.2f, yaw, g);
                func_L07_003AEAA0(obj, 0xE);
                return;
            }
            func_L01_003303B8(obj + 0x10, 0, 5, 10, 10, 3, 20, 0, 0.3f, 0.0f, 0.0f, 2.0f, 0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_004AAC98(2, 0, obj, 0x19D2);
            func_L07_003315B0(obj);
            return;
        }
        if (p[0x14E] != 0 || p[0x150] != 0 || p[0x12E] == 2) {
            func_L07_003315B0(obj);
            return;
        }
    }
    func_L07_00331158(obj);
    if ((u8)(obj[0x20] - 8) < 3) {
        if (*(f32 *)(*(u8 **)(p + 0x240) + 0x18) + 0.5f < *(f32 *)(obj + 0x18)) {
            *(f32 *)(p + 0x280) = *(f32 *)(p + 0x280) + 0.00392f;
            *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) - *(f32 *)(p + 0x280);
            if (*(f32 *)(obj + 0x18) < *(f32 *)(*(u8 **)(p + 0x240) + 0x18) + 0.5f) {
                *(f32 *)(obj + 0x18) = *(f32 *)(*(u8 **)(p + 0x240) + 0x18) + 0.5f;
            }
        } else {
            *(s32 *)(p + 0x280) = 0;
        }
    } else {
        *(s32 *)(p + 0x280) = 0;
    }
    if (obj[0x31] != 0) {
        if (func_L01_0040E548(D_L07_001E1EC0, obj + 0x10) < 576.0f) {
            func_L01_004472C0(obj);
            obj[0x6F] = 0x16;
        }
    }
}
