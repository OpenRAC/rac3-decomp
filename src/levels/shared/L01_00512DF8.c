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

/* localdecomp:start func_L01_00512DF8 */
extern u8 D_001439F4[];
extern u8 D_001A71C4[];

long func_L01_00512DF8(long a0) {
    if (D_001439F4[0] != 0 && D_001A71C4[0] == 0) {
        switch (a0) {
        case 0x40:
            return 0x44;
        case 4:
            return 1;
        case 8:
            return 2;
        }
    }
    return a0;
}
/* localdecomp:end func_L01_00512DF8 */

INCLUDE_ASM("asm/levels", func_L01_00512E68);

INCLUDE_ASM("asm/levels", func_L01_005133E8);

/* localdecomp:start func_L01_00513800 */

extern s16 D_L01_002C4C62[];
extern G_0050F828 D_00142660;

extern s32 func_L01_0041A4F0(void);

void func_L01_00513800(s32 *out, s32 *total, s32 *acc) {
    s32 sum = 0;
    s32 i;

    for (i = 0; i < 191; i++) {
        if ((D_L01_002C4C62 - 1)[i * 2] < 0) {
            break;
        }
        sum += (D_L01_002C4C62 - 1)[i * 2];
        if ((D_00142660.x34 >> 5) < sum) {
            break;
        }
        *acc += D_L01_002C4C62[i * 2];
        *out = sum;
        if (func_L01_0041A4F0() == 0 && i >= 90) {
            break;
        }
    }
    *total = sum;
}
/* localdecomp:end func_L01_00513800 */

INCLUDE_ASM("asm/levels", func_L01_005138F8);

/* localdecomp:start func_L01_00513EF0 */
typedef struct {
    u8 pad0[0xA4];
    u8 camera_setting; /* 0 follow, 1 lock-strafe, 2 first person */
} Options_513EF0;
typedef struct {
    u8 pad0[0x86];
    s16 mode;
} Camera_513EF0;
typedef struct {
    u8 pad0[0x238];
    s32 no_look_timer;
    u8 pad23C[0x16B0 - 0x23C];
    s32 camera_mode;
    u8 pad16B4[0x25C4 - 0x16B4];
    s32 state;
    u8 pad25C8[0x25CC - 0x25C8];
    s32 state_type;
    u8 pad25D0[0x25E4 - 0x25D0];
    u8 character;
    u8 pad25E5[0x2850 - 0x25E5];
    s32 health;
    u8 pad2854[0x28C4 - 0x2854];
    s32 any_state;
} Hero_513EF0;
extern D_001A4BE0_t D_001A4BE0;
extern Options_513EF0 D_00143950;
extern s32 D_L01_001D6694;
extern Camera_513EF0 *D_L01_001E2A90[];

/* hero_camera_allowed: the camera setting if the hero camera may run now, else 0 */
s32 func_L01_00513EF0(void) {
    Hero_513EF0 *hero;
    s32 state;

    if (D_00143950.camera_setting == 0) {
        if (((Hero_513EF0 *)&D_001A4BE0)->camera_mode == 0) {
            return 0;
        }
    }
    if (((Hero_513EF0 *)&D_001A4BE0)->no_look_timer != 0) {
        return 0;
    }
    /* game modes 2 and 6 */
    if (D_L01_001D6694 == 2 || D_L01_001D6694 == 6) {
        return 0;
    }
    /* a scripted camera */
    if (D_L01_001E2A90[0] != 0 && D_L01_001E2A90[0]->mode == 5) {
        return 0;
    }
    hero = (Hero_513EF0 *)&D_001A4BE0;
    if (hero->character == 5 || hero->state_type == 0x14 || hero->health == 0) {
        return 0;
    }
    if (hero->any_state == 0) {
        state = hero->state;
        if (state == 0x74 || state == 0x31 || state == 0x1C || state == 0x91 || state == 0xB0 ||
            state == 0x76) {
            return 0;
        }
    }
    return D_00143950.camera_setting;
}
/* localdecomp:end func_L01_00513EF0 */
