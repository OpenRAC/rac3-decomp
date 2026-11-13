#include "common.h"

/* declared by functions of L39_006BA5C0.c, which this file was cut from */
void func_L39_006CC158(void *, s32);

/* localdecomp:start func_L39_006BDCF0 */
extern s32 D_L39_0024D76C;
extern s32 D_L39_0024D768;
extern u8 D_L39_003D2680[];
extern s32 D_001E205C_sda;

struct O_006BDCF0;
typedef struct {
    u8 pad0[0x28];
    void (*f28)(struct O_006BDCF0 *, f32, f32);
    u8 pad2c[0x6C - 0x2C];
    s32 (*f6C)(struct O_006BDCF0 *, s32, void *);
    u8 pad70[0x78 - 0x70];
    s32 (*f78)(struct O_006BDCF0 *);
    u8 pad7c[0x88 - 0x7C];
    void (*f88)(struct O_006BDCF0 *, s32);
    s32 (*f8C)(struct O_006BDCF0 *);
} V_006BDCF0;
typedef struct O_006BDCF0 {
    u8 pad[0x60];
    V_006BDCF0 *vt;
} O_006BDCF0;
typedef struct {
    u8 pad[0x11C];
    O_006BDCF0 *obj;
} A_006BDCF0;

void func_L39_006BDCF0(A_006BDCF0 *arg0) {
    s32 cur, n, t;

    if (D_L39_0024D76C > 0) {
        cur = arg0->obj->vt->f8C(arg0->obj);
        n = arg0->obj->vt->f78(arg0->obj);
        if (cur == n - 1) {
            cur += D_001E205C_sda;
            if (cur >= 0x80) {
                cur = 0x7F;
            }
        } else {
            t = n + D_001E205C_sda;
            if (t > 0x80) {
                cur += 0x80 - t;
            }
        }
        if (cur < 0) {
            cur = 0;
        }
        arg0->obj->vt->f6C(arg0->obj, D_L39_0024D768, D_L39_003D2680);
        arg0->obj->vt->f88(arg0->obj, cur);
        arg0->obj->vt->f28(arg0->obj, 0.31f, 0.44f);
        D_L39_0024D76C = 0;
    }
}
/* localdecomp:end func_L39_006BDCF0 */
