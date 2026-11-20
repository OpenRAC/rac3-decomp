#include "common.h"

/* NTSC-U version of func_003A8040 (frontbin): 150 -> 180; 1800 -> 2160 */
#include "common.h"





typedef int u128_t __attribute__((mode(TI)));
#define QZERO(p) __asm__ __volatile__("sq $0,0x0(%0)" : : "r"(p))
extern void *D_U_001D7080;
/* localdecomp:start func_U_003A2C18 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x10];
    vu0_v4 f10;
    u8 pad20[0x8A];
    s16 hAA;
    u8 padAC[0x14];
    f32 mC0[16];
} E_003A8040;
typedef struct {
    u8 pad0[0x20];
    vu0_v4 *f20;
    u8 pad24[0x1C];
    E_003A8040 *f40;
} S_003A8040;
typedef struct {
    u8 pad0[0x30];
    s32 f30;
    s32 f34;
    u8 pad38[0xC];
    s16 h44;
    u8 pad46[0xA];
    S_003A8040 *f50;
    u8 pad54[0x14C];
    E_003A8040 *tbl[4];
} B_003A8040;
extern B_003A8040 D_U_00225780_003A8040;
extern vu0_v4 D_U_00222480;
extern void *D_U_001D7080;
__asm__(".extern D_U_001D7080, 4");
extern void func_U_003888C8(void *, void *, void *);
extern void func_U_00388830(void *, void *, f32);

void func_U_003A2C18(void) {
    s32 lo = -1;
    s32 hi = 9999;
    s32 k = 0;
    E_003A8040 *ent;
    E_003A8040 *e;
    s32 i;
    s32 j;
    vu0_v4 d;

    if (D_U_00225780_003A8040.f30 == 0) {
        lo = 180;
        hi = 2160;
        k = 3;
    }
    if (D_U_00225780_003A8040.f34 > hi) {
        D_U_00225780_003A8040.f50 = 0;
    }
    if (D_U_00225780_003A8040.f34 < lo || D_U_00225780_003A8040.f34 > hi) {
        return;
    }
    ent = 0;
    for (i = 0; i < D_U_00225780_003A8040.h44; i++) {
        e = D_U_00225780_003A8040.tbl[i];
        if (e->hAA == 0xD54) {
            ent = e;
            break;
        }
    }
    if (ent != 0) {
        for (j = 0; j < 4; j++) {
            func_U_003888C8(&D_U_00225780_003A8040.f50->f20[j], &((vu0_v4 *)D_U_001D7080)[j], ent->mC0);
            vec_add_ba(&D_U_00225780_003A8040.f50->f20[j], &D_U_00225780_003A8040.f50->f20[j], &ent->f10);
            vec_sub_ab(&d, &D_U_00222480, &D_U_00225780_003A8040.f50->f20[j]);
            func_U_00388830(&d, &d, 0.02f);
            vec_add_ba(&D_U_00225780_003A8040.f50->f20[j], &D_U_00225780_003A8040.f50->f20[j], &d);
        }
    }
    D_U_00225780_003A8040.f50->f40 = D_U_00225780_003A8040.tbl[k];
}
/* localdecomp:end func_U_003A2C18 */
