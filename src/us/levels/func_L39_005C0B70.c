#include "common.h"

typedef struct {
    u8 pad0[4];
    s16 h4;
    u8 b6;
    u8 pad7[0x11];
    void (*f18)(s32, s32);
    s32 f1C;
} S_L39_005C0B70;

/* localdecomp:start func_L39_005C0B70 */
extern S_L39_005C0B70 D_002257E0;
extern s32 func_00194C30(void);
extern void func_001264E0(s32);

void func_L39_005C0B70(s32 a0) {
    S_L39_005C0B70 *p;
    void (*cb)(s32, s32);
    s32 data;
    s32 flag;

    if (a0 == 1) {
        p = &D_002257E0;
        if (p->h4 == 0) {
            p->f18 = 0;
            p->f1C = 0;
        } else if (func_00194C30() != 0) {
            p->h4 = 2;
        } else {
            func_001264E0(0);
            flag = p->b6 == 0;
            cb = p->f18;
            p->h4 = 0;
            p->b6 = 0;
            if (cb != 0) {
                data = p->f1C;
                p->f18 = 0;
                p->f1C = 0;
                cb(data, flag);
            }
        }
    }
}
/* localdecomp:end func_L39_005C0B70 */
