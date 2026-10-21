/* US draft of func_003BCC10 (rac3-uya-decomp func_003BCB38, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003BCC10 */
typedef struct { u8 p0[0x15C]; s32 f15C; s32 f160; s32 f164; } S_142430_3B7378;
__asm__(".extern D_001D8CF0, 4");
extern S_142430_3B7378 D_142430_003BCC10;
extern s32 D_001D99A4;
extern s32 D_001D4BC4;
extern s32 D_001D9BC8;
extern f32 D_001D8CF0;
extern void func_00389620(s32);
extern void func_003A97F8(s32, unsigned long);
extern long func_00389978(s32);
extern void func_0038B8B0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern void func_00397A18(f32, f32, f32, f32, f32, s32, s32, long);
extern void func_00389750(void);
extern void func_0038B200(s32, s32, s32, s32);
void func_003BCC10(void) {
    f32 c, b, a;
    if ((u32)(D_142430_003BCC10.f15C - 15) < 2 || D_142430_003BCC10.f164 == 15 || D_001D99A4 != 0) {
        c = 272.0f;
        func_00389620(1);
        func_003A97F8(0x42, 0x8000000044UL);
        func_003A97F8(0x47, (unsigned long)0x3004B);
        func_0038B8B0(0x2C, D_001D4BC4 - 0x60, 0x40, 0x40, 0, 0, 0x40, 0x40, 0x80808080UL, func_00389978(3));
        b = (f32)((D_001D4BC4 - 0x40) << 4);
        a = (f32)(D_001D9BC8 % 55) * -6.2831855f / 55.0f;
        func_00397A18(1216.0f, b, c, c, a, 0x40, 0x40, func_00389978(4));
        func_00389750();
        if ((u32)(D_142430_003BCC10.f15C - 15) < 2 || D_142430_003BCC10.f164 == 15) D_001D99A4 = 30;
        else D_001D99A4 = D_001D99A4 - 1;
    }
    func_003A97F8(0x42, 0x8000000044UL);
    func_0038B200(0, 0, 0, (s32)(D_001D8CF0 * 128.0f));
}
/* localdecomp:end func_003BCC10 */
