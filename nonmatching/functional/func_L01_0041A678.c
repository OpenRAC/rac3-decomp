/* functional: high. Jump table on a byte at D_00143A07: cases 2-5 return per-state tables, 0/1/default return D_00163288; same behaviour, differs only in compiled switch shape. */
extern u8 D_00143A07[];
extern u8 D_00163288[];
extern u8 D_001638C8[];
extern u8 D_00163F08[];
extern u8 D_00164548[];
extern u8 D_00164B88[];

void *func_L01_0041A678(void) {
    switch (D_00143A07[0]) {
    case 2:
        return D_001638C8;
    case 3:
        return D_00163F08;
    case 4:
        return D_00164548;
    case 5:
        return D_00164B88;
    default:
        return D_00163288;
    }
}
