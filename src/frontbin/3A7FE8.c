#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003A7FE8(void);
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
#define QZERO(p) __asm__ __volatile__("sq $0,0x0(%0)" : : "r"(p))


typedef struct { u8 p0[0x15C]; s32 f15C; u8 p160[4]; s32 f164; } S_142430_3A2460;
typedef struct { u8 p0[0x228]; f32 f228; f32 f22C; u8 p230[8]; f32 f238; f32 f23C; u8 p240[0x10]; s32 f250; s32 f254; s32 f258; } S_225980_3A2460;
extern S_142430_3A2460 D_00142430_003A2460;
extern u8 D_001CCFD0_003A2460[];
extern u8 D_001A30B0[];
extern S_225980_3A2460 D_00225900_003A2460;
extern s32 D_001D9D04;
extern u32 D_001D545C;
extern s32 D_001D4B48;
extern s32 D_001D9D2C;
extern u8 D_001D9C44, D_001D9C45, D_001D9C46;
extern f32 D_001D9C48, D_001D9C4C, D_001D9C50, D_001D9C54;
extern u8 D_002D2100[];
extern s32 func_003BD4B8();
extern void func_0038A238(s32);
extern void func_11F0A0(s32);
extern void func_13CF80();
extern void func_13CA28(void);
extern void func_13B620_003A2460(void);
extern void func_003A1C28(void);
extern void func_13BF00();
extern void func_13BED0();
extern void func_00392260(s32, long, long);
extern void func_13D310();
extern s32 func_12C908(s32);
extern void func_0039C410(void);
extern void func_0039ADE0(void);
extern s32 func_0039A1E0();
extern void func_13CF40();
extern void func_13CDF0(s32);
extern void func_003A9AD0();

/* localdecomp:start func_003A7FE8 */
typedef struct { u8 pad[0x20]; void *p20; u8 pad2[0x1C]; s32 p40; } S2_3A2BC0;
typedef struct { u8 pad[0x30]; s32 f30; u8 pad2[0x1C]; S2_3A2BC0 *f50; u8 pad3[0x14C]; s32 f1A0[4]; } B_3A2BC0;
extern B_3A2BC0 D_00225700;
extern S2_3A2BC0 D_00334B90[];
extern s32 D_001D7000;
extern void *D_001D7080;
extern s32 D_001D7090;
void func_003A7FE8(void) {
    B_3A2BC0 *base = &D_00225700;
    s32 idx = -1;
    S2_3A2BC0 *p;
    if (base->f30 == 0) idx = 3;
    if (idx != -1) {
        p = D_00334B90;
        base->f50 = p;
        D_001D7080 = &D_001D7000;
        p->p20 = &D_001D7090;
        p->p40 = base->f1A0[idx];
    }
}
/* localdecomp:end func_003A7FE8 */
