/* func_L02_003A49F0: 4 diff with the file's flags. Only the non-$5F branches load lwc1 $f12 before lw $a1 (retail: lw $a1 first); tried locals, prototype types. Needs aliases D_001D545C_003A49F0 and D_L02_001D67B0_003A49F0 (lui forms of the gp symbols, hint 16). */
typedef struct { u8 pad0[0xAA]; s16 fAA; } Q;
typedef struct {
    u8 pad0[0x30];
    f32 f30;
    u8 pad34[0xA];
    u8 f3E;
    u8 pad3F[0x1F];
    u8 f5E;
    u8 f5F;
    u8 pad60[0x100];
    u8 b160[0x160];
    s32 f2C0;
    f32 f2C4;
    s32 f2C8;
    f32 f2CC;
    u8 pad2D0[0x10];
    u8 v2E0[0x10];
} D;
typedef struct {
    u8 pad0[0x20];
    u8 state;
    u8 pad21[0x47];
    D *d;
    u8 pad6C[0x29];
    u8 f95;
    u8 pad96[0x1C];
    s16 fB2;
} O;
extern s32 D_001D545C;
extern s32 D_001D545C_003A49F0;
extern s32 D_L02_001D67B0;
extern s32 D_L02_001D67B0_003A49F0;
extern s32 D_L02_001DE4C0;
extern s32 func_L02_003A4CC0(void *);
extern void func_L02_003A5138(void *);
extern u8 *func_L01_00447490(u8 *, s32, s32);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00459C50(s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
__asm__(".extern D_001D545C, 4");
__asm__(".extern D_001D545C_003A49F0, 16");
__asm__(".extern D_L02_001D67B0, 4");
__asm__(".extern D_L02_001D67B0_003A49F0, 16");
__asm__(".extern D_L02_001DE4C0, 4");
s32 func_L02_003A49F0(void *p) {
    O *self = p;
    D *d;
    Q *q;
    s32 v, h, a, w;
    d = self->d;
    if (self->state == 0) {
        if (func_L02_003A4CC0(self) != 0) return 1;
    }
    if (d->f3E != 2) {
        q = 0;
        if (D_001D545C == 5) {
            u8 *r = func_L01_00447490((u8 *)self, 0x10000, 1);
            if (r != 0) q = *(Q **)(r + 0x20);
        }
        if (func_L01_00452FB0(self, d->b160, 0, 0, 0) != 0) {
            func_L02_003A5138(self);
            if (D_001D545C_003A49F0 == 5 && d->f30 <= 0.0f) {
                if (q != 0) {
                    h = q->fAA;
                    if (h == 0x189B || h == 0x1BC3 || h == 0x1D3E) {
                        v = D_L02_001D67B0_003A49F0 + 1;
                        D_L02_001D67B0 = v;
                        if (v >= 0xF) func_L01_00459C50(7);
                    }
                }
            }
        }
        func_L01_00452860(self, &d->f30, 0);
        if (d->f5E == 0) goto body;
    }
    func_L02_003A5010((s32)self);
    return 1;
body:
    {
        {
            if ((self->fB2 + 8) % 8 != D_L02_001DE4C0 % 8) return 0;
            if (d->f5F != 0) {
                func_L01_00456BD0(self, 3);
                if (self->f95 == 0) {
                    func_L01_00456C98(self, d->f2C0, 0, 0, 0, 0, 3, 0, 0, 0, d->f2C4, 10.0f, 1.0f);
                    return 0;
                }
                func_L01_00456C98(self, d->f2C8, 0, 0, 0, 0, 3, 0, 0, 0, d->f2CC, 10.0f, 1.0f);
                return 0;
            }
            if (d->f2CC > 0.0f) func_L01_00456BD0(self, 3);
            if (self->f95 == 0) func_L01_00456C98(self, d->f2C0, d->v2E0, 0, 0, 0, 1, 0, 0, 0, d->f2C4, 10.0f, 1.0f);
            else func_L01_00456C98(self, d->f2C8, d->v2E0, 0, 0, 0, 1, 0, 0, 0, d->f2CC, 10.0f, 1.0f);
            return 0;
        }
    }
}

INCLUDE_ASM("asm/levels", func_L02_003A49F0);
