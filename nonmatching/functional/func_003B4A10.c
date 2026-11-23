/* functional: high. Checked against PAL asm; byte-exact under check.py --flags=-mno-split-addresses (a per-function override the file's own flags do not have), so not a legitimate match under the file's flags. */
extern u8 D_001D88D8[];
void **func_003B4A10(void **p) {
    p[0] = (void *)1;
    p[1] = D_001D88D8;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    return p;
}
