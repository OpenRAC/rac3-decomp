#include "common.h"

typedef struct {
    u8 pad0[104];
    u8 *inner;
} Obj3899C0;
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t q[5];
} S_2BEE10;

INCLUDE_ASM("asm/levels", func_L01_00386B38);

/* localdecomp:start func_L01_003882A0 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_003882A0;
typedef struct { u8 pad[0x46]; u8 kind; } Class_003882A0;
typedef struct { u8 pad[0x24]; Class_003882A0 *cls; } Moby_003882A0;
typedef struct { u8 pad[0x18]; Moby_003882A0 *moby; } Hit_003882A0;
typedef struct { u8 pad[0x6C]; f32 damage; u8 tail[0x80]; } WeaponRow_003882A0;

extern Hit_003882A0 D_L01_001EAA00;
extern Vec_003882A0 D_L01_001EAA20;
extern WeaponRow_003882A0 D_L01_002C5600_003882A0[];
extern u8 D_001425E7[];
extern s32 D_001A71A0[];

/* shock_cannon_ray_test: tests one of the Shock Cannon's rays from start to end. On a hit, the
 * distance sets the damage (all of it under 10 u, 3/4 under 14, 1/2 under 20, else 1/8), queued on
 * the moby hit; returns that moby if its class is of kind 5, else 0. */
Moby_003882A0 *func_L01_003882A0(void *gun, Vec_003882A0 *start, Vec_003882A0 *end, Vec_003882A0 *shot, f32 radius) {
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern void *func_L01_00389B00_003882A0(void *, void *, void *, s32, f32);
    extern f32 func_0038CF00(void *, void *);
    extern void func_L01_00446978(void *, void *);
    extern void func_L01_0034C9F0(void *, s32, void *);
    Vec_003882A0 delta;
    f32 damage, dist;
    Moby_003882A0 *moby, *ret;
    Vec_003882A0 *hit_pos;

    vec_sub_ab(shot, end, start);
    func_0038CF68(shot, shot, 1.5f);
    shot->w = 5627.925f;
    if (func_003D3CB0(start, end, 16, D_001A71A0[0], 0)) {
        vec_sub_ab(&delta, end, start);
        func_0038CF68(&delta, &delta, 1.0f);
        hit_pos = &D_L01_001EAA20;
        vec_sub_ab(&delta, hit_pos, start);
        func_L01_00389B00_003882A0(start, &delta, hit_pos, 1, radius);
        if (((s32 *)hit_pos)[-2]) {
            damage = ((WeaponRow_003882A0 *)D_L01_002C5600_003882A0)[D_001425E7[0]].damage;
            dist = func_0038CF00(hit_pos, start);
            if (dist < 10.0f) ((f32 *)shot)[7] = damage;
            else if (dist < 14.0f) ((f32 *)shot)[7] = damage * 0.75f;
            else if (dist < 20.0f) ((f32 *)shot)[7] = damage * 0.5f;
            else ((f32 *)shot)[7] = damage * 0.125f;
            func_L01_00446978(D_L01_001EAA00.moby, shot);
            func_L01_0034C9F0(D_L01_001EAA00.moby, 39, gun);
            moby = D_L01_001EAA00.moby;
            ret = 0;
            if (moby != 0) {
                Class_003882A0 *cls = moby->cls;
                ret = moby;
                if (cls == 0 || cls->kind != 5) ret = 0;
            }
        } else {
            ret = 0;
        }
    } else {
        vec_sub_ab(&delta, end, start);
        func_L01_00389B00_003882A0(start, &delta, end, 0, -1.0f);
        ret = 0;
    }
    return ret;
}
/* localdecomp:end func_L01_003882A0 */

/* localdecomp:start func_L01_003884D8 */
#include "vu0.h"

extern void func_0038CE20(void *, void *, f32);
extern f32 D_L01_001DDE14;
extern f32 D_L01_001DDE10;
extern f32 D_L01_001DDE0C;
extern s32 D_L01_001DDE30;
extern s32 D_L01_001DDE34;
__asm__(".extern D_L01_001DDE14,4");
__asm__(".extern D_L01_001DDE10,4");
__asm__(".extern D_L01_001DDE0C,4");
__asm__(".extern D_L01_001DDE30,4");
__asm__(".extern D_L01_001DDE34,4");
extern f32 D_L01_001E1EC0;
extern s32 D_L01_001E1EBC;

void func_L01_003884D8(u8 *obj) {
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32,f32);
    extern void func_0038D328(s128 *,S_38C110v *);
    extern void func_003D9740(s128 *,s32,u32,s32,s32,f32);
    s128 mat[4];
    S_38C110v pos;
    S_38C110v dir;
    S_38C110v rot;
    S_38C110v offset;
    u8 *basis=obj+0xD0;
    pos=*(S_38C110v *)(*(u8 **)(obj+0x68)+0x10);
    func_0038CE20(&dir,basis,-1.0f);
    rot.x=0;
    rot.y=-func_0038D160(func_0038CED8(&dir),dir.z) + -1.5707964f;
    rot.z=func_0038D160(dir.x,dir.y);
    rot.w=1.0f;
    func_0038D328(mat,&rot);
    func_0038CE20(&offset,basis,-1.0f);
    func_0038CE20(&offset,&offset,5.0f);
    vec_add_ab(&pos,&pos,&offset);
    mat[3]=*(s128 *)&pos;
    func_0038CE20(&mat[0],&mat[0],D_L01_001DDE14);
    func_0038CE20(&mat[1],&mat[1],D_L01_001DDE10);
    func_0038CE20(&mat[2],&mat[2],D_L01_001DDE0C);
    D_L01_001E1EC0+=0.2f;
    if (D_L01_001E1EC0>=7.0f) D_L01_001E1EC0-=7.0f;
    func_003D9740(mat,D_L01_001DDE30,((D_L01_001E1EBC*5)<<24)|0xFF8080,4,1,D_L01_001E1EC0);
    func_0038CE20(&mat[0],&mat[0],D_L01_001DDE14*1.25f);
    func_0038CE20(&mat[1],&mat[1],D_L01_001DDE10*1.25f);
    func_003D9740(mat,D_L01_001DDE34,((D_L01_001E1EBC*3)<<24)|0xBF0530,2,1,D_L01_001E1EC0);
}
/* localdecomp:end func_L01_003884D8 */

