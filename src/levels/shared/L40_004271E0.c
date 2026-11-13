#include "common.h"

/* localdecomp:start func_L40_004271E0 */
typedef struct {
    u8 pad0[0x1C];
    u8 (*f1C)(void *, s32);
} VT_004271E0;

typedef struct {
    u8 pad0[0x14];
    VT_004271E0 *vt;
} O_004271E0;

extern s32 D_L40_002499F4 __attribute__((section(".data")));
extern u8 *D_001D5F30_sda;
extern u8 *func_L39_0061D7B0(void *);
extern void *func_L01_00447490(void *, u32, s32);
extern f32 func_L01_004474E8(void *, void *);
extern O_004271E0 *func_L39_0061CEA0(void *);
extern void func_003C4A40(void *, void *);

void func_L40_004271E0(u8 *a0) {
    u8 *v;
    u8 *r;
    u8 *h;
    O_004271E0 *o;
    u8 ok;

    r = func_L39_0061D7B0(a0);
    v = *(u8 **)(a0 + 0x68);
    if (r == 0) {
        return;
    }
    if (*(s32 *)(r + 4) == D_L40_002499F4) {
        return;
    }
    h = func_L01_00447490(a0, 0x10000, 0);
    func_L01_004474E8(a0, h);
    if (h != 0 && *(void **)(h + 0x20) != 0 && *(s8 *)(D_001D5F30_sda + 0x18E) == 0) {
        o = func_L39_0061CEA0(*(void **)(h + 0x20));
        ok = *(s32 *)(v + 0x230) != 0 && *(s32 *)(v + 0x2A0) == 0;
        if (ok) {
            if (o != 0) {
                ok = o->vt->f1C(o, *(s32 *)(v + 0x27C)) ^ 1;
            }
            if (ok) {
                func_003C4A40(a0, v + 0x70);
            }
        }
    }
    *(u8 *)(a0 + 0xA8) = 0xFF;
}
/* localdecomp:end func_L40_004271E0 */
