/* US draft of func_003B4878 (rac3-uya-decomp func_003AF2C0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003B4878 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } E_3AF2C0;
__asm__(".extern D_001D894C, 4");
__asm__(".extern D_001D8940, 4");
__asm__(".extern D_001D8944, 4");
__asm__(".extern D_001D8950, 4");
__asm__(".extern D_001D8958, 4");
__asm__(".extern D_001D8954, 4");
extern f32 D_001D894C;
extern f32 D_001D8940;
extern f32 D_001D8944;
extern f32 D_001D8950;
extern f32 D_001D8958;
extern f32 D_001D8954;
extern f32 D_001D895C;
extern E_3AF2C0 D_00337640_003B4878[];
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8AE8(s32, s32, s32, s32, s32, s32);
extern s32 func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E8E38(s32, s32, s32);
extern s32 func_003E8898(s32, f32, f32);
extern s32 func_003E8958(s32, s32);
extern s32 func_003E8A08(s32, s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_003B5060(s32);
extern s32 func_00381FF0();
void func_003B4878(void) {
    f32 half = 0.5f;
    f32 one = 1.0f;
    f32 one2;
    f32 zero;
    s32 i, j;
    E_3AF2C0 *e;
    f32 y, step;
    func_003E8EF0(0xD0000, 0x3D, 0x332299DE, half, half, one, one, D_001D894C);
    func_003E8EF0(0xD0001, 0x3E, 0x332299DE, half, half, one, one, D_001D894C);
    func_003E8EF0(0xD0002, 0x3F, 0x331465B7, half, half, one, one, D_001D894C);
    func_003E8EF0(0xD0003, 0x40, 0x802299DE, half, half, one, one, D_001D894C);
    func_003E9138(0xD0028, 0x402299DE, 0, half, half, 0.333333f, 0.025f);
    func_003B5060(0xD000B);
    func_003E8AE8(0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0028);
    func_003E8348(0x10, 0xD000B);
    func_003B5060(0xD0025);
    for (i = 0; i < 5; i++) {
        if (D_00337640_003B4878[i].x4 == 0x169C) {
            func_003E9358(D_00337640_003B4878[i].x0, func_00381FF0(0x169C), 0x8066CCFF, 0.5f, 0.0f, 0.465f, 0.078f, 1.0f);
            func_003E7838(D_00337640_003B4878[i].x0, 0x40, 1);
            func_003E8E38(D_00337640_003B4878[i].x0, 1, 1);
        } else {
            zero = 0.0f;
            one2 = 1.0f;
            func_003E8FE8(D_00337640_003B4878[i].x0, func_00381FF0(D_00337640_003B4878[i].x4), 0x8066CCFF, zero, zero, one2, one2);
            func_003E7838(D_00337640_003B4878[i].x0, 0x40, 1);
            func_003E8898(D_00337640_003B4878[i].x0, 0.425f, 0.85f);
            func_003E8958(D_00337640_003B4878[i].x0, 1);
        }
        func_003E8630(0xD0025, D_00337640_003B4878[i].x0);
    }
    func_003E8348(0x11, 0xD0025);
    {
    s32 id = 0x169C;
    step = D_001D8940;
    y = D_001D8944;
    for (i = 4, j = 0; i >= 0; i--, j++) {
        if (D_00337640_003B4878[j].x4 == id) y = 0.558f;
        func_003E73B8(D_00337640_003B4878[j].x0, 0.5f, y);
        if (D_00337640_003B4878[j].x4 == id) y = 0.647f;
        else y += step;
    }
    }
    func_003E9138(0x5B0000, 0x332299DE, 0xED5A, D_001D8950, D_001D8958, -0.07f, 0.08615385f);
    func_003E9138(0x5B0001, 0x332299DE, 0xED5A, D_001D8954, D_001D895C, 0.07f, -0.08615385f);
    func_003E8A08(0xD000B, 0x5B0000, 0x5B0001);
    for (i = 0; i < 4; i++) {
        func_003E9138(i + 0x5B0002, 0x331465B7, 0, 0.5f, 0.2f, 0.33f, 0.006667f);
        func_003E8630(0xD000B, i + 0x5B0002);
    }
}
/* localdecomp:end func_003B4878 */
