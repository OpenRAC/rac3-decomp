#include "common.h"

typedef struct { u8 pad[28]; u8 *p; } E_3EAB98;
typedef struct {
    u8 pad0[56];
    u8 f38;
    u8 f39;
    u8 pad3A[8];
    s8 f42;
    s8 f43;
} Info_003EBD50;
typedef struct {
    u8 pad0[28];
    Info_003EBD50 *info;
} Ent_003EBD50;
typedef struct {
    u8 pad0[124];
    u8 f7C;
    u8 pad7D;
    s16 f7E;
    u8 pad80[4];
    s16 f84;
    s16 f86;
} Obj_003EBD50;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[512];
    u8 b200[48];
    u128_t v230;
    u8 pad240[675 - 576];
    u8 b2A3;
    u8 pad2A4[696 - 676];
    f32 f2B8;
    u8 pad2BC[712 - 700];
    f32 f2C8;
    u8 pad2CC[1120 - 716];
} Ent003EC730;
typedef int u128_3EC828 __attribute__((mode(TI)));
typedef struct { u8 p0[0x200]; u8 b200[0x30]; u128_3EC828 q230; u8 pad[0x460 - 0x240]; } E_3EC828;
typedef struct { u8 p0[0x30]; u128_3EC828 q30; u8 p40[0x54]; s32 w94; } M_3EC828;
typedef int s128_003ED620 __attribute__((mode(TI)));
typedef struct {
    u8 pad[128];
} E_003ED620;
typedef struct {
    s32 f0;
    s32 f4;
} H_003ED620;
typedef struct {
    u8 pad[8];
    H_003ED620 *h;
} Obj_003ED620;
typedef struct { s32 x0; u8 pad4[0xC64 - 4]; s32 xC64; } G_3EF740;

typedef struct {
    u8 pad0[0x7D];
    u8 f7D;
    s16 f7E;
    u8 pad80[0x86 - 0x80];
    s16 f86;
    u8 pad88[0x94 - 0x88];
    s32 w94;
} Obj_003EC990;
typedef struct {
    u8 pad0[0xFC];
    s32 xFC;
    s32 x100;
} Sub_003EC990;

typedef struct {
    u8 b0, b1, b2, b3;
    s16 s4, s6, s8, s10, s12;
    u8 e, f;
} Rec_003F2058;
typedef struct {
    u8 pad[0x54C];
    u8 b54C;
    u8 pad54D[0x557 - 0x54D];
    u8 b557;
} Ctx_003F2058;
typedef struct {
    Rec_003F2058 r[8];
} Tab_003F2058;

extern Ent003EC730 D_L01_001E2AC0[];
extern char * D_L01_001DF884 __attribute__((section(".sdata")));
extern char *D_L01_001DF884 __attribute__((section(".sdata")));
extern char *D_L01_001DF884;
extern char *D_L01_001DF884;
extern s32 fe_func_00382380(void *, s32, s32);
extern s32 func_L01_00448D50(void *, s32);
extern s32 func_L01_00448E00(void *, s32);
extern char *D_L01_001DF884;
/* localdecomp:start func_L01_003EBE48 */
extern Ent003EC730 D_L01_001E2AC0[];
extern char *D_L01_001E0180;
extern f32 func_00388800(void *, void *);

/* camera_fixed_inside: returns 1 when the owner's position lies inside the camera trigger's cuboid,
 * cylinder or sphere volume (point_in_cuboid, point_in_cylinder, point_in_sphere) and its movement
 * and rotation are nearly still, else 0. */
s32 func_L01_003EBE48(u8 *a) {
    u8 *owner = (u8 *)&D_L01_001E2AC0[*(s32 *)(a + 0x94)];
    u8 *st = owner + 0x150;
    u8 *own = *(u8 **)(owner + 0x50);
    u8 *sub = *(u8 **)(own + 0x70);
    u8 *move = sub + 0x180;
    u8 *rot = sub + 0x1E0;
    u8 *p;
    u32 mode;
    s32 r;

    p = *(u8 **)(D_L01_001DF884 + *(s16 *)(a + 0x84) * 32 + 28);
    if (*(s16 *)(own + 0x86) != 0) {
        goto out;
    }
    mode = st[0x12B] == 1 || st[0x12B] == 2;
    if (*(s16 *)(p + 0x4A) && !mode) goto out;
    if (*(s16 *)(p + 0x48) && mode) goto out;
    if (*(s32 *)(p + 0x34)) {
        if (__builtin_fabsf(*(f32 *)(move + 0x34)) > 0.01f) goto out;
        if (__builtin_fabsf(*(f32 *)(rot + 8)) > 0.01f) goto out;
    }
    if ((u32)(*(s32 *)(st + 0x100) - 0x66) >= 2 && *(f32 *)(st + 0x110) > 0.0166666675f) {
    out:
        return 0;
    }
    {
        if (*(s32 *)(p + 0xC) >= 0) {
            if (*(s32 *)(st + 0x100) == 0x66 && func_00388800(st + 0x40,D_L01_001E0180 + *(s32 *)(p + 0xC) * 128 + 0x30) < 3.0f) return 1;
            if (func_0037E0F0(st + 0x40,*(s32 *)(p + 0xC), 0)) return 1;
        }
        if (*(s32 *)(p + 0x10) >= 0) {
            if (*(s32 *)(st + 0x100) == 0x66 && func_00388800(st + 0x40,D_L01_001E0180 + *(s32 *)(p + 0x10) * 128 + 0x30) < 3.0f) return 1;
            if (func_L01_00448D50(st + 0x40,*(s32 *)(p + 0x10))) return 1;
        }
        if (*(s32 *)(p + 8) >= 0) {
            if (*(s32 *)(st + 0x100) == 0x66 && func_00388800(st + 0x40,D_L01_001E0180 + *(s32 *)(p + 8) * 128 + 0x30) < 3.0f) return 1;
            if (func_L01_00448E00(st + 0x40,*(s32 *)(p + 8))) return 1;
        }
        r = 0;
        *(s16 *)(p + 0x26) = 1;
        return r;
    }
}
/* localdecomp:end func_L01_003EBE48 */
