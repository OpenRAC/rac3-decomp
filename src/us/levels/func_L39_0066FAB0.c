#include "common.h"

/* NTSC-U counterpart of func_L39_00672400 (src/levels/shared/L39_00672400.c) */
/* localdecomp:start func_L39_0066FAB0 */
typedef struct {
    u8 pad0[0x88];
    f32 f88[4];
    u8 pad98[0xBC - 0x98];
    u8 bBC;
    u8 bBD;
} S_00672400;

typedef struct {
    u8 pad0[0x180];
    s32 f180;
} T_00672400;

extern S_00672400 D_001A5E50;
extern f32 D_001A6BC8[];
extern T_00672400 *D_001D5F30_sda_0066FAB0;
extern s32 func_00197640(s32);
extern void func_001962F8(void);

void func_L39_0066FAB0(void) {
    S_00672400 *p = &D_001A5E50;
    if (p->bBD != 0) {
        if (p->bBC != 0) {
            s32 i = func_00197640(D_001D5F30_sda_0066FAB0->f180);
            p->bBC = 0;
            p->f88[i] += D_001A6BC8[0];
            func_001962F8();
        }
    }
}
/* localdecomp:end func_L39_0066FAB0 */
