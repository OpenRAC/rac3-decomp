/* functional: high. Checked at L04: same control flow (switch on 2/4/5 decision tree matches retail), same calls and offsets; diffs are register assignment and loop-invariant loads of the table pointers (not behaviour). Logic read block by block from the assembly. */
/* localdecomp:start func_L04_004C1158 */
typedef s32 (*Fn_004C1158)(u8 *);

s32 func_L04_004C1158(u8 *self, u8 *tbl) {
    s32 i = 0;
    s32 r = 0;
    while (i < *(s32 *)(tbl + 0x10)) {
        Fn_004C1158 *a = *(Fn_004C1158 **)(tbl + 4);
        if (a != 0 && a[self[0x95]] != 0) {
            while (i < *(s32 *)(tbl + 0x10)) {
                r = (*(Fn_004C1158 **)(tbl + 4))[self[0x95]](self);
                switch (r) {
                case 4:
                    return 1;
                case 5:
                    return 0;
                case 2:
                    i++;
                    if (i < *(s32 *)(tbl + 0x10)) {
                        continue;
                    }
                    break;
                }
                break;
            }
            if (r == 3) {
                i++;
                continue;
            }
        }
        {
            Fn_004C1158 *b = *(Fn_004C1158 **)(tbl + 0xC);
            if (b == 0) {
                return 1;
            }
            if (b[self[0x20]] == 0) {
                return 1;
            }
            while (i < *(s32 *)(tbl + 0x10)) {
                r = (*(Fn_004C1158 **)(tbl + 0xC))[self[0x20]](self);
                switch (r) {
                case 4:
                    return 1;
                case 5:
                    return 0;
                case 2:
                    i++;
                    if (i < *(s32 *)(tbl + 0x10)) {
                        continue;
                    }
                    break;
                }
                break;
            }
            if (r != 3) {
                return 1;
            }
            i++;
        }
    }
    return 1;
}
/* localdecomp:end func_L04_004C1158 */
