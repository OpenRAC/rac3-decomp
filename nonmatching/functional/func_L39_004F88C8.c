/* functional: high. Same call sequence, argument values and stack-slot stores as retail (including the delay-slot stores before the first call); not byte-checked (file is @ee296, whose compiler does not run on the Mac); compiles with SN gcc, 9 calls as retail. DNAS library code, the port may replace it. */
extern s32 func_L39_004F4E58(void **);
extern s32 func_L39_004F4F68(void *, void *, s32);
extern s32 func_L39_004F6ED0(void **);
extern s32 func_L39_004F6FA0(void *, void *, void *);
extern s32 func_L39_004F6CA8(void *, void *, void *, s32);
extern s32 func_L39_004F6D38(void *, void *, s32 *, s32, void *, s32, s32, s32);
extern s32 func_L39_004F6E18(void *, void *, s32 *, s32, s32, s32);
extern void func_L39_004F4F18(void **);
extern void func_L39_004F6F38(void **);
extern s32 func_L39_00508B30(void **);
extern char D_L39_00478E50[] __attribute__((aligned(8)));
extern s32 func_L39_00508068(void **);

/* DNAS block operation: sets up two library contexts, runs the staged transform over
 * `in` (inlen bytes, at least 0x80) into `out`, and stores the total output length.
 * Returns 0 on success, -1 on any failure (key size must be 0x80). */
s32 func_L39_004F88C8(void *out, s32 keylen, void *p1, s32 p2, void *in, s32 inlen, s32 *outlen) {
    void *ctxA = 0;
    void *ctxB = 0;
    s32 args[2];
    u8 tag[8];
    s32 n1;
    s32 n2;
    s32 r;

    __builtin_memcpy(tag, D_L39_00478E50, 8);
    if (keylen != 0x80) {
        r = -1;
    } else if ((u32)inlen < 0x80) {
        r = -1;
    } else {
        args[1] = p2;
        args[0] = (s32)p1;
        r = func_L39_004F4E58(&ctxA);
        if (r == 0) {
            r = func_L39_004F4F68(ctxA, func_L39_00508068, 0);
            if (r == 0) {
                r = func_L39_004F6ED0(&ctxB);
                if (r == 0) {
                    r = func_L39_004F6FA0(ctxB, func_L39_00508B30, args);
                    if (r == 0) {
                        r = func_L39_004F6CA8(ctxA, ctxB, tag, 0);
                        if (r == 0) {
                            r = func_L39_004F6D38(ctxA, in, &n1, inlen, out, 0x80, 0, 0);
                            if (r == 0) {
                                r = func_L39_004F6E18(ctxA, (u8 *)in + n1, &n2, inlen - n1, 0, 0);
                                if (r == 0) {
                                    *outlen = n1 + n2;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (r != 0) {
        r = -1;
    }
    func_L39_004F4F18(&ctxA);
    func_L39_004F6F38(&ctxB);
    return r;
}
