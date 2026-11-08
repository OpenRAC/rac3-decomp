#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_004EF3A8);

INCLUDE_ASM("asm/levels", func_L01_004EF6F0);

INCLUDE_ASM("asm/levels", func_L01_004EF840);

INCLUDE_ASM("asm/levels", func_L01_004F02D8);

INCLUDE_ASM("asm/levels", func_L01_004F0558);

INCLUDE_ASM("asm/levels", func_L01_004F05F0);

INCLUDE_ASM("asm/levels", func_L01_004F0640);

/* localdecomp:start func_L01_004F0AB0 */
typedef int s128_004ECCD8 __attribute__((mode(TI)));

typedef struct {
    u8 pad[128];
    s128_004ECCD8 out;
    u8 pad2[9972 - 144];
    s32 idx;
    s32 count;
} St_004ECCD8;

extern St_004ECCD8 D_001A4BE0;
extern s128_004ECCD8 D_001A6C20[];
extern s32 func_L01_004F0640(s32);

void func_L01_004F0AB0(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        if (func_L01_004F0640(i) == 1) {
            return;
        }
        if (D_001A4BE0.count > 1) {
            D_001A4BE0.count--;
            D_001A4BE0.idx = (D_001A4BE0.idx + 31) % 32;
        }
        D_001A4BE0.out = D_001A6C20[D_001A4BE0.idx];
    }
}
/* localdecomp:end func_L01_004F0AB0 */

INCLUDE_ASM("asm/levels", func_L01_004F0B78);

/* localdecomp:start func_L01_004F1190 */
typedef struct {
    f32 v[4];
} Vec4ED3B8;

typedef struct {
    u8 pad0[0x1B4];
    f32 f1B4;
} Cam4ED3B8;

extern Vec4ED3B8 D_001A4CF0[];
extern void func_0038CE20(Vec4ED3B8 *, Vec4ED3B8 *, f32);

void func_L01_004F1190(f32 s) {
    Vec4ED3B8 *p = D_001A4CF0;
    func_0038CE20(p, p, s);
    func_0038CE20(p + 1, p + 1, s);
    func_0038CE20(p + 2, p + 2, s);
    func_0038CE20(p - 2, p - 2, s);
    func_0038CE20(p + 5, p + 5, s);
    {
        Cam4ED3B8 *c = (Cam4ED3B8 *)(p - 17);
        c->f1B4 *= s;
    }
}
/* localdecomp:end func_L01_004F1190 */

INCLUDE_ASM("asm/levels", func_L01_004F1220);

INCLUDE_ASM("asm/levels", func_L01_004F1638);

INCLUDE_ASM("asm/levels", func_L01_004F1C88);

INCLUDE_ASM("asm/levels", func_L01_004F2880);

/* localdecomp:start func_L01_004F2A08 */
typedef int s128_4F2A08 __attribute__((mode(TI)));
typedef union {
    s128_4F2A08 q;
    struct {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    } v;
} V_4F2A08;
typedef struct {
    u8 pad0[0x60];
    f32 target_x;
    f32 target_y;
    f32 target_z;
    u8 pad6C[0xA4 - 0x6C];
    f32 gain;
    f32 damping;
    f32 one;
} Spring_4F2A08;
/* the hero's joint springs (43, from D_L01_002F4540) */
typedef struct {
    Spring_4F2A08 root;
    Spring_4F2A08 waist;
    Spring_4F2A08 chest;
    Spring_4F2A08 neck;
    Spring_4F2A08 legs[4];
    Spring_4F2A08 other_clavicle;
    Spring_4F2A08 gun_clavicle;
    Spring_4F2A08 elbow;
    Spring_4F2A08 spring11;
    Spring_4F2A08 eyes;
    Spring_4F2A08 tail[4];
} Springs_4F2A08;
typedef struct {
    u8 pad0[0x40];
    u8 matrix[0x40]; /* 0x40: his rotation */
    V_4F2A08 pos; /* 0x80 */
    u8 pad90[0x35C - 0x90];
    s32 ground_moby;
    u8 pad360[0x368 - 0x360];
    s16 on_slope;
    u8 pad36A[0x25C4 - 0x36A];
    s32 state;
    u8 pad25C8[0x25EB - 0x25C8];
    u8 firing_held;
    u8 hold_type; /* 0 none, 1 one hand, 2 both */
    u8 pad25ED[0x25F4 - 0x25ED];
    u8 b25F4; /* 1: the clavicles drop near (330, 245, 138) */
    u8 pad25F5[0x2874 - 0x25F5];
    s16 gun_arm_raised;
} H_4F2A08;
extern s32 D_001D545C; /* the level */
extern Springs_4F2A08 D_L01_002F4540;
extern void func_0038D028(f32 *out, void *a, void *b);
extern f32 func_0038CF00(void *a, void *b);
extern void func_L01_004E63A8(f32 gain, f32 damping);

