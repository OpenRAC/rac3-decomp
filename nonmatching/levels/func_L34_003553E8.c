/* NTSC-U draft (2026-11-14, Claude worker): C of func_L34_003545F8, the NTSC-U twin of func_L34_003553E8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/34_vidcomic_3/L34_003553E8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L34_003553E8 (src/levels/34_vidcomic_3/L34_003553E8.c).
 * Byte-exact only with @ps2as added to the PAL line (-O2 -G8 -fopt-stack -mno-check-zero-division): retail builds the float
 * literals with lui/ori/mtc1 and reaches the gp slots by lui. func_L01_00445168 is declared with the four floats FIRST
 * and the two pointers LAST (f32 x4, f32 *, f32 *): the call then computes the pointer args after the floats like retail
 * (a1 = s + 8 before a0 = self + 0x18); the registers are the same as with the (f32 *, f32 *, f32...) order. */
/* localdecomp:start func_L34_003545F8 */
#include "vu0.h"
typedef struct { f32 f0, f4, f8; s32 fC; } S_003545F8;
typedef struct {
    u8 p0[0x18];
    f32 f18;
    u8 p1C[4];
    u8 b20;
    u8 p21[0x47];
    S_003545F8 *p68;
} O_003545F8;
typedef struct {
    u8 p0[0x80];
    f32 f80;
    u8 p84[4];
    f32 f88;
} H_003545F8;
typedef struct { u8 b[0x80]; } Snd80_003545F8;
extern H_003545F8 D_001A4BE0;
extern Snd80_003545F8 D_001A30B0[];
extern s32 D_001A4F3C[];
extern f32 D_001DDA38_sda;
extern f32 D_001DDA3C_sda;
extern f32 D_001DDA40_sda;
extern f32 D_001DDA44_sda;
__asm__(".extern D_001DDA38_sda, 4");
__asm__(".extern D_001DDA3C_sda, 4");
__asm__(".extern D_001DDA40_sda, 4");
__asm__(".extern D_001DDA44_sda, 4");
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_0039FB08(s32);
extern s32 func_0039FE80(s32, s32, void *);
extern f32 func_L01_00445168(f32, f32, f32, f32, f32 *, f32 *);

void func_L34_003545F8(O_003545F8 *self) {
    S_003545F8 *s = self->p68;
    Snd80_003545F8 *e;
    f32 r;

    switch (self->b20) {
    case 0:
        s->f0 = self->f18;
        s->f4 = 144.5f;
        s->fC = -1;
        func_L01_00441FB8(self, 1, -1);
        break;
    case 1: {
        s32 id1 = s->fC;
        if (id1 != -1) {
            e = &D_001A30B0[id1];
            if (*(O_003545F8 **)&e->b[0xDC] == self && e->b[0xD0] != 0) {
                func_0039FB08(id1);
            }
        }
        s->fC = -1;
        if (D_001A4F3C[0] == (s32)self) {
            if (self->f18 < s->f4 - 1.0f) {
                func_L01_00441FB8(self, 2, -1);
            }
        }
        break;
    }
    case 2:
        if (D_001DDA40_sda < D_001A4BE0.f80 && D_001A4BE0.f80 < D_001DDA44_sda) {
            s32 id2 = s->fC;
            if (id2 == -1 || (e = &D_001A30B0[id2], *(O_003545F8 **)&e->b[0xDC] != self) || e->b[0xD0] == 0) {
                s->fC = func_0039FE80(0, 4, self);
            }
            r = func_L01_00445168(s->f4, 0.00027777778f, 0.00027777778f, D_001DDA3C_sda * 0.016666668f, &self->f18, &s->f8);
            if (r < 0.01f) {
                func_L01_00441FB8(self, 1, -1);
            }
        } else {
            s32 id3 = s->fC;
            if (id3 != -1) {
                e = &D_001A30B0[id3];
                if (*(O_003545F8 **)&e->b[0xDC] == self && e->b[0xD0] != 0) {
                    func_0039FB08(id3);
                }
            }
            s->fC = -1;
        }
        if (D_001A4BE0.f88 < self->f18) {
            func_L01_00441FB8(self, 3, -1);
        }
        break;
    case 3: {
        s32 id4 = s->fC;
        if (id4 == -1 || (e = &D_001A30B0[id4], *(O_003545F8 **)&e->b[0xDC] != self) || e->b[0xD0] == 0) {
            s->fC = func_0039FE80(0, 4, self);
        }
        if (D_001A4F3C[0] == (s32)self) {
            func_L01_00441FB8(self, 2, -1);
        }
        r = func_L01_00445168(s->f0, 0.0055555557f, 0.0027777778f, D_001DDA38_sda * 0.016666668f, &self->f18, &s->f8);
        if (fabs_asm(r) < 0.01f) {
            func_L01_00441FB8(self, 1, -1);
        }
        break;
    }
    }
}
/* localdecomp:end func_L34_003545F8 */
