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
extern s128_003ED620 D_L01_001E2A40[];
extern E_003ED620 D_001A30B0[];
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

extern s32 fe_func_00382380(void *, s32, s32);
extern f32 fe_func_0038CF38(void *, void *);
extern void fe_func_0038CC88(u8 *, void *, s32);
extern void fe_func_0038CC88(u8 *, void *, s32);
/* localdecomp:start func_L01_003EC940 */
extern u8 *D_L01_001DFBEC;
extern f32 func_003887C8(void *, void *);
extern s32 func_00388398(void *);
extern s32 func_0037E1D8(s32);
extern s32 func_L01_004A74A0(s32, s32, void *, s32);
extern void func_0039FB08(s32);

/* Ambient sound emitter update: when the hero is within the emitter's radius and the timer ticks,
 * starts a sound and schedules the next one; beyond radius plus 1, stops it with sound_stop. */
void func_L01_003EC940(char *self) {
    int *sub = *(int **)(self + 8);
    unsigned int flags;
    float distance;
    if (sub[5] == 0) return;
    if (sub[0] < 0) return;
    distance = func_003887C8(D_L01_001E2A40, self + 0x40);
    if (distance < *(float *)(self + 0xc)) {
        char *slot;
        flags = 0;
        if (*(u8 *)(D_L01_001DFBEC + sub[0] * 32 + 0x18)) flags |= 4;
        slot = (char *)D_001A30B0 + sub[4] * 0x80;
        if (*(char **)(slot + 0x100) == self && *(u8 *)(slot + 0xD0)) return;
        if (func_00388398(sub + 3)) {
            sub[4] = func_L01_004A74A0(sub[0], flags, self, 0x400);
            if (sub[2] > 0) sub[3] = (int)((sub[1] + func_0037E1D8(sub[2] - sub[1])) * 60.0f);
        }
    } else if (*(float *)(self + 0xc) + 1.0f < distance) {
        char *slot;
        int index = sub[4];
        if (index != -1) {
            slot = (char *)D_001A30B0 + index * 0x80;
            if (*(char **)(slot + 0x100) == self && *(u8 *)(slot + 0xD0)) func_0039FB08(index);
        }
        sub[4] = -1;
    }
}
/* localdecomp:end func_L01_003EC940 */
