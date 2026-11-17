/* func_L01_0046ECB8: 8 diff with the file's flags (-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack @ps2as). Layout, constants and calls are in. Differs: retail narrows a2 with andi $s2,$a2,0xff in the prologue and again after the first two stores (`s32 a2` with `a2 &= 0xFF` gives a `move` in the prologue, `u8 a2` folds the second andi away); retail loads 0x70 into $v1 and 0x44 into $a0 (swapped here); retail keeps the case 1 colour byte in $v0 (andi/sll) where this reloads it with lbu. Tried: s32/u8 a2, switch vs if/else (switch gives retail's block layout), store orders of 0x12..0x17, a local u8/s32 for the colour (33 diff, worse). Needs the file's s128 typedef and U8/S16/S32/F32 macros. */
typedef int s128 __attribute__((mode(TI)));
#define U8(p, o) (*(u8 *)((p) + (o)))
#define S16(p, o) (*(s16 *)((p) + (o)))
#define S32(p, o) (*(s32 *)((p) + (o)))
#define F32(p, o) (*(f32 *)((p) + (o)))
extern S_467288 *func_L01_004618E0(s32 size);
extern u8 *D_L01_00221180[];
extern s32 func_0013D3E0(void);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern void func_00382760(void *, f32, f32, f32);

u8 *func_L01_0046ECB8(s128 *pos, u8 a1, s32 a2, s16 a3, u8 a4, u8 a5, s32 a6, f32 sx, f32 sy) {
    u8 *o;
    u8 *p;
    f32 speed;
    f32 yaw;
    s32 r;

    o = ((u8 * (*)(s32))func_L01_004618E0)(0x51);
    if (o != 0) {
        p = o + 32;
        *(s128 *)(o + 16) = *pos;
        U8(o, 1) = 0;
        U8(o, 3) = 0x44;
        U8(o, 9) = 0x70;
        r = func_0013D3E0();
        U8(o, 2) = D_L01_00221180[0][r & 7];
        F32(o, 12) = 21000.0f;
        U8(o, 8) = func_0013D3E0();
        U8(p, 0x12) = a2;
        U8(p, 0x13) = a4;
        a2 &= 0xFF;
        S32(p, 0x18) = a6;
        F32(p, 0x1C) = sx;
        U8(p, 0x17) = a1;
        S16(p, 0x10) = a3;
        U8(p, 0x15) = a5;
        switch (a2) {
        case 0:
            S16(o, 10) = a3;
            S32(o, 4) = 0xFF808080;
            U8(p, 0x14) = 0;
            break;
        case 1:
            speed = func_003824E0(3.0f, 9.0f) * sy * 0.0200000014f;
            yaw = func_00382538();
            func_00382760(p, speed, yaw, func_003824E0(1.34390354f, 1.79768908f));
            F32(o, 12) = 42000.0f;
            r = func_0013D3E0();
            U8(p, 0x16) = (r & 0x1F) + 0x10;
            S16(o, 10) = a5;
            S32(o, 4) = (U8(p, 0x16) << 24) | 0x808080;
            U8(p, 0x14) = a2;
            break;
        }
    }
    return o;
}

INCLUDE_ASM("asm/levels", func_L01_0046ECB8);
