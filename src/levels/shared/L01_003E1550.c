#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_003E1550 */
extern void func_L01_004C8668(int);
extern void func_003C2880(void *);
void func_L01_003E1550(char *m)
{
    char *v = *(char **)(m + 104);
    if (v != 0) {
        func_L01_004C8668(*(int *)(v + 40));
    }
    func_003C2880(m);
}
/* localdecomp:end func_L01_003E1550 */

/* localdecomp:start func_L01_003E1590 */
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_00382580(void *, f32, f32);
extern void func_0038CE20(f32 *, f32 *, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CF68(f32 *, f32 *, f32);
extern void func_L01_00466F50(void *, void *, s32, f32, f32);
extern u8 *D_L01_002210F4[], *D_L01_0022123C[], *D_L01_00221120[];
void func_L01_003E1590(u8 *self) {
    vu0_v4 position, velocity, offset, direction;
    if (func_00382468(3) == 0) {
        s32 life, spin;
        u8 *p;
        func_00382580(&velocity, 0.035f, 0.05f);
        func_0038CE20((f32 *)&offset, (f32 *)&velocity, 10.0f);
        vec_add_ab(&position, &offset, self + 0x10);
        life = (func_00382498(10, 30) * 5 + 2) / 6;
        spin = func_00382498(-1, -3);
        p = func_L01_004713C8(&position, &velocity, life, 0x5A182, spin, 64, 0, 0, 126000.0078125f, 231000.0f, 0.009600000455975533f);
        if (p) {
            p[3] = func_00382468(2) ? 0x48 : 0x44;
            p[2] = *D_L01_002210F4[0];
        }
    }
    if (func_00382468(3) == 0) {
        s32 life, spin;
        u8 *p;
        func_00382580(&velocity, 0.01f, 0.04f);
        func_0038CE20((f32 *)&offset, (f32 *)&velocity, 10.0f);
        vec_add_ab(&position, &offset, self + 0x10);
        life = (func_00382498(10, 30) * 5 + 2) / 6;
        spin = func_00382498(-1, -3);
        p = func_L01_004713C8(&position, &velocity, life, 0x5A182, spin, 64, 0, 0, 105000.0f, 84000.0f, 0.009600000455975533f);
        if (p) {
            p[3] = func_00382468(2) ? 0x48 : 0x44;
            p[2] = *D_L01_0022123C[0];
        }
    }
    if (func_00382468(3) == 0) {
        s32 life, spin;
        u8 *p;
        func_00382580(&velocity, 0.01f, 0.03f);
        func_0038CE20((f32 *)&offset, (f32 *)&velocity, 10.0f);
        vec_add_ab(&position, &offset, self + 0x10);
        life = (func_00382498(10, 30) * 5 + 2) / 6;
        spin = func_00382498(-1, -3);
        p = func_L01_004713C8(&position, &velocity, life, 0x5A182, spin, 64, 0, 0, 84000.0f, 42000.0f, 0.009600000455975533f);
        if (p) {
            p[3] = func_00382468(2) ? 0x48 : 0x44;
            p[2] = *D_L01_00221120[0];
        }
    }
    if (func_00382468(3) == 0) {
        func_00382580(&velocity, 0.01f, 0.03f);
        func_0038CE20((f32 *)&offset, (f32 *)&velocity, 20.0f);
        vec_add_ab(&position, &offset, self + 0x10);
        func_L01_004C7D98(self + 0x10, &direction);
        func_0038CF68((f32 *)&direction, (f32 *)&direction, -func_003824E0(0.01f, 0.05f));
        func_L01_00466F50(&position, &direction, 0x4005A182, -1.0f, -0.006000000052154064f);
    }
}
/* localdecomp:end func_L01_003E1590 */

/* localdecomp:start func_L01_003E1990 */
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046B288(void *, u32, u32, f32, f32, s32);

void func_L01_003E1990(void *a0) {
    f32 ang;
    f32 a, b, c;
    s32 n;
    s32 i;
    u8 *e;
    f32 buf[4];

    i = 0;
    do {
        i--;
        ang = func_00382538();
        a = func_003824E0(0.0f, 0.6f);
        b = func_003824E0(0.0f, 1.75f);
        c = func_003824E0(2.0f, 5.0f);
        n = func_00382498(100, 160);
        buf[0] = func_0038D098(ang) * a;
        buf[1] = func_0038D0B0(ang) * a;
        buf[2] = 0.0f;
        vec_add_ba(buf, buf, a0);
        e = func_L01_0046B288(buf, 0x5005C162, 0x0005C162, b, c, n);
        if (e != 0) {
            e[3] = func_00382468(3) != 0 ? 0x48 : 0x44;
        }
    } while (i >= 0);
}
/* localdecomp:end func_L01_003E1990 */
