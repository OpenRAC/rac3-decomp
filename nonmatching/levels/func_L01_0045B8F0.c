/* func_L01_0045B8F0: 20 bytes, 49 places, src/levels/shared/L01_0045A6F0.c (w8 p2w3)
   Copies D_L01_001E0240 (u128) to a0+0x10; 4 diff rows: retail keeps the address in $v1 and the lq result in $v0, gcc picks v0/v1 the other way round.
   Tried: scalar, unsized array, pointer local. Left: a form that makes the address pseudo allocate after the loaded value. */
extern u128_t D_L01_001E0240[];

void func_L01_0045B8F0(u8 *a0, u8 *a1) {
    u128_t *p = D_L01_001E0240;
    *(u128_t *)(a0 + 0x10) = *p;
}
