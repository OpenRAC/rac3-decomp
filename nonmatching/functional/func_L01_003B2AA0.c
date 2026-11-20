/* functional: high. V table offsets fixed (f1C/f24/f28/f2C at 0x1C/0x24/0x28/0x2C; pointers are 4 bytes). Same control flow, reads, writes and calls; only the D_L01_001E001C access (gp vs lui form) and scheduling differ. */
typedef struct {
    u8 p0[0x14];
    void (*f14)(s32);
    u8 p18[4];
    s32 (*f1C)(void);
    u8 p20[4];
    void (*f24)(s32, s32);
    void (*f28)(s32);
    void (*f2C)(void *, f32);
} V_003B2AA0;

typedef struct {
    u8 p0[0x10];
    s32 w10;
    u8 p14[4];
    s32 w18;
    u8 p1C[0x10];
    f32 f2C;
    s32 w30;
    s32 w34;
    s32 w38;
    u8 p3C[4];
    s32 w40;
    u8 p44[4];
    s32 w48;
    u8 p4C[4];
    u8 b50;
    u8 p51[0xB];
    s32 w5C;
    s32 w60;
} P_003B2AA0;

extern u8 *D_L01_001E001C;
extern s32 D_L01_001DFB40;
extern s32 D_001D545C[];
extern u8 D_001BBC40[];
extern u8 D_001426E0[];
extern u8 D_001A4BE0[];
extern s32 D_001A71A4[];
extern V_003B2AA0 *func_L01_0043B548(s32, s32);
extern void func_L01_0041A3F0(s32, s32);
extern void func_L01_004450F0(s32, s32, s32);
extern void func_L01_005003D0(s32, s32);
extern s32 func_L01_00511A98(void);
extern void func_L01_00504E38(s32);
extern void func_L01_003B29A8(void *);
extern void func_L01_003B3098(void *);
extern void func_L01_0045F1E8(s32, s32);

void func_L01_003B2AA0(void *m, P_003B2AA0 *p) {
    V_003B2AA0 *v;
    s32 flag;
    s32 idx;

    v = func_L01_0043B548(0x19E1, 0x6C);
    flag = 0;
    idx = p->w5C;
    p->w60 = D_L01_001DFB40;
    if (idx != -1) {
        flag = (D_001BBC40[idx + (D_001D545C[0] << 4)] & 0x80) == 0;
    }
    if (p->w30 != 0) {
        u8 b = p->b50;
        if (b == 0) {
            v->f24(p->w34, flag);
            func_L01_004450F0((s32)m, 0xB, -1);
            if (p->w10 == -1 || flag != 0) {
                if (D_001A71A4[0] != 0xB0) {
                    v->f28(flag);
                    if (flag != 0 || p->f2C != 0.0f) {
                        v->f2C(D_001A4BE0, -100.0f);
                    } else {
                        func_L01_005003D0(0, 1);
                    }
                }
            }
        } else if (b == 0xFF) {
            func_L01_0041A3F0(-1, 1);
            return;
        } else {
            if (p->w40 != 0) {
                s32 x = (p->w40 & 0x7FF) | ((b & 0x1F) << 11);
                D_001426E0[0x72] = x;
                D_001426E0[0x71] = x >> 8;
            }
            func_L01_0041A3F0(p->b50, 1);
            return;
        }
    } else {
        if (v->f1C()) {
            v->f24(-2, flag);
            if (p->w10 == -1 || flag != 0) {
                if (D_001A71A4[0] != 0xB0) {
                    v->f28(flag);
                    v->f2C(0, -100.0f);
                }
            } else {
                goto st7;
            }
        }
        if (flag == 0) {
st7:
            func_L01_004450F0((s32)m, 7, -1);
        } else {
            func_L01_004450F0((s32)m, 5, -1);
        }
    }
    if (p->w10 == -1 || flag != 0) {
        if (D_001A71A4[0] != 0xB0) {
            if (!func_L01_00511A98()) {
                func_L01_00504E38(0);
            }
        }
    } else {
        v->f14(p->w38);
        func_L01_003B29A8(m);
        if (p->w30 != 0) {
            if (v->f1C() && p->f2C != 0.0f) {
                v->f2C(D_001A4BE0, -100.0f);
            }
        }
    }
    if (p->w30 == 0) {
        func_L01_003B3098(D_L01_001E001C + (p->w18 << 8));
    }
    if (p->w48 != -1) {
        func_L01_0045F1E8(p->w48, -1);
    }
}
