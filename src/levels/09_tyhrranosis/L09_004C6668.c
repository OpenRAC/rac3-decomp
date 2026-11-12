#include "common.h"

/* localdecomp:start func_L09_004C6668 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 D_0016C580[];
extern void func_0038D308(void *, void *);
extern void func_003C6680(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void func_003C7C38(void *);
extern void func_0038D570(void *, void *);
extern s32 D_L09_001D98C0;
extern s32 D_001D9880;
extern s32 D_L09_001D9890;
extern s32 D_001D98A0;
extern s32 D_L09_001D98B0;
extern s32 D_L09_001D9870;
extern s32 D_L09_001D98D0;
extern f32 D_001D98E0;
extern u8 D_L09_00239C40[];

void func_L09_004C6668(u8 *a0, f32 f, s32 a1, s32 a2, s32 a3) {
    u128_t v;

    *(u128_t *)(*(u8 **)D_0016C580 + 0x10) = *(u128_t *)a0;
    *(f32 *)(*(u8 **)D_0016C580 + 0xF8) = f;
    func_0038D308(*(u8 **)D_0016C580 + 0xC0, *(u8 **)D_0016C580 + 0xF0);
    D_001D98E0 = *(f32 *)(*(u8 **)D_0016C580 + 0x18);
    func_003C6680(*(u8 **)D_0016C580, D_L09_00239C40, 0, 0, &D_001D98A0, &D_L09_001D98B0,
                  &D_L09_001D9870, &D_L09_001D98D0, &D_L09_001D98C0, &D_001D9880, &D_L09_001D9890);
    func_003C7C38(*(u8 **)D_0016C580);
    func_0038D570(D_0016C580 + 0xD0, *(u8 **)D_0016C580 + 0xC0);
    v = *(u128_t *)(*(u8 **)D_0016C580 + 0x10);
    *(s32 *)(D_0016C580 + 0x48) = a3;
    *(s32 *)(D_0016C580 + 0x40) = a1;
    *(s32 *)(D_0016C580 + 0x44) = a2;
    *(u128_t *)(D_0016C580 + 0x100) = v;
}
/* localdecomp:end func_L09_004C6668 */
