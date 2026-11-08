#include "common.h"

typedef struct { char b[28]; } B28;

INCLUDE_ASM("asm/levels", func_L24_0034A2C8);

INCLUDE_ASM("asm/levels", func_L24_0034AA48);

INCLUDE_ASM("asm/levels", func_L24_0034AE40);

/* localdecomp:start func_L24_0034AF10 */
extern B28 D_L24_001DD378;
extern s32 D_L24_002B1000[];
extern s32 D_001DD310_sda[2];
extern s32 func_00381FF0(s32 a);
extern void func_003AF408(void *buf, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern void func_003A9440(s32, unsigned long);
extern void func_0038E138(void);

void func_L24_0034AF10(u8 *obj) {
    s32 *q = D_001DD310_sda;
    s32 v = D_L24_002B1000[**(s32 **)(obj + 0x68)];
    B28 buf = D_L24_001DD378;
    s32 r = func_00381FF0(q[v]);
    func_003AF408(&buf, 0x80F0F0F0, r, 1, 0, -1, 0, 0, 0, 0);
    func_003A9440(0x47, 0x5360B);
    func_0038E138();
}
/* localdecomp:end func_L24_0034AF10 */

INCLUDE_ASM("asm/levels", func_L24_0034AFF0);

INCLUDE_ASM("asm/levels", func_L24_0034B930);

INCLUDE_ASM("asm/levels", func_L24_0034BA30);

/* localdecomp:start func_L24_0034BBD8 */
void func_L01_004443E8(s32, s32, s32);
void func_L01_00315900(s32, s32, s32);

void func_L24_0034BBD8(void *arg0) {
    s32 *p;
    s32 *base;
    s32 n;

    base = *(s32 **)((u8 *)arg0 + 0x68);
    func_L01_004443E8((s32)arg0, 0, 3);
    p = (s32 *)((u8 *)base + 0x560);
    n = 4;
    do {
        func_L01_00315900(p[-8], 0, 0);
        n--;
        func_L01_00315900(p[0], 0, 0);
        p++;
    } while (n >= 0);
}
/* localdecomp:end func_L24_0034BBD8 */

INCLUDE_ASM("asm/levels", func_L24_0034BC48);

INCLUDE_ASM("asm/levels", func_L24_0034BF38);

INCLUDE_ASM("asm/levels", func_L24_0034C088);

INCLUDE_ASM("asm/levels", func_L24_0034C208);

INCLUDE_ASM("asm/levels", func_L24_0034C348);

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
