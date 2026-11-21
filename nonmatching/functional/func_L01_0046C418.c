/* functional: high. Written from PAL asm; the vadd.xyz keeps w from the global quad as retail does. */
void func_L01_0046C418(u8 *p) {
    if (*(s32 *)(p + 0x30) == 1) {
        f32 *base = (f32 *)&D_001A4C60;
        f32 *add = (f32 *)(p + 0x20);
        f32 *dst = (f32 *)(p + 0x10);
        f32 w = base[3];
        dst[0] = base[0] + add[0];
        dst[1] = base[1] + add[1];
        dst[2] = base[2] + add[2];
        dst[3] = w;
    }
    if (func_0038CB00((s16 *)(p + 0xA))) {
        func_003CD250((Obj *)p);
    }
}
