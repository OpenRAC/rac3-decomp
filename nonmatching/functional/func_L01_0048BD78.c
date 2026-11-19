/* functional: high. Only scheduling and register choice differ from retail. */
typedef struct { s32 w0; s32 w4; f32 f8; f32 fC; f32 f10; f32 f14; f32 f18; f32 f1C; f32 f20; } Ent_0048BD78;
typedef struct { s32 id; u8 flag; u8 pad[0xA3]; Ent_0048BD78 *ent; s32 padAC; } Slot_0048BD78;
extern Slot_0048BD78 D_L01_00233DD8[];
extern f32 D_L01_001D8A5C;
extern s32 D_L01_001D8A30;
extern f32 D_L01_001E0890[];
extern f32 D_L01_001E0894[];
extern f32 D_L01_001D8B24;
extern f32 D_L01_001D8B28;
extern f32 D_L01_001D8B1C;
extern f32 D_L01_001D8B20;
extern u32 D_L01_001D8B8C;
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_005170B8(s32, u32);

void func_L01_0048BD78(void) {
    f32 t = D_L01_001D8A5C;
    f32 sx = D_L01_001D8B24 * t;
    f32 sy = D_L01_001D8B28 * t;
    f32 ox = (0.5f - D_L01_001E0890[0]) * sx;
    f32 oy = (0.5f - D_L01_001E0894[0]) * sy;
    s32 k;
    u32 rest;

    func_L01_00517538(0x13000E, sx, sy);
    func_L01_00516470(0x13000E, D_L01_001D8B1C + ox, D_L01_001D8B20 + oy);
    rest = D_L01_001D8B8C & 0xFFFFFF;
    k = (s32)(((D_L01_001D8A5C - 3.5f) * 128.0f) / (D_L01_00233DD8[D_L01_001D8A30].ent->f10 - 3.5f));
    func_L01_005170B8(0x13000F, (u32)(k << 24) | rest);
    func_L01_00517538(0x13000F, D_L01_00233DD8[D_L01_001D8A30].ent->f1C * sx, D_L01_00233DD8[D_L01_001D8A30].ent->f20 * sy);
    func_L01_00516470(0x13000F, D_L01_00233DD8[D_L01_001D8A30].ent->f14 + D_L01_001D8B1C, D_L01_00233DD8[D_L01_001D8A30].ent->f18 + D_L01_001D8B20);
}
