/* functional: high. Same control flow and bytes up to register allocation; verified block by block against asm (lw/ld widths, quad copy, 48-byte table stride). */
extern u8 *D_L05_001DFC80;
extern u8 *D_L05_001DF7CC;

void func_L05_0035AEC8(u8 *o) {
    u8 *s = *(u8 **)(o + 0x68);
    s32 a;
    s32 b;
    s32 c;
    *(s32 *)(s + 0x3E0) = 1;
    a = *(s32 *)(s + 0x384);
    if (a != -1) {
        *(s32 *)(s + 0x3E0) = 2;
    } else {
        b = *(s32 *)(s + 0x388);
        if (b != a) {
            *(s32 *)(s + 0x3E0) = 4;
            *(vu0_q *)(s + 0x350) = *(vu0_q *)(D_L05_001DFC80 + (b << 7) + 0x30);
        } else if (*(s32 *)(s + 0x380) != b) {
            *(s32 *)(s + 0x3E0) = 3;
        } else {
            c = *(s32 *)(s + 0x38C);
            if (c != -1 && *(s16 *)(D_L05_001DF7CC + c * 48 + 0x32) != 0) {
                *(s32 *)(s + 0x3E0) = 5;
            } else if (*(s32 *)(s + 0x398) != 0 || *(s32 *)(s + 0x3FC) != 0) {
                *(s32 *)(s + 0x3E0) = 4;
                *(vu0_q *)(s + 0x350) = *(vu0_q *)(o + 0x10);
            }
        }
    }
    if (*(s32 *)(s + 0x3A4) != -1 && *(long *)(s + 0x380) == -1 && *(long *)(s + 0x388) == -1) {
        *(s32 *)(s + 0x3E0) = 4;
    }
}
