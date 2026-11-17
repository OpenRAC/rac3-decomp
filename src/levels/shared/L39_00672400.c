#include "common.h"

/* localdecomp:start func_L39_00672400 */
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

extern S_00672400 D_001A5CD0;
extern f32 D_001A6A48[];
extern T_00672400 *D_001D5F30_sda;
extern s32 func_00197550(s32);
extern void func_00196208(void);

void func_L39_00672400(void) {
    S_00672400 *p = &D_001A5CD0;
    if (p->bBD != 0) {
        if (p->bBC != 0) {
            s32 i = func_00197550(D_001D5F30_sda->f180);
            p->bBC = 0;
            p->f88[i] += D_001A6A48[0];
            func_00196208();
        }
    }
}
/* localdecomp:end func_L39_00672400 */
