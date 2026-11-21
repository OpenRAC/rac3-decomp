/* functional: medium. written from asm, no draft. Stack frame modelled as one byte image because func_003D2DA0 reads a packed record at sp+0x10 (4 vertices, 4 colours, 0x20 copied block, header at +0x80); callee prototypes and the meaning of the sp+0xA0..0x110 temporaries are inferred, so medium. */
typedef int Q_3C12A8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C12A8;
typedef struct { s32 f0; u8 p4[4]; u64 f8; u8 pC[0x40]; u8 f51; } G_3C12A8;
extern G_3C12A8 D_002D2008[];
extern V_3C12A8 D_00222400;
extern u8 D_001D9010[];
extern u8 D_001D8FD0[];
extern s32 D_00225700[];
extern void func_003BC670(s32, void *);
extern void func_0038CD28(void *, void *, s32);
extern void func_003A9440(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);
extern void func_003C1490(s32);
void func_003C12A8(u8 *a0) {
    /* one stack frame image; the callees read it as a packed record at st+0x10 (offsets are retail's) */
    u8 st[0x150] __attribute__((aligned(16)));
    G_3C12A8 *g = D_002D2008;
    V_3C12A8 *pos = (V_3C12A8 *)(st + 0x00);
    V_3C12A8 *d = (V_3C12A8 *)(st + 0x120);
    V_3C12A8 *n = (V_3C12A8 *)(st + 0x130);
    V_3C12A8 *c = (V_3C12A8 *)(st + 0x140);
    s32 i;
    if (g->f51 != 0) {
        *(Q_3C12A8 *)pos = *(Q_3C12A8 *)(a0 + 0x10);
        func_003BC670(g->f0, (u8 *)g + 8);
        *(u64 *)(st + 0x90) = 0xFF9000000260UL;
        *(u64 *)(st + 0x88) = g->f8;
        *(u64 *)(st + 0x98) = 0x80000044UL;
        *(u64 *)(st + 0x80) = 0;
        func_0038CD28(st + 0x60, D_001D9010, 0x20);
        func_003A9440(0x47, 0x5360B);
        d->x = D_00222400.x - pos->x;
        d->y = D_00222400.y - pos->y;
        d->z = D_00222400.z - pos->z;
        d->w = D_00222400.w;
        func_0038CF68(d, d, 1.0f);
        *(s32 *)&n->x = 0;
        *(s32 *)&n->y = 0;
        n->z = -1.0f;
        *(s32 *)&n->w = 0;
        func_0038CE90(c, n, d);
        *(Q_3C12A8 *)(st + 0xE0) = *(Q_3C12A8 *)c;
        *(Q_3C12A8 *)(st + 0xA0) = *(Q_3C12A8 *)n;
        *(Q_3C12A8 *)(st + 0xF0) = *(Q_3C12A8 *)d;
        *(Q_3C12A8 *)(st + 0xB0) = *(Q_3C12A8 *)d;
        *(Q_3C12A8 *)(st + 0xC0) = *(Q_3C12A8 *)c;
        func_0038CE20(st + 0x100, st + 0xA0, -1.0f);
        *(Q_3C12A8 *)(st + 0x110) = *(Q_3C12A8 *)st;
        for (i = 0; i < 4; i++) {
            *(u32 *)(st + 0x50 + i * 4) = 0x80808080;
            func_0038CE20(st + 0x10 + i * 0x10, D_001D8FD0 + i * 0x10, 25.0f);
            func_0038D028(st + 0x10 + i * 0x10, st + 0x10 + i * 0x10, st + 0xE0);
        }
        func_003D2DA0(st + 0x10, 0, 0);
        func_003A9440(0x47, 0x5360B);
    }
    func_003C1490(D_00225700[0x15]);
}
