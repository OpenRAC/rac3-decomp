/* functional: high. Read against the PAL asm end to end (all branches, callee mapping, stack args, gp offsets 1DF500-1DF534 match). gp-relative globals renamed from the _sda symbols to the level names D_L01_001DF5xx so they are retail's addresses. Bytes differ only in register allocation. */
#include "common.h"
/* localdecomp:start func_L01_003DBC80 */
#include "vu0.h"
typedef struct {
    vu0_v4 position;
    u8 pad10[8];
    u8 kind, pad19;
    u16 cls;
    s32 pad1C;
    u32 flags;
    u8 pad24[12];
} Damage_003DBC80;
typedef struct {
    vu0_q direction;
    f32 life;
    s32 ticks, flag, state;
    f32 length;
    s32 lead, target;
} Vars_003DBC80;
typedef struct {
    u8 pad0[0xD0]; u8 active; u8 padD1[11]; u8 *owner;
} Handle_003DBC80;
extern u8 D_001A30B0[];
extern u8 *D_L01_001EEA80[];
extern s32 D_001A71A0[];
extern f32 D_L01_001DF500;
extern f32 D_L01_001DF504;
extern f32 D_L01_001DF508;
extern s32 D_L01_001DF50C;
extern s32 D_L01_001DF510;
extern f32 D_L01_001DF514;
extern f32 D_L01_001DF51C;
extern s32 D_L01_001DF528;
extern s32 D_L01_001DF530;
extern s32 D_L01_001DF534;
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DF500, 4");
__asm__(".extern D_L01_001DF504, 4");
__asm__(".extern D_L01_001DF508, 4");
__asm__(".extern D_L01_001DF50C, 4");
__asm__(".extern D_L01_001DF510, 4");
__asm__(".extern D_L01_001DF514, 4");
__asm__(".extern D_L01_001DF51C, 4");
__asm__(".extern D_L01_001DF530, 4");
__asm__(".extern D_L01_001DF534, 4");
__asm__(".extern D_L01_001DF528, 4");
void func_L01_003DBC80(void *object) {
    extern s32 func_003A52A0(s32, s32, void *);
    extern void func_003A4F28(s32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern void func_L01_003DC780(void *, void *);
    extern void func_L01_003DC400(void *, void *, void *);
    extern void func_L01_00446760(void *, void *, u32, void *, f32);
    extern void func_L01_00446978(void *, void *);
    extern f32 func_00382538(void);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_003D4D00(void *, s32, f32, void *, void *);
    extern s32 func_00382498(s32, s32);
    extern s32 func_0038CAD0(void *);
    extern void func_003C2880(u8 *);
    extern s32 func_L01_00470150(void *, void *, u32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32,
        s32, s32, s32, s32, s32, s32, s32, s32, u32, u32, u32, u32, u32, u32, u32, u32, u32, s32,
        f32, f32, f32, f32);
    struct { vu0_q next; Damage_003DBC80 hit; vu0_v4 temp; Damage_003DBC80 special; } w;
    Handle_003DBC80 *handle;
    f32 desired;
    u8 *self;
    Vars_003DBC80 *v;
    s32 count, remaining;
    s32 weak;
    u8 **list;
    u8 *other;
    u8 *owner;
    f32 range;
    u32 color;
    f32 scale;
    s32 now;
    self = object;
    v = *(Vars_003DBC80 **)(self + 0x68);
    if (v->lead) {
        if (v->target == -1) goto acquire;
        handle = (Handle_003DBC80 *)(D_001A30B0 + (v->target << 7));
        if (handle->owner == self && handle->active != 0) goto acquired;
acquire:
        v->target = func_003A52A0(0, 4, self);
    acquired:;

    }
    desired = D_L01_001DF500;
    if (v->length < desired) {
        v->length += D_L01_001DF504;
        if (v->length > desired) v->length = desired;
    } else if (v->length > desired) {
        v->length -= D_L01_001DF508;
        desired = D_L01_001DF500;
    if (v->length < desired) v->length = D_L01_001DF500;
    }
    if (*(u16 *)(self + 0xB2) & 1) *(f32 *)(self + 0xF0) = func_0038DAB8(*(f32 *)(self + 0xF0), D_L01_001DF51C);
    else *(f32 *)(self + 0xF0) = func_0038DB00(*(f32 *)(self + 0xF0), D_L01_001DF51C);
    func_L01_003DC780(self, v);
    vec_add_ba(&w.next, self + 0x10, &v->direction);
    func_L01_00446760(&w.hit, *(void **)(self + 0xB8), 0x20000001, v, v->life);
    w.hit.kind = 3;
    w.hit.cls = *(u16 *)(self + 0xAA);
    w.hit.position.x = func_0038D098(func_00382538()) * 4.000000476837158f;
    w.hit.position.y = func_0038D0B0(func_00382538()) * 4.000000476837158f;
    w.hit.position.z = 0.0f;
    w.hit.position.w = 5627.9248046875f;
    w.hit.flags |= 1;
    if (v->ticks > D_L01_001DF510 && !v->flag) {
        owner = *(u8 **)(*(u8 **)(self + 0xB8) + 0x68);
        if (*(s32 *)(owner + 0xE4) >= *(s32 *)(owner + 0xE8)) {
            range = (f32)(D_L01_001DF510 + 12);
            func_0038CE20(&w.temp, v, range);
            vec_add_ab(&w.temp, &w.temp, self + 0x10);
            if (func_003D4D00(self + 0x10, 0x11, D_L01_001DF514 * 1.5f, *(void **)(self + 0xB8), 0)) {
                v->ticks = func_00382498(D_L01_001DF50C, D_L01_001DF510);
            } else {
                func_0038CE20(&w.temp, v, range * 0.5f);
                vec_add_ab(&w.temp, &w.temp, self + 0x10);
                if (func_003D4D00(self + 0x10, 0x11, D_L01_001DF514 * 1.5f, *(void **)(self + 0xB8), 0))
                    v->ticks = func_00382498(D_L01_001DF50C, D_L01_001DF510) / 2;
            }
        }
    }
    count = func_003D4D00(self + 0x10, 0x11, D_L01_001DF514, *(void **)(self + 0xB8), 0);
    if (count == 0 && func_0038CAD0(&v->ticks) == 0) goto no_collision;
    {
        owner = *(u8 **)(*(u8 **)(self + 0xB8) + 0x68);
        weak = *(s32 *)(owner + 0xE4) < *(s32 *)(owner + 0xE8);
        remaining = count;
        list = D_L01_001EEA80;
        if (remaining > 0) do {
            other = *list;
            if (*(s16 *)(other + 0xAA) == 0x1AE6) {
                if (weak) {
                    func_L01_00446760(&w.special, *(void **)(self + 0xB8), 1, v, 9999.0f);
                    w.special.kind = 3;
                    w.special.cls = *(u16 *)(self + 0xAA);
                    func_L01_00446978(other, &w.special);
                }
            } else func_L01_00446978(other, &w.hit);
            list++;
        } while (--remaining);
        func_L01_003303B8(self + 0x10, 0, 20, 15, 15, 15, 35, 0,
            0,0,0,0,0,1,0x01010000,0,0x00388EF7,0x63F7,0x00407FFF,0x20FF,0x8FFF,0x003064FF,0x7F60A0FF,0x280000FF,0x003064FF,0,
            1.75f,0.0f,0.0f,2.0f);
        if (v->target != -1) {
            handle = (Handle_003DBC80 *)(D_001A30B0 + (v->target << 7));
            if (handle->owner == self && handle->active) func_003A4F28(v->target);
        }
        now = D_L01_001DFB40;
        v->target = -1;
        if (now + D_L01_001DF534 < D_L01_001DF530) D_L01_001DF528 = -1;
        if (D_L01_001DF530 < now || count) {
            func_003A52A0(1, 0, self);
            D_L01_001DF530 = D_L01_001DFB40 + D_L01_001DF534;
        }
        func_003C2880(self);
        return;
    }
no_collision:
    {
        if (!v->state) {
            if (v->flag && v->flag == D_001A71A0[0]) { color = 0x7F0000FF; scale = 3.0f; }
            else { color = 0x7F10203F; scale = 2.25f; }
            qzero(&w.temp);
            w.temp.x = -1.2f;
            v->state = func_L01_00470150(&w.temp, self, color, -1, 1, -1, 0, *(s16 *)(self + 0x32), 0, 0, scale * 210000.0f, -0.1f, 1.0f);
        }
        func_L01_003DC400(self, v, &w.next);
        *(vu0_q *)(self + 0x10) = w.next;
    }
}
/* localdecomp:end func_L01_003DBC80 */
