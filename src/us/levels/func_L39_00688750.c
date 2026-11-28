#include "common.h"
/* localdecomp:start func_L39_00688750 */
typedef struct E_0068B2F8 E_0068B2F8;
typedef struct { u8 pad0[0x1C]; void (*msg)(E_0068B2F8 *, s32, s32); } V_0068B2F8;
struct E_0068B2F8 { u8 pad0[4]; s32 f4; u8 pad8[0x58]; V_0068B2F8 *vt; };
typedef struct { u8 pad0[0x110]; E_0068B2F8 *items[1]; } L_0068B2F8;
extern void func_L01_00421DD0(s32);

s32 func_L39_00688750(L_0068B2F8 *self, s32 sel, s32 arg) {
    s32 old = *(s32 *)((u8 *)self + 0x290);
    E_0068B2F8 *e;

    if (old >= 0) {
        e = self->items[old];
        if (e->f4 >= 3) {
            e->vt->msg(e, 3, 0);
        }
    }
    *(s32 *)((u8 *)self + 0x290) = sel;
    if (sel >= 0) {
        e = self->items[sel];
        if (e->f4 >= 3) {
            e->vt->msg(e, 4, arg);
        } else {
            *(s32 *)((u8 *)self + 0x290) = -1;
        }
    }
    func_L01_00421DD0(1);
    return old;
}
/* localdecomp:end func_L39_00688750 */
