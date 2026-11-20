/* functional: high. No draft; written from the asm. Float literals reproduced from the hex immediates (9 digits). Retail f20/f21 swap and constants via ps2as only: scheduling diff, same semantics. sprintf is func_0011B2E8(buf, fmt, ...) as in other level code */
typedef struct {
    s32 x0, x4, x8, xC, x10, x14;
    f32 x18, x1C, x20, x24, x28, x2C, x30, x34;
    s32 x38, x3C, x40, x44, x48, x4C, x50;
} P_0049C338;
extern char D_L01_001D9460[];
extern s32 D_L01_001D9400;
__asm__(".extern D_L01_001D9400, 4");
extern s32 func_L01_0047DAE0(void);
extern s32 func_003BB118(s32);
extern void func_003B9C68(s32 *, P_0049C338 *);
extern void func_003BABB0(s32 *, s32, f32, f32, f32, f32, f32);
extern void func_003BABD0(s32 *, f32, f32, f32, f32);
extern void func_003BA4E0(s32 *, s32, f32, f32, f32);
extern void func_L01_00498948(s32 *, s32, s32);
extern char *func_003B9E30(s32 *, s32, s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern void func_L01_004986A8(s32 *, s32);

void func_L01_0049C338(void) {
    P_0049C338 st;
    s32 n, i;
    E_498978 *p;
    char *s;

    n = 0;
    while (D_L01_002EBED8[n].x0 > 0) n++;
    i = 0;
    st.x0 = func_L01_0047DAE0();
    st.x4 = func_003BB118(0);
    st.x8 = 20;
    st.xC = n;
    st.x10 = (n < 6) ? n : 5;
    st.x14 = 1;
    st.x18 = 1.0f;
    st.x1C = 0.699119985f;
    st.x20 = 0.0635600016f;
    st.x24 = 0.5f;
    st.x28 = 1.0f;
    st.x2C = 1.0f;
    st.x30 = 1.0f;
    st.x34 = 0.795206010f;
    st.x38 = 0; st.x3C = 0; st.x40 = 0; st.x44 = 0; st.x48 = 0; st.x4C = 0; st.x50 = 0;
    func_003B9C68(func_003B9BD0(0), &st);
    func_003BABB0(func_003B9BD0(0), 0, 0.5f, 0.816536009f, 0.0450000018f, 0.0425000004f, 0.349999994f);
    func_003BABD0(func_003B9BD0(0), 0.500369012f, 0.764262974f, 0.816536009f, 0.185586005f);
    func_003BA4E0(func_003B9BD0(0), 1, 0.0329999998f, 0.00665999996f, 0.0299999993f);
    D_L01_001D9400 = 0;
    if (n > 0) {
        p = D_L01_002EBED8;
        do {
            if (p->x14 != 0) {
                func_L01_00498948(func_003B9BD0(0), i, 0);
                s = func_003B9E30(func_003B9BD0(0), 0, i);
                func_0011B2E8(s, D_L01_001D9460, func_00381FF0(p->x0));
            } else {
                D_L01_001D9400 = 1;
                func_L01_00498948(func_003B9BD0(0), i, 1);
                s = func_003B9E30(func_003B9BD0(0), 0, i);
                func_0011B2E8(s, D_L01_001D9460, func_00381FF0(0x1C8));
            }
            i++;
            p++;
        } while (i < n);
    }
    if (D_L01_001D9400 != 0) {
        func_L01_004986A8(func_003B9BD0(0), 1);
    }
}
