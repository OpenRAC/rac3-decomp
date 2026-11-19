/* functional: high. All 48 call args cross-checked against asm; diffs scheduling only. */
extern u8 D_001A30B0[];
extern u8 D_L32_001D66B0[8];
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(u8 *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32,
                              s32);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);

/* Vid-comic 4 object death: frees its sound slot, plays the death sound and spawns a burst of
 * particles plus a flash sized by the object's scale, then deletes the object. */
void func_L32_0034DB98(u8 *obj) {
    u8 *v = *(u8 **)(obj + 0x68);
    s32 h = *(s32 *)(v + 0x10);
    u8 *slot;
    f32 f1, f15;
    s32 state;

    if (h != -1) {
        slot = D_001A30B0 + h * 128;
        if (*(u8 **)(slot + 0xDC) == obj && slot[0xD0] != 0) {
            func_003A4F28(h);
        }
    }
    *(s32 *)(v + 0x10) = -1;
    func_003A52A0(1, 0, obj);
    func_L01_00451FE0(obj, 0x1F, D_L32_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23,
                      1.0f, 1.0f, 0, 3);
    f1 = *(f32 *)(obj + 0x2C) / *(f32 *)(*(u8 **)(obj + 0x24) + 0x24);
    state = obj[0x20];
    f15 = f1 + f1;
    if (state == 2) {
        f15 = f1 * 1.1f;
    } else if (*(s32 *)v == 0) {
        f15 = f1;
    }
    func_L01_003303B8(obj + 0x10, state != 2, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, f1 * 0.57f, 0.0f, 20.0f, f15,
                      1, 1, 0, 0, 0, 1, 0x30001, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                      0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_003C2880(obj);
}
