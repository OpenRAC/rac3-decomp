#include "common.h"

/* NTSC-U counterpart of func_L39_005A55E8 (src/levels/shared/L39_005A5238.c) */
typedef struct S_005A5238 {
    u8 pad_000[0x164];
    s32 f164;
    s32 f168;
} S_005A5238;
typedef struct S_005A54F8 {
    u8 pad_00[8];
    s32 f08;
    s32 f0C;
    u8 pad_10[8];
    s16 f18;
    u8 pad_1A[6];
    s32 f20;
    u8 pad_24[0x138];
    s32 f15C;
    s32 f160;
    s32 f164;
    s32 f168;
    s32 f16C;
} S_005A54F8;
extern S_005A5238 D_001A4560;
extern S_005A5238 D_001A4560;
extern s32 D_L39_00240578;
extern s32 D_L39_0024057C;
extern s32 D_L39_00240578;
extern s32 D_L39_0024057C;
extern s32 D_L39_0024057C;
extern s32 D_L39_00240578;
extern s32 D_001D4CEC_sda_005A3978;
extern int D_001D4CEC_sda_005A3978;
extern int D_L39_00240578;
extern s32 D_001D4CEC_sda_005A3978;
extern s32 D_001D4CEC_sda_005A3978;
extern s32 D_L39_00240578;
extern s32 D_L39_0024057C;

/* localdecomp:start func_L39_005A3978 */
__asm__(".extern D_001D4CEC_sda_005A3978, 4");
__asm__(".extern D_001D7950_sda, 4");
__asm__(".extern D_001D7964_sda, 4");
extern s32 D_001D4CEC_sda_005A3978;
extern s32 D_001D7950_sda;
extern void (*D_001D7964_sda)(void);
extern s32 D_L39_00240578;
extern s32 D_L39_0024057C;

void func_L39_005A3978(void) {
    S_005A54F8 *p = (S_005A54F8 *)&D_001A4560;
    void (*cb)(void);
    s16 phase;
    s32 w;
    u16 h;

    if (p->f15C == 2 && p->f164 < 0) {
        if (p->f16C != 0) {
            D_L39_00240578 = 0x18;
            D_001D4CEC_sda_005A3978 = D_001D4CEC_sda_005A3978 | 0x40;
        } else if (p->f08 != 2) {
            D_L39_00240578 = 4;
        } else {
            phase = p->f18;
            if (phase == -2) {
                if (p->f0C + p->f20 < 600) {
                    D_L39_00240578 = 0x15;
                } else {
                    D_L39_00240578 = 0x18;
                    D_001D4CEC_sda_005A3978 = D_L39_0024057C | 0x40;
                }
            } else if (phase >= -1) {
                if (phase == -1) {
                    w = D_L39_0024057C;
                    if (w & 0x1000) {
                        h = D_001D7950_sda;
                        D_001D7950_sda = -1;
                        p->f18 = h;
                        D_L39_0024057C = w & ~0x1000;
                    }
                }
                D_L39_00240578 = 0x12;
            }
        }
        cb = D_001D7964_sda;
        if (cb != 0) {
            cb();
            D_001D7964_sda = 0;
        }
    }
}
/* localdecomp:end func_L39_005A3978 */
