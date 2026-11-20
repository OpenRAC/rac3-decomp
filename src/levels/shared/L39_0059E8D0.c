#include "common.h"

/* localdecomp:start func_L39_0059E8D0 */
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

extern G_0059E8D0 D_L39_0025CEC0_0059E8D0;
extern f32 D_001D7520_sda;
__asm__(".extern D_001D7520_sda, 4");
extern f32 D_L39_00242C34_0059E8D0;
extern f32 D_L39_00242C38_0059E8D0;
extern void func_L01_003E32F0_0059E8D0(void);
extern void func_L01_00451DB8_0059E8D0(void *, void *, s32, s32, f32);
extern void func_L01_00404808_0059E8D0(void *, void *);
extern void func_L01_00424168_0059E8D0(void);

void func_L39_0059E8D0(void) {
    s32 i;
    O_0059E8D0 *o;
    s32 t;

    func_L01_003E32F0_0059E8D0();
    for (i = 0; i < D_L39_0025CEC0_0059E8D0.count; i++) {
        o = D_L39_0025CEC0_0059E8D0.obj[i];
        if (o != 0) {
            if (o->type == 0xE29) {
                o->h34 |= 0x800;
            }
            t = o->type;
            if (t == 0xFA0) {
                if (o->p68 != 0) {
                    func_L01_00451DB8_0059E8D0(o, o->p68 + 0xC, 0x80AAAAD2, 0x80396464, 0.0733038336f);
                }
            } else if (t == 0x1DEE || t == 0x19BC) {
                func_L01_00451DB8_0059E8D0(o, &D_001D7520_sda, 0x80505080, 0x80404038, 0.0383972451f);
            } else if (t == 0x1977) {
                func_L01_00451DB8_0059E8D0(o, &D_L39_00242C34_0059E8D0, 0x8080AAAA, 0x80464646, 0.0453785658f);
            } else if (t == 0x1766) {
                func_L01_00451DB8_0059E8D0(o, &D_L39_00242C38_0059E8D0, 0x80AAAAFF, 0x80646496, 0.132645041f);
            } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
                func_L01_00404808_0059E8D0(func_L01_00424168_0059E8D0, o);
            }
        }
    }
}
/* localdecomp:end func_L39_0059E8D0 */
