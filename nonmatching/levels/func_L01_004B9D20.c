/* NTSC-U draft (Claude wave K): C of func_L01_004B6188, the NTSC-U twin of func_L01_004B9D20, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 41 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_004B6188", whose code is not the PAL one).
 * Worker's note: best 9 aligned words (TOTAL 9, 41 raw diff): control flow, regs and constants identical; only GCC reorg delay-slot fills differ: retail keeps `nop` in the slot of `beqz v0,L_2BC` (0x1D4) and in the slot of the 2nd `beqz a0`, and its jal func_45CF30 slot holds ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_004B6188 */
typedef struct {
    u8 pad0[0x34];
    u16 h34;
} Obj_004B6188;

typedef struct {
    u8 pad0[0xC];
    u8 b0C;
    u8 pad0D[0x3B];
    s32 w48[1];
} Slot_004B6188;

typedef struct {
    u8 pad0[0x24];
    Slot_004B6188 *p24;
    u8 pad28[0x40];
    s32 w68;
} Ent_004B6188;

typedef struct {
    u8 pad0[0x10];
    f32 f10;
    u8 pad14[4];
    f32 f18;
    u8 pad1C[0x28];
    s16 h44;
    s16 h46;
    u8 pad48[0x28];
    s32 w70;
    s32 w74;
    s32 w78;
    u8 pad7C[4];
    f32 f80;
    f32 f84;
    f32 f88;
    f32 f8C;
    u8 pad90[0x110];
    Ent_004B6188 *ents[16];
} G_004B6188;

typedef struct {
    u8 pad0[0x25C0];
    s32 w25C0;
    u8 pad25C4[0x21];
    u8 b25E5;
    u8 pad25E6[2];
    f32 f80;
    f32 f88;
} A_004B6188;

typedef struct {
    u8 pad0[0x76];
    s16 h76;
    u8 pad78[0x26];
    s16 h9E;
} K_004B6188;

extern f32 D_L01_001DF9D0;
__asm__(".extern D_L01_001DF9D0, 16");
extern s32 D_L01_001DF9D8;
extern s32 D_L01_001DF9DC;
extern s32 D_L01_001DF9E0;
__asm__(".extern D_L01_001DF9D8, 16");
extern K_004B6188 D_001CCFD0;
extern G_004B6188 D_L01_001E6E00;
extern A_004B6188 D_001A4BE0;
extern s32 D_L01_001D6720;
extern u8 D_L01_001DFA64;
extern u8 D_L01_001DFA65;
extern u8 D_L01_001DFA66;
extern f32 D_L01_001DFA68;
extern f32 D_L01_001DFA6C;
extern f32 D_L01_001DFA70;
extern f32 D_L01_001DFA74;
extern f32 D_L01_001E76B0[];
extern u8 *D_L01_001DFC98;
extern void *D_L01_001DFC9C;
extern void (*D_L01_001D6724)(void *);
extern void *D_L01_001D6728;
extern s32 D_L01_001EA8A0[];
extern s32 D_L01_001D6690;
extern u8 D_L01_001E6E10[];

extern void func_00385B60(s32);
extern void func_L01_0045CEB8(void);
extern void func_L01_0045CE70(f32);
extern void func_003A3B00(void);
extern void func_L01_004295C8(void);
extern void func_L01_003F32F0(s32, f32);
extern void func_003DFFD0(void);
extern void func_003821E8(s32);
extern void func_003830E8(void);
extern void func_003BD360(void *);
extern void func_L01_004B5C00(s32);
extern void func_L01_00500F10(s32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_L01_0050CAF8(void);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L01_0045CF30(void *, void *, s32);
extern void func_L01_0045BFF0(s32);
extern void func_L01_004A8EB8(void);

void func_L01_004B6188(void) {
    s32 i;
    f32 f;
    f32 g;

    if (D_L01_001DF9D0 < 0.5f) {
        func_00385B60(8);
    } else {
        func_00385B60(2);
    }
    if (D_001CCFD0.h76 != 6 && D_001CCFD0.h76 != 7) {
        D_001CCFD0.h76 = 5;
    }
    if (D_001CCFD0.h9E != 6 && D_001CCFD0.h9E != 7) {
        D_001CCFD0.h9E = 5;
    }
    i = 0;
    func_L01_0045CEB8();
    func_L01_0045CE70(1.0f);
    func_003A3B00();
    func_L01_004295C8();
    D_L01_001DF9DC = 0;
    D_L01_001DF9E0 = 0;
    D_L01_001DF9D8 = 0;
    D_L01_001D6720 = 0;
    func_L01_003F32F0(0, 15.0f);
    func_003DFFD0();
    D_L01_001DFA64 = D_L01_001E6E00.w70;
    D_L01_001DFA65 = D_L01_001E6E00.w74;
    D_L01_001DFA66 = D_L01_001E6E00.w78;
    D_L01_001DFA68 = D_L01_001E6E00.f80;
    D_L01_001DFA6C = D_L01_001E6E00.f84;
    D_L01_001DFA70 = D_L01_001E6E00.f88;
    D_L01_001DFA74 = D_L01_001E6E00.f8C;
    func_003821E8(0);
    D_L01_001E76B0[0] = 0.62f;
    func_003830E8();
    for (i = 0; i < D_L01_001E6E00.h44; i++) {
        Ent_004B6188 *e = D_L01_001E6E00.ents[i];
        if (e != 0) {
            e->p24->b0C -= 1;
            e->p24->w48[e->p24->b0C] = 0;
            e->w68 = 0;
            func_003BD360(e);
            D_L01_001E6E00.ents[i] = 0;
        }
    }
    func_L01_004B5C00(0);
    if (D_001A4BE0.w25C0 != 0) {
        func_L01_00500F10(1);
        f = func_003BE7F0(&D_001A4BE0.f80, 0, 0, 0.5f);
        if (f > 2.0f) {
            if (fabs_asm(D_001A4BE0.f88 - f) < 4.5f) {
                D_001A4BE0.f88 = f;
            }
        }
        D_001A4BE0.b25E5 = 0;
        func_L01_0050CAF8();
        if (D_L01_001E6E00.h46 != 0) {
            g = func_003BE7F0(&D_L01_001E6E00.f10, 0, 0, 0.5f);
            if (g > 2.0f) {
                if (fabs_asm(D_L01_001E6E00.f18 - g) < 2.0f) {
                    D_L01_001E6E00.f18 = g;
                }
            }
            func_L01_004F12C0(D_L01_001E6E10, D_L01_001E6E10 + 0x10, 0, 1);
        }
    }
    if (D_L01_001DFC98 != 0) {
        *(u16 *)(D_L01_001DFC98 + 0x34) &= 0xFFFE;
        if (D_L01_001DFC98 != 0) {
            func_L01_0045CF30(D_L01_001DFC98, D_L01_001DFC9C, 1);
            D_L01_001DFC98 = 0;
            D_L01_001DFC9C = 0;
        }
    }
    func_L01_0045BFF0(0x1E);
    if (D_L01_001D6724 != 0 && D_L01_001EA8A0[0] == 0 && D_L01_001D6690 != 2 && D_L01_001D6690 != 1) {
        D_L01_001D6724(D_L01_001D6728);
        D_L01_001D6724 = 0;
        D_L01_001D6728 = 0;
    }
    func_L01_004A8EB8();
}
/* localdecomp:end func_L01_004B6188 */
