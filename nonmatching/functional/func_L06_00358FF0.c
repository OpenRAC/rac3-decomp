/* functional: medium. Same calls, args and order as retail; 374 instrs differ (scheduling/layout). Switch case targets inferred: jtbl_002BD0A0 not in the decomp tree, so state n -> n-th block in code order (each block starts anim n+1, a clean 1..6 chain). Case 4 reproduces retail's zeroing of v+0x10 before the atan2 reads of v+0x10/0x14 (gives atan2(0,0)). */
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_0038CAD0(s32 *);
extern f32 func_0038CED8(f32 *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern void func_0038D308(u8 *, u8 *);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_003A4FF8(u8 *, s32, s32, void *, s32);
extern s32 func_003A52A0(s32, s32, u8 *);
extern void func_003C2880(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_003D4D00(void *, f32, s32, void *, void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00404808(void *, void *);
extern s32 func_L01_003FB640(void *, f32, s32, u8 *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_004AA7E8(u8 *, s32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern void func_L06_00359A88(u8 *, u8 *);
extern s32 func_L06_003597A0(u8 *, u8 *);
extern void func_L06_00359CD0(void);
extern u8 *D_L06_001E8458;
extern s16 D_L06_001DD3D8[];
extern s16 D_L06_001DD3DA[];

typedef struct {
    vu0_v4 dir;
    u8 pad10[8];
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[4];
    s32 flags;
    u8 pad24[0x30 - 0x24];
} D_00358FF0;

void func_L06_00358FF0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 *t;
    u8 *owner;
    u8 *m;
    vu0_v4 q;
    D_00358FF0 dd;
    f32 s;
    f32 g;
    f32 h;
    s32 hit;

    switch (a0[0x20]) {
    case 1:
        s = (f32) * (s32 *)v / 100.0f;
        t = *(u8 **)(a0 + 0x24);
        *(f32 *)(a0 + 0x2C) = (*(f32 *)(t + 0x24) + *(f32 *)(t + 0x24)) * s;
        *(s16 *)(v + 0x38) = (s32)((f32)D_L06_001DD3D8[0] * s);
        *(s16 *)(v + 0x3A) = (s32)((f32)D_L06_001DD3DA[0] * s);
        vec_add_ab(&q, a0 + 0x10, v + 0x10);
        *(f32 *)(a0 + 0xF0) = func_0038DAB8(*(f32 *)(a0 + 0xF0), 0.11177f);
        func_0038D308(a0 + 0xC0, a0 + 0xF0);
        *(vu0_v4 *)(a0 + 0x10) = q;
        func_L06_00359A88(a0, v);
        if (func_0038CAD0((s32 *)v)) {
            func_L01_004450F0(a0, 2, -1);
            *(s32 *)(a0 + 0x98) = 0;
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(a0, 1);
            *(s32 *)v = 10;
        }
        break;
    case 2:
        if (func_0038CAD0((s32 *)v)) {
            func_L01_004450F0(a0, 3, -1);
            if (func_L06_003597A0(a0, v) == 0) {
                func_003C2880(a0);
            } else {
                *(s32 *)v = 0x3C;
                func_003A4FF8(*(u8 **)(*(u8 **)(a0 + 0x24) + 0x28) + 0x20, 0, 0, v + 0x20, 0x400);
            }
        }
        break;
    case 3:
        func_L01_00404808((void *)func_L06_00359CD0, a0);
        if (func_0038CAD0((s32 *)v)) {
            func_L01_004450F0(a0, 4, -1);
            *(s32 *)v = 5;
        }
        break;
    case 4:
        func_L01_00404808((void *)func_L06_00359CD0, a0);
        if (func_0038CAD0((s32 *)v)) {
            func_L01_004450F0(a0, 5, -1);
            t = *(u8 **)(a0 + 0x24);
            *(u16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) & 0xFFBE;
            *(u16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) | (*(u16 *)(t + 0x44) & 0x1000);
            *(s32 *)(a0 + 0x98) = *(s32 *)(t + 0x10);
            qzero(v + 0x10);
            *(f32 *)(v + 0x18) = -*(f32 *)(v + 8);
            *(f32 *)(a0 + 0xF8) = func_0038D160(*(f32 *)(v + 0x10), *(f32 *)(v + 0x14));
            g = func_0038CED8((f32 *)(v + 0x10));
            *(f32 *)(a0 + 0xF4) = -func_0038D160(g, *(f32 *)(v + 0x18));
            func_0038D308(a0 + 0xC0, a0 + 0xF0);
            *(vu0_v4 *)(a0 + 0x10) = *(vu0_v4 *)(v + 0x20);
            *(f32 *)(a0 + 0x18) = *(f32 *)(a0 + 0x18) + 24.0f;
            *(s32 *)v = 0xF0;
        }
        break;
    case 5:
        func_L01_00404808((void *)func_L06_00359CD0, a0);
        t = *(u8 **)(a0 + 0x24);
        g = *(f32 *)(t + 0x24);
        s = *(f32 *)(a0 + 0x2C) / g + 0.06f;
        if (2.0f < s) {
            s = 2.0f;
        }
        h = g * s;
        s = s * 0.5f;
        *(f32 *)(a0 + 0x2C) = h;
        *(s16 *)(v + 0x38) = (s32)((f32)D_L06_001DD3D8[0] * s);
        *(s16 *)(v + 0x3A) = (s32)((f32)D_L06_001DD3DA[0] * s);
        vec_add_ab(&q, a0 + 0x10, v + 0x10);
        func_L01_00446760(&dd, *(u8 **)(a0 + 0xB8), 0x10001, v + 0x10, *(f32 *)(v + 4));
        dd.h1A = *(u16 *)(a0 + 0xAA);
        vec_sub_ab(&dd.dir, a0 + 0x10, *(u8 **)(a0 + 0xB8) + 0x10);
        dd.dir.z = 0.0f;
        func_0038CF68(&dd.dir, &dd.dir, 2.0000002f);
        dd.flags = dd.flags | 1;
        dd.b18 = 3;
        dd.dir.w = 5627.925f;
        owner = *(u8 **)(a0 + 0xB8);
        func_L01_004CB320();
        hit = func_003D3CB0(a0 + 0x10, &q, 0, owner, &dd);
        if (hit && D_L06_001E8458 != 0) {
            m = D_L06_001E8458;
            if (*(s16 *)(m + 0xAA) == 0x186D && m[0x20] != 2 && m[0x20] != 5) {
                m[0x20] = 4;
            }
        }
        func_L01_004CB358();
        if (!hit) {
            hit = func_003D3CB0(a0 + 0x10, &q, 0, *(u8 **)(a0 + 0xB8), &dd);
            if (!hit) {
                hit = func_L01_003FB640(a0 + 0x10, 0.2f, 1, *(u8 **)(a0 + 0xB8));
            }
            if (!hit) {
                if (!func_0038CAD0((s32 *)v)) {
                    *(vu0_v4 *)(a0 + 0x10) = q;
                    func_L06_00359A88(a0, v);
                    break;
                }
            }
        }
        func_003D4D00(a0 + 0x10, 1.5f, 0, *(u8 **)(a0 + 0xB8), &dd);
        func_003A52A0(0, 0, a0);
        func_L01_003303B8(a0 + 0x10, 1, 0xF, 0xA, 0xA, 0xA, 0x19, 1, 0.75f, 0.0f, 0.0f, 2.0f, 1, 1, 1, 0, 1, 0, 0x1010000,
                          0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        *(s32 *)(a0 + 0x98) = 0;
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(a0, 1);
        func_L01_004450F0(a0, 6, -1);
        break;
    case 6:
        if (func_L01_004561B8(a0)) {
            *(s32 *)v = 0x3C;
        }
        if (func_0038CAD0((s32 *)v)) {
            func_003C2880(a0);
        }
        break;
    }
}
