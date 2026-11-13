#include "common.h"

/* NTSC-U counterpart of func_L39_005A5920 (src/levels/shared/L39_005A5238.c) */
typedef struct S_005A5238 {
    u8 pad_000[0x164];
    s32 f164;
    s32 f168;
} S_005A5238;
extern S_005A5238 D_001A4560;
extern S_005A5238 D_001A4560;
extern s32 D_L39_00240578;
extern s32 D_L39_00240578;
extern s32 D_L39_00240578;
extern int D_L39_00240578;
extern s32 D_L39_00240578;
extern s32 D_L39_00240578;
extern int D_L39_00240578;
extern s32 D_L39_00240578;
extern s32 D_001D7968_sda;

/* localdecomp:start func_L39_005A3CB0 */
__asm__(".extern D_001D795C_sda, 4");
__asm__(".extern D_001D7968_sda, 4");
extern void (*D_001D795C_sda)(void);
extern s32 D_001D7968_sda;
extern s32 D_L39_00240578;

typedef struct S_005A5920 {
    u8 pad0[0x18];
    u16 f18;
    u8 pad1[0x148 - 0x1A];
    s32 f148;
    u8 pad2[0x15C - 0x14C];
    s32 f15C;
    u8 pad3[0x164 - 0x160];
    s32 f164;
} S_005A5920;

void func_L39_005A3CB0(void) {
    S_005A5920 *p = (S_005A5920 *)&D_001A4560;
    void (*fp)(void);

    if (p->f15C == 2 && p->f164 < 0) {
        fp = D_001D795C_sda;
        if (fp != 0) {
            fp();
            D_001D795C_sda = 0;
        }
        p->f18 = D_001D7968_sda;
        p->f148 = 0;
        D_L39_00240578 = 0x17;
    }
}
/* localdecomp:end func_L39_005A3CB0 */
