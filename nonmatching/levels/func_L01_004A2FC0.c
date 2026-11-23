/* Matches PAL byte for byte with check.py at its 34 places (round 19, sonnet xhigh), but the full level build rejects it:
 * func_L01_004A2FC0, its word at +0x2D8: the instruction differs (33 of 34 levels; the rest are not built with it).
 * check.py masks relocated fields; tools/level_symbols.py compares them with the real symbols of each level: a callee or global name
 * (or its address) used at +0x2D8 is wrong. Compare the retail word with the C there before spending more compiles.
 * Needs a divs_nops.txt row `func_L01_004A2FC0 0 2 1 0 0` (it was in the match commit).
 */
/* localdecomp:start func_L01_004A2FC0 */
extern f32 D_L01_001DC0EC;
__asm__(".extern D_L01_001DC0EC, 16");
extern u8 D_L01_001D96D8_004A2FC0[8];
__asm__(".extern D_L01_001D96D8_004A2FC0, 8");
extern u8 D_L01_001D9728[8];
__asm__(".extern D_L01_001D9728, 8");
extern u8 D_L01_002EDB38[];
extern void func_L01_004A2840_004A2FC0(void);
extern void func_L01_004A2560(void *);
extern s32 func_0038E548(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 func_L01_00516B90(s32, s32, s32);
extern s32 func_L01_00516818(s32, f32);
extern s32 func_003E7AC8(s32, s32);
extern s32 func_L01_00516728(s32, f32, f32);
extern s32 func_L01_00517BF8(s32, s32, s32, s32, s32, s32);
extern s32 func_L01_00517DB8(s32, s32, s32, f32);
extern s32 func_L01_00516D60(s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003E7F20(s32, s32);

void func_L01_004A2FC0(void) {
    s32 flag;
    s32 i;
    f32 lim;
    f32 pad;
    f32 off;
    f32 hi;
    f32 lo;
    f32 w;
    f32 x;
    flag = 0;
    func_L01_004A2840_004A2FC0();
    lim = 0.49000001f;
    pad = 0.0f;
    func_0038E150(0);
    lo = 6.0f;
    off = pad;
    hi = 11.0f;
    w = (f32)func_0038E548(func_00381FF0(0x1CF), -1, 1.20000005f) / D_L01_001DC0E8;
    if (lim < w) {
        flag = 1;
        pad = 0.588000059f / w;
        w = lim;
    }
    x = func_003C4088(lo, hi, (w - off) / lim);
    if (hi < x) {
        x = hi;
    } else if (x < lo) {
        x = lo;
    }
    func_003B9298(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008, func_00381FF0(0x1CF), 0xD0006, 0x124, 0xD0007, 0xCD5, x);
    func_L01_00516FD8(0xD0006, D_L01_001D9728);
    if (flag != 0) {
        func_L01_00517538(0xD0005, pad, pad);
    }
    func_L01_004A2560(D_L01_002EDB38);
    func_L01_00516FD8(0x580004, (void *)func_00381FF0(0x1CF));
    func_L01_00516FD8(0x580005, D_L01_001D96D8_004A2FC0);
    func_L01_00516B90(0x580004, 3, 3);
    func_L01_00516B90(0x580005, 3, 3);
    func_L01_00516818(0x580003, 1.0f);
    func_003E7AC8(0x580003, 1);
    func_L01_00516728(0x580003, 2.0f / D_L01_001DC0E8, 2.0f / D_L01_001DC0EC);
    func_L01_00517BF8(0x580003, 1, 1, 1, 0, 0);
    func_L01_00517DB8(0x580003, 0xB4, 0, 0.000500000024f);
    func_L01_00516D60(0x580003, 1);
    func_003E8348(0x11, 0x580000);
    func_003E7F20(0x580003, 1);
    func_L01_004A2BE0();
    i = D_L01_001D96C0 - 1;
    D_L01_001D96C4 = i;
    func_L01_00516FD8(0x580003, (void *)func_00381FF0(D_001A8EC8[i]));
}
/* localdecomp:end func_L01_004A2FC0 */
