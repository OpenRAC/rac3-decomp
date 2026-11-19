/* functional: high. Retail copies the 16 bytes with lq/sq through a GPR, as the V16 struct assignment does; only register choice differs (retail keeps idx in a copy first). Sets flag 0x40 in slot word 0x118 then copies the vector to slot+0xF0. */
typedef struct { u8 b[16]; } V16_4AAFD0 __attribute__((aligned(16)));
extern u8 D_001A30B0[];

s32 func_L01_004AAFD0(u32 idx, V16_4AAFD0 *src) {
    u8 *e;
    if (idx < 0x34) {
        e = D_001A30B0 + idx * 128;
        *(u32 *)(e + 0x118) |= 0x40;
        *(V16_4AAFD0 *)(e + 0xF0) = *src;
    }
    return 1;
}
