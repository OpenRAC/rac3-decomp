#include "common.h"

/* localdecomp:start func_L20_003F32D0 */
#include "vu0.h"
typedef int Q_003F32D0 __attribute__((mode(TI)));
extern s32 D_L20_001DF400;
__asm__(".extern D_L20_001DF400, 4");
extern s32 D_L20_001DF404;
__asm__(".extern D_L20_001DF404, 4");
extern s32 D_L20_001DF3A0;
__asm__(".extern D_L20_001DF3A0, 4");
extern s32 D_L20_001DF3A4;
__asm__(".extern D_L20_001DF3A4, 4");
extern s32 D_L20_001DF3A8;
__asm__(".extern D_L20_001DF3A8, 4");
extern s32 func_0038DBD8(s32, s32, f32);

typedef struct {
    vu0_v4 v[0x61];
} Sub_003F32D0;

typedef struct {
    u8 pad0[0x28];
    s32 x28;
    u8 pad2C[0x16];
    s16 x42;
    s32 x44;
    u8 idx[4];
    u8 pad4C[4];
    Sub_003F32D0 sub[2];
} T_003F32D0;

void func_L20_003F32D0(u8 *a0)
{
    T_003F32D0 *t = *(T_003F32D0 **)(a0 + 0x68);
    s32 n;

    if (t->x42 != 0) {
        s32 m;
        s32 j;
        s32 k;
        vu0_v4 *p;
        s32 i;

        t->x42--;
        for (m = 0; m < 23; m++) {
            vec_add_ab(&t->sub[0].v[4 + m], &t->sub[0].v[4 + m], &t->sub[0].v[36 + m]);
        }
        for (j = 0; j < 4.0f; j++) {
            p = t->sub[0].v + j + 68;
            for (k = 0; k < 3; k++) {
                vec_add_ab(p, p, p + 16);
                p += 4;
            }
        }
        for (i = 0; i < 4; i++) {
            *(Q_003F32D0 *)&t->sub[0].v[64 + i] = *(Q_003F32D0 *)&t->sub[0].v[t->idx[i]];
        }
    }
    n = t->x42;
    if (D_L20_001DF400 < n) {
        t->x44 = func_0038DBD8(D_L20_001DF3A4, D_L20_001DF3A0,
                               (f32)(n - D_L20_001DF400) / (f32)(t->x28 - D_L20_001DF400));
    } else if (D_L20_001DF404 < n) {
        t->x44 = func_0038DBD8(D_L20_001DF3A8, D_L20_001DF3A4,
                               (f32)(n - D_L20_001DF404) / (f32)(D_L20_001DF400 - D_L20_001DF404));
    } else {
        t->x44 = 0;
    }
    if (t->x42 != 0) {
        s32 m;
        s32 j;
        s32 k;
        vu0_v4 *p;
        s32 i;

        t->x42--;
        for (m = 0; m < 23; m++) {
            vec_add_ab(&t->sub[1].v[4 + m], &t->sub[1].v[4 + m], &t->sub[1].v[36 + m]);
        }
        for (j = 0; j < 4.0f; j++) {
            p = t->sub[1].v + j + 68;
            for (k = 0; k < 3; k++) {
                vec_add_ab(p, p, p + 16);
                p += 4;
            }
        }
        for (i = 0; i < 4; i++) {
            *(Q_003F32D0 *)&t->sub[1].v[64 + i] = *(Q_003F32D0 *)&t->sub[1].v[t->idx[i]];
        }
    }
}
/* localdecomp:end func_L20_003F32D0 */
