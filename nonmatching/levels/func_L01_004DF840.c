/* PAL near miss (haiku-w6): 107 words differ with the file's flags; the hero base register (retail keeps it in $s0, this draft in $s1), the 0x1480 pointer and the constant-load order in the prologue */
#include "common.h"

/* localdecomp:start func_L01_004DF840 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x24];
    s32 fire_sequence;
    u8 pad28[0xF0 - 0x28];
} GunRow_4DFDB0;
typedef struct { u8 pad[0x270]; f32 f270, f274, f278, f27C, gap280, f284; u8 gap288[0x28C4-0x288]; s32 f28C4; } Init_004DF840;
typedef struct { s32 value; u8 pad[28]; } Row_004DF840;
extern G_4DD4B0 D_001A4BE0;
extern s32 D_001D4C40 __attribute__((section(".data")));
extern s32 D_001D4C40_sda;
extern s32 D_001D4C48 __attribute__((section(".data")));
extern u8 D_001425C0[];
extern GunRow_4DFDB0 D_L01_002C5600[];
extern u8 D_00143950[];
extern Row_004DF840 D_00143A10[], D_00143A70[], D_00143AD0[];
extern u8 *D_L01_001F02E8[32], *D_L01_001F0368[32], *D_L01_001F03E8[32], *D_L01_001F0468[32];
extern u8 *D_L01_001E001C __attribute__((section(".data")));
extern u8 *D_L01_001E0024 __attribute__((section(".data")));
void func_L01_004DF840(void) {
    extern s32 func_L01_00418F70(s32);
    extern void func_L01_005078C0(s32);
    extern void func_L01_0050FED0(void);
    extern void func_L01_005003D0(s32, s32);
    extern void func_L01_004E1F00(s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00412E70(void *, void *, s32, f32, f32);
    extern void func_L01_00514508(u8, void *);
    extern void (**func_L01_0043B568(s32, s32, s32))(void);
    vu0_v4 pos;
    u8 *hero;
    Init_004DF840 *initial = (Init_004DF840 *)&D_001A4BE0;
    s32 weapon;
    s32 i;
    s32 k0, k1, k2, k3;
    u8 *p;
    u8 *src;
    void (**callback)(void);
    weapon = D_001D4C40;
    initial->f270 = initial->f278 = 0.8f;
    initial->f27C = 0.7f;
    initial->f284 = 0.45f;
    initial->f274 = 0.7f;
    if (weapon != 9 && (((u8 *)&D_L01_002C5600[D_001425C0[weapon]])[0] != 0 || func_L01_00418F70(weapon))) {
        func_L01_005078C0(D_001D4C40_sda);
    }
    hero = (u8 *)&D_001A4BE0;
    D_001D4C48 = 0;
    *(s32 *)(hero + 0x25C4) = 0;
    *(f32 *)(hero + 0xC04) = 1.0f;
    func_L01_0050FED0();
    func_L01_005003D0(0, 1);
    func_L01_004E1F00(0);
    *(s32 *)(hero + 0x27DC) = -1;
    *(s32 *)(hero + 0x27D4) = -1;
    *(s32 *)(hero + 0x27D8) = -1;
    *(f32 *)(hero + 0x16CC) = 1.75f;
    func_0038CF68(&pos, hero + 0x20, 1.75f);
    __asm__("lqc2 $vf1, %0\n\t"
            "lqc2 $vf2, %1\n\t"
            "vadd.xyz $vf1, $vf1, $vf2\n\t"
            "sqc2 $vf1, %0"
            : "+m"(pos) : "m"(*(vu0_v4 *)(hero + 0x80)) : "vf1", "vf2");
    func_L01_00412E70(hero + 0x1540, &pos, *(s32 *)(hero + 0x25C0), *(f32 *)(hero + 0x98), 0.0f);
    *(u8 **)(hero + 0x162C) = hero + 0x14B0;
    {
    u8 *q = hero + 0x1480;
    func_L01_00514508(D_00143950[0xA4], q);
    *(u8 **)(hero + 0x1628) = q;
    }
    if (D_00143950[0xA4] == 1) {
        *(f32 *)(hero + 0x1600) = -6.0f;
        *(f32 *)(hero + 0x1664) = 6.0f;
        *(f32 *)(hero + 0x1608) = 0.0f;
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
    initial->f28C4 = 0;
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
