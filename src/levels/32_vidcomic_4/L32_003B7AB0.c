#include "common.h"

/* declared by functions of L32_003B5828.c, which this file was cut from */
extern void func_L01_004450F0(void *, s32, s32);
s32 func_003A52A0(s32, s32, void *);
void func_L01_004450F0(void *, s32, s32);

/* localdecomp:start func_L32_003B7AB0 */
typedef struct {
    f32 f0;
    u8 pad4[0x3C];
    u8 f40[7];
    u8 f47;
    u8 pad48[0x2C];
    s32 f74;
} V_003B7AB0;

typedef struct {
    u8 pad0[0x2C];
    f32 f2C;
} H_003B7AB0;

extern s32 func_0038CAD0(void *);
extern void func_L01_0044ABD0(void *, void *);
extern s32 func_L30_0034D8D8(void *, f32);
extern void func_L32_0034B5A8(void *);
extern H_003B7AB0 *func_L01_00447490(void *, s32, s32);
extern void func_003C4A40(void *, void *);
extern s32 func_003A52A0(s32, s32, void *);

void func_L32_003B7AB0(u8 *a0) {
    V_003B7AB0 *v = *(V_003B7AB0 **)(a0 + 0x68);
    H_003B7AB0 *h;

    func_0038CAD0(&v->f74);
    func_L01_0044ABD0(a0, v->f40);
    if (func_L30_0034D8D8(a0 + 0x10, 1.0f) && a0[0x20] != 0x42) {
        func_L32_0034B5A8(a0);
    }
    h = func_L01_00447490(a0, 0x10000, 0);
    if (h != 0) {
        a0[0xA8] = 0xFF;
        if (h->f2C > 0.0f && a0[0x20] != 0x42 && v->f74 == 0) {
            v->f47 = 0xFF;
            func_003C4A40(a0, v->f40);
            v->f0 -= h->f2C;
            v->f74 = 12;
            if (v->f0 <= 0.0f) {
                func_003A52A0(2, 0, a0);
                func_L01_004450F0(a0, 0x42, -1);
            } else {
                func_003A52A0(1, 0, a0);
            }
        }
    }
}
/* localdecomp:end func_L32_003B7AB0 */
