/* functional: high. Written from asm; constants from hex immediates (retail reloads shared constants instead of keeping them in f20/f21, so the frame/regs differ); uses the file's E_4999A0 row type; counted loop order read against asm */
typedef struct {
    s32 x0, x4, x8, xC, x10, x14;
    f32 x18, x1C, x20, x24, x28, x2C, x30, x34;
    s32 x38, x3C, x40, x44, x48, x4C, x50;
} P_0049D2E8;
extern s32 D_L01_002EC1D8[];
extern char D_L01_001D94B8[];
extern s32 D_001D946C_sda;
__asm__(".extern D_001D946C_sda, 4");
extern s32 func_L01_0047DAE0(void);
extern s32 func_003BB118(s32);
extern s32 func_00381FF0(s32);
extern void func_003B9C68(s32, P_0049D2E8 *);
extern void func_003BABB0(s32, s32, f32, f32, f32, f32, f32);
extern void func_003BABD0(s32, f32, f32, f32, f32);
extern void func_003BA4E0(s32, s32, f32, f32, f32);
extern char *func_003B9E30(s32, s32, s32);
extern s32 func_0011B2E8(char *, char *, ...);

void func_L01_0049D2E8(void) {
    P_0049D2E8 st;
    s32 n = 0, cnt, idx = 0, j = 0;
    E_4999A0 *p;
    s32 *out;
    char *s;

    D_001D946C_sda = 0;
    if (D_L01_002EC368[0].w0 > 0) {
        p = D_L01_002EC368;
        cnt = 0;
        do {
            if (p->flag != 0) cnt++;
            p++;
            n++;
        } while (p->w0 > 0);
        D_001D946C_sda = cnt;
    }
    if (D_001D946C_sda != 0) {
        st.x0 = func_L01_0047DAE0();
        st.x4 = func_003BB118(0);
        st.x8 = 20;
        st.xC = D_001D946C_sda;
        st.x10 = (D_001D946C_sda < 6) ? D_001D946C_sda : 5;
        st.x14 = 1;
        st.x18 = 1.0f;
        st.x1C = 0.572000027f;
        st.x20 = 0.0635600016f;
        st.x24 = 0.5f;
        st.x28 = 1.0f;
        st.x2C = 1.0f;
        st.x30 = 1.0f;
        st.x34 = 0.795206010f;
        st.x38 = 0; st.x3C = 0; st.x40 = 0; st.x44 = 0; st.x48 = 0; st.x4C = 0; st.x50 = 0;
        func_003B9C68(func_003B9BD0(0), &st);
        func_003BABB0(func_003B9BD0(0), 0, 0.500369012f, 0.816536009f, 0.0450000018f, 0.0425000004f, 0.349999994f);
        func_003BABD0(func_003B9BD0(0), 0.500369012f, 0.698702991f, 0.816536009f, 0.314705998f);
        func_003BA4E0(func_003B9BD0(0), 1, 0.0329999998f, 0.00665999996f, 0.0299999993f);
        if (n > 0) {
            out = &D_L01_002EC1D8[idx];
            p = D_L01_002EC368;
            do {
                if (p->flag != 0) {
                    *out = j;
                    out++;
                    s = func_003B9E30(func_003B9BD0(0), 0, idx);
                    idx++;
                    func_0011B2E8(s, D_L01_001D94B8, func_00381FF0(p->w0));
                }
                j++;
                p++;
            } while (j < n);
        }
    }
}
