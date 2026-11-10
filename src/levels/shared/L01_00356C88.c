#include "common.h"

/* localdecomp:start func_L01_00356C88 */
void func_L01_00356C88(void) {

}
/* localdecomp:end func_L01_00356C88 */

/* localdecomp:start func_L01_00356C90 */
void func_L01_00356C90(void) {

}
/* localdecomp:end func_L01_00356C90 */

INCLUDE_ASM("asm/levels", func_L01_00356C98);

INCLUDE_ASM("asm/levels", func_L01_00357E70);

INCLUDE_ASM("asm/levels", func_L01_00358090);

INCLUDE_ASM("asm/levels", func_L01_00358238);

INCLUDE_ASM("asm/levels", func_L01_00358338);

INCLUDE_ASM("asm/levels", func_L01_003586F8);

/* localdecomp:start func_L01_003589B0 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

typedef struct {
    Vec4 v;
    u8 *o;
    s32 pad14;
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[20];
} S_357DC0;

extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_L01_00446760(S_357DC0 *s, u8 *o, s32 a, Vec4 *v, f32 f);
extern s32 func_003D3CB0(s32 a, s32 b, s32 c, u8 *o, S_357DC0 *s);
extern u8 D_001A4BE0[];

s32 func_L01_003589B0(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f12, f32 f13) {
    Vec4 v;
    S_357DC0 s;
    u8 *b;
    u8 *p;
    s32 r;

    if (*(u16 *)(a0 + 52) & 0x100) {
        v.q = *(u128_t *)(a0 + 192);
    } else {
        v.f[0] = func_0038D098(*(f32 *)(a0 + 248));
        v.f[1] = func_0038D0B0(*(f32 *)(a0 + 248));
        v.f[2] = 0.0f;
    }
    func_0038CE20(v.f, v.f, f13);
    v.f[2] = 1.0f;
    v.f[3] = 5627.9248046875f;
    func_L01_00446760(&s, a0, a3, &v, f12);
    b = D_001A4BE0;
    s.b18 = a4;
    s.b19 = a5;
    s.h1A = *(u16 *)(a0 + 170);
    s.o = a0;
    *(s32 *)(*(u8 **)(b + 9664) + 152) = 0;
    r = func_003D3CB0(a1, a2, a6, a0, &s);
    p = *(u8 **)(b + 9664);
    *(s32 *)(p + 152) = *(s32 *)(*(u8 **)(p + 36) + 16);
    return r;
}
/* localdecomp:end func_L01_003589B0 */

INCLUDE_ASM("asm/levels", func_L01_00358B00);

LINKER_REMNANT("asm/levels", func_L01_00359E08);

INCLUDE_ASM("asm/levels", func_L01_00359E10);

/* localdecomp:start func_L01_0035A190 */
void func_L01_0035A190(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0035A190 */

INCLUDE_ASM("asm/levels", func_L01_0035A218);

INCLUDE_ASM("asm/levels", func_L01_0035A6B0);

INCLUDE_ASM("asm/levels", func_L01_0035AB50);

INCLUDE_ASM("asm/levels", func_L01_0035ABB8);

INCLUDE_ASM("asm/levels", func_L01_0035AC28);

/* localdecomp:start func_L01_0035AEB8 */
extern u8 D_L01_00284500[];
extern void func_L01_004CAB30(void *, void *);
extern void func_L01_004482A0(f32 *, f32, f32 *, f32, f32, f32);
extern s32 func_0038CAD0(s32 *);

void func_L01_0035AEB8(void)
{
    int index, axis;
    char *record;
    float *position, *velocity, value, cur;

    char *base = (char *)D_L01_00284500;

    for (index = 0; index < 25; index++) {
        record = (char *)(index * 0x530 + (int)base);
        if (*(int *)(record + 0x514) != 1)
            continue;
        velocity = (float *)(record + 0x4f0);
        position = (float *)(record + 0x500);
        for (axis = 0; axis < 2; axis++) {
            func_L01_004CAB30(record + 0x20 + axis * 16, record + 0x20 + axis * 16);
            cur = position[axis];
            value = cur + velocity[axis];
            position[axis] = value;
            if (value <= -8.0f)
                position[axis] = value + 8.0f;
        }
        if (*(int *)(record + 0x518) == 0) {
            func_L01_004482A0((float *)(record + 0x510), 0.5f, (float *)(record + 0x51c), 0.0024f, 0.00024000001f, 0.024f);
            cur = *(float *)(record + 0x510);
            if (cur == 0.5f) {
                *(int *)(record + 0x518) = 2;
                *(int *)(record + 0x520) = 50;
            }
        } else if (*(int *)(record + 0x518) == 1) {
            func_L01_004482A0((float *)(record + 0x510), 0.0f, (float *)(record + 0x51c), 0.0024f, 0.00024000001f, 0.024f);
            cur = *(float *)(record + 0x510);
            if (cur == 0.0f)
                *(int *)(record + 0x514) = 0;
        } else if (func_0038CAD0((int *)(record + 0x520))) {
            *(int *)(record + 0x518) = 1;
        }
    }
}
/* localdecomp:end func_L01_0035AEB8 */

INCLUDE_ASM("asm/levels", func_L01_0035B0A0);

/* localdecomp:start func_L01_0035B5A0 */
typedef struct {
    f32 m[4][4];
    s32 c40, c44, c48, c4C;
    s32 x50, x54, x58;
    f32 x5C, x60;
    s32 x64;
    f32 x68, x6C;
    long x70, x78, x80, x88;
    f32 r[4][4];
    f32 rot[4];
} S_35A8A0;

extern void func_L01_0035AB50(S_35A8A0 *);
extern long func_00389598(s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(f32 *);
extern void func_0038D328(f32 *, f32 *);
extern void func_003D2DA0(S_35A8A0 *, f32 *, s32);

void func_L01_0035B5A0(s32 unused, f32 *pos, f32 *dir, s32 color, f32 scale) {
    S_35A8A0 s;

    func_L01_0035AB50(&s);
    s.x50 = 0;
    s.x5C = 1.0f;
    s.x60 = 1.0f;
    s.x68 = 1.0f;
    s.x6C = 1.0f;
    s.x54 = 0;
    s.x58 = 0;
    s.x64 = 0;
    s.x78 = func_00389598(11);
    s.x80 = 0xFF9000000260L;
    s.x88 = 0x8000000048L;
    s.x70 = 0;
    s.c4C = color;
    s.c48 = color;
    s.c44 = color;
    s.c40 = color;
    s.rot[3] = 0.0f;
    s.rot[2] = func_0038D160(dir[0], dir[1]);
    s.rot[1] = -func_0038D160(func_0038CED8(dir), dir[2]);
    s.rot[0] = 0.0f;
    func_0038D328(s.r[0], s.rot);
    s.r[3][3] = 1.0f;
    s.r[3][0] = pos[0];
    s.r[3][1] = pos[1];
    s.r[3][2] = pos[2];
    func_0038CE20(s.m[0], s.m[0], scale);
    func_0038CE20(s.m[1], s.m[1], scale);
    func_0038CE20(s.m[2], s.m[2], scale);
    func_0038CE20(s.m[3], s.m[3], scale);
    func_003D2DA0(&s, s.r[0], 0);
}
/* localdecomp:end func_L01_0035B5A0 */
