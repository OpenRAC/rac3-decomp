/* functional: high. Checked at L04: scan loop and every store/offset match retail; only register allocation and the order of address computations differ (retail computes the entry address twice). Struct S_004BAD40 is 0x60 bytes. D_001D96B6_sda is the  u16 serial counter. */
/* localdecomp:start func_L04_004BAD40 */
typedef struct {
    u8 used;
    s8 b1;
    s8 b2;
    s8 b3;
    u16 id;
    u8 pad6[2];
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
    u8 pad1C[0x60 - 0x1C];
} S_004BAD40;
extern S_004BAD40 D_L04_00239370[];
extern u16 D_001D96B6_sda;
__asm__(".extern D_001D96B6_sda, 2");

S_004BAD40 *func_L04_004BAD40(void) {
    u16 i;
    u16 c;
    for (i = 0; D_L04_00239370[i].used != 0 && i < 12; i++) {
    }
    if (i == 12) {
        return 0;
    }
    D_L04_00239370[i].b3 = -1;
    D_L04_00239370[i].b1 = -1;
    D_L04_00239370[i].b2 = -1;
    D_L04_00239370[i].w18 = -1;
    D_L04_00239370[i].id = 0xFFFF;
    D_L04_00239370[i].w10 = -1;
    D_L04_00239370[i].wC = 0;
    D_L04_00239370[i].w8 = 0;
    D_L04_00239370[i].w14 = 0;
    c = D_001D96B6_sda;
    D_001D96B6_sda = c + 1;
    D_L04_00239370[i].id = c;
    D_L04_00239370[i].used = 1;
    return &D_L04_00239370[i];
}
/* localdecomp:end func_L04_004BAD40 */
