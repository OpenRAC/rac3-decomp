/* functional: high. Compiles at level_01 (37 diff: only delay-slot/load scheduling). Declared as the context declares it (void *, s32 x5, f32, f32); the rect arg is an f32[4] pointer, ax/ay/shrink are u8 flags (andi 0xFF in retail). */
extern f32 D_L01_001D91A8;
extern f32 D_L01_001D91AC;

extern f32 func_L01_00497C08(s32, f32, f32);
extern f32 func_L01_00497C38(s32, f32, f32, f32);

void func_L01_00497AC8(void *fn, s32 a, s32 rect, s32 ax, s32 ay, s32 shrink, f32 fl1, f32 fl2) {
    f32 *p = (f32 *)rect;
    f32 box[4];
    u8 uax = (u8)ax;
    u8 uay = (u8)ay;
    u8 ushrink = (u8)shrink;

    box[2] = func_L01_00497C08(uax, p[2], fl1);
    box[3] = func_L01_00497C08(uay, p[3], fl2);
    box[0] = func_L01_00497C38(uax, p[0], p[2], box[2]);
    box[1] = func_L01_00497C38(uay, p[1], p[3], box[3]);
    if (ushrink != 0) {
        box[2] = box[2] - D_L01_001D91A8 * 0.001953125f;
        box[3] = box[3] - D_L01_001D91AC / 416.0f;
    }
    ((void (*)(s32, f32 *))fn)(a, box);
}
