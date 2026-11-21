#include "common.h"

/* NTSC-U counterpart of func_L39_0059E8D0 (src/levels/shared/L39_0059E8D0.c): 0.0733038 -> 0.0610865; 0.0383972 -> 0.0319977; 0.0453786 -> 0.0378155; 0.132645 -> 0.110538 */
/* localdecomp:start func_L39_0059CC68 */
typedef struct {
    u8 p0[0x34];
    u16 h34;
    u8 p36[0x32];
    u8 *p68;
    u8 p6C[0x3E];
    s16 type;
} O_0059E8D0;

typedef struct {
    u8 p0[0x44];
    s16 count;
    u8 p46[0x15A];
    O_0059E8D0 *obj[1];
} G_0059E8D0;

extern G_0059E8D0 D_L39_0025CFC0_0059CC68;
extern f32 D_001D7500_sda;
__asm__(".extern D_001D7500_sda, 4");
extern f32 D_L39_00242D94_0059CC68;
extern f32 D_L39_00242D98_0059CC68;
extern void func_L01_003E8B20_0059CC68(void);
extern void func_L01_0044EB38_0059CC68(void *, void *, s32, s32, f32);
extern void func_L01_00402498_0059CC68(void *, void *);
extern void func_L01_00421438_0059CC68(void);

void func_L39_0059CC68(void) {
    s32 i;
    O_0059E8D0 *o;
    s32 t;

    func_L01_003E8B20_0059CC68();
    for (i = 0; i < D_L39_0025CFC0_0059CC68.count; i++) {
        o = D_L39_0025CFC0_0059CC68.obj[i];
        if (o != 0) {
            if (o->type == 0xE29) {
                o->h34 |= 0x800;
            }
            t = o->type;
            if (t == 0xFA0) {
                if (o->p68 != 0) {
                    func_L01_0044EB38_0059CC68(o, o->p68 + 0xC, 0x80AAAAD2, 0x80396464, 0.061086528f);
                }
            } else if (t == 0x1DEE || t == 0x19BC) {
                func_L01_0044EB38_0059CC68(o, &D_001D7500_sda, 0x80505080, 0x80404038, 0.031997703f);
            } else if (t == 0x1977) {
                func_L01_0044EB38_0059CC68(o, &D_L39_00242D94_0059CC68, 0x8080AAAA, 0x80464646, 0.0378154702f);
            } else if (t == 0x1766) {
                func_L01_0044EB38_0059CC68(o, &D_L39_00242D98_0059CC68, 0x80AAAAFF, 0x80646496, 0.110537529f);
            } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
                func_L01_00402498_0059CC68(func_L01_00421438_0059CC68, o);
            }
        }
    }
}
/* localdecomp:end func_L39_0059CC68 */
