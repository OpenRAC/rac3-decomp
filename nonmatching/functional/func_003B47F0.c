/* functional: high. Checked against PAL asm; byte-exact under check.py --flags=-mno-split-addresses (a per-function override the file's own flags do not have), so not a legitimate match under the file's flags. */
extern u8 D_001D88F8[];
void **func_003B47F0(void **p) {
    p[0] = (void *)1;
    p[1] = D_001D88F8;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    return p;
}