/* hero_slope_lean: on a slope, not firing a held gun, the waist leans with the ground's tilt
   (up to 21 deg; 7 deg with a gun), the neck half of it back, the clavicles against it with a
   gun not raised; the tail too. */
void func_L01_004F2A08(void) {
    V_4F2A08 v; /* the ground's down in his frame, then a spot */
    f32 limit;
    f32 lean;
    f32 tilt;
    f32 tail;
    s32 near;

    if (D_001D545C == 21) {
        return;
    }
    if ((*(H_4F2A08 *)&D_001A4BE0).on_slope != 0 && (*(H_4F2A08 *)&D_001A4BE0).firing_held == 0) {
        v.q = 0;
        v.v.z = -1.0f;
        func_0038D028(&v.v.x, &v, (*(H_4F2A08 *)&D_001A4BE0).matrix);
        func_L01_004E63A8(0.018720001f, 0.432000041f);
        limit = 0.366519153f; /* 21 deg */
        if ((*(H_4F2A08 *)&D_001A4BE0).state == 0x72) {
            limit = 0.0872664601f; /* 5 deg */
        } else if ((*(H_4F2A08 *)&D_001A4BE0).state == 0x73 || (*(H_4F2A08 *)&D_001A4BE0).state == 4) {
            limit = 0.191986218f; /* 11 deg */
        }
        if ((*(H_4F2A08 *)&D_001A4BE0).hold_type != 0 && limit > 0.122173049f) {
            limit = 0.122173049f; /* 7 deg with a gun */
        }
        if ((*(H_4F2A08 *)&D_001A4BE0).ground_moby != 0 && limit > 0.157079637f) {
            limit = 0.157079637f; /* 9 deg on a moby */
        }
        if ((*(H_4F2A08 *)&D_001A4BE0).gun_arm_raised == 0) {
            lean = v.v.x * 0.698131680f; /* 40 deg */
            if (lean > limit) {
                lean = limit;
            } else if (lean < -limit) {
                lean = -limit;
            }
            D_L01_002F4540.waist.target_y = lean;
            D_L01_002F4540.neck.target_y = -lean * 0.5f;
            if ((*(H_4F2A08 *)&D_001A4BE0).hold_type != 0) {
                D_L01_002F4540.other_clavicle.target_y = -lean;
                D_L01_002F4540.gun_clavicle.target_y = -lean;
            }
        }
        tilt = -v.v.y * 0.698131680f;
        if (tilt > limit) {
            tilt = limit;
        } else if (tilt < -limit) {
            tilt = -limit;
        }
        D_L01_002F4540.waist.target_x = tilt;
        D_L01_002F4540.neck.target_x = -tilt * 0.25f;
        tail = -v.v.x * 1.22173047f; /* 70 deg */
        if (tail > 0.994837642f) {
            tail = 0.994837642f; /* 57 deg */
        }
        if (tail < -0.122173049f) {
            tail = -0.122173049f;
        }
        if (v.v.z > 0.850000024f) {
            if (tail < 1.39626336f) {
                tail = 1.39626336f; /* 80 deg */
            }
        } else if (v.v.z > 0.5f) {
            if (tail < 1.22173047f) {
                tail = 1.22173047f;
            }
        }
        tilt = v.v.y * 1.22173047f;
        D_L01_002F4540.tail[0].target_y = tail * 0.569999993f;
        D_L01_002F4540.tail[1].target_y = tail * 0.5f;
        D_L01_002F4540.tail[2].target_y = tail * 0.5f;
        D_L01_002F4540.tail[3].target_y = tail * 0.349999994f;
        if (tilt > 1.22173047f) {
            tilt = 1.22173047f;
        } else if (tilt < -1.22173047f) {
            tilt = -1.22173047f;
        }
        D_L01_002F4540.tail[3].target_x = tilt;
        D_L01_002F4540.tail[0].target_x = tilt * 0.699999988f;
        D_L01_002F4540.tail[1].target_x = tilt * 0.699999988f;
        D_L01_002F4540.tail[2].target_x = tilt * 0.699999988f;
    }
    if ((*(H_4F2A08 *)&D_001A4BE0).b25F4 == 1) {
        v.q = 0;
        v.v.x = 330.0f;
        v.v.y = 245.0f;
        v.v.z = 138.0f;
        near = 0;
        if (func_0038CF00(&(*(H_4F2A08 *)&D_001A4BE0).pos, &v) < 35.0f) {
            near = 1;
        }
        if ((*(H_4F2A08 *)&D_001A4BE0).hold_type != 0 && near) {
            D_L01_002F4540.gun_clavicle.gain = 0.0720000044f;
            D_L01_002F4540.gun_clavicle.damping = 0.432000041f;
            D_L01_002F4540.gun_clavicle.target_y = -0.226892799f;
            D_L01_002F4540.other_clavicle.gain = 0.0720000044f;
            D_L01_002F4540.other_clavicle.damping = 0.432000041f;
            D_L01_002F4540.other_clavicle.target_y = -0.226892799f;
        }
    }
}
/* localdecomp:end func_L01_004F2A08 */

