/* functional: high. Builds a GIF/DMA packet (tag 0x10000008 + 7 qwords) for a rotated textured quad: corners from centre +/- half-axes (a3 != 0 drops the second axis on the top edge), packed as 16.4 xy + fog word at D_L01_001DFD0C; a2 and a4[0..3] are the tag and per-vertex uv/rgba words stored as sign-extended 64-bit like retail. */
typedef struct {
    f32 x, y, z, w;
} V4_00420E80;

typedef struct {
    s32 w[4];
} Q_00420E80;

extern u8 *D_L01_001E1068;
extern u8 D_001DA170[];
extern s32 D_001D4BD0[];
extern s32 D_001D4BD4[];
extern s32 D_L01_001DFD0C[];

extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

static long pack_00420E80(f32 x, f32 y) {
    s32 lo = (s32)x + D_001D4BD0[0] - 8;
    s32 hi = (s32)y + D_001D4BD4[0] - 8;
    return (long)lo | ((long)hi << 16) | ((long)D_L01_001DFD0C[0] << 32);
}

void func_L01_00420E80(s32 a0, s32 a1, long a2, s32 a3, s32 *a4, f32 cx, f32 cy, f32 hv, f32 hu, f32 ang) {
    V4_00420E80 A, B, C, p30, p40, p50, p60, z;
    s32 w8, w9, w10;
    u8 *p, *P2;

    C.x = cx;
    C.y = cy;
    A.x = hu * func_0038D0B0(ang);
    A.y = hu * func_0038D098(ang);
    B.x = -hv * func_0038D098(ang);
    B.y = hv * func_0038D0B0(ang);
    if (a3 != 0) {
        z.x = 0.0f;
        z.y = 0.0f;
        z.z = 0.0f;
        p50.x = (C.x + A.x) + z.x;
        p50.y = (C.y + A.y) + z.y;
        p30.x = (C.x - A.x) + z.x;
        p30.y = (C.y - A.y) + z.y;
        p40.x = (C.x - A.x) - B.x;
        p40.y = (C.y - A.y) - B.y;
        p60.x = (C.x + A.x) - B.x;
        p60.y = (C.y + A.y) - B.y;
    } else {
        p60.x = (C.x + A.x) - B.x;
        p60.y = (C.y + A.y) - B.y;
        p50.x = (C.x + A.x) + B.x;
        p50.y = (C.y + A.y) + B.y;
        p40.x = (C.x - A.x) - B.x;
        p40.y = (C.y - A.y) - B.y;
        p30.x = (C.x - A.x) + B.x;
        p30.y = (C.y - A.y) + B.y;
    }
    p = D_L01_001E1068;
    *(s32 *)(p + 0) = 0x10000008;
    *(s32 *)(D_L01_001E1068 + 4) = 0;
    *(s32 *)(D_L01_001E1068 + 8) = 0;
    *(s32 *)(D_L01_001E1068 + 0xC) = 0x50000008;
    w8 = a0 << 4;
    w9 = a1 << 20;
    w10 = w9 + w8;
    p = D_L01_001E1068;
    *(Q_00420E80 *)(p + 0x10) = *(Q_00420E80 *)D_001DA170;
    D_L01_001E1068 = p + 0x10;
    P2 = D_L01_001E1068 + 0x10;
    D_L01_001E1068 = P2;
    *(long *)(P2 + 0x00) = a2;
    *(long *)(P2 + 0x08) = 0x15C;
    *(long *)(P2 + 0x10) = a4[0];
    *(long *)(P2 + 0x18) = 0;
    *(long *)(P2 + 0x20) = pack_00420E80(p30.x, p30.y);
    *(long *)(P2 + 0x28) = a4[1];
    *(long *)(P2 + 0x30) = w8;
    *(long *)(P2 + 0x38) = pack_00420E80(p40.x, p40.y);
    *(long *)(P2 + 0x40) = a4[2];
    *(long *)(P2 + 0x48) = w9;
    *(long *)(P2 + 0x50) = pack_00420E80(p50.x, p50.y);
    *(long *)(P2 + 0x58) = a4[3];
    *(long *)(P2 + 0x60) = w10;
    *(long *)(P2 + 0x68) = pack_00420E80(p60.x, p60.y);
    D_L01_001E1068 = D_L01_001E1068 + 0x70;
}
