#include "common.h"

typedef struct {
    char pad0[0x10];
    u8 count;
} Anim;
typedef struct {
    char pad0[0x48];
    Anim *anims[1];
} Class;
typedef struct {
    char pad0[0x24];
    Class *cls;
    char pad28[0x40 - 0x28];
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 unk43;
    s32 unk44;
    char pad48[0x58 - 0x48];
    s32 unk58;
    s32 unk5C;
} Moby;
typedef struct {
    char data[0x600];
} Buf;
typedef struct {
    u8 pad0[0xC20];
    s32 xC20;
    s32 xC24;
    s32 xC28;
} D_001A4BE0_t;
typedef struct {
    u8 pad0[0x20];
    u8 b32;
    u8 pad21[0x34 - 0x21];
    u16 h52;
    u8 pad36[0xAA - 0x36];
    s16 h170;
} M_50C8E8;
typedef struct {
    M_50C8E8 *p[3];
    u8 padC[0x28 - 0xC];
    s32 w40;
    u8 pad2C[0x50 - 0x2C];
} E_50C8E8;
typedef struct {
    u8 pad0[0xBF8];
    M_50C8E8 *p3064;
    u8 padBFC[0x1200 - 0xBFC];
    E_50C8E8 e[1];
    u8 pad1250[0x12FC - 0x1250];
    M_50C8E8 *p4860;
    u8 pad1300[0x1A24 - 0x1300];
    M_50C8E8 *p6692;
    u8 pad1A28[0x25E4 - 0x1A28];
    u8 b9700;
} G_50C8E8;
typedef struct {
    u8 pad0[0x44];
    s16 h68;
    u8 pad46[0x1A0 - 0x46];
    M_50C8E8 *arr[1];
} H_50C8E8;
typedef struct {
    u8 pad0[0x20];
    s16 h32;
} K_50C8E8;
typedef struct {
    f32 m[16];
} M_0050D430;
typedef struct {
    f32 v[4];
} V_0050D430;
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_50D4D8;
typedef struct {
    u8 pad0[64];
    Vec4_50D4D8 m;
    u8 pad50[9636];
    u8 b25F4;
} G_50D4D8;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    u8 m0[64];
    u8 m40[9716 - 64];
    u8 mode;
} S_50D530;
typedef struct {
    f32 m0[4][4];
    f32 m1[4][4];
    u8 pad[0x25F4 - 0x80];
    u8 mode;
} Cam50D5B0;
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_00511618;
typedef struct {
    u8 m0[64];
    u8 m40[9716 - 64];
    u8 mode;
} S_50D870;
typedef struct {
    u8 pad[138];
    u16 h8A;
    u8 pad2[240 - 140];
} S_50D8F8;
typedef struct {
    u8 pad0[0x8A];
    u16 h8A;
    u8 pad8C[0xF0 - 0x8C];
} S_50DA08;
typedef struct {
    u8 arr[0x40];
} S_50DA08a;
typedef struct {
    s32 arr[0x40];
} S_50DA08b;
typedef struct {
    u8 pad0[52];
    s32 x34;
} G_0050F828;

typedef struct {
    u8 pad0[0x78];
    s32 color78;
} Node_005124D8;
typedef struct {
    u8 pad0[0x1340];
    Node_005124D8 *p1340;
    Node_005124D8 *p1344;
    Node_005124D8 *p1348;
    u8 pad134C[0x1390 - 0x134C];
    Node_005124D8 *p1390;
    u8 pad1394[0x2890 - 0x1394];
    f32 f2890;
    f32 f2894;
    f32 f2898;
    f32 f289C;
} Glob_005124D8;

typedef struct Manip_00512A30 {
    u8 pad0;
    u8 initialized;
    u8 pad2[0x1E];
    f32 scale[3];
    u8 pad2C[0x14];
} Manip_00512A30;

/* declared by functions of L01_0050F9E8.c, which this file was cut from */
extern D_001A4BE0_t D_001A4BE0;
extern s32 D_L01_001D6694;
extern s32 func_L01_00513EF0(void);
extern s32 D_L01_001D673C;
extern int D_001A71A4[];

