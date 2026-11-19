/* functional: medium. Same reads, writes, calls and call order; only stack frame/register allocation differ. Callees are frontbin text/draw helpers (func_00381FF0 text lookup, 0038FA18 draw text, 0038C3B0 fill rect, 003910C0 box init); box fields named from offsets only. */
typedef struct {
    u8 p0[8];
    s16 x;
    s16 y;
    u16 w;
    u16 h;
    u8 p0C[2];
    u16 flags;
    u8 p14[6];
    s16 f18;
    s16 f1A;
    u8 p1C[0x14];
} TextBox_003B42E8;

extern char D_L01_001DE6C0[];
extern char D_L01_001DE6D8[];
extern char D_L01_001DE6F0[];
extern char D_L01_001DE708[];
extern char D_L01_001DE718[];
extern char D_L01_002A2970[];
extern u8 D_L01_002C5600[];
extern f32 D_L01_001E11A4;
extern s32 D_001D4BC8[];
extern s32 D_001D64E8[];

extern char *func_00381FF0(s32);
extern void func_11B2E8(char *, char *, ...);
extern void func_003910C0(void *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0038FA18(void *, u32, char *, s32, u32, f32, f32);
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern void func_L01_00436020(s32, u32, f32, f32, f32, f32);

s32 func_L01_003B42E8(s32 a0, s32 a1, s32 a2, s32 a3) {
    TextBox_003B42E8 box;
    char *t23;
    char *t19;
    char *t20;
    char *t18;
    s32 scale;
    s32 g;
    s32 w2;
    s32 h2;
    s32 cx;
    s32 cy;

    if (a1 == 0 && a2 == 0 && a3 == 0) {
        func_11B2E8(D_L01_002A2970, D_L01_001DE718, func_00381FF0(a0));
        scale = 0x100;
    } else {
        t23 = func_00381FF0(0x125C);
        if (a1 != 0) {
            if (a3 != 0) {
                if (a2 != 0) {
                    t19 = func_00381FF0(0x282);
                    t20 = func_00381FF0(0x12B4);
                    t18 = func_00381FF0(*(s32 *)(D_L01_002C5600 + a2 * 0xF0 + 4));
                    func_11B2E8(D_L01_002A2970, D_L01_001DE6C0, func_00381FF0(a0), t20, t23, t18, t23, a1, t19);
                } else {
                    t19 = func_00381FF0(0x282);
                    t20 = func_00381FF0(0x12B4);
                    func_11B2E8(D_L01_002A2970, D_L01_001DE6D8, func_00381FF0(a0), t20, t23, a1, t19);
                }
            } else if (a2 != 0) {
                t19 = func_00381FF0(0x282);
                t18 = func_00381FF0(*(s32 *)(D_L01_002C5600 + a2 * 0xF0 + 4));
                func_11B2E8(D_L01_002A2970, D_L01_001DE6F0, func_00381FF0(a0), t23, t18, t23, a1, t19);
            } else {
                t19 = func_00381FF0(0x282);
                func_11B2E8(D_L01_002A2970, D_L01_001DE708, func_00381FF0(a0), t23, a1, t19);
            }
        }
        scale = 0x100;
    }
    g = D_001D4BC8[0];
    func_003910C0(&box, (s32)((f32)scale * D_L01_001E11A4 + 0.5f), (s32)(D_L01_001E11A4 * 384.0f + 0.5f),
                  g - 0x90, g + 0x90, g, 0x140, 0x10, 0x27);
    box.f1A = 2;
    box.f18 = 2;
    func_0038FA18(&box, 0x8066CCFF, D_L01_002A2970, -1, 0x80000000, 1.0f, 1.0f);
    w2 = (s16)box.w / 2 + 8;
    h2 = (s16)box.h / 2 + 8;
    cy = box.y;
    cx = box.x;
    func_0038C3B0(cy - h2, cy + h2, cx - w2, cx + w2, 0x33, 0x331465B7);
    cy = box.y;
    cx = box.x;
    func_L01_00436020(0x60, 0x332299DE, (f32)(cy - h2), (f32)(cy + h2), (f32)(cx - w2), (f32)(cx + w2));
    box.flags &= 0xFFFB;
    func_0038FA18(&box, 0x8066CCFF, D_L01_002A2970, -1, 0x80000000, 1.0f, 1.0f);
    D_001D64E8[0] = 1;
    return 1;
}
