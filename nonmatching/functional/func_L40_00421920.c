/* functional: medium. Written from the PAL assembly (no twin existed); the object-list walk follows func_L40_0053E000's form. The mob list terminator/continuation test (p[-1] >= 0 || p == first) is read straight from the asm. */
extern u16 *D_L40_0028EA20[];
extern u8 *D_L40_0035746C __attribute__((section(".data")));
extern u8 *D_L40_0024845C;
extern s32 D_L40_00248498;
extern u8 D_L40_00249FC0[];
extern s32 func_L40_0053DAE8(s32, s32);
extern s32 func_L40_0053F850(u8 *, u8 *, s32);
extern s32 func_L40_0053F018(u8 *);
extern void func_L39_0066C470(s32);
extern void func_L40_00421300(s32, u8 *);
extern void func_L40_00420A38(u8 *, u8 *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00421920;

void func_L40_00421920(u8 *m, u8 *v, s32 t) {
    f32 f20;
    s32 r;

    if (m[0x20] == 0) {
        V_00421920 pos;
        f32 keep;
        u16 *p;
        s32 cnt;
        s32 idx;
        u8 *e;

        func_L40_0053DAE8(t, *(s32 *)(D_L40_0035746C + *(s32 *)(v + 0x290) * 4 + 0x88));
        keep = *(f32 *)(v + 0x2B4);
        *(u16 *)(v + 0x118) = *(u16 *)(v + 0x118) & 0xFFFC;
        v[0xF0] = 3;
        v[0x3E] = 1;
        v[0xF2] = 0xFF;
        v[0x128] = 0xFF;
        v[0xF1] = 0xFF;
        *(f32 *)(v + 0x13C) = 0.0005f;
        *(f32 *)(v + 0x138) = 0.0001f;
        *(f32 *)(v + 0x30) = keep;
        *(s32 *)(v + 0x298) = 0;
        pos = *(V_00421920 *)(m + 0x10);
        pos.z = pos.z + 1.0f;
        *(f32 *)(m + 0x18) = func_003C3D30(&pos, 0, 0, 0.5f);

        cnt = 0;
        p = D_L40_0028EA20[*(s32 *)(v + 0x464)];
        for (;;) {
            idx = *(s32 *)(v + 0x464);
            if ((idx & 0xFF) == 0xFF || D_L40_00248498 < idx || p == 0) {
                break;
            }
            if ((s16)p[-1] < 0 && p != D_L40_0028EA20[idx]) {
                break;
            }
            e = D_L40_0024845C + ((*p & 0x7FFF) << 8);
            if (e == 0) {
                break;
            }
            if (cnt < 6) {
                *(u8 **)(v + 0x310 + cnt * 4) = e;
                *(s32 *)(v + 0x328 + cnt * 4) = 0;
                cnt++;
            }
            p++;
            *(u16 *)(e + 0x34) = *(u16 *)(e + 0x34) & 0xFFBE;
            *(u16 *)(e + 0x34) = *(u16 *)(e + 0x34) | (*(u16 *)(*(u8 **)(e + 0x24) + 0x44) & 0x1000);
            *(s32 *)(e + 0x98) = *(s32 *)(*(u8 **)(e + 0x24) + 0x10);
        }
        func_L01_004450F0(m, 1, -1);
    }
    *(u16 *)(m + 0x34) = *(u16 *)(m + 0x34) | 0x1000;
    f20 = *(f32 *)(v + 0x30);
    r = func_L40_0053F850(m, v + 0xE0, 0);
    if (f20 != *(f32 *)(v + 0x30)) {
        func_L39_005F33E0(1, 0, m);
    }
    if (r == 4 || *(f32 *)(v + 0x30) < 0.0f) {
        if (func_L40_0053F018(m) != 0 || *(f32 *)(v + 0x30) < 0.0f) {
            func_L39_0066C470(t);
        }
    }
    func_L40_00421300(t, m);
    func_L40_00420A38(m, v);
    if (m[0x31] != 0) {
        if (func_L01_0040E548(D_L40_00249FC0, m + 0x10) < 256.0f) {
            func_L01_004472C0(m);
            m[0x6F] = 0xF;
        }
    }
}
