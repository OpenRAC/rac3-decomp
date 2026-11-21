/* functional: medium. Same loads/stores/calls and results as retail (checked structure: 65 instruction diffs are register allocation and global addressing only). Global D_L39_00453FB0 is accessed through raw offsets 0x10534/0x10738/0x106B8 as in the sibling struct S_004B3230; callee prototypes (func_L39_004B4800/48E0/CDB18/CDCF0) taken from asm arg usage only. */
/* checks a received block's length (two variable-size parts + 0x80 trailer), then runs the 0x10534 follow-up check */

extern u8 D_L39_00453FB0_004D9058[];
extern s32 func_L39_004B4800(u8 *);
extern s32 func_L39_004B48E0(u8 *);
extern s32 func_L39_004CDC00(void);
extern s32 func_L39_004CDB18(u8 *);
extern s32 func_L39_004CDCF0(u8 *, u8 *);

s32 func_L39_004D9058(u8 *buf, s32 expected) {
    u8 *p;
    u8 *tail;
    s32 total;
    s32 r;
    u8 *base;
    s32 flags;

    p = buf + func_L39_004B4800(buf);
    p = p + func_L39_004B48E0(p);
    tail = p;
    total = (s32)(p + 0x80) - (s32)buf;
    if (expected != total) {
        return -0x6A;
    }
    base = D_L39_00453FB0_004D9058;
    if (*(s32 *)(base + 0x10738) >= 0) {
        r = func_L39_004CDC00();
        if (r < 0) {
            return r;
        }
        if (r == 0) {
            r = func_L39_004CDCF0(tail, base + 0x10534);
            if (r < 0) {
                return r;
            }
        } else {
            r = func_L39_004CDB18(base + 0x10534);
            if (r < 0) {
                return r;
            }
        }
    }
    flags = *(s32 *)(base + 0x106B8);
    if (flags & 1) {
        *(s32 *)(base + 0x106B8) = flags & ~1;
    }
    return total;
}
