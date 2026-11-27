#include "common.h"

typedef struct {
    u8 pad0[104];
    u8 *inner;
} Obj3899C0;
typedef struct {
    u8 b[8];
} Pair_371CB8;
typedef struct {
    u8 pad0[16];
    f32 pos[4];
    u8 pad32[4];
    s32 i36;
    s32 i40;
    u8 pad44[4];
    f32 f48;
} Obj_371CB8;
typedef struct {
    u8 pad_0[0x80];
    f32 x;                     /* 0x80: position */
    f32 y;                     /* 0x84 */
    u8 pad_88[0x1210 - 0x88];
    s32 fire_button;           /* 0x1210: the button the item fires on */
    u8 pad_1214[0x25C0 - 0x1214];
    u8 *camera;                /* 0x25C0 */
    s32 state;                 /* 0x25C4: the hero's state (0x1D aiming) */
    u8 pad_25C8[0x25ED - 0x25C8];
    u8 no_firing;              /* 0x25ED: guns refuse to fire while set */
    u8 pad_25EE[0x2874 - 0x25EE];
    s16 mode;                  /* 0x2874 */
    u8 pad_2876[0x28BC - 0x2876];
    s32 aiming_fire_wait;      /* 0x28BC: 40 outside state 29 */
} Hero_3727B8;

INCLUDE_ASM("asm/levels", func_L01_0036B670);

/* localdecomp:start func_L01_0036C828 */
#include "vu0.h"
typedef struct { u8 pad[0x54]; s32 mode; } Vars_0036C828;
typedef struct { u8 pad[0x18]; u8 *hit; u8 pad1C[4]; vu0_v4 pos; } Hit_0036C828;
typedef struct { u8 p0; u8 effect; u8 p2[0x6A]; f32 damage; u8 p70[0x80]; } Weapon_0036C828;
extern Hit_0036C828 D_L01_001EAA00;
extern vu0_v4 D_L01_001EAA20;
extern u8 *D_001A71A0[];
extern u8 D_001425C0[];
extern Weapon_0036C828 D_L01_002C5600_0036C828[];
u8 *func_L01_0036C828(u8 *owner, vu0_v4 *from, vu0_v4 *to, f32 *out, f32 damage) {
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
    extern void func_L01_00389B00(void *, void *, void *, s32, f32);
    extern void func_L01_0036AA60(void *, void *, void *, s32, f32);
    extern f32 func_0038CF00(void *, void *);
    extern void func_L01_00446978(u8 *, f32 *);
    extern void func_L01_0034C9F0(u8 *, s32, u8 *);
    Vars_0036C828 *vars;
    vu0_v4 delta;
    f32 dist;
    u8 *hit;
    u8 *result;
    vars = *(Vars_0036C828 **)(owner + 0x68);
    vec_sub_ab(out, to, from);
    func_0038CF68(out, out, 1.5f);
    out[3] = 5627.9248046875f;
    if (func_003D3CB0(from, to, 16, D_001A71A0[0], 0)) {
        vec_sub_ba(&delta, to, from);
        func_0038CF68(&delta, &delta, 1.0f);
        vec_sub_ba(&delta, &D_L01_001EAA20, from);
        if (vars->mode) func_L01_00389B00(from, &delta, &D_L01_001EAA20, 1, damage);
        else func_L01_0036AA60(from, &delta, &D_L01_001EAA20, 1, damage);
        if (D_L01_001EAA00.hit != 0) {
            damage = ((Weapon_0036C828 *)(D_001425C0[0x27] * 0xF0 + (u8 *)D_L01_002C5600_0036C828))->damage;
            if (vars->mode) damage *= 3.0f;
            dist = func_0038CF00(&D_L01_001EAA00.pos, from);
            if (dist < 10.0f) out[7] = damage;
            else if (dist < 14.0f) out[7] = damage * 0.75f;
            else if (dist < 20.0f) out[7] = damage * 0.5f;
            else out[7] = damage * 0.125f;
            func_L01_00446978(D_L01_001EAA00.hit, out);
            if (D_L01_002C5600_0036C828[D_001425C0[0x27]].effect) func_L01_0034C9F0(D_L01_001EAA00.hit, 39, owner);
            hit = D_L01_001EAA00.hit;
            if (hit == 0) goto none;
            if (*(u8 **)(hit + 0x24) == 0) goto none;
            result = hit;
            if ((*(u8 **)(hit + 0x24))[0x46] == 5) goto done;
            goto none;
        }
    } else {
        vec_sub_ab(&delta, to, from);
        if (vars->mode) func_L01_00389B00(from, &delta, to, 0, damage);
        else func_L01_0036AA60(from, &delta, to, 0, damage);
    }
none:
    result = 0;
done:
    return result;
}
/* localdecomp:end func_L01_0036C828 */

/* localdecomp:start func_L01_0036CB08 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_0036CB08;

extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, s32, void *, f32, u32, s32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_L01_00448D88(u32, s32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);

typedef struct { u8 p0[0x110]; u8 v110[0x250]; s32 f360; u8 p364[0x6C0 - 0x364]; u8 v6C0[0x10]; u8 v6D0[0x10]; } H_0036CB08;
extern H_0036CB08 D_001A4BE0_0036CB08;
void func_L01_0036CB08(u8 *self, V4_0036CB08 *pos) {
    V4_0036CB08 q;
    V4_0036CB08 dir;
    V4_0036CB08 up = { 0.3f, -1.0f, 0.0f };
    V4_0036CB08 center;
    V4_0036CB08 step;
    V4_0036CB08 p60;
    V4_0036CB08 drift;
    V4_0036CB08 off;
    V4_0036CB08 p90;
    u8 *p;
    f32 ang;
    f32 life;
    f32 scale;
    s32 i;
    s32 j;
    s32 n;
    u8 *e;
    u8 *sub;

    up.w = 1.0f;
    ang = 0.0f;
    center = *pos;
    func_0038D890(&up, D_001A4BE0_0036CB08.v6C0, D_001A4BE0_0036CB08.v6D0, 0.34906584f);
    dir = up;
    qzero(&drift);
    if (D_001A4BE0_0036CB08.f360 != 0) {
        func_0038CE20(&drift, D_001A4BE0_0036CB08.v110, 1.7f);
    }
    func_0038CE20(&off, D_001A4BE0_0036CB08.v6C0, 0.4f);
    vec_add_ab(&center, &center, &off);
    for (i = 0; i < 20; i++) {
        ang = func_0038DAB8(ang, func_003824E0(0.0f, 0.62831855f));
        func_0038CE20(&step, &dir, func_003824E0(0.24000001f, 0.32000002f));
        vec_add_ab(&step, &step, &drift);
        p60.x = center.x + func_L01_00443A18(0.0f, 0.3f);
        p60.y = center.y + func_L01_00443A18(0.0f, 0.3f);
        p60.z = center.z + func_L01_00443A18(0.0f, 0.3f);
        n = func_L01_00443A18(1.0f, 2.0f);
        e = func_L01_004669B0(&p60, 0.0f, 1.0f, 1.01f, n, D_001A4BE0_0036CB08.v110,
                              func_003824E0(0.2f, 0.75f) * 210000.0f, 0x7FFFFFFF, 0);
        if (e != 0) {
            e[3] = 0x48;
            *(s16 *)(e + 0xA) = 50;
            e[9] = 0x44;
            sub = e + 0x20;
            *(f32 *)(sub + 0x1C) = 4.0f;
            *(s32 *)(sub + 0x4) = 3;
            sub[0xA] = 0x30;
            sub[0xB] = e[0xA];
        }
        p60.x = center.x + func_L01_00443A18(0.0f, 0.6f);
        p60.y = center.y + func_L01_00443A18(0.0f, 0.6f);
        p60.z = center.z + func_L01_00443A18(0.0f, 0.6f);
        life = func_003824E0(0.2f, 1.75f);
        vec_sub_ab(&p60, &p60, &step);
        func_L01_0046A610(&p60, &step, 5, 0x7F, 0x404040, n, life * 210000.0f, 500.0f, 0.95f, 0.0f, 0.0f);
        if (fabs_asm(ang) > 1e-5f) {
            func_003C4840(&q, D_001A4BE0_0036CB08.v6C0, ang);
            func_0038D850(&dir, &up, &q);
        }
    }
    {
        f32 k = func_003824E0(8.0f, 12.0f) * 0.020000001f;
        func_0038CE20(&up, D_001A4BE0_0036CB08.v6C0, k);
    }
    scale = 0.5f;
    for (j = 0; j < 2; j++) {
        f32 pitch = func_003824E0(0.2617994f, 1.3962634f);
        f32 yaw = func_00382538();
        func_00382760(&p90, scale * (func_003824E0(7.0f, 10.5f) * 0.020000001f), yaw, pitch);
        vec_add_ab(&p90, &p90, &up);
        p90.z += 0.060000002f;
        {
            s32 c0 = func_L01_00448D88(0x4F007FFF, 0);
            s32 c1 = func_L01_00448D88(0x1F00007F, 0);
            func_L01_00465738(pos, &p90, c0, c1, func_00382498(50, 100), 1, -1, -1, 0, scale * 40000.0f);
        }
    }
}
/* localdecomp:end func_L01_0036CB08 */

INCLUDE_ASM("asm/levels", func_L01_0036D018);

/* localdecomp:start func_L01_0036D8C8 */
#include "vu0.h"
typedef int Q_0036D8C8 __attribute__((mode(TI)));
typedef union { Q_0036D8C8 q; f32 f[4]; } V_0036D8C8;
typedef struct {
    u8 pad[0x25C0];
    u8 *camera;
    u8 pad25C4[0x2874-0x25C4];
    s16 mode;
} Hero_0036D8C8;
extern Hero_0036D8C8 D_001A4BE0_0036D8C8;
extern f32 D_L01_001E1D20;
extern s32 D_L01_001E1D1C;
extern f32 D_L01_001DD85C;
__asm__(".extern D_L01_001DD85C, 4");
extern f32 D_L01_001DD858;
__asm__(".extern D_L01_001DD858, 4");
extern f32 D_L01_001DD854;
__asm__(".extern D_L01_001DD854, 4");
extern s32 D_L01_001DD868;
__asm__(".extern D_L01_001DD868, 4");
extern s32 D_L01_001DD86C;
__asm__(".extern D_L01_001DD86C, 4");
void func_L01_0036D8C8(u8 *obj) {
    extern void func_003C2F58(s32,s32,void *);
    extern void func_0038CE20(void *,void *,f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32,f32);
    extern void func_0038D328(void *,void *);
    extern void func_003D9740(void *,s32,u32,s32,s32,f32);
    V_0036D8C8 matrix[4];
    V_0036D8C8 position, direction, rotation, offset;
    func_003C2F58((s32)obj,0,&position);
    if(D_001A4BE0_0036D8C8.mode) func_0038CE20(&direction,obj+0xD0,-1.0f);
    else direction.q=*(Q_0036D8C8 *)(D_001A4BE0_0036D8C8.camera+0xC0);
    rotation.f[0]=0.0f;
    rotation.f[1]=-func_0038D160(func_0038CED8(&direction),direction.f[2]) + -1.5707964f;
    rotation.f[2]=func_0038D160(direction.f[0],direction.f[1]);
    rotation.f[3]=1.0f;
    func_0038D328(matrix,&rotation);
    if(D_001A4BE0_0036D8C8.mode) func_0038CE20(&offset,obj+0xD0,-1.0f);
    else offset.q=*(Q_0036D8C8 *)(D_001A4BE0_0036D8C8.camera+0xC0);
    func_0038CE20(&offset,&offset,5.0f);
    vec_add_ab(&position, &position, &offset);
    *(Q_0036D8C8 *)&matrix[3]=*(Q_0036D8C8 *)&position;
    func_0038CE20(&matrix[0],&matrix[0],D_L01_001DD85C);
    func_0038CE20(&matrix[1],&matrix[1],D_L01_001DD858);
    func_0038CE20(&matrix[2],&matrix[2],D_L01_001DD854);
    D_L01_001E1D20 += 0.2f;
    if(D_L01_001E1D20 >= 7.0f) D_L01_001E1D20 -= 7.0f;
    func_003D9740(matrix,D_L01_001DD868,(D_L01_001E1D1C*5 <<24)|0x00FF8080,4,1,D_L01_001E1D20);
    func_0038CE20(&matrix[0],&matrix[0],D_L01_001DD85C*1.25f);
    func_0038CE20(&matrix[1],&matrix[1],D_L01_001DD858*1.25f);
    func_003D9740(matrix,D_L01_001DD86C,(D_L01_001E1D1C*3 <<24)|0x00FFC480,2,1,D_L01_001E1D20);
}
/* localdecomp:end func_L01_0036D8C8 */

/* localdecomp:start func_L01_0036DB20 */
extern s32 D_L01_001E1D18;
extern void func_003C2F58(s32, s32, void *);
extern void func_L01_0036DB78(void *, s32, s32, f32, f32, f32, f32);
void func_L01_0036DB20(s32 a0) {
    u8 buf[16];
    func_003C2F58(a0, 0, buf);
    func_L01_0036DB78(buf, 66, D_L01_001E1D18 * 5, 1.0f, 0.0f, 0.0f, 0.9f);
}
/* localdecomp:end func_L01_0036DB20 */