/* localdecomp:start func_L01_003886E8 */
typedef struct {
    u8 pad0[0x16B0]; s32 mode;
    u8 pad16B4[0x25C0 - 0x16B4]; u8 *camera;
    u8 pad25C4[0x2874 - 0x25C4]; s16 aiming;
} Hero_003886E8;
extern Hero_003886E8 D_001A4BE0_003886E8;
extern s128 D_L01_001E29E0;
extern f32 D_L01_001DDE00, D_L01_001DDE04, D_L01_001DDE08;
extern s32 D_L01_001DDDF4, D_L01_001DDDF8, D_L01_001DDDFC;
extern s32 D_L01_001E1EA4;
extern f32 D_L01_001E1EA8, D_L01_001E1EAC, D_L01_001E1EB0;
__asm__(".extern D_L01_001DDE00, 4");
__asm__(".extern D_L01_001DDE04, 4");
__asm__(".extern D_L01_001DDE08, 4");
__asm__(".extern D_L01_001DDDF4, 4");
__asm__(".extern D_L01_001DDDF8, 4");
__asm__(".extern D_L01_001DDDFC, 4");

/* shock_cannon_domes_draw: the Shock Cannon lance's three spinning domes (fx_dome), from the gun
 * along the aim, the camera's facing, or the scripted direction, opening out along the lance. */
void func_L01_003886E8(u8 *moby) {
    extern void func_003C2F58(void *, s32, void *);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    extern void func_0038D328(s128 *, S_38C110v *);
    extern void func_0038D890(f32 *, f32 *, f32 *, f32);
    extern void func_003D9740(s128 *, s32, u32, s32, s32, f32);
    struct { s128 matrix[4], position, direction; S_38C110v rotation; s128 offset; } v;
    func_003C2F58(moby, 0, &v.position);
    if (D_001A4BE0_003886E8.aiming) {
        func_0038CE20(&v.direction, moby + 0xD0, -1.0f);
    } else if (D_001A4BE0_003886E8.mode == 1) {
        v.direction = D_L01_001E29E0;
    } else {
        v.direction = *(s128 *)(D_001A4BE0_003886E8.camera + 0xC0);
    }
    v.rotation.x = 0.0f;
    v.rotation.y = -func_0038D160(func_0038CED8(&v.direction), ((f32 *)&v.direction)[2]) + -1.57079637f;
    v.rotation.z = func_0038D160(((f32 *)&v.direction)[0], ((f32 *)&v.direction)[1]);
    v.rotation.w = 1.0f;
    func_0038D328(v.matrix, &v.rotation);
    if (D_001A4BE0_003886E8.aiming) {
        func_0038CE20(&v.offset, moby + 0xD0, -1.0f);
    } else if (D_001A4BE0_003886E8.mode == 1) {
        v.offset = D_L01_001E29E0;
    } else {
        v.offset = *(s128 *)(D_001A4BE0_003886E8.camera + 0xC0);
    }
    func_0038CE20(&v.offset, &v.offset, D_L01_001DDE00 - 0.5f);
    vec_add_ab(&v.position, &v.position, &v.offset);
    v.matrix[3] = v.position;
    func_0038CE20(&v.matrix[0], &v.matrix[0], D_L01_001DDE08);
    func_0038CE20(&v.matrix[1], &v.matrix[1], D_L01_001DDE04);
    func_0038CE20(&v.matrix[2], &v.matrix[2], D_L01_001DDE00);
    /* each dome's spin, wrapped at 7 */
    D_L01_001E1EA8 += 0.15f;
    if (D_L01_001E1EA8 >= 7.0f) D_L01_001E1EA8 -= 7.0f;
    D_L01_001E1EAC += 0.1f;
    if (D_L01_001E1EAC >= 7.0f) D_L01_001E1EAC -= 7.0f;
    D_L01_001E1EB0 += 0.05f;
    if (D_L01_001E1EB0 >= 7.0f) D_L01_001E1EB0 -= 7.0f;
    func_0038D890((f32 *)&v.matrix[0], (f32 *)&v.matrix[0], (f32 *)&v.matrix[2], 0.785398185f);
    func_0038D890((f32 *)&v.matrix[1], (f32 *)&v.matrix[1], (f32 *)&v.matrix[2], 0.785398185f);
    func_003D9740(v.matrix, D_L01_001DDDF4, (D_L01_001E1EA4 << 25) | 0x804020, 8, 1, D_L01_001E1EA8);
    func_0038D890((f32 *)&v.matrix[0], (f32 *)&v.matrix[0], (f32 *)&v.matrix[2], -1.57079637f);
    func_0038D890((f32 *)&v.matrix[1], (f32 *)&v.matrix[1], (f32 *)&v.matrix[2], -1.57079637f);
    func_003D9740(v.matrix, D_L01_001DDDF8, (D_L01_001E1EA4 << 25) | 0x801040, 8, 1, D_L01_001E1EAC);
    func_003D9740(v.matrix, D_L01_001DDDFC, (D_L01_001E1EA4 << 25) | 0x804010, 8, 1, D_L01_001E1EB0);
    func_0038CE20(&v.matrix[0], &v.matrix[0], 1.1f);
    func_0038CE20(&v.matrix[1], &v.matrix[1], 1.1f);
    func_003D9740(v.matrix, 10, (D_L01_001E1EA4 << 24) | 0xD20A40, 6, 1, D_L01_001E1EA8);
}
/* localdecomp:end func_L01_003886E8 */

/* localdecomp:start func_L01_00388AC8 */
#include "vu0.h"
typedef struct {
    u8 pad_0[0x110];
    s128 velocity;              /* 0x110 */
    u8 pad_120[0x360 - 0x120];
    s32 moving;                 /* 0x360 */
    u8 pad_364[0x6C0 - 0x364];
    S_38C110v axes[2];          /* 0x6C0 */
} Hero_00388AC8;
extern Hero_00388AC8 D_001A4BE0_00388AC8;
extern u8 *D_L01_00221098[];

/* A burst of 20 smoke puffs (particle_spawn_smoke) and embers (particle_spawn_ember) from position,
 * thrown out along a direction tilted 20 deg about the hero's axes and spun by a random angle each
 * time, carrying 1.7 x the hero's velocity when he moves. */
