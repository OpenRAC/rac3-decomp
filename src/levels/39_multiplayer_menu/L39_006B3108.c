#include "common.h"

/* declared by functions of L39_006B2120.c, which this file was cut from */
extern s32 *D_L39_00247914;

/* localdecomp:start func_L39_006B3108 */
typedef struct O_006B3108 O_006B3108;
typedef struct {
    u8 pad0[0x1C];
    void (*f1C)(O_006B3108 *, s32, s32);
    u8 pad20[0x28 - 0x20];
    void (*f28)(O_006B3108 *, f32, f32);
    u8 pad2C[0x48 - 0x2C];
    void (*f48)(O_006B3108 *, s32, s32);
    void (*f4C)(O_006B3108 *, s32, s32);
} V_006B3108;
struct O_006B3108 {
    u8 pad0[0x60];
    V_006B3108 *vt;
};
typedef struct {
    u8 pad0[0x110];
    O_006B3108 *f110;
    O_006B3108 *f114;
    u8 pad118[0x290 - 0x118];
    s32 f290;
    u8 pad294[0x2A8 - 0x294];
    s32 f2A8;
    s32 f2AC;
} S_006B3108;
__asm__(".extern D_L39_00247914, 16");
extern s32 *D_L39_00247914;
s32 func_L39_0068AEF8(void *, s32);
void func_L39_0068A4A8(void *, s32, s32, f32, f32, f32, f32, s32);

s32 func_L39_006B3108(S_006B3108 *this, s32 arg1) {
    f32 x;

    if (func_L39_0068AEF8(this, arg1) == 1) {
        return 1;
    }
    if (arg1 == 7) {
        s32 r = 0;
        if (this->f290 == 2) {
            this->f2A8 = 1;
            r = 1;
        } else if (this->f290 == 3) {
            this->f2A8 = 2;
            r = 1;
        }
        if (r == 1) {
            D_L39_00247914[0x284 / 4] = 0x2C;
            return 1;
        }
    } else if (arg1 == 5) {
        if (this->f2AC >= 2) {
            return 1;
        }
    }
    x = 0.3f;
    this->f110->vt->f1C(this->f110, 1, 0);
    this->f110->vt->f4C(this->f110, 0x40, 1);
    this->f110->vt->f48(this->f110, 3, 3);
    this->f110->vt->f28(this->f110, 0.5f, x);
    this->f114->vt->f28(this->f114, 0.502f, 0.705f);
    func_L39_0068A4A8(this, 0, 1, x, x, 0.0f, x, 0x332299DE);
    return 0;
}
/* localdecomp:end func_L39_006B3108 */
