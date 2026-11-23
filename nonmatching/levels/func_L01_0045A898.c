/* func_L01_0045A898 (level 01, 344 bytes): near miss, 11 words differ (--no-context; the file's own
 * `extern void func_L01_0045A898(f32 *, f32 *, f32)` casts would need adjusting).
 * Structure, branches, gp/lui split (D_001DFB40 via $gp, D_L01_001DFB40 with a 16-byte hint via lui) all match.
 * Only the reset arm's registers differ: retail w9C in $v0, -3 in $v1, 0xff in $a0, swc1 before `and`;
 * this C gives w9C in $a0, 0xff in $v0. All 120 statement orders of the five stores give the same bytes.
 */
#include "common.h"
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x38];
    s32 w38;
    u8 pad3C[0x80 - 0x3C];
    s32 w80;
    u8 pad84[0x94 - 0x84];
    s32 w94;
    s32 w98;
    s32 w9C;
    u128_t qA0;
    u8 padB0[4];
    f32 fB4;
    s32 wB8;
    s32 wBC;
    u8 padC0[0xEA - 0xC0];
    u8 bEA;
} O_45A898;
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DFB40, 16");
extern s32 D_001DFB40;
extern O_45A898 *func_L01_0045B958(void *);
extern void func_L01_0045B908(void *, O_45A898 *);
extern void func_L01_0045B6C8(void *, O_45A898 *, f32);
extern void func_L01_0045B8D8(void *, O_45A898 *);
extern void func_L01_0045AAD8(void *, O_45A898 *, f32 *, f32 *, f32 *, f32);
extern void func_L01_0045AF28(void *, O_45A898 *);
extern void func_L01_0045B110(void *, O_45A898 *, f32 *);
extern void func_L01_0045BB60(void *, O_45A898 *, f32);
extern void func_L01_0045C240(void);
s32 func_L01_0045A898(void *a0, f32 *a1, f32 a2) {
    f32 v[4];
    f32 w[4];
    s32 t;
    O_45A898 *o = func_L01_0045B958(a0);
    if (o == 0) {
        return 8;
    }
    if (D_001DFB40 != o->wBC) {
        o->w98 = o->w94;
        o->w94 = 0;
        if ((o->w38 & 0x100) == 0) {
            func_L01_0045B908(a0, o);
        }
        if (D_L01_001DFB40 - o->wBC < 2 && o->wBC != 0) {
            t = D_001DFB40;
        } else {
            func_L01_0045B6C8(a0, o, 0.0f);
            o->fB4 = 0.0f;
            o->w9C &= ~2;
            o->bEA = 0xFF;
            qzero(&o->qA0);
            o->w80 = 0;
            t = D_L01_001DFB40;
        }
        o->wBC = t;
        func_L01_0045B8D8(a0, o);
        func_L01_0045AAD8(a0, o, a1, v, w, a2);
        func_L01_0045AF28(a0, o);
        func_L01_0045B110(a0, o, a1);
        func_L01_0045BB60(a0, o, a2);
        func_L01_0045C240();
    }
    return o->w94;
}
