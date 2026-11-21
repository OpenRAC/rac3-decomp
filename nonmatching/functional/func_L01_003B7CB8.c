/* functional: medium. Not byte-matched. COP2 lqc2/vadd.xyz/vsub.xyz/sqc2 written as plain float xyz math with w kept from the first operand; the 128-bit zero stores as four float zeroes. Retail passes a 0x20-byte stack struct (sp+0x30..0x4F) to func_003D3CB0 whose bytes 0x10..0x17 are leftovers of the effect block (uninitialised when the effect is skipped); st.b mirrors that. fx[0]|=1 reads the retail stack slot at sp+0x50 (also leftover when the effect is skipped). */
extern f32 D_L01_001DFB4C;
extern f32 D_L01_001DFB50;
extern s32 D_L01_001DFB40[];
extern u8 *D_L01_001EAA18;
extern u8 D_L01_001D66B0[];
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern s32 func_0038CAD0(u8 *);
extern s32 func_0013D3E0(void);
extern void func_003C2880(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_L01_003FB640(f32 *, s32, u8 *, f32);
extern void func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_00466588(void *, void *, s32, s32, s32, s32, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_0044AF78(void *, void *, void *, f32, f32, f32, s32, s32, s32, f32, f32, s32, s32, f32, f32, s32, s32, s32, s32);

void func_L01_003B7CB8(u8 *m) {
    f32 newpos[4] __attribute__((aligned(16)));
    struct { f32 a[4]; f32 b[4]; } st __attribute__((aligned(16)));
    f32 fx[4] __attribute__((aligned(16)));
    u8 *vars;
    u8 *other;
    f32 *pos;
    f32 len;
    s32 flag, i;
    f32 *vv;

    if (m[0x20] != 1) {
        return;
    }
    vars = *(u8 **)(m + 0x68);
    pos = (f32 *)(m + 0x10);
    vv = (f32 *)vars;

    *(f32 *)(m + 0xF0) = func_0038DAB8(*(f32 *)(m + 0xF0), 0.12566371f);

    flag = 0;
    newpos[0] = pos[0] + vv[0];
    newpos[1] = pos[1] + vv[1];
    newpos[2] = pos[2] + vv[2];
    newpos[3] = pos[3];
    if (0.9f < D_L01_001DFB4C) {
        flag = 1;
    } else if (0.9f < D_L01_001DFB50) {
        flag = 1;
    }

    if (!(flag != 0 && (D_L01_001DFB40[0] & 1) != 0)) {
        len = func_0038CEA8(vars);
        for (i = 0; i < 4; i++) {
            fx[i] = 0.0f;
        }
        fx[0] = func_003824E0(-1.0f, 1.0f);
        fx[1] = func_003824E0(-1.0f, 1.0f);
        fx[2] = func_003824E0(-1.0f, 1.0f);
        st.b[0] = fx[0];
        st.b[1] = fx[1];
        st.b[2] = fx[2];
        st.b[3] = fx[3];
        {
            f32 r = func_003824E0(0.04f, 0.08f);
            func_0038CF68(st.b, st.b, r * 0.020000001f);
        }
        func_0038CE20(st.a, vars, func_003824E0(0.2f, 0.99f));
        st.b[0] = st.b[0] + st.a[0];
        st.b[1] = st.b[1] + st.a[1];
        st.b[2] = st.b[2] + st.a[2];
        func_0038CF68(st.a, vars, func_003824E0(0.0f, 1.0f) * len);
        st.a[0] = st.a[0] + pos[0];
        st.a[1] = st.a[1] + pos[1];
        st.a[2] = st.a[2] + pos[2];
        func_L01_0046A610(pos, st.b, 6, 0x7F, 0xB0B0B0, 3, 40000.0f, 1000.0f, 1.0f, -0.0004f, 0.0f);
        for (i = 0; i < 4; i++) {
            fx[i] = 0.0f;
        }
        fx[2] = 0.01f;
        func_0038D000(fx, fx, m + 0xC0);
        func_0038D890(fx, fx, m + 0xC0, func_00382538());
        if (func_0013D3E0() & 1) {
            func_L01_00466588(st.a, fx, 0x4F007FFF, 0x1FFFFFFF, 0xB, 1, 25000.0f);
        }
    }

    func_L01_00446760(st.a, *(void **)(m + 0xB8), 0x10001, vars, *(f32 *)(vars + 0x14));
    other = *(u8 **)(m + 0xB8);
    *(u16 *)((u8 *)st.b + 0xA) = *(u16 *)(m + 0xAA);
    st.a[0] = pos[0] - ((f32 *)other)[4];
    st.a[1] = pos[1] - ((f32 *)other)[5];
    st.a[2] = pos[2] - ((f32 *)other)[6];
    st.a[2] = 0.0f;
    func_0038CF68(st.a, st.a, 2.0000002f);
    *(s32 *)&fx[0] = *(s32 *)&fx[0] | 1;
    st.a[3] = 5627.925f;
    ((u8 *)st.b)[8] = 4;
    if (func_003D3CB0(pos, newpos, 0, other, st.a) == 0
        && func_L01_003FB640(pos, 1, other, 0.3f) == 0
        && func_0038CAD0(vars + 0x10) == 0) {
        *(f32 *)(m + 0x10) = newpos[0];
        *(f32 *)(m + 0x14) = newpos[1];
        *(f32 *)(m + 0x18) = newpos[2];
        *(f32 *)(m + 0x1C) = newpos[3];
        return;
    }
    if (D_L01_001EAA18 == 0) {
        func_L01_0044AF78(m, D_L01_001D66B0, 0, 0.0f, 0.0f, 0.0f, 2, 8, -1, 0.0f, 0.0f, 9.0f, 0.5f, 0.0f, 0, 1, -1, 0, 0x1010001);
        func_003C2880(m);
        return;
    }
    if (D_L01_001EAA18 == other) {
        *(f32 *)(m + 0x10) = newpos[0];
        *(f32 *)(m + 0x14) = newpos[1];
        *(f32 *)(m + 0x18) = newpos[2];
        *(f32 *)(m + 0x1C) = newpos[3];
        return;
    }
    if (*(s16 *)(D_L01_001EAA18 + 0xAA) != 0x4E) {
        func_003D4D00(pos, 0, other, st.a, 0.5f);
    }
    func_L01_0044AF78(m, D_L01_001D66B0, 0, 0.0f, 0.0f, 0.0f, 2, 10, -1, 0.0f, 0.0f, 9.0f, 0.666f, 0.0f, 0, 1, -1, 0, 0x1010001);
    func_003C2880(m);
}
