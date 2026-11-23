#include "common.h"
#include "structs/moby.h"
#include "structs/vector.h"
#include "vu0.h"


typedef struct {
    u8 pad_0[0x80];
    Vec4f pos;
    u8 pad_90[0x60];
    Vec4f intended_vel;
    u8 pad_100[0x10];
    Vec4f vel;
    u8 pad_120[0xBC];
    s16 timer_1fc;
    u8 pad_1DE[0x3E];
    s16 x21C;
    u8 pad_21E[0x16];
    s32 giant_clank;
    u8 pad_238[0x3F6];
    s16 x62E;
    u8 pad_630[0x34];
    struct MobyHit *x664;
    u8 pad_668[0xE11];
    u8 walk_slow_flag;
    u8 pad_147A[0x236];
    s32 hero_camera_mode;
    u8 pad_16B4[0x3D0];
    s32 x1A84;
    u8 pad_1A88[0xB38];
    struct Moby *hero_moby;
    s32 state;
    u8 pad_25C8[0x4];
    s32 state_type;
    u8 pad_25D0[0x14];
    u8 body_kind;
    u8 pad_25E5[0x223];
    struct Moby *x2808;
    u8 pad_280C[0x44];
    s32 health;
} Hero_004CFA98;
extern Hero_004CFA98 D_001A4BE0;

extern s32 D_001D6694;
extern struct MobyHit D_001ECA00[];
extern u8 D_00142660[];
extern s32 func_L01_0041A4F0(void);
extern f32 func_L01_004C93D8(void);
extern f32 func_L01_004C9360(f32);
extern f32 func_L01_004DFE88(s32);
extern void func_L01_004E1560(void);
extern void func_L01_005110E8(void *, s32, f32, f32, f32);
extern s32 func_L23_004E3428(s32, s32);
extern void *func_L01_00447490(void *, s32, s32);
extern void func_L01_004DFEA0(s32);
extern void func_L01_003F1F20(s32, s32);
extern s32 func_L01_004F4E70(s32, s32);
extern void func_L01_004ED838(void *, s32, f32, f32);
extern void func_L01_00511618(void *, void *, f32);
extern void func_L23_003098F8(s32);
extern void func_0038CE20(void *, void *, f32);

