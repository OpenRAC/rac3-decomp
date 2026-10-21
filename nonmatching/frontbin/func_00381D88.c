/* US draft of func_00381D88 (rac3-uya-decomp func_0037DD30, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00381D88 */
__asm__(".extern D_001D568C, 4");
__asm__(".extern D_001D5690, 4");
__asm__(".extern D_001D5694, 4");
typedef struct { u8 p0[0xAD]; u8 bAD; } S_143950_37DD30;
typedef struct { u8 p0[0x15C]; s32 f15C; u8 p160[4]; s32 f164; s32 f168; } S_142430_37DD30;
extern S_143950_37DD30 D_00143950_00381D88;
extern S_142430_37DD30 D_00142430_00381D88;
extern s32 D_001D568C;
extern s32 D_001D5690;
extern s32 D_001D5694;
extern s32 D_00227400[];
extern s32 D_001D4D40;
extern void func_0038E150(s32);
extern void func_13D3C0(s32);
extern s32 func_00392B20();
extern s32 func_00392C78();
extern s32 func_00381FF0(s32);
extern void func_003820C8(void);
extern void func_003910C0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_0038B1E8(s32, long, s32, s32, unsigned long, s32, f32, f32);
void func_00381D88(void) {
    s16 buf[16];
    s32 x;
    if (D_001D5694 < 0x5A) x = (D_001D5694 - 0xF) * 0xE0 / 0x1E;
    else x = (0xA5 - D_001D5694) * 0xE0 / 0x1E;
    if (x < 0) x = 0;
    if (x > 0xE0) x = 0xE0;
    D_001D5694++;
    x = (x | (((x << 16) | 0x80000000) | (x << 8)));
    func_0038E150(1);
    switch (D_001D5690) {
    case 7:
        D_001D4D40 = 0;
        if (D_00143950_00381D88.bAD != 0) func_00392B20(D_00227400, 0x1D);
        else func_00392B20(D_00227400, 0x1F);
        D_00227400[0] = 4;
        func_00392C78(D_00227400);
        D_001D5694 = 0;
        D_001D5690 = 8;
        break;
    case 8:
        D_001D568C = 0;
        func_13D3C0(10);
        if (D_00142430_00381D88.f15C == 2 && D_00142430_00381D88.f164 < 0) {
            D_00142430_00381D88.f168 = 0;
            D_00142430_00381D88.f164 = 0x18;
        }
        break;
    case 9:
        D_001D568C = 1;
        func_003910C0(buf, 0, 0x1E0, 0x20, 0x1E0, 0x100, 0xC8, 0x10, 3);
        ((void (*)(s16 *, s32, s32, s32, unsigned long, f32, f32))func_0038B1E8)(buf, x, func_00381FF0(0x1700), -1, 0x80000000UL, 1.0f, 1.0f);
        if (D_001D5694 >= 0xB5) func_003820C8();
        break;
    }
}
/* localdecomp:end func_00381D88 */
