#include "common.h"

/* localdecomp:start func_L39_005A9068 */
typedef struct {
    s32 x0;
    s32 (*fn)(void);
} E_005A9068;

typedef struct {
    u8 pad0[0x24D9C];
    void (*fn24D9C)(void);
    u8 pad24DA0[0x24DBC - 0x24DA0];
    s32 (*fn24DBC)(void);
    E_005A9068 a[4];
    E_005A9068 b[3];
} S_005A9068;

extern s32 D_L39_0024BD18;
extern S_005A9068 *D_L39_00242A50;
extern s32 D_L39_00241128;
extern f32 D_L39_0025D6C0[];
extern void func_00397BE0(void);
extern void func_L39_005872D8(void);
extern void func_003AF628(void);

void func_L39_005A9068(void) {
    s32 r;
    s32 i;

    if (D_L39_0024BD18 != 0) {
        return;
    }
    if (D_L39_00242A50 != 0) {
        r = 0;
        func_00397BE0();
        if (D_L39_00242A50->fn24DBC != 0) {
            r = D_L39_00242A50->fn24DBC() != 0;
        }
        for (i = 0; i < 4; i++) {
            if (D_L39_00242A50->a[i].fn != 0) {
                r |= ((E_005A9068 *)((u8 *)D_L39_00242A50 + i * 8 + 0x24DC0))->fn();
            }
        }
        for (i = 0; i < 3; i++) {
            if (D_L39_00242A50->b[i].fn != 0) {
                r |= ((E_005A9068 *)((u8 *)D_L39_00242A50 + i * 8 + 0x24DE0))->fn();
            }
        }
        if (r != 0) {
            return;
        }
    }
    if (D_L39_00241128 == 0x11 || D_L39_00241128 == 0 || D_L39_00241128 == 5) {
        if (D_L39_00242A50 != 0) {
            f32 saved;
            D_L39_00242A50->fn24D9C();
            saved = D_L39_0025D6C0[44];
            D_L39_0025D6C0[44] = 0.62f;
            func_L39_005872D8();
            func_003AF628();
            D_L39_0025D6C0[44] = saved;
            func_L39_005872D8();
        }
    }
}
/* localdecomp:end func_L39_005A9068 */
