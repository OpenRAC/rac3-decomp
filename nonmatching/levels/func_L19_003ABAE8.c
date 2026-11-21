/* func_L19_003ABAE8: 30 diff with the file's flags. Remaining: arg0 and obj swapped between $s0/$s1 (retail arg0 in $s1, obj in $s0), and the nonzero-path branch offset (beqz to 0x90, mine 0x94; one instruction more before the constant path). abs.s comes from __builtin_fabsf; float constants are inline without @ps2as. Tried: obj loaded before the hw check, hw bound as <= 0xFFFE. */
extern void func_0038CAD0(u8 *a0);

void func_L19_003ABAE8(u8 *arg0) {
    u8 *obj;
    u16 hw;
    u16 hw2;
    s32 r;
    s32 ia;
    s32 ib;
    f32 t;
    f32 y;
    f32 z;

    obj = *(u8 **)(arg0 + 0x68);
    hw = *(u16 *)(arg0 + 0x96);
    if (hw <= 0xFFFE) {
        *(u16 *)(arg0 + 0x96) = hw + 1;
    }
    func_0038CAD0(obj + 0x27C);
    if (*(s32 *)(obj + 0x240) != 0) {
        hw2 = *(u16 *)(arg0 + 0x96);
        t = (f32)(s32)((u32)hw2 % 60u) / 40.0f;
        y = __builtin_fabsf(0.75f - t);
        y = y + 0.25f;
        z = y - 0.25f;
        ia = (s32)(y * 127.0f);
        ib = (s32)(z * 32.0f);
        r = ((ib << 16) | ((ib << 8) | 0x7F000000)) | ia;
    } else {
        r = 0x7F000020;
    }
    *(s32 *)(obj + 0x78) = r;
}

INCLUDE_ASM("asm/levels", func_L19_003ABAE8);
