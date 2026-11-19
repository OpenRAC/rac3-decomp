/* functional: high. 33 words differ at level_01, register allocation only. Request is a 0x2C-byte struct pointer; mirrors the matched func_L01_00446A70 (same ring buffer of 64 entries at D_L01_001EAA00/D_L01_001EEC80). */
#include "vu0.h"
typedef int u128_446978 __attribute__((mode(TI)));

typedef struct {
    u128_446978 v0;
    u128_446978 v10;
    s32 w20;
    s32 flags;
    u8 b28;
    u8 b29;
    u16 h2A;
    f32 f2C;
    s32 w30;
    f32 f34;
    u8 *owner;
    s32 w3C;
} Entry_446978;

typedef struct {
    u128_446978 v0;
    s32 w10;
    s32 flags;
    u8 b18;
    u8 b19;
    u16 h1A;
    f32 f1C;
    s32 w20;
    f32 f24;
    s32 w28;
} Req_446978;

typedef struct {
    u8 pad0[20];
    s32 next;
} Ring_446978;

extern Ring_446978 D_L01_001EAA00;
extern Entry_446978 D_L01_001EEC80[];

void func_L01_00446978(u8 *owner, Req_446978 *req) {
    s32 slot = D_L01_001EAA00.next;
    s32 flags = 0;
    Entry_446978 *e;

    if (owner[168] != 255) {
        e = &D_L01_001EEC80[owner[168]];
        if (e->owner == owner) {
            if (req->f1C < e->f2C) {
                e->flags |= req->flags;
                return;
            }
            flags = e->flags;
        }
    }
    e = &D_L01_001EEC80[slot];
    qzero(&e->v0);
    D_L01_001EEC80[slot].v10 = req->v0;
    e->flags = req->flags | flags;
    e->w20 = req->w10;
    e->b28 = req->b18;
    e->b29 = req->b19;
    e->h2A = req->h1A;
    e->f2C = req->f1C;
    e->f34 = req->f24;
    e->owner = owner;
    e->w30 = req->w20;
    e->w3C = req->w28;
    owner[168] = slot;
    D_L01_001EAA00.next = (slot + 1) & 63;
}
