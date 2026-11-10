#include "common.h"

/* localdecomp:start func_L39_006A03B0 */
typedef struct {
    char _p0[0xE0];
    s16 hE0[8];
    s16 hF0[8];
} S_006A03B0_p;
typedef struct {
    char _p0[0x8];
    s32 w8;
    char _p1[0x169 - 0xC];
    u8 b169;
    char _p2[0x2EC - 0x16A];
    s32 w2EC;
} S_006A03B0_g;
typedef struct {
    char _p0[0x284];
    s32 f284;
} S_006A03B0_s;

extern S_006A03B0_p *D_001D5F30_sda;
extern S_006A03B0_s *D_001DC204_sda;
extern S_006A03B0_g D_001A5CD0;
extern void func_L39_006A0540(void *);
extern s32 func_L39_0068AEF8(void *, s32);

s32 func_L39_006A03B0(void *a0, s32 a1) {
    s32 i;
    s32 idx;

    func_L39_006A0540(a0);
    if (D_001D5F30_sda != 0) {
        idx = -1;
        for (i = 0; i < 8; i++) {
            if (D_001D5F30_sda->hE0[i] == D_001A5CD0.w8) {
                idx = i;
                break;
            }
        }
        if (idx < 0) {
            return 0;
        }
        if ((D_001D5F30_sda != 0 && D_001D5F30_sda->hF0[idx] == 5) || D_001A5CD0.b169 != 0
            || D_001A5CD0.w2EC != 0 || (D_001D5F30_sda != 0 && D_001D5F30_sda->hF0[0] >= 7)) {
            D_001DC204_sda->f284 = 0x2C;
            return 1;
        }
    }
    if (a1 == 7) {
        D_001DC204_sda->f284 = 0x2C;
        return 1;
    }
    return func_L39_0068AEF8(a0, a1) != 0;
}
/* localdecomp:end func_L39_006A03B0 */
