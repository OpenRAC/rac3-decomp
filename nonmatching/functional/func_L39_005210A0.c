/* functional: high. Same reads, writes, calls and call order as retail PAL; written from the PAL assembly (the NTSC-U draft differs in several constants and callees: 0x11, 0x13, 1.4, 0xD/8/0x12, etc.). The key decode is the file's usual 5-step byte decode, written once as a helper. Retail's 0x2530 field of the player is the camera pointer. */
#include "vu0.h"

typedef union {
    vu0_v4 v;
    u32 w[4];
    u8 b[16];
} Buf_5210A0;
typedef struct {
    u8 pad0[0x10];
    void *(*object)(void *);
    u8 pad14[0x20];
    void (*set)(void *, s32, s32, s32, s32);
} VT_5210A0;
typedef struct {
    u8 pad0[0x14];
    VT_5210A0 *vtable;
    u8 pad18[0x2F4];
    s32 f30C;
    u8 pad310[0xA0];
    vu0_v4 v3B0;
    u8 pad3C0[0x64];
    s32 f424;
    u8 pad428[0x48];
    s32 f470;
    u8 pad474[0xDB8];
    u8 *target;
    u8 pad1230[0x10];
    vu0_v4 v1240;
    f32 f1250;
    u8 pad1254[0x5C];
    vu0_v4 v12B0;
    u8 pad12C0[0x50];
    s32 f1310;
    u8 pad1314[0x24];
    s32 f1338, f133C;
    u8 pad1340[0x6A4];
    u8 key;
    u8 pad19E5[0x22];
    u8 b1A07, b1A08;
    u8 pad1A09[0xB];
    u8 b1A14;
    u8 pad1A15[0x2B];
    u8 a1A40[0x10];
    u8 pad1A50[0xA79];
    u8 b24C9;
    u8 pad24CA[0x66];
    u8 *camera;
    s32 sound;
} Player_5210A0;
typedef struct {
    vu0_v4 origin[2], direction;
    u8 pad30[0x10];
    vu0_v4 target_pos;
    s16 h50, h52;
    s32 sound;
    Player_5210A0 *player;
    u32 target_id;
    s16 h60, h62, h64, h66;
    s32 f68, counter;
    u8 *target;
} P_5210A0;
typedef struct {
    u8 pad0[0x2C];
    u32 target_id;
    f32 point[3], normal[3];
    u8 pad48[8];
} Hit_5210A0;