void func_L01_00388AC8(void *unused, s128 *position) {
    extern void func_0038D890(f32 *, f32 *, f32 *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D850(void *, void *, void *);
    S_38C110v spin, direction, base, origin, velocity, point, inherited, offset;
    s32 i, kind;
    f32 angle = 0.0f;
    u8 *particle;

    *(s128 *)&base = 0;
    base.x = 0.3f;
    base.y = -1.0f;
    base.w = 1.0f;
    *(s128 *)&origin = *position;
    func_0038D890((f32 *)&base, (f32 *)&D_001A4BE0_00388AC8.axes[0], (f32 *)&D_001A4BE0_00388AC8.axes[1], 0.34906584f);
    direction = base;
    qzero(&inherited);
    if (D_001A4BE0_00388AC8.moving)
        func_0038CE20(&inherited, &D_001A4BE0_00388AC8.velocity, 1.7f);
    func_0038CE20(&offset, &D_001A4BE0_00388AC8.axes[0], 0.4f);
    vec_add_ab(&origin, &origin, &offset);
    for (i = 0; i < 20; i++) {
        angle = func_0038DAB8(angle, func_003824E0(0.0f, 0.62831855f));
        func_0038CE20(&velocity, &direction, func_003824E0(0.24000001f, 0.32000002f));
        vec_add_ab(&velocity, &velocity, &inherited);
        point.x = origin.x + func_L01_00443A18(0.0f, 0.3f);
        point.y = origin.y + func_L01_00443A18(0.0f, 0.3f);
        point.z = origin.z + func_L01_00443A18(0.0f, 0.3f);
        kind = (s32)func_L01_00443A18(1.0f, 2.0f);
        particle = func_L01_004669B0(&point, 0.0f, 1.0f, 1.01f, func_003824E0(0.2f, 0.75f) * 210000.0f, kind,
                                     &D_001A4BE0_00388AC8.velocity, 0x7FFFFFFF, 0);
        if (particle) {
            u8 *p;
            particle[3] = 72;
            *(s16 *)(particle + 10) = 50;
            p = particle + 0x20;
            particle[9] = 68;
            *(f32 *)(p + 0x1C) = 4.0f;
            *(s32 *)(p + 4) = 3;
            p[10] = 48;
            p[11] = particle[10];
        }
        point.x = origin.x + func_L01_00443A18(0.0f, 0.6f);
        point.y = origin.y + func_L01_00443A18(0.0f, 0.6f);
        point.z = origin.z + func_L01_00443A18(0.0f, 0.6f);
        {
            f32 size = func_003824E0(0.2f, 1.75f);
            vec_sub_ab(&point, &point, &velocity);
            particle = func_L01_0046A610(&point, &velocity, 5, 127, 0x404040, kind, size * 210000.0f, 500.0f, 0.95f, 0.0f, 0.0f);
        }
        if (particle) particle[2] = D_L01_00221098[0x5B][1];
        if (fabs_asm(angle) > 0.00001f) {
            func_003C4840(&spin, &D_001A4BE0_00388AC8.axes[0], angle);
            func_0038D850(&direction, &base, &spin);
        }
    }
    {
        f32 scale = func_003824E0(8.0f, 12.0f) * 0.020000001f;
        func_0038CE20(&base, &D_001A4BE0_00388AC8.axes[0], scale);
    }
}
/* localdecomp:end func_L01_00388AC8 */

INCLUDE_ASM("asm/levels", func_L01_00388EE0);

/* localdecomp:start func_L01_00389798 */
typedef struct {
    u8 pad_0[0x10];
    u8 position[0x10];
} ShotVars_389798;
typedef struct {
    u8 pad_0[0x68];
    ShotVars_389798 *vars;
} Moby_389798;

/* The screen warp's timer: 6 frames for an uncharged shot, 27 charged (0x1E1F20 on NTSC-U) */
extern s32 D_L01_001E1EA0;
extern void func_L01_00389810(void *position, s32 texture, s32 alpha, f32 a, f32 b, f32 c, f32 d);

/* shock_cannon_warp: the Shock Cannon's screen warp each frame its timer runs: texture 66 at
   5 x the timer; the four floats (1, 0, 0, 0.9) aren't read */
void func_L01_00389798(Moby_389798 *shot) {
    func_L01_00389810(shot->vars->position, 0x42, D_L01_001E1EA0 * 5, 1.0f, 0.0f, 0.0f, 0.9f);
}
/* localdecomp:end func_L01_00389798 */

/* localdecomp:start func_L01_003897E8 */
/* The charged lance's beam state (0x1E1F50 on NTSC-U); declared small so its address is one la,
   as retail builds it. */
extern u8 D_L01_001E1ED0[8];
/* The beam's numbers: fade times, half width, texture spacing (0x2B3C90 on NTSC-U) */
extern u8 D_L01_002B3C10[];
extern void func_L01_0040B858(void *beam, void *numbers);

/* shock_cannon_beam_draw: draws the Shock Cannon's charged lance beam with fx_beam_rings:
   texture 69 from the gun 40 u along the aim */
void func_L01_003897E8(void) {
    func_L01_0040B858(D_L01_001E1ED0, D_L01_002B3C10);
}
/* localdecomp:end func_L01_003897E8 */

/* localdecomp:start func_L01_00389810 */
extern s32 D_001D5520;
extern s16 D_001CFEC0[];
extern s32 D_L01_001DDE38;
__asm__(".extern D_L01_001DDE38, 4");
extern s32 D_L01_001DDE40;
__asm__(".extern D_L01_001DDE40, 4");
extern s32 D_L01_001DDE44;
__asm__(".extern D_L01_001DDE44, 4");
extern s32 D_L01_001DDE48;
__asm__(".extern D_L01_001DDE48, 4");
extern s32 D_L01_001DDE4C;
__asm__(".extern D_L01_001DDE4C, 4");
extern s32 D_L01_001DDE50;
__asm__(".extern D_L01_001DDE50, 4");
extern s32 D_L01_001DDE54;
__asm__(".extern D_L01_001DDE54, 4");
extern s32 D_L01_001DDE58;
__asm__(".extern D_L01_001DDE58, 4");
extern s32 D_L01_001DDE5C;
__asm__(".extern D_L01_001DDE5C, 4");
extern s32 D_L01_001DDE60;
__asm__(".extern D_L01_001DDE60, 4");
extern s32 D_L01_001DDE64;
__asm__(".extern D_L01_001DDE64, 4");
extern s32 D_L01_001DDE68;
__asm__(".extern D_L01_001DDE68, 4");
extern s32 D_L01_001DDE6C;
__asm__(".extern D_L01_001DDE6C, 4");
extern s32 D_L01_001DDE70;
__asm__(".extern D_L01_001DDE70, 4");
extern s32 D_L01_001DDE94;
__asm__(".extern D_L01_001DDE94, 4");
extern void func_L01_004C5E28(void);
/* the file's earlier blocks declare it with a 32-bit value; these calls pass the full 64-bit GS register */
extern void func_003A9440(s32, unsigned long);
extern unsigned long func_00389598(s32 a);
extern void func_0038B4D0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, long i, long j);

