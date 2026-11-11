/* func_L40_0040A4D0: near miss, 16 diff at level 40. 1336 bytes, 14 levels (40-53),
   src/levels/shared/L40_0040A4D0.c (flags -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division @ps2as). Written from asm (2026-11-11). The Ranger legs' moby update
   (multiplayer.md, "Siege Rangers"): the dormant twin (team -1), the bootstrap at pVar+0x348 0
   (Base Defense: Bots off destroys it; network callbacks; team tint; torso), the create message
   from the console that owns the moby (0x348 1), the state-37 respawn after its timer and the
   state-39 one at once.

   What is left, the rest is retail's:
   - two constant pairs get each other's registers: m+0x20 = 0x26 / pVar+0x348 = 2 and
     pVar+0x348 = 1 / m+0x30 = 0xFF (retail $v1 for the first store's constant, ours $v0;
     8 words);
   - the state-37 respawn: retail loads the moby array base (for the moby's index) before the
     health stores and puts the s16 health store in the call's slot (8 words).
   Got here by: the moby array (0x24845C) and the settings pointer (0x241640) in .sdata (single
   load macros, as retail rebuilds them each time), the moby array's one $gp read (in a delay
   slot) through a sized alias D_L40_0024845C_b, tint = the team code first, each message's
   pointers block-local, the team tint table as a struct member array.
   Tried for the rest: the stores of each pair swapped (they move instead, 22), the constants as
   named locals (18), the index computed into a local before or between the stores (16-18).
   Context: the file's prelude and earlier blocks (D_001A5DF8[] and the message helpers are
   func_L40_0040ABB8's). */
#include "common.h"
#include "vu0.h"

extern s32 D_001A5DF8[];
/* localdecomp:start func_L40_0040A4D0 */
/* The moby array where this function reads it through $gp (the lui reads are the plain name;
   func_L40_0040D678's near miss says why there are two). */
__asm__(".extern D_L40_0024845C_b, 4");
extern u8 *D_L40_0024845C_b;
extern u8 *D_L40_0024845C[] __attribute__((section(".sdata")));
__asm__(".extern D_L40_00247244, 4");
extern s32 D_L40_00247244; /* the tint of a Ranger of no team */
extern u8 *D_L40_00241640[] __attribute__((section(".sdata"))); /* the game settings; +0x18D Base Defense: Bots */
typedef struct {
    u8 pad[0x88];
    s32 tint[8];
} Teams_40A4D0;
extern Teams_40A4D0 *D_L40_0035746C[];
extern s32 D_001A5DF8[];
extern void func_003C2880(u8 *m);
extern void func_L39_0061C1E0(u8 *m, s32 a1);
extern void func_L40_0053D8C8(s32 cls, void *update, void *think, void *create);
extern void func_L39_005F2FF8(u8 *m, s32 a1);
extern u8 *func_003C24B0(s32 cls, s32 a1);
extern void func_L01_00456160(u8 *torso, u8 *m);
extern f32 func_003C3D30(void *pos, s32 a1, s32 a2, f32 f);
extern void func_003C2F58(u8 *m, s32 a1, void *pos);
extern s32 func_L40_0053F7F0(s32 index);
extern u8 *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32 type, s32 uid, s32 time, s32 kind, u8 *msg);
extern s32 func_00197498(s32 n);
extern s32 func_003D4D00(void *pos, s32 a1, s32 a2, s32 a3, f32 r);
extern void func_L40_0040ABB8(u8 *m);
extern u8 *func_L40_0040AA08(s32 a0, s32 a1, u8 *msg);
extern s32 func_L40_0040BCF0(s32 a0, u8 *m);

/* The Ranger legs' moby update: bootstrap (network callbacks, team tint, torso), the create
   message from the console that owns it, and the respawn of a dead one (state 37 after its
   timer, state 39 at once). */
