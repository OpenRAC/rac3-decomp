/* func_L19_003B2D00: 19 diff, all in the 30-argument call's stack stores and the following flag clear; same call as func_L19_003B2748 (which matches). */
extern void func_L01_004450F0(u8 *, s32, s32);

s32 func_L19_003B2D00(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    V_3B2748 v;

    func_L19_003B2B28(obj);
    func_L05_00356018(obj);
    *(u16 *)(obj + 0x7C) = 0x701;
    func_003C2F58(obj, 4, (u8 *)&v);
    func_L01_003303B8(&v, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 1.0f, 0.0f, 0.0f, 0.0f,
        0, 0, 0, 0, 0, 0, 0x10000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_003A52A0(0xB, 0, obj);
    *(s32 *)(p + 0xA8) &= ~0x10;
    *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
    *(u16 *)(obj + 0x34) |= 0x1000;
    *(f32 *)(p + 0x30) = (f32)*(s16 *)(p + 0x34) * 0.1f;
    func_L01_004450F0(obj, 0x1E, 5);
    *(s32 *)(p + 0xA8) |= 1;
    obj[0xBF] = 15;
    *(f32 *)(p + 0x70) = 1.5f;
    return 1;
}