/* localdecomp:start func_L01_0036DB78 */
extern s32 D_L01_001DD870;
__asm__(".extern D_L01_001DD870, 4");
extern s32 D_L01_001DD878;
__asm__(".extern D_L01_001DD878, 4");
extern s32 D_L01_001DD87C;
__asm__(".extern D_L01_001DD87C, 4");
extern s32 D_L01_001DD880;
__asm__(".extern D_L01_001DD880, 4");
extern s32 D_L01_001DD884;
__asm__(".extern D_L01_001DD884, 4");
extern s32 D_L01_001DD888;
__asm__(".extern D_L01_001DD888, 4");
extern s32 D_L01_001DD88C;
__asm__(".extern D_L01_001DD88C, 4");
extern s32 D_L01_001DD890;
__asm__(".extern D_L01_001DD890, 4");
extern s32 D_L01_001DD894;
__asm__(".extern D_L01_001DD894, 4");
extern s32 D_L01_001DD898;
__asm__(".extern D_L01_001DD898, 4");
extern s32 D_L01_001DD89C;
__asm__(".extern D_L01_001DD89C, 4");
extern s32 D_L01_001DD8A0;
__asm__(".extern D_L01_001DD8A0, 4");
extern s32 D_L01_001DD8A4;
__asm__(".extern D_L01_001DD8A4, 4");
extern s32 D_L01_001DD8A8;
__asm__(".extern D_L01_001DD8A8, 4");
extern s32 D_L01_001DD8CC;
__asm__(".extern D_L01_001DD8CC, 4");
typedef struct {
    u8 pad_0[0x150];
    s16 width;                 /* 0x150: the frame's width */
    s16 height;                /* 0x152: the frame's height */
} Screen_36DB78;

extern s32 D_001D5520;
extern s32 D_001A1ED0[];
extern Screen_36DB78 D_001CFEC0;
extern void func_L01_004C5E28(void);
extern void func_003A9440(s32 code, long value);
extern void func_003D1030(void);
extern long func_00389598(s32 tex);
extern void func_0038B4D0(s32 x0, s32 y0, s32 x1, s32 y1, s32 u0, s32 v0, s32 u1, s32 v1, long colour, long tex);

/* screen_warp_draw: redraws the frame (texture -7) in four mirrored quarters through the warp's
   texture; the Nitro, Flux scope and RY3NO code have copies */
void func_L01_0036DB78(void *buf, s32 tex, s32 alpha, f32 a, f32 b, f32 c, f32 d)
{
    long colour;
    long frame_tex;
    s32 w;
    s32 h;

    func_L01_004C5E28();
    if (D_001D5520) {
        D_L01_001DD8CC = -1;
        D_L01_001DD8A4 = 0xEC;
        D_L01_001DD8A8 = 0xF0;
    }
    func_003A9440(0x4E, (D_001A1ED0[2] >> 13) | 0x1000000 | 0x100000000);
    func_003A9440(0x42, (long)D_L01_001DD87C | ((long)D_L01_001DD880 << 2) | ((long)D_L01_001DD884 << 4) | ((long)D_L01_001DD888 << 6) | 0x8000000000);
    func_003D1030();
    frame_tex = func_00389598(D_L01_001DD870);
    colour = (alpha << 24) | 0x7F7F7F;
    func_0038B4D0(0, 0, (s32)(D_001CFEC0.width * 0.5f), (s32)(D_001CFEC0.height * 0.5f), 0, 0, 0xFF, 0xFF, colour, frame_tex);
    func_0038B4D0(D_001CFEC0.width, 0, -(s32)(D_001CFEC0.width * 0.5f), (s32)(D_001CFEC0.height * 0.5f), 0, 0, 0xFF, 0xFF, colour, frame_tex);
    func_0038B4D0(0, D_001CFEC0.height, (s32)(D_001CFEC0.width * 0.5f), -(s32)(D_001CFEC0.height * 0.5f), 0, 0, 0xFF, 0xFF, colour, frame_tex);
    func_0038B4D0(D_001CFEC0.width, D_001CFEC0.height, -(s32)(D_001CFEC0.width * 0.5f), -(s32)(D_001CFEC0.height * 0.5f), 0, 0, 0xFF, 0xFF, colour, frame_tex);
    func_003A9440(0x42, (long)D_L01_001DD87C | ((long)D_L01_001DD880 << 2) | ((long)D_L01_001DD884 << 4) | ((long)D_L01_001DD888 << 6) | 0x8000000000);
    func_003A9440(0x42, (long)D_L01_001DD88C | ((long)D_L01_001DD890 << 2) | ((long)D_L01_001DD894 << 4) | ((long)D_L01_001DD898 << 6) | 0x8000000000);
    func_0038B4D0(0, 0, D_001CFEC0.width, D_001CFEC0.height, D_L01_001DD89C, D_L01_001DD8A0, D_L01_001DD8A4, D_L01_001DD8A8, D_L01_001DD878, func_00389598(D_L01_001DD8CC));
    func_003A9440(0x4E, 0x1000000 | (D_001A1ED0[2] >> 13));
}
/* localdecomp:end func_L01_0036DB78 */

