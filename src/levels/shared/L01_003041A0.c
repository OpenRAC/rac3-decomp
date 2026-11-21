#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_003041A0 */
typedef struct {
    u8 p0[1];
    u8 b1;
    u8 p2[0x6A];
    f32 f6C;
    u8 p70[0x80];
} RecF0_003041A0;
typedef struct {
    vu0_v4 v;
    u8 p10[8];
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 p1C[4];
    s32 w20;
} Hit_003041A0;
typedef struct {
    u8 p0[0x30];
    s32 w30;
    u8 p34[0xC];
} Ent40A_003041A0;
typedef struct {
    u8 p0[0x38];
    s32 w38;
    u8 p3C[4];
} Ent40B_003041A0;
typedef struct {
    u8 p0[0x514];
    s32 w514;
    u8 p518[0x530 - 0x518];
} Ent530_003041A0;
typedef struct {
    u8 p0[0x80];
} Row80_003041A0;
typedef struct {
    vu0_q q0;
    vu0_q q10;
    u8 p20[0x14];
    s32 w34;
    s32 w38;
    s32 w3C;
    s32 w40;
    s32 w44;
    s32 w48;
    u8 p4C[4];
    f32 f50;
    s32 w54;
    f32 f58;
    f32 f5C;
    s32 w60;
    s32 w64;
    s32 w68;
} V_003041A0;
typedef struct {
    u8 p0[0xBD8];
    s32 wBD8;
    u8 pBDC[0x1210 - 0xBDC];
    s32 w1210;
    u8 p1214[0x1224 - 0x1214];
    s32 w1224;
    u8 p1228[0x1430 - 0x1228];
    u8 *w1430;
    u8 p1434[0x25C0 - 0x1434];
    u8 *w25C0;
    s32 w25C4;
    u8 p25C8[0x25ED - 0x25C8];
    u8 b25ED;
    u8 p25EE[0x28BC - 0x25EE];
    s32 w28BC;
} G_003041A0;
typedef struct {
    u8 p0[0x1A0];
    s32 w1A0;
    s32 w1A4;
} H_003041A0;
extern u8 D_001425C0[];
extern u8 D_00142A60[];
extern RecF0_003041A0 D_L01_002C5600[];
extern G_003041A0 D_001A4BE0;
extern Row80_003041A0 D_001A30B0[];
extern H_003041A0 *D_001D52FC;
extern s32 D_L01_001D673C;
extern s32 D_L01_001D6694;
extern u8 *D_L01_001EEA80[];
extern Ent40A_003041A0 *D_L01_001DC5C0;
extern Ent40B_003041A0 *D_L01_001DC5C4;
extern Ent530_003041A0 *D_L01_001DC5C8;
__asm__(".extern D_L01_001DC5C0, 4");
__asm__(".extern D_L01_001DC5C4, 4");
__asm__(".extern D_L01_001DC5C8, 4");
extern s32 func_0038CAD0(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern s32 func_L01_004572B0(void *, s32, void *);
extern u8 *func_L01_00457480(s32, s32);
extern s32 func_L01_00304A58(s32);
extern void func_L01_004C8668(s32);
extern void func_L01_004482A0(void *, void *, f32, f32, f32, f32);
extern void func_L01_005118D0(s32, s32);
extern s32 func_L01_005119E0(s32);
extern s32 func_L01_004AA710(void *, s32);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
extern void func_L01_005003D0(s32, s32);
extern void func_L01_00457588(void *, void *, void *, f32);
extern void func_L01_003057A0(void *, void *, void *, s32);
extern void func_L01_00304C48(void *);
extern void func_L01_00304AA0(void *);
extern void func_L01_003068B8(void *);
extern void func_L01_00404A10_003041A0(void *, void *);
extern void func_L01_00305AB8(void *);

void func_L01_003041A0(u8 *m) {
    vu0_v4 vec;
    vu0_v4 v;
    Hit_003041A0 info;
    s32 out;
    s32 j;
    s32 n;
    u8 *mc;
    V_003041A0 *p;
    Ent40B_003041A0 *x;
    u8 *row;
    s32 i;
    s32 ok;
    s32 idx;

    i = 0;
    p = *(V_003041A0 **)(m + 0x68);
    func_0038CAD0(&p->w68);
    if ((D_L01_002C5600 + D_001425C0[0x11])->b1 >= 2) {
        D_00142A60[0x11] |= 0x20;
    }
    if (D_001A4BE0.w1224 == 3) {
        if (D_L01_001DC5C4 != 0) {
            for (; i < 0x23; i++) {
                x = &D_L01_001DC5C4[i];
                if (x->w38 >= 0) {
                    func_L01_004C8668(x->w38);
                    x->w38 = -1;
                }
            }
        }
    }
    if (m[0x20] == 0) {
        p->w34 = func_L01_004572B0(m, 0, &out);
        D_L01_001DC5C8 = (Ent530_003041A0 *)func_L01_00457480(*(s16 *)(m + 0xAA), p->w34);
        D_L01_001DC5C0 = (Ent40A_003041A0 *)func_L01_00304A58((s32)D_L01_001DC5C8 + 0x33E0);
        D_L01_001DC5C4 = (Ent40B_003041A0 *)func_L01_00304A58((s32)D_L01_001DC5C0 + 0x1F40);
        for (i = 0; i < 0x7D; i++) {
            D_L01_001DC5C0[i].w30 = 1;
        }
        for (i = 0; i < 10; i++) {
            D_L01_001DC5C8[i].w514 = 0;
        }
        for (i = 0; i < 0x23; i++) {
            D_L01_001DC5C4[i].w38 = -1;
        }
        p->w3C = 0;
        p->w48 = 0;
        p->w40 = 0;
        p->w44 = 0;
        p->w54 = 0;
        p->f50 = 0;
        p->f58 = 0;
        p->f5C = 0;
        p->w60 = 0;
        p->w64 = 0;
        m[0x20] = 1;
        p->w38 = -1;
    }
    if (D_001A4BE0.w1224 == 3) {
        idx = p->w38;
        if (idx != -1) {
            row = (u8 *)&D_001A30B0[idx];
            if (*(u8 **)(row + 0xDC) == m && row[0xD0] != 0) {
                func_003A4F28(idx);
            }
        }
        p->w38 = -1;
        return;
    }
    func_003C2F58(m, 0, p);
    ok = 1;
    if (D_001A4BE0.w25C4 == 0x1D) {
        if (func_0038CAD0(&D_001A4BE0.w28BC) == 0) {
            ok = 0;
        }
    } else {
        D_001A4BE0.w28BC = 0x21;
    }
    if ((D_001D52FC->w1A0 & D_001A4BE0.w1210) != 0 && ok != 0 && func_L01_005119E0(-1) != 0 &&
        D_001A4BE0.b25ED == 0) {
        func_L01_004482A0(&p->f50, &p->w54, 10.0f, 0.009000001f, 0.0024f, 12.0f);
        if (p->w60 % 10 == 0) {
            func_L01_005118D0(-1, 1);
        }
        p->w60 = p->w60 + 1;
        if (func_L01_004AA710(m, p->w38) == 0) {
            p->w38 = func_003A52A0(0, 4, m);
        }
        n = func_003D4D00(p, 0x10, m, 0, 0.5f);
        if (n != 0 && p->w68 == 0) {
            if ((D_L01_002C5600 + D_001425C0[0x11])->b1 >= 4) {
                p->w68 = 7;
                func_L01_004AAC98(1, 0, m, 0xC59);
            } else {
                p->w68 = 7;
                func_L01_004AAC98(1, 0, m, 0x5C9);
            }
        }
        mc = m + 0xC0;
        for (j = 0; j < n; j++) {
            if (D_L01_001EEA80[j] != D_001A4BE0.w25C0) {
                vec_sub_ab(&v, D_L01_001EEA80[j] + 0x10, m + 0x10);
                func_0038CF68(&v, &v, 1.0f);
                func_0038CF68(&info, &info, 1.0f);
                if ((D_L01_002C5600 + D_001425C0[0x11])->b1 >= 4) {
                    func_L01_00446760(&info, m, 0x11010000, &v, (D_L01_002C5600 + D_001425C0[0x11])->f6C);
                } else {
                    func_L01_00446760(&info, m, 0x01110000, &v, (D_L01_002C5600 + D_001425C0[0x11])->f6C);
                }
                info.v = *(vu0_v4 *)&v;
                info.v.w = 5627.925f;
                info.w20 = 1;
                info.b18 = 9;
                info.b19 = 1;
                info.h1A = *(u16 *)(D_L01_001EEA80[j] + 0xAA);
                func_L01_00446978(D_L01_001EEA80[j], &info);
                if (p->w68 == 0) {
                    if ((D_L01_002C5600 + D_001425C0[0x11])->b1 >= 4) {
                        p->w68 = 7;
                        func_L01_004AAC98(1, 0, m, 0xC59);
                    } else {
                        p->w68 = 7;
                        func_L01_004AAC98(1, 0, m, 0x5C9);
                    }
                }
            }
        }
    } else {
        idx = p->w38;
        if (idx != -1) {
            row = (u8 *)&D_001A30B0[idx];
            if (*(u8 **)(row + 0xDC) == m && row[0xD0] != 0) {
                func_003A4F28(idx);
            }
        }
        p->w38 = -1;
        if ((D_001D52FC->w1A4 & D_001A4BE0.w1210) != 0 && func_L01_005119E0(-1) == 0 && D_001A4BE0.b25ED == 0) {
            func_003A52A0(2, 0, m);
        }
        mc = m + 0xC0;
        func_L01_004482A0(&p->f50, &p->w54, 0.0f, 0.072000004f, 0.012f, 0.15f);
        p->w60 = 0;
    }
    if (D_001A4BE0.w25C4 == 1) {
        func_L01_005003D0(0x1D, 1);
    }
    func_003C2F58(m, 0, p);
    qzero(&vec);
    vec.y = -1.0f;
    func_0038D000(&vec, &vec, mc);
    vec.z = vec.z + 0.02f;
    func_0038CF68(&vec, &vec, p->f50 * 0.05f);
    if (D_001A4BE0.w1430 != 0) {
        D_001A4BE0.wBD8 = (s32)D_001A4BE0.w1430;
        func_L01_00457588(D_001A4BE0.w1430, p, &vec, p->f50 * 0.05f);
        if (D_L01_001D673C != 0) {
            func_0038CE20(&v, m + 0xE0, 0.02f);
            vec_add_ab(&vec, &vec, &v);
        } else {
            vec.z = vec.z + 0.02f;
        }
    }
    p->q10 = p->q0;
    if (D_001A4BE0.w25C4 != 0) {
        func_0038D890(&vec, &vec, D_001A4BE0.w25C0 + 0xD0, -0.09817477f);
    }
    if (p->f50 != 0.0f) {
        func_L01_003057A0(m, p, &vec, 0x21);
    }
    p->f58 = p->f58 - 0.1f;
    if (p->f58 <= -8.0f) {
        p->f58 = p->f58 + 8.0f;
    }
    p->f5C = p->f5C - 0.025f;
    if (p->f5C <= -8.0f) {
        p->f5C = p->f5C + 8.0f;
    }
    if (p->f50 != 0.0f) {
        func_L01_00304C48(m);
        func_L01_00304AA0(m);
    } else {
        p->w44 = 0;
        p->w3C = 0;
        p->w48 = 0;
        p->w40 = 0;
    }
    func_L01_003068B8(m);
    if (D_L01_001D6694 != 2 && m[0x31] != 0) {
        func_L01_00404A10_003041A0(func_L01_00305AB8, m);
    }
}
/* localdecomp:end func_L01_003041A0 */
