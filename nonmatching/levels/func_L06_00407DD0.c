/* NTSC-U draft (Claude wave C3): C of func_L06_00405228, the NTSC-U twin of func_L06_00407DD0, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L06_00405228", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (0 diff) only with @ps2as added to the PAL flags (the 13-place shared function has inline lui/ori/mtc1 float constants where the PAL flags give $gp .lit4 loads: 81 diff with the PAL flags); needs D_001D6A90_sda (.extern 4) and .extern 16 ...
 */
#include "common.h"

/* localdecomp:start func_L06_00405228 */
typedef struct { u8 pad0[0x44]; s16 count; u8 pad46[0x1A0 - 0x46]; u8 *mobys[1]; } L_405228;
extern L_405228 D_L06_001E5A40;
extern u8 *D_L06_002380B0[];
extern f32 D_001D6A90_sda;
__asm__(".extern D_001D6A90_sda, 4");
extern f32 D_L06_001D6A94;
__asm__(".extern D_L06_001D6A94, 16");
extern f32 D_L06_001D6A98;
__asm__(".extern D_L06_001D6A98, 16");
extern void func_L01_00420D88(void);
extern void func_003A04A0(void *, s32);
extern void func_L01_00402498(void *, void *);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_0044EB38(void *, void *, s32, s32, f32);
extern void func_L06_004051A0(void);
extern void func_003A04A0_cb(void);

void func_L06_00405228(void)
{
    s32 i;
    u8 *m;
    s16 id;
    s32 j;

    func_L01_00420D88();
    for (i = 0; i < D_L06_001E5A40.count; i++) {
        m = D_L06_001E5A40.mobys[i];
        if (m != 0 && *(s16 *)(m + 0xAA) == 0xE29) {
            *(u16 *)(m + 0x34) |= 0x800;
        }
        if (*(s16 *)(m + 0xAA) == 0xD54) {
            m[0x63] = 0;
            for (j = 0; D_L06_002380B0[j] != 0; j++) {
                if (D_L06_002380B0[j][0x63] != 0) {
                    D_L06_002380B0[j][0x63] = 1;
                }
            }
            func_003A04A0(m, 0);
            func_L01_004026A0(func_003A04A0_cb, m);
        }
        if (m != 0) {
            id = *(s16 *)(m + 0xAA);
            if (id == 0xFA0) {
                if (*(u8 **)(m + 0x68) != 0) {
                    func_L01_0044EB38(m, *(u8 **)(m + 0x68) + 0xC, 0x80AAAAD2, 0x80396464, 0.061086528f);
                }
            } else if (id == 0x1DEE || id == 0x19BC) {
                func_L01_0044EB38(m, &D_001D6A90_sda, 0x80505080, 0x80404038, 0.031997703f);
            } else if (id == 0x1977) {
                func_L01_0044EB38(m, &D_L06_001D6A94, 0x8080AAAA, 0x80464646, 0.0378154702f);
            } else if (id == 0x1766) {
                func_L01_0044EB38(m, &D_L06_001D6A98, 0x80AAAAFF, 0x80646496, 0.110537529f);
            } else if (id == 0x195B || id == 0x1B58 || id == 0x195C || id == 0x175A) {
                func_L01_00402498(func_L06_004051A0, m);
            }
        }
    }
}
/* localdecomp:end func_L06_00405228 */
