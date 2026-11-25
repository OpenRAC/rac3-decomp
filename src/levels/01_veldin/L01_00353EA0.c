#include "common.h"

/* localdecomp:start func_L01_00353EA0 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef union { u8 b[0x2A00]; s16 h[0x1500]; u16 uh[0x1500]; s32 i[0xA80]; u32 u[0xA80]; f32 f[0xA80]; u8 *ptr[0xA80]; u128_t q[0x2A0]; } Hero_353EA0;
typedef union { u8 b[0x600]; s8 c[0x600]; s16 h[0x300]; u16 uh[0x300]; s32 i[0x180]; u32 u[0x180]; f32 f[0x180]; u8 *ptr[0x180]; u128_t q[0x60]; } Obj_353EA0;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_353EA0;

extern Hero_353EA0 D_001A4BE0;
extern s32 D_001D545C;
extern u8 *D_L01_001E001C;
extern f32 D_L01_001DD5B4;
__asm__(".extern D_L01_001DD5B4, 4");
extern f32 D_L01_001DD5B8;
__asm__(".extern D_L01_001DD5B8, 4");
extern f32 D_L01_001DD5BC;
__asm__(".extern D_L01_001DD5BC, 4");
extern f32 D_L01_001DD5D4;
__asm__(".extern D_L01_001DD5D4, 4");
extern f32 D_L01_001DD5DC;
__asm__(".extern D_L01_001DD5DC, 4");
extern f32 D_L01_001DD5E0;
__asm__(".extern D_L01_001DD5E0, 4");
extern f32 D_L01_001DD5E4;
__asm__(".extern D_L01_001DD5E4, 4");
extern s32 D_L01_001DD5E8;
__asm__(".extern D_L01_001DD5E8, 4");
extern void func_L01_00356568(void *);

extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void *func_003C24B0(s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_003C41A0(void *, f32, f32, f32, f32, void *);
extern void func_L01_00315900(Obj_353EA0 *, s32, void *);
extern s32 func_L01_00355D88(u8 *);
extern void func_L01_00356588(void *);
extern void func_L01_003564D0(u8 *, s32);
extern void func_L01_003565E0(Obj_353EA0 *);
extern void func_L01_003569A0(Obj_353EA0 *, void *, f32);
extern s32 func_L01_003CD878(void *, void *, void *, s32, s32, f32);
extern f32 func_L01_004395E0(Obj_353EA0 *);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004468C8(Obj_353EA0 *, f32, f32, f32, s32, s32, s32, s32, s32);
extern void func_L01_00448890(void *, f32, f32, f32, f32, void *, s32);
extern s32 func_L01_0044E1B8(Obj_353EA0 *, f32);
extern s32 func_L01_00454370(Obj_353EA0 *, void *);
extern void func_L01_00456160(void *, void *);
extern s32 func_L01_004561B8(Obj_353EA0 *);
extern s32 func_L01_004561E0(Obj_353EA0 *);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_00458F78(Obj_353EA0 *, void *, s32, s32);
extern void func_L01_00459188(Obj_353EA0 *, void *, void *);
extern void func_L01_004591B8(Obj_353EA0 *, void *, void *);
extern u8 *func_L01_004592A8(Obj_353EA0 *, void *, s32, void *);
extern u8 *func_L01_004593B8(Obj_353EA0 *, void *, void *, void *, void *);
extern void func_L01_0045A7A8(Obj_353EA0 *, void *, f32);
extern void func_L01_0045A898(Obj_353EA0 *, void *, f32);
extern s32 func_L01_0045A9F0(Obj_353EA0 *);
extern s32 func_L01_0045AA10(Obj_353EA0 *, f32);
extern s32 func_L01_0045AA30(Obj_353EA0 *, void *);
extern void func_L01_0045BD10(Obj_353EA0 *, f32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0045BDE8(Obj_353EA0 *, s32);
extern s32 func_L01_0045C2A0(Obj_353EA0 *, f32, f32, f32);

void func_L01_00353EA0(Obj_353EA0 *m) {
    V4_353EA0 s0, s10, s20, s30;
    Obj_353EA0 *pv;

    pv = (Obj_353EA0 *)m->ptr[0x68 / 4];
    if (func_L01_00355D88((u8 *)m) != 0) {
        func_L01_003564D0((u8 *)m, 1);
        return;
    }
    *(u128_t *)&s0 = m->q[1];
    switch (m->b[0x95]) {
    case 0: {
        u8 *e = D_L01_001E001C + (pv->i[0x344 / 4] << 8);
        if (pv->i[0x2F8 / 4] != 0) {
            if ((D_001D545C == 1 || D_001D545C == 0x60) && pv->i[0x360 / 4] == 0) {
                pv->ptr[0x360 / 4] = func_003C24B0(0x1AA2, 0x80);
                func_L01_00456160(pv->ptr[0x360 / 4], m);
                pv->i[0x240 / 4] = pv->i[0x360 / 4];
            }
            m->i[0x98 / 4] = ((Obj_353EA0 *)m->ptr[0x24 / 4])->i[0x10 / 4];
            func_L01_003569A0(m, &m->q[1], pv->f[0x35C / 4]);
        } else if (func_L01_00456250(e) != 0) {
            func_L01_004450F0(m, 7, 1);
            if (m->b[0x43] != 0x12) {
                func_003C3A10(m, 0x12, func_00382498(0, 0xA), 0);
            }
        }
        break;
    }
    case 1:
        if (func_L01_004561E0(m) != 0 && pv->i[0x350 / 4] == 0) {
            pv->h[0x2F6 / 2] = (func_00382498(0, 0x28) * 5 + 2) / 6;
        }
        if (pv->h[0x234 / 2] == 1 && func_0038CB00(&pv->h[0x2F6 / 2]) != 0) {
            if (m->b[0x43] != 0x13) {
                func_003C3A10(m, 0x13, 0, 8);
            }
            func_L01_004450F0(m, 0xB, 3);
            if (pv->i[0x348 / 4] != -1) {
                func_L01_004450F0(m, 0xA, -1);
            }
        } else if (pv->i[0x2F8 / 4] != 0 && func_0038CB00(&pv->h[0x2F6 / 2]) != 0) {
            func_L01_004450F0(m, m->b[0x20], 2);
            pv->i[0x2F8 / 4] = 0;
            if (pv->i[0x2F0 / 4] < 0xFA) {
                pv->i[0x2F0 / 4] = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    case 2:
        if (pv->h[0x234 / 2] == 1) {
            if (m->b[0x43] != 0x13) {
                func_003C3A10(m, 0x13, 0, 8);
            }
            func_L01_004450F0(m, 0xB, 3);
        } else if (pv->i[0x2F0 / 4] == 0) {
            func_L01_004450F0(m, m->b[0x20], 1);
        }
        break;
    case 3:
        if (pv->h[0x234 / 2] != 1 && func_L01_004561E0(m) == 0 && m->b[0x20] != 1) {
            func_L01_004450F0(m, 7, 2);
            if (m->b[0x43] != 0x12) {
                func_003C3A10(m, 0x12, func_00382498(0, 0xA), 8);
            }
            pv->i[0x2F0 / 4] = (func_00382498(0x30C, 0x384) * 5 + 2) / 6;
        }
        break;
    case 7: {
        s32 r = func_L01_00454370(m, &pv->b[0x160]);
        if ((r & 1) || (m->uh[0x96 / 2] >= 0x65 && pv->f[0x30 / 4] <= 0.0f)) {
            func_L01_00356588(m);
            func_L01_00315900(m, 0, func_L01_00356568);
            return;
        }
        if (r & 2) {
            if (pv->h[0x234 / 2] == 1) {
                if (m->b[0x43] != 0x13) {
                    func_003C3A10(m, 0x13, 0, 8);
                }
                func_L01_004450F0(m, 0xB, 3);
            } else {
                func_L01_004450F0(m, 9, 2);
                pv->i[0x2F0 / 4] = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    }
    }

    switch (m->b[0x20]) {
    case 6:
        if (m->b[0x60] & 2) {
            func_L01_004450F0(m, 7, -1);
            if (m->b[0x43] != 0x12) {
                func_003C3A10(m, 0x12, 0, 8);
            }
        }
        break;
    case 7:
        if (func_L01_004561B8(m) != 0) {
            f32 a = func_00382538();
            f32 r = func_003824E0(2.0f, 6.0f);
            qzero(&pv->b[0x330]);
            pv->f[0x330 / 4] = func_0038D098(a) * r;
            pv->f[0x334 / 4] = func_0038D0B0(a) * r;
            vec_add_ab(&pv->b[0x330], &pv->b[0x330], &pv->b[0x320]);
            if (pv->i[0x34C / 4] != -1 && func_L01_00456500(&pv->b[0x330], pv->i[0x34C / 4]) == 0) {
                pv->q[0x330 / 16] = pv->q[0x320 / 16];
            }
            pv->i[0x340 / 4] = func_00382498(0x12C, 0x212);
            func_L01_0045BD78(m, 0.0036000002f, 0.030000001f, 0.0018151426f, 0.12566371f);
        }
        func_L01_0045A898(m, &pv->b[0x330], m->f[0xF8 / 4]);
        func_L01_00448890(&m->f[0xF8 / 4], func_0038D160(pv->f[0x330 / 4] - m->f[0x10 / 4], pv->f[0x334 / 4] - m->f[0x14 / 4]),
                          0.0018151426f, 0.0018151426f, 0.03490659f, &pv->b[0x31C], 0);
        if (func_0038CF38(&m->q[1], &pv->b[0x330]) < 0.75f) {
            f32 a = func_00382538();
            f32 r = func_003824E0(2.0f, 6.0f);
            qzero(&pv->b[0x330]);
            pv->f[0x330 / 4] = func_0038D098(a) * r;
            pv->f[0x334 / 4] = func_0038D0B0(a) * r;
            vec_add_ab(&pv->b[0x330], &pv->b[0x330], &pv->b[0x320]);
            if (pv->i[0x34C / 4] != -1 && func_L01_00456500(&pv->b[0x330], pv->i[0x34C / 4]) == 0) {
                pv->q[0x330 / 16] = pv->q[0x320 / 16];
            }
        }
        if (func_0038CAD0(&pv->b[0x340]) != 0) {
            if (m->b[0x43] != 0xB) {
                func_003C3A10(m, 0xB, 0, 8);
            }
            func_L01_004450F0(m, 6, -1);
        }
        break;
    case 4:
        if (func_L01_004561E0(m) != 0) {
            pv->f[0x308 / 4] = m->f[0x18 / 4];
        }
        if (m->b[0x42] == 3) {
            f32 t = func_L01_004395E0(m);
            if (t > 2.0f && t < 10.0f) {
                func_0038CF68(&s30, &m->b[0xC0], 0.0f);
                vec_add_ba(&s10, &m->q[1], &s30);
            }
            if (t > 2.0f) {
                func_003C41A0(&s10.z, pv->f[0x308 / 4] + 1.0f, 0.09375f, 0.15625f, 0.0625f, &pv->b[0x310]);
            }
            if (t > 2.0f && t < 10.0f) {
                vec_sub_ab(&s20, &s10, &m->q[1]);
                func_L01_0045AA30(m, &s20);
                func_L01_0045BD10(m, func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4]));
            }
        }
        if (m->b[0x60] & 2) {
            pv->i[0x310 / 4] = 0;
            func_L01_004450F0(m, 5, -1);
            if (m->b[0x43] != 8) {
                func_003C3A10(m, 8, 0, 0);
            }
        }
        break;
    case 5: {
        f32 t = func_L01_004395E0(m);
        if (t < 22.0f) {
            func_0038CF68(&s30, &m->b[0xC0], 0.0f);
            vec_add_ba(&s10, &m->q[1], &s30);
        }
        if (t < 15.0f) {
            func_L01_0045BD10(m, func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4]));
            func_003C41A0(&s10.z, func_003C3D30(&m->q[1], 0, 0, 0.5f), 0.050000004f, 0.4166667f, 0.050000004f, &pv->b[0x310]);
        }
        if (t < 22.0f) {
            vec_sub_ab(&s20, &s10, &m->q[1]);
            func_L01_0045AA30(m, &s20);
        }
        if (m->b[0x60] & 2) {
            pv->i[0x310 / 4] = 0;
            func_L01_004450F0(m, 0xB, -1);
            if (m->b[0x43] != 0x13) {
                func_003C3A10(m, 0x13, 0, 7);
            }
        }
        break;
    }
    case 8:
        if (func_L01_004561B8(m) != 0) {
            f32 a = func_0038DAB8(m->f[0xF8 / 4], func_L01_00443A18(60.0f, 80.0f) * 0.017453292f);
            f32 r = func_003824E0(3.0f, 4.0f);
            qzero(&pv->b[0x300]);
            pv->f[0x300 / 4] = func_0038D098(a) * r;
            pv->f[0x304 / 4] = func_0038D0B0(a) * r;
            vec_add_ab(&pv->b[0x300], &m->q[1], &pv->b[0x300]);
            func_L01_0045BD78(m, 0.0036000002f, 0.030000001f, 0.0018151426f, 0.12566371f);
        }
        func_L01_0045A898(m, &pv->b[0x300], m->f[0xF8 / 4]);
        func_L01_00448890(&m->f[0xF8 / 4], func_0038D160(pv->f[0x300 / 4] - m->f[0x10 / 4], pv->f[0x304 / 4] - m->f[0x14 / 4]),
                          0.0018151426f, 0.0018151426f, 0.03490659f, &pv->b[0x31C], 0);
        if (func_0038CF38(&m->q[1], &pv->b[0x300]) < 0.75f) {
            f32 a = func_0038DAB8(m->f[0xF8 / 4], func_L01_00443A18(60.0f, 80.0f) * 0.017453292f);
            f32 r = func_003824E0(3.0f, 4.0f);
            qzero(&pv->b[0x300]);
            pv->f[0x300 / 4] = func_0038D098(a) * r;
            pv->f[0x304 / 4] = func_0038D0B0(a) * r;
            vec_add_ab(&pv->b[0x300], &m->q[1], &pv->b[0x300]);
        }
        if (func_0038DBA0(m->f[0xF8 / 4], func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4])) < 1.9198622f
            || D_001A4BE0.f[0x174 / 4] > 0.030000001f) {
            if (m->b[0x43] != 0x13) {
                func_003C3A10(m, 0x13, 0, 5);
            }
            func_L01_004450F0(m, 0xB, -1);
        }
        break;
    case 11: {
        f32 d;
        if (func_L01_004561B8(m) != 0) {
            func_L01_00459188(m, pv->ptr[0x230 / 4], &pv->b[0x370]);
            func_L01_0045BD78(m, 0.0032000002f, 0.10000001f, 0.010053097f, 0.25132743f);
        }
        d = fabs_asm(m->f[0x18 / 4] - pv->f[0x228 / 4]);
        if (pv->i[0x368 / 4] != 0) {
            func_L01_0045BD10(m, func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4]));
        } else {
            func_L01_00458F78(m, &pv->b[0x370], 0, 0);
            func_L01_0045A7A8(m, &pv->b[0x370], pv->f[0x318 / 4]);
        }
        if (func_0038CF38(&m->q[1], &pv->b[0x220]) < 2.5f) {
            if (func_0038DBA0(m->f[0xF8 / 4], func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4])) < 0.34906584f) {
                func_L01_004450F0(m, 0x10, -1);
                if (m->b[0x43] != 3) {
                    func_003C3A10(m, 3, 0, 8);
                }
            }
        }
        if (pv->i[0x360 / 4] != 0) {
            if (func_0038CF38(&m->q[1], &pv->b[0x220]) < 7.0f) {
                if (func_0038DBA0(m->f[0xF8 / 4], func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4])) < 0.34906584f) {
                    pv->i[0x364 / 4] = 0;
                    func_L01_004450F0(m, 0xC, -1);
                    if (m->b[0x43] != 0xF) {
                        func_003C3A10(m, 0xF, 0, 8);
                    }
                }
            }
            if (pv->i[0x368 / 4] != 0) {
                if (func_0038DBA0(m->f[0xF8 / 4], func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4])) < 0.34906584f) {
                    pv->i[0x364 / 4] = 0;
                    func_L01_004450F0(m, 0xC, -1);
                    if (m->b[0x43] != 0xF) {
                        func_003C3A10(m, 0xF, 0, 8);
                    }
                }
            }
        }
        if (d > 5.0f) {
            if (m->b[0x43] != 0x13) {
                func_003C3A10(m, 0x13, 0, 8);
            }
            func_L01_004450F0(m, 0x17, -1);
        }
        break;
    }
    case 23:
        if (func_L01_004561B8(m) != 0) {
            u8 *n;
            pv->i[0x458 / 4] = 0;
            pv->i[0x454 / 4] = 0;
            n = func_L01_004592A8(m, &pv->b[0x3F0], pv->i[0x36C / 4], &pv->b[0x420]);
            pv->ptr[0x450 / 4] = n;
            *(u128_t *)&s10 = *(u128_t *)(n + 0x10);
            func_L01_004591B8(m, &s10, &pv->b[0x370]);
            func_L01_0045BD78(m, 0.0032000002f, 0.10000001f, 0.010053097f, 0.25132743f);
        }
        if (pv->i[0x458 / 4] == 0) {
            func_L01_00458F78(m, &pv->b[0x370], 0, 0);
            func_L01_0045A7A8(m, &pv->b[0x370], pv->f[0x318 / 4]);
        } else {
            func_L01_0045A7A8(m, pv->ptr[0x450 / 4] + 0x10, pv->f[0x318 / 4]);
        }
        if (func_0038CF38(&m->q[1], pv->ptr[0x450 / 4] + 0x10) <= 1.0f) {
            pv->i[0x458 / 4] = 1;
            *(u128_t *)&s10 = pv->q[0x220 / 16];
            pv->ptr[0x450 / 4] = func_L01_004593B8(m, pv->ptr[0x450 / 4], &pv->b[0x420], &pv->b[0x454], &s10);
            if (pv->ptr[0x450 / 4] == 0) {
                func_L01_004450F0(m, 0xB, -1);
                if (m->b[0x43] != 0x13) {
                    func_003C3A10(m, 0x13, 0, 8);
                }
            }
        }
        break;
    case 12:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, 0.2f, 0.030000001f, 0.0018151426f, 0.12566371f);
            m->f[0x48 / 4] = D_L01_001DD5E4;
        }
        if (m->b[0x60] & 2) {
            func_L01_004450F0(m, 0xD, -1);
            if (m->b[0x43] != 0x10) {
                func_003C3A10(m, 0x10, 0, 3);
            }
        }
        func_L01_0045AA10(m, func_0038D160(((Obj_353EA0 *)pv->ptr[0x230 / 4])->f[0x10 / 4] - m->f[0x10 / 4],
                                         ((Obj_353EA0 *)pv->ptr[0x230 / 4])->f[0x14 / 4] - m->f[0x14 / 4]));
        break;
    case 13:
        if ((m->b[0x60] & 2) && D_L01_001DD5E8 < pv->i[0x364 / 4]) {
            func_L01_004450F0(m, 0xE, -1);
            if (m->b[0x43] != 0x11) {
                func_003C3A10(m, 0x11, 0, 8);
            }
        }
        if (func_L01_0044E1B8(m, 1.0f) != 0 && m->b[0x42] == 0x10) {
            m->f[0x48 / 4] = 0.5f;
            pv->i[0x364 / 4] = pv->i[0x364 / 4] + 1;
            func_003C2F58(pv->ptr[0x360 / 4], 0, &s10);
            if (pv->ptr[0x230 / 4] != D_001A4BE0.ptr[0x25C0 / 4]) {
                vec_sub_ab(&s20, &pv->b[0x220], &s10);
            } else {
                vec_sub_ab(&s20, &D_001A4BE0.b[0xD0], &s10);
                func_0038CF68(&s20, &s20, D_L01_001DD5E0);
            }
            func_003A52A0(8, 0, m);
            func_L01_003CD878(pv->ptr[0x360 / 4], &s10, &s20, 0, -1, (f32)pv->b[0x44]);
        }
        func_L01_0045A9F0(m);
        break;
    case 14:
        if (m->b[0x60] & 2) {
            func_L01_004450F0(m, 0xB, -1);
            if (m->b[0x43] != 0x13) {
                func_003C3A10(m, 0x13, 0, 8);
            }
        }
        break;
    case 10:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, 0.0032000002f, 0.10000001f, 0.010053097f, 0.25132743f);
        }
        if (func_0038CF38(&m->q[1], &pv->b[0x220]) < 5.0f) {
            func_L01_004450F0(m, 0xC, -1);
            if (m->b[0x43] != 0xF) {
                func_003C3A10(m, 0xF, 0, 8);
            }
        }
        if (func_L01_0045BDE8(m, pv->i[0x348 / 4]) != 0) {
            if (func_0038CF38(&m->q[1], &pv->b[0x220]) < 5.0f) {
                func_L01_004450F0(m, 0xC, -1);
                if (m->b[0x43] != 0xF) {
                    func_003C3A10(m, 0xF, 0, 8);
                }
            } else {
                func_L01_004450F0(m, 0xB, -1);
                if (m->b[0x43] != 0x13) {
                    func_003C3A10(m, 0x13, 0, 8);
                }
            }
        }
        break;
    case 16:
        if (func_L01_004561E0(m) != 0) {
            pv->f[0x308 / 4] = m->f[0x18 / 4];
        }
        if (m->b[0x42] == 3) {
            f32 t = func_L01_004395E0(m);
            if (t > 2.0f && t < 10.0f) {
                func_0038CF68(&s30, &m->b[0xC0], 0.125f);
                vec_add_ba(&s10, &m->q[1], &s30);
            }
            if (t > 2.0f) {
                *(u128_t *)&s30 = m->q[1];
                if (pv->b[0x5F] != 0) {
                    func_L01_004468C8(m, 0.75f, 1.0f, 0.75f, 0, 0x10000, 0, 1, 0);
                } else {
                    func_L01_004468C8(m, 0.75f, 1.0f, 0.75f, 0, 1, 0, 1, 0);
                }
                func_003C41A0(&s10.z, pv->f[0x308 / 4] + 0.5f, 0.09375f, 0.15625f, 0.0625f, &pv->b[0x310]);
            }
            if (t > 2.0f && t < 10.0f) {
                vec_sub_ab(&s20, &s10, &m->q[1]);
                func_L01_0045AA30(m, &s20);
            } else {
                func_L01_0045AA10(m, m->f[0xF8 / 4]);
            }
        } else {
            func_L01_0045AA10(m, m->f[0xF8 / 4]);
        }
        if (m->b[0x60] & 2) {
            pv->i[0x310 / 4] = 0;
            func_L01_004450F0(m, 0x12, -1);
            if (m->b[0x43] != 4) {
                func_003C3A10(m, 4, 0, 0);
            }
        }
        break;
    case 17: {
        f32 t;
        if (func_L01_004561B8(m) != 0) {
            pv->f[0x314 / 4] = 0.083333336f;
        }
        t = func_L01_004395E0(m);
        if (t > 15.0f) {
            pv->f[0x314 / 4] = pv->f[0x314 / 4] - 0.004f;
        }
        if (t < 22.0f) {
            func_0038CF68(&s30, &m->b[0xC0], pv->f[0x314 / 4]);
            vec_add_ba(&s10, &m->q[1], &s30);
        }
        if (t < 15.0f) {
            func_003C41A0(&s10.z, func_003C3D30(&m->q[1], 0, 0, 0.5f), 0.050000004f, 0.4166667f, 0.050000004f, &pv->b[0x310]);
        }
        if (t < 22.0f) {
            vec_sub_ab(&s20, &s10, &m->q[1]);
            func_L01_0045AA30(m, &s20);
        } else {
            func_L01_0045AA10(m, m->f[0xF8 / 4]);
        }
        if (m->b[0x60] & 2) {
            pv->i[0x310 / 4] = 0;
            func_L01_004450F0(m, 0x13, -1);
            if (m->b[0x43] != 0xB) {
                func_003C3A10(m, 0xB, 8, 7);
            }
        }
        break;
    }
    case 18: {
        f32 t = func_L01_004395E0(m);
        if (t < 7.0f) {
            func_0038CF68(&s30, &m->b[0xC0], -0.14285715f);
            vec_add_ba(&s10, &m->q[1], &s30);
        }
        if (t < 7.0f) {
            func_003C41A0(&s10.z, func_003C3D30(&m->q[1], 0, 0, 0.5f), 0.023809524f, 0.17857143f, 0.04761905f, &pv->b[0x310]);
        }
        if (t < 7.0f) {
            vec_sub_ab(&s20, &s10, &m->q[1]);
            func_L01_0045AA30(m, &s20);
        } else {
            func_L01_0045AA10(m, m->f[0xF8 / 4]);
        }
        if (func_L01_0044E1B8(m, 10.0f) != 0) {
            pv->i[0x310 / 4] = 0;
            func_L01_004450F0(m, 0x14, -1);
            if (m->b[0x43] != 6) {
                func_003C3A10(m, 6, 1, 3);
            }
        }
        break;
    }
    case 20:
        if (func_L01_004561B8(m) != 0) {
            pv->f[0x308 / 4] = m->f[0x18 / 4];
        }
        if (m->b[0x42] == 6) {
            f32 t = func_L01_004395E0(m);
            if (t > 4.0f && t < 18.0f) {
                func_0038CF68(&s30, &m->b[0xC0], -0.071428575f);
                vec_add_ba(&s10, &m->q[1], &s30);
            }
            if (t > 4.0f && t < 12.0f) {
                func_003C41A0(&s10.z, pv->f[0x308 / 4] + 0.75f, 0.09375f, 0.1875f, 0.09375f, &pv->b[0x310]);
            }
            if (t == 12.0f) {
                pv->i[0x310 / 4] = 0;
            }
            if (t > 12.0f && t < 18.0f) {
                func_003C41A0(&s10.z, func_003C3D30(&m->q[1], 0, 0, 0.5f), 0.020833334f, 0.25f, 0.1875f, &pv->b[0x310]);
            }
            if (t > 4.0f && t < 18.0f) {
                vec_sub_ab(&s20, &s10, &m->q[1]);
                func_L01_0045AA30(m, &s20);
            } else {
                func_L01_0045AA10(m, m->f[0xF8 / 4]);
            }
            if (m->b[0x60] & 2) {
                func_L01_004450F0(m, 0xB, -1);
                if (m->b[0x43] != 0x13) {
                    func_003C3A10(m, 0x13, 0, 5);
                }
            }
        }
        break;
    case 1:
        if (func_L01_004561B8(m) != 0) {
            pv->f[0x308 / 4] = m->f[0x18 / 4];
        }
        if (m->b[0x42] == 6) {
            f32 t = func_L01_004395E0(m);
            if (t > 4.0f && t < 18.0f) {
                func_0038CF68(&s30, &m->b[0xC0], -0.071428575f);
                vec_add_ba(&s10, &m->q[1], &s30);
            }
            if (t > 4.0f && t < 12.0f) {
                func_003C41A0(&s10.z, pv->f[0x308 / 4] + 0.75f, 0.09375f, 0.1875f, 0.09375f, &pv->b[0x310]);
            }
            if (t == 12.0f) {
                pv->i[0x310 / 4] = 0;
            }
            if (t > 12.0f && t < 18.0f) {
                m->f[0x48 / 4] = 0.5f;
                func_003C41A0(&s10.z, func_003C3D30(&m->q[1], 0, 0, 0.5f), 0.0625f, 0.625f, 0.5625f, &pv->b[0x310]);
            }
            if (t > 4.0f && t < 18.0f) {
                vec_sub_ab(&s20, &s10, &m->q[1]);
                func_L01_0045AA30(m, &s20);
            } else {
                func_L01_0045AA10(m, m->f[0xF8 / 4]);
            }
            if (m->b[0x60] & 2) {
                m->f[0x48 / 4] = 1.0f;
                func_L01_004450F0(m, 0xB, -1);
                if (m->b[0x43] != 0x13) {
                    func_003C3A10(m, 0x13, 0, 5);
                }
            }
        }
        break;
    case 21:
        func_L01_0045AA10(m, m->f[0xF8 / 4]);
        if (m->b[0x60] & 2) {
            func_L01_004450F0(m, 0xB, -1);
            if (m->b[0x43] != 0x13) {
                func_003C3A10(m, 0x13, 0, 5);
            }
        }
        break;
    case 19:
        if (func_L01_004561B8(m) != 0) {
            pv->h[0x2F6 / 2] = 0;
        }
        func_L01_0045AA10(m, m->f[0xF8 / 4]);
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 0x13) {
                func_003C3A10(m, 0x13, 0, 5);
            }
            func_L01_004450F0(m, 0xB, -1);
        }
        /* falls through */
    case 22:
        if (func_L01_004561B8(m) != 0) {
            pv->h[0x2F6 / 2] = 0;
        }
        func_L01_0045AA10(m, m->f[0xF8 / 4]);
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 0x12) {
                func_003C3A10(m, 0x12, 0, 3);
            }
            func_L01_004450F0(m, 8, -1);
        }
        break;
    case 25: {
        Obj_353EA0 *o;
        f32 t;
        if (func_L01_004561B8(m) != 0) {
            pv->f[0x1B8 / 4] = 2.0f;
            pv->f[0x1BC / 4] = 2.0f;
        }
        if (pv->f[0x358 / 4] < 1.0f) {
            pv->f[0x358 / 4] = pv->f[0x358 / 4] + D_L01_001DD5D4;
            if (pv->f[0x358 / 4] > 1.0f) {
                pv->f[0x358 / 4] = 1.0f;
            }
            m->f[0x2C / 4] = ((Obj_353EA0 *)m->ptr[0x24 / 4])->f[0x24 / 4] * pv->f[0x358 / 4];
        }
        pv->f[0x120 / 4] = pv->f[0x120 / 4] * D_L01_001DD5DC;
        t = pv->f[0x118 / 4];
        pv->i[0x118 / 4] = 0;
        func_0038CF68(&pv->b[0x110], &pv->b[0x110], pv->f[0x120 / 4]);
        pv->f[0x118 / 4] = t;
        pv->f[0x9C / 4] = 0.00392f;
        if (0.0f < t) {
            pv->f[0x9C / 4] = 0.00196f;
        }
        if (pv->ptr[0x354 / 4] != 0) {
            ((Obj_353EA0 *)pv->ptr[0x354 / 4])->i[0x98 / 4] = 0;
        }
        if (func_L01_0045C2A0(m, D_L01_001DD5B4, D_L01_001DD5B8, D_L01_001DD5BC) != 0) {
            m->f[0x48 / 4] = 1.0f;
            func_L01_0045A9F0(m);
            pv->f[0x9C / 4] = 0.00392f;
            pv->f[0x1BC / 4] = 0.75f;
            pv->f[0x1B8 / 4] = 0.2f;
            func_L01_004450F0(m, 0xB, 3);
            if (m->b[0x43] != 0x13) {
                func_003C3A10(m, 0x13, func_00382498(0, 0x14), 0);
            }
        }
        if ((o = (Obj_353EA0 *)pv->ptr[0x354 / 4]) != 0) {
            o->i[0x98 / 4] = ((Obj_353EA0 *)o->ptr[0x24 / 4])->i[0x10 / 4];
        }
        break;
    }
    }
    vec_sub_ab(&s10, &s0, &m->q[1]);
    if (func_0038CEA8(&s10) < pv->f[0x98 / 4] * 0.5f) {
        pv->i[0x3B0 / 4]++;
    }
    func_L01_003565E0(m);
}
/* localdecomp:end func_L01_00353EA0 */