extern u8 D_L39_004997E0[];
extern u8 D_L39_0049C890[];
extern u8 D_L39_004701E0[];
extern vu0_v4 D_L39_0025F760;
extern vu0_v4 D_001DF290_sda;
extern vu0_v4 D_001DF2A0_sda;
__asm__(".extern D_001DF290_sda, 16");
__asm__(".extern D_001DF2A0_sda, 16");
extern void func_L39_0061C4D0(void *, void *, s32);
extern void func_L01_00444F38(void *, s32, s32, s32, s32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CC88(void *, void *, s32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);
extern s32 func_L39_005FFD20(void *, void *, s32, f32);
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern u8 *func_L39_006472D0(void *, void *, void *, s32, f32, f32, f32, f32, f32);
extern u8 *func_00382348(void *);
extern s32 func_L39_00639D90(void *);
extern u32 func_0038DBD8(u32, u32, f32);
extern s32 func_L39_00648AE0(void *, s32);
extern u32 func_L39_0061D780(void *);
extern s32 func_L39_006732D0(void *, s32, s32, void *);
extern u8 func_L39_00673498(void *, s32);
extern void func_L39_00621D60(void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_003F2058(void *, s32);
extern void *func_L39_0061D1D8(u32);
extern void func_L39_005F33E0(s32, s32, void *);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern void func_L39_00533790(void *, void *, void *, void *, s32, s32, f32);
extern void func_L01_00404A10(void (*)(), void *);
extern void func_L39_00521FE0();
extern void func_L39_00521BC0();
extern void func_L39_00622288(void *);
extern void func_L01_003F2278(s32, s32);
extern s32 func_L01_003F1FC0(s32, s32);

static __inline__ u32 dec_5210A0(u8 *key, Buf_5210A0 *b)
{
    s32 n, k, m, i;
    u8 *dst;

    if (!*key) return 0;
    n = *key;
    m = n + 1;
    k = ((s32)key - n) & 7;
    dst = b->b;
    for (i = 0; i < 40; i += 5) *dst++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    b->w[0] ^= (u32)key;
    b->w[1] ^= b->w[0];
    return b->w[1];
}

void func_L39_005210A0(u8 *o)
{
    Buf_5210A0 a;
    Buf_5210A0 c;
    Hit_5210A0 hit;
    vu0_v4 previous, aim;
    P_5210A0 *p = *(P_5210A0 **)(o + 0x68);
    Player_5210A0 *player;
    u8 *target, *other, *target_data;
    void *handle;
    vu0_v4 *direction, *second, *right;
    s32 colour, status, flag;
    f32 ratio, f, d;

    if (o[0x20] == 0) {
        o[0x30] = 0xFF;
        p->sound = -1;
        p->h52 = 0;
        o[0x20] = 1;
        func_L39_0061C4D0(o, &p->player, 1);
        p->h66 = 1;
    }
    player = p->player;
    direction = &p->direction;
    second = &p->origin[1];
    right = (vu0_v4 *)(o + 0xD0);
    if ((dec_5210A0(&player->key, &a) ^ 1) == 0) player->vtable->set(player, 0x1D, 1, 0, 1);
    if (o[0x42] == o[0x43] && (o[0x60] & 2)) func_L01_00444F38(o, 1, 0, 2, 0);
    target = 0;
    func_0038D000(&a.v, &D_001DF290_sda, o + 0xC0);
    vec_add_ab(&a.v, &a.v, o + 0x10);
    p->origin[0] = a.v;
    func_0038D000(&c.v, &D_001DF2A0_sda, o + 0xC0);
    vec_add_ab(&c.v, &c.v, o + 0x10);
    p->origin[1] = c.v;
    func_0038CF68(direction, right, -1.0f);
    if (player->f1310) {
        func_0038CC88(&c.v, (p->h64 ? second : &p->origin[0]), 0x10);
        vec_sub_ab(direction, &player->v12B0, &c.v);
        if (0.8f < player->f1250) {
            flag = func_L39_005FFD20(&player->f1338, &player->f133C, 1, 150.0f);
            if (player->b1A14) func_L01_003F6F20(player->b24C9, o, flag, 0, 0x56, -1, 4, 0.7f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            target = player->target;
        } else {
            flag = func_L39_005FFD20(&player->f1338, &player->f133C, 0, 150.0f);
            if (player->b1A14) func_L01_003F6F20(player->b24C9, o, flag, 0, 0x56, -1, 4, 0.7f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            if (0.0f < func_0038CE68(direction, right)) func_0038CF68(direction, player->camera + 0x200, 20.0f);
            else func_0038CF68(direction, direction, 20.0f);
        }
    } else {
        *direction = player->v3B0;
        func_0038CF68(direction, direction, 20.0f);
        target = func_L39_006472D0(player, p, direction, 1, 0.05235988f, 0.05235988f, 35.0f, 0.7853982f, 0.6108652f);
    }
    if (player->b1A08) {
        func_0038CF68(direction, right, -20.0f);
        target = 0;
    }
    if (target) {
        p->target_pos = *(vu0_v4 *)(target + 0x10);
        target_data = func_00382348(target);
        if (target_data) {
            func_0038CE20(&c.v, target + 0xE0, *(f32 *)(target_data + 0x10));
            vec_add_ab(&p->target_pos, &p->target_pos, &c.v);
        }
        if ((dec_5210A0(&player->key, &c) ^ 0x1D) != 0) {
            ratio = (player->f1250 - 0.8f) / 0.19999999f;
            if (1.0f < ratio) ratio = 1.0f;
            else if (ratio < 0.0f) ratio = 0.0f;
            status = func_L39_00639D90(player);
            if (status) colour = func_0038DBD8(0xFF0FFFFF, 0xFF0F0FFF, ratio);
            else colour = 0xFF0F0FFF;
            f = func_0038CF00(player->camera, &p->target_pos) / 150.0f;
            f = fabs_asm(0.9f - f * 0.65f);
            if (player->b1A14) func_L01_003F6F20(player->b24C9, o, colour, &p->target_pos, 0x26, -1, 4, f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            if (target_data) {
                d = func_0038CF00(p, &p->target_pos);
                func_0038CE20(&c.v, &player->v1240, (d / 1.4f) * 0.8f);
                vec_add_ab(&p->target_pos, &p->target_pos, &c.v);
            }
        }
        func_0038CC88(&c.v, (p->h64 ? second : &p->origin[0]), 0x10);
        vec_sub_ba(direction, &p->target_pos, &c.v);
        func_0038CF68(direction, direction, 20.0f);
        p->target_id = func_L39_0061D780(target);
        p->target = target;
    } else {
        p->target = 0;
        p->target_id = 0xFFFFFFFF;
    }
    status = func_L39_006732D0(player->a1A40, 0, 1, &hit);
    if ((func_L39_00673498(player->a1A40, 0) && player->f470 >= 0x13) || status == 8 || status == 4) {
        p->h50 = 0x11;
        p->h52++;
        p->counter = 0;
        if (status == 8) {
            func_L39_00621D60(player, -1);
            *(f32 *)(o + 0x48) = 3.0f;
            if (o[0x43] != 2) func_003C3A10(o, 2, 0, 0);
            *(f32 *)(o + 0x48) = 3.0f;
            p->h66 = 1;
            p->sound = func_L01_003F2058(D_L39_004701E0, player->sound);
            other = 0;
            if (hit.target_id != 0xFFFFFFFF) {
                handle = func_L39_0061D1D8(hit.target_id);
                if (handle) other = (u8 *)(*(VT_5210A0 **)((u8 *)handle + 0x14))->object(handle);
            }
            func_0038CC88(&previous, (p->h64 ? second : &p->origin[0]), 0x10);
            p->h64 = (p->h64 == 0);
            if (other) {
                aim.x = hit.point[0];
                aim.y = hit.point[1];
                aim.z = hit.point[2];
                aim.w = 0.0f;
                vec_add_ba(&aim, &aim, other + 0x10);
                vec_sub_ab(&c.v, &aim, &previous);
                func_0038CF68(&c.v, &c.v, 1.4f);
            } else {
                c.v.y = hit.normal[1];
                c.v.x = hit.normal[0];
                c.v.z = hit.normal[2];
                c.v.w = 0.0f;
                func_0038CE20(&aim, right, -1.0f);
                func_0038CF68(&c.v, &c.v, 1.0f);
                if (func_0038CE68(&c.v, &aim) < 0.866f) c.v = aim;
                func_0038CE20(&c.v, &c.v, 1.4f);
            }
            func_L39_005F33E0(3, 0, o);
            if (func_003D3CB0(o + 0x10, &previous, 0, p->player->f424, 0)) {
                vec_sub_ba(&aim, &D_L39_0025F760, o + 0x10);
                f = func_0038CEA8(&aim);
                func_0038CF68(&aim, &aim, f - 0.05f);
                vec_add_ab(&previous, &aim, o + 0x10);
                func_0038CF68(&c.v, right, -1.4f);
            }
            if (func_L39_00648AE0(player, 1)) flag = *(s8 *)(D_L39_0049C890 + 0xA1);
            else flag = 1;
            func_L39_00533790(o, player, &previous, &c.v, 0x10001, 1, *(f32 *)(D_L39_0049C890 + (flag << 7) + 0x30));
            func_L01_00404A10(func_L39_00521FE0, o);
            func_L39_00521BC0(o);
        } else if (status == 4 && p->h66 == 1) {
            func_L39_005F33E0(4, 0, o);
            p->h66 = 0;
        }
    } else {
        p->counter++;
        if (player->f30C >= 0xD && p->counter >= 8) func_L39_00622288(player);
        if (p->counter >= 0x12) p->h66 = 1;
        if (p->h50 <= 0) p->h52 = 0;
    }
    if (status != 8 || !player->b1A07) {
        if (p->sound >= 0) {
            func_L01_003F2278(p->sound, player->sound);
            p->sound = -1;
        }
    }
    if (p->sound > 0 && !func_L01_003F1FC0(p->sound - 1, player->sound)) p->sound = -1;
}
