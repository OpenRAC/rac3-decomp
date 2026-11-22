#include "common.h"

/* localdecomp:start func_L41_0041B350 */
__asm__(".extern D_00241120, 16");
extern s32 *D_00241120;
extern s32 D_L41_002412DC;
__asm__(".extern D_L41_00247700, 4");
__asm__(".extern D_L41_002476FC, 4");
extern s32 D_L41_00247700;
extern s32 D_L41_002476FC;
extern u8 *D_L41_0029B21C[];
extern u8 *func_L01_004713C8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);
extern void func_L01_00443B88(f32 *, f32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_005B43C8(s32, s32);

void func_L41_0041B350(void *a0, s32 n, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6) {
    f32 v[4];
    s32 i;
    u8 *r;
    s32 c;
    f32 t;
    f32 k;

    s32 cnt = n;
    if (*D_00241120 >= 3) {
        cnt = n / 3;
    }
    n = cnt;
    i = 0;
    if (n > i) do {
        k = 0.020000001f;
        func_L01_00443B88(v, f3 * k, f4 * k);
        v[2] = func_L39_005B4410(f5, f6) * k;
        k = 0.0f;
        t = func_L39_005B4410(f1, f2);
        c = func_L39_005B4398(3) != 0 ? D_L41_00247700 : D_L41_002476FC;
        switch (D_L41_002412DC) {
        case 0x2A:
        case 0x34:
            c = func_L39_005B4398(3) != 0 ? 0x273538 : 0x263438;
            break;
        case 0x29:
        case 0x2D:
        case 0x33:
        case 0x37:
            c = func_L39_005B4398(3) != 0 ? 0x282720 : 0x272418;
            break;
        }
        r = func_L01_004713C8(a0, v, (func_L39_005B43C8(0x5A, 0x96) * 5 + 2) / 6, t * 210000.0f, c, -2, 0x7F, 0x7F, t * 210000.0f, f0 * 0.00040000002f, 0);
        if (r != 0) {
            u8 b = D_L41_0029B21C[0][func_L39_005B4398(3) + 0xA];
            r[3] = 0x44;
            r[2] = b;
        }
        i++;
    } while (i < n);
}
/* localdecomp:end func_L41_0041B350 */

/* localdecomp:start func_L41_0041B578 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) GeV4;
typedef struct { u8 pad0[0x2C]; f32 f2C; } GePart;
__asm__(".extern D_L41_0024824C, 4");
extern f32 D_L41_0024824C;
extern f32 func_L39_005B44C8(void);
extern void func_00382760(GeV4 *, f32, f32, f32);
extern GePart *func_L01_003298C8(void *, GeV4 *, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32);
void func_L41_0041B578(void *a0, f32 scale, f32 lo, f32 hi) {
    GeV4 v;
    GePart *p;
    s32 flag;
    f32 r;
    f32 a;

    if (*D_00241120 >= 3) {
        return;
    }
    flag = 0;
    r = func_L39_005B4410(10.0f, 20.0f) * 0.020000001f * scale;
    a = func_L39_005B44C8();
    func_00382760(&v, r, a, func_L39_005B4410(0.43633232f, 0.7853982f));
    if (func_L39_005B4398(3) != 0 && D_L41_0024824C < 0.8f) {
        flag = 1;
    }
    p = func_L01_003298C8(a0, &v, func_L39_005B43C8(100, 125), 3, flag, 0x80808080, 0, 1, 0x32, 0x78, 1.0f, 14.6f);
    if (p != 0) {
        p->f2C *= func_L39_005B4410(lo, hi);
    }
}
/* localdecomp:end func_L41_0041B578 */

/* localdecomp:start func_L41_0041B6F0 */
typedef int u128_41B6F0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_41B6F0;

extern f32 func_L39_005B4410(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_005C5FC8(void *, void *, s32, s32, s32, s32, s32, s32);

extern s32 D_L01_001DC020;
__asm__(".extern D_L01_001DC020, 4");
extern f32 D_L01_001DC024;
__asm__(".extern D_L01_001DC024, 4");
extern f32 D_L01_001DC028;
__asm__(".extern D_L01_001DC028, 4");
extern f32 D_L01_001DC02C;
__asm__(".extern D_L01_001DC02C, 4");
extern f32 D_L01_001DC030;
__asm__(".extern D_L01_001DC030, 4");
extern f32 D_L01_001DC034;
__asm__(".extern D_L01_001DC034, 4");
extern s32 D_L01_001DC014;
__asm__(".extern D_L01_001DC014, 4");
extern s32 D_L01_001DC018;
__asm__(".extern D_L01_001DC018, 4");
extern s32 D_L01_001DC01C;
__asm__(".extern D_L01_001DC01C, 4");

extern s32 *D_00241120;
extern s32 D_L41_002412DC;
void func_L41_0041B6F0(void *a0) {
    V4_41B6F0 out;
    V4_41B6F0 tmp;
    s32 i;
    s32 n;
    s32 flag;
    s32 ca;
    s32 cb;

    flag = 0;
    if (D_L41_002412DC == 0x2D || D_L41_002412DC == 0x37) {
        ca = 0x7FE9D09F;
        cb = 0xE9D09F;
        flag = 1;
    } else {
        ca = 0x7F325C66;
        cb = 0x4C6C74;
    }
    n = D_L01_001DC020;
    if (*D_00241120 >= 3) {
        n = n / 5;
    }
    for (i = 0; i < n; i++) {
        if (flag == 0 || (i & 1) != 0) {
            *(u128_41B6F0 *)&tmp = 0;
            tmp.x = func_L39_005B4410(D_L01_001DC028, D_L01_001DC02C);
            tmp.y = func_L39_005B4410(D_L01_001DC028, D_L01_001DC02C);
            tmp.z = func_L39_005B4410(D_L01_001DC030, D_L01_001DC034);
            *(u128_41B6F0 *)&out = *(u128_41B6F0 *)&tmp;
            func_0038CF68(&out, &out, D_L01_001DC024 * 0.020000001f);
            func_L39_005C5FC8(a0, &out, ca, cb, D_L01_001DC014, D_L01_001DC018, D_L01_001DC01C, 0);
        }
    }
}
/* localdecomp:end func_L41_0041B6F0 */
