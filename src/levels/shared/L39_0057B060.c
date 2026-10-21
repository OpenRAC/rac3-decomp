#include "common.h"

/* localdecomp:start func_L39_0057B060 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    u128_t pos;
    u128_t unk10;
    u8 pad20[896 - 32];
    f32 c[3];
    f32 pad38C;
    f32 a[3];
    f32 pad39C;
    f32 b[3];
    f32 pad3AC;
    f32 m[3][4];
    u128_t pos2;
    u8 pad3F0[1064 - 1008];
    f32 fov;
    u8 pad42C[1081 - 1068];
    u8 mode;
    u8 pad43A[1120 - 1082];
} Cam_0057A0B8;

typedef struct {
    u128_t pos;
    u128_t unk10;
    u8 unk20[48];
} View_0057A0B8;

extern s32 *D_L39_00241120;
extern Cam_0057A0B8 D_L39_0024DE80[];
extern View_0057A0B8 D_L39_0024DE00;
extern f32 D_L39_0025D770[];
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038CD28(void *, void *, s32);

void func_L39_0057B060(s32 idx)
{
    Cam_0057A0B8 *e;
    f32 h;

    if (*D_L39_00241120 >= 2) {
        if (D_L39_0024DE80[idx].mode == 1) {
            h = D_L39_0024DE80[idx].fov * 0.5f;
            D_L39_0025D770[0] = func_0038D0B0(h) / func_0038D098(h);
        } else {
            D_L39_0025D770[0] = 0.62f;
        }
    }
    e = &D_L39_0024DE80[idx];
    e->m[0][0] = -e->a[0];
    e->m[1][0] = -e->a[1];
    e->m[2][0] = -e->a[2];
    e->m[0][1] = -e->b[0];
    e->m[1][1] = -e->b[1];
    e->m[2][1] = -e->b[2];
    e->m[0][2] = e->c[0];
    e->m[1][2] = e->c[1];
    e->m[2][2] = e->c[2];
    e->pos2 = e->pos;
    D_L39_0024DE00.pos = e->pos;
    D_L39_0024DE00.unk10 = D_L39_0024DE80[idx].unk10;
    func_0038CD28(D_L39_0024DE00.unk20, D_L39_0024DE80[idx].c, 48);
}
/* localdecomp:end func_L39_0057B060 */

INCLUDE_ASM("asm/levels", func_L39_0057B1C0);
