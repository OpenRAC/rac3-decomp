/* functional: medium. written from asm, no draft; stack frame modelled as a byte image (sprite record at sp+0, temporaries at 0x90..0xE0) so offsets match retail. Float/vector helper roles inferred from args. */
typedef int Q_3D98C0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3D98C0;
extern V_3D98C0 D_00222400;
extern u8 D_002225D0[];
extern s32 D_001D52F0;
extern u8 D_001D9180[];
extern void func_003D9768(void *, s32, s32, long);
extern void func_0038D348(void *, void *, f32);
extern void func_0038D270(void *, void *, void *);
extern void func_0038D6E8(void *, void *);
extern void func_0038D9D0(void *, void *, void *);
extern void func_0038D200(void *, void *, f32);
extern void func_0038D408(void *, void *, void *);
extern void func_003D3158(void *, s32, s32);
void func_003D98C0(u8 *a0, s32 a1, s32 col, s32 a3, f32 f0, f32 f1, f32 f2) {
    /* stack image: the sprite record at st+0 (vertices 0..0x3F, colours 0x40, uvs 0x50) plus temporaries at 0x90.. */
    u8 st[0x110] __attribute__((aligned(16)));
    V_3D98C0 *v90 = (V_3D98C0 *)(st + 0x90);
    s32 i;
    func_003D9768(st, a1, a3, 0x80);
    *(Q_3D98C0 *)(st + 0xC0) = *(Q_3D98C0 *)a0;
    *(s32 *)(st + 0x40) = col;
    *(s32 *)(st + 0x4C) = col;
    *(s32 *)(st + 0x48) = col;
    *(s32 *)(st + 0x44) = col;
    *(s32 *)(st + 0x50) = 0;
    *(s32 *)(st + 0x54) = 0;
    *(s32 *)(st + 0x58) = 0;
    *(f32 *)(st + 0x5C) = 1.0f;
    *(f32 *)(st + 0x60) = 1.0f;
    *(s32 *)(st + 0x64) = 0;
    *(f32 *)(st + 0x68) = 1.0f;
    *(f32 *)(st + 0x6C) = 1.0f;
    v90->x = D_00222400.x - ((V_3D98C0 *)(st + 0xC0))->x;
    v90->y = D_00222400.y - ((V_3D98C0 *)(st + 0xC0))->y;
    v90->z = D_00222400.z - ((V_3D98C0 *)(st + 0xC0))->z;
    v90->w = D_00222400.w;
    func_0038D348(st + 0x90, st + 0x90, 1.0f);
    func_0038D270(st + 0xA0, st + 0x90, D_002225D0 + D_001D52F0 * 0x460 + 0x80);
    func_0038D348(st + 0xA0, st + 0xA0, 1.0f);
    func_0038D270(st + 0xB0, st + 0xA0, st + 0x90);
    if (f2 != 0.0f) {
        *(Q_3D98C0 *)(st + 0xD0) = 0;
        *(f32 *)(st + 0xD0) = f2;
        func_0038D6E8(st + 0xE0, st + 0xD0);
        func_0038D9D0(st + 0x90, st + 0x90, st + 0xE0);
    }
    func_0038D200(st + 0xD0, st + 0x90, f1);
    {
        V_3D98C0 *p = (V_3D98C0 *)(st + 0xC0), *o = (V_3D98C0 *)(st + 0xD0);
        p->x = p->x + o->x;
        p->y = p->y + o->y;
        p->z = p->z + o->z;
    }
    for (i = 0; i < 4; i++) {
        func_0038D200(st + i * 0x10, D_001D9180 + i * 0x10, f0);
        func_0038D408(st + i * 0x10, st + i * 0x10, st + 0x90);
    }
    func_003D3158(st, 0, 0);
}
