/* exact: high. MATCH at level 01 with file flags (draft from nonmatching) */
int func_L01_004CE720(char *base, int idx) {
    float *p = *(float **)(base + idx * 0x230 + 0x4614);
    return *p > 0.0f;
}
