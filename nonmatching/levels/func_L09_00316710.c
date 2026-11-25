/* PAL level 09 draft (state machine of 3704 bytes; one source with a six-way jump table, which needs a real level-09 build if this lands).
 * tools/check.py --no-context --as ps2as --target level_09 with the file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division):
 * 636 raw differences; 181 aligned rows (difflib over the instruction columns; the 371/298-aligned drafts this extends measure 426
 * on the same count), 133 when the four saved registers that hold the hoisted high halves are not compared by name.
 * Fixed in round 27 (W23), from 426 aligned:
 * - D_L09_001F2EC0 as `extern s32 D_L09_001F2EC0[4]` (read as [0]): a 16-byte object is split into explicit high/lo_sum RTL, so gcse PRE
 *   hoists its `lui` into a saved register before the dispatch like the other three (retail pre-loads FOUR high halves; the scalar form
 *   was an assembler `lw sym` macro that PRE cannot see). 426 -> 395. D_L09_00236780 the same (`lui/lw` in retail): -7.
 * - One pointer temp per kind of use instead of five: case 1's `pt` and case 2's `q` and case 5's `P` and `q` are spelled with the
 *   variables below (q, q, q, P, q, pt, q in source order). The allocator then gives z $s1 and the vtable temp $s0 as in retail
 *   (it changes which pseudos exist and so how the global allocator orders them): 395 -> 290.
 * - The two `z->f10[i]` loops store through a typed struct (F18_316710, field f18): the store is MEM_IN_STRUCT_P, so loop.c can hoist
 *   the load of the global pointer D_L09_001E009C out of the loop as retail does (`lw $a1, 0x37ec($gp)` before it): 290 -> 270.
 * - The five bit-mask globals tested with `(x[0] & (1 << D_001D545C)) == 0` are `u32` arrays (retail uses sllv/and, an s32 array
 *   gives srav/andi 1), and their names were wrong: retail's `lui 0x1b` + negative lo is 0x1A8090/0x1A8420/0x1A8AE0/0x1A8D08,
 *   not 0x1B8xxx: 270 -> 212.
 * - The seven 16-byte vector arguments of func_003C6680 as `extern u8 X[8]` plus `.extern X, 16` (sized small object, assembler `la`
 *   pair that sched2 keeps together, as in retail): 212 -> 187.
 * - The `u8 f1C[4]` flag loop as a pointer walk (`fl = D_001426E0.f1C; for (i = 0; i < 4; i++) { if (*fl) z->f0++; fl++; }`) is retail's pointer-increment
 *   count-down loop (`bgez`); the indexed form `f1C[i]` was an up-counting `slti` loop: raw 678 -> 636. Reading `z->f8` into `i` before its two uses: 187 -> 181.
 * What still differs:
 * - Which saved register holds which high half: retail $fp 0x1c (D_001BBC40), $s5 0x14 (D_001426E0), $s6 0x1f (D_L09_001F2EC0), $s7 0x14
 *   (D_00142BA0); here $s6 0x1c, $s5 0x14, $s7 0x1f, $fp 0x14. The four pseudos are the last ones the global allocator assigns, in
 *   the order gcse created them, which is the order of the expressions in its hash table, i.e. a function of the symbol NAMES. Declaring
 *   the symbols in another order changes nothing (24 orders tried). An alias `D_001BBC48 - 8` for D_001BBC40 changes the order but
 *   adds 18 structural rows. About 50 aligned rows are this one allocation.
 * - The tail test (D_L09_001F2EC0 == 2 && ... && func_L01_004BA800() == 0): retail evaluates the && chain into $s0 (`addiu $s0, 1` in the
 *   delay slot of the first compare, `move $s0, $zero` at the failure label, `beqz $s0`), then tests it; every spelling that assigns it to
 *   a variable first (s0, i, a block local, `!= 0`, `? 1 : 0`) gets folded to direct branches (187, same code).
 * - case 2, join after `z->f74 = -1; z->f6C = -1; z->f70 = -1;`: retail has `bnel` with `sw $s0, 0x74` in its slot and then 0x6c, 0x70;
 *   the 12 source orders of the five stores give 185-188.
 * - case 5: retail reads `z->f2 ? f2C : f28` into a plain temp ($v1) instead of $s0 (ternary or `i`: 188 / 197; the row pointer in its own
 *   local `r`, which keeps it out of $s0's variable: 187 -> 184 with the compare as `z->f2 == 0`), and schedules the two
 *   `lq/sq` copies of the table row before `jal 0x444900`.
 * - case 1: the store `D_001D98E0 = ... + 0.4f` is in the `jal func_003C6680` delay slot in retail.
 * The jump table's `lui/addiu 0` rows are only the missing relocation of this standalone compile.
 */
