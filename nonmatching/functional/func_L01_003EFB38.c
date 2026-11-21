/* functional: high. Ambient-volume field emitter (PAL twin of the L39 routine func_L39_00574F20, ported with PAL names/offsets after reading the PAL asm): while the listener is inside the emitter box it keeps voice sub[5] alive (flags 0x19, or 0x1D when the row byte 0x18 is set), samples a byte grid (dims packed 10/10/10 bits) trilinearly at the listener position via func_L01_003EFAA0/003EFA80 and sets the voice volume (max 0x400) */
typedef struct {
    u32 x : 10;
    u32 y : 10;
    u32 z : 10;
} Dims_003EFB38;

typedef struct {
    Dims_003EFB38 d;
    u8 *data;
    u8 pad8[8];
} Grid_003EFB38;

typedef struct {
    u8 pad0[0x18];
    u8 f18;
    u8 pad19[7];
} Ent_003EFB38;

extern u8 *D_L01_001DFB6C;
extern Grid_003EFB38 *D_001DFC8C;
extern vu0_v4 D_001DF750;
__asm__(".extern D_001DF750, 16");
extern f32 D_001DF740;
__asm__(".extern D_001DF740, 4");
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L01_004AAE90(s32, s32, void *, s32);
extern s32 func_003A53E8(u32, s32);
extern f32 func_L01_003EFA80(f32, f32, f32);
extern f32 func_L01_003EFAA0(f32 *, f32, f32);

void func_L01_003EFB38(u8 *self) {
    vu0_v4 d;
    vu0_v4 r;
    f32 s[4];
    vu0_v4 t;
    s32 *sub;
    Grid_003EFB38 *g;
    s32 flags;
    u8 *slot;
    s32 x, y, z;
    s32 x1, y1, z1;
    f32 fx, fy, fz;
    f32 a, b;
    s32 v;

    sub = *(s32 **)(self + 8);
    vec_sub_ab(&d, D_L01_001E29C0, self + 0x40);
    d.w = 0.0f;
    func_0038D000(&r, &d, self + 0x50);
    flags = 0x19;
    if (fabs_asm(r.x) <= 1.0f && fabs_asm(r.y) <= 1.0f && fabs_asm(r.z) <= 1.0f) {
        if (D_L01_001DFB6C[sub[1] * 32 + 0x18]) flags = 0x1D;
        slot = (u8 *)D_001A30B0 + (sub[5] << 7);
        if (*(u8 **)(slot + 0x100) != self || slot[0xD0] == 0) {
            sub[5] = func_L01_004AAE90(sub[1], flags, self, 0x400);
        }
        g = &D_001DFC8C[sub[6]];
        func_0038CE20(&t, &r, 0.5f);
        vec_add_ab(&t, &t, &D_001DF750);
        func_0038CE20(&r, &t, (f32)g->d.x);
        fz = r.z;
        z = fz;
        fy = r.y;
        y = fy;
        fx = r.x;
        x = fx;
        fx -= (f32)x;
        fy -= (f32)y;
        fz -= (f32)z;
        {
            s32 px = x;
            s32 py = y;
            s32 pz = z;
            if (px == g->d.x) px--;
            if (py == g->d.y) py--;
            if (pz == g->d.z) pz--;
            s[0] = g->data[px + py * g->d.x + pz * g->d.x * g->d.y];
        }
        x1 = x + 1;
        {
            s32 px = x1;
            s32 py = y;
            s32 pz = z;
            if (px == g->d.x) px--;
            if (py == g->d.y) py--;
            if (pz == g->d.z) pz--;
            s[1] = g->data[px + py * g->d.x + pz * g->d.x * g->d.y];
        }
        y1 = y + 1;
        {
            s32 px = x;
            s32 py = y1;
            s32 pz = z;
            if (px == g->d.x) px--;
            if (py == g->d.y) py--;
            if (pz == g->d.z) pz--;
            s[2] = g->data[px + py * g->d.x + pz * g->d.x * g->d.y];
        }
        {
            s32 px = x1;
            s32 py = y1;
            s32 pz = z;
            if (px == g->d.x) px--;
            if (py == g->d.y) py--;
            if (pz == g->d.z) pz--;
            s[3] = g->data[px + py * g->d.x + pz * g->d.x * g->d.y];
        }
        a = func_L01_003EFAA0(s, fx, fy);
        z1 = z + 1;
        {
            s32 px = x;
            s32 py = y;
            s32 pz = z1;
            if (px == g->d.x) px--;
            if (py == g->d.y) py--;
            if (pz == g->d.z) pz--;
            s[0] = g->data[px + py * g->d.x + pz * g->d.x * g->d.y];
        }
        {
            s32 px = x1;
            s32 py = y;
            s32 pz = z1;
            if (px == g->d.x) px--;
            if (py == g->d.y) py--;
            if (pz == g->d.z) pz--;
            s[1] = g->data[px + py * g->d.x + pz * g->d.x * g->d.y];
        }
        {
            s32 px = x;
            s32 py = y1;
            s32 pz = z1;
            if (px == g->d.x) px--;
            if (py == g->d.y) py--;
            if (pz == g->d.z) pz--;
            s[2] = g->data[px + py * g->d.x + pz * g->d.x * g->d.y];
        }
        {
            s32 px = x1;
            s32 py = y1;
            s32 pz = z1;
            if (px == g->d.x) px--;
            if (py == g->d.y) py--;
            if (pz == g->d.z) pz--;
            s[3] = g->data[px + py * g->d.x + pz * g->d.x * g->d.y];
        }
        b = func_L01_003EFAA0(s, fx, fy);
        v = (s32)(func_L01_003EFA80(a, b, fz) * D_001DF740);
        func_003A53E8(sub[5], v > 0x400 ? 0x400 : v);
    }
}
