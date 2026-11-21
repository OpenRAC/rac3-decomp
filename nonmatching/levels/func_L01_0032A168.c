/* PAL near miss (Sonnet round 20, b33 h4d / h4e): 27 raw differences (6 words that are not branch offsets or the masked jump-table lui/addiu) with `-mvu0-use-vf0-vf2` added to
 * its file's flags (the vec_add_ab at the end of case 4 needs it: without it cc1 reports `fixed or forbidden register 96 (vf17) was spilled for class VU_REGS`, so a match would also
 * change the flag line of src/levels/shared/L01_00329AD0.c and every other block of that file would have to be re-checked).
 * Check: python tools/check.py nonmatching/levels/func_L01_0032A168.c func_L01_0032A168 --flags=-mvu0-use-vf0-vf2
 * 5-state menu / vendor machine: one `switch (o->b20)` with FALL-THROUGH cases (0 -> 1 -> 2, 3 -> 4 through `if (o->b20 != 4) break;`), a 5-entry jump table (every place needs the manager's
 * jump-table check). H4d wrote the structure from the listing (35 raw). Levers found by h4e: (1) the table loop in case 2 gets its OWN counter `j` (the `i` shared with the other two loops was
 * allocated $s1 and the loop's hoisted -1 constant $s0, retail has counter $s0 / constant $s1) 35 -> 29; (2) `extern s32 D_L01_001E6DB0[];` unsized (retail `lui $v1; lw $v0,0x6db0($v1)`) 29 -> 27.
 * Left (one cluster, case 2): retail loads THREE separate -1 constants in the table code: `addiu $v0,-1` for `v->w0 != -1`, `addiu $a1,-1` for the guard `p[0] != -1` (it sits in the
 * delay slot of the `beqz tbl` branch, `ok = 1` / `addiu $t1` is mid-block) and `addiu $s1,-1` hoisted for the loop. Ours shares ONE pseudo between the w0 test and the guard: cse follows the
 * `beq` around the call block (-fcse-skip-blocks, `AROUND` path) and deletes the `(set rC -1)` of the guard (jump.c's copy of the loop-exit test), so the constant lives across the call in a saved
 * register and `ok = 1` moves into the slot. `-fno-cse-skip-blocks` gives retail's first `$v0` but is a new flag (and 136 raw elsewhere). Mini reproduction (about 30 lines, 1 s per compile):
 * any CFG variant of the w0 test (nested if, || form, goto form, result variable, else arm, dead store in the return path, extra folded branches before it) keeps the shared constant; a
 * wrapper inline or a boolean result variable breaks the sharing but changes the code. Not tried: a real source form that makes the call block contain a label at cse time. */
#include "common.h"
/* localdecomp:start func_L01_0032A168 */
#include "vu0.h"

typedef struct {
    s32 w0;
    s32 w4;
    u8 b8;
    s8 c9;
    u8 ba;
    s8 cb;
    s8 cc;
    u8 bd;
    u8 pe;
    u8 bf;
    s32 w10;
    s32 w14;
    u8 p18[8];
    s32 w20[4];
    s32 w30;
    s32 w34;
    s8 c38;
    u8 b39;
    u8 b3a;
    u8 b3b;
} V_32A168;

typedef struct {
    u8 p0[0x20];
    u8 b20;
    u8 p21[0x47];
    V_32A168 *vars;
    u8 p6c[0x28];
    u8 b94;
    u8 p95[0x1B];
    u8 bb0;
    u8 pb1[0xB];
    u8 bbc;
} O_32A168;

typedef struct {
    u8 p0[0x80];
    f32 x80;
    f32 y84;
    f32 z88;
    u8 p8c[0xC];
    f32 f98;
    u8 p9c[0x25C4 - 0x9C];
    s32 w25C4;
    u8 p25C8[0x2850 - 0x25C8];
    s32 w2850;
} H_32A168;

typedef struct {
    u8 p0[0x26];
    s16 h26;
    u8 p28[0x48];
    vu0_q q70;
} G_32A168;

typedef struct {
    u8 p0[0x24];
    void (*f24)(s32, s32);
    u8 p28[0x1C];
    void (*f44)(s32);
} Vt_32A168;

typedef struct {
    u8 p0[0x30];
    u8 b30;
    u8 p31[3];
    u16 h34;
    u8 p36[0x2E];
    void (*f64)(u8 *);
} E_32A168;