INCLUDE_ASM("asm/levels", func_L01_004F2E68);

INCLUDE_ASM("asm/levels", func_L01_004F3BE0);

INCLUDE_ASM("asm/levels", func_L01_004F3F40);

INCLUDE_ASM("asm/levels", func_L01_004F40A8);

INCLUDE_ASM("asm/levels", func_L01_004F4148);

INCLUDE_ASM("asm/levels", func_L01_004F4410);

INCLUDE_ASM("asm/levels", func_L01_004F45F0);

INCLUDE_ASM("asm/levels", func_L01_004F4730);

INCLUDE_ASM("asm/levels", func_L01_004F47F0);

/* localdecomp:start func_L01_004F4E20 */
extern u8 D_001A4C20[];
extern void func_0038D028(f32 *out, void *a, void *b);
extern f32 func_0038D160(f32 a, f32 b);
extern void func_L01_004485E0(void *p, f32 a, f32 b);

void func_L01_004F4E20(void *a0, void *a1)
{
    f32 v[4];
    func_0038D028(v, a0, D_001A4C20);
    func_L01_004485E0(a1, func_0038D160(v[0], v[1]), 0.0f);
}
/* localdecomp:end func_L01_004F4E20 */

/* localdecomp:start func_L01_004F4E70 */
extern St_004ECCD8 D_001A4BE0;
typedef int u128_4F1068 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x10];
    u128_4F1068 v10;
} S_4F1068b;

typedef struct {
    u8 pad0[0x80];
    u128_4F1068 v80;
    u8 pad90[0xBF8 - 0x90];
    S_4F1068b *pBF8;
    u8 padBFC[0x25C0 - 0xBFC];
    S_4F1068b *p25C0;
    u8 pad25C4[0x25E4 - 0x25C4];
    u8 b25E4;
} S_4F1068;

extern s32 func_003A52A0(s32 a0, s32 a1, S_4F1068b *a2);

s32 func_L01_004F4E70(s32 a0, s32 a1) {
    S_4F1068 *s = ((S_4F1068 *)&D_001A4BE0);
    if (s->b25E4 == 3) {
        if (s->pBF8 != 0) {
            s->pBF8->v10 = s->v80;
            return func_003A52A0(a0, a1, s->pBF8);
        }
    } else {
        return func_003A52A0(a0, a1, s->p25C0);
    }
    return -1;
}
/* localdecomp:end func_L01_004F4E70 */

/* localdecomp:start func_L01_004F4ED0 */
extern s32 D_001A71A0[];
extern void func_L01_004AA760(s32, s32);
void func_L01_004F4ED0(s32 a) {
    func_L01_004AA760(a, D_001A71A0[0]);
}
/* localdecomp:end func_L01_004F4ED0 */

/* localdecomp:start func_L01_004F4EF8 */
extern void func_L01_004F4ED0(s32);
void func_L01_004F4EF8(void) {
    func_L01_004F4ED0(25);
}
/* localdecomp:end func_L01_004F4EF8 */

/* localdecomp:start func_L01_004F4F18 */
extern s32 func_003A52A0(s32 a0, s32 a1, S_4F1068b *a2);
extern St_004ECCD8 D_001A4BE0;
typedef struct {
    u8 pad0[202];
    s16 idx;
    u8 pad1[4];
    u8 active;
    u8 pad2[11];
    s32 id;
    u8 pad3[52];
} Slot;

