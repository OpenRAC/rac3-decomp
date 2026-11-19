/* functional: high. Compiles at level_01 (130 diff, scheduling/regalloc; frame size 0x460 matches retail). Retail's dead load of D_001E11A0 omitted. Text struct 'box' is a 32-byte u16 array filled by func_003910C0 (x,y,w,h at halfword 4..7, flag halfword 9, halfwords 12/13 preset to 2). */
extern s32 D_001D4BC8;
extern f32 D_L01_001E11A4;
extern char D_L01_001D91A0[];
extern void func_0038AE20(s32, s32, s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern void func_003910C0(u16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_0038FA18(u16 *, long, char *, s32, unsigned long, f32, f32);
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern void func_L01_00436020(s32, s32, f32, f32, f32, f32);

void func_L01_004968C0(s32 msg) {
    char text[0x400];
    u16 box[16];
    s32 s1;
    s32 s2;
    s32 x;
    s32 y;
    s32 base;
    s32 halfw;
    s32 halfh;

    func_0038AE20(0, 0, 0, 0x60);
    s1 = func_00381FF0(msg);
    s2 = func_00381FF0(0xCD5);
    func_0011B2E8(text, D_L01_001D91A0, s1, s2);
    box[13] = 2;
    box[12] = 2;
    x = (s32)(D_L01_001E11A4 * 256.0f + 0.5f + 0.0f);
    y = (s32)(D_L01_001E11A4 * 384.0f + 0.5f + 0.0f);
    base = D_001D4BC8;
    func_003910C0(box, x, y, base - 0x90, base + 0x90, base, 0x140, 0x10, 0x27);
    func_0038FA18(box, 0x8066CCFFL, text, -1, 0x80000000UL, 1.0f, 1.0f);
    halfw = ((s16)box[6] >> 1) + 8;
    halfh = ((s16)box[7] >> 1) + 8;
    func_0038C3B0((s16)box[5] - halfh, (s16)box[5] + halfh, (s16)box[4] - halfw, (s16)box[4] + halfw, 0x33, 0x331465B7);
    func_L01_00436020(0x33, 0x332299DE, (f32)((s16)box[5] - halfh), (f32)((s16)box[5] + halfh),
                      (f32)((s16)box[4] - halfw), (f32)((s16)box[4] + halfw));
    box[9] &= 0xFFFB;
    func_0038FA18(box, 0x8066CCFFL, text, -1, 0x80000000UL, 1.0f, 1.0f);
}
