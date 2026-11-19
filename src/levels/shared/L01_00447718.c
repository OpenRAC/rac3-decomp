#include "common.h"

/* localdecomp:start func_L01_00447718 */
#include "vu0.h"
#include "structs/moby.h"
/* A damage record, as damage_queue (func_L01_00446978) takes it (open-rac-engine
   docs/research/weapons.md, "Damage": damage_info_fill fills the push at +0x00 and sets +0x20;
   the queue compares the damage at +0x1C). */
typedef struct {
    vu0_v4 momentum;               /* 0x00: the push */
    struct Moby *attacker;         /* 0x10 */
    s32 flags;                     /* 0x14 */
    u8 type;                       /* 0x18 */
    u8 mode;                       /* 0x19 */
    u16 attacker_class;            /* 0x1A: the attacker's oclass */
    f32 damage;                    /* 0x1C */
    s32 pushed;                    /* 0x20: set with the push */
    s32 unk_24;                    /* 0x24 */
    s32 extra;                     /* 0x28 */
} DamageIn_447718;
/* blast_damage_apply: deals a blast's damage to the mobys in a list, each pushed out from the blast
   by `push_out` and up by `push_up` (open-rac-engine docs/research/weapons.md: the RY3NO V1 blast 4
   out and 6 up, the explosive crate's 1 and 1 on the hero). */
void func_L01_00447718(struct Moby *attacker, Vec4f *position, struct Moby **targets, s32 count, struct Moby *ignore, s32 flags, s32 type, s32 mode, s32 extra, f32 damage, f32 push_out, f32 push_up)
{
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_L01_00446978(struct Moby *, DamageIn_447718 *);
    vu0_v4 centre;
    DamageIn_447718 hit;
    f32 angle;
    vu0_v4 *c = &centre;
    *(vu0_q *)&centre = *(vu0_q *)position;
    if (count > 0) {
    struct Moby **target = targets;
    s32 left = count;
    do {
        if (*target != ignore) {
            hit.attacker = attacker;
            hit.attacker_class = attacker->oclass;
            hit.flags = flags;
            hit.damage = damage;
            hit.pushed = flags;
            hit.type = type;
            hit.mode = mode;
            hit.extra = extra;
            angle = func_0038D160((*target)->position.x - c->x, (*target)->position.y - c->y);
            hit.momentum.x = func_0038D098(angle) * push_out;
            hit.momentum.y = func_0038D0B0(angle) * push_out;
            hit.momentum.z = push_up;
            hit.momentum.w = 5627.9248046875f;
            func_L01_00446978(*target, &hit);
        }
        left--;
        target++;
    } while (left != 0);
    }
}
/* localdecomp:end func_L01_00447718 */
