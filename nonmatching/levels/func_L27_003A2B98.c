/* func_L27_003A2B98: 27 diff (level 27; needs "-mvu0-use-vf0-vf2 ... @ps2as" on L27_003A1250.c, which
   func_L27_003A2E08 already gave it, and "#include \"vu0.h\""). Everything matches except one register swap in
   state 6: retail keeps entry a (D_L27_001DED1C + (d->f0 << 8)) in $s0 and entry b in $s1 (b reusing the table
   pointer register), this C gives a $s1 and b $s0, which shifts the later uses (and bne/bnel of the first
   branch, and where the D_L27_001DEE00 lui lands). Declaration order, computing b first, a local for f24 and
   byte-offset access for fF8 did not change it. Retail also keeps all three stores to b->h34 (this order
   of the statements gives that). */
/* localdecomp:start func_L27_003A2B98 */
typedef struct { u8 pad[0x10]; s32 f10; u8 pad14[0x30]; u16 h44; } S_2B98_Q;
typedef struct { u8 pad[0x10]; vu0_v4 v10; u8 pad20[4]; S_2B98_Q *f24; u8 pad28[0xC]; u16 h34; u8 pad36[0x62]; s32 f98; u8 pad9C[0x54]; vu0_v4 vF0; } S_2B98_E1;
typedef struct { s32 f0; s32 f4; u8 pad8[0x38]; s32 f40; u8 pad44[4]; s32 f48; s32 f4C; } S_2B98_D;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_2B98_D *f68; } S_2B98_O;
typedef struct { u8 pad[0x30]; vu0_v4 v30; u8 p40[0x30]; f32 f70; f32 f74; f32 f78; u8 p7C[4]; } S_2B98_E;
extern void func_L01_003EB5E0(s32, s32);
extern void func_L01_004ED3F8(s32, s32, void *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_00511A40(void *, s32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *D_L27_001DED1C;
extern S_2B98_E *D_L27_001DEE00;

void func_L27_003A2B98(S_2B98_O *self) {
    S_2B98_D *d = self->f68;
    vu0_v4 v;
    func_L01_003EB5E0(0, 2);
    func_L01_004ED3F8(1, 0x3F, D_L27_001DED1C + (d->f0 << 8));
    if (self->b20 == 4) {
        func_L01_004F50C8(&D_L27_001DEE00[d->f40].v30, &D_L27_001DEE00[d->f40].f70, -1, 1);
        v.x = func_0038D098(D_L27_001DEE00[d->f40].f78);
        v.y = func_0038D0B0(D_L27_001DEE00[d->f40].f78);
        v.z = 0;
        vec_add_ab(&v, &v, &D_L27_001DEE00[d->f40].v30);
        func_L01_00511A40(&v, 1, D_L27_001DEE00[d->f40].f78);
    } else if (self->b20 == 6) {
        S_2B98_E1 *a;
        S_2B98_E1 *b;
        func_L01_004F50C8(&D_L27_001DEE00[d->f48].v30, &D_L27_001DEE00[d->f48].f70, -1, 0);
        a = (S_2B98_E1 *)(D_L27_001DED1C + (d->f0 << 8));
        b = (S_2B98_E1 *)(D_L27_001DED1C + (d->f4 << 8));
        v.x = -func_0038D098(a->vF0.z);
        v.y = -func_0038D0B0(a->vF0.z);
        v.z = 0;
        v.w = 1.0f;
        vec_add_ba(&b->v10, &a->v10, &v);
        b->h34 &= 0xFFBE;
        b->vF0 = a->vF0;
        b->h34 |= b->f24->h44 & 0x1000;
        b->f98 = b->f24->f10;
        b->h34 &= 0xFFFD;
        v.x = func_0038D098(D_L27_001DEE00[d->f48].f78);
        v.y = func_0038D0B0(D_L27_001DEE00[d->f48].f78);
        v.z = 0;
        vec_add_ab(&v, &v, &D_L27_001DEE00[d->f48].v30);
        func_L01_00511A40(&v, 1, D_L27_001DEE00[d->f48].f78);
    }
}
/* localdecomp:end func_L27_003A2B98 */