/* localdecomp:start func_L01_00355D88 */
extern s32 func_L01_00356050(void *);
extern void func_L01_00356588(void *);
extern void func_L01_00356668(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L01_0044FD88(void *, s32, s32, s32);
extern void func_L01_00452860(void *, void *, s32);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, f32, void *, s32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 D_L01_001E2A40[];
extern s32 D_001DD61C_sda;
__asm__(".extern D_001DD61C_sda, 4");
s32 func_L01_00355D88(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 0) {
        if (func_L01_00356050(a0) != 0) return 1;
    }
    if (p[0x3e] == 2) goto L68;
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L01_001E2A40, a0 + 0x10) < 576.0f) {
            func_L01_004472C0(a0);
            a0[0x6f] = 0x16;
        }
    }
    if (*(s32 *)(p + 0x360) != 0) func_L01_0044FD88(a0, *(s32 *)(p + 0x360), 1, D_001DD61C_sda);
    func_L01_00452860(a0, p + 0x30, 0);
    if (func_L01_00452FB0(a0, p + 0x160, 0, 0, 0) != 0) func_L01_00356668(a0);
    if (p[0x5e] != 0) {
L68:
        func_L01_00356588(a0);
        return 1;
    }
    if (p[0x5f] != 0) {
        if ((*(unsigned long *)(a0 + 0x30) & 0x104100000000ul) != 0x4100000000ul || *(s32 *)(a0 + 0x98) != 0) {
            if (0.0f < *(f32 *)(p + 0x30)) func_L01_00456BD0(a0, 5);
        }
        if (a0[0x95] == 1) {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2E0), *(f32 *)(p + 0x2E4), p + 0x320, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2E8), *(f32 *)(p + 0x2EC), p + 0x320, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        }
    } else {
        if ((*(unsigned long *)(a0 + 0x30) & 0x104100000000ul) != 0x4100000000ul || *(s32 *)(a0 + 0x98) != 0) {
            if (0.0f < *(f32 *)(p + 0x30)) func_L01_00456BD0(a0, 3);
        }
        if (a0[0x95] == 1 || a0[0x95] == 4) {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2E0), *(f32 *)(p + 0x2E4), p + 0x320, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2E8), *(f32 *)(p + 0x2EC), p + 0x320, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
        }
    }
    return 0;
}
/* localdecomp:end func_L01_00355D88 */