/* localdecomp:start func_L01_0036DEB0 */
#include "vu0.h"
extern void func_L01_0040E020(void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_00382468_0036DEB0(s32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, s32, void *, f32, u32, s32);

void func_L01_0036DEB0(u8 *self) {
    vu0_v4 pos;
    vu0_v4 off;
    vu0_v4 vel;
    s32 i;
    s32 j;
    s32 k;
    s32 life;
    f32 size;

    if (self[0xBC] == 0) {
        return;
    }
    func_L01_0040E020(self + 0xBC);
    func_0038CE20(&pos, self + 0xD0, 0.1f);
    vec_add_ba(&pos, &pos, self + 0x10);
    func_0038CE20(&off, self + 0xC0, 0.275f);
    vec_add_ab(&pos, &pos, &off);
    func_0038CE20(&vel, self + 0xD0, 0.120000005f);
    for (i = 0; i < 4; i++) {
        u8 *p;
        k = func_00382468_0036DEB0(0x10);
        if (func_00382468_0036DEB0(2) != 0) {
            k = -k;
        }
        p = func_L01_004669B0(&pos, 0.04f, 1.0f, 0.9f, k, &vel, 84000.0f, 0x7F204080, 0);
        if (p != 0) {
            u8 *t = p + 0x20;
            *(s16 *)(p + 0xA) = 7;
            p[9] = ((*(s16 *)(self + 0x32) >> 5) << 4) + 4;
            *(s32 *)(t + 4) = 2;
            t[0xA] = 0x7F;
            t[0xB] = p[0xA];
        }
    }
    k = 0x10;
    size = 15750.001f;
    life = 2;
    for (j = 0; j < 3; j++) {
        u8 *p;
        p = func_L01_004669B0(&pos, 0.02f, 1.0f, 1.0f, k, &vel, size, 0x7FFFFFFF, 0);
        if (p != 0) {
            u8 *t = p + 0x20;
            p[9] = ((*(s16 *)(self + 0x32) >> 5) << 4) + 4;
            *(s16 *)(p + 0xA) = life;
            p[8] = func_00382468_0036DEB0(0xFF);
            *(s32 *)(t + 4) = 2;
            t[0xA] = 0x7F;
            t[0xB] = p[0xA];
        }
        k = -k;
        life <<= 1;
        size -= 3150.0f;
    }
}
/* localdecomp:end func_L01_0036DEB0 */

/* localdecomp:start func_L01_0036E120 */
#include "vu0.h"

extern f32 D_L01_001DD8D0;
__asm__(".extern D_L01_001DD8D0, 4");
extern f32 D_L01_001DD8D4;
__asm__(".extern D_L01_001DD8D4, 4");
extern s32 D_L01_001DD8D8;
__asm__(".extern D_L01_001DD8D8, 4");
extern s32 D_L01_001DD8DC;
__asm__(".extern D_L01_001DD8DC, 4");
extern s32 D_L01_001DD8E0;
__asm__(".extern D_L01_001DD8E0, 4");
extern f32 D_L01_001DD8E4;
__asm__(".extern D_L01_001DD8E4, 4");
extern f32 D_L01_001DD8E8;
__asm__(".extern D_L01_001DD8E8, 4");
extern f32 D_L01_001DD8EC;
__asm__(".extern D_L01_001DD8EC, 4");
extern f32 D_L01_001DD8F0;
__asm__(".extern D_L01_001DD8F0, 4");
extern f32 D_L01_001DD8F4;
__asm__(".extern D_L01_001DD8F4, 4");
extern f32 D_L01_001DD8F8;
__asm__(".extern D_L01_001DD8F8, 4");

extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern u8 *func_L01_004660F8(void *, void *);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
typedef struct { u8 p0[0x110]; u8 v110[0x250]; s32 f360; u8 p364[0x6C0 - 0x364]; u8 v6C0[0x10]; u8 v6D0[0x10]; } H_0036E120;
extern H_0036E120 D_001A4BE0_0036E120;
extern u8 *D_L01_00221098_0036E120[];
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L01_0036E120(u8 *a0) {
    vu0_v4 q;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    u8 *p;
    u8 *r;
    s32 i;
    f32 ang;
    s32 life;
    s32 spin;
    f32 f;
    vu0_v4 *c;
    s32 col;

    *(vu0_q *)&v20 = 0;
    v20.x = 0.3f;
    v20.y = -1.0f;
    v20.w = 1.0f;
    col = 0x307F7F7F;
    func_0038D000(&v20, &v20, a0 + 0xC0);
    ang = 0.0f;
    vec_add_ab(&v30, a0 + 0x10, &v20);
    a0[0xBC] = 5;
    func_0038D890(&v20, D_001A4BE0_0036E120.v6C0, D_001A4BE0_0036E120.v6D0, 0.34906584f);
    v10 = v20;
    for (i = 19; i >= 0; i--) {
        ang = func_0038DAB8(ang, func_003824E0(0.0f, 0.62831855f));
        func_0038CE20(&v40, &v10, func_003824E0(0.120000005f, 0.36f));
        p = func_L01_004660F8(&v30, &v40);
        if (p != 0) {
            c = (vu0_v4 *)(p + 0x30);
            func_0038CE20(&v40, &v10, 0.75f);
            vec_add_ab(p + 0x10, &v30, &v40);
            *(vu0_v4 *)(p + 0x20) = v30;
            c->w = 2.0f;
            *(f32 *)(p + 0x1C) = 0.05f;
            *(f32 *)(p + 0x2C) = 0.5f;
            *(s32 *)(p + 0x4) = col;
            *(s32 *)(p + 0xC) = col;
        }
        if (fabs_asm(ang) > 1e-5f) {
            func_003C4840(&q, D_001A4BE0_0036E120.v6C0, ang);
            func_0038D850(&v10, &v20, &q);
        }
    }
    func_0038D890(&v20, D_001A4BE0_0036E120.v6C0, D_001A4BE0_0036E120.v6D0, D_L01_001DD8D0 * 0.017453292f);
    ang = 0.0f;
    v10 = v20;
    qzero(&v60);
    if (D_001A4BE0_0036E120.f360 != 0) {
        func_0038CE20(&v60, D_001A4BE0_0036E120.v110, 1.7f);
    }
    for (i = 0; i < 20; i++) {
        ang = func_0038DAB8(ang, func_003824E0(0.0f, 0.62831855f));
        func_0038CE20(&v40, &v10, func_003824E0(D_L01_001DD8E8 * 0.020000001f, D_L01_001DD8EC * 0.020000001f));
        vec_add_ab(&v40, &v40, &v60);
        life = (D_L01_001DD8E0 * 5 + 2) / 6;
        spin = func_L01_00443A18(1.0f, 2.0f);
        v50.x = v30.x + func_L01_00443A18(0.0f, D_L01_001DD8D4);
        v50.y = v30.y + func_L01_00443A18(0.0f, D_L01_001DD8D4);
        v50.z = v30.z + func_L01_00443A18(0.0f, D_L01_001DD8D4);
        f = func_003824E0(D_L01_001DD8F0, D_L01_001DD8F4);
        vec_sub_ab(&v50, &v50, &v40);
        r = func_L01_0046A610(&v50, &v40, life, D_L01_001DD8D8, D_L01_001DD8DC, spin,
                          f * 210000.0f, D_L01_001DD8F8, D_L01_001DD8E4, 0.0f, 0.0f);
        if (r != 0) {
            r[2] = D_L01_00221098_0036E120[0x5B][0];
        }
        if (fabs_asm(ang) > 1e-5f) {
            func_003C4840(&q, D_001A4BE0_0036E120.v6C0, ang);
            func_0038D850(&v10, &v20, &q);
        }
    }
}
/* localdecomp:end func_L01_0036E120 */

/* localdecomp:start func_L01_0036E578 */
#include "vu0.h"
typedef struct {
    u8 pad_0[0x80];
    vu0_v4 pos;                /* 0x80 */
    u8 pad_90[0x6F0 - 0x90];
    vu0_v4 aim;                /* 0x6F0 */
    u8 pad_700[0xBD8 - 0x700];
    u8 *last_lockon;           /* 0xBD8 */
    u8 pad_BDC[0x1210 - 0xBDC];
    s32 fire_button;           /* 0x1210 */
    u8 pad_1214[0x1220 - 0x1214];
    s32 i1220;                 /* 0x1220 */
    u8 pad_1224[0x1430 - 0x1224];
    u8 *lockon_target;         /* 0x1430 */
    u8 pad_1434[0x16B0 - 0x1434];
    s32 i16B0;                 /* 0x16B0 */
    u8 pad_16B4[0x16D4 - 0x16B4];
    s32 i16D4;                 /* 0x16D4 */
    s32 i16D8;                 /* 0x16D8 */
    u8 pad_16DC[0x25C0 - 0x16DC];
    u8 *moby;                  /* 0x25C0 */
    s32 state;                 /* 0x25C4 */
    u8 pad_25C8[0x25E9 - 0x25C8];
    u8 b25E9;                  /* 0x25E9 */
    u8 pad_25EA[0x25ED - 0x25EA];
    u8 no_firing;              /* 0x25ED */
    u8 pad_25EE[0x2874 - 0x25EE];
    s16 h2874;                 /* 0x2874 */
    u8 pad_2876[0x28BC - 0x2876];
    s32 aiming_fire_wait;      /* 0x28BC */
} Hero_0036E578;
typedef struct {
    f32 timer;                 /* 0x00 */
    u8 pad_4[0xC - 4];
    f32 spin;                  /* 0x0C */
    u8 *target;                /* 0x10 */
    s32 lose_wait;             /* 0x14 */
    f32 radius;                /* 0x18 */
    s16 light;                 /* 0x1C */
    s16 flash;                 /* 0x1E */
    u8 *last;                  /* 0x20 */
    s32 lock_wait;             /* 0x24 */
    s32 aiming;                /* 0x28 */
    s32 rumble;                /* 0x2C */
} Vars_0036E578;
typedef struct { u8 pad_0; u8 kind; u8 pad_2[0x50 - 2]; f32 rate; u8 pad_54[0xF0 - 0x54]; } Row_0036E578;
typedef struct { f32 r, g, b, pad; vu0_v4 pos; } Light_0036E578;
extern Hero_0036E578 D_001A4BE0_0036E578;
extern u8 *D_001D52FC;
extern u8 D_00142A60[];
extern s32 D_L01_001D6694;
extern s32 D_L01_001E1D24;
extern u8 D_L01_002B3940[];
extern Row_0036E578 D_L01_002C5600_0036E578[];
extern u8 *D_L01_001EEA80[];
extern Light_0036E578 D_L01_001F1B40[];
extern vu0_v4 D_L01_001E29C0_0036E578;

void func_L01_0036E578(u8 *self)
{
    extern s32 func_L01_0040E050(void *);
    extern void func_L01_005003D0(s32, s32);
    extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
    extern u32 func_L01_004CB1F0(f32, f32);
    extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
    extern u8 *func_L01_00450BB0(void *, void *, f32, f32, f32, f32, f32, s32);
    extern u8 *func_00382348(void *);
    extern s32 func_0038CAD0(void *);
    extern f32 func_0038CF00(void *, void *);
    extern void func_L01_004CB128(void *, void *, s32);
    extern void func_003C3A10(void *, s32, s32, s32);
    extern s32 func_L01_005118D0(s32, s32);
    extern s32 func_003D4D00(void *, s32, void *, s32, f32);
    extern s32 func_003C4B50(void *);
    extern s32 func_003A52A0(s32, s32, void *);
    extern void func_L01_004EA7D8(s32);
    extern s32 func_L01_003F2058(void *, s32);
    extern s32 func_L01_005119E0(s32);
    extern void func_L01_003F2278(s32, s32);
    extern s32 func_L01_00424CB0(void *, f32, f32, f32, f32, f32);
    extern void func_0038CB00(void *);
    extern void func_L01_00424D88(s32);
    extern void func_L01_0036F120(u8 *);
    Vars_0036E578 *v;
    u8 *target;
    u8 *info;
    u8 *c;
    s32 i;
    s32 n;
    s32 can_fire;
    f32 d;
    f32 cone;
    f32 cone2;
    f32 cr;
    f32 cg;
    f32 cb;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 w;
    vu0_v4 pos;
    vu0_v4 off;
    vu0_v4 off2;

    v = *(Vars_0036E578 **)(self + 0x68);
    if (self[0x20] == 0) {
        self[0x20] = 1;
        v->light = -1;
        v->lock_wait = 4;
        v->rumble = -1;
        v->flash = 0;
        v->target = 0;
        v->last = 0;
        v->aiming = 0;
    }
    if ((D_L01_002C5600_0036E578 + D_001425C0[0x3F])->kind >= 2)
        D_00142A60[0x3F] |= 2;
    if ((D_L01_002C5600_0036E578 + D_001425C0[0x3F])->kind >= 3)
        D_00142A60[0x3F] |= 0x20;
    func_L01_0036DEB0(self);
    func_L01_0040E050(&v->timer);
    if (D_001A4BE0_0036E578.state == 1)
        func_L01_005003D0(0x1D, 1);
    if (self[0x42] == self[0x43] && (self[0x60] & 2))
        func_L01_00444F38(self, 1, 0, 2, 0);
    if (D_001A4BE0_0036E578.lockon_target != 0)
        D_001A4BE0_0036E578.last_lockon = D_001A4BE0_0036E578.lockon_target;
    {
        u8 kind = (D_L01_002C5600_0036E578 + D_001425C0[0x3F])->kind;
        if (kind == 2)
            *(s16 *)(self + 0x7C) = 3;
        else if (kind == 1)
            *(s16 *)(self + 0x7C) = kind;
        else if (kind >= 3)
            *(s16 *)(self + 0x7C) = 7;
    }
    if ((D_001A4BE0_0036E578.state == 0x1D && (*(u16 *)(D_001A4BE0_0036E578.moby + 0x34) & 1)) ||
        D_001A4BE0_0036E578.i16B0 != 0) {
        if (v->aiming == 0) {
            v->target = 0;
            v->lock_wait = 4;
        }
        v->aiming = 1;
        func_L01_003F6F20(0, self, func_L01_004CB1F0(0.97f, 150.0f), 0, 0x44, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f,
                          40.0f, 40.0f);
        cone = cone2 = 0.06981317f;
        if (D_001A4BE0_0036E578.h2874 != 0 && D_001A4BE0_0036E578.i16B0 != 2) {
            func_0038CE20(&a, self + 0xD0, -1.0f);
        } else {
            vu0_v4 *p = &D_001A4BE0_0036E578.aim;
            a = *p;
        }
        func_0038CE20(&b, D_001A4BE0_0036E578.moby + 0xE0, 0.75f);
        vec_add_ab(&b, &D_001A4BE0_0036E578.pos, &b);
    } else {
        D_001A4BE0_0036E578.i16D4 = 0;
        D_001A4BE0_0036E578.i16D8 = 0;
        v->aiming = 0;
        cone = 0.31415927f;
        cone2 = 0.29670596f;
        if (D_001A4BE0_0036E578.h2874 != 0 && D_001A4BE0_0036E578.i16B0 != 2) {
            func_0038CE20(&a, self + 0xD0, -1.0f);
        } else {
            vu0_v4 *p = &D_001A4BE0_0036E578.aim;
            a = *p;
        }
        func_0038CE20(&b, D_001A4BE0_0036E578.moby + 0xE0, 0.75f);
        vec_add_ab(&b, &D_001A4BE0_0036E578.pos, &b);
    }
    target = func_L01_00450BB0(&b, &a, cone, cone2, 30.0f, cone, cone, 1);
    if (v->target != 0) {
        info = func_00382348(v->target);
        c = v->target;
        if (c == 0 || c[0x20] == 0xFE || c[0x20] == 0xFD || *(u8 **)(c + 0x24) == 0 ||
            (*(u8 **)(c + 0x24))[0x46] != 5 || (info != 0 && *(f32 *)info <= 0.0f) || c[0x31] == 0 ||
            D_001A4BE0_0036E578.h2874 != 0) {
            v->target = 0;
            v->lock_wait = 4;
        } else if (target != v->target) {
            if (func_0038CAD0(&v->lose_wait) != 0) {
                v->target = 0;
                v->lock_wait = 4;
            }
        } else {
            v->lose_wait = 4;
            if (D_001A4BE0_0036E578.i16B0 == 0) {
                d = func_0038CF00(&D_L01_001E29C0_0036E578, target + 0x10) / 150.0f;
                func_L01_004CB128(&w, target, 0);
                v->spin = func_0038DAB8(v->spin, 0.034906585f);
                func_L01_003F6F20(0, self, 0xFF0FFF0F, &w, 0x26, -1, 4, fabs_asm(0.9f - d * 0.65f), -v->spin, 90.0f,
                                  0.5f, 0.5f, 40.0f, 40.0f);
            }
            D_001A4BE0_0036E578.last_lockon = target;
        }
    } else if (target == v->last) {
        if (func_0038CAD0(&v->lock_wait) != 0) {
            v->target = target;
            v->lose_wait = 4;
            {
                u8 *ri = func_00382348(target);
                if (ri == 0)
                    v->radius = 0.1f;
                else
                    v->radius = *(f32 *)(ri + 0x10);
            }
        }
    } else {
        v->lock_wait = 4;
    }
    v->last = target;
    target = v->target;
    can_fire = 1;
    if (D_001A4BE0_0036E578.state == 0x1D) {
        if (func_0038CAD0(&D_001A4BE0_0036E578.aiming_fire_wait) == 0)
            can_fire = 0;
    } else {
        D_001A4BE0_0036E578.aiming_fire_wait = 0x21;
    }
    if (D_L01_001D6694 != 2 && v->timer == 0.0f && D_001A4BE0_0036E578.no_firing == 0 && self[0x42] < 2 &&
        D_001A4BE0_0036E578.i1220 >= 0x17 &&
        ((*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0_0036E578.fire_button) ||
         ((*(s32 *)(D_001D52FC + 0x1A0) & 8) && D_001A4BE0_0036E578.state == 0x1D)) &&
        can_fire) {
        if (self[0x43] == 0)
            func_003C3A10(self, 1, 0, 3);
        if (func_L01_005118D0(-1, 1)) {
            D_L01_001E1D24 = 1;
            if (target == 0) {
                func_0038CE20(&pos, self + 0xD0, -1.0f);
                vec_add_ab(&pos, &pos, self + 0x10);
                func_0038CE20(&off, self + 0xC0, 0.275f);
                vec_add_ab(&pos, &pos, &off);
                n = func_003D4D00(&pos, 1, D_001A4BE0_0036E578.moby, 0, 1.0f);
                if (n != 0) {
                    for (i = 0; i < n; i++) {
                        u8 *m = D_L01_001EEA80[i];
                        u8 *mi = func_00382348(m);
                        u8 *t;
                        if (m[0x31] != 0 && *(s16 *)(m + 0x32) > 0 && m != 0 && m[0x20] != 0xFE &&
                            m[0x20] != 0xFD && *(s16 *)(m + 0xAA) != 0xC87 && *(s16 *)(m + 0xAA) != 0xECC &&
                            *(s16 *)(m + 0xAA) != 0x1D61 && *(s16 *)(m + 0xAA) != 0x1BAE && mi != 0 &&
                            (0.0f < *(f32 *)mi || func_003C4B50(m) != 0)) {
                            t = *(u8 **)(m + 0x24);
                            if (t == 0 || t[0x46] != 5) {
                                target = D_L01_001EAA00.hit;
                                v->target = target;
                                break;
                            }
                        }
                    }
                }
            }
            v->flash = 0xC;
            func_L01_0036E120(self);
            func_003A52A0(0, 0, self);
            func_L01_0036F120(self);
            func_L01_004EA7D8(-1);
            func_003C3A10(self, 2, 0, 0);
            if ((D_L01_002C5600_0036E578 + D_001425C0[0x3F])->kind >= 4)
                *(f32 *)(self + 0x48) = 2.0f;
            v->rumble = func_L01_003F2058(D_L01_002B3940, 0);
            v->timer = 1.0f / (D_L01_002C5600_0036E578 + D_001425C0[0x3F])->rate;
        } else if ((*(s32 *)(D_001D52FC + 0x1A4) & D_001A4BE0_0036E578.fire_button) || D_L01_001E1D24 == 1) {
            func_003A52A0(1, 0, self);
            D_L01_001E1D24 = 0;
        }
        if (!(((*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0_0036E578.fire_button) ||
               ((*(s32 *)(D_001D52FC + 0x1A0) & 8) && D_001A4BE0_0036E578.state == 0x1D)) &&
              func_L01_005119E0(-1) && D_001A4BE0_0036E578.b25E9 != 0) &&
            v->rumble >= 0) {
            func_L01_003F2278(v->rumble, 0);
            v->rumble = -1;
        }
    }
    if (self[0x42] != 2 && v->flash > 0) {
        n = v->flash;
        if (n > 10) {
            f32 t = (f32)(12 - n);
            cr = t * 0.5f;
            cb = t * 0.5f * 0.5f;
            cg = t * 0.8f * 0.5f;
        } else {
            f32 t = (f32)n;
            cr = t * 0.1f;
            cg = t * 0.8f * 0.1f;
            cb = t * 0.5f * 0.1f;
        }
        if (D_001A4BE0_0036E578.h2874 != 0) {
            func_0038CE20(&off, self + 0xD0, -1.0f);
            func_003C2F58((s32)self, 0, &pos);
        } else {
            off = D_001A4BE0_0036E578.aim;
            func_003C2F58((s32)self, 0, &pos);
        }
        vec_add_ab(&pos, &pos, &off);
        func_0038CE20(&off2, D_001A4BE0_0036E578.moby + 0xE0, 0.3f);
        vec_add_ab(&pos, &pos, &off2);
        if (v->light == -1) {
            v->light = func_L01_00424CB0(&pos, 8.0f, 0.0f, cr, cg, cb);
        } else {
            Light_0036E578 *l = &D_L01_001F1B40[v->light];
            l->pos = pos;
            l->pos.w = 8.0f;
            l->r = cr;
            l->g = cg;
            l->b = cb;
        }
        func_0038CB00(&v->flash);
    } else if (v->light != -1) {
        func_L01_00424D88(v->light);
        v->light = -1;
        v->flash = 0;
    }
    if (self[0x43] == 2) {
        if (v->light != -1)
            func_L01_00424D88(v->light);
        v->light = -1;
        v->flash = 0;
    }
}
/* localdecomp:end func_L01_0036E578 */

LINKER_REMNANT("asm/levels", func_L01_0036F118);

/* localdecomp:start func_L01_0036F120 */
#include "vu0.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_0036F120;
typedef struct {
    u8 pad0[0x10]; void *target; u8 pad14[0x30-0x14];
    Vec_0036F120 direction, endpoint;
} Vars_0036F120;
typedef struct {
    u8 pad0[0x1430]; s32 f1430; u8 pad1434[0x16B0-0x1434]; s32 f16B0;
    u8 pad16B4[0x16D4-0x16B4]; s32 f16D4,f16D8;
    u8 pad16DC[0x25C0-0x16DC]; u8 *f25C0; s32 f25C4;
    u8 pad25C8[0x2874-0x25C8]; s16 f2874;
} Hero_0036F120;
extern Hero_0036F120 D_001A4BE0_0036F120;
extern Vec_0036F120 D_L01_001E29E0;
void func_L01_0036F120(u8 *moby) {
    extern void func_003C2F58(s32,s32,void *);
    extern void func_L01_004CB128(void *,void *,s32);
    extern void func_0038CF68(void *,void *,f32);
    extern u8 *func_L01_00397A28(void *,void *,void *,void *,void *);
    Vec_0036F120 pos, target;
    Vars_0036F120 *v = *(Vars_0036F120 **)(moby+0x68);
    u8 *shot;
    func_003C2F58((s32)moby,0,&pos);
    if(v->target) {
        func_L01_004CB128(&target,v->target,0);
        vec_sub_ba(&v->direction,&target,&pos);
        func_0038CF68(&v->direction,&v->direction,20.0f);
        vec_add_ab(&v->endpoint,&v->direction,&pos);
    }
    if(D_001A4BE0_0036F120.f2874 && D_001A4BE0_0036F120.f25C4!=29 &&
       (!D_001A4BE0_0036F120.f16B0 || D_001A4BE0_0036F120.f1430)) {
        func_0038CF68(&v->direction,moby+0xD0,-20.0f);
        vec_add_ab(&v->endpoint,&v->direction,&pos);
        D_001A4BE0_0036F120.f16D4=0;
        D_001A4BE0_0036F120.f16D8=0;
    } else if(D_001A4BE0_0036F120.f25C4==29 ||
       (D_001A4BE0_0036F120.f16B0 && !D_001A4BE0_0036F120.f1430)) {
        func_0038CF68(&v->direction,&D_L01_001E29E0,20.0f);
        vec_add_ab(&v->endpoint,&v->direction,&pos);
    } else if(D_001A4BE0_0036F120.f25C4==29 ||
       (D_001A4BE0_0036F120.f16B0 && D_001A4BE0_0036F120.f1430)) {
        func_L01_004CB128(&target,v->target,0);
        vec_sub_ba(&v->direction,&target,&pos);
        func_0038CF68(&v->direction,&v->direction,20.0f);
        vec_add_ab(&v->endpoint,&v->direction,&pos);
    } else if(!v->target) {
        func_0038CF68(&v->direction,D_001A4BE0_0036F120.f25C0+0xC0,20.0f);
        vec_add_ab(&v->endpoint,&v->direction,&pos);
    }
    shot=func_L01_00397A28(moby,&pos,v->target,&v->direction,&v->endpoint);
    if(shot) *(u8 **)(shot+0xB8)=moby;
}
/* localdecomp:end func_L01_0036F120 */

/* localdecomp:start func_L01_0036F330 */
#include "vu0.h"
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_0036F330;
typedef struct { s32 w[6]; } Skip_0036F330;
typedef struct {
    u8 pad_0[0x1D8];
    s32 i1D8;                  /* 0x1D8 */
    u8 pad_1DC[0x6F0 - 0x1DC];
    Vec_0036F330 aim;          /* 0x6F0 */
    u8 pad_700[0x1210 - 0x700];
    s32 fire_button;           /* 0x1210 */
    u8 pad_1214[0x1220 - 0x1214];
    s32 i1220;                 /* 0x1220 */
    u8 pad_1224[0x1430 - 0x1224];
    u8 *lockon_target;         /* 0x1430 */
    u8 pad_1434[0x25C0 - 0x1434];
    u8 *moby;                  /* 0x25C0 */
    s32 state;                 /* 0x25C4 */
    u8 pad_25C8[0x25E9 - 0x25C8];
    u8 b25E9;                  /* 0x25E9 */
    u8 pad_25EA[0x25ED - 0x25EA];
    u8 no_firing;              /* 0x25ED */
    u8 pad_25EE[0x28BC - 0x25EE];
    s32 aiming_fire_wait;      /* 0x28BC */
} Hero_0036F330;
typedef struct {
    u8 pad_0[0x10];
    u8 landing[0x10];          /* 0x10 */
    f32 timer;                 /* 0x20 */
    s32 w24;                   /* 0x24 */
    s32 w28;                   /* 0x28 */
    s32 rumble;                /* 0x2C */
} Vars_0036F330;
typedef struct {
    u8 pad_0[0x10];
    Vec_0036F330 pos;          /* 0x10 */
    u8 phase;                  /* 0x20 */
    u8 pad_21[0x42 - 0x21];
    u8 b42;                    /* 0x42 */
    u8 b43;                    /* 0x43 */
    u8 pad_44[0x60 - 0x44];
    u8 b60;                    /* 0x60 */
    u8 pad_61[0x68 - 0x61];
    Vars_0036F330 *vars;       /* 0x68 */
    u8 pad_6C[0x7C - 0x6C];
    s16 h7C;                   /* 0x7C */
} Moby_0036F330;
typedef struct { u8 pad_0; u8 kind; u8 pad_2[0x50 - 2]; f32 rate; u8 pad_54[0xF0 - 0x54]; } Row_0036F330;
extern Hero_0036F330 D_001A4BE0_0036F330;
extern u8 *D_001D52FC;
extern s32 D_001D545C;
extern u8 D_001425C0[];
extern u8 D_00142A60[];
extern u8 D_L01_001DAFF0_0036F330;
extern s32 D_L01_001D673C_0036F330;
extern s32 D_L01_001E1D28;
extern f32 D_L01_001DD900;
__asm__(".extern D_L01_001DD900, 4");
extern f32 D_L01_001DD904;
__asm__(".extern D_L01_001DD904, 4");
extern f32 D_L01_001DD908;
__asm__(".extern D_L01_001DD908, 4");
extern f32 D_L01_001DD90C;
__asm__(".extern D_L01_001DD90C, 4");
extern Skip_0036F330 D_L01_001DD910;
extern Skip_0036F330 D_L01_001DD928;
extern u8 D_L01_002B39C0[];
extern Row_0036F330 D_L01_002C5600_0036F330[];

void func_L01_0036F330(Moby_0036F330 *m)
{
    extern void func_003C2F58(s32, s32, void *);
    extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
    extern f32 *func_00382348(void *);
    extern f32 func_0038CF00(void *, void *);
    extern s32 func_0038CAD0(void *);
    extern u8 *func_L01_004501E8(void *, void *, f32, f32, f32, f32, void *, s32, s32, s32, f32, s32, void *, s32, s32, s32);
    extern void func_L01_0036FA50(void *, void *, void *, void *, f32, f32, f32, f32);
    extern s32 func_L01_004C7A18(f32, void *, void *, void *, void *, void *, s32, s32);
    extern void func_L01_004EAA80(void);
    extern s32 func_L01_005118D0(s32, s32);
    extern void func_L01_004EA7D8(s32);
    extern s32 func_L01_003F2058(void *, s32);
    extern void func_0038D890(void *, void *, void *, f32);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00362610(void *, void *, void *, s32, s32);
    extern void func_003A52A0(s32, s32, void *);
    extern s32 func_L01_005119E0(s32);
    extern void func_L01_003F2278(s32, s32);
    extern void func_L01_0040E050(void *);
    extern void func_L01_00404A10(void *, void *);
    extern void func_L01_0036F9F8();
    Vars_0036F330 *vars = m->vars;
    u8 *target;
    Vec_0036F330 pos;
    union { Skip_0036F330 skip; Vec_0036F330 dir; } u;
    s32 at;
    s32 at2;
    s32 can_fire;
    u8 kind;

    func_003C2F58((s32)m, 0, &pos);
    if (m->b42 == m->b43 && (m->b60 & 2))
        func_L01_00444F38((u8 *)m, 1, 0, 2, 0);
    target = 0;
    if ((D_L01_002C5600_0036F330 + D_001425C0[0x77])->kind >= 2)
        D_00142A60[0x77] |= 0x20;
    if (D_001A4BE0_0036F330.lockon_target != 0 && D_001A4BE0_0036F330.lockon_target[0x20] != 0xFE &&
        D_001A4BE0_0036F330.lockon_target[0x20] != 0xFD) {
        f32 *health = func_00382348(D_001A4BE0_0036F330.lockon_target);
        if (health != 0 && 0.0f < *health &&
            func_0038CF00(D_001A4BE0_0036F330.lockon_target + 0x10, &m->pos) < D_L01_001DD900)
            target = D_001A4BE0_0036F330.lockon_target;
    }
    kind = (D_L01_002C5600_0036F330 + D_001425C0[0x77])->kind;
    if (kind == 2)
        m->h7C = 3;
    else if (kind == 1)
        m->h7C = kind;
    else if (kind >= 3)
        m->h7C = 7;
    can_fire = 1;
    if (D_001A4BE0_0036F330.state == 0x1D || D_001A4BE0_0036F330.state == 1) {
        if (func_0038CAD0(&D_001A4BE0_0036F330.aiming_fire_wait) == 0)
            can_fire = 0;
    } else {
        D_001A4BE0_0036F330.aiming_fire_wait = 0x21;
        if (target == 0) {
            u.skip = D_L01_001DD910;
            target = func_L01_004501E8(&pos, &D_001A4BE0_0036F330.aim, 0.39269909262657166f, 1.5707963705062866f,
                                       11.100000381469727f, 0.0f, &at, 0, 0, 0, 0.0f, 0, &u.skip, 1, -1, 0);
        }
    }
    if (D_L01_001DAFF0_0036F330 != 0 && D_001D545C == 5) {
        u.skip = D_L01_001DD928;
        target = func_L01_004501E8(&pos, &D_001A4BE0_0036F330.aim, 0.8726646304130554f, 1.0471975803375244f,
                                   30.0f, 0.0f, &at2, 0, 0, 0, 0.0f, 0, &u.skip, 1, -1, 0);
        D_L01_001DD900 = 30.0f;
        D_L01_001DD90C = 20.0f;
    } else if (D_L01_001D673C_0036F330 != 0) {
        D_L01_001DD900 = 6.0f;
        D_L01_001DD90C = 12.5f;
    } else {
        D_L01_001DD900 = 12.0f;
        D_L01_001DD90C = 12.5f;
    }
    func_L01_0036FA50(&u.dir, &pos, target, 0, D_L01_001DD904, D_L01_001DD900,
                      D_L01_001DD90C * 0.020000001415610313f, D_L01_001DD908 * 0.0004000000189989805f);
    vars->w24 = func_L01_004C7A18(0.0052000004798173904f, &pos, &u.dir, vars, vars->landing, m, 0, 0);
    switch (m->phase) {
    case 0:
        m->phase = 1;
        vars->rumble = -1;
        vars->timer = 0.0f;
        vars->w28 = 0;
    case 1:
        if (D_001A4BE0_0036F330.i1D8 >= 0x12)
            func_L01_004EAA80();
        if (can_fire && vars->timer == 0.0f && D_001A4BE0_0036F330.no_firing == 0 &&
            (*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0_0036F330.fire_button) &&
            D_001A4BE0_0036F330.i1220 >= 0x13) {
            if (func_L01_005118D0(-1, 1)) {
                D_L01_001E1D28 = 1;
                func_L01_004EA7D8(-1);
                vars->rumble = func_L01_003F2058(D_L01_002B39C0, 0);
                func_L01_00444F38((u8 *)m, 2, 0, 2, 0);
                if (target != 0 && *(s16 *)(target + 0xAA) == 0x1A13 && D_L01_001DAFF0_0036F330 != 0) {
                    vec_sub_ab(&u.dir, target + 0x10, &pos);
                    func_0038CF68(&u.dir, &u.dir, 0.7000000476837158f);
                    func_0038D890(&u.dir, &u.dir, D_001A4BE0_0036F330.moby + 0xD0, -0.15707963705062866f);
                }
                if (D_L01_001DAFF0_0036F330 == 0) {
                    if (func_0038CEA8(&u.dir) > 0.6000000238418579f)
                        func_0038CF68(&u.dir, &u.dir, 0.4400000274181366f);
                }
                func_L01_00362610(&pos, &u.dir, m, 0, 0);
                func_003A52A0(0, 0, m);
                vars->timer = 1.0f / (D_L01_002C5600_0036F330 + D_001425C0[0x77])->rate;
            } else if ((*(s32 *)(D_001D52FC + 0x1A4) & D_001A4BE0_0036F330.fire_button) || D_L01_001E1D28 == 1) {
                func_003A52A0(1, 0, m);
                D_L01_001E1D28 = 0;
            }
            if (!((*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0_0036F330.fire_button) && func_L01_005119E0(-1) &&
                  D_001A4BE0_0036F330.b25E9 != 0) && vars->rumble >= 0) {
                func_L01_003F2278(vars->rumble, 0);
                vars->rumble = -1;
            }
        }
        break;
    }
    func_L01_0040E050(&vars->timer);
    func_L01_00404A10(func_L01_0036F9F8, m);
}
/* localdecomp:end func_L01_0036F330 */

/* localdecomp:start func_L01_0036F9F8 */

extern s32 func_L01_005119E0(s32);
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, f32);

