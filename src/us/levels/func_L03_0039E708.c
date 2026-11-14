#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_0039E708 */
typedef struct {
    u8 pad[0x20];
    f32 speed, acceleration, limit;
    u8 pad2C[0xC];
    s32 flags;
} Move_39E708;

typedef struct {
    u8 pad[0x150];
    Move_39E708 move;
    u8 pad18C[0x2F0 - 0x18C];
    u8 list[0x440 - 0x2F0];
    vu0_v4 destination;
    u8 pad450[0xA];
    u8 flag;
} Vars_39E708;

typedef struct {
    u8 pad[0x10];
    vu0_v4 pos;
    u8 pad20[0x14];
    u16 flags;
    u8 pad36[0xD];
    u8 animation;
    u8 pad44[0x24];
    Vars_39E708 *vars;
    u8 pad6C[0x54];
    vu0_v4 forward;
} Object_39E708;

extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L03_0032D348_0039E708(void *);
extern void func_L03_0032CFF8(void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_0044B090(void *, void *);
extern void func_L01_0044B0B8(void *, s32, s32, f32);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L03_0039E708(Object_39E708 *obj, s32 state) {
    Vars_39E708 *v = obj->vars;
    vu0_v4 vec;
    void *list;
    switch (state) {
    case 1:
        if (obj->animation != 2) func_003BE4F0(obj, 2, 0, 0);
        break;
    case 2:
        if (obj->animation != 2) func_003BE4F0(obj, 2, 0, 0);
    case 3:
        obj->flags |= 0x5000;
        break;
    case 4:
        break;
    case 5:
        func_L03_0032D348_0039E708(obj);
        if (obj->animation != 2) func_003BE4F0(obj, 2, 0, 3);
        break;
    case 6: {
        Move_39E708 *m = &v->move;
        m->speed = 0.011111111380159855f;
        m->limit = 0.13333334028720856f;
        m->acceleration = 0.011111111380159855f;
        m->flags &= ~0x10;
        if (obj->animation != 3) func_003BE4F0(obj, 3, 0, 3);
        break;
    }
    case 7:
        func_L03_0032CFF8(obj);
        if (obj->animation != 4) func_003BE4F0(obj, 4, 0, 3);
        break;
    case 8:
        if (obj->animation != 5) func_003BE4F0(obj, 5, 0, 3);
        break;
    case 9: {
        Move_39E708 *m;
        func_L03_0032CFF8(obj);
        m = &v->move;
        m->speed = 0.0008333333535119891f;
        m->limit = 0.05000000447034836f;
        m->acceleration = 0.0008333333535119891f;
        m->flags |= 0x10;
        if (obj->animation != 0) func_003BE4F0(obj, 0, 0, 8);
        break;
    }
    case 10:
        v->flag = 0;
        if (obj->animation != 6) func_003BE4F0(obj, 6, 0, 8);
        break;
    case 11:
        func_00388830(&vec, &obj->forward, 6.0f);
        list = v->list;
        vec_add_ba(&v->destination, &obj->pos, &vec);
        func_L01_00458A70(obj, 0.0833333358168602f, 0.8333333730697632f,
                         0.0008726646774448454f, 0.05235988274216652f);
        v->move.flags |= 0x10;
        func_L01_0044B090(obj, list);
        func_L01_0044B0B8(list, 0x40, 1, 1.1f);
        func_L01_0044B0B8(list, 0x30, 2, 1.1f);
        func_L01_0044B0B8(list, 0x20, 3, 1.1f);
        func_L01_0044B0B8(list, 0x10, 4, 1.1f);
        if (obj->animation != 7) func_003BE4F0(obj, 7, 0, 3);
        break;
    case 12:
        if (obj->animation != 8) func_003BE4F0(obj, 8, 0, 3);
        break;
    case 13: {
        Move_39E708 *m = &v->move;
        m->speed = 0.0008333333535119891f;
        m->limit = 0.05000000447034836f;
        m->acceleration = 0.0008333333535119891f;
        m->flags |= 0x10;
        if (obj->animation != 1) func_003BE4F0(obj, 1, 5, 3);
        break;
    }
    case 14: {
        Move_39E708 *m = &v->move;
        m->speed = 0.0005555555690079927f;
        m->limit = 0.03333333507180214f;
        m->acceleration = 0.0005555555690079927f;
        m->flags |= 0x10;
        if (obj->animation != 0) func_003BE4F0(obj, 0, 0, 3);
        break;
    }
    }
    func_L01_00441FB8(obj, state, -1);
}
/* localdecomp:end func_L03_0039E708 */
