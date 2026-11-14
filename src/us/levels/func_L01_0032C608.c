#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_0032CAA0 (src/levels/shared/L01_0032C6B8.c) */
/* localdecomp:start func_L01_0032C608 */
typedef struct {
    vu0_v4 pos;
    vu0_v4 vel;
    f32 life;
    u8 *owner;
    u8 pad[8];
} Slot_32C608;

extern Slot_32C608 D_L01_00277110[];
extern void func_003BDA38(void *, s32, void *);

void func_L01_0032C608(u8 *obj, vu0_v4 *vel) {
    u8 *s = *(u8 **)(obj + 0x68);
    vu0_v4 pos;
    Slot_32C608 *p;
    Slot_32C608 *end;
    f32 life;
    func_003BDA38(obj, 1, &pos);
    life = 120.0f;
    p = D_L01_00277110;
    end = p + 100;
    for (; (s32)p < (s32)end; p++) {
        if (p->owner == 0) {
            *(u16 *)(s + 0x66) += 1;
            p->owner = obj;
            p->life = life;
            p->vel = *vel;
            p->pos = pos;
            break;
        }
    }
}
/* localdecomp:end func_L01_0032C608 */
