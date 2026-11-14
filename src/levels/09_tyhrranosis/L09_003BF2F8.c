#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L09_003BF2F8 */
extern u8 *D_L09_001E009C;
__asm__(".extern D_L09_001E009C, 16");
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C6FE0(void *);
extern void func_003C7C38(void *);
extern void func_0038D590(void *, void *);
extern void func_L01_00448E10(void *);
extern void func_003C7DD8(void *);

void func_L09_003BF2F8(u8 *a0) {
    u128_t buf[4];
    u8 *e = D_L09_001E009C + (*(s32 *)(*(u8 **)(a0 + 0x68) + 0xCD0) << 8);
    u8 *t;
    func_003C2EC0(a0, 1, buf);
    *(u128_t *)(e + 0x10) = buf[3];
    func_0038CE20(buf, buf, -1.0f);
    func_003C6FE0(e);
    if (!(*(u16 *)(e + 0x34) & 4))
        func_003C7C38(e);
    t = e + 0xC0;
    func_0038D590(t, buf);
    func_L01_00448E10(t);
    func_003C7DD8(e);
    if ((*(u16 *)(a0 + 0x34) & 1) && a0[0x95] == 0)
        *(u16 *)(e + 0x34) |= 0x41;
    else
        *(u16 *)(e + 0x34) &= 0xFFBE;
    *(u16 *)(e + 0x34) |= 4;
}
/* localdecomp:end func_L09_003BF2F8 */

INCLUDE_ASM("asm/levels", func_L09_003BF3E0);

INCLUDE_ASM("asm/levels", func_L09_003BF5F0);
