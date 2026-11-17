#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_003D8DA0);

INCLUDE_ASM("asm/levels", func_L01_003D8E60);

/* localdecomp:start func_L01_003D9240 */
typedef struct {
    u8 pad0[0x20];
    u8 state;
    u8 pad21[0x34 - 0x21];
    u16 flags;
    u8 pad36[0x68 - 0x36];
    void *pvars;
} M_3D9240;

typedef struct {
    M_3D9240 *mobys[15];
    s16 count;
    s16 timer;
    f32 f40;
    f32 f44;
    u8 pad48[2];
    u8 b4A;
    u8 b4B;
} V_3D9240;

extern u16 D_L01_001DF4F4;
__asm__(".extern D_L01_001DF4F4, 2");
extern u8 D_L01_001D66B0;
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_00450F00(void *, void *);
extern void func_L01_003D8E60(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_0038CB00(s16 *);
extern void func_003C2880(void *);

void func_L01_003D9240(M_3D9240 *self) {
    V_3D9240 *v = self->pvars;
    M_3D9240 *m;
    s32 i;
    s32 done;
    u8 buf[0x10];

    switch (self->state) {
    case 0:
        func_L01_004450F0(self, 1, -1);
        v->timer = D_L01_001DF4F4;
        if (v->f44 == -100000.0f) {
            v->f44 = func_003C3D30((u8 *)self + 0x10, 0, 0, 0.5f) + 0.1f;
        }
        break;
    case 1:
        done = 0;

        for (i = 0; v != 0 && i < v->count; i++) {
            m = v->mobys[i];
            if (m == 0 || m->state == 0xFE || m->state == 0xFD || (m->flags & 2) || m->pvars == 0) {
                done++;
            } else {
                func_L01_00450F00(m, buf);
                func_L01_003D8E60(buf, &D_L01_001D66B0, 30, 7, 6, 2, 0x40, 2, v->f44, v->f40, -11.0f);
            }
        }
        if ((!v->b4A && (done == v->count || func_0038CB00(&v->timer))) || (v->b4A && v->b4B)) {
            func_003C2880(self);
        }
        break;
    }
}
/* localdecomp:end func_L01_003D9240 */
