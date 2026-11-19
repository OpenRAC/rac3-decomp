/* functional: high. Returns whether the size field of file-table entry (arg&0xFF) in table A (bit 0x100 set) or B is positive; only address-calc scheduling differs. */
int func_L01_0042E360(int arg) {
    if ((arg & 0x100) == 0) {
        arg &= 0xFF;
        return D_00160C40.b[arg].size > 0;
    }
    arg &= 0xFF;
    return D_00160C40.a[arg].size > 0;
}