/* localdecomp:start func_L23_004CFA98 */
s32 func_L23_004CFA98(s32 arg) {
    vu0_v4 v;
    struct MobyHit *o;
    struct Moby *m;
    struct MobyHit *h;
    s32 n;
    s32 fl;
    s32 s;
    f32 f;

    if (D_001A4BE0.state_type == 0x14 || D_001A4BE0.state_type == 7) {
        return 0;
    }
    if (D_001A4BE0.state == 0x74) {
        return 0;
    }
    if (D_001A4BE0.state == 0x31) {
        return 0;
    }
    if (D_001A4BE0.timer_1fc != 0) {
        return 0;
    }
    if (D_001D6694 != 0) {
        return 0;
    }
    D_001A4BE0.x2808 = 0;
    if (D_001A4BE0.hero_moby->hit == 0xFF) {
        return 0;
    }
    o = &D_001ECA00[D_001A4BE0.hero_moby->hit];
    if (o->victim != D_001A4BE0.hero_moby) {
        return 0;
    }
    if (D_001A4BE0.body_kind == 2) {
        if (!(o->flags & 2)) {
            return 0;
        }
    } else if (!(o->flags & 9)) {
        return 0;
    }
    if (D_001A4BE0.giant_clank != 0) {
        return 0;
    }
    if (o->damage != 0.0f && func_L01_0041A4F0() != 0 && D_001A4BE0.body_kind != 5) {
        D_00142660[0x5A] = 0;
        D_00142660[0x5B] = 0;
    }
    if (func_L01_004C93D8() != 0.0f && D_001A4BE0.body_kind == 0 && !(o->flags & 0x20000000)) {
        f = func_L01_004C9360(o->damage);
        o->damage = f;
        if (f == 0.0f) {
            return 0;
        }
    }
    if ((o->flags & 0x20000000) && D_001A4BE0.body_kind == 0) {
        {
            s32 k = *(s16 *)(D_00142660 + 0x40);
            if (k >= 5) {
                k = 4;
            }
            if (k < 0) {
                k = 0;
            }
            o->damage = o->damage / func_L01_004DFE88(k);
        }
    }
    D_001A4BE0.x2808 = o->attacker;
    if (D_001A4BE0.state_type == 0xF) {
        D_001A4BE0.x664 = o;
        D_001A4BE0.x62E = 1;
        return 0;
    }
    if (D_001A4BE0.body_kind == 2) {
        s32 hp = D_001A4BE0.x1A84 - (s32)o->damage;
        D_001A4BE0.x1A84 = hp;
        if (hp < 0) {
            D_001A4BE0.x1A84 = 0;
        }
    }
    if (arg != 0) {
    func_L01_004E1560();
    fl = 0;
    if (o->pushed & 1) {
        v = *(vu0_v4 *)&o->momentum;
        if (o->momentum.w == 5627.9248f) {
            fl = 1;
        }
    } else if (o->attacker != 0) {
        vec_sub_ba(&v, &D_001A4BE0.pos, &o->attacker->position);
    } else {
        func_L01_005110E8(&v, 0, -1.0f, 0.0f, 0.0f);
    }
    switch (D_001A4BE0.body_kind) {
    case 0:
        m = D_001A4BE0.x2808;
        if (m != 0) {
            s = m->oclass;
            if (s == 0x4EB || s == 0x558 || s == 0x1C5F) {
                func_L23_004E3428(0x82, 1);
                return 1;
            }
        }
        if ((D_001A4BE0.state == 1 || D_001A4BE0.state == 0x1D ||
             D_001A4BE0.hero_camera_mode == 2) && !(o->flags & 8)) {
            h = func_L01_00447490(D_001A4BE0.hero_moby, 1, 0);
            if (h != 0) {
                func_L01_004DFEA0((s32)h->damage);
            }
            if (D_001A4BE0.health == 0) {
                func_L23_004E3428(0x16, 1);
            } else {
                func_L01_003F1F20(0x12, 0);
            }
            D_001A4BE0.timer_1fc = 0x40;
            if (D_001A4BE0.x21C == 0) {
                D_001A4BE0.x21C = 0xF;
            }
            func_L01_004F4E70(0x14, 0);
            return 0;
        }
        if (D_001A4BE0.state_type == 0x12) {
            func_L23_004E3428(0x77, 1);
        } else if (D_001A4BE0.state_type == 0x11) {
            func_L23_004E3428(0x78, 1);
        } else if (o->flags & 8) {
            func_L23_004E3428(0x91, 1);
        } else {
            func_L23_004E3428(0x16, 1);
        }
        if (D_001A4BE0.state == 0x91) {
            qzero(&v);
            break;
        }
        func_L01_004ED838(&v, fl, D_001A4BE0.walk_slow_flag ? 0.0f : 0.0660000071f, 0.034f);
        if (fl != 0 && o->unk_28 == 4) {
            func_L01_00511618(&v, &v, 2.0f);
        }
        break;
    case 1:
        func_L23_004E3428(0x42, 1);
        func_L01_004ED838(&v, fl, 0.0600000024f, 0.0600000024f);
        break;
    case 2:
        if ((o->flags & 4) || D_001A4BE0.x1A84 <= 0) {
            func_L23_004E3428(0x5D, 1);
            func_L23_003098F8((s32)D_001A4BE0.hero_moby);
            func_0038CE20(&v, &v, 0.114000008f);
        } else {
            qzero(&v);
        }
        break;
    case 3:
        func_L23_004E3428(0x55, 1);
        func_L01_004ED838(&v, fl, 0.100000009f, 0.0480000041f);
        break;
    }
    vec_add_ba(&D_001A4BE0.intended_vel, &D_001A4BE0.intended_vel, &v);
    vec_add_ba(&D_001A4BE0.vel, &D_001A4BE0.vel, &v);
    } else if (D_001A4BE0.timer_1fc == 0) {
        h = func_L01_00447490(D_001A4BE0.hero_moby, 1, 0);
        if (h != 0) {
            func_L01_004DFEA0((s32)h->damage);
        } else {
            func_L01_004DFEA0(1);
        }
        D_001A4BE0.timer_1fc = 0x40;
    }
    return 1;
}
/* localdecomp:end func_L23_004CFA98 */
