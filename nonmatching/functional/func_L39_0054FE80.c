/* functional: high. Multiplayer-menu scope overlay: delegates to the flux-scope drawer when the mode word is 1, else draws four mirrored quarter-screen quads (texture 0x46, colour 0x2F202020), and, if the mode word became 1 meanwhile, the shading quarters and the framed lens; D_L39_0024030x re-read per use as retail does; byte diff is register allocation only. */
#include "common.h"

extern s32 *D_L39_00241120;
extern s32 D_L39_00240300;
extern s32 D_L39_00240304;
__asm__(".extern D_L39_00240300, 16");
__asm__(".extern D_L39_00240304, 16");
extern s32 D_001FC450[];
extern s32 D_001DF9D8;
extern s32 D_001DF9DC;
extern s32 D_001DF9E0;
extern s32 D_001DF9E4;
extern s32 D_001DF9E8;
extern s32 D_001DF9EC;
extern s32 D_001DF9F0;
extern s32 D_001DF9F4;
extern s32 D_001DF9F8;
extern s32 D_001DF9FC;
extern s32 D_001DFA00;
extern s32 D_001DFA04;
extern s32 D_001DFA08;
extern void func_L01_00346668(void);
extern void func_L01_004C5E28(void);
extern void func_003A9440(s32, unsigned long);
extern void func_003D1030(void);
extern long func_L39_00589890(s32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);

void func_L39_0054FE80(void) {
    long tex;

    if (*D_L39_00241120 == 1) {
        func_L01_00346668();
        return;
    }
    func_L01_004C5E28();
    func_003A9440(0x4E, (long)(D_001FC450[2] >> 13) | 0x1000000L | 0x100000000L);
    tex = func_L39_00589890(0x46);
    func_0038B4D0(0, 0, (s32)(D_L39_00240300 * 0.5f), (s32)(D_L39_00240304 * 0.5f), 0, 0, 0x7F, 0x7F, 0x2F202020, tex);
    tex = func_L39_00589890(0x46);
    func_0038B4D0(D_L39_00240300, 0, -(s32)(D_L39_00240300 * 0.5f), (s32)(D_L39_00240304 * 0.5f), 0, 0, 0x7F, 0x7F, 0x2F202020, tex);
    tex = func_L39_00589890(0x46);
    func_0038B4D0(0, D_L39_00240304, (s32)(D_L39_00240300 * 0.5f), -(s32)(D_L39_00240304 * 0.5f), 0, 0, 0x7F, 0x7F, 0x2F202020, tex);
    tex = func_L39_00589890(0x46);
    func_0038B4D0(D_L39_00240300, D_L39_00240304, -(s32)(D_L39_00240300 * 0.5f), -(s32)(D_L39_00240304 * 0.5f), 0, 0, 0x7F, 0x7F, 0x2F202020, tex);
    if (*D_L39_00241120 == 1) {
        func_003A9440(0x42, (long)D_001DF9E4 | ((long)D_001DF9E8 << 2) | ((long)D_001DF9EC << 4) |
                                ((long)D_001DF9F0 << 6) | 0x8000000000L);
        func_003D1030();
        tex = func_L39_00589890(D_001DF9D8);
        func_0038B4D0(0, 0, (s32)(D_L39_00240300 * 0.5f), (s32)(D_L39_00240304 * 0.5f), 0, 0, 0xFF, 0xFF, D_001DF9DC, tex);
        func_0038B4D0(D_L39_00240300, 0, -(s32)(D_L39_00240300 * 0.5f), (s32)(D_L39_00240304 * 0.5f), 0, 0, 0xFF, 0xFF, D_001DF9DC, tex);
        func_0038B4D0(0, D_L39_00240304, (s32)(D_L39_00240300 * 0.5f), -(s32)(D_L39_00240304 * 0.5f), 0, 0, 0xFF, 0xFF, D_001DF9DC, tex);
        func_0038B4D0(D_L39_00240300, D_L39_00240304, -(s32)(D_L39_00240300 * 0.5f), -(s32)(D_L39_00240304 * 0.5f), 0, 0, 0xFF, 0xFF, D_001DF9DC, tex);
        func_003A9440(0x42, (long)D_001DF9E4 | ((long)D_001DF9E8 << 2) | ((long)D_001DF9EC << 4) |
                                ((long)D_001DF9F0 << 6) | 0x8000000000L);
        func_003A9440(0x42, (long)D_001DF9F4 | ((long)D_001DF9F8 << 2) | ((long)D_001DF9FC << 4) |
                                ((long)D_001DFA00 << 6) | 0x8000000000L);
        tex = func_L39_00589890(-7);
        func_0038B4D0(0, 0, D_L39_00240300, D_L39_00240304, D_001DFA04, D_001DFA08,
                      D_L39_00240300 - 20, D_L39_00240304 - 20, D_001DF9E0, tex);
    }
    func_003A9440(0x4E, (long)(D_001FC450[2] >> 13) | 0x1000000L);
}
