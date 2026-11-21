#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

/* localdecomp:start func_L31_003498F8 */
__asm__(".extern D_L31_001DD0AC, 4");
__asm__(".extern D_L31_001DD0F0, 4");
__asm__(".extern D_L31_001DD0F4, 4");
extern s32 D_L31_001DD0AC;
extern s32 D_L31_001DD0F0;
extern f32 D_L31_001DD0F4;
extern u8 D_L31_001E1290[];
extern void func_L31_00349D18(Obj_00349D18 *o, f32 *out1, f32 *out2, f32 t);
extern void func_0038D308(u8 *, u8 *);
extern void func_003C7DD8(u8 *);
extern s32 func_L30_0034D8D8(u8 *, f32);
extern void func_L30_0034C8A8(u8 *, u8 *);

void func_L31_003498F8(u8 *obj) {
    s32 i = 0;
    u8 *v = *(u8 **)(obj + 0x68);
    u8 **p;
    f32 *base;

    if (D_L31_001DD0AC > 0) {
        base = (f32 *)(v + 0x50);
        p = (u8 **)(v + 0x90);
        do {
            func_L31_00349D18((Obj_00349D18 *)obj, (f32 *)(*p + 0x10), (f32 *)(*p + 0xF0), *(f32 *)((u8 *)base + ((i * D_L31_001DD0F0 + D_L31_001DD0F0) << 2)));
            func_0038D308(*p + 0xC0, *p + 0xF0);
            (*p)[0x23] = (s32)(D_L31_001DD0F4 * (f32)(D_L31_001DD0AC - i) / (f32)(D_L31_001DD0AC + 1));
            i++;
            func_003C7DD8(*p);
            p++;
        } while (i < D_L31_001DD0AC);
    }
    if (func_L30_0034D8D8(obj + 0x10, 1.1f) != 0) {
        func_L30_0034C8A8(D_L31_001E1290, obj);
    }
}
/* localdecomp:end func_L31_003498F8 */
