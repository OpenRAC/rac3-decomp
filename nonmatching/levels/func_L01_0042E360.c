/* func_L01_0042E360: near miss 6 diff, p2w3 w1. Retail has addiu base before sll idx; mine sll first.
   Size 68, places 34 levels, file src/levels/shared/L01_0042DB28.c
   Left: address-calc scheduling only. */
int func_L01_0042E360(int arg) {
    if ((arg & 0x100) == 0) {
        arg &= 0xFF;
        return D_00160C40.b[arg].size > 0;
    }
    arg &= 0xFF;
    return D_00160C40.a[arg].size > 0;
}
