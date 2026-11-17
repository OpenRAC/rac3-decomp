#include "common.h"
#include "vu0.h"

__asm__(".extern D_L03_001DC4B0, 4");

/* localdecomp:start func_L03_00300AD8 */
extern s32 D_L01_001D6694;
extern s32 D_L01_001D673C;
extern s32 D_001A71A4[];
extern u8 D_001BBC40[];
extern s32 D_001D545C;
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 4");
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern void func_L03_003DA010(s32);
extern void func_L01_00451290(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, s32);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L03_003DA148(s32, void *);
extern s32 func_L03_003F6A80(void *, void *, void *, s32, s32);
extern s32 func_L01_00459590(void *, void *, f32);
extern void func_L01_004048D0_00300AD8(void *, void *);
extern void func_L03_00300DA0(u8 *);
extern void func_L03_00300F50(u8 *);

void func_L03_00300AD8(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    vu0_v4 tmp;
    vu0_v4 mat[3];
    u8 *e;
    s32 a;
    s32 b;
    u16 h;
    s16 id;
    if (D_L01_001D6694 == 2) {
        return;
    }
    switch (m[0x20]) {
    case 0:
        h = *(u16 *)(m + 0x34) | 0x1000;
        *(u16 *)(m + 0x34) = h;
        a = *(s32 *)(v + 0x30);
        if (a == -1) {
            s32 c = *(s32 *)(v + 0x3C);
            if (c == a) goto init;
            e = D_L03_001DF99C + (c << 8);
            if (e == 0 || e[0x20] == 0xFE || e[0x20] == 0xFD) goto init;
        }
        m[0x30] = 0xFF;
        *(u16 *)(m + 0x34) = h | 0x41;
        m[0x20] = 2;
        break;
    init:
        func_L01_0043B9E8(m, 0xC0, 0xC0, 0xC0);
        func_L03_003DA010(0);
        if (D_L01_001D673C != 0) {
            *(u16 *)(m + 0x34) |= 0x100;
            func_L01_00451290(m, &tmp, 1);
            func_L01_004515D8(m + 0xC0, &tmp, 0);
        }
        m[0x20] = 1;
        break;
    case 1:
        id = *(s16 *)(m + 0xAA);
        if (id == 0x323 || id == 0x19C4 || id == 0x2F6) {
            if (D_L01_001D673C != 0) {
                qzero(&tmp);
                tmp.z = 0.0628318563f;
                func_0038D308(mat, &tmp);
                func_0038D5F0(m + 0xC0, m + 0xC0, mat);
            } else {
                *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), 0.0628318563f);
            }
        }
        if (D_001A71A4[0] != 0x2B) {
            func_L03_003DA148(0, m);
        }
        break;
    case 2:
        if (D_001BBC40[*(s32 *)(v + 0x30) + D_001D545C * 16] == 0) {
            b = *(s32 *)(v + 0x3C);
            if (b == -1) break;
            e = D_L03_001DF99C + (b << 8);
            if (e != 0 && e[0x20] != 0xFE && e[0x20] != 0xFD) break;
        }
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x1000) & 0xFFBE;
        func_L03_003F6A80(m, m + 0x10, m + 0xF0, 0, 0);
        *(s32 *)(v + 0x30) = -1;
        m[0x20] = 0;
        break;
    }
    *(vu0_q *)&tmp = *(vu0_q *)(m + 0x10);
    tmp.w = 2.0f;
    if (func_L01_00459590(&tmp, 0, 64.0f) > 0) {
        if (*(s16 *)(m + 0xAA) != 0x2F6) {
            func_L01_004048D0_00300AD8(func_L03_00300DA0, m);
        } else {
            func_L01_004048D0_00300AD8(func_L03_00300F50, m);
        }
    }
}
/* localdecomp:end func_L03_00300AD8 */

/* localdecomp:start func_L03_00300DA0 */
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038D328(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D9740(void *, s32, s32, s32, s32, f32);
extern s32 D_L03_001DC4B0;

void func_L03_00300DA0(u8 *m) {
    vu0_v4 mat[4];
    vu0_v4 rot;
    vu0_v4 dir;
    u8 *v = *(u8 **)(m + 0x68);
    f32 t;
    if (v == 0 || m[0x31] == 0) {
        return;
    }
    t = *(f32 *)(v + 0x40) + 0.1f;
    *(f32 *)(v + 0x40) = t;
    if (t >= 7.0f) {
        *(f32 *)(v + 0x40) = t - 7.0f;
    }
    *(vu0_q *)&dir = *(vu0_q *)(m + 0xD0);
    rot.x = 0.0f;
    rot.y = -func_0038D160(func_0038CED8(&dir), dir.z) + -1.5707964f;
    rot.z = func_0038D160(dir.x, dir.y);
    rot.w = 1.0f;
    func_0038D328(mat, &rot);
    func_0038CE20(&dir, &dir, 2.5f);
    vec_add_ba(&mat[3], m + 0x10, &dir);
    func_0038CE20(&mat[2], &mat[2], 2.5f);
    func_003D9740(mat, D_L03_001DC4B0, 0x80084010, 5, 1, *(f32 *)(v + 0x40));
    func_0038CE20(&mat[2], &mat[2], -1.0f);
    *(vu0_q *)&dir = *(vu0_q *)(m + 0xD0);
    func_0038CE20(&dir, &dir, -2.5f);
    vec_add_ab(&mat[3], m + 0x10, &dir);
    func_003D9740(mat, D_L03_001DC4B0, 0x80084010, 5, 1, *(f32 *)(v + 0x40));
}
/* localdecomp:end func_L03_00300DA0 */

/* localdecomp:start func_L03_00300F50 */
__asm__(".extern D_L03_001DC4B4, 4");
extern f32 D_L03_001DC4B4;

void func_L03_00300F50(u8 *m) {
    vu0_v4 mat[4];
    vu0_v4 rot;
    vu0_v4 dir;
    u8 *v = *(u8 **)(m + 0x68);
    f32 t;
    if (v == 0 || m[0x31] == 0) {
        return;
    }
    t = *(f32 *)(v + 0x40) + 0.1f;
    *(f32 *)(v + 0x40) = t;
    if (t >= 7.0f) {
        *(f32 *)(v + 0x40) = t - 7.0f;
    }
    *(vu0_q *)&dir = *(vu0_q *)(m + 0xD0);
    rot.x = 0.0f;
    rot.y = -func_0038D160(func_0038CED8(&dir), dir.z) + -1.5707964f;
    rot.z = func_0038D160(dir.x, dir.y);
    rot.w = 1.0f;
    func_0038D328(mat, &rot);
    func_0038CE20(&dir, &dir, D_L03_001DC4B4);
    *(vu0_q *)&mat[3] = *(vu0_q *)(m + 0x10);
    func_0038CE20(&mat[2], &mat[2], D_L03_001DC4B4);
    func_003D9740(mat, D_L03_001DC4B0, 0x80084010, 10, 1, *(f32 *)(v + 0x40));
}
/* localdecomp:end func_L03_00300F50 */