#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct VT_316710 {
    void (*f0)(void);
    u8 pad4[0x24];
    void (*f28)(u8 *, s32, s32);
    void (*f2C)(u8 *);
    u8 pad30[0x1C];
    s32 (*f4C)(u8 *);
} VT_316710;
typedef struct Z_316710 {
    u8 f0, f1, f2, f3;
    u8 pad4[4];
    s32 f8;
    s32 fC;
    s32 f10[2];
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3C;
    s32 f40;
    s32 f44;
    s32 f48;
    s32 f4C;
    s32 f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    u8 f64;
    u8 pad65[7];
    s32 f6C;
    s32 f70;
    s32 f74;
} Z_316710;
typedef struct { u8 pad[0x18]; f32 f18; } F18_316710;
typedef struct X_316710 { u8 pad[0x3C]; s16 h3C; u8 pad3E[0xA]; s16 h48; } X_316710;
typedef struct K_316710 { u8 pad[0x18]; u8 f18; u8 f19; u8 pad1A[2]; u8 f1C[4]; u8 pad20[0x1D]; u8 f3D; u8 pad3E[0x94]; u8 fD2; } K_316710;

extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern u8 D_001A4C60[];
typedef struct { u8 p0[0x80]; u8 f80[0x10]; u8 f90[0x10]; u8 p_a0[0x25C4 - 0xA0]; s32 f25C4; u8 p25C8[0x2850 - 0x25C8]; s32 f2850; } H_316710;
extern H_316710 D_001A4BE0;
extern K_316710 D_001426E0;
extern struct { u8 pad[0x94]; u32 flags, next; } D_00142BA0;
extern s32 D_00143D70[];
extern s16 D_001426A0;
extern X_316710 D_001CCFD0;
extern s32 D_L09_001F2EC0[4];
extern u8 *D_L09_001E009C;
extern u8 *D_L09_001E0180;
extern f32 D_L09_001DF9D0;
extern s32 D_L09_001DFBC0;
extern u8 *D_L09_0016C580[];
extern u8 *D_001DC710;
__asm__(".extern D_001DC710, 4");
__asm__(".extern D_001D98E0, 4");
extern f32 D_001D98E0;
typedef struct { s32 a; s32 b; } S_DFC10;
extern S_DFC10 D_001DFC10;
extern s32 D_001A71A4[];
extern s32 D_001D4C38;
extern s32 D_001A7DD0[];
extern u32 D_001A8090[];
extern u32 D_001A8420[];
extern u32 D_001A8AE0[];
extern u32 D_001A7F28[];
extern u32 D_001A8D08[];
extern s32 D_L09_00236780[4];
extern u8 D_L09_00239C40[];
extern u8 D_001D9870[8];
__asm__(".extern D_001D9870, 16");
extern u8 D_001D9880[8];
__asm__(".extern D_001D9880, 16");
extern u8 D_001D9890[8];
__asm__(".extern D_001D9890, 16");
extern u8 D_001D98A0[8];
__asm__(".extern D_001D98A0, 16");
extern u8 D_001D98B0[8];
__asm__(".extern D_001D98B0, 16");
extern u8 D_001D98C0[8];
__asm__(".extern D_001D98C0, 16");
extern u8 D_001D98D0[8];
__asm__(".extern D_001D98D0, 16");