/* localdecomp:start func_L01_00356050 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_356050;
typedef struct { void (*fn0)(void *); } Vt_356050;
extern s32 func_00443948(s32);
extern s32 func_00443978(s32, s32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_00459218(void *, void *, s32, void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void *func_L01_0043B548(s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void *func_003C24B0(s32, s32);
extern void func_L01_00456160(void *, void *);

extern s32 D_001D545C;
extern u8 *D_001E001C_sda;
__asm__(".extern D_001E001C_sda, 4");

s32 func_L01_00356050(void *arg) {
    u8 *obj = arg;
    u8 *p = *(u8 **)(obj + 0x68);
    s32 one;
    s32 flag;
    s32 x;
    f32 a, b;
    Vt_356050 *t;
    if (func_00443948(2)) *(u16 *)(obj + 0x34) |= 0x8000;
    one = 1;
    *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24);
    *(V4_356050 *)(p + 0x300) = *(V4_356050 *)(obj + 0x10);
    *(V4_356050 *)(p + 0x320) = *(V4_356050 *)(obj + 0x10);
    *(f32 *)(p + 0x318) = func_L01_00443A18(0.0f, 20.0f) * 0.01745329238474369f;
    func_L01_00459218(obj, p + 0x3F0, 12, p + 0x36C);
    p[0x1D7] = one;
    p[0x170] = 0x1B;
    p[0x1A8] = 7;
    *(f32 *)(p + 0x190) = 0.5f;
    *(f32 *)(p + 0x194) = 0.5f;
    *(f32 *)(p + 0x19C) = 0.15000000596046448f;
    if (func_00443948(2)) {
        p[0x1D3] = 0x11;
        p[0x1D2] = 0xB;
        p[0x176] = 0;
    } else {
        p[0x176] = one;
        p[0x1D3] = 0x13;
        p[0x1D2] = 0xA;
    }
    *(f32 *)(p + 0x17C) = 0.30000001192092896f;
    *(f32 *)(p + 0x180) = 0.020000001415610313f;
    *(f32 *)(p + 0x184) = 0.010000000707805157f;
    *(f32 *)(p + 0x188) = 0.014000000432133675f;
    *(f32 *)(p + 0x18C) = 0.000800000037997961f;
    p[0x1DB] = 0xFF;
    p[0x1D8] = 0;
    p[0x1D9] = 0;
    p[0x1DA] = 0;
    a = 1.0f;
    b = 0.5f;
    *(f32 *)(p + 0x1A0) = *(f32 *)(obj + 0x18) - 10.0f;
    *(f32 *)(p + 0x70) = 0.44999998807907104f;
    *(f32 *)(p + 0x74) = 0.25f;
    *(f32 *)(p + 0x80) = 1.3089969158172607f;
    *(f32 *)(p + 0xA0) = 0.3490658402442932f;
    *(f32 *)(p + 0x9C) = 0.0020000000949949026f;
    *(f32 *)(p + 0x78) = b;
    *(f32 *)(p + 0x7C) = a;
    *(f32 *)(p + 0x210) = a;
    func_L01_0045BD78(obj, 0.003200000151991844f, 0.10000000894069672f, 0.005026548635214567f, 0.12566371262073517f);
    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    if (*(s16 *)(p + 0x34) == 0) {
        *(f32 *)(p + 0x30) = a;
        *(s16 *)(p + 0x34) = 1;
    }
    *(f32 *)(p + 0x40) = b;
    flag = 0;
    p[0x38] = 0;
    p[0x39] = 1;
    p[0x3E] = 1;
    p[0x5E] = 0;
    p[0x5F] = 0;
    *(s32 *)(p + 0x2F0) = 0;
    *(s16 *)(p + 0x2F4) = 0;
    *(s32 *)(p + 0x2F8) = 0;
    *(s32 *)(p + 0x340) = 0;
    *(s32 *)(p + 0x35C) = 0;
    if (*(s32 *)(p + 0x250) > 0) {
        t = func_L01_0043B548(0x19E1, 0x6C);
        *(s32 *)(p + 0x250) = -1;
        flag = 1;
        if (obj[0x43] != 5) func_003C3A10(obj, 5, 0, 0);
        p[0x25E] = 0x1A;
        p[0x25F] = 6;
        t->fn0(obj);
    } else if (*(s32 *)(p + 0x350) != 0) {
        func_L01_004450F0(obj, 0x18, 5);
        *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(obj + 0x98) = 0;
        func_L01_004AA7E8(obj, 1);
        if (*(u8 **)(p + 0x360) != 0) {
            *(u16 *)(*(u8 **)(p + 0x360) + 0x34) |= 0x41;
            *(u16 *)(*(u8 **)(p + 0x360) + 0x34) &= 0xEFFF;
            *(s32 *)(*(u8 **)(p + 0x360) + 0x98) = 0;
            func_L01_004AA7E8(*(u8 **)(p + 0x360), 1);
        } else {
        }
    } else {
        s32 id = *(s32 *)(p + 0x344);
        if (id != -1) {
            s32 h = *(s16 *)(D_001E001C_sda + (id << 8) + 0xAA);
            if (h == 0x19B1 || h == 0x1AB4) flag = 1;
            func_L01_004450F0(obj, 3, 0);
            if (obj[0x43] != 5) {
                func_003C3A10(obj, 5, func_00443978(0, 5), 0);
            } else {
            }
        } else {
            func_L01_004450F0(obj, 7, 1);
            if (obj[0x43] != 0x12) {
                func_003C3A10(obj, 0x12, func_00443978(0, 10), 0);
            }
        }
    }
    x = D_001D545C;
    if ((x == 1 || x == 0x60) && flag == 0) {
        void *q = func_003C24B0(0x1AA2, 0x80);
        *(void **)(p + 0x360) = q;
        func_L01_00456160(q, obj);
        *(void **)(p + 0x240) = *(void **)(p + 0x360);
    }
    return 0;
}
/* localdecomp:end func_L01_00356050 */

/* localdecomp:start func_L01_003564D0 */
typedef struct {
    void (*fn0)(void *);
    void (*fn1)(void *);
} Vt_003564D0;

extern void *func_L01_0043B548(s32, s32);
extern void func_003C2880(void *);

void func_L01_003564D0(u8 *obj, s32 a1) {
    u8 *p = *(u8 **)(obj + 0x68);

    if (*(void **)(p + 0x360) != 0) {
        func_003C2880(*(void **)(p + 0x360));
        *(void **)(p + 0x360) = 0;
        *(s32 *)(p + 0x240) = 0;
    }
    if (*(s32 *)(p + 0x250) != 0) {
        Vt_003564D0 *t = func_L01_0043B548(6625, 108);
        t->fn0(obj);
        if (a1 != 0) {
            t->fn1(obj);
        }
    } else {
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L01_003564D0 */
