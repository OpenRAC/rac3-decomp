/* functional: high. Rewritten in plain C from PAL asm (draft used inline asm and NTSC names). VU0 vsub/vadd.xyz written as per-component float ops, w of the diff vector copied from the target w as retail's lqc2/sqc2 do. fabs written via __builtin_fabsf (abs.s). 145 diff lines are scheduling/frame only. */
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038DB00(f32, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_0040E4C0(void *);
extern void func_L07_003AF240(u8 *);
extern void func_L01_00448890(void *, void *, f32, f32, f32, f32, long);
extern void func_L07_003AF010(u8 *, void *, void *);
extern void func_L01_003B2DC8();
extern f32 D_L07_001D9AE0[];

void func_L07_003AED80(u8 *obj) {
    f32 diff[4], step[4];
    u8 *state = *(u8 **)(obj + 0x68);
    u8 *target = *(u8 **)(state + 0x240);
    f32 *op = (f32 *)(obj + 0x10);
    f32 *tp = (f32 *)(target + 0x10);
    f32 angle, length, turn, sq, h;

    diff[0] = tp[0] - op[0];
    diff[1] = tp[1] - op[1];
    diff[2] = tp[2] - op[2];
    diff[3] = tp[3];
    angle = func_0038D160(diff[0], diff[1]);
    length = func_0038CEA8(diff);
    turn = func_0038DB00(angle, *(f32 *)(state + 0x260));
    if (turn > 0.0f) {
        func_0038CE90(step, diff, D_L07_001D9AE0);
    } else {
        func_0038CE90(step, D_L07_001D9AE0, diff);
    }
    step[2] = 0.0f;
    func_0038CF68(step, step, __builtin_fabsf(length * turn));
    func_0038CF68(diff, diff, length - *(f32 *)(state + 0x264));
    h = *(f32 *)(obj + 0x18);
    step[0] = step[0] + diff[0];
    step[1] = step[1] + diff[1];
    step[2] = step[2] + diff[2];
    step[2] = *(f32 *)(state + 0x268) - (h - *(f32 *)(*(u8 **)(state + 0x240) + 0x18));
    sq = func_L01_0040E4C0(step);
    if (sq > 25.0f) {
        func_0038CF68(step, step, 5.0f);
    } else if (sq < 0.25f) {
        func_L07_003AF240(obj);
    }
    step[0] = op[0] + step[0];
    step[1] = op[1] + step[1];
    step[2] = op[2] + step[2];
    func_L01_00448890(obj + 0xF8, state + 0xE4, angle, *(f32 *)(state + 0x44), *(f32 *)(state + 0x48), *(f32 *)(state + 0x4C), 0);
    func_L07_003AF010(obj, step, func_L01_003B2DC8);
}
