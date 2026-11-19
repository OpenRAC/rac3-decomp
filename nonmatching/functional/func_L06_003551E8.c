/* functional: high. check.py at level_06: 33 instruction diffs (scheduling/register choice). Callee func_L01_00477F20 is (table, count, f32, f32, f32): retail leaves the table pointer in a0, passed explicitly here. */
extern f32 func_L01_00477F20(u8 *, s32, f32, f32, f32);
extern s32 func_L06_00351390(u8 *, u8 *);
s32 func_L06_003551E8(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 n;
    f32 f;
    u8 *tbl;

    if (*(s32 *)(v + 0x350) == 0 && func_L06_00351390(m, v)) {
        func_L01_004450F0(m, 1, 1);
        return 1;
    }
    if (m[0x20] == 0xF) {
        func_L01_004450F0(m, 0x10, -1);
        return 1;
    }
    if (m[0x20] != 1 && (u8)(m[0x20] - 4) >= 0xB) {
        return 0;
    }
    n = *(s32 *)(v + 0x344);
    tbl = *(u8 **)(v + 0x358);
    f = func_L01_00477F20(tbl, *(s32 *)(v + 0x27C), 0.0f,
                          (f32)n + *(f32 *)(v + 0x348) / *(f32 *)(tbl + n * 16 + 0x1C), 20.0f);
    *(f32 *)(v + 0x34C) = f * (f32)*(s32 *)(v + 0x27C);
    if ((u8)(m[0x20] - 4) < 0xB) {
        return 0;
    }
    func_L01_004450F0(m, 3, -1);
    return 1;
}
