/* NTSC-U draft (2026-11-14, Claude worker): C of func_L39_0059CC68, the NTSC-U twin of func_L39_0059E8D0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "@ps2as" (src/levels/shared/L39_0059E8D0.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_0059E8D0-class (src/levels/shared/L39_0059E8D0.c) */

/* localdecomp:start func_L39_0059CC68 */
typedef struct {
    u8 p0[0x34];
    u16 h34;
    u8 p36[0x34];
    u8 *p68;
    u8 p6C[0x3E];
    s16 type;
} O_0059CC68;

typedef struct {
    u8 p0[0x44];
    s16 count;
    u8 p46[0x15A];
    O_0059CC68 *obj[1];
} G_0059CC68;

extern G_0059CC68 D_L39_0025CFC0;
extern f32 D_001D7500_sda[];
__asm__(".extern D_001D7500_sda, 16");
extern f32 D_L39_00242D94[];
extern f32 D_L39_00242D98[];
extern u8 D_L39_0059CBE0[];
extern void func_L01_003E8B20(void);
extern void func_L01_0044EB38(void *, void *, s32, s32, f32);
extern void func_L01_00402498(void *, void *);

void func_L39_0059CC68(void) {
    s32 i;
    O_0059CC68 *o;
    s32 t;

    func_L01_003E8B20();
    for (i = 0; i < D_L39_0025CFC0.count; i++) {
        o = D_L39_0025CFC0.obj[i];
        if (o != 0) {
            if (o->type == 0xE29) {
                o->h34 |= 0x800;
            }
            t = o->type;
            if (t == 0xFA0) {
                if (o->p68 != 0) {
                    func_L01_0044EB38(o, o->p68 + 0xC, 0x80AAAAD2, 0x80396464, 0.06108653f);
                }
            } else if (t == 0x1DEE || t == 0x19BC) {
                func_L01_0044EB38(o, D_001D7500_sda, 0x80505080, 0x80404038, 0.0319977f);
            } else if (t == 0x1977) {
                func_L01_0044EB38(o, D_L39_00242D94, 0x8080AAAA, 0x80464646, 0.037815470f);
            } else if (t == 0x1766) {
                func_L01_0044EB38(o, D_L39_00242D98, 0x80AAAAFF, 0x80646496, 0.11053753f);
            } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
                func_L01_00402498(D_L39_0059CBE0, o);
            }
        }
    }
}
/* localdecomp:end func_L39_0059CC68 */
