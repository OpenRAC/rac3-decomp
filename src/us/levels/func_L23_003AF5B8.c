#include "common.h"
#include "vu0.h"
#include "structs/hero.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;

extern struct Hero D_001A4BE0;
extern s32 D_L23_001DECC0;
__asm__(".extern D_L23_001DECC0, 16");
extern void *func_L01_00447490(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00404808(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L03_0043FC00(void *, s32, u8 *, s32, s32, f32, f32, f32, f32, u8, f32, f32, s32, s32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2880(void *);

/* NTSC-U counterpart of func_L23_003B0EC0. */
/* localdecomp:start func_L23_003AF5B8 */
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 16");
extern u8 *D_L23_001E009C;
__asm__(".extern D_L23_001E009C, 16");
extern u8 *D_L23_001E0094;
__asm__(".extern D_L23_001E0094, 16");
extern u8 *D_L23_001E0094_003AF5B8;
__asm__(".extern D_L23_001E0094_003AF5B8, 4");
extern s16 D_L23_0023A440[];
extern f32 D_L23_001DE2E0_003AF5B8;
__asm__(".extern D_L23_001DE2E0_003AF5B8, 4");
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
void func_L23_003AFB10(void *arg0);

void func_L23_003AF5B8(u8 *self)
{
    u8 *v = *(u8 **)(self + 0x68);
    u8 *hit;
    u16 *p;
    u16 *q;
    u8 *m;
    u8 *e;
    f32 ang;
    V4 dir;
    f32 z;
    V4 b;
    V4 a;

    if (self[0x20] == 1) {
        hit = func_L01_00447490(self, -1, 0);
        if (hit != 0) {
            *(f32 *)(v + 8) -= *(f32 *)(hit + 0x2C);
            if (*(f32 *)(v + 8) <= 0.0f)
                func_L01_004450F0(self, 2, -1);
        }
        if ((D_L23_001DECC0 & 7) == (((s32)self >> 8) & 7)) {
            p = D_L23_001D6764[*(s32 *)v];
            while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[*(s32 *)v])) {
                m = D_L23_001E009C + ((*p & 0x7FFF) << 6);
                if (m == 0)
                    break;
                if (D_L23_0023A440[(D_L23_001E0094_003AF5B8 + ((*p & 0x7FFF) << 5))[0x1D]] == 0x1CCC &&
                    __builtin_fabsf(*(f32 *)(m + 0x38) - *(f32 *)(self + 0x18)) > 0.01f)
                    func_L01_004450F0(self, 2, -1);
                p++;
            }
        }
        func_L01_00404808(func_L23_003AFB10, self);
    }
    if (self[0x20] == 2) {
        ang = func_0038D160(*(f32 *)(self + 0x10) - D_001A4BE0.pos.x, *(f32 *)(self + 0x14) - D_001A4BE0.pos.y);
        dir.x = func_0038D098(ang) * 0.25f;
        dir.y = func_0038D0B0(ang) * 0.25f;
        dir.z = 0.0f;
        dir.w = 1.0f;
        z = dir.z;
        func_L03_0043FC00(self, 0xFF, (u8 *)&dir, 3, 3, z, 5.0f, z, 1.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 1.0f);
        q = D_L23_001D6764[*(s32 *)v];
        while (q != 0 && ((s16)q[-1] >= 0 || q == D_L23_001D6764[*(s32 *)v])) {
            e = D_L23_001E0094 + ((*q & 0x7FFF) << 5);
            if (e == 0)
                break;
            if (D_L23_0023A440[e[0x1D]] == 0x1CCC) {
                e[0x1E] |= 4;
                break;
            }
            q++;
        }
        qzero(&a);
        qzero(&b);
        a.z = D_L23_001DE2E0_003AF5B8;
        func_L02_003E2E38(self, &a, 5.0f, &b, 0x28, 0, 0, 0.33333334f, 2.0f, 10.0f, 1.0f);
        func_003A52A0(0, 0, self);
        func_003C2880(self);
    }
}
/* localdecomp:end func_L23_003AF5B8 */
