/* functional: medium. Same calls/arguments/order as retail. The damage-record locals (retail overlaps several in one frame) are separate structs; the record positions are zeroed once before first use where retail scales them uninitialised. */
#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) vu0_v4;

/* xyz add/sub with w taken from the first source, as the VU0 .xyz ops leave it (this file's flags lack the vu0 helpers) */
static void v_add(void *d, void *a, void *b) {
    f32 *fd = (f32 *)d;
    f32 *fa = (f32 *)a;
    f32 *fb = (f32 *)b;
    f32 x = fa[0] + fb[0];
    f32 y = fa[1] + fb[1];
    f32 z = fa[2] + fb[2];
    f32 w = fa[3];
    fd[0] = x;
    fd[1] = y;
    fd[2] = z;
    fd[3] = w;
}
static void v_sub(void *d, void *a, void *b) {
    f32 *fd = (f32 *)d;
    f32 *fa = (f32 *)a;
    f32 *fb = (f32 *)b;
    f32 x = fa[0] - fb[0];
    f32 y = fa[1] - fb[1];
    f32 z = fa[2] - fb[2];
    f32 w = fa[3];
    fd[0] = x;
    fd[1] = y;
    fd[2] = z;
    fd[3] = w;
}

typedef struct {
    vu0_v4 pos;
    u8 pad10[8];
    u8 b18;
    u8 b19;
    s16 h1A;
    u8 pad1C[4];
    s32 flags;
    u8 pad24[12];
} Q_00304C48 __attribute__((aligned(16)));

extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
extern u8 D_001A4BE0[];
extern u8 *D_L01_001DC5C4;
__asm__(".extern D_L01_001DC5C4, 4");
extern u8 D_001EAA20[];
extern u8 D_001EAA00[];
extern u8 *D_L01_001EEA80[];
extern u8 D_001BBE90[];
extern u8 D_001D60D8[];
extern u8 D_001D60E0[];
extern s32 D_00142698;
extern s32 D_001D545C;
extern u8 D_0014275B;
extern u8 D_00142DE0[];
extern f32 D_002F1600[];
extern f32 D_001DAA34;
__asm__(".extern D_001DAA34, 4");
extern void func_003DE198(void);

