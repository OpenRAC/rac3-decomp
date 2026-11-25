/* func_L02_003A0EE8 (level 02, switch with a jump table): near miss, 60 raw differences of 1294 words (same length as retail) with --flags=-mvu0-use-vf0-vf2 on the file's line (the file's text_parts row lacks -mvu0-use-vf0-vf2; a landing needs that row change), round 27 W28.
   Start: W22's draft (856 raw). New in this version (see D:\Projects\UYA Decomp Data\sonnet-b41-w28-findings.md):
   - `j` and the loop pointer are declared per state inside the `if (n != 0) {` block, `hit` stays function-level with `hit = 1` stored in both f1DC arms (global-alloc priority: hit gets the lowest of $s5/$s6/$s7 like retail);
   - the loop reads `D_L02_001EC0C0[j]` (no `tab` pointer): loop.c strength-reduces it with the giv init in the loop preheader after the blez guard, j reversed to the count-down (retail's `blez; lui; addiu s7; move s6,a1` and the nop in beqz's slot);
   - D_L02_001E8058 is an unsized array read as [0] (not $gp, like retail); state 3's calls take the float argument inline like state 2; 0.060000002f;
   - D_001D545C sites 1 and 3 read `D_001D545C_big[0]` (unsized/sized array: split lui/lw).
   Still differs (62 raw): (a) the 4 D_001D545C reads (the whole remaining diff but 4 lines; tried: two-call form (sched2 does not merge the tails, 925), callee parameter order f/tp, &tmp instead of tp, float local, hint on a scalar; the move is before the branch in retail's RTL: reorg takes a preceding insn, and the function has no sched1 regions (jump table = nonregular cfg), so no source form found): retail has `move $a3,$s2` in the beqz delay slot and `lui $v0; lw $v0,0x545c($v0)` after it (one scheduling unit: gcc's 1-insn $gp load of a 4-byte extern assembled as macro with `.extern X, 16`; the assembler turns it back to $gp when gcc puts the load into a delay slot, `.set nomacro`), ours has the lui in the slot and `move $a3` after the join; (b) `por $a0,$zero,$zero` + `sq $a0,0x30($sp)` where retail uses $v0 (states 3 and 4); (c) none left in state 4: the k loop is `for (k = 0; k < 20; k++)` (loop.c reverses it, init after the hoisted `addiu $s1,$sp,0x10` like retail). */
/* localdecomp:start func_L02_003A0EE8 */
#include "vu0.h"
extern s32 D_L02_001D5458_003A0EE8[4];
__asm__(".extern D_L02_001D5458_003A0EE8, 16");
extern s32 D_001D545C_big[4];

typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A0EE8;
typedef struct {
    s32 f0;
    u8 f4;
    u8 f5;
    s16 f6;
    f32 f8;
    s32 fC;
    V4_3A0EE8 v;
    s32 t20;
    f32 f24;
    f32 f28;
    s16 f2C;
    s16 f2E;
} Vars_3A0EE8;
typedef struct Self_3A0EE8 {
    u8 pad0[0x10];
    V4_3A0EE8 pos;
    u8 state;
    u8 pad21[3];
    struct { u8 pad[0x10]; s32 f10; } *f24;
    u8 pad28[0x40];
    Vars_3A0EE8 *vars;
    u8 pad6C[0x2C];
    s32 f98;
    u8 pad9C[0xE];
    u16 fAA;
    u8 padAC[0x44];
    f32 fF0;
    u8 padF4[4];
    f32 fF8;
} Self_3A0EE8;
typedef struct { u8 pad0[0x18]; u8 f18; u8 f19; u16 f1A; u8 pad1C[4]; } Info_3A0EE8;
typedef struct {
    u8 pad0[0x1DC]; s16 f1DC; u8 pad1DE[0x15E]; f32 f33C; u8 pad340[0x2E]; s16 f36E;
    u8 pad370[0x2250]; s32 f25C0; s32 f25C4; u8 pad25C8[0x288]; s32 f2850;
} G_3A0EE8;
typedef struct { u8 pad[0x20]; f32 f20; u8 pad24[4]; s32 f28; s32 f2C; } T_3A0EE8;
typedef struct { u8 pad[0xAA]; s16 fAA; } Obj_3A0EE8;
typedef union { V4_3A0EE8 v[2]; Info_3A0EE8 i; } A_3A0EE8;

