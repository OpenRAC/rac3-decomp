#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
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

INCLUDE_ASM("asm/nonmatchings/text", func_003A8040);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A2C18;
typedef struct { u8 pad0[0x10]; V4_3A2C18 f10; u8 pad20[0x8A]; s16 hAA; } E_3A2C18;
typedef struct { u8 pad[0x20]; V4_3A2C18 *f20; u8 pad2[0x1C]; s32 f40; } S3_3A2C18;
typedef struct {
    u8 pad[0x30]; s32 f30; s32 f34; u8 pad38[0xC]; s16 h44; u8 pad46[0xA];
    S3_3A2C18 *f50; u8 pad54[0x14C]; E_3A2C18 *tbl[4];
} B_3A2C18;
extern B_3A2C18 D_00225700_003A2C18;
extern V4_3A2C18 D_00222400_003A2C18[];
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
typedef struct { u8 pad[0x48]; s32 f48; s32 f4C; } E_3A2DF8;
extern u8 *D_001D6EEC;
extern f32 D_001D6EF0;
extern s32 D_001DA010[2];
/* localdecomp:start func_003A8220 */
__asm__(".extern D_001D6EEC, 4");
__asm__(".extern D_001D6EF0, 4");
/* Retail forms the address of this 8-byte global with lui/addiu, not $gp: an unsized
   array is never small data. The shared declaration in this file is the sized
   `extern s32 D_001DA010[2];`, so this block uses a per-function alias for it. */
extern s32 D_001DA010_003A8220[];
void func_003A8220(E_3A2DF8 *a0) {
    s32 i;
    f32 one;
    D_001D6EEC = (u8 *)a0;
    for (i = 0x1FF; i >= 0; i--) {
        a0[i].f48 = 0;
    }
    do { one = 1.0f; } while (0);
    QZERO(D_001DA010_003A8220);
    D_001D6EF0 = one;
}
/* localdecomp:end func_003A8220 */

/* localdecomp:start func_003A8268 */
extern u8 *D_001D6EEC;
void func_003A8268(s32 a0, u8 *src) {
    u8 *p;
    s32 i;
    if (D_001D6EEC == 0) return;
    p = D_001D6EEC;
    i = 0;
    do {
        i++;
        if (*(s32 *)(p + 0x48) == 0) {
            *(s32 *)(p + 0x38) = *(s32 *)(src + 0x38);
            *(s32 *)(p + 0x3C) = *(s32 *)(src + 0x3C);
            *(s32 *)(p + 0x30) = *(s32 *)(src + 0x30);
            *(s32 *)(p + 0x44) = *(s32 *)(src + 0x44);
            *(f32 *)(p + 0x24) = *(f32 *)(src + 0x24);
            *(f32 *)(p + 0x20) = *(f32 *)(src + 0x20);
            *(f32 *)(p + 0x28) = *(f32 *)(src + 0x28);
            *(s32 *)(p + 0x34) = *(s32 *)(src + 0x34);
            *(s32 *)(p + 0x2C) = *(s32 *)(src + 0x2C);
            *(s32 *)(p + 0x40) = *(s32 *)(src + 0x40);
            *(s32 *)(p + 0x4C) = *(s32 *)(src + 0x4C);
            *(u128_t *)(p + 0) = *(u128_t *)(src + 0);
            *(u128_t *)(p + 0x10) = *(u128_t *)(src + 0x10);
            *(s32 *)(p + 0x48) = a0;
            return;
        }
        p += 0x50;
    } while (i < 0x200);
}
/* localdecomp:end func_003A8268 */
