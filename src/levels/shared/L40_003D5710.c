#include "common.h"

/* localdecomp:start func_L40_003D5710 */
typedef struct {
    u8 pad0[0x180];
    s32 x180;
} S_003D5710_G;

typedef struct {
    u8 pad0[0xC];
    s32 xC;
} S_003D5710_V;

extern S_003D5710_G *D_001D5F30_sda;

s32 func_L40_003D5710(u8 *a0) {
    s32 t = (*(S_003D5710_V **)(a0 + 0x68))->xC;

    return t == 0 || (t == 1 && D_001D5F30_sda->x180 == 0) || (t == 2 && D_001D5F30_sda->x180 == 1) || (t == 3 && D_001D5F30_sda->x180 == 2);
}
/* localdecomp:end func_L40_003D5710 */

/* localdecomp:start func_L46_0041C860 */
typedef struct {
    u8 pad0[0x8C];
    s32 x8C;
} S_0041C860_V;

/* D_001D5F30_sda: the file's declaration (S_003D5710_G *, field at 0x180) */
s32 func_L46_0041C860(u8 *a0) {
    s32 t = (*(S_0041C860_V **)(a0 + 0x68))->x8C;

    return t == 0 || (t == 1 && D_001D5F30_sda->x180 == 0) || (t == 2 && D_001D5F30_sda->x180 == 1) || (t == 3 && D_001D5F30_sda->x180 == 2);
}
/* localdecomp:end func_L46_0041C860 */
