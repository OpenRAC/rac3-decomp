/* func_L27_003A43A8: 9 diff (level 27, needs @ps2as for the inline 1.1f constant; D_001D5570 must be sized [8] for the la macro).
   Left: (1) the four beq of the 0x1A4E..0x1BA0 chain jump back to the earlier "b; addiu v0,1" tail of the
   first block (gcc cross-jumps the identical return 1) where retail jumps to its own return-1 block after the
   chain; (2) retail loads D_L27_001E83C0.f18 into $a0 and uses a plain beqz, this C uses $v1 and beql.
   Chain as || (37 diff), nested ifs (31), no else (same 9) did not help. */
/* localdecomp:start func_L27_003A43A8 */
typedef struct { u8 pad[0x34]; u16 h34; u8 pad36[0x74]; s16 hAA; } S_43A8_H;
typedef struct { u8 pad[0x84]; s32 f84; s32 f88; } S_43A8_R;
typedef struct { u8 pad[0x35C]; s32 f35C; s32 f360; u8 pad364[0x225C]; S_43A8_H *f25C0; } G_43A8;
typedef struct { u8 pad[0x18]; S_43A8_H *f18; } E_43A8;
typedef struct { u8 pad[0x24]; f32 f24; } P_43A8;
typedef struct { u8 pad[0x20]; s32 f20; u8 pad24[0xC]; s32 f30; } D_43A8;
typedef struct { u8 pad0[0x10]; u8 v10[0x1C]; f32 f2C; u8 pad30[0x38]; D_43A8 *f68; u8 pad6C[0x44]; u8 fB0; } O_43A8;
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern u8 D_001BBC40[][16];
__asm__(".extern D_001BBC40, 16");
extern u8 D_001D5570[8];
extern G_43A8 D_001A4BE0;
extern E_43A8 D_L27_001E83C0;
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_0043B510(s32);
extern void func_L01_004A3610(void *, void *);
extern S_43A8_R *func_L01_0045B958(void);

s32 func_L27_003A43A8(O_43A8 *self) {
    D_43A8 *d = self->f68;
    if (d->f20 != 0) {
        if ((D_001BBC40[D_001D545C_sda][self->fB0] & 0x80) != 0) return 1;
    }
    if (d->f30 != 0) {
        if (D_001D5570[d->f30] != 0) return 1;
    }
    if (D_001A4BE0.f35C == (s32)self && D_001A4BE0.f360 >= 2) return 1;
    if (func_L01_003FB640(self->v10, 1, self, self->f2C * 1.1f / ((P_43A8 *)((void **)self)[9])->f24) == 0) return 0;
    if (D_L27_001E83C0.f18 == 0) return 0;
    if (D_L27_001E83C0.f18 == D_001A4BE0.f25C0 && D_001A4BE0.f35C == (s32)self) {
        if (d->f20 == 0) return 1;
        func_L01_0043B510(self->fB0);
        func_L01_004A3610((u8 *)&D_001A4BE0 + 0x80, (u8 *)&D_001A4BE0 + 0x90);
        return 1;
    } else {
        S_43A8_R *r;
        if ((D_L27_001E83C0.f18->h34 & 0x20) == 0) return 0;
        r = func_L01_0045B958();
        if (r == 0) return 0;
        if (r->f88 == (s32)self || r->f84 == (s32)self) {
            s16 t = D_L27_001E83C0.f18->hAA;
            if (t != 0x1A4E && t != 0x1AA0 && t != 0x1BD3 && t != 0x16BE && t != 0x1BA0) return 0;
            return 1;
        }
        return 0;
    }
}
/* localdecomp:end func_L27_003A43A8 */