void func_L40_0040A4D0(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);

    if (*(s32 *)(v + 0x2B8) == -1 && *(u8 *)(m + 0x20) == 0) {
        if (*(s8 *)(D_L40_00241640[0] + 0x18D) == 0) {
            func_003C2880(m);
        } else {
        func_L39_0061C1E0(m, -1);
        func_L40_0053D8C8(0x109F, func_L40_0040BCF0, func_L40_0040ABB8, func_L40_0040AA08);
        *(u8 *)(m + 0x20) = 0x26;
        *(s32 *)(v + 0x348) = 2;
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L39_005F2FF8(m, 1);
        if (*(u8 **)(v + 0x270) != 0) {
            *(u16 *)(*(u8 **)(v + 0x270) + 0x34) |= 0x41;
            *(u16 *)(*(u8 **)(v + 0x270) + 0x34) &= 0xEFFF;
            *(s32 *)(*(u8 **)(v + 0x270) + 0x98) = 0;
            func_L39_005F2FF8(*(u8 **)(v + 0x270), 1);
        }
        }
        return;
    }
    if (*(s32 *)(v + 0x348) == 0) {
        if (*(s8 *)(D_L40_00241640[0] + 0x18D) == 0) {
            func_003C2880(m);
            return;
        }
        func_L39_0061C1E0(m, -1);
        func_L40_0053D8C8(0x109F, func_L40_0040BCF0, func_L40_0040ABB8, func_L40_0040AA08);
        *(s32 *)(v + 0x348) = 1;
        *(u8 *)(m + 0x30) = 0xFF;
        {
        s32 tint;

        tint = *(s32 *)(v + 0x2F0);
        if ((u32)tint >= 2) {
            tint = D_L40_00247244;
        } else {
            tint = D_L40_0035746C[0]->tint[*(s32 *)(v + 0x2B8)];
        }
        if (*(u8 **)(v + 0x270) == 0 || *(u8 *)(*(u8 **)(v + 0x270) + 0x20) == 0xFE || *(u8 *)(*(u8 **)(v + 0x270) + 0x20) == 0xFD) {
            *(u8 **)(v + 0x270) = func_003C24B0(0x109E, 0);
            if (*(u8 **)(v + 0x270) != 0) {
                func_L01_00456160(*(u8 **)(v + 0x270), m);
            }
        }
        *(f32 *)(m + 0x18) = func_003C3D30(m + 0x10, 0, 0, 0.5f);
        *(f32 *)(*(u8 **)(v + 0x270) + 0xF8) = *(f32 *)(m + 0xF8);
        func_003C2F58(m, 0, *(u8 **)(v + 0x270) + 0x10);
        *(s32 *)(m + 0x98) = 0;
        *(u8 *)(m + 0x7E) = ((*(u8 *)(m + 0x7E) | 0x80) & 0x8F) | (tint << 4);
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        }
        func_L39_005F2FF8(m, 1);
        if (*(u8 **)(v + 0x270) != 0) {
            *(u16 *)(*(u8 **)(v + 0x270) + 0x34) |= 0x41;
            *(u16 *)(*(u8 **)(v + 0x270) + 0x34) &= 0xEFFF;
            *(s32 *)(*(u8 **)(v + 0x270) + 0x98) = 0;
            func_L39_005F2FF8(*(u8 **)(v + 0x270), 1);
        }
    } else if (func_L40_0053F7F0((m - D_L40_0024845C_b) >> 8)) {
        if (*(s32 *)(v + 0x348) == 1) {
            {
            u8 *msg;
            u8 *p;

            msg = func_L39_0066C2B8();
            if (msg == 0) {
                return;
            }
            p = msg + func_L39_0066C280(0, func_00197498(2), D_001A5DF8[0] + 500, 0x109F, msg);
            *(s32 *)p = (m - D_L40_0024845C[0]) >> 8;
            p += 4;
            *(s32 *)p = *(s32 *)(v + 0x2B8);
            p += 4;
            *(s32 *)msg = p - msg;
            }
            *(s32 *)(v + 0x348) = 2;
            func_L40_0053D8C8(0x109F, func_L40_0040BCF0, func_L40_0040ABB8, func_L40_0040AA08);
        }
    } else if (*(s32 *)(v + 0x348) == 1) {
        *(s32 *)(v + 0x348) = 2;
        func_L40_0053D8C8(0x109F, func_L40_0040BCF0, func_L40_0040ABB8, func_L40_0040AA08);
    }
    if (*(u8 *)(m + 0x20) == 37) {
        *(s32 *)(v + 0x2CC) = 0;
        *(s32 *)(v + 0x34C) += 1;
        if ((*(s32 *)(v + 0x3D8) * 5 + 2) / 6 < *(s32 *)(v + 0x34C)) {
            s32 r = func_003D4D00(m + 0x10, 1, 0, 0, 2.0f);
            *(s32 *)(v + 0x3D8) += 500;
            if (r == 0) {
                *(u8 *)(m + 0x20) = 0;
                *(s32 *)(v + 0x360) = 0;
                *(f32 *)(v + 0x30) = *(f32 *)(v + 0x3D0);
                *(s16 *)(v + 0x34) = *(f32 *)(v + 0x3D0);
                if (func_L40_0053F7F0((m - D_L40_0024845C[0]) >> 8)) {
                    {
                    u8 *msg;
                    u8 *p;

                    msg = func_L39_0066C2B8();
                    if (msg == 0) {
                        return;
                    }
                    p = msg + func_L39_0066C280(0, func_00197498(2), D_001A5DF8[0] + 5000, 0x109F, msg);
                    *(s32 *)p = (m - D_L40_0024845C[0]) >> 8;
                    p += 4;
                    *(s32 *)p = *(s32 *)(v + 0x2B8);
                    p += 4;
                    *(s32 *)msg = p - msg;
                    }
                }
            }
        }
    }
    if (*(u8 *)(m + 0x20) == 39) {
        *(s32 *)(v + 0x2CC) = 0;
        *(s32 *)(v + 0x34C) += 1;
        *(u8 *)(m + 0x20) = 0;
        *(s32 *)(v + 0x360) = 0;
        *(f32 *)(v + 0x30) = *(f32 *)(v + 0x3D0);
        *(s16 *)(v + 0x34) = *(f32 *)(v + 0x3D0);
        {
        u8 *msg;
        u8 *p;

        msg = func_L39_0066C2B8();
        if (msg == 0) {
            return;
        }
        p = msg + func_L39_0066C280(0, func_00197498(2), D_001A5DF8[0] + 5000, 0x109F, msg);
        *(s32 *)p = (m - D_L40_0024845C[0]) >> 8;
        p += 4;
        *(s32 *)p = *(s32 *)(v + 0x2B8);
        p += 4;
        *(s32 *)msg = p - msg;
        }
    }
}
/* localdecomp:end func_L40_0040A4D0 */
