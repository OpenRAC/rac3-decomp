#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

extern f32 D_L31_001DD018;
extern float D_L31_001DD09C;
extern float D_L31_001DD0A0;
extern u8 D_L31_001D66B0[8];
extern void func_L30_0034CB68(s32, u8 *, s32, s32, s32, s32, float, float);

/* localdecomp:start func_L31_0034CC30 */
typedef struct {
    u8 pad[0x40];
} S_0034CC30;

typedef struct {
    u8 pad0[0xE8];
    s32 xE8;
    u8 padEC[0x154 - 0xEC];
    s32 x154;
    u8 pad158[0x15C - 0x158];
    s32 x15C;
} V_0034CC30;

typedef struct {
    u8 pad0[0x68];
    V_0034CC30 *vars;
    u8 pad6C[0x94 - 0x6C];
    u8 b94;
} M_0034CC30;

extern S_0034CC30 D_L31_00284110[];
extern void *D_L31_001E12D0[] __attribute__((section(".sdata")));
extern u8 *D_L31_001DF79C;
extern u8 D_00142660[];
extern void func_003C2C98(void *, void *);
extern void func_L01_00456230(void *, s32);
extern void func_L31_0034D390(void *, s32);
extern void func_003C2880(void *);

void func_L31_0034CC30(M_0034CC30 *m) {
    V_0034CC30 *v = m->vars;
    s32 i;
    s32 j;

    for (i = 0; i < 31; i++) {
        func_003C2C98(m, &D_L31_00284110[i]);
    }
    for (j = 13; j >= 0; j--) {
        D_L31_001E12D0[j] = 0;
    }
    v->x15C = 0;
    if (m->b94) {
        if (v->xE8 != -1) {
            func_L01_00456230(D_L31_001DF79C + v->xE8 * 0x100, 0);
        }
        if (v->x154 == 0) {
            D_00142660[0x77] |= 0x10;
            func_L31_0034D390(m, 0);
        }
    }
    func_003C2880(m);
}
/* localdecomp:end func_L31_0034CC30 */

INCLUDE_ASM("asm/levels", func_L31_0034CD18);
