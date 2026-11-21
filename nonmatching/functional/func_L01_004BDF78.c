/* functional: medium. Rewritten from PAL asm; large layout differences only. The lqc2/vadd.xyz/sqc2 triple is plain xyz float adds (w left untouched). Fixed in round 2: the two stick axes were swapped (f21 is pad+0x144, f20 pad+0x140) and the mode-5 store went to 0x1D81E0 instead of retail's gp-0x4CD0 = 0x1D7BE0; level $gp slots are D_L01_ names (they move per level). */
/* localdecomp:start func_L01_004BDF78 */
typedef struct { u8 pad0[0x140]; f32 stickY; f32 stickX; u8 pad148[0x78]; s32 held; s32 buttons; } Pad_BDF78;
typedef struct {
    s32 type;          /* 0 fade in, 1 running, 2 closing */
    s32 timer;
    s32 f8;
    u8 pad0C[0x1C];
    s32 f28;
    s32 *objs;
    s32 f30;
    s32 nobjs;
    u8 pad38[0x18];
    s32 mode;
    u8 pad54[0xC];
    s32 f60;
    u8 pad64[8];
    s32 scroll;
    u8 pad70[0x14];
    s32 active;
    u8 f88;
    u8 f89;
    u8 pad8A[2];
    s32 f8C;
    s32 f90;
    f32 f94;
    s32 f98;
    s32 f9C;
    s32 fA0;
    f32 fA4, fA8, fAC, fB0, fB4, fB8;
} UI_BDF78;
extern S_00244740 D_L01_002446C0[];
extern Pad_BDF78 *D_001D52FC_sda;
extern f32 D_L01_001DAC50;
extern f32 D_L01_001DAD5C;
extern s32 D_L01_001DABD8;
extern s32 D_L01_001DABA0;
extern s32 D_L01_001DABA8;
extern s32 D_L01_001D7BE0;
extern s32 D_L01_001E0F88;
extern s32 D_L01_001E0F8C;
extern s32 D_L01_001E0F90;
extern s32 D_L01_001E0F7C[];
extern u8 D_00143950[];
extern u8 D_00160C40[];
extern s16 D_0016C6A4[];
extern void func_003A2750(s32);
extern void func_0039AA38(s32);
extern void func_003E5520(void);
extern void func_003CD058(void);
extern void func_003CD350(void);
extern void func_003A0F98(s32, s32);
extern void func_00396568(s32);
extern void func_003D0B20(void);
extern void func_003E55B8(void);
extern void func_003A4288(void);
extern void func_003AF498(void);
extern void func_003C7C38(u8 *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(f32 *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L01_0040DF68(f32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern void func_L01_004AB0E0(void);
extern void func_L01_004E20E8(void);
extern void func_L01_0042D110(s32);
extern void func_L01_004C1460(s32);
extern void func_L01_004C3840(s32);
extern void func_L01_004C42D0(s32);
extern void func_L01_004C4D90(s32);
extern void func_L01_004C26A8(void);
extern void func_L01_004BDF08(void);
extern void func_L01_004BD4A8(void);
extern void func_L01_004BF980(void);
extern void func_L01_004C1EA0(void);
extern void func_L01_00478898(void);
extern void func_L01_004788D0(s32);

void func_L01_004BDF78(void) {
    UI_BDF78 *u = (UI_BDF78 *)D_L01_002446C0;
    Pad_BDF78 *p;
    f32 f20, f21;
    s32 i;
    s32 a;
    f32 tmp[4] __attribute__((aligned(16)));

    if (D_L01_001DAC50 < 1.0f) D_L01_001DAC50 = 1.0f;

    if (u->type == 1) {
        p = D_001D52FC_sda;
        if (p->held & 0x8000) D_L01_001E0F88++; else D_L01_001E0F88 = 0;
        p = D_001D52FC_sda;
        if (p->held & 0x2000) D_L01_001E0F8C++; else D_L01_001E0F8C = 0;

        if (u->f8C == 0) {
            u->f90 += 3;
            if (u->f90 >= 0x80) {
                u->f8C = 2;
                u->f90 = 0x80;
            }
        } else if (u->f8C == 1) {
            u->f94 = u->f94 * 0.9f;
            u->f90 -= 16;
            if (u->f90 <= 0) {
                D_L01_001DABA0--;
                if (D_L01_001DABA0 <= 0) {
                    u->f8C = 3;
                    D_L01_001DABA0 = 4;
                }
                u->f94 = 0.0f;
                u->f90 = 0;
            }
        }

        if (u->f88 && u->mode != 0) {
            if (u->nobjs > 0) {
                for (i = 0; i < u->nobjs; i++) {
                    u8 *o = (u8 *)u->objs + i * 256;
                    f32 s;
                    func_0038D000(o + 0x10, (u8 *)u + 0xC0, (u8 *)u->f28 + 0xC0);
                    {
                        f32 *dv = (f32 *)(o + 0x10);
                        f32 *bv = (f32 *)((u8 *)u->f28 + 0x10);
                        dv[0] = dv[0] + bv[0];
                        dv[1] = dv[1] + bv[1];
                        dv[2] = dv[2] + bv[2];
                    }
                    s = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * u->f94;
                    if (D_00143950[0xAD]) s = s * D_L01_001DAD5C;
                    *(f32 *)(o + 0x2C) = s;
                    if (*(s16 *)(o + 0xAA) == 0x10E3) o[0x23] = u->f90 / 2;
                    else o[0x23] = (u8)u->f90;
                    if (u->mode != 2) {
                        *(f32 *)(o + 0xF8) = func_0038DAB8(*(f32 *)(o + 0xF8), func_L01_0040DF68(0.01f));
                    } else {
                        p = D_001D52FC_sda;
                        f21 = p->stickX / 100.0f;   /* retail: f21 = pad+0x144 / 100, f20 = pad+0x140 / 100 */
                        f20 = p->stickY / 100.0f;
                        if (u->fA0 <= 0 || u->active != 0) {
                            u->fB0 = func_0038DAB8(u->fB0, (u->fA4 - u->fB0) / 150.0f);
                            u->fB4 = func_0038DAB8(u->fB4, (u->fA8 - u->fB4) / 150.0f);
                            u->fB8 = func_0038DAB8(u->fB8, (u->fAC - u->fB8) / 150.0f);
                        } else {
                            u->fB8 = func_0038DAB8(u->fB8, f20);
                            u->fB4 = func_0038DAB8(u->fB4, f21);
                        }
                        *(f32 *)(o + 0xF0) = u->fB0;
                        *(f32 *)(o + 0xF4) = u->fB4;
                        *(f32 *)(o + 0xF8) = u->fB8;
                        {
                            double d1 = (double)f20;
                            double d2 = (double)f21;
                            if (d1 < 0) d1 = -d1;
                            if (d1 > (double)0.0001f) {
                                u->fA0 = 180;
                            } else {
                                if (d2 < 0) d2 = -d2;
                                if (d2 > (double)0.0001f) u->fA0 = 180;
                            }
                        }
                    }
                    func_003C7C38(o);
                    if (u->mode != 2 && u->mode != 5 && u->mode != 3) {
                        func_0038CE20(tmp, o, 0.0009765625f);
                        *(f32 *)(o + 0x10) = *(f32 *)(o + 0x10) + (*(f32 *)(o + 0x10) - tmp[0]);
                        *(f32 *)(o + 0x14) = *(f32 *)(o + 0x14) + (*(f32 *)(o + 0x14) - tmp[1]);
                        func_003C7C38(o);
                    }
                }
            }
            if (u->fA0 > 0) u->fA0--;
        }
        if (!u->f89 && u->f8C == 3 && u->active == 0 && u->scroll == 0) func_L01_004BF980();
        u->timer++;
        func_L01_004BDF08();
        func_L01_004BD4A8();
        func_L01_004C1EA0();
        D_L01_001E0F90 = D_001D52FC_sda->buttons;
        func_00396568(1);
        func_003AF498();
        func_L01_00478898();
        func_L01_004788D0(0);
    } else if (u->type < 2) {
        if (u->type == 0) {
            D_L01_001DAC50 = D_L01_001DAC50 + 0.1f;
            if (1.0f <= D_L01_001DAC50) {
                u->type = 1;
                D_L01_001DAC50 = 1.0f;
                u->timer = 0;
            }
        }
    } else if (u->type == 2) {
        if (u->mode == 0) func_L01_004C1460(1);
        else if (u->mode == 3) func_L01_004C3840(1);
        else if (u->mode == 2) func_L01_004C42D0(1);
        else if (u->mode == 5) func_L01_004C4D90(1);
        D_L01_001DAC50 = D_L01_001DAC50 + 0.1f;
        D_L01_001E0F7C[0] = D_L01_001E0F7C[0] + 1;
        if (D_L01_001E0F7C[0] >= 12) {
            func_L01_004C26A8();
            D_L01_001DAC50 = 1.0f;
            if (u->f8 != 0) {
                a = u->f9C;
                u->f8 = 0;
                if (a >= 0) {
                    s32 v = *(s32 *)(D_00160C40 + a * 20 + 0x4590);
                    func_003A2750(1);
                    func_0039AA38(v);
                    func_003A2750(1);
                    func_L01_0042D110(v);
                } else {
                    D_0016C6A4[0] = -1;
                }
            }
            u->timer = 0;
            if (u->f60 == 0) {
                func_003E5520();
                func_003CD058();
                func_L01_004AB0E0();
                func_L01_004E20E8();
                func_003CD350();
            }
            func_003A0F98(D_L01_001DABD8 > 0 ? D_L01_001DABD8 : 0, 0);
            func_00396568(1);
            if (u->f60 == 0) {
                func_L01_003EB350(0, (u8 *)u + 0xD0);
                func_L01_003EB3C0(0, (u8 *)u + 0xE0);
            }
            func_003D0B20();
            func_003E55B8();
            if (u->mode == 5) D_L01_001D7BE0 = D_L01_001DABA8;
        }
    }
    func_003A4288();
}
/* localdecomp:end func_L01_004BDF78 */
