/* functional: medium. functional: loops, argument order and constants verified against the asm */
typedef struct {
    s32 w0;
    u8 u4;
    u8 pad5[0xA3];
    s32 xA8;
    void (*fnAC)(s32, s32);
} E_lv100_AAE8;
typedef struct {
    s32 y;
    s32 x;
} P_lv100_AAE8;
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    f32 f34;
    s32 z[7];
} S_lv100_AAE8;
extern E_lv100_AAE8 D_L01_00233DD8_0048AAE8[];
extern P_lv100_AAE8 D_L01_002E9DC0_0048AAE8[];
extern s32 D_00143050[];
extern s32 D_L01_002EAEC0[];
extern char D_L01_001D8BA8[];
extern s32 D_L01_001D8A3C;
extern f32 D_L01_001D8B2C, D_L01_001D8B30, D_L01_001D8B34, D_L01_001D8B38, D_L01_001D8B3C;
extern s32 func_0011A264(void *, s32, s32);
extern void func_L01_0048AA70(s32, s32);
extern s32 func_L01_0047DAE0(void);
extern s32 func_003BB118(s32);
extern s32 func_003B9BD0(s32);
extern void func_003B9C68(s32, void *);
extern void func_003BABB0(s32, s32, f32, f32, f32, f32, f32);
extern void func_003BABD0(s32, f32, f32, f32, f32);
extern void func_003BA4E0(s32, s32, f32, f32, f32);
extern void func_L01_00498F18(s32, s32, s32);
extern void func_L01_00498948(s32, s32, s32);
extern s32 func_003B9E30(s32, s32, s32);
extern s32 func_00381FF0(s32);

void func_L01_0048AAE8(void) {
    S_lv100_AAE8 st;
    s32 k;
    s32 w;
    s32 idx;
    s32 i;
    s32 dst;
    s32 s;

    D_L01_001D8A3C = 0;
    func_0011A264(D_L01_00233DD8_0048AAE8, 0x14A0, 0);
    for (k = 0; k < 60; k++) {
        w = D_00143050[k];
        if (w == 0 || w == 1 || w == 0x1C || w == 0x1B || w == 6 || w == 0x1D || w == 0x17 || w == 0x1A) {
            continue;
        }
        if (w == 0x14) {
            continue;
        }
        if (D_L01_001D8A3C < 0 && w >= 2) {
            D_L01_001D8A3C = 0;
        }
        idx = D_L01_001D8A3C;
        D_L01_001D8A3C = idx + 1;
        D_L01_00233DD8_0048AAE8[idx].w0 = D_00143050[k];
        D_L01_00233DD8_0048AAE8[idx].xA8 = D_L01_002EAEC0[D_00143050[k] - 1];
        D_L01_00233DD8_0048AAE8[idx].fnAC = func_L01_0048AA70;
        D_L01_00233DD8_0048AAE8[idx].u4 = 1;
    }
    st.w0 = func_L01_0047DAE0() - 0x800;
    st.w4 = func_003BB118(1);
    st.w8 = 0x14;
    st.wC = D_L01_001D8A3C;
    st.w10 = (D_L01_001D8A3C < 8) ? D_L01_001D8A3C : 7;
    st.w14 = 1;
    st.f18 = 1.0f;
    st.f1C = 0.38509601354599f;
    st.f20 = 0.055399999022483826f;
    st.f24 = D_L01_001D8B2C;
    st.f28 = 1.0f;
    st.f2C = 1.0f;
    st.f30 = 1.0f;
    st.f34 = D_L01_001D8B34 - (D_L01_001D8B3C + D_L01_001D8B3C);
    st.z[0] = 0;
    st.z[1] = 0;
    st.z[2] = 0;
    st.z[3] = 0;
    st.z[4] = 0;
    st.z[5] = 0;
    st.z[6] = 0;
    func_003B9C68(func_003B9BD0(0), &st);
    func_003BABB0(func_003B9BD0(0), 0, D_L01_001D8B2C, st.f34, 0.04500000178813934f, 0.042500000447034836f, 0.3499999940395355f);
    func_003BABD0(func_003B9BD0(0), D_L01_001D8B2C, D_L01_001D8B30, D_L01_001D8B34 - 0.00800000037997961f, D_L01_001D8B38 - 0.009999999776482582f);
    func_003BA4E0(func_003B9BD0(0), 1, 0.026499999687075615f, 0.006659999955445528f, 0.029999999329447746f);
    func_L01_00498F18(func_003B9BD0(0), 0, 1);
    if (D_L01_001D8A3C > 0) {
        i = 0;
        do {
            func_L01_00498948(func_003B9BD0(0), i, 0);
            dst = func_003B9E30(func_003B9BD0(0), 0, i);
            w = D_L01_00233DD8_0048AAE8[i].w0;
            if (w == 1 || w == 2 || w == 4 || w == 8 || w == 0x1B || w == 0x1C || w == 9 || w == 0x1D || w == 5 || w == 0xD || w == 0x17 || w == 0xA || w == 0x12 || w == 0xE) {
                if (w > 0) {
                    s = D_L01_002E9DC0_0048AAE8[w % 0x3C].x;
                } else {
                    s = D_L01_002E9DC0_0048AAE8[1].x;
                }
            } else {
                if (w > 0) {
                    s = D_L01_002E9DC0_0048AAE8[w % 0x3C].y;
                } else {
                    s = D_L01_002E9DC0_0048AAE8[1].y;
                }
            }
            i++;
            func_0011B2E8((char *)dst, D_L01_001D8BA8, func_00381FF0(s));
        } while (i < D_L01_001D8A3C);
    }
}
