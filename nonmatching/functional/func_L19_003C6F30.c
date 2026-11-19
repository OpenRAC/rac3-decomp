/* functional: high. Same calls, args and stores as retail; the final flag is written as (bit 23 != 0) which compiles to sra/andi instead of and/sltu, same value. Padding word at end is not part of it. */
typedef struct { u8 pad[0x30]; vu0_v4 v30; u8 p40[0x30]; f32 f70; f32 f74; f32 f78; u8 p7C[4]; } S_6F30_E;
typedef struct { s32 f0; u8 p4[4]; s32 f8; u8 pC[0x14]; s32 f20; } S_6F30_D;
typedef struct { u8 pad[0x68]; S_6F30_D *f68; } S_6F30_O;
extern void func_L01_004ED3F8(s32, s32, void *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern void func_L01_00511A40(void *, s32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *D_001DF71C;
extern S_6F30_E *D_001DF800;
extern u32 D_00142C54[];
extern s32 D_001DBC94;

void func_L19_003C6F30(S_6F30_O *self) {
    S_6F30_D *d = self->f68;
    vu0_v4 v;
    func_L01_004ED3F8(1, 0x3F, D_001DF71C + (d->f0 << 8));
    func_L01_004F50C8(&D_001DF800[d->f8].v30, &D_001DF800[d->f8].f70, -1, 1);
    func_L01_00456230(D_001DF71C + (d->f20 << 8), 0);
    v.x = func_0038D098(D_001DF800[d->f8].f78);
    v.y = func_0038D0B0(D_001DF800[d->f8].f78);
    v.z = 0;
    vec_add_ab(&v, &v, &D_001DF800[d->f8].v30);
    func_L01_00511A40(&v, 1, D_001DF800[d->f8].f78);
    D_001DBC94 = (D_00142C54[0] & 0x800000) != 0;
}