void func_L01_0036F9F8(Obj3899C0 *obj) {
    u8 *p = obj->inner;
    if (*(s32 *)(p + 36) == 0) {
        return;
    }
    if (func_L01_005119E0(-1)) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_0036F9F8 */

/* localdecomp:start func_L01_0036FA50 */
#include "vu0.h"
typedef int u128_4C4A18 __attribute__((mode(TI)));
typedef struct {
    u128_4C4A18 pos;
    f32 x10;
    f32 x14;
    f32 x18;
    u8 *x1C;
} E_4C4A18;
typedef struct {
    u8 pad0[872];
    s16 x368;
    u8 pad36A[8790];
    u8 *x25C0;
} S_4C4A18;
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_004C4AD8;
typedef struct {
    u8 p0[0x10];
    Vec4_004C4AD8 x10;
} O_004C4AD8;
typedef struct {
    u8 p0[0xE0];
    Vec4_004C4AD8 xE0;
} P_004C4AD8;
typedef struct {
    Vec4_004C4AD8 x0;
    f32 x10;
    f32 x14;
    f32 x18;
    O_004C4AD8 *x1C;
} T_004C4AD8;
typedef struct { u8 pad[0x368]; s16 state; u8 gap[0x25C0-0x36A]; u8 *camera; s32 mode; u8 gap2[0x25ED-0x25C8]; u8 disabled; } Hero_004C7438;
extern S_4C4A18 D_001A4BE0_0036FA50;
extern s32 D_L01_001D6740;
extern s32 D_L01_001D673C;
extern u8 *D_001D52FC;
extern Vec4_004C4AD8 D_L01_001E29E0_0036FA50;
void func_L01_0036FA50(Vec4_004C4AD8 *out, Vec4_004C4AD8 *pos, u8 *moby, u8 *camera,
                     f32 minimum, f32 maximum, f32 speed, f32 acceleration) {
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003C5180(u128_4C4A18 *, E_4C4A18 *, s32);
    extern void func_L01_005003D0(s32, s32);
    extern s32 func_003A3BB8(s32, s32);
    extern void func_0038CF68(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
    extern f32 func_0038CE68(Vec4_004C4AD8 *, T_004C4AD8 *);
    extern void func_0038CE90(Vec4_004C4AD8 *, Vec4_004C4AD8 *, T_004C4AD8 *);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D098(f32);
    extern void func_0038D810(Vec4_004C4AD8 *, Vec4_004C4AD8 *);
    extern void func_0038D5F0(Vec4_004C4AD8 *, Vec4_004C4AD8 *, Vec4_004C4AD8 *);
    extern f32 func_0038CEA8(Vec4_004C4AD8 *);
    extern f32 func_L01_004451A8(f32);
    extern void func_0038D000(void *, void *, void *);
    extern f32 *func_00382348(u8 *);
    Vec4_004C4AD8 v, temp, direction, target, delta, correction;
    Vec4_004C4AD8 from, to, accel, result;
    Vec4_004C4AD8 basis[4];
    Vec4_004C4AD8 quat, axis, unit, rotated[3], matrix[3], point;
    f32 distance, denominator, plane, angle, t, inv;
    f32 *data;
    if (camera) {
        *(u128_4C4A18 *)&basis[0] = *(u128_4C4A18 *)(camera+0x10);
        *(u128_4C4A18 *)&basis[1] = *(u128_4C4A18 *)(camera+0xC0);
        *(u128_4C4A18 *)&basis[2] = *(u128_4C4A18 *)(camera+0xD0);
        *(u128_4C4A18 *)&basis[3] = *(u128_4C4A18 *)(camera+0xE0);
    } else {
        *(u128_4C4A18 *)&basis[0] = *(u128_4C4A18 *)(D_001A4BE0_0036FA50.x25C0+0x10);
        *(u128_4C4A18 *)&basis[1] = *(u128_4C4A18 *)((u8 *)&D_001A4BE0_0036FA50+0x6C0);
        *(u128_4C4A18 *)&basis[2] = *(u128_4C4A18 *)((u8 *)&D_001A4BE0_0036FA50+0x6D0);
        *(u128_4C4A18 *)&basis[3] = *(u128_4C4A18 *)((u8 *)&D_001A4BE0_0036FA50+0x6E0);
    }
    out->x=1; out->y=0; out->z=0; out->w=0;
    if (D_001A4BE0_0036FA50.x368 && !D_L01_001D6740)
        func_0038CE20(&direction,(Vec4_004C4AD8 *)(D_001A4BE0_0036FA50.x25C0+0xE0),-1.0f);
    else func_003C5180((u128_4C4A18 *)&basis[0],(E_4C4A18 *)&direction,0);
    distance=maximum;
    if (!moby) {
        if (((Hero_004C7438 *)&D_001A4BE0_0036FA50)->mode==1) func_L01_005003D0(29,1);
        if ((*(s32 *)(D_001D52FC+0x1A0)&func_003A3BB8(4,0)) && !((Hero_004C7438 *)&D_001A4BE0_0036FA50)->disabled) {
            func_0038CF68(&unit,&D_L01_001E29E0_0036FA50,1.0f);
            angle=func_0038CE68(&unit,(T_004C4AD8 *)&direction);
            func_0038CE20(&temp,&direction,angle);
            vec_sub_ab(&v, &unit, &temp);
            func_0038CF68(&v,&v,1.0f);
            func_0038CE90(&axis,&unit,(T_004C4AD8 *)&v);
            angle=func_0038CE68(&unit,(T_004C4AD8 *)&v)*0.5f;
            func_0038CE20(&quat,&axis,func_0038D0B0(angle));
            quat.w=func_0038D098(angle);
            func_0038D810(&quat,matrix);
            func_0038D5F0(rotated,matrix,&D_L01_001E29E0_0036FA50);
            plane=-func_0038CE68(&basis[0],(T_004C4AD8 *)&direction);
            func_0038CF68(&point,&D_L01_001E29E0_0036FA50,1.0f);
            denominator=func_0038CE68(&direction,(T_004C4AD8 *)&point);
            if (denominator>0.0f) {
                func_0038CE20(&point,&point,(func_0038CE68(&direction,(T_004C4AD8 *)((u8 *)&D_L01_001E29E0_0036FA50-0x20))+plane)/denominator);
                vec_sub_ba(&point, (u8 *)&D_L01_001E29E0_0036FA50 - 0x20, &point);
                vec_sub_ba(&point, &point, (u8 *)&D_L01_001E29E0_0036FA50 - 0x20);
                angle=func_0038CE68(&point,(T_004C4AD8 *)&direction);
                func_0038CE20(&temp,&direction,angle);
                vec_sub_ab(&v, &point, &temp);
                distance=func_0038CEA8(&v);
                if (maximum<distance) distance=maximum;
                else if (distance<minimum) distance=minimum;
            }
            distance=maximum*func_L01_004451A8(distance/maximum);
            func_0038D000(out,out,rotated);
        } else func_0038D000(out,out,&basis[1]);
        func_0038CF68(out,out,distance);
        vec_add_ba(&target, out, &basis[0]);
    } else {
        *(u128_4C4A18 *)&target=*(u128_4C4A18 *)(moby+0x10);
    }
    vec_sub_ab(&delta, &target, pos);
    angle=func_0038CE68(&delta,(T_004C4AD8 *)&direction);
    func_0038CE20(&temp,&direction,angle);
    vec_sub_ba(&v, &delta, &temp);
    func_0038CF68(out,&v,speed);
    t=func_0038CEA8(&v)/speed;
    inv=1.0f/t;
    angle=func_0038CE68(pos,(T_004C4AD8 *)&direction);
    func_0038CE20(&from,&direction,angle);
    angle=func_0038CE68(&target,(T_004C4AD8 *)&direction);
    func_0038CE20(&to,&direction,angle);
    func_0038CE20(&accel,&direction,acceleration*(t*t)*0.5f);
    vec_sub_ba(&result, &from, &to);
    vec_add_ba(&result, &result, &accel);
    func_0038CE20(&result,&result,-1.0f);
    func_0038CE20(&correction,&result,inv);
    vec_add_ab(out, out, &correction);
}
/* localdecomp:end func_L01_0036FA50 */

/* localdecomp:start func_L01_0036FF90 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_0036FF90;
typedef struct {
    u8 pad0[0x20];
    u8 phase;
    u8 pad21[0x42 - 0x21];
    u8 b42;
    u8 b43;
    u8 pad44[0x60 - 0x44];
    u8 flags60;
    u8 pad61[0x68 - 0x61];
    void *vars;
    u8 pad6C[0x7C - 0x6C];
    s16 bangles;
} Moby_0036FF90;
typedef struct { s32 timer; f32 angle; } Vars_0036FF90;
typedef struct {
    u8 pad0[0x1210];
    s32 fire_button;
    u8 pad1214[0x1220 - 0x1214];
    s32 f1220;
    u8 pad1224[0x15CC - 0x1224];
    u8 *f15CC;
    u8 pad15D0[0x15F0 - 0x15D0];
    f32 f15F0;
    u8 pad15F4[0x16B0 - 0x15F4];
    s32 f16B0;
    u8 pad16B4[0x16D4 - 0x16B4];
    s32 f16D4;
    s32 f16D8;
    u8 pad16DC[0x25C0 - 0x16DC];
    u8 *camera;
    s32 state;
    u8 pad25C8[0x25ED - 0x25C8];
    u8 no_firing;
    u8 pad25EE[0x2874 - 0x25EE];
    s16 f2874;
} Hero_0036FF90;
typedef struct { u8 pad0[0x1A0]; s32 w1A0; s32 w1A4; } Pad_0036FF90;
typedef struct { u8 p0; u8 kind; u8 p2[0x6A]; f32 damage; u8 p70[0xF0 - 0x70]; } Row_0036FF90;
extern Hero_0036FF90 D_001A4BE0_0036FF90;
extern Pad_0036FF90 *D_001D52FC_0036FF90;
extern Row_0036FF90 D_L01_002C5600_0036FF90[];
extern u8 D_001425C0_0036FF90[];
extern u8 D_L01_001DAFF0_0036FF90;
extern s32 D_L01_001D6694_0036FF90;
extern Vec_0036FF90 D_L01_001DD940[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DD940, 8");
extern Vec_0036FF90 D_L01_001DD950[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DD950, 8");
extern Vec_0036FF90 D_L01_001DD960 __attribute__((section(".sdata")));
extern s32 D_L01_001DD970;
__asm__(".extern D_L01_001DD970, 4");
extern Vec_0036FF90 D_L01_001E29C0_0036FF90;
extern Vec_0036FF90 D_L01_001E2DC0;
void func_L01_0036FF90(Moby_0036FF90 *moby) {
    extern s32 func_L01_005003D0(s32, s32);
    extern void func_0038D000(void *, void *, void *);
    extern s32 func_0038CAD0(s32 *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00444F38(void *, s32, s32, s32, s32);
    extern u8 *func_L01_00450BB0(void *, void *, f32, f32, f32, f32, f32, s32);
    extern s32 func_L01_004CB128(void *, void *, s32);
    extern f32 func_0038CF00(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_L01_003F6F20(s32, void *, s32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
    extern s32 func_L01_004CB1F0(f32, f32);
    extern s32 func_L01_005119E0(s32);
    extern void func_003C3A10(void *, s32, s32, s32);
    extern s32 func_L01_005118D0(s32, s32);
    extern void func_L01_004EA7D8(s32);
    extern f32 *func_00382348(void *);
    extern void func_0038D890(void *, void *, void *, f32);
    extern s32 func_003A52A0(s32, s32, void *);
    extern void *func_L01_003706F0(void *, void *, void *, s32, void *, s32, s32, f32);
    Vec_0036FF90 A, B, C;
    Vars_0036FF90 *vars = moby->vars;
    u8 *target;
    u8 *camera;
    s32 k, lowk, mask;
    f32 reach, d, ang;
    f32 *r;
    u8 st;

    if (moby->phase == 0) {
        vars->timer = 0;
        moby->phase = 1;
    }
    if (D_001A4BE0_0036FF90.state == 1)
        func_L01_005003D0(0x1D, 1);
    k = (D_L01_002C5600_0036FF90 + D_001425C0_0036FF90[0x4F])->kind;
    if (k == 3)
        moby->bangles = 7;
    if (k == 2)
        moby->bangles = 3;
    else if (k == 1)
        moby->bangles = k;
    func_0038D000(&A, D_L01_001DD940, (u8 *)moby + 0xC0);
    vec_add_ab(&A, &A, (Vec_0036FF90 *)((u8 *)moby + 0x10));
    func_0038CAD0(&vars->timer);
    B = *(Vec_0036FF90 *)(D_001A4BE0_0036FF90.camera + 0xC0);
    func_0038CF68(&B, &B, 0.3499999940395355f);
    if (moby->b42 == moby->b43 && (moby->flags60 & 2))
        func_L01_00444F38(moby, 1, 0, 2, 0);
    reach = 20.0f;
    if (k >= 3)
        reach = 35.0f;
    if (D_L01_001DAFF0_0036FF90)
        target = func_L01_00450BB0(&A, &B, 0.3490658402442932f, 0.1745329201221466f, 50.0f, 0.7853981852531433f, 0.7853981852531433f, 0);
    else
        target = func_L01_00450BB0(&A, &B, 0.5323254466056824f, 0.5323254466056824f, reach, 0.7853981852531433f, 0.7853981852531433f, 0);
    if (target) {
        func_L01_004CB128(&C, target, 0);
        if (D_001A4BE0_0036FF90.f16B0 == 0) {
            d = func_0038CF00(&D_L01_001E29C0_0036FF90, &C) / 150.0f;
            ang = func_0038DAB8(vars->angle, 0.03490658476948738f);
            d = d * 0.6499999761581421f;
            vars->angle = ang;
            func_L01_003F6F20(0, moby, 0xFF0FFF0F, &C, 0x26, -1, 4,
                              fabs_asm(0.8999999761581421f - d), -ang, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        }
    }
    if (D_001A4BE0_0036FF90.state == 0x1D || D_001A4BE0_0036FF90.f16B0) {
        s32 ret;
        target = 0;
        ret = func_L01_004CB1F0(0.9800000190734863f, 150.0f);
        if (0.9800000190734863f < D_001A4BE0_0036FF90.f15F0)
            target = D_001A4BE0_0036FF90.f15CC;
        func_L01_003F6F20(0, moby, ret, 0, 0x5A, -1, 4,
                          0.800000011920929f, 3.1415927410125732f, 90.0f, 0.5f, 0.5f, 80.0f, 40.0f);
    } else {
        D_001A4BE0_0036FF90.f16D4 = 0;
        D_001A4BE0_0036FF90.f16D8 = 0;
    }
    if (D_L01_001D6694_0036FF90)
        goto release;
    if (D_001A4BE0_0036FF90.no_firing)
        goto release;
    if (vars->timer != 0)
        goto release;
    if (moby->b42 >= 2)
        goto release;
    mask = D_001D52FC_0036FF90->w1A0;
    if (!(mask & D_001A4BE0_0036FF90.fire_button)) {
        if (!(mask & 8))
            goto release;
        if (D_001A4BE0_0036FF90.state != 0x1D)
            goto release;
    }
    if (D_001A4BE0_0036FF90.f1220 < 0x13)
        goto release;
    if (!func_L01_005119E0(-1))
        goto release;
    if (moby->b43 == 0)
        func_003C3A10(moby, 1, 0, 3);
    func_003C3A10(moby, 2, 0, 0);
    func_L01_005118D0(-1, 1);
    func_L01_004EA7D8(-1);
        if (target) {
        r = func_00382348(target);
        if (((st = target[0x20]) != 0xFE && st != 0xFD) || (r && *r >= 0.0f) || target[0x31] != 0 || D_001A4BE0_0036FF90.f2874 == 0) {
            vec_sub_ab(&B, (Vec_0036FF90 *)(target + 0x10), &A);
        }
    }
    lowk = k < 4;
    if (!lowk) {
        if (D_001A4BE0_0036FF90.state == 0x1D || D_001A4BE0_0036FF90.f16B0)
            B = D_L01_001E2DC0;
        func_0038CF68(&B, &B, 0.699999988079071f);
    } else {
        if (D_001A4BE0_0036FF90.state != 0x1D && D_001A4BE0_0036FF90.f16B0 == 0) {
            if (target)
                func_0038D890(&B, &B, D_001A4BE0_0036FF90.camera + 0xD0, -1.0559241771697998f);
            else
                func_0038D890(&B, &B, D_001A4BE0_0036FF90.camera + 0xD0, -0.39269909262657166f);
        } else {
            B = D_L01_001E2DC0;
        }
        func_0038CF68(&B, &B, 0.3499999940395355f);
    }
    if (!lowk) {
        if (D_L01_001DD970) {
            func_0038D000(&C, D_L01_001DD950, (u8 *)moby + 0xC0);
            vec_add_ab(&C, &C, (Vec_0036FF90 *)((u8 *)moby + 0x10));
            func_003A52A0(1, 0, moby);
            func_L01_003706F0(moby, &C, &B, 0x10000, target, 0, 0, (D_L01_002C5600_0036FF90 + D_001425C0_0036FF90[0x4F])->damage);
            D_L01_001DD970 = 0;
        } else {
            func_0038D000(&C, &D_L01_001DD960, (u8 *)moby + 0xC0);
            vec_add_ab(&C, &C, (Vec_0036FF90 *)((u8 *)moby + 0x10));
            func_003A52A0(1, 0, moby);
            func_L01_003706F0(moby, &C, &B, 0x10000, target, 0, 0, (D_L01_002C5600_0036FF90 + D_001425C0_0036FF90[0x4F])->damage);
            D_L01_001DD970 = 1;
        }
    } else {
        func_003A52A0(1, 0, moby);
        func_L01_003706F0(moby, &A, &B, 0x10000, target, 0, 0, (D_L01_002C5600_0036FF90 + D_001425C0_0036FF90[0x4F])->damage);
    }
    vars->timer = 0x19;
    return;
release:
    if ((D_001D52FC_0036FF90->w1A4 & D_001A4BE0_0036FF90.fire_button) && !func_L01_005119E0(-1))
        func_003A52A0(2, 0, moby);
}
/* localdecomp:end func_L01_0036FF90 */

/* localdecomp:start func_L01_003706F0 */
typedef int Q_003706F0 __attribute__((mode(TI)));
typedef struct { u8 bytes[0xF0]; } WeaponRow_003706F0;
typedef struct { Q_003706F0 rows[3]; } Basis_003706F0;
extern u8 D_0014260F[];
extern WeaponRow_003706F0 D_L01_002C5600_003706F0[];
extern s32 D_L01_001DD9A0;
__asm__(".extern D_L01_001DD9A0, 4");
typedef struct { u8 pad0[0x368]; s16 h368; u8 pad36A[0x16B0-0x36A]; s32 i16B0; u8 pad16B4[0x25C0-0x16B4]; u8 *p25C0; s32 i25C4; } Hero_003706F0;
extern Hero_003706F0 D_001A4BE0_003706F0;
extern Basis_003706F0 D_L01_001E29E0_003706F0;
extern s32 D_L01_001D673C;
extern u8 D_001A4C60[];
void *func_L01_003706F0(void *owner, Q_003706F0 *position, Q_003706F0 *direction, f32 damage, s32 arg3, s32 arg4, s16 arg5, s32 arg6) {
    extern void *func_003C24B0(s32, s32);
    extern f32 func_00382538(void);
    extern s32 func_00382468(s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_L01_004C7D98(void *, void *);
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CEA8(void *);
    extern void func_L01_004CAC78(void *, void *, f32, f32, f32);
    extern s32 func_L01_004C85C8(void *, s32, f32, f32, f32);
    Q_003706F0 temporary, projected;
    u8 *m = func_003C24B0(0x1867, 0x300);
    if (m) {
        u8 *v;
        Q_003706F0 *dir;
        m[0x30] = *(u16 *)(m + 0x32) = 0xFF;
        *(f32 *)(m + 0x2C) = 0.019f;
        v = *(u8 **)(m + 0x68);
        { WeaponRow_003706F0 *row = &D_L01_002C5600_003706F0[D_0014260F[0]]; *(s32 *)(v + 0x2D4) = row->bytes[1]; }
        m[0x20] = 0;
        *(u16 *)(m + 0x34) |= 0x100;
        *(Q_003706F0 *)(m + 0x10) = *position;
        *(Q_003706F0 *)v = *direction;
        *(s32 *)(v + 0x17C) = arg3;
        *(void **)(v + 0x174) = owner;
        *(f32 *)(v + 0x180) = func_00382538();
        *(s16 *)(v + 0x188) = func_00382468(2);
        *(f32 *)(v + 0x178) = damage;
        *(s32 *)(v + 0x184) = arg4;
        *(s32 *)(v + 0x2DC) = arg6;
        *(s16 *)(v + 0x18A) = arg5;
        *(s32 *)(v + 0x2D0) = -1;
        *(f32 *)(v + 0x2A0) = 0.5f;
        *(f32 *)(v + 0x2B0) = -0.5f;
        *(s32 *)(v + 0x170) = 0;
        *(s32 *)(v + 0x2A4) = 0;
        *(s32 *)(v + 0x2A8) = 0;
        *(f32 *)(v + 0x2AC) = 1.0f;
        *(s32 *)(v + 0x2B4) = 0;
        *(s32 *)(v + 0x2B8) = 0;
        *(f32 *)(v + 0x2BC) = 1.0f;
        *(s32 *)(v + 0x2C4) = 0;
        if (*(s32 *)(v + 0x2D4) >= 4) D_L01_001DD9A0++;
        if (D_001A4BE0_003706F0.i25C4 == 29 || D_001A4BE0_003706F0.i16B0) {
            *(Basis_003706F0 *)(m + 0xC0) = D_L01_001E29E0_003706F0;
        } else {
            *(Q_003706F0 *)(m + 0xC0) = *(Q_003706F0 *)v;
            func_0038CF68(m + 0xC0, m + 0xC0, 1.0f);
            func_0038CE90(m + 0xE0, D_001A4BE0_003706F0.p25C0 + 0xD0, m + 0xC0);
            func_0038CE90(m + 0xD0, m + 0xC0, m + 0xE0);
            func_0038D890(m + 0xD0, m + 0xD0, v, 1.57079637f);
            func_0038D890(m + 0xE0, m + 0xE0, v, 1.57079637f);
        }
        dir = (Q_003706F0 *)(v + 0x10);
        *dir = *(Q_003706F0 *)v;
        if (D_L01_001D673C || D_001A4BE0_003706F0.h368) {
            func_L01_004C7D98(D_001A4C60, &temporary);
            { f32 scale = func_0038CE68(v, &temporary); func_0038CE20(&projected, &temporary, scale); }
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*dir) : "m"(*(Q_003706F0 *)v), "m"(projected) : "memory");
        } else {
            *(s32 *)(v + 0x18) = 0;
            func_0038CF68(dir, dir, 1.0f);
        }
        if (D_001A4BE0_003706F0.i16B0) {
            func_L01_004CAC78(dir, position, func_0038CEA8(dir), 30.0f, 1.39626336f);
            func_L01_004CAC78(v, position, func_0038CEA8(v), 30.0f, 1.39626336f);
        }
        *(s32 *)(v + 0x2D8) = func_L01_004C85C8(m, 0, 1.0f, 1.0f, 1.0f);
    }
    return m;
}
/* localdecomp:end func_L01_003706F0 */

INCLUDE_ASM("asm/levels", func_L01_00370A48);

/* localdecomp:start func_L01_00371C98 */
void func_L01_00371C98(u8 *a) {
    a[0x20] = 1;
}
/* localdecomp:end func_L01_00371C98 */

/* localdecomp:start func_L01_00371CA8 */
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
extern u8 D_L01_001D66B0[8];
void func_L01_00371CA8(u8 *self, vu0_v4 *source)
{
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_00470668(void *, void *, s32, f32);
    extern void func_00382580(void *, f32, f32);
    extern void func_L01_00474078(void *, void *, s32, u32, u32, s32, s32, f32, f32, f32, f32);
    extern u8 *func_L01_0046B458(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
    extern void func_L01_00470C78(void *, s32, f32, f32, s32, s32, s32, void *, s32, s32, s32, s32);
    vu0_v4 velocity, toward;
    s32 i, j;

    if (*(s32 *)(*(u8 **)(self + 0x68) + 0x2D4) < 2) {
        vec_sub_ba(&velocity, &D_L01_001E29C0, source);
        func_0038CF68(&velocity, &velocity, func_003824E0(0.1f, 0.2f));
        for (i = 0; i < 15; i++) {
            velocity.x += func_003824E0(-0.05f, 0.05f);
            velocity.y += func_003824E0(-0.05f, 0.05f);
            velocity.z += func_003824E0(-0.05f, 0.05f);
            func_L01_00470668(self + 0x10, &velocity, (func_00382498(25, 40) * 5 + 2) / 6, 0.00584f);
        }
    } else {
        u32 color0, color1, color2, tint;
        f32 f, zero, g;
        color0 = 0x80804020;
        tint = 0xFF0000;
        color1 = 0xBF804020;
        color2 = 0xBF604020;
        if (*(s32 *)(*(u8 **)(self + 0x68) + 0x2D4) >= 4) {
            color0 = 0x80204080;
            tint = 0xFF;
            color1 = 0xBF2040FF;
            color2 = 0xBF2040FF;
        }
        for (j = 0; j < 10; j++) {
            func_00382580(&velocity, 0.10000001f, 0.20000002f);
            func_L01_00474078(self + 0x10, &velocity, (func_00382498(15, 25) * 5 + 2) / 6, color0, tint, 0, 0, 0.1f, 0.25f, 0.9f, 0.5f);
        }
        vec_sub_ba(&toward, &D_L01_001E29C0, self + 0x10);
        func_0038CF68(&toward, &toward, 0.4f);
        f = 0.1f;
        zero = 0.0f;
        vec_add_ba(&velocity, self + 0x10, &toward);
        g = 0.7f;
        func_L01_0046B458(&velocity, 14, 3.5f, f, color1, 2, 1, D_L01_001D66B0, zero, 1);
        func_L01_0046B458(&velocity, 14, 2.5f, f, color2, 2, -1, D_L01_001D66B0, zero, 1);
        func_L01_0046B458(&velocity, 14, 1.75f, f, 0xC0FFFFFF, 2, 1, D_L01_001D66B0, zero, 1);
        func_L01_0046B458(&velocity, 14, 1.25f, f, 0xB0FFFFFF, 2, -1, D_L01_001D66B0, zero, 1);
        func_L01_00470C78(&velocity, 17, 0.9f, g, 0x46787878, 2, 2, D_L01_001D66B0, 0, 2, 6, 1);
        func_L01_00470C78(&velocity, 17, 1.7f, g, 0x46787878, 2, -1, D_L01_001D66B0, 1, 2, 6, 1);
        func_L01_00470C78(&velocity, 17, 2.0f, 1.5f, 0x2D787878, 2, 1, D_L01_001D66B0, 1, 2, 6, 1);
    }
}
/* localdecomp:end func_L01_00371CA8 */

LINKER_REMNANT("asm/levels", func_L01_00372120);

/* localdecomp:start func_L01_00372128 */
typedef int u128_372128 __attribute__((mode(TI)));
typedef struct {
    u8 pad_0[0x18C];
    s32 first_drawn;           /* 0x18C: set once rotation is kept */
    u128_372128 places[8];     /* 0x190: the ring of kept places */
    u128_372128 turns[8];      /* 0x210: each place's turn */
    u128_372128 rotation;      /* 0x290: the disc's rotation at its first draw */
    u8 trail[0x2C0 - 0x2A0];   /* 0x2A0: the trail's own state */
    s32 count;                 /* 0x2C0: places kept */
    s32 newest;                /* 0x2C4: the newest place's slot */
    f32 share;                 /* 0x2C8: share of the frames to the next kept place */
    u8 pad_2CC[0x2D4 - 0x2CC];
    s32 level;                 /* 0x2D4: the gun's level, 1 = V2 */
} DiscVars_372128;
typedef struct {
    u8 pad_0[0x10];
    u128_372128 position;
    u8 pad_20[0x68 - 0x20];
    DiscVars_372128 *vars;
    u8 pad_6C[0xF0 - 0x6C];
    u128_372128 rotation;
} Moby_372128;

extern void func_003C3FC0(u128_372128 *out, u128_372128 *angles);
extern void func_L01_00408C98(void *trail, s32 kind, u128_372128 *places, u128_372128 *turns,
                              s32 newest, s32 count, u32 head_colour, u32 tail_colour, f32 share,
                              s32 texture);

/* disc_blade_ribbon_draw: the Disc Blade's ribbon trail from V2: keeps the disc's place and turn
   in the ring and draws it with fx_trail, its colours by level */
void func_L01_00372128(Moby_372128 *disc) {
    DiscVars_372128 *vars = disc->vars;
    u32 head_colour;
    u32 tail_colour;
    s32 texture;

    if (vars->first_drawn != 0) {
        func_003C3FC0(&vars->turns[vars->newest], &vars->rotation);
    } else {
        func_003C3FC0(&vars->turns[vars->newest], &disc->rotation);
        vars->rotation = disc->rotation;
        vars->first_drawn = 1;
    }
    (&vars->places[0])[vars->newest] = disc->position;
    /* V2: (0xFF, 0x80, 0x40) at 0x6F to (0xFF, 0x20, 0) */
    head_colour = 0x6F4080FF;
    tail_colour = 0x20FF;
    texture = 8;
    if (vars->level == 2) {
        /* V3: (0x40, 0x80, 0xFF) at 0x6F to (0, 0x20, 0xFF), texture 29 */
        head_colour = 0x6FFF8040;
        tail_colour = 0xFF2000;
        texture = 0x1D;
    }
    if (vars->level == 3) {
        /* V4: (0x20, 0x10, 0xFF) at 0x4F to (0, 0, 0xFF), texture 60 */
        head_colour = 0x4FFF1020;
        tail_colour = 0xFF0000;
        texture = 0x3C;
    }
    if (vars->level >= 4) {
        /* V5: (0xFF, 0x10, 0x20) at 0x4F to (0xFF, 0, 0) */
        head_colour = 0x4F2010FF;
        tail_colour = 0xFF;
        texture = 0x3C;
    }
    func_L01_00408C98(vars->trail, 2, vars->places, vars->turns, vars->newest, vars->count,
                      head_colour, tail_colour, vars->share, texture);
}
/* localdecomp:end func_L01_00372128 */

/* localdecomp:start func_L01_00372240 */
typedef struct {
    u8 pad_0[0x180];
    f32 phase;                 /* 0x180: the turning phase of the sprites' rolls */
    u8 pad_184[0x2D4 - 0x184];
    s32 level;                 /* 0x2D4: the gun's level, 1 = V2 */
} DiscVars_372240;
typedef struct {
    u8 pad_0[0x10];
    u8 position[0x10];
    u8 pad_20[0x68 - 0x20];
    DiscVars_372240 *vars;
} Moby_372240;

extern s32 D_L01_001DD9A8;
__asm__(".extern D_L01_001DD9A8, 4");
extern f32 D_L01_001DD9BC;
__asm__(".extern D_L01_001DD9BC, 4");
extern f32 D_L01_001DD9C0;
__asm__(".extern D_L01_001DD9C0, 4");
extern f32 D_L01_001DD9C4;
__asm__(".extern D_L01_001DD9C4, 4");

extern f32 func_0038DAB8(f32 a, f32 b);
extern f32 func_00382538(void);
extern void func_003D9508(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);

/* disc_blade_sprites_draw: the Disc Blade's disc draws, to V4, added billboards of textures 57, 49
   and 47 on it, rolled by a turning phase */
void func_L01_00372240(Moby_372240 *disc) {
    DiscVars_372240 *vars = disc->vars;
    u32 colour_a = 0x207F7F7F;  /* grey 0x7F at 0x20 */
    u32 colour_b = 0x10007FFF;  /* (0xFF, 0x7F, 0) at 0x10 */
    f32 phase;

    phase = func_0038DAB8(vars->phase, D_L01_001DD9BC * 0.01745329238474369f);
    vars->phase = phase;
    if ((u32)(vars->level - 2) < 2) {
        colour_a = 0x20FF2020;  /* V3-V4 (0x20, 0x20, 0xFF) */
        colour_b = 0x10FF7F00;  /* V3-V4 (0, 0x7F, 0xFF) */
    }
    if (vars->level < 4) {
        func_003D9508(disc->position, D_L01_001DD9A8, colour_a, 1, D_L01_001DD9C4, 0.0799999982118f,
                      func_0038DAB8(-vars->phase * 1.5f, 0.0f));
        func_003D9508(disc->position, D_L01_001DD9A8, colour_a, 1, D_L01_001DD9C4, 0.0799999982118f,
                      vars->phase * 0.5f);
        func_003D9508(disc->position, D_L01_001DD9A8, colour_a, 1, D_L01_001DD9C4, 0.0799999982118f,
                      func_0038DAB8(vars->phase * 2.5f, 0.0f));
        func_003D9508(disc->position, 0x31, colour_b, 1, 0.36000001430511475f, 0.0799999982118f,
                      vars->phase * 0.5f);
        func_003D9508(disc->position, 0x31, colour_b, 1, 0.36000001430511475f, 0.0799999982118f,
                      vars->phase * -0.5f);
        func_003D9508(disc->position, 0x2F, 0x507F7F7F, 1, D_L01_001DD9C0, 0.0799999982118f,
                      func_00382538());
    }
}
/* localdecomp:end func_L01_00372240 */

/* localdecomp:start func_L01_00372430 */
#include "vu0.h"
typedef struct { u8 pad0[0x2D4]; s32 level; } Vars_00372240;
extern u8 *D_L01_00221098_00372430[];
extern u8 *D_L01_0022116C[];
extern f32 D_001A4EC0[];
void func_L01_00372430(u8 *p, vu0_v4 *from_ptr, vu0_v4 *to_ptr) {
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern u8 func_0013D3E0(void);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern s32 func_00382468(s32);
    extern void func_003C4C18(void *, f32);
    extern u8 *func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
    s32 spin;
    s32 colour1=0x407FFF, colour2=0x4040FF;
    vu0_v4 from=*from_ptr;
    vu0_v4 to=*to_ptr;
    vu0_v4 velocity, position, step, tail;
    Vars_00372240 *v=*(Vars_00372240 **)(p+0x68);
    f32 length=func_0038CEA8(v);
    s32 count=length/0.1f;
    s32 i;
    position=to;
    vec_sub_ab(&step,&from,&to);
    func_0038CF68(&step,&step,length/count);
    if ((u32)(v->level-2)<2) {colour1=0xFF7F40;colour2=0xFF4040;}
    if (v->level<4) {
        for(i=0;i<count;++i) {
            s32 life, alpha, colour;
            u8 *particle;
            spin=func_L01_00443A18(1.0f,3.0f);
            {f32 sp_=func_003824E0(0.1f,0.2f); func_0038CE20(&velocity,D_001A4EC0,-(sp_*0.020000001415610313f));}
            life=func_00382498(3,6);
            if (func_0013D3E0()&2) {alpha=64;colour=colour1;}
            else {alpha=96;colour=colour2;}
            particle=func_L01_0046A610(&position,&velocity,(life*5+2)/6,alpha,colour,spin,63000.00390625f,10000.0f,1.0f,0.0f,0.0f);
            vec_add_ab(&position,&position,&step);
            if (particle) {
                particle[2]=*D_L01_00221098_00372430[23];
                particle[3]=alpha==64?0x48:0x44;
            }
        }
    }
    {
        s32 colour1=0x7F407FFF,colour2=0x7F80DFFF,alpha=255;
        if ((u32)(v->level-2)<2) {colour1=0x7FFF7F40;colour2=0x7FFFDF80;alpha=0xFF0000;}
        if (v->level<4 && func_00382468(2)) {
            s32 colour;
            u8 *particle;
            func_0038CE20(&tail,v,-0.04000000283122063f);
            func_003C4C18(&tail,0.12000000476837158f);
            tail.z+=0.06000000238418579f;
            colour=func_00382468(2)?colour1:colour2;
            particle=func_L01_00465738(p+0x10,&tail,colour,alpha,func_00382498(8,17),0,-1,-1,0,94500.0f);
            if (particle) {
                *(f32 *)(particle+0x2C)=0.002400000113993883f;
                particle[2]=*D_L01_0022116C[0];
            }
        }
    }
}
/* localdecomp:end func_L01_00372430 */

/* localdecomp:start func_L01_003727B8 */
typedef struct {
    u8 pad_0[0x20];
    s32 timer;                 /* 0x20: frames to the next phase */
    s32 w24;                   /* 0x24 */
    s32 w28;                   /* 0x28: 1 once the glove is ready */
} GloveVars_3727B8;
typedef struct {
    u8 pad_0[0x20];
    u8 phase;                  /* 0x20: 0 start, 1 ready, 2 throwing, 3 wait */
    u8 pad_21[0x31 - 0x21];
    u8 level_flag;             /* 0x31 */
    u8 pad_32[0x68 - 0x32];
    GloveVars_3727B8 *vars;    /* 0x68 */
    u8 pad_6C[0x7C - 0x6C];
    s16 bangles;               /* 0x7C: the glove's bangles by level */
} Glove_3727B8;
typedef struct { u8 pad[0x5C]; u8 *p5C; } T_221098;

extern Hero_3727B8 D_001A4BE0;
extern u8 *D_001D52FC;
extern u8 D_00142627[];
typedef struct { u8 pad_0; u8 kind; u8 pad_2[0xEE]; } Row_3727B8;
extern Row_3727B8 D_L01_002C5600[];
extern f32 D_L01_001E2880[];
extern T_221098 D_L01_00221098;
extern f32 D_L01_002F4D7C[];

extern void func_L01_004C7438(void *out, void *in, s32 a, s32 b, f32 c, f32 d, f32 e, f32 f);
extern s32 func_0038CAD0(s32 *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *dst, void *src, f32 s);
extern s32 func_L01_0037C720_003727B8(void);
extern s32 func_L01_005118D0(s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_004EA7D8(s32);
extern void func_L01_00377A10(f32, void *, void *, void *);
extern void func_L01_004EAA80(void);
extern s32 func_L01_004C7A18(f32 h, void *a, void *b, void *c, void *d, void *e, s32 f, s32 g);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32 a, f32 b);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8(void *a, void *b, s32 life, s32 colour, s32 c, s32 d, s32 e, s32 f, f32 g, f32 h, f32 i);
extern void func_L01_00372CE8(u8 *moby);
extern void func_L01_00404A10_003727B8(void *, u8 *);

/* holo_glove_update: the Holo Shield Glove's update: phase 2 to throw, 1 for no ammo, 3 with none
   left; each frame it also puffs sparks round the hand */
void func_L01_003727B8(Glove_3727B8 *glove)
{
    GloveVars_3727B8 *vars = glove->vars;
    f32 v[20];
    f32 *pos;
    s32 can_throw;
    u8 kind;
    Row_3727B8 *row;
    s32 i;
    s32 life;
    f32 yaw;
    f32 speed;

    func_003C2F58((s32)glove, 0, &v[0]);
    pos = &v[4];
    speed = 5.0f;
    if (D_001A4BE0.state == 0x1D)
        speed = 8.0f;
    func_L01_004C7438(pos, &v[0], 0, 0, 1.5f, speed, 0.30000001192092896f, 0.004399999976158142f);
    if (glove->level_flag)
        D_L01_002F4D7C[0] = 0.10000000149011612f;
    can_throw = 1;
    if (D_001A4BE0.state == 0x1D) {
        if (func_0038CAD0(&D_001A4BE0.aiming_fire_wait) == 0)
            can_throw = 0;
    } else {
        D_001A4BE0.aiming_fire_wait = 0x21;
    }
    row = D_L01_002C5600 + D_00142627[0];
    kind = row->kind;
    if (kind == 3)
        glove->bangles = 7;
    if (kind == 2)
        glove->bangles = 3;
    else if (kind == 1)
        glove->bangles = kind;
    switch (glove->phase) {
    case 0:
        glove->phase = 1;
        vars->w28 = 1;
        vars->w24 = 0;
    case 1:
        if ((*(s32 *)(D_001D52FC + 0x1A4) & D_001A4BE0.fire_button) ||
            ((*(s32 *)(D_001D52FC + 0x1A4) & 8) && D_001A4BE0.state == 0x1D)) {
            if (D_001A4BE0.no_firing == 0 && can_throw) {
                if (func_L01_0037C720_003727B8() || vars->w28 == 0) {
                    func_003A52A0(3, 0, glove);
                } else if (func_L01_005118D0(-1, 1)) {
                    func_003A52A0(2, 0, glove);
                    func_L01_004EA7D8(-1);
                    glove->phase = 2;
                    vars->timer = 0x11;
                } else {
                    func_003A52A0(1, 0, glove);
                }
            }
        }
        break;
    case 2:
        if (func_0038CAD0(&vars->timer)) {
            if (func_0038CEA8(pos) > 0.40000003576278687f)
                func_0038CF68(pos, pos, 0.40000003576278687f);
            func_L01_00377A10(1.0f, glove, &v[0], pos);
            func_L01_004EAA80();
            glove->phase = 3;
            vars->timer = 0x32;
        }
        break;
    case 3:
        if (func_0038CAD0(&vars->timer))
            glove->phase = 1;
        break;
    }
    if (glove->phase == 3)
        return;
    if (func_L01_0037C720_003727B8())
        return;
    vars->w24 = func_L01_004C7A18(0.004399999976158142f, &v[0], pos, vars, (u8 *)vars + 0x10, 0, 0, 0);
    func_003C2F58((s32)glove, 1, &v[8]);
    for (i = 3; i >= 0; i--) {
        yaw = func_0038D160(D_001A4BE0.x - D_L01_001E2880[0x50], D_001A4BE0.y - D_L01_001E2880[0x51]);
        func_L01_00443A18(1.0f, 2.0f);
        v[12] = v[8] + func_003824E0(-0.15f, 0.15f);
        v[13] = v[9] + func_003824E0(-0.15f, 0.15f);
        v[14] = v[10] + func_003824E0(-0.15f, 0.15f);
        yaw = func_0038DAB8(yaw, func_L01_00443A18(0.0f, -6.2831854820251465f));
        v[16] = func_0038D098(yaw) * 0.015000000596046448f;
        v[17] = func_0038D0B0(yaw) * 0.015000000596046448f;
        v[18] = 0.0f;
        life = (func_00382498(10, 30) * 5 + 2) / 6;
        {
            u8 *spark = func_L01_004713C8(&v[12], &v[16], life, 0x804020, func_00382498(-2, -4), 0x7F, 0, 0,
                                         46200.0f, 16800.0f, 0.000800000037997961f);
            if (spark)
                spark[2] = D_L01_00221098.p5C[0];
        }
    }
    func_L01_00404A10_003727B8(func_L01_00372CE8, (u8 *)glove);
}
/* localdecomp:end func_L01_003727B8 */

/* localdecomp:start func_L01_00372CE8 */
extern void func_003C2F58(s32, s32, void *);
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, f32);


extern Pair_371CB8 D_L01_001DD9D0[];
extern void func_L01_004C7D98(void *a, void *b);
extern f32 func_0038CE68(void *a, void *b);
extern f32 func_0038DAB8(f32 a, f32 b);
extern s32 func_L01_004CB2D8(void);
extern void func_L01_004CAB30(void *a, void *b);
extern void func_003D9508(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);
extern f32 func_00382538(void);

void func_L01_00372CE8(u8 *moby) {
    u8 buf[16];
    Pair_371CB8 tmp;
    f32 vec[4];
    Obj_371CB8 *o = *(Obj_371CB8 **)(moby + 104);

    func_L01_004C7D98(o, buf);
    if (func_0038CE68(o->pos, buf) <= 0.9f) {
        o->i40 = 0;
    } else {
        o->i40 = 1;
    }
    tmp = D_L01_001DD9D0[0];
    if (o->i36) {
        if (o->i40) {
            ((void (*)(f32 s, void *a, void *b, void *c, s32 d))func_L01_004C70A8)(1.0f, o, o->pos, 0, 1);
        } else {
            ((void (*)(f32 s, void *a, void *b, void *c, s32 d))func_L01_004C70A8)(1.0f, o, o->pos, &tmp, 1);
        }
    }
    ((void (*)(void *a, s32 b, void *c))func_003C2F58)(moby, 1, vec);
    o->f48 = func_0038DAB8(o->f48, 0.017453292f);
    if (func_L01_004CB2D8()) {
        func_L01_004CAB30(vec, vec);
    }
    func_003D9508(vec, 57, 0x50505050, 1, 0.25f, 0.0f, func_0038DAB8(o->f48 * 2.5f, 0.0f));
    func_003D9508(vec, 42, 0x307F2040, 1, 0.25f, 0.0f, func_0038DAB8(-o->f48 * 1.5f, 0.0f));
    func_003D9508(vec, 44, 0x307F2040, 1, 0.25f, 0.0f, func_0038DAB8(o->f48, 0.0f));
    func_003D9508(vec, 49, 0x30FF7F00, 1, 0.18f, 0.0f, o->f48 * 0.5f);
    func_003D9508(vec, 49, 0x0030FF7F, 1, 0.18f, 0.0f, o->f48 * -0.5f);
    func_003D9508(vec, 47, 0x607F7F7F, 1, 0.06f, 0.0f, func_00382538());
}
/* localdecomp:end func_L01_00372CE8 */

/* localdecomp:start func_L01_00372F78 */
#include "vu0.h"
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
struct Moby_373368;
void func_L01_00373410(struct Moby_373368 *);
void func_L01_00372F78(u8 *obj) {
    extern f32 func_00382538(void);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_0038CF38(void *, void *);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern void func_L01_00404A10_00372F78(void (*)(struct Moby_373368 *), u8 *);
    extern s32 func_L01_00456250(void *);
    extern void func_L01_003738E0(void *, s32);
    extern void func_L01_00456230(void *, s32);
    extern void func_003C2880(u8 *);
    extern void func_L01_003739B8(void *);
    vu0_v4 old, velocity;
    u8 info[0x30];
    vu0_v4 back, acceleration;
    u8 *state = *(u8 **)(obj + 0x68);
    f32 power = *(f32 *)(state + 0x3C);
    vu0_v4 *point;
    s32 hit;
    s32 rotation;
    *(f32 *)(state + 0x38) += 1.0f;
    if (*(f32 *)(state + 0x38) > 32.0f) power *= 1.0f - (*(f32 *)(state + 0x38) - 32.0f) / 6.0f;
    if (*(f32 *)(state + 0x38) > 2.0f) old = *(vu0_v4 *)(state + 0x10);
    else old = *(vu0_v4 *)state;
    rotation = (s32)func_00382538();
    func_L01_0046A610(state + 0x10, D_L01_001D66B0, 3, 96, 0xFF1010, rotation, 210000.0f, 200.0f, 0.95f, 0.0f, 0.0f);
    if (*(f32 *)(state + 0x38) < 15.0f) {
        *(f32 *)(state + 0x34) += 0.50000006f;
        func_0038CF68((f32 *)(state + 0x10), (f32 *)(state + 0x20), *(f32 *)(state + 0x34));
        func_0038CF68((f32 *)&velocity, (f32 *)(state + 0x20), 0.08000000566244125f);
        func_L01_00446760(info, obj, 0x10000, &velocity, power);
        *(u8 **)(info + 0x10) = obj;
        *(u16 *)(info + 0x1A) = *(u16 *)(obj + 0xAA);
        vec_add_ba(state + 0x10, state, state + 0x10);
        func_0038CF68((f32 *)&back, (f32 *)(state + 0x20), -0.50000006f);
        vec_add_ab(&back, &back, state + 0x10);
        hit = func_003D3CB0(state + 0x10, &old, 16, *(void **)(obj + 0xB8), info);
        if (hit) {
            Hit_0036C828 *collision = &D_L01_001EAA00;
            if (collision->hit == *(void **)(obj + 0xB8)) goto first_continue;
            {
                point = &collision->pos;
                *(vu0_q *)(state + 0x10) = *(vu0_q *)point;
                if (!func_L01_00456250(obj)) {
                    func_L01_003738E0(point, 20);
                    func_L01_00456230(obj, 1);
                }
                func_003C2880(obj);
                return;
            }
        }
    first_continue:
        func_L01_00404A10_00372F78(func_L01_00373410, obj);
    } else if (*(f32 *)(state + 0x38) < 38.0f) {
        if (0.50000006f < func_0038CF38(state, state + 0x10)) {
            *(f32 *)(state + 0x34) += 0.50000006f;
            func_0038CF68((f32 *)(state + 0x10), (f32 *)(state + 0x20), *(f32 *)(state + 0x34));
            func_0038CF68((f32 *)&velocity, (f32 *)(state + 0x20), 0.08000000566244125f);
            func_L01_00446760(info, obj, 0x10000, &velocity, power);
            *(u16 *)(info + 0x1A) = *(u16 *)(obj + 0xAA);
            vec_add_ba(state + 0x10, state, state + 0x10);
            func_0038CF68((f32 *)&back, (f32 *)(state + 0x20), -0.50000006f);
            vec_add_ab(&back, &back, state + 0x10);
            hit = func_003D3CB0(state + 0x10, &old, 16, obj, info);
            {
                u8 *other;
                if (hit) {
                    Hit_0036C828 *collision = &D_L01_001EAA00;
                    other = collision->hit;
                    if (other != *(u8 **)(obj + 0xB8) && (other == 0 || *(s16 *)(other + 0xAA) != 0x1625)) {
                        point = &collision->pos;
                        *(vu0_q *)(state + 0x10) = *(vu0_q *)point;
                        if (!func_L01_00456250(obj)) {
                            func_L01_003738E0(point, 20);
                            func_L01_00456230(obj, 1);
                        }
                        func_003C2880(obj);
                        return;
                    }
                }
            }
            func_0038CF68((f32 *)&acceleration, (f32 *)(state + 0x20), 1.0000001f);
            vec_add_ab(state, state, &acceleration);
            func_L01_00404A10_00372F78(func_L01_00373410, obj);
        }
    } else {
        func_L01_003739B8(state + 0x10);
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L01_00372F78 */

/* localdecomp:start func_L01_00373368 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_373368;
typedef struct {
    Vec_373368 start;
    Vec_373368 pos_10;
    Vec_373368 target;
    u8 pad_30[0x34 - 0x30];
    f32 speed;
    f32 age;
    f32 damage;
} PulseVars_373368;
typedef struct Moby_373368 {
    u8 pad_0[0x10];
    Vec_373368 position;
    s8 state;
    u8 pad_21[0x30 - 0x21];
    u8 unk_30;
    u8 unk_31;
    u16 unk_32;
    u8 pad_34[0x38 - 0x34];
    long unk_38;
    u8 pad_40[0x68 - 0x40];
    PulseVars_373368 *vars;
    u8 pad_6C[0xB8 - 0x6C];
    struct Moby_373368 *owner;
} Moby_373368;

extern void *func_003C24B0(s32 class_id, s32 flags);

/* holo_pulse_spawn: spawns the Ultrashield's pulse (class 0x1869) from shield, for damage,
   leaving from start toward target */
Moby_373368 *func_L01_00373368(Moby_373368 *shield, Vec_373368 *from, Vec_373368 *to, f32 damage) {
    Vec_373368 start = *from;
    Vec_373368 target = *to;
    Moby_373368 *pulse = func_003C24B0(0x1869, 0x80);

    if (pulse != 0) {
        PulseVars_373368 *vars;

        pulse->unk_30 = 0xFF;
        pulse->unk_32 = 0xFF;
        pulse->unk_31 = 1;
        pulse->state = 0;
        pulse->owner = shield;
        vars = pulse->vars;
        pulse->unk_38 = shield->unk_38;
        pulse->position = vars->start;
        vars->start = start;
        vars->target = target;
        vars->damage = damage;
        vars->age = 0.0f;
        vars->speed = 0.0f;
    }
    return pulse;
}
/* localdecomp:end func_L01_00373368 */

/* localdecomp:start func_L01_00373410 */
void func_L01_00373410(Moby_373368 *pulse) {
    extern void func_L01_00373438_00373410(Moby_373368 *, Vec_373368 *);
    Vec_373368 start=pulse->vars->start;
    func_L01_00373438_00373410(pulse,&start);
}
/* localdecomp:end func_L01_00373410 */