extern s32 func_00382380(void *, s32, s32);
extern void func_L01_00445130(u8 *, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_00445188(u8 *, u8);
extern void func_L01_004B0EE0(void);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_00456230(void *, s32);
extern VT_316710 *func_L01_0043B568(s32, s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L03_003B1DD0(u8 *);
extern void func_L01_003EC9E0(s32);
extern s32 func_L01_003ECA10(s32);
extern s32 func_L01_004AADE8(s32, s32, void *, s32);
extern void func_0039EF28(void);
extern f32 func_L01_0040E548(void *, void *);
extern void func_0038D308(void *, void *);
extern void func_003C6680(void *, void *, s32, s32, void *, void *, void *, void *, void *, void *, void *);
extern void func_L01_0043B510(s32);
extern void func_L01_004A3610(void *, void *);
extern s32 func_L01_004BA800(void);
extern void func_L01_0042B068(s32, s32);
extern s32 func_L01_00513EF0(void);
extern void func_L01_0041A5B0(s32, s32);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_0045F1E8(s32, s32);
extern void func_L09_004C6668(u8 *, f32, s32, s32, s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L09_003175C8(void);
extern void func_L09_00317798(void);
extern void func_L09_003177B8(void *, void *);

void func_L09_00316710(u8 *obj) {
    Z_316710 *z = *(Z_316710 **)(obj + 0x68);
    VT_316710 *vt;
    u8 *P;
    u8 *pt;
    u8 *q;
    u8 *r;
    s32 s0;
    s32 i;
    u8 *fl;
    u8 sv20[16] __attribute__((aligned(16)));
    u8 sv30[16] __attribute__((aligned(16)));

    if (z->f24 != -1 && func_00382380(D_001A4C60, z->f24, 0) != 0) {
        z->f2 = 2;
        func_L01_00445130(obj, 5, -1);
    }
    switch (obj[0x20]) {
    case 0:
        obj[0x30] = 0xFF;
        D_001DC710 = obj;
        z->f3 = 0;
        z->f64 = 0;
        if (z->f50 != -1 && (D_001BBC40[z->f50 + D_001D545C * 16] & 0x80) == 0)
            func_L01_004B0EE0();
        func_L01_004450F0(obj, 1, -1);
        break;
    case 1:
        if (func_L01_004561B8(obj) != 0) {
            if (z->f50 != -1 && (D_001BBC40[z->f50 + D_001D545C * 16] & 0x80) == 0)
                func_L01_004B0EE0();
            if (D_001426E0.f18 != 0) {
                func_L01_004450F0(obj, 2, -1);
                break;
            }
            z->f30 = 0x53;
        }
        vt = func_L01_0043B568(0x1ADD, 0, 0x68);
        if (vt->f4C(D_L09_001E009C + (z->f60 << 8)) != 0 && (D_001BBC40[z->f50 + D_001D545C * 16] & 0x80) != 0 &&
            *(s32 *)(*(u8 **)(D_L09_001E009C + (z->f60 << 8) + 0x68) + 0x6BC) == 3)
            vt->f2C(D_L09_001E009C + (z->f60 << 8));
        func_L01_00456230(obj, z->f0);
        if (z->f0 == 2) {
            if (D_001426E0.f18 == 0) {
                if (func_0038CAD0(&z->f30) == 0)
                    break;
                if (z->f18 != -1) {
                    func_L03_003B1DD0(D_L09_001E009C + (z->f18 << 8));
                    func_L01_003EC9E0(z->fC);
                    func_L01_004AADE8(0x11, 4, 0, 8);
                    D_001DFC10.b = 0;
                }
                D_001426E0.f18 = 1;
                func_0039EF28();
            } else {
                if (func_L01_003ECA10(z->fC) == 0)
                    break;
                z->f0 = 0;
                q = D_L09_001E0180 + (z->f34 << 7);
                D_001DFC10.b = 2;
                if (10000.0f < func_L01_0040E548(D_L09_0016C580[0] + 0x10, q + 0x30)) {
                    *(u128_t *)(D_L09_0016C580[0] + 0x10) = *(u128_t *)(q + 0x30);
                    *(u128_t *)(D_L09_0016C580[0] + 0xF0) = *(u128_t *)(q + 0x70);
                    func_0038D308(D_L09_0016C580[0] + 0xC0, D_L09_0016C580[0] + 0xF0);
                    D_001D98E0 = *(f32 *)(D_L09_0016C580[0] + 0x18) + 0.4f;
                    func_003C6680(D_L09_0016C580[0], D_L09_00239C40, 0, 0, D_001D98A0, D_001D98B0, D_001D9870, D_001D98D0, D_001D98C0, D_001D9880, D_001D9890);
                }
                func_L01_004450F0(obj, 2, -1);
            }
        }
        break;
    case 2:
        if (func_L01_004561B8(obj) != 0) {
            if (D_001426E0.f19 != 0) {
                for (i = 0; i < 2; i++)
                    ((F18_316710 *)(D_L09_001E009C + (z->f10[i] << 8)))->f18 = ((F18_316710 *)(D_L09_001E009C + (z->f10[i] << 8)))->f18 - 20.0f;
                func_L01_004450F0(obj, 4, -1);
                break;
            }
            fl = D_001426E0.f1C;
            for (i = 0; i < 4; i++) {
                if (*fl != 0)
                    z->f0++;
                fl++;
            }
        }
        i = z->f8;
        if (i != -1 && (D_L09_001E009C + (i << 8))[0x20] == 3) {
            if (z->f64 == 0) {
                vt = func_L01_0043B568(0x1ADD, 0, 0x68);
                vt->f28(D_L09_001E009C + (z->f60 << 8), 0, 0);
                z->f64 = 1;
            }
        } else if (z->f64 != 0) {
            vt = func_L01_0043B568(0x1ADD, 0, 0x68);
            vt->f2C(D_L09_001E009C + (z->f60 << 8));
            z->f64 = 0;
        }
        func_L01_00456230(obj, z->f0 + 2);
        if (z->f0 == 4 && z->f1 != 0) {
            if (D_001A4BE0.f2850 > 0 && D_001A4BE0.f25C4 != 0x6A && D_001A4BE0.f25C4 != 0x7D) {
                if ((D_00142BA0.flags & 0x800000) == 0) {
                    if (z->f1C != -1)
                        func_L01_00456230(D_L09_001E009C + (z->f1C << 8), 1);
                } else if (func_L01_004BA800() == 0) {
                    for (i = 0; i < 2; i++)
                        ((F18_316710 *)(D_L09_001E009C + (z->f10[i] << 8)))->f18 = ((F18_316710 *)(D_L09_001E009C + (z->f10[i] << 8)))->f18 - 20.0f;
                    if (z->f6C != -1)
                        func_L01_0043B510(z->f6C);
                    if (*(u8 *)((u8 *)&D_001426E0 + z->f74) == 0) {
                        *(u8 *)((u8 *)&D_001426E0 + z->f74) = 1;
                        func_0039EF28();
                    }
                    z->f74 = -1;
                    z->f6C = -1;
                    z->f70 = -1;
                    z->f1 = 0;
                    z->f0 = 0;
                    D_001426E0.f19 = 1;
                    func_0039EF28();
                    func_L01_004A3610(D_001A4C60, D_001A4C60 + 0x10);
                    func_L01_004450F0(obj, 4, -1);
                }
            } else {
                if (z->f6C != -1)
                    func_L01_0043B510(z->f6C);
                if (*(u8 *)((u8 *)&D_001426E0 + z->f74) == 0) {
                    *(u8 *)((u8 *)&D_001426E0 + z->f74) = 1;
                    func_0039EF28();
                }
                if (z->f70 == -1) {
                    func_L01_004A3610(D_001A4BE0.f80, D_001A4BE0.f90);
                } else {
                    q = D_L09_001E0180 + (z->f70 << 7);
                    func_L01_004A3610(q + 0x30, q + 0x70);
                }
                z->f1 = 0;
                z->f70 = -1;
                z->f6C = -1;
            }
        }
        break;
    case 3:
        break;
    case 4:
        s0 = D_L09_001F2EC0[0];
        if (s0 == 1) {
            if (func_L01_004561B8(obj) != 0) {
                vt = func_L01_0043B568(0x1ADD, 0, 0x68);
                vt->f28(D_L09_001E009C + (z->f60 << 8), 2, 0);
                break;
            }
            if (D_L09_001F2EC0[0] == s0)
                break;
        }
        func_L01_004450F0(obj, 4, -1);
        break;
    case 5:
        if (func_L01_004561B8(obj) != 0)
            obj[0xBC] = 0;
        if (obj[0xBC] == 0) {
            if (1.0f <= D_L09_001DF9D0) {
                D_L09_001DF9D0 = 1.5f;
                obj[0xBC] = obj[0xBC] + 1;
                if (z->f2 == 0)
                    s0 = z->f28;
                else
                    s0 = z->f2C;
                r = D_L09_001E0180 + (s0 << 7);
                *(u128_t *)sv20 = *(u128_t *)(r + 0x30);
                *(u128_t *)sv30 = *(u128_t *)(r + 0x70);
                func_L01_0042B068(z->f2, 0);
                vt = func_L01_0043B568(0x1A5B, 0, 4);
                if (vt != 0) {
                    func_L01_0043B510(z->f38);
                    P = D_L09_001E0180 + (z->f2C << 7);
                    func_L01_004A3610(P + 0x30, P + 0x70);
                    vt->f0();
                }
            } else {
                D_L09_001DF9D0 = D_L09_001DF9D0 + 0.060000002f;
            }
        } else {
            D_L09_001DF9D0 = D_L09_001DF9D0 - 0.060000002f;
            if (D_L09_001DF9D0 <= 0.0f) {
                D_L09_001DF9D0 = 0.0f;
                func_L01_004450F0(obj, obj[0x94], -1);
            }
        }
        break;
    }
    switch (obj[0xBC]) {
    case 0:
        if (D_L09_001F2EC0[0] == 1)
            func_L01_00445188(obj, 2);
        else if (D_L09_001F2EC0[0] == 2)
            func_L01_00445188(obj, 1);
        break;
    case 1:
        if ((D_001CCFD0.h3C == -1 ? D_001CCFD0.h48 : D_001CCFD0.h3C) != z->f54)
            func_L01_0045F1E8(z->f54, -1);
        if (D_L09_001F2EC0[0] == 1)
            func_L01_00445188(obj, 2);
        break;
    case 2:
        if (((D_001CCFD0.h3C == -1 ? D_001CCFD0.h48 : D_001CCFD0.h3C) != z->f58) && D_001426E0.f3D == 0) {
            func_L01_0045F1E8(z->f58, -1);
        } else if (((D_001CCFD0.h3C == -1 ? D_001CCFD0.h48 : D_001CCFD0.h3C) != z->f54) && D_001426E0.f3D != 0) {
            func_L01_0045F1E8(z->f54, -1);
        }
        if (D_L09_001F2EC0[0] == 2)
            func_L01_00445188(obj, 1);
        break;
    }
    if (D_001BBC40[z->f50 + D_001D545C * 16] & 0x80) {
        if (D_L09_001DFBC0 < 5) {
            D_001426E0.fD2 = D_001426E0.fD2 | 1;
            func_0039EF28();
        }
    }
    if (D_001BBC40[z->f38 + D_001D545C * 16] & 0x80) {
        D_001426E0.fD2 = D_001426E0.fD2 | 2;
        func_0039EF28();
    }
    if (D_L09_001F2EC0[0] == 2 && D_001426E0.f3D == 0 && D_001A71A4[0] != 0x74 && (D_00142BA0.flags & 0x400000) != 0 &&
         func_L01_004BA800() == 0) {
        if (z->f3 == 0) {
            func_L09_003175C8();
            z->f3 = 1;
        }
        func_L09_003177B8(obj, z);
        if ((D_001A8090[0] & (1 << D_001D545C)) == 0)
            func_L01_0041A5B0(0xB91, 0x34);
    } else if (z->f3 != 0) {
        func_L09_00317798();
        z->f3 = 0;
    }
    if (D_00143D70[D_001D545C] == 3 && func_L01_00513EF0() == 0 && (u32)((D_001D4C38 * 5 + 2) / 6 - D_001A7DD0[0]) > 0x2BF20 &&
        (D_001A8420[0] & (1 << D_001D545C)) == 0)
        func_L01_0041A5B0(0xCD7, 0x80);
    if (D_00143D70[D_001D545C] == 5 && D_001426A0 < 2 && (D_001A8AE0[0] & (1 << D_001D545C)) == 0)
        func_L01_0041A5B0(0x140E, 0x110);
    if (z->f5C != -1 && func_L01_00456500(D_001A4C60, z->f5C) != 0 && (D_001A7F28[0] & (1 << D_001D545C)) == 0)
        func_L01_0041A5B0(0xB42, 0x16);
    if ((D_00142BA0.next & 0x1000000) != 0 && func_L01_004BA800() == 0 && (D_001A8D08[0] & (1 << D_001D545C)) == 0)
        func_L01_0041A5B0(0x169B, 0x13E);
    if (z->f38 != -1 && (D_001BBC40[z->f38 + D_001D545C * 16] & 0x80) != 0) {
        q = D_L09_001E0180 + (z->f3C << 7);
        pt = D_L09_001E0180 + (z->f40 << 7);
        func_L09_004C6668(pt + 0x30, *(f32 *)(pt + 0x78), z->f44, z->f48, z->f4C);
        if (D_L09_001DFBC0 < 5) {
            if (D_L09_00236780[0] == 0) {
                if (D_L09_001F2EC0[0] != 2)
                    func_L01_0042B068(2, 0);
                func_L01_004F50C8(q + 0x30, q + 0x70, 0, 1);
            }
        }
        z->f38 = -1;
    }
}