extern void func_L01_004CAB30(void *, void *);
extern void func_L01_004C8688(s32, void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004C8668(s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038D328(f32 *, f32 *);
extern void func_0038D028(void *, void *, void *);
extern s32 func_0013D3E0(void);
extern s32 func_00382498(s32, s32);
extern void func_L01_004739D8(void *, void *, s32, f32, s32, s16, s32);
extern void func_L01_00466F50(void *, void *, s32, f32, f32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern u8 *func_00382348(void *);
extern s32 func_003C4B50(void *);
extern void func_L01_00446748(void *, void *, s32, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern void func_L01_00315900(void *, s32, void *);
extern void func_L01_003E31A8(void *);
extern s32 func_L01_004006C8(void *, s32, s32);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_00306628(u8 *, u8 *, void *, void *);
extern void func_L01_004C7D40(void *, void *, f32);
extern void func_L01_00305970(u8 *, u8 *, void *);

void func_L01_00304C48(u8 *self) {
    vu0_v4 vn;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v80;
    f32 mtx[16];
    f32 ang[4];
    Q_00304C48 qa;
    Q_00304C48 qb;
    u8 *st;
    u8 *e;
    u8 *pos;
    u8 *target;
    u8 *row;
    u8 *rec;
    u8 *t;
    s32 idx;
    s32 next;
    s32 k;
    s32 count;
    s32 hit;
    s32 j;
    s32 col;
    s32 bonus;
    s32 dmg;
    s32 tab;
    f32 sz;

    if (D_L01_001DC5C4 == 0) {
        return;
    }
    st = *(u8 **)(self + 0x68);
    k = 0;
    idx = *(s32 *)(st + 0x48);
    if (*(s32 *)(st + 0x44) <= 0) {
        return;
    }
    qa.pos.x = 0.0f;
    qa.pos.y = 0.0f;
    qa.pos.z = 0.0f;
    qa.pos.w = 0.0f;
    qb = qa;
    do {
        e = D_L01_001DC5C4 + idx * 64;
        if (k != 0) {
            func_L01_004CAB30(e, e);
        }
        pos = e + 0x10;
        if (*(s32 *)(e + 0x38) >= 0) {
            func_L01_004C8688(*(s32 *)(e + 0x38), pos, e);
        }
        v_add(&vn, e, e + 0x10);
        if (*(s32 *)(e + 0x34) != 0) {
            k++;
            next = idx - 1;
        } else {
            hit = func_003D3CB0(e, &vn, 0x10, self, 0);
            if (hit == 0) {
                next = idx - 1;
                func_L01_004C7D40(e, pos, 0.006f);
                k++;
            } else {
                *(s128 *)(e + 0x10) = 0;
                *(s128 *)e = *(s128 *)D_001EAA20;
                func_0038CF68(&v10, D_001EAA20 + 0x20, 0.1f);
                v_add(e, e, &v10);
                *(s32 *)(e + 0x34) = 1;
                func_L01_004C8668(*(s32 *)(e + 0x38));
                *(s32 *)(e + 0x38) = -1;
                *(s128 *)(e + 0x20) = *(s128 *)&v10;
                func_0038CF68(&v20, &v10, 0.01f);
                ang[0] = func_003824E0(-0.7853982f, 0.7853982f);
                ang[1] = func_003824E0(-0.7853982f, 0.7853982f);
                ang[2] = func_003824E0(-0.7853982f, 0.7853982f);
                func_0038D328(mtx, ang);
                mtx[12] = 0.0f;
                mtx[13] = 0.0f;
                mtx[14] = 0.0f;
                func_0038D028(&v20, &v20, mtx);
                row = D_L01_002C5600 + D_001425C0[0x11] * 240;
                if (row[1] >= 4) {
                    if ((func_0013D3E0() & 1) != 0) {
                        col = (func_00382498(0x40, 0x64) << 16) | 0x64004040;
                        sz = func_003824E0(0.1f, 0.2f) * 210000.0f;
                        j = func_00382498(0x14, 0x50);
                        func_L01_004739D8(e, &v20, col, sz, 0xFF0A0A, (s16)((j * 5 + 2) / 6), 0);
                    }
                } else {
                    func_L01_00466F50(e, &v20, 0, -1.0f, 0.0f);
                }
                v30.x = 0.0f;
                v30.y = 0.0f;
                v30.z = 0.0f;
                v30.w = 0.0f;
                target = *(u8 **)(D_001EAA00 + 0x18);
                next = idx - 1;
                if (target == 0 || target == *(u8 **)(D_001A4BE0 + 0x25C0) ||
                    ((*(u16 *)(target + 0x34) & 0x1000) == 0 && (*(u8 **)(target + 0x24))[0x46] != 5)) {
                    k++;
                    if (func_0013D3E0() % 0xB == 0) {
                        func_L01_00306628(self, D_001EAA20, &v10, &v30);
                    }
                } else {
                    rec = func_00382348(target);
                    row = D_L01_002C5600 + D_001425C0[0x11] * 240;
                    if (rec != 0 && *(f32 *)rec <= *(f32 *)(row + 0x6C) && row[1] >= 4 &&
                        func_003C4B50(target) == 0) {
                        if (rec[0xE] == 3) {
                            k++;
                            func_L01_00446748(&qa, target, 0x10010000, *(f32 *)(row + 0x6C));
                            qa.b18 = 9;
                            func_L01_00446978(target, &qa);
                        } else {
                            func_L01_004AAC98(1, 0, self, 0xC59);
                            func_L01_00315900(target, 5, (void *)func_003DE198);
                            func_L01_003E31A8(target);
                            bonus = (D_00142698 + 0x31) / 0x32;
                            tab = D_001BBE90[(*(s16 *)(target + 0xB2) >> 1) + (D_001D545C << 10)];
                            if ((*(u16 *)(target + 0xB2) & 1) != 0) {
                                tab = tab >> 4;
                            }
                            if ((tab & 8) != 0) {
                                dmg = func_L01_004006C8(D_001D60E0, *(u16 *)(target + 0xB6), *(s16 *)(target + 0xB2));
                            } else {
                                dmg = func_L01_004006C8(D_001D60D8, *(u16 *)(target + 0xB6), *(s16 *)(target + 0xB2));
                            }
                            dmg = dmg << D_001A4BE0[0x28C8];
                            if (func_L01_0041A4F0() != 0) {
                                f32 mul;
                                if (D_001D545C == 7 && D_0014275B != 0) {
                                    mul = D_001DAA34;
                                } else {
                                    mul = D_002F1600[D_001D545C];
                                }
                                dmg = (s32)((f32)dmg * mul);
                            }
                            k++;
                            *(s32 *)(D_00142DE0 + 0x44) = *(s32 *)(D_00142DE0 + 0x44) + dmg + bonus;
                        }
                    } else {
                        v_sub(&v80, target + 0x10, self + 0x10);
                        func_0038CF68(&v80, &v80, 1.0f);
                        func_0038CF68(&qb, &qb, 1.0f);
                        if (row[1] >= 4) {
                            func_L01_00446760(&qb, self, 0x11010000, &v80, *(f32 *)(row + 0x6C));
                        } else {
                            func_L01_00446760(&qb, self, 0x1110000, &v80, *(f32 *)(row + 0x6C));
                        }
                        qb.pos = v80;
                        qb.b18 = 9;
                        qb.pos.w = 5627.9248f;
                        qb.flags = 1;
                        qb.b19 = 1;
                        qb.h1A = *(u16 *)(target + 0xAA);
                        func_L01_00446978(target, &qb);
                        if (*(s32 *)(st + 0x68) == 0) {
                            *(s32 *)(st + 0x68) = 7;
                            if (D_L01_002C5600[D_001425C0[0x11] * 240 + 1] >= 4) {
                                func_L01_004AAC98(1, 0, self, 0xC59);
                            } else {
                                func_L01_004AAC98(1, 0, self, 0x5C9);
                            }
                        }
                        count = func_003D4D00(target + 0x10, 0x10, self, 0, 1.5f);
                        if (*(s32 *)(st + 0x68) == 0) {
                            *(s32 *)(st + 0x68) = 7;
                            if (D_L01_002C5600[D_001425C0[0x11] * 240 + 1] >= 4) {
                                func_L01_004AAC98(1, 0, self, 0xC59);
                            } else {
                                func_L01_004AAC98(1, 0, self, 0x5C9);
                            }
                        }
                        k++;
                        for (j = 0; j < count; j++) {
                            t = D_L01_001EEA80[j];
                            if (t == *(u8 **)(D_001A4BE0 + 0x25C0)) {
                                continue;
                            }
                            v_sub(&v80, t + 0x10, self + 0x10);
                            func_0038CF68(&v80, &v80, 1.0f);
                            func_0038CF68(&qb, &qb, 1.0f);
                            row = D_L01_002C5600 + D_001425C0[0x11] * 240;
                            if (row[1] >= 4) {
                                func_L01_00446760(&qb, self, 0x11010000, &v80, *(f32 *)(row + 0x70));
                            } else {
                                func_L01_00446760(&qb, self, 0x1110000, &v80, *(f32 *)(row + 0x70));
                            }
                            qb.pos = v80;
                            qb.b18 = 9;
                            qb.pos.w = 5627.9248f;
                            qb.flags = 1;
                            qb.b19 = 1;
                            qb.h1A = *(u16 *)(t + 0xAA);
                            func_L01_00446978(t, &qb);
                            if (*(s32 *)(st + 0x68) == 0) {
                                *(s32 *)(st + 0x68) = 7;
                                if (D_L01_002C5600[D_001425C0[0x11] * 240 + 1] >= 4) {
                                    func_L01_004AAC98(1, 0, self, 0xC59);
                                } else {
                                    func_L01_004AAC98(1, 0, self, 0x5C9);
                                }
                            }
                        }
                    }
                }
            }
        }
        idx = (next > -1) ? next : 0x22;
        v_add(e, e, e + 0x10);
        if (func_0013D3E0() % 7 == 0) {
            func_0038CF68(&v10, pos, 0.05f);
            func_L01_00305970(self, e, pos);
        }
        if (func_0013D3E0() % 0x16 == 0) {
            func_0038CF68(&v10, pos, 0.05f);
            if (D_L01_002C5600[D_001425C0[0x11] * 240 + 1] >= 4) {
                if ((func_0013D3E0() & 1) != 0) {
                    col = (func_00382498(0x40, 0x64) << 16) | 0x64004040;
                    sz = func_003824E0(0.1f, 0.2f) * 210000.0f;
                    j = func_00382498(0x14, 0x50);
                    func_L01_004739D8(e, &v10, col, sz, 0xFF0A0A, (s16)((j * 5 + 2) / 6), 0);
                }
            } else {
                func_L01_00466F50(e, &v10, 0, -1.0f, 0.0f);
            }
        }
    } while (k < *(s32 *)(st + 0x44));
}
