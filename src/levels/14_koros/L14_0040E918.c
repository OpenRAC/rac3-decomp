#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L14_0040E918 */
extern vu0_v4 D_L14_001E20C0;
extern void func_003C4098(void *, void *, void *, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
void func_L14_0040E918(u8 *p) {
    vu0_v4 off;
    vu0_v4 out;
    vu0_v4 a;
    vu0_v4 b;
    *(vu0_q *)&off = 0;
    off.y = 2.0f;
    off.z = 6.0f;
    if (p != 0) {
        a = D_L14_001E20C0;
        b = *(vu0_v4 *)(p + 0x10);
        func_003C4098(&out, &a, &b, 0.5f);
        vec_add_ab(&out, &out, &off);
        func_003D9508(&out, 0xB, 0x30406080, 1, 15.0f, 0.08f, 0.0f);
    }
}
/* localdecomp:end func_L14_0040E918 */

/* localdecomp:start func_L14_0040E9D0 */
extern int D_L14_001EEC50[];

int func_L14_0040E9D0(void)
{
    int i;
    int *base = D_L14_001EEC50;
    int *p = base + 4;
    for (i = 0; i < 0x28; i++) {
        if (*p <= 0)
            return i;
        p += 8;
    }
    return -1;
}
/* localdecomp:end func_L14_0040E9D0 */

/* localdecomp:start func_L14_0040EA08 */
extern s32 D_L14_001E64B4[];
extern u8 D_L14_001EF150[];
void func_L14_0040EA08(void) {
    s32 i;
    u8 *p;
    u8 *base;
    if (D_L14_001E64B4[0] == 1) {
        p = (u8 *)D_L14_001EEC50;
        for (i = 39; i >= 0; i--) {
            qzero(p);
            *(s32 *)(p + 0x10) = 0;
            p += 0x20;
        }
        base = D_L14_001EF150;
        for (i = 0; i < 14; i++) {
            p = base + i * 0x30;
            qzero(p);
            qzero(p + 0x10);
            *(s32 *)(p + 0x24) = 0;
        }
    }
}
/* localdecomp:end func_L14_0040EA08 */

/* localdecomp:start func_L14_0040EA78 */
typedef struct {
    u8 pad[0x34];
    s32 f34;
} S_40EA78;
extern S_40EA78 D_L14_001E6480;
extern vu0_v4 D_L14_001D66B0 __attribute__((section(".sdata")));
extern vu0_v4 D_L14_001E20E0;
__asm__(".extern D_L14_001D6BC0, 4");
__asm__(".extern D_L14_001D6BC4, 4");
__asm__(".extern D_L14_001D6BC8, 4");
__asm__(".extern D_L14_001D6BD0, 4");
__asm__(".extern D_L14_001D6C18, 4");
extern s32 D_L14_001D6BC0;
extern s32 D_L14_001D6BC4;
extern s32 D_L14_001D6BC8;
extern f32 D_L14_001D6BD0;
extern s32 D_L14_001D6C18;
extern void func_0038D570(void *, void *);
extern void func_L14_003F9A10(void *, void *, f32);
extern void func_003D9740(void *, s32, s32, s32, s32, f32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
void func_L14_0040EA78(void) {
    vu0_v4 m[4];
    vu0_v4 a;
    vu0_v4 b;
    u8 *p;
    u8 *q;
    u8 *end;
    s32 i;
    s32 c;
    f32 t;
    p = (u8 *)D_L14_001EEC50;
    for (i = 39; i >= 0; i--) {
        if (*(s32 *)(p + 0x10) >= 0) {
            func_0038D570(m, &D_L14_001E20E0);
            m[3] = D_L14_001D66B0;
            func_L14_003F9A10(m, m, *(f32 *)(p + 0xC));
            c = D_L14_001D6BC4;
            t = (f32)*(s32 *)(p + 0x10) / (f32)D_L14_001D6BC8;
            m[3] = *(vu0_v4 *)p;
            func_003D9740(m, D_L14_001D6BC0, ((s32)(t * 0.6f * (f32)c) << 24) | (c << 16) | (c << 8) | c, 10, 1, 0.0f);
            *(f32 *)(p + 0xC) += t * D_L14_001D6BD0;
            *(s32 *)(p + 0x10) -= 1;
        }
        p += 0x20;
    }
    if (D_L14_001E6480.f34 < 0x466) {
        for (i = 0; i < 14; i++) {
            q = D_L14_001EF150 + i * 0x30;
            if (*(s32 *)(q + 0x24) >= 0) {
                a = *(vu0_v4 *)q;
                b = *(vu0_v4 *)(q + 0x10);
                func_L01_0040A8C0(&a, &b, 0x16, 1, D_L14_001D6C18, D_L14_001D6C18, 0, 0, *(f32 *)(q + 0x20), 2.0f, 0.0f);
                *(f32 *)(q + 0x20) += 0.008f;
            }
        }
    }
}
/* localdecomp:end func_L14_0040EA78 */

INCLUDE_ASM("asm/levels", func_L14_0040EC48);

INCLUDE_ASM("asm/levels", func_L14_0040EF88);

INCLUDE_ASM("asm/levels", func_L14_0040F1B8);