/* shock_cannon_warp_draw: the screen warp, texture 66 into the frame's alpha in four mirrored quarters, then the frame's copy mixed in */
void func_L01_00389810(void *position, s32 texture, s32 alpha, f32 a, f32 b, f32 c, f32 d) {
    long tex, col;

    func_L01_004C5E28();
    if (D_001D5520 != 0) {
        D_L01_001DDE94 = -1;
        D_L01_001DDE6C = 0xEC;
        D_L01_001DDE70 = 0xF0;
    }
    ((void (*)(s32, long))func_003A9440)(0x47, 0x513F1);
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDE44 | ((long)D_L01_001DDE48 << 2) | ((long)D_L01_001DDE4C << 4) | ((long)D_L01_001DDE50 << 6)) | (0x8000L << 24));
    tex = func_00389598(D_L01_001DDE38);
    col = (s32)((alpha << 24) | 0x7F7F7F);
    func_0038B4D0(0, 0, (s32)((f32)D_001CFEC0[0xA8] * 0.5f), (s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(D_001CFEC0[0xA8], 0, -(s32)((f32)D_001CFEC0[0xA8] * 0.5f), (s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(0, D_001CFEC0[0xA9], (s32)((f32)D_001CFEC0[0xA8] * 0.5f), -(s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(D_001CFEC0[0xA8], D_001CFEC0[0xA9], -(s32)((f32)D_001CFEC0[0xA8] * 0.5f), -(s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDE44 | ((long)D_L01_001DDE48 << 2) | ((long)D_L01_001DDE4C << 4) | ((long)D_L01_001DDE50 << 6)) | (0x8000L << 24));
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDE54 | ((long)D_L01_001DDE58 << 2) | ((long)D_L01_001DDE5C << 4) | ((long)D_L01_001DDE60 << 6)) | (0x8000L << 24));
    func_0038B4D0(0, 0, D_001CFEC0[0xA8], D_001CFEC0[0xA9], D_L01_001DDE64, D_L01_001DDE68, D_L01_001DDE6C, D_L01_001DDE70, D_L01_001DDE40, func_00389598(D_L01_001DDE94));
}
/* localdecomp:end func_L01_00389810 */

/* localdecomp:start func_L01_00389B00 */
#include "vu0.h"
typedef struct {
    s128 position;             /* 0x00 */
    u8 pad_10[0x10];
    vu0_v4 velocity;           /* 0x20 */
    u8 pad_30[4];
    s32 owner;                 /* 0x34 */
    s32 life;                  /* 0x38 */
    f32 fade;                  /* 0x3C */
    u8 pad_40[0x10];
    vu0_v4 back;               /* 0x50 */
    f32 value;                 /* 0x60 */
} Vars_00389B00;
typedef struct Moby_00389B00 {
    u8 pad_0[0x10];
    s128 pos;                  /* 0x10 */
    u8 b20;                    /* 0x20 */
    u8 pad_21[0xF];
    u8 b30;                    /* 0x30 */
    u8 b31;                    /* 0x31 */
    u16 h32;                   /* 0x32 */
    u16 h34;                   /* 0x34 */
    u8 pad_36[0x68 - 0x36];
    Vars_00389B00 *vars;       /* 0x68 */
} Moby_00389B00;
extern u8 *func_003C24B0(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0038A4B8(void *);

Moby_00389B00 *func_L01_00389B00(s128 *position, void *direction, s128 *rotation, s32 owner, f32 value)
{
    Moby_00389B00 *moby = (Moby_00389B00 *)func_003C24B0(0x1883, 0x80);
    if (moby != 0) {
        Vars_00389B00 *vars = moby->vars;
        s128 *pos = &moby->pos;
        vu0_v4 back;
        moby->b30 = 0xFF;
        moby->b20 = 0;
        moby->h32 = 0xFF;
        moby->b31 = 1;
        moby->h34 |= 0x41;
        func_0038CF68(&vars->velocity, direction, 0.16000001f);
        vars->position = *position;
        moby->pos = *rotation;
        func_0038CF68(&back, &vars->velocity, -1.5f);
        vec_add_ab(&vars->back, position, &back);
        vars->value = value;
        vars->owner = owner;
        vars->fade = 0.05882353f;
        vars->life = 17;
        func_L01_0038A4B8(pos);
    }
    return moby;
}
/* localdecomp:end func_L01_00389B00 */

INCLUDE_ASM("asm/levels", func_L01_00389C28);

/* localdecomp:start func_L01_0038A0F8 */
#include "vu0.h"
typedef struct {
    vu0_v4 position[4];
    u32 colour[4];
    f32 uv[4][2];
    u8 pad70[0x20];
} Quad_0038A0F8;
extern s32 D_L01_001DDEA0;
extern s32 D_L01_001DDEA4;
extern vu0_v4 D_L01_001E29C0;
__asm__(".extern D_L01_001DDEA0, 4");
__asm__(".extern D_L01_001DDEA4, 4");

/* shock_cannon_ray_draw: draws the Shock Cannon's ray (class 0x1883) from the moby to the end point
 * in its vars (+0x50) as camera-facing quads, their u scrolled by vars+0x30 each frame: the first
 * texture in (0x20, 0x40, 0x80) blended over two halves, then the second in (0, 0x40, 0xFF), its
 * alpha 96 x life x fade. */
void func_L01_0038A0F8(u8 *moby) {
    extern void func_003D93B0(Quad_0038A0F8 *, s32, s32, s32);
    extern void func_003D2DA0(Quad_0038A0F8 *, s32, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    Quad_0038A0F8 quad;
    vu0_v4 eye, step, end, side;
    u8 *vars;
    f32 intensity, *uv;
    s32 i;
    u32 colour;

    vars = *(u8 **)(moby + 0x68);
    if (moby == 0) return;
    if (moby[0x20] == 0xFE) return;
    if (moby[0x20] == 0xFD) return;
    if (vars == 0) return;
    intensity = (f32)*(s32 *)(vars + 0x38) * *(f32 *)(vars + 0x3C);
    func_003D93B0(&quad, D_L01_001DDEA0, 0, 0x80);
    colour = ((s32)(intensity * 96.0f) << 24) | 0x804020;
    quad.colour[1] = colour;
    quad.colour[0] = colour;
    quad.colour[3] = colour;
    quad.colour[2] = colour;
    quad.uv[0][0] = 0.0f;
    quad.uv[0][1] = 0.0f;
    quad.uv[1][0] = 0.0f;
    quad.uv[1][1] = 1.0f;
    quad.uv[2][0] = 1.0f;
    quad.uv[2][1] = 0.0f;
    quad.uv[3][0] = 1.0f;
    quad.uv[3][1] = 1.0f;
    uv = &quad.uv[0][0];
    for (i = 3; i >= 0; i--, uv += 2) {
        *uv += *(f32 *)(vars + 0x30);
        if (*uv >= 7.0f) *uv -= 7.0f;
    }
    *(f32 *)(vars + 0x30) += 0.1f;
    if (*(f32 *)(vars + 0x30) >= 4.0f) *(f32 *)(vars + 0x30) -= 4.0f;
    vec_sub_ab(&eye, moby + 0x10, &D_L01_001E29C0);
    vec_sub_ab(&step, vars + 0x50, moby + 0x10);
    func_0038CE20(&step, &step, 0.5f);
    vec_add_ba(&end, moby + 0x10, &step);
    func_0038CE90(&side, &eye, &step);
    func_0038CF68(&side, &side, 1.4f);
    vec_add_ba(&quad.position[0], moby + 0x10, &side);
    vec_sub_ab(&quad.position[1], moby + 0x10, &side);
    func_0038CF68(&side, &side, 0.6f);
    vec_add_ba(&quad.position[2], &end, &side);
    vec_sub_ba(&quad.position[3], &end, &side);
    func_003D2DA0(&quad, 0, 0);
    quad.colour[0] = quad.colour[2];
    quad.colour[1] = quad.colour[3];
    quad.colour[3] = 0x204080;
    quad.colour[2] = 0x204080;
    *(vu0_q *)&quad.position[0] = *(vu0_q *)&quad.position[2];
    *(vu0_q *)&quad.position[1] = *(vu0_q *)&quad.position[3];
    vec_add_ba(&quad.position[2], &quad.position[2], &step);
    vec_add_ab(&quad.position[3], &quad.position[3], &step);
    func_003D2DA0(&quad, 0, 0);
    func_003D93B0(&quad, D_L01_001DDEA4, 1, 0x80);
    colour = ((s32)(intensity * 96.0f) << 24) | 0xFF4000;
    quad.uv[0][0] = 0.0f;
    quad.uv[0][1] = 0.0f;
    quad.uv[1][0] = 0.0f;
    quad.uv[1][1] = 1.0f;
    quad.colour[1] = colour;
    quad.uv[2][0] = 1.0f;
    quad.uv[2][1] = 0.0f;
    quad.uv[3][0] = 1.0f;
    quad.colour[0] = colour;
    quad.colour[3] = 0xFF4000;
    quad.uv[3][1] = 1.0f;
    quad.colour[2] = 0xFF4000;
    func_0038CF68(&side, &side, 0.6f);
    vec_add_ba(&quad.position[0], moby + 0x10, &side);
    vec_sub_ab(&quad.position[1], moby + 0x10, &side);
    vec_add_ab(&end, moby + 0x10, &step);
    vec_add_ba(&end, &end, &step);
    vec_add_ab(&quad.position[2], &end, &side);
    vec_sub_ab(&quad.position[3], &end, &side);
    func_003D2DA0(&quad, 0, 0);
}
/* localdecomp:end func_L01_0038A0F8 */

/* localdecomp:start func_L01_0038A4B8 */
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
extern u8 *D_L01_00221098[];

void func_L01_0038A4B8(void *p) {
    extern f32 func_0038D160(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    vu0_v4 *origin = p;
    vu0_v4 delta, velocity, position;
    f32 angle, speed, tilt, yaw;
    f32 life;
    s32 type, i;
    u8 *particle;

    vec_sub_ab(&delta, &D_L01_001E29C0, origin);
    angle = func_0038D160(delta.x, delta.y);
    for (i = 14; i >= 0; i--) {
        speed = func_003824E0(0.5f, 1.0f);
        type = func_L01_00443A18(1.0f, 2.0f);
        func_003824E0(0.05f, 0.2f);
        life = 210000.0f;
        tilt = func_003824E0(0.0f, 1.3962634f);
        yaw = func_0038DAB8(angle, func_L01_00443A18(0.0f, 1.3962634f));
        func_00382760(&velocity, speed * 0.020000001415610313f, yaw, tilt);
        position.x = origin->x + func_L01_00443A18(0.0f, 0.1f);
        position.y = origin->y + func_L01_00443A18(0.0f, 0.1f);
        position.z = origin->z + func_L01_00443A18(0.0f, 0.1f);
        particle = func_L01_0046A610(&position, &velocity, 25, 127, 0x7F7F7F, type,
            func_003824E0(0.05f, 0.2f) * life, 500.0f, 1.0f, 0.0f, 2.0f);
        if (particle) particle[2] = D_L01_00221098[0x5B][1];
    }
}
/* localdecomp:end func_L01_0038A4B8 */

/* localdecomp:start func_L01_0038A708 */
typedef struct {
    u8 pad_0[0x1D8];
    s32 i1D8;                  /* 0x1D8 */
    u8 pad_1DC[0x6F0 - 0x1DC];
    S_38C110v aim;             /* 0x6F0 */
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
} Hero_0038A708;
typedef struct {
    u8 pad_0[0x10];
    u8 landing[0x10];          /* 0x10 */
    f32 timer;                 /* 0x20 */
    s32 w24;                   /* 0x24 */
    s32 w28;                   /* 0x28 */
    s32 rumble;                /* 0x2C */
} Vars_0038A708;
typedef struct {
    u8 pad_0[0x20];
    u8 phase;                  /* 0x20 */
    u8 pad_21[0x42 - 0x21];
    u8 b42;                    /* 0x42 */
    u8 b43;                    /* 0x43 */
    u8 pad_44[0x60 - 0x44];
    u8 b60;                    /* 0x60 */
    u8 pad_61[0x68 - 0x61];
    Vars_0038A708 *vars;       /* 0x68 */
} Moby_0038A708;
typedef struct { u8 pad_0[0x50]; f32 rate; u8 pad_54[0xF0 - 0x54]; } Row_0038A708;
typedef struct { s32 w[5]; } Skip_0038A708;
typedef struct { s32 w[6]; } Skip2_0038A708;
extern Hero_0038A708 D_001A4BE0_0038A708;
extern u8 *D_001D52FC;
extern s32 D_001D545C;
extern u8 D_00142637[];
extern u8 D_L01_001DAFF0_0038A708;
extern s32 D_L01_001D673C_0038A708;
extern s32 D_L01_001E1F10_0038A708;
extern f32 D_L01_001DDEA8_0038A708;
__asm__(".extern D_L01_001DDEA8_0038A708, 4");
extern f32 D_L01_001DDEAC_0038A708;
__asm__(".extern D_L01_001DDEAC_0038A708, 4");
extern f32 D_L01_001DDEB0_0038A708;
__asm__(".extern D_L01_001DDEB0_0038A708, 4");
extern f32 D_L01_001DDEB4_0038A708;
__asm__(".extern D_L01_001DDEB4_0038A708, 4");
extern Skip_0038A708 D_L01_001DDEB8_0038A708;
extern Skip2_0038A708 D_L01_001DDED0_0038A708;
extern u8 D_L01_002B3C60_0038A708[];
extern Row_0038A708 D_L01_002C5600_0038A708[];
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_00444F38_0038A708(u8 *, s32, s32, s32, s32);
extern u8 *func_00382348(void *);
extern s32 func_0038CAD0(void *);
extern u8 *func_L01_004501E8_0038A708(void *, void *, f32, f32, f32, f32, void *, s32, s32, s32, f32, s32, void *, s32, s32, s32);
extern void func_L01_0038AD40_0038A708(void *, void *, void *, s32, f32, f32, f32, f32);
extern s32 func_L01_004C7A18_0038A708(f32, void *, void *, void *, void *, void *, s32, s32);
extern void func_L01_004EAA80_0038A708(void);
extern s32 func_L01_005118D0_0038A708(s32, s32);
extern void func_L01_004EA7D8_0038A708(s32);
extern s32 func_L01_003F2058_0038A708(void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00362610_0038A708(void *, void *, void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_005119E0_0038A708(s32);
extern void func_L01_003F2278_0038A708(s32, void *);
extern s32 func_L01_0040E050_0038A708(void *);
extern void func_L01_00404A10_0038A708(void *, void *);
extern void func_L01_0038ACE8_0038A708(void *);

void func_L01_0038A708(Moby_0038A708 *m)
{
    Vars_0038A708 *vars = m->vars;
    u8 *target;
    S_38C110v pos;
    union { Skip_0038A708 skip; S_38C110v dir; } u;
    Skip2_0038A708 skip2;
    s32 at;
    s32 at2;
    s32 can_fire;

    func_003C2F58(m, 0, &pos);
    if (m->b42 == m->b43 && (m->b60 & 2))
        func_L01_00444F38_0038A708((u8 *)m, 1, 0, 2, 0);
    target = 0;
    if (D_001A4BE0_0038A708.lockon_target != 0 && D_001A4BE0_0038A708.lockon_target[0x20] != 0xFE &&
        D_001A4BE0_0038A708.lockon_target[0x20] != 0xFD) {
        f32 *health = (f32 *)func_00382348(D_001A4BE0_0038A708.lockon_target);
        if (health != 0 && 0.0f < *health)
            target = D_001A4BE0_0038A708.lockon_target;
    }
    can_fire = 1;
    if (D_001A4BE0_0038A708.state == 0x1D || D_001A4BE0_0038A708.state == 1) {
        if (func_0038CAD0(&D_001A4BE0_0038A708.aiming_fire_wait) == 0)
            can_fire = 0;
    } else {
        D_001A4BE0_0038A708.aiming_fire_wait = 0x21;
        if (target == 0) {
            u.skip = D_L01_001DDEB8_0038A708;
            target = func_L01_004501E8_0038A708(&pos, &D_001A4BE0_0038A708.aim, 0.39269909262657166f, 1.5707963705062866f,
                                       11.100000381469727f, 0.0f, &at, 0, 0, 0, 0.0f, 0, &u.skip, 1, -1, 0);
        }
    }
    if (D_L01_001DAFF0_0038A708 != 0 && D_001D545C == 5) {
        skip2 = D_L01_001DDED0_0038A708;
        target = func_L01_004501E8_0038A708(&pos, &D_001A4BE0_0038A708.aim, 0.8726646304130554f, 1.0471975803375244f,
                                   30.0f, 0.0f, &at2, 0, 0, 0, 0.0f, 0, &skip2, 1, -1, 0);
        if (target != 0 && *(s16 *)(target + 0xAA) == 0x1A13) {
            D_L01_001DDEA8_0038A708 = 10.0f;
            D_L01_001DDEB4_0038A708 = 50.0f;
        } else {
            D_L01_001DDEA8_0038A708 = 12.0f;
            D_L01_001DDEB4_0038A708 = 12.5f;
        }
    } else if (D_L01_001D673C_0038A708 != 0) {
        D_L01_001DDEA8_0038A708 = 6.0f;
        D_L01_001DDEB4_0038A708 = 12.5f;
    } else {
        D_L01_001DDEA8_0038A708 = 12.0f;
        D_L01_001DDEB4_0038A708 = 12.5f;
    }
    func_L01_0038AD40_0038A708(&u.dir, &pos, target, 0, D_L01_001DDEAC_0038A708, D_L01_001DDEA8_0038A708,
                      D_L01_001DDEB4_0038A708 * 0.020000001415610313f, D_L01_001DDEB0_0038A708 * 0.0004000000189989805f);
    vars->w24 = func_L01_004C7A18_0038A708(D_L01_001DDEB0_0038A708 * 0.0004000000189989805f, &pos, &u.dir, vars, vars->landing,
                                  m, 0, 0);
    switch (m->phase) {
    case 0:
        m->phase = 1;
        vars->rumble = -1;
        vars->timer = 0.0f;
        vars->w28 = 0;
    case 1:
        if (D_001A4BE0_0038A708.i1D8 >= 0x12)
            func_L01_004EAA80_0038A708();
        if (can_fire && vars->timer == 0.0f && D_001A4BE0_0038A708.no_firing == 0 &&
            (*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0_0038A708.fire_button) &&
            D_001A4BE0_0038A708.i1220 >= 0x13) {
            if (func_L01_005118D0_0038A708(-1, 1)) {
                D_L01_001E1F10_0038A708 = 1;
                func_L01_004EA7D8_0038A708(-1);
                vars->rumble = func_L01_003F2058_0038A708(D_L01_002B3C60_0038A708, 0);
                func_L01_00444F38_0038A708((u8 *)m, 2, 0, 2, 0);
                if (target != 0)
                    func_0038D890(&u.dir, &u.dir, D_001A4BE0_0038A708.moby + 0xD0, -0.17453292012214661f);
                else
                    func_0038D890(&u.dir, &u.dir, D_001A4BE0_0038A708.moby + 0xD0, 0.08726646006107330f);
                if (func_0038CEA8(&u.dir) > 0.6000000238418579f)
                    func_0038CF68(&u.dir, &u.dir, 0.4400000274181366f);
                func_L01_00362610_0038A708(&pos, &u.dir, m, 1, 0);
                func_003A52A0(0, 0, m);
                vars->timer = 1.0f / (D_L01_002C5600_0038A708 + D_00142637[0])->rate;
            } else if ((*(s32 *)(D_001D52FC + 0x1A4) & D_001A4BE0_0038A708.fire_button) || D_L01_001E1F10_0038A708 == 1) {
                func_003A52A0(1, 0, m);
                D_L01_001E1F10_0038A708 = 0;
            }
            if (!((*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0_0038A708.fire_button) && func_L01_005119E0_0038A708(-1) &&
                  D_001A4BE0_0038A708.b25E9 != 0) && vars->rumble >= 0) {
                func_L01_003F2278_0038A708(vars->rumble, 0);
                vars->rumble = -1;
            }
        }
        break;
    }
    func_L01_0040E050_0038A708(&vars->timer);
    func_L01_00404A10_0038A708(func_L01_0038ACE8_0038A708, m);
}
/* localdecomp:end func_L01_0038A708 */

/* localdecomp:start func_L01_0038ACE8 */

extern s32 func_L01_005119E0(s32);
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, f32);

void func_L01_0038ACE8(Obj3899C0 *obj) {
    u8 *p = obj->inner;
    if (*(s32 *)(p + 36) == 0) {
        return;
    }
    if (func_L01_005119E0(-1)) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_0038ACE8 */

INCLUDE_ASM("asm/levels", func_L01_0038AD40);

/* localdecomp:start func_L01_0038B280 */
#include "vu0.h"

typedef struct {
    u8 pad_0[0x80];
    vu0_v4 pos;                /* 0x80 */
    u8 pad_90[0x1D8 - 0x90];
    s32 i1D8;                  /* 0x1D8 */
    u8 pad_1DC[0x6F0 - 0x1DC];
    vu0_v4 aim;                /* 0x6F0 */
    u8 pad_700[0x1210 - 0x700];
    s32 fire_button;           /* 0x1210 */
    u8 pad_1214[0x1220 - 0x1214];
    s32 i1220;                 /* 0x1220 */
    u8 pad_1224[0x1430 - 0x1224];
    u8 *lockon_target;         /* 0x1430 */
    u8 pad_1434[0x25C4 - 0x1434];
    s32 state;                 /* 0x25C4 */
    u8 pad_25C8[0x25E9 - 0x25C8];
    u8 b25E9;                  /* 0x25E9 */
    u8 pad_25EA[0x25ED - 0x25EA];
    u8 no_firing;              /* 0x25ED */
    u8 pad_25EE[0x2874 - 0x25EE];
    s16 h2874;                 /* 0x2874 */
    u8 pad_2876[0x28BC - 0x2876];
    s32 aiming_fire_wait;      /* 0x28BC */
} Hero_38B280_0038B280;
typedef struct {
    u8 pad_0[0x10];
    u8 landing[0x10];          /* 0x10 */
    f32 timer;                 /* 0x20 */
    s32 w24;                   /* 0x24 */
    u8 pad_28[4];
    s32 rumble;                /* 0x2C */
} InfVars_38B280_0038B280;
typedef struct {
    u8 pad_0[0x10];
    vu0_v4 pos;                /* 0x10 */
    u8 phase;                  /* 0x20 */
    u8 pad_21[0x42 - 0x21];
    u8 b42;                    /* 0x42 */
    u8 b43;                    /* 0x43 */
    u8 pad_44[0x60 - 0x44];
    u8 b60;                    /* 0x60 */
    u8 pad_61[0x68 - 0x61];
    InfVars_38B280_0038B280 *vars;      /* 0x68 */
    u8 pad_6C[0xC0 - 0x6C];
    u8 matrix[0x10];           /* 0xC0 */
    u8 forward[0x10];          /* 0xD0 */
} Inf_38B280_0038B280;
typedef struct { u8 pad_0[0x50]; f32 rate; u8 pad_54[0xF0 - 0x54]; } Row_38B280_0038B280;
typedef struct { s32 w[5]; } Skip_38B280_0038B280;

extern Hero_38B280_0038B280 D_001A4BE0;
extern u8 *D_001D52FC;
extern u8 D_001425F7[];
extern s32 D_L01_001D673C_0038B280;
extern s32 D_L01_001E1F14_0038B280;
extern f32 D_L01_001DDEF0_0038B280;
__asm__(".extern D_L01_001DDEF0_0038B280, 4");
extern f32 D_L01_001DDEF4_0038B280;
__asm__(".extern D_L01_001DDEF4_0038B280, 4");
extern f32 D_L01_001DDEF8_0038B280;
__asm__(".extern D_L01_001DDEF8_0038B280, 4");
extern f32 D_L01_001DDEFC_0038B280;
__asm__(".extern D_L01_001DDEFC_0038B280, 4");
extern f32 D_L01_001DDF00_0038B280[2];
__asm__(".extern D_L01_001DDF00_0038B280, 8");
extern Skip_38B280_0038B280 D_L01_001DDF10_0038B280;
extern u8 D_L01_002B3CE0_0038B280[];
extern Row_38B280_0038B280 D_L01_002C5600_0038B280[];
extern u8 D_L01_001D66B0_0038B280[8];
extern u8 *D_L01_0022123C_0038B280[];

extern void func_003C2F58(void *, s32, void *);
extern u8 *func_00382348(void *);
extern s32 func_0038CAD0(void *);
extern u8 *func_L01_004501E8_0038B280(void *, void *, f32, f32, f32, f32, void *, s32, s32, s32, f32, s32, void *, s32, s32, s32);
extern void func_L01_004C7438_0038B280(void *out, void *in, void *target, s32 b, f32 c, f32 d, f32 e, f32 f);
extern s32 func_L01_004C7A18_0038B280(f32 h, void *a, void *b, void *c, void *d, void *e, s32 f, s32 g);
extern void func_L01_00444F38_0038B280(u8 *, s32, s32, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004EAA80_0038B280(void);
extern s32 func_L01_005118D0_0038B280(s32, s32);
extern void func_L01_004EA7D8_0038B280(s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_003F2058_0038B280(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00390240_0038B280(void *, void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_005119E0_0038B280(s32);
extern void func_L01_003F2278_0038B280(s32, void *);
extern void func_0038D000(void *, void *, void *);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8_0038B280(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_00382468(s32);
extern void func_L01_004C7D98_0038B280(void *, void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_0013D3E0(void);
extern void func_L01_00466F50_0038B280(void *, void *, s32, f32, f32);
extern s32 func_L01_0040E050_0038B280(void *);
extern void func_L01_00404A10_0038B280(void *, void *);
extern void func_L01_0038B950_0038B280(u8 *);

/* infector_v5_update: the Infector's V5 update: entry 0 to fire, 1 for no ammo */
void func_L01_0038B280(Inf_38B280_0038B280 *inf)
{
    InfVars_38B280_0038B280 *vars = inf->vars;
    u8 *target = 0;
    vu0_v4 from;
    union { Skip_38B280_0038B280 skip; vu0_v4 pos; } u;
    vu0_v4 spot;
    vu0_v4 up;
    vu0_v4 at;
    s32 can_fire;
    s32 life;
    u8 *p;

    func_003C2F58(inf, 0, &from);
    if (D_001A4BE0.lockon_target != 0 && D_001A4BE0.lockon_target[0x20] != 0xFE &&
        D_001A4BE0.lockon_target[0x20] != 0xFD) {
        f32 *health = (f32 *)func_00382348(D_001A4BE0.lockon_target);
        if (health != 0 && 0.0f < *health)
            target = D_001A4BE0.lockon_target;
    }
    can_fire = 1;
    if (D_001A4BE0.state == 0x1D || D_001A4BE0.state == 1) {
        if (func_0038CAD0(&D_001A4BE0.aiming_fire_wait) == 0)
            can_fire = 0;
    } else {
        D_001A4BE0.aiming_fire_wait = 0x21;
        if (target == 0) {
            u.skip = D_L01_001DDF10_0038B280;
            target = func_L01_004501E8_0038B280(&from, &D_001A4BE0.aim, 0.39269909262657166f, 0.7853981852531433f,
                                       11.100000381469727f, 0.0f, &at, 0, 0, 0, 0.0f, 0, &u.skip, 1, -1, 0);
        }
    }
    if (D_L01_001D673C_0038B280 != 0) {
        D_L01_001DDEF0_0038B280 = 7.800000190734863f;
        D_L01_001DDEF4_0038B280 = 9.999999747378752e-06f;
        D_L01_001DDEF8_0038B280 = 12.0f;
        D_L01_001DDEFC_0038B280 = 10.0f;
    } else {
        D_L01_001DDEF0_0038B280 = 12.0f;
        D_L01_001DDEF4_0038B280 = 9.999999747378752e-06f;
        D_L01_001DDEF8_0038B280 = 12.0f;
        D_L01_001DDEFC_0038B280 = 15.0f;
    }
    func_L01_004C7438_0038B280(&u.pos, &from, target, 0, D_L01_001DDEF4_0038B280, D_L01_001DDEF0_0038B280,
                      D_L01_001DDEFC_0038B280 * 0.020000001415610313f, D_L01_001DDEF8_0038B280 * 0.0004000000189989805f);
    vars->w24 = func_L01_004C7A18_0038B280(D_L01_001DDEF8_0038B280 * 0.0004000000189989805f, &from, &u.pos, vars, vars->landing,
                                  inf, 0, 0);
    if (inf->b42 == inf->b43 && (inf->b60 & 2))
        func_L01_00444F38_0038B280((u8 *)inf, 1, 0, 2, 0);
    if (D_001A4BE0.h2874 != 0)
        func_0038CE20(&u.pos, inf->forward, -0.2900000214576721f);
    switch (inf->phase) {
    case 0:
        inf->phase = 1;
        vars->rumble = -1;
        vars->timer = 0.0f;
    case 1:
        if (D_001A4BE0.i1D8 >= 0x12)
            func_L01_004EAA80_0038B280();
        if (vars->timer == 0.0f && D_001A4BE0.no_firing == 0 &&
            (*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0.fire_button) && can_fire &&
            D_001A4BE0.i1220 >= 0x13) {
            if (func_L01_005118D0_0038B280(-1, 1)) {
                D_L01_001E1F14_0038B280 = 1;
                func_L01_004EA7D8_0038B280(-1);
                func_003C3A10(inf, 2, 0, 0);
                vars->rumble = func_L01_003F2058_0038B280(D_L01_002B3CE0_0038B280, 0);
                if (func_0038CEA8(&u.pos) > 0.6000000238418579f)
                    func_0038CF68(&u.pos, &u.pos, 0.4400000274181366f);
                func_L01_00390240_0038B280(inf, &from, &u.pos);
                func_003A52A0(0, 0, inf);
                vars->timer = 1.0f / (D_L01_002C5600_0038B280 + D_001425F7[0])->rate;
            } else if ((*(s32 *)(D_001D52FC + 0x1A4) & D_001A4BE0.fire_button) || D_L01_001E1F14_0038B280 == 1) {
                func_003A52A0(1, 0, inf);
                D_L01_001E1F14_0038B280 = 0;
            }
            if (!((*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0.fire_button) && func_L01_005119E0_0038B280(-1) &&
                  D_001A4BE0.b25E9 != 0) && vars->rumble >= 0) {
                func_L01_003F2278_0038B280(vars->rumble, 0);
                vars->rumble = -1;
            }
            inf->phase = 1;
        }
        break;
    }
    if (D_001A4BE0.no_firing == 0) {
        func_0038D000(&spot, D_L01_001DDF00_0038B280, inf->matrix);
        vec_add_ab(&spot, &spot, &inf->pos);
        life = (func_00382498(10, 20) * 5 + 2) / 6;
        p = func_L01_004713C8_0038B280(&spot, D_L01_001D66B0_0038B280, life, 0x5A182, func_00382498(1, 4), 0x30, 0, 0,
                              52500.0f, 157500.0f, 0.00020000000949949026f);
        if (p != 0) {
            p[3] = func_00382468(2) ? 0x48 : 0x44;
            p[2] = D_L01_0022123C_0038B280[0][0];
        }
        func_L01_004C7D98_0038B280(&D_001A4BE0.pos, &up);
        func_0038CF68(&up, &up, func_003824E0(0.004999999888241291f, 0.014999999664723873f));
        spot.x += func_003824E0(-0.07500000298023224f, 0.07500000298023224f);
        spot.y += func_003824E0(-0.07500000298023224f, 0.07500000298023224f);
        spot.z += func_003824E0(-0.07500000298023224f, 0.07500000298023224f);
        if (func_0013D3E0() % 12 == 0)
            func_L01_00466F50_0038B280(&spot, &up, 0x4005A182, -1.0f, 0.0f);
    }
    func_L01_0040E050_0038B280(&vars->timer);
    func_L01_00404A10_0038B280(func_L01_0038B950_0038B280, inf);
}
/* localdecomp:end func_L01_0038B280 */

/* localdecomp:start func_L01_0038B950 */
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, float);
void func_L01_0038B950(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (*(s32 *)(p + 36) != 0) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_0038B950 */

/* localdecomp:start func_L01_0038B988 */
extern void func_L01_0036E578_0038B988();
 
void func_L01_0038B988(void) {
    func_L01_0036E578_0038B988();
}
/* localdecomp:end func_L01_0038B988 */
