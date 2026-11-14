#include "common.h"

/* NTSC-U counterpart of func_L19_003C2628 (src/levels/19_thran_asteroid_belt/L19_003C0938.c) */
#include "vu0.h"
extern void func_L19_003C07A0(void *, void *, int, float);

/* localdecomp:start func_L19_003C07A0 */
typedef struct { f32 x, y, z, w; } V_3C2628 __attribute__((aligned(16)));
__asm__(".extern D_L19_001DE840_003C07A0, 4");
__asm__(".extern D_L19_001DE880, 4");
__asm__(".extern D_L19_001DE848, 8");
__asm__(".extern D_L19_001DE860, 8");
extern s32 D_L19_001DE840_003C07A0;
extern f32 D_L19_001DE880;
extern f32 D_L19_001DE848[2];
extern f32 D_L19_001DE860[2];
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern s32 func_L01_00457708(void *, f32);
extern s32 func_L01_00458A08(void *, f32);
extern void func_L01_00457440(void *, void *);
extern void func_L01_00457728(void *, void *);

void func_L19_003C07A0(void *objp, void *a5, int state, float fv) {
    u8 *obj = objp;
    u8 *p = *(u8 **)(obj + 0x68);
    V_3C2628 v;
    f32 s;

    if (state != *(s32 *)(p + 0x418)) {
        if (state == 2)
            *(f32 *)(obj + 0x48) = D_L19_001DE880;
        if (D_L19_001DE840_003C07A0 != 0)
            *(f32 *)(obj + 0x48) = 0.1f;
        s = *(f32 *)(obj + 0x48);
        func_L01_00458A70(obj, D_L19_001DE860[state] * s, D_L19_001DE848[state] * s, s * 0.0034906587f, s * 0.104719765f);
        if (state == 3)
            *(s32 *)(p + 0xA8) = 0x514;
        else
            *(s32 *)(p + 0xA8) = 0;
    }
    *(s32 *)(p + 0x418) = state;
    switch (state) {
    case 0:
        func_L01_00457708(obj, fv);
        func_L01_00458A08(obj, fv);
        break;
    case 1:
    case 2:
        func_L01_00457440(obj, a5);
        break;
    case 3:
        v = *(V_3C2628 *)(p + 0x110);
        v.z = *(f32 *)(p + 0x448);
        *(f32 *)(p + 0x448) = *(f32 *)(p + 0x448) - (*(f32 *)(p + 0x9C) + *(f32 *)(p + 0x9C));
        func_L01_00457728(obj, &v);
        break;
    }
}
/* localdecomp:end func_L19_003C07A0 */
