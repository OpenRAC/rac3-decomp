#include "common.h"

/* NTSC-U counterpart of func_L05_00362810 (src/levels/05_daxx/L05_003619F0.c) */
extern void func_L01_00441FB8(s32, s32, s32);

/* localdecomp:start func_L05_003614F8 */
typedef struct P_362810 {
    f32 f0;
    s32 w4;
    f32 f8;
    s32 wC;
} P_362810;

typedef struct S_362810 {
    char pad0[0x18];
    f32 f18;
    char pad1[0x20 - 0x1C];
    u8 b20;
    char pad2[0x68 - 0x21];
    P_362810 *p68;
} S_362810;

struct S_362968;
void func_L05_00361630(struct S_362968 *a0);
s32 func_0039FE80(void *, s32, void *);
void func_0039FB08(s32);
void func_003BEC60(f32 *, void *, f32, f32, f32, f32);

extern u8 D_001A30B0[];
__asm__(".extern D_001A30B0, 16");
extern f32 D_001DDA78_sda;
extern f32 D_001DDA7C_sda;
__asm__(".extern D_001DDA78_sda, 4");
__asm__(".extern D_001DDA7C_sda, 4");

void func_L05_003614F8(S_362810 *a0) {
    P_362810 *p;
    u8 *e;
    s32 w;
    s32 k;
    f32 t;
    f32 u;

    func_L05_00361630(a0);
    p = a0->p68;
    k = a0->b20;
    if (k != 2) {
        if (k < 3) {
            if (k == 1) {
                func_L01_00441FB8((s32) a0, 2, -1);
            }
        }
    } else {
        if (a0->f18 < p->f0) {
            if (p->wC == -1) {
                p->wC = func_0039FE80(0, 4, a0);
            } else {
                e = D_001A30B0 + (p->wC << 7);
                if (*(void **) (e + 0xDC) != a0 || e[0xD0] == 0) {
                    p->wC = func_0039FE80(0, 4, a0);
                }
            }
            t = D_001DDA78_sda;
            u = D_001DDA7C_sda;
            func_003BEC60(&a0->f18, &p->w4, p->f0, t, t, u);
        } else {
            w = p->wC;
            if (w != -1) {
                e = D_001A30B0 + (w << 7);
                if (*(void **) (e + 0xDC) == a0 && e[0xD0] != 0) {
                    func_0039FB08(w);
                }
            }
            p->wC = -1;
            func_L01_00441FB8((s32) a0, 3, -1);
        }
    }
}
/* localdecomp:end func_L05_003614F8 */
