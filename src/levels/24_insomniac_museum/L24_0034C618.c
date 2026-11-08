#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L24_0034C618 */
extern void func_003C2EC0(char *, s32, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C6FE0(char *);
extern void func_003C7C38(char *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_0038D308(void *, void *);
extern void func_003C7DD8(char *);

void func_L24_0034C618(char *a0, char *a1, s32 a2, u128_t *a3, s32 flags)
{
    u128_t w[5];
    f32 *v = (f32 *)w;
    f32 dist;
    char *pp;

    w[0] = *a3;
    func_003C2EC0(a0, a2, &v[4]);
    pp = a1 + 0x10;
    *(u128_t *)(a1 + 0x10) = w[0];
    if (flags & 1) {
        func_0038CE20(&v[4], &v[4], -1.0f);
    }
    if (flags & 2) {
        func_0038CE20(&v[8], &v[8], -1.0f);
    }
    if (flags & 4) {
        func_0038CE20(&v[12], &v[12], -1.0f);
    }
    func_003C6FE0(a1);
    if ((*(u16 *)(a1 + 0x34) & 4) == 0) {
        func_003C7C38(a1);
    }
    *(f32 *)(a1 + 0xF8) = func_0038D160(v[16] - *(f32 *)(a1 + 0x10), v[17] - *(f32 *)(a1 + 0x14));
    *(f32 *)(a1 + 0xF8) = func_0038DAB8(*(f32 *)(a1 + 0xF8), 3.1415927f);
    dist = func_0038CF38(pp, &v[16]);
    *(f32 *)(a1 + 0xF4) = func_0038D160(dist, v[18] - *(f32 *)(a1 + 0x18));
    *(f32 *)(a1 + 0xF0) = 1.5707964f;
    func_0038D308(a1 + 0xC0, a1 + 0xF0);
    func_003C7DD8(a1);
    if (*(u16 *)(a0 + 0x34) & 1) {
        *(u16 *)(a1 + 0x34) |= 0x41;
    } else {
        *(u16 *)(a1 + 0x34) &= 0xFFBE;
    }
    *(u16 *)(a1 + 0x34) |= 6;
}
/* localdecomp:end func_L24_0034C618 */

INCLUDE_ASM("asm/levels", func_L24_0034C7A8);

INCLUDE_ASM("asm/levels", func_L24_0034C8D0);

/* localdecomp:start func_L24_0034CCA0 */
void func_0038CAD0(s32);
void func_0038CB00(s32);

void func_L24_0034CCA0(void *arg0) {
    s32 temp_s0;
    u16 temp_v1;

    temp_s0 = *(s32 *)((u8 *)arg0 + 0x68);
    func_0038CAD0(temp_s0 + 0x4B0);
    func_0038CB00(temp_s0 + 0x4B4);
    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
}
/* localdecomp:end func_L24_0034CCA0 */
