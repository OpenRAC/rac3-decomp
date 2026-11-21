/* functional: high. Loop/branch structure read against asm; compiles; remaining diff is scheduling. */
extern float D_L31_001E12B4;
extern float D_L31_00284A10[];
extern void func_L31_0034B850(void *, void *, float);

/* Maps t in [0,1] through a monotone 512-entry table (binary search, 12 steps) to a path parameter. */
void func_L31_0034BA10(void *obj, void *out, float t) {
    s32 lo = 0;
    s32 hi = 0x1FE;
    s32 mid = 0xFF;
    s32 found = 0;
    s32 i;
    float ft;

    if (1.0f < t) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    ft = t * D_L31_001E12B4;
    for (i = 0; i < 12; i++) {
        if (D_L31_00284A10[mid + 1] < ft) {
            lo = mid + 1;
        } else if (ft < D_L31_00284A10[mid]) {
            hi = mid - 1;
        } else {
            found = 1;
            break;
        }
        mid = (lo + hi) / 2;
    }
    if (found) {
        float a = D_L31_00284A10[mid];
        float b = D_L31_00284A10[mid + 1];
        func_L31_0034B850(obj, out, ((float)mid + (ft - a) / (b - a)) / 511.0f);
    }
}
