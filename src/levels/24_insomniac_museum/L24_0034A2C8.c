#include "common.h"

typedef struct { char b[28]; } B28;

INCLUDE_ASM("asm/levels", func_L24_0034A2C8);

INCLUDE_ASM("asm/levels", func_L24_0034AA48);

/* localdecomp:start func_L24_0034AE40 */
extern B28 D_L24_001DD358;
extern s32 D_L24_002B0FA0[];
extern s32 func_00381FF0(s32 a);
extern void func_003AF408(void *buf, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern void func_003A9440(s32, unsigned long);
extern void func_0038E138(void);

void func_L24_0034AE40(u8 *obj) {
    s32 *st = *(s32 **)(obj + 0x68);
    B28 buf = D_L24_001DD358;
    s32 r = func_00381FF0(D_L24_002B0FA0[*st]);
    func_003AF408(&buf, 0x80F0F0F0, r, 1, 0, -1, 0, 0, 0, 0);
    func_003A9440(0x47, 0x5360B);
    func_0038E138();
}
/* localdecomp:end func_L24_0034AE40 */

/* localdecomp:start func_L24_0034AF10 */
extern B28 D_L24_001DD378;
extern s32 D_L24_002B1000[];
__asm__(".extern D_001DD310_sda, 8");
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

/* localdecomp:start func_L24_0034B930 */
extern s32 func_L24_0034BA30(void *);
extern void func_L01_0044ABD0(void *, void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern f32 func_L01_004474E8(void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L24_0043C3B0(u8 *, s32, s32, s32, f32, f32);

s32 func_L24_0034B930(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    s32 r;
    s32 v;
    f32 f;

    if (obj[0x20] == 0) {
        if (func_L24_0034BA30(obj) != 0) {
            return 1;
        }
    }
    func_L01_0044ABD0(obj, s + 0x160);
    r = func_L01_00447490(obj, 0x10000, 0);
    v = func_0038CB00(s + 0x36);
    f = func_L01_004474E8(obj, v != 0 ? r : 0);
    obj[0xA8] = 0xFF;
    *(f32 *)(s + 0x30) = *(f32 *)(s + 0x30) - f;
    if (*(f32 *)(s + 0x30) <= 0.0f) {
        if (obj[0x43] != 3) {
            func_003C3A10(obj, 3, 0, 0x11);
        }
        func_L01_004450F0(obj, 0xE, 3);
    }
    func_L24_0043C3B0(obj, *(s32 *)(s + 0x4A0), 0, 0, 30.0f, 10.0f);
    return 0;
}
/* localdecomp:end func_L24_0034B930 */

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

/* localdecomp:start func_L24_0034BF38 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
extern void func_003C2EC0(char *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L24_0034C618(s32, s32, s32, void *, s32);

void func_L24_0034BF38(u8 *obj) {
    u8 buf[0x60];
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *p;
    s32 *q;
    s32 n;
    s32 m;
    u8 *p2;
    s32 *q2;

    p = s + 0x250;
    q = (s32 *)(s + 0x540);
    n = 3;
    do {
        func_003C2EC0((char *)q[0], 0, buf + 0x10);
        n--;
        func_0038CF68(buf, buf + 0x10, *(f32 *)(s + 0x584));
        vec_add_ab(p, buf, buf + 0x40);
        *(u128_t *)(p + 0x90) = *(u128_t *)p;
        *(u128_t *)(buf + 0x50) = *(u128_t *)p;
        p += 0x10;
        func_L24_0034C618(q[0], q[1], 0, buf + 0x50, 0);
        q++;
    } while (n >= 0);
    p2 = s + 0x380;
    q2 = (s32 *)(s + 0x560);
    m = 3;
    do {
        func_003C2EC0((char *)q2[0], 0, buf + 0x10);
        m--;
        func_0038CF68(buf, buf + 0x10, *(f32 *)(s + 0x584));
        vec_add_ab(p2, buf, buf + 0x40);
        *(u128_t *)(p2 + 0x90) = *(u128_t *)p2;
        *(u128_t *)(buf + 0x50) = *(u128_t *)p2;
        p2 += 0x10;
        func_L24_0034C618(q2[0], q2[1], 0, buf + 0x50, 0);
        q2++;
    } while (m >= 0);
}
/* localdecomp:end func_L24_0034BF38 */

INCLUDE_ASM("asm/levels", func_L24_0034C088);

INCLUDE_ASM("asm/levels", func_L24_0034C208);

INCLUDE_ASM("asm/levels", func_L24_0034C348);
