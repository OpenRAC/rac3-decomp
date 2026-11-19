#include "common.h"

/* NTSC-U counterpart of func_003A78B8 (src/frontbin/3A6890.c): argument 6, and the second wait loop polls D_00142430 */
/* localdecomp:start func_U_003A2460 */
typedef struct { u8 p0[0x228]; f32 f228; f32 f22C; u8 p230[8]; f32 f238; f32 f23C; u8 p240[0x10]; s32 f250; s32 f254; s32 f258; } S_225980_003A2460;
typedef struct { u8 pad[0x90]; s32 f90[6]; } Q_003A2460;
typedef struct { u8 p0[0x15C]; s32 f15C; u8 p160[4]; s32 f164; } S_142430_003A2460;
extern u8 D_001CCFD0_003A2460[];
extern Q_003A2460 D_001A30B0_003A2460;
extern S_225980_003A2460 D_U_00225980_003A2460;
extern S_142430_003A2460 D_00142430_003A2460;
extern s32 D_U_001D9D84_003A2460;
extern s32 D_001D545C_003A2460;
extern s32 D_001D545C_003A2460_l;
__asm__(".extern D_001D545C_003A2460_l, 16");
extern s32 D_001D4B48_003A2460;
__asm__(".extern D_001D4B48_003A2460, 16");
extern s32 D_U_001D9DAC_003A2460;
extern u8 D_U_001D9CC4_003A2460, D_U_001D9CC5_003A2460, D_U_001D9CC6_003A2460;
extern f32 D_U_001D9CC8_003A2460, D_U_001D9CCC_003A2460, D_U_001D9CD0_003A2460, D_U_001D9CD4_003A2460;
extern u8 D_U_002CE180_003A2460[];
__asm__(".extern D_U_001D9D84_003A2460, 16");
__asm__(".extern D_U_001D9DAC_003A2460, 16");
__asm__(".extern D_U_001D9CC4_003A2460, 16");
__asm__(".extern D_U_001D9CC5_003A2460, 16");
__asm__(".extern D_U_001D9CC6_003A2460, 16");
__asm__(".extern D_U_001D9CC8_003A2460, 16");
__asm__(".extern D_U_001D9CCC_003A2460, 16");
__asm__(".extern D_U_001D9CD0_003A2460, 16");
__asm__(".extern D_U_001D9CD4_003A2460, 16");

extern s32 func_U_003B7FD8_003A2460(void);
extern void func_U_00385B60_003A2460(s32);
extern void func_0011F0A0_003A2460(s32);
extern void func_0013CF80_003A2460(s32, s32, s32, s32, s32);
extern void func_0013CA28_003A2460(void);
extern s32 func_0013B620_003A2460(void);
extern void func_U_003A0010_003A2460(void);
extern void func_U_0039CBA0_003A2460(void);
extern void func_0013BF00_003A2460(s32);
extern void func_0013BED0_003A2460(void);
extern void func_U_0038DA28_003A2460(s32, long, long);
extern void func_0013D310_003A2460(s32, u8 *);
extern s32 func_0012C908_003A2460(s32);
extern void func_U_00397490_003A2460(void);
extern void func_U_00395FF0_003A2460(void);
extern s32 func_U_003953F0_003A2460(void);
extern void func_0013CF40_003A2460(s32);
extern long func_0013CDF0_003A2460(s32);
extern void func_U_003A4580_003A2460(void);
void func_U_003A2460(void) {
    s32 i;
    S_225980_003A2460 *q;
    if (func_U_003B7FD8_003A2460() != 0) return;
    func_U_00385B60_003A2460(6);
    D_001D545C_003A2460 = D_U_001D9D84_003A2460;
    D_001D4B48_003A2460 = 0;
    func_0011F0A0_003A2460(0);
    func_0013CF80_003A2460(2, 0, 0, 0, 0);
    func_0013CA28_003A2460();
    func_0013B620_003A2460();
    func_U_003A0010_003A2460();
    func_U_0039CBA0_003A2460();
    D_001CCFD0_003A2460[7] = 1;
    for (i = 0; i < 6; i++) {
        if (D_001A30B0_003A2460.f90[i] != 0) {
            func_0013BF00_003A2460(D_001A30B0_003A2460.f90[i]);
            func_0013BED0_003A2460();
            D_U_001D9DAC_003A2460 = 0;
            D_001A30B0_003A2460.f90[i] = 0;
        }
    }
    q = &D_U_00225980_003A2460;
    q->f258 = 0x10;
    q->f250 = 0;
    q->f254 = 0;
    q->f228 = 0;
    q->f22C = 524288.0f;
    q->f238 = 255.0f;
    q->f23C = 128.0f;
    D_U_001D9CC4_003A2460 = q->f250;
    D_U_001D9CC5_003A2460 = q->f254;
    D_U_001D9CC6_003A2460 = q->f258;
    D_U_001D9CC8_003A2460 = q->f228;
    D_U_001D9CCC_003A2460 = q->f22C;
    D_U_001D9CD0_003A2460 = q->f238;
    D_U_001D9CD4_003A2460 = q->f23C;
    func_U_0038DA28_003A2460(0, 0, 0);
    func_0013D310_003A2460(D_001D545C_003A2460_l, D_U_002CE180_003A2460);
    D_001CCFD0_003A2460[7] = 1;
    do {
        func_0011F0A0_003A2460(0);
        func_0012C908_003A2460(0);
        func_U_00397490_003A2460();
        func_U_00395FF0_003A2460();
    } while (func_U_003953F0_003A2460() == 0);
    while (D_00142430_003A2460.f15C != 2 || D_00142430_003A2460.f164 >= 0) {
        func_0011F0A0_003A2460(0);
        func_0012C908_003A2460(0);
        func_U_00397490_003A2460();
        func_U_00395FF0_003A2460();
    }
    while (func_0013B620_003A2460() != 0);
    func_0013BED0_003A2460();
    func_0013CF40_003A2460(0);
    func_0013CDF0_003A2460(0);
    func_0013CDF0_003A2460(0);
    D_001CCFD0_003A2460[7] = 0;
    func_U_003A4580_003A2460();
}
/* localdecomp:end func_U_003A2460 */
