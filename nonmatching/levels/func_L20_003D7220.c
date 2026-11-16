/* PAL near miss (Codex wave 8): held at landing (e0c7b461): the C matches PAL at every place, but its NTSC-U counterpart (same code) did not build from it everywhere in the NTSC-U build.
 */
#include "common.h"
/* localdecomp:start func_L20_003D7220 */
extern s32 D_001D5520;
extern s32 D_L20_001DEC10, D_L20_001DEC14;
extern s32 D_L20_001DEC18, D_L20_001DEC1C, D_L20_001DEC20, D_L20_001DEC24;
extern s32 D_L20_001DEC28, D_L20_001DEC2C, D_L20_001DEC30, D_L20_001DEC34;
extern s32 D_L20_001DEC38, D_L20_001DEC3C, D_L20_001DEC40, D_L20_001DEC44, D_L20_001DEC48;
extern s32 D_001A1ED0[];
__asm__(".extern D_L20_001DEC10, 4");
__asm__(".extern D_L20_001DEC14, 4");
__asm__(".extern D_L20_001DEC18, 4");
__asm__(".extern D_L20_001DEC1C, 4");
__asm__(".extern D_L20_001DEC20, 4");
__asm__(".extern D_L20_001DEC24, 4");
__asm__(".extern D_L20_001DEC28, 4");
__asm__(".extern D_L20_001DEC2C, 4");
__asm__(".extern D_L20_001DEC30, 4");
__asm__(".extern D_L20_001DEC34, 4");
__asm__(".extern D_L20_001DEC38, 4");
__asm__(".extern D_L20_001DEC3C, 4");
__asm__(".extern D_L20_001DEC40, 4");
__asm__(".extern D_L20_001DEC44, 4");
__asm__(".extern D_L20_001DEC48, 4");
void func_L20_003D7220(void *p, s32 x, s32 alpha, f32 a, f32 b, f32 c, f32 d)
{
    extern void func_L01_004C5E28(void);
    extern void func_003A9440(s32, long);
    extern void func_003D1030(void);
    extern long func_00389598(s32);
    extern void func_0038B4D0(s32,s32,s32,s32,s32,s32,s32,s32,long,long);
    long tex;
    s32 color;
    func_L01_004C5E28();
    if (D_001D5520) {
        D_L20_001DEC48 = -1;
        D_L20_001DEC40 = 0xEC;
        D_L20_001DEC44 = 0xF0;
    }
    func_003A9440(0x4E, (D_001A1ED0[2] >> 13) | 0x1000000 | 0x100000000L);
    func_003A9440(0x42, (long)D_L20_001DEC18 | ((long)D_L20_001DEC1C << 2) | ((long)D_L20_001DEC20 << 4) | ((long)D_L20_001DEC24 << 6) | 0x8000000000L);
    func_003D1030();
    tex=func_00389598(D_L20_001DEC10);
    color=(alpha << 24) | 0x7F7F7F;
    func_0038B4D0(0,0,(s32)(D_001CFEC0_003D6F30->h150 * 0.5f),(s32)(D_001CFEC0_003D6F30->h152 * 0.5f),0,0,255,255,color,tex);
    func_0038B4D0(D_001CFEC0_003D6F30->h150,0,-(s32)(D_001CFEC0_003D6F30->h150 * 0.5f),(s32)(D_001CFEC0_003D6F30->h152 * 0.5f),0,0,255,255,color,tex);
    func_0038B4D0(0,D_001CFEC0_003D6F30->h152,(s32)(D_001CFEC0_003D6F30->h150 * 0.5f),-(s32)(D_001CFEC0_003D6F30->h152 * 0.5f),0,0,255,255,color,tex);
    func_0038B4D0(D_001CFEC0_003D6F30->h150,D_001CFEC0_003D6F30->h152,-(s32)(D_001CFEC0_003D6F30->h150 * 0.5f),-(s32)(D_001CFEC0_003D6F30->h152 * 0.5f),0,0,255,255,color,tex);
    func_003A9440(0x42, (long)D_L20_001DEC18 | ((long)D_L20_001DEC1C << 2) | ((long)D_L20_001DEC20 << 4) | ((long)D_L20_001DEC24 << 6) | 0x8000000000L);
    func_003A9440(0x42, (long)D_L20_001DEC28 | ((long)D_L20_001DEC2C << 2) | ((long)D_L20_001DEC30 << 4) | ((long)D_L20_001DEC34 << 6) | 0x8000000000L);
    func_0038B4D0(0,0,D_001CFEC0_003D6F30->h150,D_001CFEC0_003D6F30->h152,D_L20_001DEC38,D_L20_001DEC3C,D_L20_001DEC40,D_L20_001DEC44,D_L20_001DEC14,func_00389598(D_L20_001DEC48));
    func_003A9440(0x4E, 0x1000000 | (D_001A1ED0[2] >> 13));
}
/* localdecomp:end func_L20_003D7220 */
