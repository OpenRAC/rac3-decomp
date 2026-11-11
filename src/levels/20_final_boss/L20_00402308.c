#include "common.h"

/* localdecomp:start func_L20_00402308 */
extern s32 D_L20_001D6694;
__asm__(".extern D_L20_001D6694, 16");
extern void func_L01_004AA7E8(void *, s32);

void func_L20_00402308(u8 *p) {
    if (D_L20_001D6694 == 2) {
        u8 *q = *(u8 **)(p + 0x24);
        u16 f = *(u16 *)(p + 0x34);

        f &= 0xFFBE;
        *(u16 *)(p + 0x34) = f;
        f |= *(u16 *)(q + 0x44) & 0x1000;
        *(u16 *)(p + 0x34) = f;
        *(s32 *)(p + 0x98) = *(s32 *)(q + 0x10);
    } else {
        u16 f = *(u16 *)(p + 0x34);

        *(s32 *)(p + 0x98) = 0;
        f = (f | 0x41) & 0xEFFF;
        *(u16 *)(p + 0x34) = f;
        func_L01_004AA7E8(p, 1);
    }
}
/* localdecomp:end func_L20_00402308 */

/* localdecomp:start func_L20_00402380 */
extern s32 D_L20_001D6694;
__asm__(".extern D_L20_001D6694, 16");
void func_L01_004AA7E8(void *, s32);

void func_L20_00402380(void *arg0) {
    if (D_L20_001D6694 == 2) {
        void *p = *(void **)((u8 *)arg0 + 0x24);
        u16 f = *(u16 *)((u8 *)arg0 + 0x34);
        f = f & 0xFFBE;
        *(u16 *)((u8 *)arg0 + 0x34) = f;
        f = f | (*(u16 *)((u8 *)p + 0x44) & 0x1000);
        *(u16 *)((u8 *)arg0 + 0x34) = f;
        *(s32 *)((u8 *)arg0 + 0x98) = *(s32 *)((u8 *)p + 0x10);
    } else {
        u16 f = *(u16 *)((u8 *)arg0 + 0x34);
        *(s32 *)((u8 *)arg0 + 0x98) = 0;
        f = (f | 0x41) & 0xEFFF;
        *(u16 *)((u8 *)arg0 + 0x34) = f;
        func_L01_004AA7E8(arg0, 1);
    }
}
/* localdecomp:end func_L20_00402380 */

/* localdecomp:start func_L20_004023F8 */
extern s32 D_L20_001D6694;
extern void func_L01_004AA7E8(void *, s32);
__asm__(".extern D_L20_001D6694, 16");

void func_L20_004023F8(u8 *arg0) {
    if (D_L20_001D6694 == 2) {
        u8 *p = *(u8 **)(arg0 + 0x24);
        u16 h = *(u16 *)(arg0 + 0x34);
        h &= 0xFFBE;
        *(u16 *)(arg0 + 0x34) = h;
        h |= *(u16 *)(p + 0x44) & 0x1000;
        *(u16 *)(arg0 + 0x34) = h;
        *(s32 *)(arg0 + 0x98) = *(s32 *)(p + 0x10);
    } else {
        u16 h = *(u16 *)(arg0 + 0x34);
        *(s32 *)(arg0 + 0x98) = 0;
        h = (h | 0x41) & 0xEFFF;
        *(u16 *)(arg0 + 0x34) = h;
        func_L01_004AA7E8(arg0, 1);
    }
}
/* localdecomp:end func_L20_004023F8 */

INCLUDE_ASM("asm/levels", func_L20_00402470);

INCLUDE_ASM("asm/levels", func_L20_004024E8);

/* localdecomp:start func_L20_00402598 */
typedef int u128_t __attribute__((mode(TI)));
void func_L01_00456160(void *, s32);
void func_0038CF68(void *, void *, f32);
f32 func_0038CEA8(void *);
f32 func_003824E0(f32, f32);
void func_L20_00402598(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *src = (u8 *)arg1;
    u8 *p;
    func_L01_00456160(obj, 0);
    *(u128_t *)(obj + 0x10) = *(u128_t *)src;
    p = *(u8 **)(obj + 0x68);
    *(u16 *)(p + 0x18) = *(u16 *)(src + 0x4C);
    *(u16 *)(p + 0x1A) = *(u16 *)(src + 0x4E);
    *(f32 *)(p + 0x14) = *(f32 *)(src + 0x24);
    *(s32 *)(p + 0x10) = *(s32 *)(src + 0x48);
    func_0038CF68(p, src + 0x10, *(f32 *)(src + 0x20));
    *(s32 *)(p + 0x1C) = 0;
    *(f32 *)(p + 0x20) = func_0038CEA8(p);
    *(f32 *)(p + 0x24) = *(f32 *)(p + 0x14) * func_003824E0(6.0f, 8.0f);
    if (-1.0f == *(f32 *)(src + 0x54)) {
        *(f32 *)(p + 0x2C) = *(f32 *)(src + 0x20) * 1.6f;
    } else {
        *(f32 *)(p + 0x2C) = *(f32 *)(src + 0x54);
    }
    *(s32 *)(obj + 0x98) = 0;
}
/* localdecomp:end func_L20_00402598 */
