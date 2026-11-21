/* functional: high. compiles; 58 diff lines (sda vs lui addressing: plain externs without .extern size directives); D_001A71A0 is a core global */
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_003D4D00(void *, s32, void *, s32);
extern void func_L01_00447718(void *, void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 D_L01_001EEA80[];
extern s32 D_001A71A0;
extern s32 D_001DE4A4_sda;
extern f32 D_001DE4B8_sda;

s32 func_L01_003AE5B8(u8 *m) {
    u8 *pv = *(u8 **)(m + 0x68);
    f32 pos[4] __attribute__((aligned(16)));
    f32 t;
    s32 n;
    s32 i;

    *(u16 *)(m + 0x34) |= 0x41;
    t = func_003C4088(0.0f, D_001DE4B8_sda, 1.0f - (f32)*(s32 *)(pv + 0x14) / (f32)D_001DE4A4_sda);
    n = func_003D4D00(m + 0x10, 0x10, m, 0);
    vec_copy(pos, m + 0x10);
    func_L01_00447718(*(void **)(m + 0xB8), pos, D_L01_001EEA80, n, 0,
                      *(s32 *)(pv + 0x1C) | 0x1000000, *(s32 *)(pv + 0x18), 1, -1,
                      *(f32 *)(pv + 0x20), 1.0f, 1.0f);
    for (i = 0; i < n; i++) {
        if (D_L01_001EEA80[i] == D_001A71A0) {
            return 1;
        }
    }
    return 0;
}
