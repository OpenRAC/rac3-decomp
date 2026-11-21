/* functional: high. Changes the selected entry (+0x290) of a list object: if the old selection is valid and its entry state (+4) is >= 3, sends it message 3 (via the entry's vtable slot 0x1C, arg 0); stores the new index; if the new one is valid, sends it message 4 with arg a2 when its state is >= 3, else resets the selection to -1; then calls func_005B4860(1) and returns the old selection. */
typedef struct E_0068B2F8 E_0068B2F8;
typedef struct { u8 pad0[0x1C]; void (*msg)(E_0068B2F8 *, s32, s32); } V_0068B2F8;
struct E_0068B2F8 { u8 pad0[4]; s32 f4; u8 pad8[0x58]; V_0068B2F8 *vt; };
typedef struct { u8 pad0[0x110]; E_0068B2F8 *items[1]; } L_0068B2F8;
extern void func_005B4860(s32);

s32 func_L39_0068B2F8(L_0068B2F8 *self, s32 sel, s32 arg) {
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
        if (e->f4 < 3) {
            *(s32 *)((u8 *)self + 0x290) = -1;
        } else {
            e->vt->msg(e, 4, arg);
        }
    }
    func_005B4860(1);
    return old;
}
