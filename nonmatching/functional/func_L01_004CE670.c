/* functional: high. No usable draft (file held a sibling function with other callee/constants); written from asm; 39ish diff words scheduling only */
extern s32 func_00381FF0(s32);
extern void func_0011B2E8(void *, s32, s32);
extern void func_L01_004CDB70(void *, s32, s32, f32, f32);

void func_L01_004CE670(u8 *o, s32 i, s32 a, s32 b, s32 c) {
    s32 v = 0x64;
    s32 r;
    u8 *e;

    if (c != -1) {
        v = c;
    }
    e = o + i * 0x230 + 0x4698;
    r = func_00381FF0(a);
    func_0011B2E8(e, r, b);
    func_L01_004CDB70(o + (i * 0x230 + 0x4610), 1, v, 255.0f, 135.0f);
}