extern u8 D_001D5530[8];
__asm__(".extern D_001D5530, 16");
extern u8 D_001BBC40[][16];
extern u8 *D_001D52FC;
extern s32 D_L01_001DFB40;
extern s32 D_L01_001DFB94;
extern s32 D_L01_001E1880;
extern s32 D_L01_001DFC28;
extern f32 D_L01_001DF950;
extern s32 D_L01_001E6DB0[];
extern s32 D_L01_001D6694;
extern s32 D_L01_001D6690;
extern s32 D_L01_002D15F0[];
extern u8 D_00142CAD[];
extern u8 D_0014275D[];
extern u8 D_0014275C[];
extern u8 D_00142CA0[];
extern u8 D_00142CBE[];
extern u8 D_00142D62[];
extern u8 D_001426E0[];
extern u8 D_001BBDA2;
extern u8 D_L01_001DFE82;
extern u32 D_00142BA0[];
extern u8 D_L01_001EA7C0[];
extern s32 D_L01_001F3F40[];
extern s16 **D_L01_002AF350[];
extern H_32A168 D_001A4BE0;
extern G_32A168 D_0016C580;
extern u8 D_001A4C60[];

extern void func_L01_00456230(void *, s32);
extern s32 func_L01_00456250(void *);
extern void func_003C2880(void *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_00392B20(void *, s32);
extern s32 func_00392C78(void *);
extern void func_L01_004BA7B8(void);
extern s32 func_L01_004BA800(void);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_0044CCC8(s32);
extern void func_0039EF28(void);
extern void func_L01_0044FC48(s32, s32);
extern void func_L01_0043B510(s32);
extern void func_L01_004A3610(u8 *, u8 *);
extern void func_00392DF0(s32, s32);
extern void func_003A0EC0(s32, s32, s32, s32, s32);
extern void func_0039EC28(s32, s32);
extern void func_L01_0042B068(s32, s32);
extern Vt_32A168 *func_L01_0043B548(s32, s32);
extern void func_L01_00419188(s32);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_00511A40(void *, s32, f32);

void func_L01_0032A168(O_32A168 *o) {
    V_32A168 *v;
    s32 i;
    s32 j;
    u32 id;
    s32 g;
    s32 ok;
    s32 f;
    s16 **tbl;
    s16 *p;
    u8 *hero;
    E_32A168 *e;
    vu0_v4 vec;
    Vt_32A168 *vt;
    s32 c;
    u32 x;

    v = o->vars;
    if (D_001D545C == 0x11 && o->b20 == 0 && v->w10 != 0 && (D_001BBC40[D_001D545C][o->bb0] & 0x80)) {
        for (i = 0; i < 4; i++) {
            if (v->w20[i] >= 0) {
                func_L01_00456230(D_L01_001E001C + (v->w20[i] << 8), 1);
            }
        }
        func_003C2880(o);
        return;
    }
    if (D_L01_001DFB40 <= 0) {
        return;
    }
    switch (o->b20) {
    case 0:
        if (v->c9 != -1 && D_001D5530[v->c9] != 0) {
            func_003C2880(o);
            return;
        }
        if (o->bb0 != 0xFF && (D_001BBC40[D_001D545C][o->bb0] & 0x80)) {
            func_003C2880(o);
            return;
        }
        func_L01_004450F0(o, 1, -1);
    case 1:
        if (v->ba == 0 && func_L01_00456250(o) == 0 && o->bbc == 0) {
            return;
        }
        v->ba = 1;
        func_L01_004450F0(o, 2, -1);
    case 2:
        if (v->w14 != 0) {
            if (D_00142CAD[0] == 0) {
                return;
            }
            if (D_0014275D[0] == 0) {
                return;
            }
            if (D_001D545C == 0xD) {
                if ((*(s32 *)(D_001D52FC + 0x1A4) & 0x10) == 0) {
                    return;
                }
                if (D_L01_002D15F0[0] == 0xC) {
                    return;
                }
            }
        }
        if (D_001D545C == 4 && D_L01_001D6694 == 6) {
            return;
        }
        if (v->ba == 0) {
            func_L01_004450F0(o, 1, -1);
            return;
        }
        if (D_001A4BE0.w25C4 == 0x1C) {
            return;
        }
        if (D_001A4BE0.w25C4 == 0x31) {
            return;
        }
        if (D_001A4BE0.w2850 <= 0) {
            return;
        }
        if (D_L01_001D6694 != 0) {
            return;
        }
        if (v->w0 != -1 && func_00382380(&D_001A4BE0.x80, v->w0, 0) == 0) {
            return;
        }
        ok = 1;
        D_L01_001E1880 = D_L01_001DFB94;
        if (D_L01_002AF350[D_001D545C] != 0 && D_L01_002AF350[D_001D545C][v->b8] != 0) {
            for (j = 0; D_L01_002AF350[D_001D545C][v->b8][j] != -1; j++) {
                id = D_L01_002AF350[D_001D545C][v->b8][j];
                if (v->bd == 0 && (v->w34 == -1 || (D_001BBC40[D_001D545C][v->w34] & 0x80)) &&
                    (D_00142BA0[id >> 2] & (1 << (id & 0x1F)))) {
                    continue;
                }
                if (func_00392B20(D_L01_001EA7C0, id) == 0 && j == 0) {
                    return;
                }
                ok = 0;
            }
        }
        if (ok != 0) {
            v->bf = 0;
            func_L01_004450F0(o, 4, -1);
            return;
        }
        v->bf = 1;
        func_00392C78(D_L01_001EA7C0);
        if (D_L01_001DFB40 < 5 || D_L01_001DF950 >= 0.83f) {
            D_L01_001DF950 = 1.5f;
            func_L01_004BA7B8();
        }
        func_L01_004450F0(o, 3, -1);
        break;
    case 3:
        if (D_001D545C == 3 && v->b8 == 0) {
            D_L01_001DFB94 = 0;
        }
        if (D_001D545C == 0xA && (u32)(D_L01_001E6DB0[0] - 5) < 2) {
            D_L01_001DFB94 = 0;
        }
        if (D_L01_001D6694 != 2) {
            if (D_L01_001DFB40 < 300 && D_L01_001DF950 > 0.7f) {
                D_L01_001DF950 = 1.5f;
            }
            if (v->w14 != 0 && D_001D545C == 0xD && D_L01_001D6690 != 6 && D_L01_001D6694 != 6) {
                vec.x = 260.53f;
                vec.y = 268.38f;
                vec.z = 100.0f;
                D_L01_001DFC28 = 1;
                D_0016C580.h26 = 1;
                D_0016C580.q70 = *(vu0_q *)&vec;
            }
        }
        if (func_L01_004BA800() == 0) {
            if (v->w4 != -1) {
                func_L01_004F50C8(D_L01_001E0100 + (v->w4 << 7) + 0x30, D_L01_001E0100 + (v->w4 << 7) + 0x70, 0, 1);
            }
            func_L01_004450F0(o, 4, -1);
        }
        if (D_001D545C != 0 || v->c9 == -1 || func_L01_004BA800() != 0) {
            goto chk;
        }
        f = 0;
        if (v->c9 != -1) {
            func_L01_0044CCC8(v->c9);
            func_0039EF28();
            if (v->c9 != 0x18) {
                func_L01_0044FC48(v->c9, 0);
            }
            f = 1;
        }
        if (o->bb0 != 0xFF && (D_001BBC40[D_001D545C][o->bb0] & 0x80) == 0) {
            func_L01_0043B510(o->bb0);
            f = 1;
        }
        if (v->cb != 0) {
            if (*(u32 *)((u8 *)v + 0xC) & 0xFFFF0000) {
                if (v->w4 != -1) {
                    func_L01_004A3610(D_L01_001E0100 + (v->w4 << 7) + 0x30, D_L01_001E0100 + (v->w4 << 7) + 0x70);
                } else {
                    func_L01_004A3610((u8 *)o + 0x10, (u8 *)o + 0xF0);
                }
            }
        }
        if (v->cc != -1) {
            if (v->b39 == 0) {
                func_00392DF0(v->cc, 1);
            } else {
                D_L01_001D6694 = 3;
                D_L01_001D6690 = -2;
                func_003A0EC0(6, 2, 1, v->cc, 0);
            }
        } else if (f != 0 || v->bf != 0) {
            func_0039EC28(0, -1);
        }
    chk:
        if (o->b20 != 4) {
            break;
        }
    case 4:
        D_L01_001DFB94 = D_L01_001E1880;
        g = 0;
        if (v->c9 != -1) {
            func_L01_0044CCC8(v->c9);
            func_0039EF28();
            func_L01_0044FC48(v->c9, 0);
            if (v->c38 != -1) {
                func_L01_0044CCC8(v->c38);
                func_0039EF28();
                func_L01_0044FC48(v->c38, 1);
            }
            g = 1;
        }
        if (o->bb0 != 0xFF && (D_001BBC40[D_001D545C][o->bb0] & 0x80) == 0) {
            func_L01_0043B510(o->bb0);
            g = 1;
        }
        if (v->w10 != 0) {
            if (D_001D545C == 0x13) {
                D_001426E0[0x82] |= 1;
                func_0039EF28();
            } else if (D_001D545C == 0x11) {
                if (D_00142CA0[0x22] == 0) {
                    D_00142CA0[0x22] = 1;
                    D_00142D62[0] = 1;
                    func_0039EF28();
                    func_L01_00452560(0, 0xF, 0x14EB, 0x96, 0, 0, 0);
                }
            } else if (D_001D545C == 7) {
                if (D_00142CBE[0] == 0) {
                    func_L01_00419188(0x1E);
                    func_L01_00452560(0, 0xF, 0xAF0, 0x96, 0, 0, 0);
                }
            } else {
                D_0014275C[0] = 1;
            }
            g = 1;
        }
        if (v->cb > 0 && (*(u32 *)((u8 *)v + 0xC) & 0xFFFF0000)) {
            if (v->w4 != -1) {
                func_L01_004A3610(D_L01_001E0100 + (v->w4 << 7) + 0x30, D_L01_001E0100 + (v->w4 << 7) + 0x70);
            } else {
                func_L01_004A3610(D_001A4C60, D_001A4C60 + 0x10);
            }
        }
        for (i = 0; i < 4; i++) {
            if (v->w20[i] >= 0) {
                func_L01_00456230(D_L01_001E001C + (v->w20[i] << 8), 1);
            }
        }
        if (D_001D545C == 0x16) {
            if (v->w20[0] >= 0) {
                vt = func_L01_0043B548(0x19E1, 0x6C);
                vt->f24(0, 0);
                vt->f44(1);
                D_001BBC40[0x16][2] = 0x80;
                D_L01_001DFE82 = 0x80;
                x = ((D_001D545C & 0x1F) << 11) | 0x64;
                D_001426E0[0x72] = x;
                D_001426E0[0x71] = x >> 8;
            }
        }
        if (v->cc != -1) {
            if (D_001D545C == 0xA && v->b8 == 0) {
                func_L01_0042B068(1, 0);
            } else if (v->cc == D_001D545C) {
                if (D_L01_001F3F40[3] > 0) {
                    func_L01_0042B068(1 - D_L01_001F3F40[0], 0);
                } else {
                    goto lab_a40;
                }
            } else {
            lab_a40:
                if (v->b39 == 0) {
                    func_00392DF0(v->cc, 1);
                } else {
                    D_L01_001D6694 = 3;
                    D_L01_001D6690 = -2;
                    func_003A0EC0(6, 2, 1, v->cc, 0);
                }
            }
        } else if (g != 0 || v->bf != 0) {
            if (v->cb != v->cc) {
                func_0039EC28(0, -1);
            }
        }
        if (v->w30 != -1) {
            e = (E_32A168 *)(D_L01_001E001C + (v->w30 << 8));
            func_L01_00456230(e, 1);
            e->h34 &= ~2;
            e->b30 = 0xFF;
            e->f64((u8 *)e);
        }
        if (v->b3a != 0) {
            func_0038CE20(&vec, &D_001A4BE0, 3.0f);
            vec_add_ab(&vec, &vec, &D_001A4BE0.x80);
            vec.z += 0.5f;
            vec.z = func_003C3D30(&vec, 0, 0, 0.5f);
            if (fabs_asm(D_001A4BE0.z88 - vec.z) > 0.3f) {
                return;
            }
            func_L01_00511A40(&vec, 1, D_001A4BE0.f98);
        }
        if (v->b3b != 0 && o->b94 == 3) {
            func_003A0EC0(5, 1, 6, 0, 0);
        }
        func_003C2880(o);
        break;
    }
}
/* localdecomp:end func_L01_0032A168 */
