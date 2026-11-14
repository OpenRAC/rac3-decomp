/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_0032B848, the NTSC-U twin of func_L01_0032BCB0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_0032B408.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_0032BCB0 (src/levels/shared/L01_0032BCB0.c) */
/* localdecomp:start func_L01_0032B848 */
typedef int s128 __attribute__((mode(TI)));

extern f32 D_001DCE70_sda;
__asm__(".extern D_001DCE70_sda, 4");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
typedef struct {
    u8 pad0[0x100];
    s32 w100[0x40];
} T_0032B848;
extern T_0032B848 D_L01_00276EE0;
extern void func_L01_004C4190(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_L01_004C7180(void *, void *);
extern void func_L01_0032C5E8(void);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_00441E00(void *, s32, s32, s32, s32);

void func_L01_0032B848(u8 *self) {
    f32 old[4] __attribute__((aligned(16)));
    u8 *s;

    *(s128 *)old = *(s128 *)(self + 0x10);
    s = *(u8 **)(self + 0x68);
    vec_add_ab(self + 0x10, self + 0x10, s);
    func_L01_004C4190(self + 0x10, s, D_001DCE70_sda * 0.00027777778f * 0.1f);
    if (func_003CE740(old, self + 0x10, 0x10, self, 0) != 0) {
        self[0x20] = 8;
        if (D_001D545C == 0x1C) {
            s[0x4E] = func_L01_004C7180(&D_L01_00276EE0, self);
            func_L01_0032C5E8();
            if (D_L01_00276EE0.w100[(s8)s[0x4E]] != 0) {
                self[0x20] = 2;
                func_0039FE80(1, 0, self);
                func_L01_00441E00(self, 1, 0, 0, 0);
            } else {
                self[0x20] = 6;
            }
        }
    }
}
/* localdecomp:end func_L01_0032B848 */
