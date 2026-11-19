/* functional: high. 96 instructions differ (scheduling and branch layout); same calls, tests and stores. */
#include "vu0.h"
extern u8 D_L01_001EAA00[];
extern f32 D_L01_001DF00C_003CCED8;
extern f32 D_L01_001DF010_003CCED8;
__asm__(".extern D_L01_001DF00C_003CCED8, 4");
__asm__(".extern D_L01_001DF010_003CCED8, 4");
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
extern void func_L01_003CD248(void *, s32, s32, s32, void *);

void func_L01_003CCED8(u8 *obj, u8 *old_pos) {
    vu0_v4 v;
    u8 *st = *(u8 **)(obj + 0x68);
    s32 hit;
    u8 *p;
    f32 scale;
    func_L01_004CB320();
    hit = func_003D3CB0(old_pos, obj + 0x10, 0, obj, 0);
    if (hit) {
        p = *(u8 **)(D_L01_001EAA00 + 0x18);
        if (p && *(s16 *)(p + 0xAA) == 0x186D && p[0x20] != 2 && p[0x20] != 5) {
            p[0x20] = 4;
        }
    }
    func_L01_004CB358();
    if (!hit) return;
    p = *(u8 **)(D_L01_001EAA00 + 0x18);
    if (p) {
        if (p != *(u8 **)(st + 0x20) && (*(u16 *)(p + 0x34) & 0x4000)) {
            scale = D_L01_001DF00C_003CCED8;
            if (*(s32 *)(st + 0x24) == 0) scale = scale * 0.5f;
            func_0038CF68(&v, st, scale);
            v.z = D_L01_001DF010_003CCED8;
            v.w = 5627.9248046875f;
            func_L01_00446A70(*(u8 **)(D_L01_001EAA00 + 0x18), obj, 0x10001, obj + 0x10, &v, *(f32 *)(st + 0x1C));
            func_L01_003CD248(obj + 0x10, 0xA, 2, 1, obj);
        }
        if (*(u8 **)(D_L01_001EAA00 + 0x18)) {
            obj[0x20] = 2;
            return;
        }
    }
    func_L01_003CD248(obj + 0x10, 0xF, 5, 0, obj);
    obj[0x20] = 2;
}