typedef struct {
    u8 pad[10124];
    s32 slot[9];
    s32 id[9];
} SlotMap;

extern u8 D_001A30B0[];

void func_L01_004F4F18(s32 i, s32 id, s32 x) {
    s32 s;
    Slot *e;

    s = (*(SlotMap *)&D_001A4BE0).slot[i];
    if (s != -1) {
        e = (Slot *)(D_001A30B0 + s * 128);
        if (e->id == id && e->active != 0) {
            goto done;
        }
    }
    (*(SlotMap *)&D_001A4BE0).slot[i] = ((s32 (*)(s32, s32, s32))func_003A52A0)(x, 4, id);
done:
    (*(SlotMap *)&D_001A4BE0).id[i] = id;
}
/* localdecomp:end func_L01_004F4F18 */

/* localdecomp:start func_L01_004F4FC0 */
extern St_004ECCD8 D_001A4BE0;
typedef struct { s16 on; s16 a; s16 b; s16 c; } Slot_4F4FC0;
void func_L01_004F4FC0(s32 a, s32 b, s32 c) {
    u8 *h = (u8 *)&D_001A4BE0;
    Slot_4F4FC0 *s = (Slot_4F4FC0 *)(h + 0x274C);
    s32 i = 0;
    do {
        if (s->on == 0) {
            s->on = 1;
            s->c = c;
            s->b = b;
            s->a = a;
            return;
        }
        i++;
        s++;
    } while (i < 8);
}
/* localdecomp:end func_L01_004F4FC0 */

INCLUDE_ASM("asm/levels", func_L01_004F5010);

INCLUDE_ASM("asm/levels", func_L01_004F50C8);

INCLUDE_ASM("asm/levels", func_L01_004F52E0);

INCLUDE_ASM("asm/levels", func_L01_004F5540);

INCLUDE_ASM("asm/levels", func_L01_004F5730);

INCLUDE_ASM("asm/levels", func_L01_004F5810);

INCLUDE_ASM("asm/levels", func_L01_004F5AE8);

/* localdecomp:start func_L01_004F5DC8 */
extern St_004ECCD8 D_001A4BE0;
typedef int s128_4F1FC0 __attribute__((mode(TI)));
typedef int s64_4F1FC0 __attribute__((mode(DI)));

typedef struct {
    u8 pad0[128];
    s128_4F1FC0 q80;
    s128_4F1FC0 q90;
    u8 padA0[2908];
    u8 *unkBFC;
    u8 padC00[6592];
    u8 *unk25C0;
} S_001A4BE0;

extern u8 D_L01_001FDBD0[];
extern s32 D_L01_001FD180[];
extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(u8 *);
extern void func_L01_004ED3F8(s32, s32, u8 *);

void func_L01_004F5DC8(void) {
    s32 type = 5947;
    u8 *m;

    if (D_L01_001FDBD0[6734] != 255 && D_L01_001FD180[D_L01_001FDBD0[6734]] != 0) {
        type = 6734;
    }
    m = func_003C24B0(type, 128);
    ((S_001A4BE0 *)&D_001A4BE0)[0].unkBFC = m;
    if (m != 0) {
        *(s128_4F1FC0 *)(m + 16) = ((S_001A4BE0 *)&D_001A4BE0)[0].q80;
        *(s128_4F1FC0 *)(((S_001A4BE0 *)&D_001A4BE0)[0].unkBFC + 240) = ((S_001A4BE0 *)&D_001A4BE0)[0].q90;
        *(s16 *)(((S_001A4BE0 *)&D_001A4BE0)[0].unkBFC + 50) = 64;
        ((S_001A4BE0 *)&D_001A4BE0)[0].unkBFC[49] = 1;
        *(s32 *)(((S_001A4BE0 *)&D_001A4BE0)[0].unkBFC + 120) = 0;
        *(s64_4F1FC0 *)(((S_001A4BE0 *)&D_001A4BE0)[0].unkBFC + 56) = *(s64_4F1FC0 *)(((S_001A4BE0 *)&D_001A4BE0)[0].unk25C0 + 56);
        func_003C7C38(((S_001A4BE0 *)&D_001A4BE0)[0].unkBFC);
        func_L01_004ED3F8(3, 81, ((S_001A4BE0 *)&D_001A4BE0)[0].unkBFC);
    }
}
/* localdecomp:end func_L01_004F5DC8 */
