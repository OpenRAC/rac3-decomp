/* PAL near miss (haiku-w6; round 14 C, 2026-11-24): hero_level_start. 3 words with its file's
   flags (L01_004DF428.c now has -mvu0-use-vf0-vf2): retail stores 0x1608 ($f20, 0.0) after
   0x1600/0x1664, gcc before; the rest is the vadd block's schedule. What closed 107 -> 3: the hero
   as a typed global alias (fields at their offsets, base rebuilt after each join);
   `(&D_001D4C40)[2] = 0` (a two-word macro store, so it stays out of the delay slot);
   func_L01_00514508 takes one argument; store orders; alias D_L01_002C5600_004DF840; vec_add_ab
   from vu0.h. The one-block asm form (no flag) was 10. */
#include "common.h"

/* localdecomp:start func_L01_004DF840 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x24];
    s32 fire_sequence;
    u8 pad28[0xF0 - 0x28];
} GunRow_4DF840;
typedef struct {
    u8 p0[0x20];
    u8 pos20[0x10];          /* 0x20 */
    u8 p30[0x80 - 0x30];
    u8 pos80[0x10];          /* 0x80 */
    u8 p90[0x98 - 0x90];
    f32 f98;                 /* 0x98 */
    u8 p9C[0x270 - 0x9C];
    f32 f270, f274, f278, f27C, f280, f284; /* 0x270 */
    u8 p288[0xC04 - 0x288];
    f32 fC04;                /* 0xC04 */
    u8 pC08[0x1480 - 0xC08];
    u8 f1480[0x30];          /* 0x1480 */
    u8 f14B0[0x1540 - 0x14B0]; /* 0x14B0 */
    u8 f1540[0x1600 - 0x1540]; /* 0x1540 */
    f32 f1600;               /* 0x1600 */
    u8 p1604[4];
    f32 f1608;               /* 0x1608 */
    u8 p160C[0x1628 - 0x160C];
    u8 *f1628;               /* 0x1628 */
    u8 *f162C;               /* 0x162C */
    u8 p1630[0x1664 - 0x1630];
    f32 f1664;               /* 0x1664 */
    u8 p1668[0x16CC - 0x1668];
    f32 f16CC;               /* 0x16CC */
    u8 p16D0[0x25C0 - 0x16D0];
    s32 f25C0;               /* 0x25C0 */
    s32 f25C4;               /* 0x25C4 */
    u8 p25C8[0x27D4 - 0x25C8];
    s32 f27D4, f27D8, f27DC; /* 0x27D4 */
    u8 p27E0[0x28C4 - 0x27E0];
    s32 f28C4;               /* 0x28C4 */
} H_4DF840;
typedef struct { s32 value; u8 pad[28]; } Row_004DF840;
extern H_4DF840 D_001A4BE0_004DF840;
extern s32 D_001D4C40;
extern s32 D_001D4C40_sda;
extern s32 D_001D4C48;
extern u8 D_001425C0[];
extern GunRow_4DF840 D_L01_002C5600_004DF840[];
extern u8 D_00143950[];
extern Row_004DF840 D_00143A10[], D_00143A70[], D_00143AD0[];
extern u8 *D_L01_001F02E8[32], *D_L01_001F0368[32], *D_L01_001F03E8[32], *D_L01_001F0468[32];
extern u8 *D_L01_001E001C;
extern u8 *D_L01_001E0024;
void func_L01_004DF840(void) {
    extern s32 func_L01_00418F70(s32);
    extern void func_L01_005078C0(s32);
    extern void func_L01_0050FED0(void);
    extern void func_L01_005003D0_004DF840(s32, s32);
    extern void func_L01_004E1F00(s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00412E70(void *, void *, f32, s32, f32);
    extern void func_L01_00514508(s32);
    extern void (**func_L01_0043B568(s32, s32, s32))(void);
    vu0_v4 pos;
    s32 weapon;
    s32 k0, k1, k2, k3;
    u8 *p;
    u8 *src;
    void (**callback)(void);
    weapon = D_001D4C40;
    D_001A4BE0_004DF840.f270 = 0.8f;
    D_001A4BE0_004DF840.f274 = 0.7f;
    D_001A4BE0_004DF840.f284 = 0.45f;
    D_001A4BE0_004DF840.f278 = 0.8f;
    D_001A4BE0_004DF840.f27C = 0.7f;
    (&D_001D4C40)[2] = 0;
    if (weapon != 9 && (((u8 *)&D_L01_002C5600_004DF840[D_001425C0[weapon]])[0] != 0 || func_L01_00418F70(weapon))) {
        func_L01_005078C0(D_001D4C40_sda);
    }
    D_001A4BE0_004DF840.f25C4 = 0;
    D_001A4BE0_004DF840.fC04 = 1.0f;
    func_L01_0050FED0();
    func_L01_005003D0_004DF840(0, 1);
    func_L01_004E1F00(0);
    D_001A4BE0_004DF840.f27D4 = -1;
    D_001A4BE0_004DF840.f27D8 = -1;
    D_001A4BE0_004DF840.f27DC = -1;
    D_001A4BE0_004DF840.f16CC = 1.75f;
    func_0038CF68(&pos, D_001A4BE0_004DF840.pos20, 1.75f);
    vec_add_ab(&pos, &pos, D_001A4BE0_004DF840.pos80);
    func_L01_00412E70(D_001A4BE0_004DF840.f1540, &pos, D_001A4BE0_004DF840.f98, D_001A4BE0_004DF840.f25C0, 0.0f);
    D_001A4BE0_004DF840.f1628 = D_001A4BE0_004DF840.f1480;
    D_001A4BE0_004DF840.f162C = D_001A4BE0_004DF840.f14B0;
    func_L01_00514508(D_00143950[0xA4]);
    if (D_00143950[0xA4] == 1) {
        D_001A4BE0_004DF840.f1600 = -6.0f;
        D_001A4BE0_004DF840.f1664 = 6.0f;
        D_001A4BE0_004DF840.f1608 = 0.0f;
    }
    {
    s32 n;
    src = D_00143950 + 0x74;
    for (n = 0; n < 3; n++) {
        D_00143A10[n].value = *(s32 *)(src - 0x60);
        D_00143A70[n].value = *(s32 *)(src - 0x30);
        D_00143AD0[n].value = *(s32 *)src;
        src += 0x10;
    }
    }
    D_001A4BE0_004DF840.f28C4 = 0;
    { s32 n; for (n = 31; n >= 0; n--) D_L01_001F02E8[n] = 0; }
    { s32 n; for (n = 31; n >= 0; n--) D_L01_001F0368[n] = 0; }
    { s32 n; for (n = 31; n >= 0; n--) D_L01_001F03E8[n] = 0; }
    { s32 n; for (n = 31; n >= 0; n--) D_L01_001F0468[n] = 0; }
    for (p = D_L01_001E001C; p < D_L01_001E0024; p += 0x100) {
        s32 id = *(s16 *)(p + 0xAA);
        if (id == 0x323) {
            for (k0 = 0; k0 < 32; k0++) {
                if (!D_L01_001F02E8[k0]) { D_L01_001F02E8[k0] = p; break; }
            }
        } else if (id == 0x2F6) {
            for (k1 = 0; k1 < 32; k1++) {
                if (!D_L01_001F0368[k1]) { D_L01_001F0368[k1] = p; break; }
            }
        } else if (id == 0x99D) {
            for (k2 = 0; k2 < 32; k2++) {
                if (!D_L01_001F03E8[k2]) { D_L01_001F03E8[k2] = p; break; }
            }
        } else if (p && *(u8 **)(p + 0x24) && (*(u8 **)(p + 0x24))[0x46] == 23) {
            for (k3 = 0; k3 < 32; k3++) {
                if (!D_L01_001F0468[k3]) { D_L01_001F0468[k3] = p; break; }
            }
        }
    }
    callback = func_L01_0043B568(0x1E6F, 0, 12);
    if (callback) (*callback)();
}
/* localdecomp:end func_L01_004DF840 */
