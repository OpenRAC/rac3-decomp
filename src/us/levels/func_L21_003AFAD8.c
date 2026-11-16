#include "common.h"

/* NTSC-U counterpart of func_L21_003B1690 (src/levels/21_obani_draco/L21_003B0F18.c) */
#include "vu0.h"
#include "vu0.h"
extern f32 func_00389380(f32, f32);
void func_L21_003AFAD8(u8 *arg0);

/* localdecomp:start func_L21_003AFAD8 */
typedef struct {
    u8 pad0[0x24];
    f32 angle;
    u8 pad28[0xC];
    s32 count;
    u8 pad38[0x8];
    vu0_q pos[4];
    f32 size[4];
} S_003B1690;

static __inline__ void copy_003B1690(vu0_q *d, vu0_q *src) {
    *d = *src;
}

extern f32 func_00389380(f32, f32);
void func_L21_003AFC20(void *pos, s32 alpha, f32 ang);

void func_L21_003AFAD8(u8 *arg0) {
    S_003B1690 *s;
    s32 i;
    s32 j;

    s = *(S_003B1690 **)(arg0 + 0x68);
    s->angle = func_00389380(s->angle, -0.5235988f);
    func_L21_003AFC20(arg0 + 0x10, 0xFF, s->angle);
    for (i = 0; i < s->count; i++) {
        func_L21_003AFC20(&s->pos[i], 0xFF - i * 0x10, s->size[i]);
    }
    s->count++;
    if (s->count >= 4) {
        s->count = 3;
    }
    for (j = s->count; j >= 0; j--) {
        if (j == 0) {
            copy_003B1690(&s->pos[0], (vu0_q *)(arg0 + 0x10));
            s->size[0] = s->angle;
        } else {
            copy_003B1690(&s->pos[j], &s->pos[j - 1]);
            s->size[j] = s->size[j - 1];
        }
    }
}
/* localdecomp:end func_L21_003AFAD8 */
