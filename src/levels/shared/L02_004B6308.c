#include "common.h"

/* localdecomp:start func_L02_004B6308 */
typedef struct {
    u8 pad0[36];
    s32 f36;
    u8 pad1[200];
} Ent4B21A8;

extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern Ent4B21A8 D_L02_002C31C0[];
extern s32 func_L01_004E9238(s32);
extern s32 func_L01_004DFD60(void);

s32 func_L02_004B6308(s32 a0) {
    if (D_001A4BE0[9700] == 3) {
        return 1;
    }
    if (a0 != 0 && D_001A4BE0[9707] != 0 && *(s16 *)(D_001A4BE0 + 10356) == 0) {
        s32 v = func_L01_004E9238(0);
        return ((Ent4B21A8 *)(D_001425C0[v] * 240 + (u8 *)D_L02_002C31C0))->f36;
    }
    if (func_L01_004DFD60() != 0) {
        return 74;
    }
    if (D_001A4BE0[5236] != 0) {
        return 85;
    }
    return 0;
}
/* localdecomp:end func_L02_004B6308 */
