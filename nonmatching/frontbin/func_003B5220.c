/* US draft of func_003B5220 (rac3-uya-decomp func_003AFC68, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003B5220 */
__asm__(".extern D_001D89BC, 4");
__asm__(".extern D_001D89E4, 4");
extern s32 D_001D89BC;
extern s32 D_001D89E4;
extern u8 D_0037F880[];
extern f32 D_001D9698_003B5220;
extern void func_003B5B38();
extern void func_0038E150(s32);
extern s32 func_00381FF0();
extern s32 func_0038E548(f32, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E81F0(s32, f32, f32);
extern void func_003B5858();
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7928(s32, s32, s32);
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003E7A18(s32, s32);
extern s32 func_003E8710(s32, s32);
extern s32 func_003E7E48(s32, s32);
extern s32 func_003E87B8(s32, s32, s32);
extern void func_003B5D70();
extern void func_003B0A60();
extern void *func_003B42F8();
void func_003B5220(void) {
    s32 flag = 0;
    f32 lim = 0.49f;
    f32 scale = 0.0f;
    f32 base = 0.0f;
    f32 lo = 6.0f;
    f32 hi = 11.0f;
    f32 x, y;
    D_001D89BC = -1;
    D_001D89E4 = 0;
    func_003B5B38();
    func_0038E150(0);
    x = (f32)func_0038E548(1.2f, func_00381FF0(0x107), -1) / D_001D9698_003B5220;
    if (lim < x) {
        flag = 1;
        scale = 0.588000059f / x;
        x = lim;
    }
    y = func_003C4088(lo, hi, (x - base) / lim);
    if (hi < y) y = hi;
    else if (y < lo) y = lo;
    func_003B9298(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, y, 0xD0008, func_00381FF0(0x107), 0xD0006, 0xFF, 0xD0007, 0xCD5);
    if (flag) func_003E81F0(0xD0005, scale, scale);
    func_003B5858(D_0037F880);
    func_003E8FE8(0x1C0004, func_00381FF0(0x1EBD), 0x8066CCFF, 0.5f, 0.932f, 0.9f, 0.9f);
    func_003E7928(0x1C0004, 3, 3);
    func_003E7838(0x1C0004, 0x2040, 1);
    func_003E8630(0x1C0000, 0x1C0004);
    func_003E8348(0x11, 0x1C0000);
    func_003E7A18(0x1C0003, 0);
    func_003E8710(0x1C0003, func_003B42F8(0));
    func_003E7E48(0x1C0003, 5);
    func_003E87B8(0x1C0003, 1, 0xA);
    func_003B5D70();
    func_003B0A60();
}
/* localdecomp:end func_003B5220 */
