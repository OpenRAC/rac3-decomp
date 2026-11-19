/* functional: high. Same float math (x = r0 + (r2-r3)*0.5 + 1/128), same calls and order as retail; byte diff from literal handling/regalloc */
extern void func_003E9138(s32, s32, f32, f32, f32, f32, s32);
extern void func_003E8FE8(s32, char *, s32, f32, f32, f32, f32);
extern char *func_00381FF0(s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00516B90(s32, s32, s32);
extern s32 func_L01_00518110(s32, s32, s32, s32);

void func_L01_004945B8(s32 a0, f32 *r) {
    f32 x;
    char *s;

    x = r[0] + (r[2] - r[3]) * 0.5f + 0.0078125f;
    func_003E9138(0x1A0015, 0x706EC8FF, x, r[1], r[3] - 0.0234375f, r[3] - 0.012019231f, 0xED26);
    func_003E8FE8(0x1A0016, 0, 0x8066CCFF, x - r[3] * 0.5f, r[1], 1.0f, 1.0f);
    func_L01_00516AA0(0x1A0016, 0x40, 1);
    func_L01_00516B90(0x1A0016, 2, 3);
    s = func_00381FF0(0xCA7);
    func_003E8FE8(0x1A0017, s, 0x8066CCFF, r[0] - r[2] * 0.5f, r[1], 1.0f, 1.0f);
    func_L01_00516AA0(0x1A0017, 0x40, 1);
    func_L01_00516B90(0x1A0017, 1, 3);
    func_L01_00518110(a0, 0x1A0015, 0x1A0016, 0x1A0017);
}