/* localdecomp:start func_L01_00513FD8 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x80];
    f32 origin[4];
    u8 pad90[0x80];
    f32 velocity[4];
    u8 pad120[0x1D0];
    f32 point[4];
    u8 pad300[0x3C];
    f32 distance;
    u8 pad340[0x14];
    f32 height;
    u8 pad358[0x1148];
    f32 direction[4];
    u8 pad14B0[0x60];
    Vec4 transformed;
    Vec4 position;
    u8 pad1530[0x10];
    Vec4_50D4D8 rotation;
    u8 pad1550[0x50];
    f32 angle;
    u8 pad15A4[0x5C];
    f32 offset;
    u8 pad1604[0xAC];
    s32 mode;
    u8 pad16B4[0x18];
    f32 scale;
    u8 pad16D0[0xC];
    s32 blocked;
    u8 pad16E0[0xEE4];
    s32 state;
    u8 pad25C8[0x4];
    s32 state_type;
    u8 pad25D0[0x14];
    u8 character;
} Hero_00513FD8;
extern f32 D_L01_001DBD58;
extern f32 D_L01_001DBD5C;
__asm__(".extern D_L01_001DBD58, 4");
__asm__(".extern D_L01_001DBD5C, 4");
void func_L01_00513FD8(void) {
    extern void func_L01_00511508(Vec4 *, Vec4 *, f32);
    extern f32 func_L01_005114B0(f32 *);
    extern f32 func_0038CF00(void *, void *);
    extern void func_003C41A0(f32 *, f32 *, f32, f32, f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    f32 scale;
    Vec4 out;
    if (((Hero_00513FD8 *)&D_001A4BE0)->scale == 0.0f) {
        if (((Hero_00513FD8 *)&D_001A4BE0)->character == 1) ((Hero_00513FD8 *)&D_001A4BE0)->scale = 1.1f;
        else if (((Hero_00513FD8 *)&D_001A4BE0)->character == 2) ((Hero_00513FD8 *)&D_001A4BE0)->scale = D_L01_001DBD58;
        else ((Hero_00513FD8 *)&D_001A4BE0)->scale = 1.75f;
    }
    switch (((Hero_00513FD8 *)&D_001A4BE0)->character) {
    case 1:
        scale = 1.1f;
        if (((Hero_00513FD8 *)&D_001A4BE0)->scale > scale) ((Hero_00513FD8 *)&D_001A4BE0)->scale = scale;
        if (((Hero_00513FD8 *)&D_001A4BE0)->offset != 0.0f) ((Hero_00513FD8 *)&D_001A4BE0)->offset = -3.0f;
        break;
    case 2:
        scale = D_L01_001DBD58;
        if (((Hero_00513FD8 *)&D_001A4BE0)->scale > scale) ((Hero_00513FD8 *)&D_001A4BE0)->scale = scale;
        if (((Hero_00513FD8 *)&D_001A4BE0)->offset != 0.0f) ((Hero_00513FD8 *)&D_001A4BE0)->offset = D_L01_001DBD5C;
        break;
    default:
        if (((Hero_00513FD8 *)&D_001A4BE0)->mode == 2) {
            scale = 1.75f;
            if (((Hero_00513FD8 *)&D_001A4BE0)->state == 4) scale = 1.0f;
        } else scale = 2.0f;
        if (((Hero_00513FD8 *)&D_001A4BE0)->offset != 0.0f) ((Hero_00513FD8 *)&D_001A4BE0)->offset = -6.0f;
    }
    {
    Vec4 *transformed = (Vec4 *)((u8 *)&D_001A4BE0 + 0x1510);
    Hero_00513FD8 *h = (Hero_00513FD8 *)((u8 *)transformed - 0x1510);
    Vec4 *velocity = (Vec4 *)((u8 *)transformed - 0x1400);
    *transformed = *velocity;
    if (h->mode == 1) {
        if (h->state_type == 4 && h->state != 0x86) {
            if (h->distance < 3.0f && !h->blocked) {
                f32 d;
                func_L01_00511508(transformed, velocity, 0.0f);
                h->scale -= func_L01_005114B0(velocity->f);
                d = func_0038CF00(h->point, h->origin);
                if (d > 1.0f) d = h->distance;
                scale = 2.0f - d;
            } else ((Hero_00513FD8 *)&D_001A4BE0)->blocked = 1;
        } else ((Hero_00513FD8 *)&D_001A4BE0)->blocked = 0;
    }
    }
    {
    f32 *current = (f32 *)((u8 *)&D_001A4BE0 + 0x16CC);
    Hero_00513FD8 *h = (Hero_00513FD8 *)((u8 *)current - 0x16CC);
    func_003C41A0(current, current + 1, scale, 0.006400000303983688f, 0.006400000303983688f, 0.64000004529953f);
    func_0038CF68((u8 *)current - 0x1AC, (u8 *)current - 0x22C, h->scale);
    {
        vu0_q result;
        vu0_q origin;
        __asm__("lqc2 %0, %2\n\tlqc2 %1, %3\n\tvadd.xyz %0, %0, %1"
            : "=j"(result), "=j"(origin)
            : "m"(*(Vec4 *)((u8 *)current - 0x1AC)), "m"(*(Vec4 *)h->origin));
        __asm__("sqc2 %1, %0" : "=m"(*(Vec4 *)((u8 *)current - 0x1AC)) : "j"(result));
    }
    if (h->state_type == 25 || h->state == 107) {
        if (h->position.f[2] < h->height + 0.75f) h->position.f[2] = h->height + 0.75f;
    }
    }
    {
    Hero_00513FD8 *h = (Hero_00513FD8 *)&D_001A4BE0;
    if (h->angle > 0.0f) {
        Vec4 zero = { 0 };
        zero.f[0] = func_0038D098(h->angle);
        zero.f[2] = func_0038D0B0(h->angle);
        out = zero;
        func_0038CE20(out.f, out.f, h->angle / 1.5707963705062866f * 0.44999998807907104f);
        func_0038D000((Vec4_50D4D8 *)&out, out.f, &h->rotation);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(h->position) : "m"(h->position), "m"(out) : "vf1", "vf2");
    }
    }
}
/* localdecomp:end func_L01_00513FD8 */
