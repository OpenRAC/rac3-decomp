#include "common.h"

/* NTSC-U counterpart of func_L34_003553E8 (src/levels/34_vidcomic_3/L34_003553E8.c) */
/* localdecomp:start func_L34_003545F8 */
#include "vu0.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    s32 fC;
} V_003553E8;

typedef struct {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1C[0x20 - 0x1C];
    u8 f20;
    u8 pad21[0x68 - 0x21];
    V_003553E8 *f68;
} S_003553E8;

typedef struct {
    u8 pad0[0x80];
    f32 f80;
    f32 f84;
    f32 f88;
} G_003553E8;

extern u8 D_001A30B0[];
extern G_003553E8 D_001A4BE0;
extern void *D_001A4F3C[];
extern f32 D_L34_001DDA38;
extern f32 D_L34_001DDA3C;
extern f32 D_L34_001DDA40;
extern f32 D_L34_001DDA44;
__asm__(".extern D_L34_001DDA38, 4");
__asm__(".extern D_L34_001DDA3C, 4");
__asm__(".extern D_L34_001DDA40, 4");
__asm__(".extern D_L34_001DDA44, 4");
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_0039FB08(s32);
extern s32 func_0039FE80(s32, s32, void *);
extern f32 func_L01_00445168(f32 *, f32, f32 *, f32, f32, f32);

void func_L34_003545F8(S_003553E8 *p) {
    V_003553E8 *q = p->f68;
    u8 *e;

    switch (p->f20) {
    case 0:
        q->f0 = p->f18;
        q->f4 = 144.5f;
        q->fC = -1;
        func_L01_00441FB8(p, 1, -1);
        break;
    case 1:
        if (q->fC != -1) {
            e = D_001A30B0 + (q->fC << 7);
            if (*(void **)(e + 0xDC) == p && e[0xD0] != 0) {
                func_0039FB08(q->fC);
            }
        }
        q->fC = -1;
        if (D_001A4F3C[0] == p && p->f18 < q->f4 - 1.0f) {
            func_L01_00441FB8(p, 2, -1);
        }
        break;
    case 2:
        if (D_L34_001DDA40 < D_001A4BE0.f80 && D_001A4BE0.f80 < D_L34_001DDA44) {
            if (q->fC == -1) {
                q->fC = func_0039FE80(0, 4, p);
            } else {
                e = D_001A30B0 + (q->fC << 7);
                if (*(void **)(e + 0xDC) != p || e[0xD0] == 0) {
                    q->fC = func_0039FE80(0, 4, p);
                }
            }
            if (func_L01_00445168(&p->f18, q->f4, &q->f8, 0.00027777778450399637f, 0.00027777778450399637f, D_L34_001DDA3C * 0.01666666753590107f) < 0.01f) {
                func_L01_00441FB8(p, 1, -1);
            }
        } else {
            if (q->fC != -1) {
                e = D_001A30B0 + (q->fC << 7);
                if (*(void **)(e + 0xDC) == p && e[0xD0] != 0) {
                    func_0039FB08(q->fC);
                }
            }
            q->fC = -1;
        }
        if (D_001A4BE0.f88 < p->f18) {
            func_L01_00441FB8(p, 3, -1);
        }
        break;
    case 3:
        if (q->fC == -1) {
            q->fC = func_0039FE80(0, 4, p);
        } else {
            e = D_001A30B0 + (q->fC << 7);
            if (*(void **)(e + 0xDC) != p || e[0xD0] == 0) {
                q->fC = func_0039FE80(0, 4, p);
            }
        }
        if (D_001A4F3C[0] == p) {
            func_L01_00441FB8(p, 2, -1);
        }
        if (fabs_asm(func_L01_00445168(&p->f18, q->f0, &q->f8, 0.0055555556900799274f, 0.0027777778450399637f, D_L34_001DDA38 * 0.01666666753590107f)) < 0.01f) {
            func_L01_00441FB8(p, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L34_003545F8 */