struct O_3A2320;
extern void func_L02_003A2320(struct O_3A2320 *);
extern s32 func_L01_00456500(void *, s32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CB00(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_0040E790(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_004471A8(void *, f32);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446748(void *, void *, s32, f32);
extern void func_L01_00446978(void *, void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_003A4F28(s32);
extern s32 func_L01_004AA710(void *, s32);
extern void func_003C4C18(void *, f32);
extern void *func_L01_003016B0(void *, s32, f32, f32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *func_L01_00468A68(void *, void *, s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);

extern u8 D_001A4C60[];
extern u8 D_001A30B0[];
extern G_3A0EE8 D_001A4BE0;
extern V4_3A0EE8 D_L02_001E8040[];
extern T_3A0EE8 D_L02_001E1300;
extern Obj_3A0EE8 *D_L02_001E8058[];
extern Obj_3A0EE8 *D_L02_001EC0C0[];
extern f32 D_L02_002EF1F0[];
extern u8 *D_L02_0021E0D8[];
extern s32 D_001D545C_sda;

void func_L02_003A0EE8(Self_3A0EE8 *self) {
    Vars_3A0EE8 *v;
    V4_3A0EE8 prev;
    A_3A0EE8 a;
    V4_3A0EE8 pos2;
    V4_3A0EE8 tmp;
    u8 *rr;
    f32 f;
    f32 d;
    s32 i;
    s32 n;
    s32 hit;
    s32 mode;
    s32 cnt;
    s32 k;

    func_L02_003A2320((struct O_3A2320 *)self);
    v = self->vars;
    switch (self->state) {
    case 1:
        if (v->f0 != -1 && func_L01_00456500(D_001A4C60, v->f0) != 0) {
            self->state = 2;
        }
        break;
    case 2:
        prev = self->pos;
        v->v.z -= v->f8;
        vec_add_ab(&self->pos, &self->pos, &v->v);
        self->fF0 = func_0038DAB8(self->fF0, v->f28);
        if (v->f6 == 1) self->fF8 = 2.3561945f;
        if (self->pos.x < 2.0f || self->pos.x > 1021.0f || self->pos.y < 2.0f || self->pos.y > 1021.0f
            || self->pos.z < 2.0f || self->pos.z > 1021.0f) {
            self->state = 5;
        }
        if (func_0038CB00(&v->f2C) != 0
            && (func_003D3CB0(&prev, &self->pos, 2, self, 0) != 0
                || func_L01_003FB640(&self->pos, 2, self, v->f24) != 0)) {
            V4_3A0EE8 *contact;
            if (v->f4 != 0) {
                func_L01_0040E790(&v->v, &v->v, &D_L02_001E8040[4]);
                v->f28 = func_0038CEA8(&v->v);
            } else {
                func_L01_0040E790(&v->v, &v->v, &D_L02_001E8040[4]);
                v->v.z *= 0.7f;
                v->v.y *= 1.15f;
                v->v.x = 0.0f;
                v->f28 = func_0038CEA8(&v->v) * 0.6f;
                if (v->v.y < -0.120000005f) v->v.y = -0.18f;
                if (v->f28 > 1.32f) v->f28 = 1.32f;
            }
            contact = &D_L02_001E8040[2];
            a.v[0] = *contact;
            a.v[0].z += 0.15f;
            cnt = v->f2E * 6;
            for (i = 0; i < cnt; i++) {
                f32 f = func_003824E0(0.3f, 0.6f) * 210000.0f;
                u8 *rr;
                a.v[1].x = func_L01_00443A18(0.0f, 0.020000001f);
                a.v[1].y = func_L01_00443A18(0.0f, 0.020000001f);
                a.v[1].z = func_003824E0(0.25f, 0.8f) * 0.020000001f;
                pos2 = a.v[0];
                pos2.x += func_L01_00443A18(0.0f, 0.6f);
                pos2.y += func_L01_00443A18(0.0f, 0.6f);
                pos2.z += func_L01_00443A18(0.0f, 0.2f);
                rr = func_L01_0046FB40(&pos2, &a.v[1], (func_00382498(35, 60) * 5 + 2) / 6, 0x128090A0,
                                       func_00382468(2) != 0 ? 1 : -1, 0x32, 0, f, f, 0.0f, 0);
                if (rr != 0) {
                    rr[2] = D_L02_0021E0D8[23][0];
                    rr[3] = 0x44;
                }
                if (v->f4 != 0) {
                    self->state = 3;
                    v->v.z = 0.0f;
                    self->pos.z = D_L02_001E8040[2].z + 0.98f;
                    v->f8 = 0.008f;
                }
            }
            func_003A52A0(0, 0, self);
            {
            f32 dd = func_0038CF00(&self->pos, D_001A4C60);
            f32 e = ((f32)v->f2E * dd == 0.0f) ? 1.0f : 0.5f / dd;
            D_L02_001E1300.f20 = e;
            }
            D_L02_001E1300.f28 = 0x15;
            D_L02_001E1300.f2C = 0;
            if (--v->f2E == 0) self->state = 3;
        }
        func_L01_004471A8(self, v->f6 == 0 ? 0.7f : 1.1f);
        hit = 0;
        n = func_003D4D00(&self->pos, 0, self, 0, v->f6 == 0 ? 0.8f : 1.1f);
        if (n != 0) {
            s32 j;
            for (j = 0; j < n; j++) {
                V4_3A0EE8 *tp = &tmp;
                if (D_L02_001EC0C0[j]->fAA != 0x18C2) {
                    if (D_L02_001EC0C0[j]->fAA == 0) {
                        if (D_001A4BE0.f36E != 0 && D_001A4BE0.f33C > 0.5f) {
                            tmp = v->v;
                            func_0038CE20(tp, tp, 3.0f);
                            tmp.w = 5627.9248f;
                            self->f98 = self->f24->f10;
                            func_L01_00446760(&a, self, 1, tp,
                                              func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C_big[0]] : 1.0f);
                        } else if (D_001A4BE0.f25C4 != 0x91 && D_001A4BE0.f2850 != 0) {
                            if (D_001A4BE0.f1DC == 0) {
                                self->f98 = 0;
                                func_L01_00446748(&a, self, 8,
                                                  func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C_sda] : 1.0f);
                                hit = 1;
                            } else {
                                D_001A4BE0.f1DC = 0;
                                self->f98 = 0;
                                func_L01_00446748(&a, self, 8, 0.0f);
                                hit = 1;
                            }
                        }
                    } else {
                        tmp = v->v;
                        func_0038CE20(tp, tp, 3.0f);
                        tmp.w = 5627.9248f;
                        self->f98 = self->f24->f10;
                        func_L01_00446760(&a, self, 0x10000, tp,
                                          func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C_big[0]] : 1.0f);
                        hit = 1;
                    }
                    a.i.f19 = 1;
                    a.i.f1A = self->fAA;
                    a.i.f18 = 0;
                    func_L01_00446978(D_L02_001EC0C0[j], &a);
                }
            }
        }
        if (hit != 0) {
            if ((s32)D_L02_001E8058[0] != D_001A4BE0.f25C0 || D_001A4BE0.f1DC == 0) {
                func_003A52A0(2, 0, self);
            }
        }
        if ((v->f6 == 0 && self->pos.y < 248.0f) || self->pos.z <= 22.0f) {
            self->state = 4;
            if (v->fC != -1) {
                u8 *e = D_001A30B0 + (v->fC << 7);
                if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) func_003A4F28(v->fC);
            }
            v->fC = -1;
            self->f98 = self->f24->f10;
        }
        break;
    case 3:
        prev = self->pos;
        v->v.z -= v->f8;
        vec_add_ab(&self->pos, &self->pos, &v->v);
        self->fF0 = func_0038DAB8(self->fF0, v->f28);
        if (v->f6 == 1) self->fF8 = 2.3561945f;
        if (self->pos.x < 2.0f || self->pos.x > 1021.0f || self->pos.y < 2.0f || self->pos.y > 1021.0f
            || self->pos.z < 2.0f || self->pos.z > 1021.0f) {
            self->state = 5;
        }
        if (func_L01_004AA710(self, v->fC) == 0) v->fC = func_003A52A0(1, 4, self);
        if (func_0038CB00(&v->f2C) != 0
            && (func_003D3CB0(&prev, &self->pos, 2, self, 0) != 0
                || func_L01_003FB640(&self->pos, 2, self, v->f24) != 0)) {
            V4_3A0EE8 *contact;
            f32 f;
            u8 *rr;
            if (v->f4 != 0) {
                if (D_L02_001E8058[0] != 0 && D_L02_001E8058[0]->fAA == 0x18C2) {
                    self->pos.z += 0.2f;
                } else {
                    func_L01_0040E790(&v->v, &v->v, &D_L02_001E8040[4]);
                    v->f28 = func_0038CEA8(&v->v);
                    if (v->v.z > 0.0f) v->v.z = 0.0f;
                }
            } else {
                func_L01_0040E790(&v->v, &v->v, &D_L02_001E8040[4]);
                v->v.z *= 0.15999997f;
                v->v.y *= 1.18f;
                v->v.x = 0.0f;
                v->f28 = func_0038CEA8(&v->v) * 0.52f;
                if (v->v.y < -0.120000005f) v->v.y = -0.18f;
                if (v->f28 > 1.32f) v->f28 = 1.32f;
            }
            contact = &D_L02_001E8040[2];
            a.v[0] = *contact;
            func_003C4C18(&a.v[0], 0.2f);
            *(u128_t *)&pos2 = 0;
            pos2.z = func_003824E0(0.05f, 0.5f) * 0.020000001f;
            a.v[1] = pos2;
            f = func_003824E0(0.7f, 1.0f) * 210000.0f;
            rr = func_L01_0046FB40(&a.v[0], &a.v[1], (func_00382498(35, 60) * 5 + 2) / 6, 0x128090A0,
                                   func_00382468(2) != 0 ? 1 : -1, 0x32, 0, f, f, 0.0f, 0);
            if (rr != 0) {
                rr[2] = D_L02_0021E0D8[23][0];
                rr[3] = 0x44;
            }
            if (v->f4 != 0) self->pos.z = contact->z + 0.98f;
        }
        func_L01_004471A8(self, v->f6 == 0 ? 0.7f : 1.1f);
        hit = 0;
        n = func_003D4D00(&self->pos, 0, self, 0, v->f6 == 0 ? 0.8f : 1.1f);
        if (n != 0) {
            s32 j;
            for (j = 0; j < n; j++) {
                V4_3A0EE8 *tp = &tmp;
                if (D_L02_001EC0C0[j]->fAA != 0x18C2) {
                    if (D_L02_001EC0C0[j]->fAA == 0) {
                        if (D_001A4BE0.f36E != 0 && D_001A4BE0.f33C > 0.5f) {
                            tmp = v->v;
                            func_0038CE20(tp, tp, 3.0f);
                            tmp.w = 5627.9248f;
                            self->f98 = self->f24->f10;
                            func_L01_00446760(&a, self, 1, tp,
                                              func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C_big[0]] : 1.0f);
                        } else if (D_001A4BE0.f25C4 != 0x91 && D_001A4BE0.f2850 != 0) {
                            if (D_001A4BE0.f1DC == 0) {
                                self->f98 = 0;
                                func_L01_00446748(&a, self, 8,
                                                  func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C_sda] : 1.0f);
                                hit = 1;
                            } else {
                                D_001A4BE0.f1DC = 0;
                                self->f98 = 0;
                                func_L01_00446748(&a, self, 8, 0.0f);
                                hit = 1;
                            }
                        }
                    } else {
                        tmp = v->v;
                        func_0038CE20(tp, tp, 3.0f);
                        tmp.w = 5627.9248f;
                        self->f98 = self->f24->f10;
                        func_L01_00446760(&a, self, 0x10000, tp,
                                          func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C_big[0]] : 1.0f);
                        hit = 1;
                    }
                    a.i.f19 = 1;
                    a.i.f1A = self->fAA;
                    a.i.f18 = 0;
                    func_L01_00446978(D_L02_001EC0C0[j], &a);
                }
            }
        }
        if (hit != 0) {
            if ((s32)D_L02_001E8058[0] != D_001A4BE0.f25C0 || D_001A4BE0.f1DC == 0) {
                func_003A52A0(2, 0, self);
            }
        }
        if ((v->f6 == 0 && self->pos.y < 248.0f) || (d = func_003C3D30(&self->pos, 0, 0, 0.5f), self->pos.z + 20.0f < d)
            || self->pos.z <= 22.0f) {
            self->state = 4;
            if (v->fC != -1) {
                u8 *e = D_001A30B0 + (v->fC << 7);
                if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) func_003A4F28(v->fC);
            }
            v->fC = -1;
            self->f98 = self->f24->f10;
        }
        break;
    case 4:
        prev = self->pos;
        v->v.z -= v->f8;
        vec_add_ab(&self->pos, &self->pos, &v->v);
        self->fF0 = func_0038DAB8(self->fF0, v->f28);
        if (v->f6 == 1) self->fF8 = 2.3561945f;
        mode = self->pos.z <= 22.0f ? 0xB20 : 0;
        if (func_0038CB00(&v->f2C) != 0
            && (func_003D3CB0(&prev, &self->pos, mode, self, 0) != 0
                || func_L01_003FB640(&self->pos, mode, self, v->f24) != 0)) {
            f32 f;
            u8 *rr;
            func_L01_0040E790(&v->v, &v->v, &D_L02_001E8040[4]);
            v->v.x *= 0.88f;
            v->v.y *= 0.88f;
            a.v[0] = D_L02_001E8040[2];
            func_003C4C18(&a.v[0], 0.2f);
            *(u128_t *)&pos2 = 0;
            pos2.z = func_003824E0(0.05f, 0.5f) * 0.020000001f;
            a.v[1] = pos2;
            f = func_003824E0(0.3f, 1.0f) * 210000.0f;
            rr = func_L01_0046FB40(&a.v[0], &a.v[1], (func_00382498(35, 60) * 5 + 2) / 6, 0x128090A0,
                                   func_00382468(2) == 0 ? -1 : 1, 0x10, 0, f, f, 0.0f, 0);
            if (rr != 0) {
                rr[2] = D_L02_0021E0D8[23][0];
                rr[3] = 0x44;
            }
            func_003A52A0(0, 0, self);
        }
        if (v->f5 == 0) {
            if (self->pos.z < 21.0f) {
                rr = func_L01_003016B0(&self->pos, 9, v->f6 == 1 ? 2.5f : 2.0f, 1.1f);
                if (rr != 0) func_L01_0043B9E8(rr, 0x7F, 0x30, 0x1F);
                for (k = 0; k < 20; k++) {
                    f32 ang = func_00382538();
                    f32 dd = func_003824E0(0.0f, 0.060000002f);
                    u8 *r;
                    a.v[0].x = func_0038D098(ang) * dd;
                    a.v[0].y = func_0038D0B0(ang) * dd;
                    a.v[0].z = func_003824E0(0.060000002f, 0.16000001f);
                    r = func_L01_00468A68(&self->pos, &a.v[0], func_00382468(2), func_00382498(90, 120));
                    if (r != 0) r[2] = D_L02_0021E0D8[91][0];
                }
                v->f5 = 1;
            }
        }
        if (func_0038CAD0(&v->t20) != 0 || self->pos.z < 17.0f || self->pos.x < 2.0f || self->pos.x > 1021.0f
            || self->pos.y < 2.0f || self->pos.y > 1021.0f || self->pos.z < 2.0f || self->pos.z > 1021.0f) {
            self->state = 5;
        }
        break;
    case 5:
        func_003C2880(self);
        break;
    }
}
/* localdecomp:end func_L02_003A0EE8 */
