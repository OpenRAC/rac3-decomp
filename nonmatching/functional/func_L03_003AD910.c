/* functional: high. Callee float arg f12=row[0] passed explicitly as 4th f32 arg. f12 for callees loaded from vars+slot row; second roll only when c==0 and vars[0x838]==1. */
/* localdecomp:start func_L03_003AD910 */
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_L03_003B5EF8(u8 *, s32, s32, f32);
extern void func_L03_003B6CB8(u8 *, s32, f32);
s32 func_L03_003AD910(u8 *obj, s32 count, s32 base, s32 extra) {
    u8 *vars = *(u8 **)(obj + 0x68);
    f32 *row = (f32 *)(vars + *(s32 *)(vars + 0x2C) * 32 + 0x1F0);
    s32 mask = 0;
    s32 i = 0;
    while (i < count) {
        s32 slot = func_00382468(8) << 2;
        s32 c, v;
        i++;
        while ((mask >> slot) & 1) {
            if (slot == 0x1C) slot = 0; else slot += 4;
        }
        mask |= 1 << slot;
        v = func_00382498(0, 100);
        if (v < base) c = 1;
        else if (v < base + extra) c = 0;
        else c = 2;
        if ((u32)c < 2) {
            if (c == 0 && *(s32 *)(vars + 0x838) == 1) {
                c = (*(s32 *)(vars + 0x834) < func_00382498(0, 100)) ? 0 : 1;
            }
            func_L03_003B5EF8(obj, slot, c, row[0]);
        } else {
            func_L03_003B6CB8(obj, slot, row[0]);
        }
    }
    return count;
}
/* localdecomp:end func_L03_003AD910 */
