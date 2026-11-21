/* functional: high. Same allocation, error report and field stores as retail; retail zeroes +0x10 with one sd, here two sw (same bytes). Checked with SN flags only (file context declares it void(s32), must become a pointer return). */
typedef struct Node_004FA480 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 padC;
    s32 f10;
    s32 f14;
} Node_004FA480;

extern void *func_L39_004BEED8(s32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* allocate a zeroed 0x18-byte node tagged with `type` at +4; 0 and an error on failure */
Node_004FA480 *func_L39_004FA480(s32 type) {
    Node_004FA480 *p = func_L39_004BEED8(0x18);

    if (p == 0) {
        func_L39_004BC6C8(0xD, 0x74, 0x21, 0, 0);
        return 0;
    }
    p->f4 = type;
    p->f0 = 0;
    p->f8 = 0;
    p->f10 = 0;
    p->f14 = 0;
    return p;
}
