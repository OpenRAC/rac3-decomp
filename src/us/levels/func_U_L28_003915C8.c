#include "common.h"
#include "vu0.h"
#include "structs/moby.h"

/* NTSC-U counterpart of func_L28_003930D0. */
/* localdecomp:start func_U_L28_003915C8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003930D0;
typedef struct {
    s32 n;
    s32 pad[3];
    V4_003930D0 p[1];
} Path_003930D0;

typedef struct {
    u8 pad_00[0x78];
    f32 f78;
    f32 f7C;
    f32 f80;
    u8 pad_84[0x20];
    f32 fA4;
    s32 fA8;
    u8 pad_AC[0x174];
    f32 f220;
    f32 f224;
    u8 pad_228[0xC];
    s16 f234;
    u8 pad_236[0xBA];
    s32 f2F0;
    u8 pad_2F4[0x4];
    s32 f2F8;
    u8 pad_2FC[0x4];
    s32 f300;
    u8 pad_304[0x4];
    s32 f308;
    u8 pad_30C[0x4];
    s32 f310;
    u8 pad_314[0x4];
    s32 f318;
    u8 pad_31C[0x10];
    s32 f32C;
    u8 pad_330[0x8];
    s32 f338;
    u8 pad_33C[0x4];
    s32 f340;
    s32 f344;
    s32 f348;
    f32 f34C;
} State_003915C8;

typedef struct {
    u8 pad_00[0x10];
    s32 f10;
    u8 pad_14[0x30];
    u16 f44;
} Class_003915C8;

extern u8 *D_U_001DEC9C;
extern u8 D_U_001D66B0[8];
extern Path_003930D0 *D_U_0021C940[];
extern s32 D_001D545C;
extern s32 D_U_001DDCD8;
extern f32 D_U_001DDCDC;
extern f32 D_U_001DDCE0;
extern f32 D_U_001DDCE4;
extern f32 D_U_001DDCE8;
extern f32 D_U_001DDCEC;
extern s32 D_U_001DDCF0;
extern s32 D_U_001DDCF4;
extern s32 D_U_001DDCF8;
extern s32 D_U_001DDCFC;
extern f32 D_U_001DDD00;
__asm__(".extern D_U_001DDCD8, 4");
__asm__(".extern D_U_001DDCDC, 4");
__asm__(".extern D_U_001DDCE0, 4");
__asm__(".extern D_U_001DDCE4, 4");
__asm__(".extern D_U_001DDCE8, 4");
__asm__(".extern D_U_001DDCEC, 4");
__asm__(".extern D_U_001DDCF0, 4");
__asm__(".extern D_U_001DDCF4, 4");
__asm__(".extern D_U_001DDCF8, 4");
__asm__(".extern D_U_001DDCFC, 4");
__asm__(".extern D_U_001DDD00, 4");

extern s32 func_U_003926B8(u8 *);
extern void func_U_00392C48(u8 *);
extern s32 func_U_00392D70(u8 *, s32);
extern s32 func_U_00392E68(u8 *, s32);
extern void func_U_00392AF8(void *);
extern void func_U_00400B60(void *);
extern void func_U_0040C4F8(void *, s32, s32);
extern s32 func_U_0041C7D8(void *);
extern s32 func_U_0041C800(void *);
extern s32 func_U_0041CB00(void *, s32);
extern s32 func_U_0040AE68(s32, s32);
extern void func_U_0040C1B8(void *, s32, s32, s32);
extern s32 func_U_0041A988(void *, void *);
extern void func_U_00418878(u8 *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32,
                              s32);
extern void func_U_0040B810(u8 *, s32, s32);
extern void func_U_00312800(void *, s32, s32);
extern void func_U_00401FD8(void *, s32, void *);
extern s32 func_U_0041E558(void *, s32, f32);
extern void func_U_0038E3E0(u8 *, u8 *);
extern void func_U_003E5590(s32, s32);
extern f32 func_U_003D7CC8(void *, void *);
extern f32 func_U_003D8118(f32, f32);
extern s32 func_U_004151D0(void *, f32);
extern f32 func_U_0040D3E0(void *, s32, s32, f32);
extern void func_U_00420AF0(void *, void *, s32, s32);
extern void func_U_0041F200(void *, void *);
extern s32 func_U_00420788(void *, s32);
extern f32 func_U_003D7C70(void *, void *);
extern void func_U_0040D8E8(u8 *, void *, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_U_004206B0(void *, f32);
extern f32 func_U_00400E40(void *);
extern void func_U_00412F60(void *, f32);
extern void func_U_003D7D78(void *, void *, f32);
extern f32 func_U_0040E9F8(void *, void *, s32, f32, f32);
extern s32 func_U_00393930(void *, void *, void *, f32, f32);
extern void func_U_0040DA30(u8 *, s32, f32, s32, f32, f32, s32, s32, s32);

void func_U_L28_003915C8(u8 *self) {
    struct Moby *moby = (struct Moby *)self;
    u8 *st = moby->pvar;
    State_003915C8 *state = (State_003915C8 *)st;
    s32 found;
    s32 idx, idx2, idx3, i2;
    s32 r;
    s32 r4;
    s32 i;
    Path_003930D0 *path;
    f32 d0, g;

    if (func_U_003926B8(self) != 0) {
        func_U_00400B60(self);
        return;
    }

    switch (self[0x95]) {
    case 3:
        found = 0;
        if (func_U_00392D70(self, 0) != 0) {
            found = 1;
            state->f338 = 0;
        } else if (func_U_00392D70(self, 1) != 0) {
            found = 1;
            state->f338 = 1;
        }
        if (state->f340 != 0 && func_U_0041CB00(st + 0x220, state->f2F8) != 0) {
            func_U_0040C4F8(self, 1, 0);
        }
        if (state->f344 != 0 && func_U_0041CB00(st + 0x220, state->f310) != 0) {
            func_U_0040C4F8(self, 1, 0);
        }
        if (found) {
            u8 *o;
            *(s32 *)(st + (state->f338 << 2) + 0x340) = 1;
            o = *(u8 **)(self + 0x24);
            moby->mode_flags &= ~0x41;
            moby->mode_flags |= ((Class_003915C8 *)o)->f44 & 0x1000;
            moby->coll_record = (void *)((Class_003915C8 *)o)->f10;
            func_U_0040C4F8(self, 4, 1);
            idx3 = state->f338 ? state->f318 : state->f300;
            if (idx3 != -1) {
                func_U_0040C4F8(self, 2, 1);
            }
        }
        break;
    case 4:
        found = 0;
        if (func_U_00392D70(self, 0) != 0) {
            found = 1;
            state->f338 = 0;
        } else if (func_U_00392D70(self, 1) != 0) {
            found = 1;
            state->f338 = 1;
        }
        if (found) {
            u8 *o = *(u8 **)(self + 0x24);
            moby->mode_flags &= ~0x41;
            moby->mode_flags |= ((Class_003915C8 *)o)->f44 & 0x1000;
            moby->coll_record = (void *)((Class_003915C8 *)o)->f10;
            *(s32 *)(st + (state->f338 << 2) + 0x340) = 1;
            func_U_0040C4F8(self, 10, 1);
            if (moby->cur_seq != 8) {
                func_U_0040C1B8(self, 8, 0, 10);
            }
        }
        break;
    case 0:
        if (state->f234 == 1) {
            if (func_U_00392E68(self, 0) != 0) {
                state->f338 = 0;
                if (state->f340 == 0) {
                    goto no;
                }
                func_U_0040C4F8(self, 4, 1);
            } else if (func_U_00392E68(self, 1) != 0) {
                state->f338 = 1;
                if (state->f344 != 0) {
                    func_U_0040C4F8(self, 4, 1);
                } else {
                no:
                    func_U_0040C4F8(self, 12, 3);
                }
            }
        }
        break;
    case 1:
        if (state->f234 != 1 && func_U_0041C800(self) == 0 && self[0x20] != 10) {
            func_U_0040C4F8(self, 6, 0);
            state->f32C = func_U_0040AE68(0x244, 0x258);
        }
        break;
    case 2:
        r = func_U_0041A988(self, st + 0x160);
        if (func_U_0041C7D8(self) != 0 && self[0x94] == 2) {
            idx2 = state->f338 ? state->f318 : state->f300;
            if (idx2 != -1) {
                u8 *m = D_U_001DEC9C + (idx2 << 8);
                func_U_00418878(m, 0x4FFF, D_U_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f,
                    0, 3);
                func_U_00418878(m, 0x4FFF, D_U_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f,
                    0, 3);
                func_U_0040B810(m, 0, 3);
                func_U_00400B60(m);
                if (state->f338 == 0) {
                    state->f300 = -1;
                } else {
                    state->f318 = -1;
                }
            }
        }
        if (r & 1) {
            V4_003930D0 q;
            V4_003930D0 p;
            V4_003930D0 *pq;
            func_U_00392AF8(self);
            func_U_00312800(self, 7, 0);
            for (i = 4; i < 8; i++) {
                func_U_00401FD8(self, i, &p);
                pq = &q;
                q = p;
                q.w = 5.0f;
                if (func_U_0041E558(pq, 0, 255.0f) >= 0) {
                    func_U_0038E3E0(self, (u8 *)&p);
                }
            }
            if (state->f300 != -1) {
                u8 *m = D_U_001DEC9C + (state->f300 << 8);
                func_U_00418878(m, 0x4FFF, D_U_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f,
                    0, 3);
                func_U_00418878(m, 0x4FFF, D_U_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f,
                    0, 3);
                func_U_0040B810(m, 0, 3);
                func_U_00400B60(m);
            }
            if (state->f318 != -1) {
                u8 *m = D_U_001DEC9C + (state->f318 << 8);
                func_U_00418878(m, 0x4FFF, D_U_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f,
                    0, 3);
                func_U_00418878(m, 0x4FFF, D_U_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f,
                    0, 3);
                func_U_0040B810(m, 0, 3);
                func_U_00400B60(m);
            }
            return;
        }
        if (r & 2) {
            if (state->f234 == 1) {
                func_U_0040C4F8(self, 4, 1);
            } else {
                func_U_0040C4F8(self, 1, 0);
                state->f32C = func_U_0040AE68(0x244, 0x258);
            }
        }
        break;
    }

    switch (self[0x20]) {
    case 1:
        if (func_U_0041C7D8(self) != 0 && moby->cur_seq != 1) {
            func_U_0040C1B8(self, 1, 0, 10);
        }
        break;
    case 2:
        i2 = state->f338 ? state->f308 : state->f2F0;
        path = D_U_0021C940[i2];
        if (func_U_0041C7D8(self) != 0) {
            if (D_001D545C == 8) {
                func_U_003E5590(0xB76, 0x4650);
            }
            if (moby->cur_seq != 0) {
                func_U_0040C1B8(self, 0, 0, 10);
            }
            d0 = func_U_003D7CC8(&path->p[0], st + 0x2E0);
            if (func_U_003D7CC8(&path->p[path->n - 1], st + 0x2E0) < d0) {
                moby->position.x = path->p[path->n - 1].x;
                moby->position.y = path->p[path->n - 1].y;
            } else {
                moby->position.x = path->p[0].x;
                moby->position.y = path->p[0].y;
            }
            moby->rotation.z = func_U_003D8118(state->f220 - moby->position.x, state->f224 - moby->position.y);
        }
        if (func_U_004151D0(self, 20.0f) != 0 && moby->prev_seq == 0) {
            u8 *m = D_U_001DEC9C + ((state->f338 ? state->f318 : state->f300) << 8);
            func_U_00418878(m, 0x4FFF, D_U_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f,
                0, 3);
            func_U_00418878(m, 0x4FFF, D_U_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f,
                0, 3);
            func_U_0040B810(m, 0, 3);
            func_U_00400B60(m);
            if (state->f338 == 0) {
                state->f300 = -1;
            } else {
                state->f318 = -1;
            }
        }
        if (moby->anim_flags & 2) {
            func_U_0040C4F8(self, 4, -1);
        }
        break;
    case 10: {
        f32 h;
        h = func_U_0040D3E0(self + 0x10, 0x10, 0, 0.5f);
        if (h < 959.0f && state->f34C >= 959.0f) {
            h = 959.0f;
        }
        if (h < 959.0f && state->f34C >= 959.0f) {
            h = 959.0f;
        }
        moby->position.z -= 0.583333373f;
        if (moby->position.z < h) {
            moby->position.z = h;
        }
        if (moby->anim_flags & 2) {
            func_U_0040C4F8(self, 4, -1);
            if (moby->cur_seq != 2) {
                func_U_0040C1B8(self, 2, 0, 8);
            }
        }
        break;
    }
    case 4:
        idx = state->f338 ? state->f308 : state->f2F0;
        if (func_U_0041C7D8(self) != 0) {
            state->fA8 &= ~4;
            state->fA8 &= ~0x10;
            state->f78 = 0.7f;
            state->f7C = 0.7f;
            moby->mode_flags &= ~0x100;
            state->f80 = 12.566371f;
            state->fA8 |= 3;
            if (idx != -1) {
                path = D_U_0021C940[idx];
                d0 = func_U_003D7CC8(&path->p[0], st + 0x2E0);
                if (func_U_003D7CC8(&path->p[path->n - 1], st + 0x2E0) < d0) {
                    func_U_00420AF0(self, path, 0, 0);
                } else {
                    func_U_00420AF0(self, path, path->n - 1, path->n - 1);
                }
            }
            if (moby->cur_seq != 2) {
                func_U_0040C1B8(self, 2, 0, 10);
            }
        }
        if (idx == -1) {
            func_U_0041F200(self, st + 0x220);
            if (func_U_003D7C70(self + 0x10, st + 0x220) < D_U_001DDCEC) {
                func_U_0040C4F8(self, 9, -1);
            }
        } else {
            r4 = func_U_00420788(self, idx);
            if (func_U_003D7C70(self + 0x10, st + 0x220) < D_U_001DDCEC) {
                func_U_0040C4F8(self, 9, -1);
            } else if (r4 != 0 || *(u16 *)(self + 0x96) > 60) {
                func_U_0040C4F8(self, 7, -1);
            }
            if (func_U_003D7C70(self + 0x10, st + 0x220) < 6.0f) {
                func_U_0040C4F8(self, 7, -1);
                if (moby->cur_seq != 4) {
                    func_U_0040C1B8(self, 4, 0, 10);
                }
            }
        }
        if (func_U_0041CB00(st + 0x220, state->f338 ? state->f310 : state->f2F8) == 0) {
            func_U_0040C4F8(self, 6, -1);
        }
        func_U_0040D8E8(self, self + 0x10, 0x10000, 0, 1, 0, D_U_001DDD00, 5.0f, 1.0f);
        break;
    case 6:
        if (func_U_0041C7D8(self) != 0 && moby->cur_seq != 3) {
            func_U_0040C1B8(self, 3, 0, 10);
        }
        func_U_0041F200(self, st + 0x2E0);
        if (func_U_003D7C70(self + 0x10, st + 0x2E0) < state->fA4) {
            func_U_0040C4F8(self, 1, 0);
        }
        break;
    case 7:
        func_U_004206B0(self, func_U_003D8118(state->f220 - moby->position.x, state->f224 - moby->position.y));
        if (func_U_0041C7D8(self) != 0 && moby->cur_seq != 4) {
            func_U_0040C1B8(self, 4, 0, 10);
        }
        if (moby->anim_flags & 2) {
            func_U_0040C4F8(self, 8, -1);
            if (moby->cur_seq != 5) {
                func_U_0040C1B8(self, 5, 0, 3);
            }
        }
        break;
    case 8:
        func_U_004206B0(self, func_U_003D8118(state->f220 - moby->position.x, state->f224 - moby->position.y));
        if (func_U_0041C7D8(self) != 0) {
            state->f348 = 0;
        }
        if (moby->anim_flags & 2) {
            func_U_0040C4F8(self, 4, -1);
        }
        if (func_U_00400E40(self) > D_U_001DDCE0 && state->f348 < D_U_001DDCD8) {
            V4_003930D0 tgt;
            V4_003930D0 muz;
            V4_003930D0 dir;
            f32 d, sp;
            V4_003930D0 *pv;
            d = func_U_003D7C70(self + 0x10, st + 0x220);
            tgt = *(V4_003930D0 *)(st + 0x220);
            pv = &tgt;
            if (state->f348 != 0) {
                func_U_00412F60(pv, D_U_001DDCDC * d);
            }
            sp = D_U_001DDCE4 * d;
            func_U_00401FD8(self, 2, &muz);
            vec_sub_ab(&dir, &tgt, &muz);
            sp = sp * 0.0166666675f;
            func_U_003D7D78(&dir, &dir, sp);
            dir.z = func_U_0040E9F8(&muz, pv, 0, sp, -(D_U_001DDCE8 * 0.000277777785f));
            func_U_00393930(&muz, &dir, self, 5.0f, D_U_001DDCE8);
            state->f348++;
        }
        break;
    case 9:
        if (func_U_0041C7D8(self) != 0 && moby->cur_seq != 6) {
            func_U_0040C1B8(self, 6, 0, 10);
        }
        func_U_004206B0(self, func_U_003D8118(state->f220 - moby->position.x, state->f224 - moby->position.y));
        g = func_U_00400E40(self);
        if (g < (f32)D_U_001DDCFC && (f32)D_U_001DDCF8 < g) {
            func_U_0040DA30(self, 0, 1.0f, 1, 5.0f, 1.5f, 0, 1, 0);
        }
        if (g < (f32)D_U_001DDCF4 && (f32)D_U_001DDCF0 < g) {
            func_U_0040DA30(self, 1, 1.0f, 1, 5.0f, 1.5f, 0, 1, 0);
        }
        if (moby->anim_flags & 2) {
            func_U_0040C4F8(self, 4, -1);
        }
        break;
    }
    func_U_00392C48(self);
}
/* localdecomp:end func_U_L28_003915C8 */
