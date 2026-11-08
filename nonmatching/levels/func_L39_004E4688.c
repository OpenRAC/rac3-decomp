/* Near miss, ported from rac4-decomp's func_L00_00520488 (cross-game near pair). NEAR: SQ_RA: body identical to retail; only frame 0x50 with 16-byte-spaced saves (s0@0,s1@0x10,s2@0x20,s3@0x30,ra@0x40) differs; start_c unchanged */
typedef struct Type1 {
    u8 f0[4];
    int f4;
    u8 f8[4];
    void **fC;
} Type1;
extern void *func_L39_004E47A8(void);
extern void func_L39_004E47F8(void *);
extern int func_L39_004E4970(void *, void *, int);

void *func_L39_004E4688(void *a1, Type1 *a2, int a3)
{
    void *v5;
    int v6;
    int v8;
    void *v10;
    if (!a1) {
        v5 = func_L39_004E47A8();
        if (!v5)
            return 0;
    } else {
        v5 = a1;
    }
    v8 = 0;
    v6 = a2->f4;
    if (v6 > 0) {
        do {
            v10 = a2->fC[v8];
            if (v10) {
                if (func_L39_004E4970(v5, v10, a3))
                    goto fail;
                v6 = a2->f4;
            }
            v8++;
        } while (v8 < v6);
    }
    return v5;
fail:
    func_L39_004E47F8(v5);
    return 0;
}