/* PAL near miss (k6 agent 2, 2026-11-26), from its functional C. 309 = 309 instructions, 4 words differ with tools/check.py at
 * level 39: only the first `*D_L39_00241120 == 1` test, where retail keeps the pointer in $v0 and the word in $v1 (here the other
 * way round). What fixed the rest: the $gp scalars as slot names (D_001DF9D8_sda..D_001DFA08_sda, size 4) and func_L39_00589890's
 * texture handle passed straight into func_0038B4D0 in the first four calls and the last (retail stores the result to the stack
 * argument slot; only the second block's handle is a variable). Tried without effect: an index or a struct field for the mode
 * word, `1 == *D`, a switch, the tail as an else, the constant 1 in a local, an s32 return, u32 pointer type.
 */
#include "common.h"

extern s32 *D_L39_00241120;
extern s32 D_L39_00240300;
extern s32 D_L39_00240304;
__asm__(".extern D_L39_00240300, 16");
__asm__(".extern D_L39_00240304, 16");
extern s32 D_001FC450[];
extern s32 D_001DF9D8_sda;
extern s32 D_001DF9DC_sda;
extern s32 D_001DF9E0_sda;
extern s32 D_001DF9E4_sda;
extern s32 D_001DF9E8_sda;
extern s32 D_001DF9EC_sda;
extern s32 D_001DF9F0_sda;
extern s32 D_001DF9F4_sda;
extern s32 D_001DF9F8_sda;
extern s32 D_001DF9FC_sda;
extern s32 D_001DFA00_sda;
extern s32 D_001DFA04_sda;
extern s32 D_001DFA08_sda;
__asm__(".extern D_001DF9D8_sda, 4");
__asm__(".extern D_001DF9DC_sda, 4");
__asm__(".extern D_001DF9E0_sda, 4");
__asm__(".extern D_001DF9E4_sda, 4");
__asm__(".extern D_001DF9E8_sda, 4");
__asm__(".extern D_001DF9EC_sda, 4");
__asm__(".extern D_001DF9F0_sda, 4");
__asm__(".extern D_001DF9F4_sda, 4");
__asm__(".extern D_001DF9F8_sda, 4");
__asm__(".extern D_001DF9FC_sda, 4");
__asm__(".extern D_001DFA00_sda, 4");
__asm__(".extern D_001DFA04_sda, 4");
__asm__(".extern D_001DFA08_sda, 4");
extern void func_L01_00346668(void);
extern void func_L01_004C5E28(void);
extern void func_003A9440(s32, unsigned long);
extern void func_003D1030(void);
extern long func_L39_00589890(s32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);

/* localdecomp:start func_L39_0054FE80 */
void func_L39_0054FE80(void) {
    long tex;

    if (*D_L39_00241120 == 1) {
        func_L01_00346668();
        return;
    }
    func_L01_004C5E28();
    func_003A9440(0x4E, (long)(D_001FC450[2] >> 13) | 0x1000000L | 0x100000000L);
    func_0038B4D0(0, 0, (s32)(D_L39_00240300 * 0.5f), (s32)(D_L39_00240304 * 0.5f), 0, 0, 0x7F, 0x7F, 0x2F202020, func_L39_00589890(0x46));
    func_0038B4D0(D_L39_00240300, 0, -(s32)(D_L39_00240300 * 0.5f), (s32)(D_L39_00240304 * 0.5f), 0, 0, 0x7F, 0x7F, 0x2F202020, func_L39_00589890(0x46));
    func_0038B4D0(0, D_L39_00240304, (s32)(D_L39_00240300 * 0.5f), -(s32)(D_L39_00240304 * 0.5f), 0, 0, 0x7F, 0x7F, 0x2F202020, func_L39_00589890(0x46));
    func_0038B4D0(D_L39_00240300, D_L39_00240304, -(s32)(D_L39_00240300 * 0.5f), -(s32)(D_L39_00240304 * 0.5f), 0, 0, 0x7F, 0x7F, 0x2F202020, func_L39_00589890(0x46));
    if (*D_L39_00241120 == 1) {
        func_003A9440(0x42, (long)D_001DF9E4_sda | ((long)D_001DF9E8_sda << 2) | ((long)D_001DF9EC_sda << 4) |
                                ((long)D_001DF9F0_sda << 6) | 0x8000000000L);
        func_003D1030();
        tex = func_L39_00589890(D_001DF9D8_sda);
        func_0038B4D0(0, 0, (s32)(D_L39_00240300 * 0.5f), (s32)(D_L39_00240304 * 0.5f), 0, 0, 0xFF, 0xFF, D_001DF9DC_sda, tex);
        func_0038B4D0(D_L39_00240300, 0, -(s32)(D_L39_00240300 * 0.5f), (s32)(D_L39_00240304 * 0.5f), 0, 0, 0xFF, 0xFF, D_001DF9DC_sda, tex);
        func_0038B4D0(0, D_L39_00240304, (s32)(D_L39_00240300 * 0.5f), -(s32)(D_L39_00240304 * 0.5f), 0, 0, 0xFF, 0xFF, D_001DF9DC_sda, tex);
        func_0038B4D0(D_L39_00240300, D_L39_00240304, -(s32)(D_L39_00240300 * 0.5f), -(s32)(D_L39_00240304 * 0.5f), 0, 0, 0xFF, 0xFF, D_001DF9DC_sda, tex);
        func_003A9440(0x42, (long)D_001DF9E4_sda | ((long)D_001DF9E8_sda << 2) | ((long)D_001DF9EC_sda << 4) |
                                ((long)D_001DF9F0_sda << 6) | 0x8000000000L);
        func_003A9440(0x42, (long)D_001DF9F4_sda | ((long)D_001DF9F8_sda << 2) | ((long)D_001DF9FC_sda << 4) |
                                ((long)D_001DFA00_sda << 6) | 0x8000000000L);
        func_0038B4D0(0, 0, D_L39_00240300, D_L39_00240304, D_001DFA04_sda, D_001DFA08_sda,
                      D_L39_00240300 - 20, D_L39_00240304 - 20, D_001DF9E0_sda, func_L39_00589890(-7));
    }
    func_003A9440(0x4E, (long)(D_001FC450[2] >> 13) | 0x1000000L);
}
/* localdecomp:end func_L39_0054FE80 */
