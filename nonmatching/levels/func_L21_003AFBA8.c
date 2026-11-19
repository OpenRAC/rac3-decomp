/* func_L21_003AFBA8: 6 diff with the file's flags (@ps2as). Everything matches except the register pair of the halfword update: retail loads the flag halfword into $3 and the 0xFF byte into $2, this C gives $2/$3 the other way (lhu/addiu/ori/sb/andi/sh). Stores to 0x7F/0x8/0x38/0x7/0x9 are in retail order (source order sh, 7, 9, 8 gives it). Tried: s32 and u16 temporaries, the 0xFF store before and after the halfword load, one-expression update. */
extern u8 *func_00382348(void *);
extern u8 *func_L01_00448FF0(void *);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L01_004AA710(void *, s32);
extern void func_003A4F28(s32);
extern void func_L21_003B00A0(void *, s32);
extern void func_L21_003B00C0(void *, s32);
extern void func_L01_004443E8(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L21_003AFBA8(void *mp)
{
    u8 *m = mp;
    u8 *p;
    u8 *q;
    s32 i;

    m[0x7F] = 0;
    i = 0;
    p = func_00382348(m);
    *(f32 *)p = (f32)*(s16 *)(p + 4);
    q = func_L01_00448FF0(m);
    *(s16 *)(q + 0x38) = 0;
    q[7] = 0;
    q[9] = 0;
    q[8] = 0;
    p[0xE] = 1;
    p[0x2F] = 0;
    func_L01_00456C98(m, -1, 0, 0, 0, 0, 3, 0, 0, 0, 0.0f, 0.0f, 1.0f);
    *(s32 *)(m + 0x98) = 0;
    m[0xA8] = 0xFF;
    *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
    func_L01_004AA7E8(m, 1);
    do {
        if (func_L01_004AA710(m, i) != 0) {
            func_003A4F28(i);
        }
        i++;
    } while (i < 0x34);
    func_L21_003B00A0(m, 0);
    func_L21_003B00C0(m, -1);
    if (m[0x20] != 0) {
        func_L01_004443E8(m, 0, 3);
        m[0x7F] = 0;
    }
    func_L01_004450F0(m, 1, 4);
}

INCLUDE_ASM("asm/levels", func_L21_003AFBA8);
