/* func_L01_003A0778: a Veldin enemy's update (7 levels: 01 04 09 12 18 26 29). Near miss, not
   linked. Written from the retail assembly (no rac2/rac4 twin; Opus singletons, 2026-11-08).
   State: 2834 of 2834 instructions, the same opcode at every row except two; 2823 rows equal with
   registers (check.py at level 01; the 4 jtbl %hi/%lo rows are the snippet's own .rodata and are
   not real differences). Left: case 11's spilled +0x430 pointer (both the +0x95 == 3 and the +0x3D0
   path): retail computes it after the D_L01_001E0100 load ($v0) and after the +0x3D0 load ($v1);
   this C schedules it first in both paths (its position in the source, its scope and temporaries
   do not move it). The +0x3D0 path's byte offset `o = i * 0x30` gives retail's registers.
   Needs, when it lands: its own file, src/levels/shared/L01_003A0778.c, with
   "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (func_L01_003A0710 and
   func_L01_003A4938 do not take those flags; split L01_0039E1B0.c at 0x3A0778 and 0x3A33C0, both
   8-aligned in all 7 levels). Check it with
     tools/check.py THIS.c func_L01_003A0778 --mode S --as ps2as --flags=-mvu0-use-vf0-vf2
   What made the difference: a fresh counter per loop of case 11 (one shared counter outranks the
   per-object pointer in global allocation), the D_L01_001DFC4C header struct (record pointer +
   index order), byte arithmetic `+ (id << 7)` for D_L01_001E0100, scalar tunables with .extern
   hints, `*(u128_t *)&s9 = 0` before the 4-float constant, the xori/andi flag test, and the
   prototypes (00448890: ptr, f, f, f, f, ptr, int; 004468C8: ptr, f, f, f, ints). */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef union { u8 b[0x2A00]; s16 h[0x1500]; u16 uh[0x1500]; s32 i[0xA80]; u32 u[0xA80]; f32 f[0xA80]; u8 *ptr[0xA80]; u128_t q[0x2A0]; } Hero;
typedef union { u8 b[0x500]; s8 c[0x500]; s16 h[0x280]; u16 uh[0x280]; s32 i[0x140]; u32 u[0x140]; f32 f[0x140]; u8 *ptr[0x140]; u128_t q[0x50]; } Obj;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { u8 p[0x10]; s16 n10; s16 n12; s16 n14; s16 n16; u8 p18[4]; s32 *list1C; s32 *list20; u8 p24[0x0C]; } Rec30;
typedef struct { s32 count; u8 p4[0x1C]; Rec30 recs[1]; } Hdr30;
typedef struct { u8 b[0x80]; } Rec80;

extern Hero D_001A4BE0;
extern u8 D_001A4C60[];
extern u8 D_001426E0[];
extern s32 D_001D545C;
extern s32 D_L01_001D6694;
extern s32 D_L01_001D66B0;
extern Hdr30 *D_L01_001DFC4C;
extern u8 *D_L01_001E001C;
extern u8 *D_L01_001E0100;
extern s32 *D_L01_0021F6C0[];
extern u8 *D_L01_00221098[];
extern f32 D_L01_001DE250;
__asm__(".extern D_L01_001DE250, 4");
extern f32 D_L01_001DE254;
__asm__(".extern D_L01_001DE254, 4");
extern f32 D_L01_001DE258;
__asm__(".extern D_L01_001DE258, 4");
extern f32 D_L01_001DE268;
__asm__(".extern D_L01_001DE268, 4");
extern f32 D_L01_001DE26C;
__asm__(".extern D_L01_001DE26C, 4");
extern f32 D_L01_001DE270;
__asm__(".extern D_L01_001DE270, 4");
extern f32 D_L01_001DE274;
__asm__(".extern D_L01_001DE274, 4");

extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern f32 func_00382538(void);
extern Obj *func_00382348(void *);
extern s32 func_00382380(void *, s32, s32);
extern void func_00382580(void *, f32, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_003C3A10(Obj *, s32, s32, s32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_003A33C0(Obj *);
extern void func_L01_003A3EC8(Obj *, s32);
extern void func_L01_003A3F68(Obj *);
extern void func_L01_003A4180(Obj *);
extern s32 func_L01_003A8CF0(Obj *, void *, void *, f32);
extern s32 func_L01_003AA018(Obj *, void *, void *, s32, f32);
extern f32 func_L01_004395E0(Obj *);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_004450F0(Obj *, s32, s32);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern void func_L01_00445BE0(s32, s32);
extern s32 func_L01_00446058(Obj *, s32, s32);
extern void func_L01_004468C8(Obj *, f32, f32, f32, s32, s32, s32, s32, s32);
extern void func_L01_00448890(void *, f32, f32, f32, f32, void *, s32);
extern s32 func_L01_0044E1B8(Obj *, f32);
extern s32 func_L01_00454370(Obj *, void *);
extern s32 func_L01_004561B8(Obj *);
extern s32 func_L01_004561E0(Obj *);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_00458F78(Obj *, void *, s32, s32);
extern void func_L01_00459188(Obj *, void *, void *);
extern void func_L01_004591B8(Obj *, void *, void *);
extern void func_L01_0045A748(Obj *, void *);
extern void func_L01_0045A898(void *, void *, f32);
extern void func_L01_0045A9F0(Obj *);
extern s32 func_L01_0045BD10(Obj *, f32);
extern void func_L01_0045BD78(Obj *, f32, f32, f32, f32);
extern s32 func_L01_0045BDE8(Obj *, s32);
extern void func_L01_0045C150(Obj *, void *, s32, s32);
extern s32 func_L01_0045C2A0(Obj *, f32, f32, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_004AA7E8(Obj *, s32);

void func_L01_003A0778(Obj *m) {
    V4 s9, sA, sB;
    Obj *pv;
    s32 x;

    pv = (Obj *)m->ptr[0x68 / 4];
    if (func_L01_003A33C0(m) != 0) {
        func_L01_003A3EC8(m, 1);
        return;
    }
    if (D_001D545C == 1 && pv->i[0x42C / 4] == 0 && pv->i[0x3C0 / 4] != 0) {
        func_L01_00446058(m, 0x1F02, 0x18A2);
        m->h[0xAA / 2] = 0x18A2;
        pv->i[0x42C / 4] = 1;
    }
    if (D_001426E0[0x7C] != 0 && pv->i[0x42C / 4] == 0) {
        if (func_L01_00446058(m, 0x1F03, 0x18A2) != 0) {
            m->h[0xAA / 2] = 0x18A2;
            pv->i[0x42C / 4] = 1;
        }
    } else if ((D_001D545C == 0xD || D_001D545C == 0x10 || D_001D545C == 0x1D || D_001D545C == 0xC || D_001D545C == 0x45)
               && pv->i[0x42C / 4] == 0 && D_001426E0[0x7C] == 0) {
        pv->i[0x42C / 4] = 1;
        func_L01_00446058(m, 0x1ED9, 0x18A2);
        m->h[0xAA / 2] = 0x18A2;
    }
    if (D_L01_001D6694 == 2) {
        if ((m->b[0x34] ^ 1) & 1) {
            m->i[0x98 / 4] = 0;
            m->uh[0x34 / 2] = (m->uh[0x34 / 2] | 0x41) & ~0x1000;
            func_L01_004AA7E8(m, 1);
            pv->i[0x428 / 4] = 1;
        }
        return;
    }
    if (pv->i[0x428 / 4] != 0) {
        Obj *c = (Obj *)m->ptr[0x24 / 4];
        m->uh[0x34 / 2] &= 0xFFBE;
        m->uh[0x34 / 2] |= c->uh[0x44 / 2] & 0x1000;
        m->i[0x98 / 4] = c->i[0x10 / 4];
        pv->i[0x428 / 4] = 0;
    }
    x = 1;
    if (pv->b[0x5F] != 0) {
        x = 0x10001;
    }

    switch (m->b[0x95]) {
    case 5:
        if (func_L01_00456250(D_L01_001E001C + (pv->i[0x3AC / 4] << 8)) != 0) {
            func_L01_004450F0(m, 2, 0);
            if (m->b[0x43] != 0) {
                func_003C3A10(m, 0, 0, 0);
            }
            if (pv->i[0x2F8 / 4] != -1) {
                func_L01_004450F0(m, 4, -1);
                if (m->b[0x43] != 8) {
                    func_003C3A10(m, 8, 0, 0);
                }
            }
        }
        break;
    case 0: {
        s32 found;

        if (func_L01_004561E0(m) != 0 && pv->h[0x2E6 / 2] == 0) {
            pv->h[0x2E6 / 2] = (func_00382498(0, 0x1E) * 5 + 2) / 6;
        }
        found = 0;
        if (pv->i[0x3C8 / 4] != -1) {
            u8 *e = D_L01_001E001C + (pv->i[0x3C8 / 4] << 8);
            f32 *q = (f32 *)func_00382348(e);
            if (e == 0 || e[0x20] == 0xFE) {
                found = 1;
            } else if (e[0x20] == 0xFD) {
                found = 1;
            } else if (q != 0 && *q <= 0.0f) {
                found = 1;
            }
        }
        if (pv->i[0x3CC / 4] != 0xFF && func_L01_00445AD0(pv->i[0x3CC / 4], -1, 1) != 0) {
            found = 0;
        }
        if ((pv->h[0x234 / 2] == 1 || found) && func_0038CB00(&pv->h[0x2E6 / 2]) != 0) {
            if (m->b[0x43] != 8) {
                func_003C3A10(m, 8, 0, (func_00382498(6, 0xA) * 5 + 2) / 6);
            }
            func_L01_004450F0(m, 7, 2);
            if (pv->i[0x2EC / 4] != -1) {
                func_L01_004450F0(m, 9, -1);
                if (m->b[0x43] != 8) {
                    func_003C3A10(m, 8, 0, 8);
                }
            } else if (pv->i[0x3B0 / 4] != -1) {
                func_L01_004450F0(m, 0xA, -1);
            } else if (pv->i[0x3D0 / 4] != -1 && D_L01_001DFC4C->recs[pv->i[0x3D0 / 4]].n12 != 0) {
                func_L01_004450F0(m, 0xB, -1);
            }
        } else if (pv->i[0x418 / 4] != 0) {
            if (pv->i[0x414 / 4] != -1 && D_L01_001DFC4C->recs[pv->i[0x414 / 4]].n12 != 0) {
                if (m->b[0x43] != 8) {
                    func_003C3A10(m, 8, 0, 8);
                }
                func_L01_004450F0(m, 0xB, 3);
            }
        } else if (pv->i[0x2E8 / 4] != 0 && func_0038CB00(&pv->h[0x2E6 / 2]) != 0) {
            func_L01_004450F0(m, 5, 1);
            pv->i[0x2E8 / 4] = 0;
            if (pv->i[0x2E0 / 4] < 0xFA) {
                pv->i[0x2E0 / 4] = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    }
    case 1:
        if (pv->h[0x234 / 2] == 1) {
            if (m->b[0x43] != 8) {
                func_003C3A10(m, 8, 0, 8);
            }
            func_L01_004450F0(m, 7, 2);
            if (pv->i[0x2EC / 4] != -1) {
                func_L01_004450F0(m, 9, -1);
                if (m->b[0x43] != 8) {
                    func_003C3A10(m, 8, 0, 8);
                }
            } else if (pv->i[0x3B0 / 4] != -1) {
                func_L01_004450F0(m, 0xA, -1);
            } else if (pv->i[0x3D0 / 4] != -1 && D_L01_001DFC4C->recs[pv->i[0x3D0 / 4]].n12 != 0) {
                func_L01_004450F0(m, 0xB, -1);
            }
        } else if (pv->i[0x418 / 4] != 0) {
            if (pv->i[0x414 / 4] != -1 && D_L01_001DFC4C->recs[pv->i[0x414 / 4]].n12 != 0) {
                if (m->b[0x43] != 8) {
                    func_003C3A10(m, 8, 0, 8);
                }
                func_L01_004450F0(m, 0xB, 3);
            }
        } else if (pv->i[0x2E0 / 4] == 0) {
            func_L01_004450F0(m, 2, 0);
        }
        break;
    case 2:
        if (pv->h[0x234 / 2] != 1 && func_L01_004561E0(m) == 0 && m->b[0x20] != 0xE && func_00382468(0x1E) != 0) {
            if (m->b[0x21] != 0xFF) {
                func_L01_00445BE0(m->b[0x21], 0);
            }
            func_L01_004450F0(m, 6, 1);
            if (m->b[0x43] != 8) {
                func_003C3A10(m, 8, 0, ((func_00382498(6, 0xA) * 5 + 2) / 6 * 5 + 2) / 6);
            }
            pv->i[0x2E0 / 4] = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
        }
        if (D_001D545C == 0x1D && pv->i[0x418 / 4] != 0) {
            if (pv->i[0x414 / 4] != -1 && D_L01_001DFC4C->recs[pv->i[0x414 / 4]].n12 != 0) {
                if (m->b[0x43] != 8) {
                    func_003C3A10(m, 8, 0, 8);
                }
                func_L01_004450F0(m, 0xB, 3);
            }
        }
        break;
    case 3:
        if (func_L01_004561E0(m) != 0 && pv->i[0x3B4 / 4] == 0 && pv->h[0x2E6 / 2] == 0) {
            if (D_001D545C == 0x1D) {
                pv->i[0x2EC / 4] = -1;
            }
            pv->h[0x2E6 / 2] = (func_00382498(0, 0x28) * 5 + 2) / 6;
        }
        if (pv->h[0x234 / 2] == 1 && func_0038CB00(&pv->h[0x2E6 / 2]) != 0
            && (D_001D545C != 0x1D || pv->i[0x418 / 4] == 0)) {
            if (m->b[0x43] != 8) {
                func_003C3A10(m, 8, 0, (func_00382498(6, 0xA) * 5 + 2) / 6);
            }
            func_L01_004450F0(m, 7, 2);
            if (pv->i[0x2EC / 4] != -1) {
                func_L01_004450F0(m, 9, -1);
                if (m->b[0x43] != 8) {
                    func_003C3A10(m, 8, 0, 8);
                }
            } else if (pv->i[0x3B0 / 4] != -1) {
                func_L01_004450F0(m, 0xA, -1);
            } else if (pv->i[0x3D0 / 4] != -1 && D_L01_001DFC4C->recs[pv->i[0x3D0 / 4]].n12 != 0) {
                func_L01_004450F0(m, 0xB, -1);
            }
        }
        break;
    case 4: {
        s32 r = func_L01_00454370(m, &pv->b[0x160]);
        if (D_001D545C == 1 && m->h[0xB2 / 2] == 0x65 && pv->f[0x1E8 / 4] > 0.1f) {
            pv->f[0x1E8 / 4] = 0.1f;
        }
        if (pv->f[0x30 / 4] <= 0.0f || (r & 1)) {
            if (m->b[0x21] != 0xFF) {
                func_L01_00445BE0(m->b[0x21], 0);
            }
            func_L01_003A3F68(m);
            func_003C2F58(m, 4, &s9);
            s9.z += 1.0f;
            func_L01_003303B8(&s9, 0, 0x19, 0x14, 0x14, 0x14, 0x14, 0, 1.25f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_003A3EC8(m, 1);
            return;
        }
        if (r & 2) {
            if (pv->h[0x234 / 2] == 1) {
                if (pv->i[0x3D4 / 4] != -1 && func_00382380(&m->q[1], pv->i[0x3D4 / 4], 0) == 0) {
                    pv->i[0x3B0 / 4] = -1;
                }
                if (m->b[0x43] != 8) {
                    func_003C3A10(m, 8, 0, 8);
                }
                func_L01_004450F0(m, 7, 2);
                if (pv->i[0x3B0 / 4] != -1) {
                    func_L01_004450F0(m, 0xA, -1);
                } else if (pv->i[0x3D0 / 4] != -1 && D_L01_001DFC4C->recs[pv->i[0x3D0 / 4]].n12 != 0) {
                    func_L01_004450F0(m, 0xB, -1);
                }
                if (D_001D545C == 0x1A && pv->i[0x2EC / 4] != -1) {
                    func_L01_004450F0(m, 9, -1);
                    if (m->b[0x43] != 8) {
                        func_003C3A10(m, 8, 0, 8);
                    }
                }
            } else {
                func_L01_004450F0(m, 2, 1);
                if (m->b[0x43] != 0) {
                    func_003C3A10(m, 0, 0, 0);
                }
                if (pv->i[0x2F8 / 4] != -1) {
                    func_L01_004450F0(m, 4, -1);
                    if (m->b[0x43] != 8) {
                        func_003C3A10(m, 8, 0, 0);
                    }
                }
                pv->i[0x2E0 / 4] = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    }
    case 6:
    case 7:
    case 8:
        break;
    }

    switch (m->b[0x20]) {
    case 1:
        break;
    case 2:
        if ((m->b[0x60] & 2) && (pv->i[0x3A8 / 4] == 0 || pv->i[0x2F8 / 4] != -1)) {
            func_L01_004450F0(m, 3, -1);
            if (m->b[0x43] != 8) {
                func_003C3A10(m, 8, 0, 8);
            }
            if (pv->i[0x2F8 / 4] != -1) {
                s32 *path = D_L01_0021F6C0[pv->i[0x2F8 / 4]];
                f32 d = func_0038CF38(&m->q[1], path + 4);
                if (func_0038CF38(&m->q[1], path + path[0] * 4) < d) {
                    func_L01_0045C150(m, path, 0, path[0] - 1);
                } else {
                    func_L01_0045C150(m, path, path[0] - 1, 0);
                }
                func_L01_004450F0(m, 4, -1);
            }
        }
        break;
    case 4:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, 0.0112000005f, 0.120000005f, 0.0201061945f, 0.50265485f);
        }
        if (func_L01_0045BDE8(m, pv->i[0x2F8 / 4]) != 0) {
            if (m->b[0x43] != 2) {
                func_003C3A10(m, 2, 0, 0xC);
            }
            func_L01_004450F0(m, 2, -1);
        }
        break;
    case 3: {
        if (func_L01_004561B8(m) != 0) {
            f32 a = func_00382538();
            f32 r = func_003824E0(6.0f, 9.0f);
            qzero(&pv->b[0x390]);
            pv->f[0x390 / 4] = func_0038D098(a) * r;
            pv->f[0x394 / 4] = func_0038D0B0(a) * r;
            vec_add_ab(&pv->b[0x390], &pv->b[0x390], &pv->b[0x380]);
            if (pv->i[0x2FC / 4] != -1 && func_L01_00456500(&pv->b[0x390], pv->i[0x2FC / 4]) == 0) {
                pv->q[0x390 / 16] = pv->q[0x380 / 16];
            }
            pv->i[0x3A4 / 4] = func_00382498(0x190, 0x212);
            func_L01_0045BD78(m, 0.0112000005f, 0.120000005f, 0.0201061945f, 0.50265485f);
        }
        func_L01_0045A898(m, &pv->b[0x390], m->f[0xF8 / 4]);
        func_L01_00448890(&m->f[0xF8 / 4], func_0038D160(pv->f[0x390 / 4] - m->f[0x10 / 4], pv->f[0x394 / 4] - m->f[0x14 / 4]), 0.00418879045f, 0.00251327432f, 0.125663713f, &pv->b[0x3A0], 0);
        if (func_0038CF38(&m->q[1], &pv->b[0x390]) < 0.75f) {
            f32 a = func_00382538();
            f32 r = func_003824E0(6.0f, 9.0f);
            qzero(&pv->b[0x390]);
            pv->f[0x390 / 4] = func_0038D098(a) * r;
            pv->f[0x394 / 4] = func_0038D0B0(a) * r;
            vec_add_ab(&pv->b[0x390], &pv->b[0x390], &pv->b[0x380]);
            if (pv->i[0x2FC / 4] != -1 && func_L01_00456500(&pv->b[0x390], pv->i[0x2FC / 4]) == 0) {
                pv->q[0x390 / 16] = pv->q[0x380 / 16];
            }
        }
        if (func_0038CAD0(&pv->b[0x3A4]) != 0) {
            if (m->b[0x43] != 2) {
                func_003C3A10(m, 2, 0, 0xC);
            }
            func_L01_004450F0(m, 2, -1);
        }
        break;
    }
    case 6:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, 0.0112000005f, 0.120000005f, 0.0201061945f, 0.50265485f);
        }
        func_L01_0045A748(m, &pv->b[0x380]);
        if (func_0038CF38(&m->q[1], &pv->b[0x380]) < 0.75f) {
            func_L01_004450F0(m, 2, -1);
            if (m->b[0x43] != 1) {
                func_003C3A10(m, 1, 0, 8);
            }
        }
        break;
    case 9:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, 0.0112000005f, 0.120000005f, 0.0201061945f, 0.50265485f);
        }
        if (func_L01_0045BDE8(m, pv->i[0x2EC / 4]) != 0
            || (func_0038CF38(&m->q[1], &pv->b[0x220]) < 8.0f && pv->i[0x3C4 / 4] == 0)) {
            if (D_001D545C == 0x1A) {
                pv->i[0x2EC / 4] = -1;
            }
            func_L01_004450F0(m, 7, -1);
            if (pv->i[0x3B0 / 4] != -1) {
                func_L01_004450F0(m, 0xA, -1);
            } else if (pv->i[0x3D0 / 4] != -1 && D_L01_001DFC4C->recs[pv->i[0x3D0 / 4]].n12 != 0) {
                func_L01_004450F0(m, 0xB, -1);
            }
        }
        break;
    case 10: {
        u8 *t = D_L01_001E0100 + (pv->i[0x3B0 / 4] << 7);
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, 0.0112000005f, 0.120000005f, 0.0201061945f, 0.50265485f);
            *(u128_t *)&s9 = *(u128_t *)(t + 0x30);
            func_L01_004591B8(m, &s9, &pv->b[0x430]);
        }
        if (func_0038CF38(&m->q[1], t + 0x30) < 0.5f) {
            goto face;
        }
    walk:
        func_L01_00458F78(m, &pv->b[0x430], 0, 0);
        func_L01_0045A748(m, &pv->b[0x430]);
        goto count;
    }
    case 11: {
        if (func_L01_004561B8(m) != 0) {
            u8 *dst;
            s32 k1;
            s32 k2;
            func_L01_0045BD78(m, 0.0112000005f, 0.120000005f, 0.0201061945f, 0.50265485f);
            if (m->b[0x95] == 3) {
                *(u128_t *)&pv->b[0x3E0] = *(u128_t *)(D_L01_001E0100 + (*D_L01_001DFC4C->recs[pv->i[0x414 / 4]].list20 << 7) + 0x30);
                dst = &pv->b[0x430];
                for (k1 = 0; k1 < D_L01_001DFC4C->recs[pv->i[0x414 / 4]].n12; k1++) {
                    u8 *t = D_L01_001E0100 + (D_L01_001DFC4C->recs[pv->i[0x414 / 4]].list20[k1] << 7);
                    f32 d = func_0038CF38(t + 0x30, &pv->b[0x220]);
                    if ((func_0038CF38(&pv->b[0x3E0], &pv->b[0x220]) < d || func_0038CF38((u8 *)&m->q[1], &pv->b[0x3E0]) < 2.0f)
                        && func_0038CF38((u8 *)&m->q[1], t + 0x30) > 2.0f) {
                        *(u128_t *)&pv->b[0x3E0] = *(u128_t *)(t + 0x30);
                    }
                }
            } else {
                dst = &pv->b[0x430];
                if (pv->i[0x3D0 / 4] != -1) {
                    s32 o = pv->i[0x3D0 / 4] * 0x30;
                    if (*(s16 *)((u8 *)D_L01_001DFC4C + o + 0x32) != 0) {
                    *(u128_t *)&pv->b[0x3E0] = *(u128_t *)(D_L01_001E0100 + (**(s32 **)((u8 *)D_L01_001DFC4C + o + 0x40) << 7) + 0x30);
                    for (k2 = 0; k2 < D_L01_001DFC4C->recs[pv->i[0x3D0 / 4]].n12; k2++) {
                        u8 *t = D_L01_001E0100 + (D_L01_001DFC4C->recs[pv->i[0x3D0 / 4]].list20[k2] << 7);
                        f32 d = func_0038CF38(t + 0x30, &pv->b[0x220]);
                        if ((func_0038CF38(&pv->b[0x3E0], &pv->b[0x220]) < d || func_0038CF38((u8 *)&m->q[1], &pv->b[0x3E0]) < 2.0f)
                            && func_0038CF38((u8 *)&m->q[1], t + 0x30) > 2.0f) {
                            *(u128_t *)&pv->b[0x3E0] = *(u128_t *)(t + 0x30);
                        }
                    }
                    }
                }
            }
            *(u128_t *)&s9 = pv->q[0x3E0 / 16];
            func_L01_004591B8(m, &s9, dst);
        }
        if (!(func_0038CF38((u8 *)&m->q[1], &pv->b[0x3E0]) < 1.0f)) {
            goto walk;
        }
    }
    face:
        func_L01_0045BD10(m, func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4]));
        if (func_0038DBA0(m->f[0xF8 / 4], func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4])) < 0.279252678f) {
            func_L01_004450F0(m, 0xC, -1);
            if (m->b[0x43] != 3) {
                func_003C3A10(m, 3, 0, (func_00382498(0xA, 0xF) * 5 + 2) / 6);
            }
        }
        break;
    case 8: {
        f32 d;
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, 0.0112000005f, 0.120000005f, 0.0201061945f, 0.50265485f);
        }
        *(u128_t *)&s9 = 0;
        s9.x = 478.410004f;
        s9.y = 888.0f;
        s9.z = 117.169998f;
        s9.w = 1.0f;
        if (D_001D545C == 4 && func_0038CF00(&s9, &m->q[1]) < 20.0f && func_0038CF00(&s9, D_001A4C60) < 20.0f) {
            func_L01_004450F0(m, 0xC, -1);
            if (m->b[0x43] != 3) {
                func_003C3A10(m, 3, 0, 0xC);
            }
            break;
        }
        func_L01_0045A748(m, &pv->b[0x220]);
        d = func_L01_004395E0(m);
        if (d > 15.0f && d < 33.0f && m->b[0x42] == 8) {
            func_L01_004468C8(m, 0.5f, 1.0f, 1.0f, 0, x, 0, 1, 0);
        }
        if (d > 45.0f && m->b[0x42] == 8) {
            func_L01_004468C8(m, 0.5f, 1.0f, 1.0f, 1, x, 0, 1, 0);
        }
        if (func_0038CF38(&m->q[1], &pv->b[0x220]) < 10.0f
            && func_0038DBA0(m->f[0xF8 / 4], func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4])) < 0.279252678f) {
            func_L01_004450F0(m, 0xC, -1);
            if (m->b[0x43] != 3) {
                func_003C3A10(m, 3, 0, 0xC);
            }
        }
        if (pv->i[0xF0 / 4] >= 4) {
            func_L01_004450F0(m, 0xC, -1);
            if (m->b[0x43] != 3) {
                func_003C3A10(m, 3, 0, 0xC);
            }
            break;
        }
        break;
    }
    case 7: {
        f32 d;
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, 0.0112000005f, 0.120000005f, 0.0201061945f, 0.50265485f);
            func_L01_00459188(m, pv->ptr[0x230 / 4], &pv->b[0x430]);
        }
        *(u128_t *)&s9 = 0;
        s9.x = 478.410004f;
        s9.y = 888.0f;
        s9.z = 117.169998f;
        s9.w = 1.0f;
        if (D_001D545C == 4 && func_0038CF00(&s9, &m->q[1]) < 20.0f && func_0038CF00(&s9, D_001A4C60) < 20.0f) {
            func_L01_004450F0(m, 0xC, -1);
            if (m->b[0x43] != 3) {
                func_003C3A10(m, 3, 0, 0xC);
            }
            break;
        }
        func_L01_00458F78(m, &pv->b[0x430], 0, 0);
        func_L01_0045A748(m, &pv->b[0x430]);
        if (pv->ptr[0x480 / 4] != pv->ptr[0x230 / 4]) {
            func_L01_00459188(m, pv->ptr[0x230 / 4], &pv->b[0x430]);
        }
        d = func_L01_004395E0(m);
        if (d > 7.0f && d < 12.0f && m->b[0x42] == 8) {
            func_L01_004468C8(m, 0.5f, 1.0f, 1.0f, 0, x, 0, 1, 0);
        }
        if (d > 15.0f && m->b[0x42] == 8) {
            func_L01_004468C8(m, 0.5f, 1.0f, 1.0f, 1, x, 0, 1, 0);
        }
        if (func_0038CF38(&m->q[1], &pv->b[0x220]) < 10.0f
            && func_0038DBA0(m->f[0xF8 / 4], func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4])) < 0.279252678f) {
            func_L01_004450F0(m, 0xC, -1);
            if (m->b[0x43] != 3) {
                func_003C3A10(m, 3, 0, 8);
            }
        }
        if (pv->i[0xF0 / 4] >= 4) {
            func_L01_004450F0(m, 0xC, -1);
            if (m->b[0x43] != 3) {
                func_003C3A10(m, 3, 0, 0xC);
            }
        }
    count:
        if (pv->f[0x120 / 4] < pv->f[0x98 / 4] * 0.8f) {
            pv->i[0x470 / 4]++;
        }
        break;
    }
    case 12: {
        if (func_L01_004561B8(m) != 0) {
            s32 done;
            if (m->b[0x21] == 0xFF) {
                done = 1;
            } else {
                done = m->b[0xBC] == 0;
            }
            if (!done) {
                if (m->b[0x43] != 0) {
                    func_003C3A10(m, 0, 0, 8);
                }
                func_L01_004450F0(m, 0xD, -1);
            } else if (m->b[0x21] != 0xFF) {
                func_L01_00445BE0(m->b[0x21], 1);
            }
        }
        if (m->b[0x42] == 3) {
            m->f[0x48 / 4] = func_003824E0(0.8f, 0.899999976f);
            if (func_L01_004395E0(m) >= 12.0f) {
                u32 c1 = 0x202080;
                u32 c2 = 0x2040DD;
                s32 k;
                if (pv->i[0x3C0 / 4] != 0 && D_001D545C == 1) {
                    c1 = 0x208020;
                    c2 = 0x20DD40;
                }
                func_003C2F58(m, 2, &s9);
                for (k = 0; k < 2; k++) {
                    u8 *r;
                    func_00382580(&sA, 0.100000009f, 0.140000015f);
                    if (sA.z < 0.0f) {
                        sA.z = -sA.z;
                    }
                    r = func_L01_004713C8(&s9, &sA, 8, c1, (s32)func_L01_00443A18(2.0f, 5.0f), 0x7F, 0x7F, 6,
                                          func_003824E0(0.8f, 1.25f) * 210000.0f, 2100.0f, 0.00584000023f);
                    if (r != 0) {
                        r[2] = *D_L01_00221098[0xD4 / 4];
                    }
                    r = func_L01_004713C8(&s9, &sA, 8, c2, (s32)func_L01_00443A18(2.0f, 5.0f), 0x30, 0x30, 0,
                                          func_003824E0(0.8f, 1.25f) * 210000.0f * 3.0f, 4200.0f, 0.00584000023f);
                    if (r != 0) {
                        r[2] = *D_L01_00221098[0xD4 / 4];
                    }
                }
                func_003C2F58(m, 3, &s9);
                for (k = 0; k < 2; k++) {
                    u8 *r;
                    func_00382580(&sA, 0.100000009f, 0.140000015f);
                    if (sA.z < 0.0f) {
                        sA.z = -sA.z;
                    }
                    r = func_L01_004713C8(&s9, &sA, 8, c1, (s32)func_L01_00443A18(2.0f, 5.0f), 0x7F, 0x7F, 6,
                                          func_003824E0(0.8f, 1.25f) * 210000.0f, 2100.0f, 0.00584000023f);
                    if (r != 0) {
                        r[2] = *D_L01_00221098[0xD4 / 4];
                    }
                    r = func_L01_004713C8(&s9, &sA, 8, c2, (s32)func_L01_00443A18(2.0f, 5.0f), 0x30, 0x30, 0,
                                          func_003824E0(0.8f, 1.25f) * 210000.0f * 3.0f, 4200.0f, 0.00584000023f);
                    if (r != 0) {
                        r[2] = *D_L01_00221098[0xD4 / 4];
                    }
                }
            }
        }
        if (m->b[0x60] & 2) {
            m->f[0x48 / 4] = 1.0f;
            func_L01_004450F0(m, 0xE, -1);
            if (m->b[0x43] != 4) {
                func_003C3A10(m, 4, 0, ((func_00382498(2, 6) * 5 + 2) / 6 * 5 + 2) / 6);
            }
            pv->ptr[0x3DC / 4] = pv->ptr[0x230 / 4];
        }
        func_L01_0045A9F0(m);
        break;
    }
    case 13: {
        s32 done;
        if (m->b[0x21] == 0xFF) {
            done = 1;
        } else {
            done = m->b[0xBC] == 0;
        }
        if (done) {
            func_L01_004450F0(m, 0xC, -1);
            if (m->b[0x43] != 3) {
                func_003C3A10(m, 3, 0, 5);
            }
        }
        func_L01_0045A9F0(m);
        break;
    }
    case 14:
        if (m->b[0x42] == 4) {
            Obj *tg = (Obj *)pv->ptr[0x3DC / 4];
            f32 a = func_0038DB00(func_0038D160(tg->f[0x10 / 4] - m->f[0x10 / 4], tg->f[0x14 / 4] - m->f[0x14 / 4]), m->f[0xF8 / 4]);
            u32 c1;
            u32 c2;
            if (m->uh[0x34 / 2] & 0x8000) {
                a = -a;
            }
            pv->f[0x368 / 4] = a;
            if (func_L01_0044E1B8(m, 31.0f) != 0) {
                if (m->b[0x21] != 0xFF) {
                    func_L01_00445BE0(m->b[0x21], 0);
                }
                func_003C2F58(m, 2, &s9);
                if ((u8 *)pv->ptr[0x3DC / 4] == D_001A4BE0.ptr[0x25C0 / 4]) {
                    vec_sub_ab(&sA, D_001A4BE0.b + 0xD0, &s9);
                    if (pv->i[0x3C0 / 4] != 0) {
                        sA.z -= 4.0f;
                    }
                } else {
                    Obj *o;
                    *(u128_t *)&sB = ((Obj *)pv->ptr[0x3DC / 4])->q[1];
                    o = func_00382348(pv->ptr[0x3DC / 4]);
                    if (o != 0) {
                        sB.z += o->f[0x10 / 4];
                    } else {
                        sB.z += 0.5f;
                    }
                    vec_sub_ab(&sA, &sB, &s9);
                }
                if (sA.z > 1.13446403f) {
                    sA.z = 1.13446403f;
                }
                func_0038CF68(&sA, &sA, 1.00000012f);
                if (pv->i[0x3C0 / 4] != 0) {
                    func_0038CF68(&sA, &sA, 0.3f);
                }
                func_L01_003A8CF0(m, &s9, &D_L01_001D66B0, 1.0f);
                pv->i[0x2F0 / 4] = func_L01_003AA018(m, &sA, &s9, pv->i[0x3C0 / 4], (f32)pv->b[0x44]);
            }
            c1 = 0x202080;
            c2 = 0x2040DD;
            if (pv->i[0x3C0 / 4] != 0 && D_001D545C == 1) {
                c1 = 0x208020;
                c2 = 0x20DD40;
            }
            if (func_L01_004395E0(m) < 31.0f || m->b[0x42] != 4) {
                s32 k;
                func_003C2F58(m, 2, &s9);
                for (k = 0; k < 2; k++) {
                    u8 *r;
                    func_00382580(&sA, 0.100000009f, 0.140000015f);
                    if (sA.z < 0.0f) {
                        sA.z = -sA.z;
                    }
                    r = func_L01_004713C8(&s9, &sA, 8, c1, (s32)func_L01_00443A18(2.0f, 5.0f), 0x7F, 0x7F, 6,
                                          func_003824E0(0.8f, 1.25f) * 210000.0f, 2100.0f, 0.00584000023f);
                    if (r != 0) {
                        r[2] = *D_L01_00221098[0xD4 / 4];
                    }
                    r = func_L01_004713C8(&s9, &sA, 8, c2, (s32)func_L01_00443A18(2.0f, 5.0f), 0x30, 0x30, 0,
                                          func_003824E0(0.8f, 1.25f) * 210000.0f * 3.0f, 4200.0f, 0.00584000023f);
                    if (r != 0) {
                        r[2] = *D_L01_00221098[0xD4 / 4];
                    }
                }
            }
            if (func_L01_0044E1B8(m, 1.0f) != 0) {
                func_003C2F58(m, 3, &s9);
                if ((u8 *)pv->ptr[0x3DC / 4] == D_001A4BE0.ptr[0x25C0 / 4]) {
                    vec_sub_ab(&sA, D_001A4BE0.b + 0xD0, &s9);
                    if (pv->i[0x3C0 / 4] != 0) {
                        sA.z -= 4.0f;
                    }
                } else {
                    Obj *o;
                    *(u128_t *)&sB = ((Obj *)pv->ptr[0x3DC / 4])->q[1];
                    o = func_00382348(pv->ptr[0x3DC / 4]);
                    if (o != 0) {
                        sB.z += o->f[0x10 / 4];
                    } else {
                        sB.z += 0.5f;
                    }
                    vec_sub_ab(&sA, &sB, &s9);
                }
                func_0038CF68(&sA, &sA, 1.00000012f);
                if (pv->i[0x3C0 / 4] != 0) {
                    func_0038CF68(&sA, &sA, 0.3f);
                }
                func_L01_003A8CF0(m, &s9, &D_L01_001D66B0, 1.0f);
                pv->i[0x2F4 / 4] = func_L01_003AA018(m, &sA, &s9, pv->i[0x3C0 / 4], (f32)pv->b[0x44]);
            }
            if (m->b[0x42] != 4) {
                s32 k;
                func_003C2F58(m, 3, &s9);
                for (k = 0; k < 2; k++) {
                    u8 *r;
                    func_00382580(&sA, 0.100000009f, 0.140000015f);
                    if (sA.z < 0.0f) {
                        sA.z = -sA.z;
                    }
                    r = func_L01_004713C8(&s9, &sA, 8, 0x202080, (s32)func_L01_00443A18(2.0f, 5.0f), 0x7F, 0x7F, 6,
                                          func_003824E0(0.8f, 1.25f) * 210000.0f, 2100.0f, 0.00584000023f);
                    if (r != 0) {
                        r[2] = *D_L01_00221098[0xD4 / 4];
                    }
                    r = func_L01_004713C8(&s9, &sA, 8, 0x2040DD, (s32)func_L01_00443A18(2.0f, 5.0f), 0x30, 0x30, 0,
                                          func_003824E0(0.8f, 1.25f) * 210000.0f * 3.0f, 4200.0f, 0.00584000023f);
                    if (r != 0) {
                        r[2] = *D_L01_00221098[0xD4 / 4];
                    }
                }
            }
            if (m->b[0x60] & 2) {
                if (pv->i[0x3B0 / 4] == -1 || (pv->b[0x5F] != 0 && D_001D545C == 9)) {
                    func_L01_004450F0(m, 8, -1);
                    if (m->b[0x43] != 8) {
                        func_003C3A10(m, 8, 0, 8);
                    }
                } else if (func_0038CF38(&m->q[1], D_L01_001E0100 + (pv->i[0x3B0 / 4] << 7) + 0x30) < 0.5f) {
                    func_L01_0045BD10(m, func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4]));
                    if (func_0038DBA0(m->f[0xF8 / 4], func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4])) < 0.279252678f) {
                        func_L01_004450F0(m, 0xC, -1);
                        if (m->b[0x43] != 3) {
                            func_003C3A10(m, 3, 0, (func_00382498(0x12, 0x17) * 5 + 2) / 6);
                        }
                    }
                } else {
                    func_L01_004450F0(m, 0xA, -1);
                    if (m->b[0x43] != 8) {
                        func_003C3A10(m, 8, 0, 8);
                    }
                }
                if (pv->i[0x3D0 / 4] != -1 && D_L01_001DFC4C->recs[pv->i[0x3D0 / 4]].n12 != 0
                    && !(pv->b[0x5F] != 0 && D_001D545C == 9)) {
                    if (m->b[0x43] != 8) {
                        func_003C3A10(m, 8, 0, 8);
                    }
                    func_L01_004450F0(m, 0xB, -1);
                }
                if (m->b[0x95] == 3) {
                    if (m->b[0x43] != 8) {
                        func_003C3A10(m, 8, 0, 8);
                    }
                    func_L01_004450F0(m, 0xB, -1);
                }
            }
        }
        func_L01_0045A9F0(m);
        break;
    case 17: {
        Obj *q = (Obj *)m->ptr[0x68 / 4];
        f32 s;
        if (func_L01_004561B8(m) != 0) {
            q->f[0x1B8 / 4] = 2.0f;
            q->f[0x1BC / 4] = 2.0f;
        }
        if (q->f[0x3BC / 4] < 1.0f) {
            q->f[0x3BC / 4] += D_L01_001DE268 * 0.020000001f;
            if (q->f[0x3BC / 4] > 1.0f) {
                q->f[0x3BC / 4] = 1.0f;
            }
            m->f[0x2C / 4] = ((Obj *)m->ptr[0x24 / 4])->f[0x24 / 4] * q->f[0x3BC / 4];
        }
        if (m->b[0x23] < 0x7F) {
            m->b[0x23] += (s32)(D_L01_001DE274 * 0.020000001f * 127.0f);
            if (m->c[0x23] < 0) {
                m->b[0x23] = 0x7F;
            }
            if (m->b[0x23] == 0x7F) {
                m->uh[0x34 / 2] &= 0xF7FF;
            }
        }
        s = q->f[0x118 / 4];
        q->f[0x118 / 4] = 0.0f;
        q->f[0x120 / 4] *= (D_L01_001DE26C - 1.0f) * 1.2f + 1.0f;
        func_0038CF68(&q->b[0x110], &q->b[0x110], q->f[0x120 / 4]);
        q->f[0x118 / 4] = s;
        q->f[0x9C / 4] = 0.008f;
        if (D_L01_001DE270 * 0.020000001f < s) {
            q->f[0x9C / 4] = 0.002f;
        }
        if (q->ptr[0x3B8 / 4] != 0 && ((Obj *)q->ptr[0x3B8 / 4])->ptr[0x24 / 4] != 0) {
            ((Obj *)q->ptr[0x3B8 / 4])->i[0x98 / 4] = 0;
        }
        if (func_L01_0045C2A0(m, D_L01_001DE250, D_L01_001DE254, D_L01_001DE258) != 0) {
            func_003A52A0(0xC, 0, m);
            m->f[0x48 / 4] = 1.0f;
            func_L01_0045A9F0(m);
            q->f[0x1BC / 4] = 0.75f;
            q->f[0x1B8 / 4] = 0.2f;
            q->f[0x9C / 4] = 0.00392f;
            func_L01_004450F0(m, 2, 0);
            if (m->b[0x43] != 0) {
                func_003C3A10(m, 0, 0, 0);
            }
            if (q->i[0x2F8 / 4] != -1) {
                func_L01_004450F0(m, 4, -1);
                if (m->b[0x43] != 8) {
                    func_003C3A10(m, 8, 0, 0);
                }
            }
        } else if (D_L01_001DE258 < func_L01_004395E0(m)) {
            q->f[0x1BC / 4] = 0.75f;
            q->f[0x1B8 / 4] = 0.2f;
        }
        if (q->ptr[0x3B8 / 4] != 0) {
            Obj *c = (Obj *)((Obj *)q->ptr[0x3B8 / 4])->ptr[0x24 / 4];
            if (c != 0) {
                ((Obj *)q->ptr[0x3B8 / 4])->i[0x98 / 4] = c->i[0x10 / 4];
            }
        }
        break;
    }
    case 18:
        break;
    }
    func_L01_003A4180(m);
}
