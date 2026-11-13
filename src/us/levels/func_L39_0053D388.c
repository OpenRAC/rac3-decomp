#include "common.h"

/* NTSC-U counterpart of func_L39_0053DB28 (src/levels/shared/L39_0053DA40.c) */
/* localdecomp:start func_L39_0053D388 */
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0x47];
    u8 *f68;
} Obj_0053DB28;
typedef struct {
    u8 pad0[0x40];
    s32 f40;
    u8 pad44[0x68];
    s32 fAC;
    s32 fB0;
    s32 fB4;
    s32 fB8;
    s32 fBC;
} Cur_0053DB28;
typedef struct {
    u8 pad0[0x180];
    s32 f180;
} Glob_0053DB28;
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0x89];
    s16 fAA;
    u8 padAC[0x54];
} Ent_0053DB28;
extern Glob_0053DB28 *D_L39_002417C0;
extern Ent_0053DB28 *D_L39_0024C05C;
extern s32 func_L01_00442998(s32, s32, s32);
extern s32 func_L39_0053D148_0053D388(s32);
extern void func_L39_0053D170(s32);
extern s32 func_L39_0053D198_0053D388(s32);
extern void func_L39_0053D1C0_0053D388(u8 *);
extern s32 func_L39_0053D248(s32);
extern void func_L39_0053D270(s32);

s32 func_L39_0053D388(Obj_0053DB28 *a0, s32 a1) {
    Cur_0053DB28 *p;
    if (a1 == 0 && a0->f20 == 2) {
        p = (Cur_0053DB28 *)a0->f68;
        if (p->f40 == 0) {
            if (!func_L01_00442998(p->fB0, 5, 0)) {
                if (!func_L39_0053D148_0053D388((s32)a0)) {
                    func_L39_0053D170((s32)a0);
                }
            }
        } else {
            if (D_L39_002417C0->f180 == 0 && p->fB4 >= 0) {
                Ent_0053DB28 *e = (Ent_0053DB28 *)((p->fB4 << 8) + (s32)D_L39_0024C05C);
                if (e->fAA == 0x1C57 && e->f20 == a0->f20) {
                    if (!func_L39_0053D198_0053D388((s32)a0)) func_L39_0053D1C0_0053D388((u8 *)a0);
                }
            }
            if (!func_L01_00442998(p->fAC, 7, 0)) {
                if (p->fBC >= (s32)((f32)(p->fB8 * 10 + 30) * 60.0f)) {
                    if (!func_L39_0053D248((s32)a0)) {
                        func_L39_0053D270((s32)a0);
                    }
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L39_0053D388 */
