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

INCLUDE_ASM("asm/levels", func_L01_003E1590);

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
