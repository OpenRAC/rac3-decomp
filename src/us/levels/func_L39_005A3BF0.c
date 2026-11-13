#include "common.h"

/* NTSC-U counterpart of func_L39_005A5860 (src/levels/shared/L39_005A5238.c) */
typedef struct S_005A5238 {
    u8 pad_000[0x164];
    s32 f164;
    s32 f168;
} S_005A5238;
extern S_005A5238 D_001A4560;
extern S_005A5238 D_001A4560;
extern s32 D_001D4CEC_sda_005A3BF0;
extern int D_001D4CEC_sda_005A3BF0;
extern s32 D_001D4CEC_sda_005A3BF0;
extern s32 D_001D4CEC_sda_005A3BF0;
extern s32 D_001D4CEC_sda_005A3BF0;
extern int D_001D4CEC_sda_005A3BF0;
extern s32 D_001D4CEC_sda_005A3BF0;
extern s32 D_001D4CEC_sda_005A3BF0;

/* localdecomp:start func_L39_005A3BF0 */
__asm__(".extern D_001D7968_sda, 4");
__asm__(".extern D_001D7954_sda, 4");
extern s32 D_001D4CEC_sda_005A3BF0;
extern s32 D_001D7968_sda;
extern void (*D_001D7954_sda)(void);
extern void func_00397238(void);
extern s32 D_L39_00240578;
extern s32 D_L39_0024057C;

void func_L39_005A3BF0(void) {
    u8 *base = (u8 *)&D_001A4560;
    void (*fp)(void);
    s32 idx;
    s32 e;
    s32 v;
    u16 h;

    if (*(s32 *)(base + 0x15C) == 2) {
        if (*(s32 *)(base + 0x164) < 0) {
            idx = D_001D7968_sda;
            e = *(s32 *)(base + idx * 0x1C + 0x30);
            if (e == -1 || (D_001D4CEC_sda_005A3BF0 & 0x6000) != 0) {
                func_00397238();
                fp = D_001D7954_sda;
                v = D_L39_0024057C & ~0x4000;
                D_001D4CEC_sda_005A3BF0 = v;
                if (fp != 0) {
                    fp();
                    D_001D7954_sda = 0;
                }
                h = D_001D7968_sda;
                D_L39_00240578 = 0x19;
                *(u16 *)(base + 0x18) = h;
            } else {
                D_L39_00240578 = 0x21;
            }
        }
    }
}
/* localdecomp:end func_L39_005A3BF0 */
