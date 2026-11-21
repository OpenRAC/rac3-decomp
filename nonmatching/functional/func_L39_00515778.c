/* functional: medium. 184 diffs: retail lays the allocation failure paths out differently (goto-style). Control flow and every store checked against the asm; struct field meanings (n at 0x18, pointers at 0x1C/0x20/0x24) inferred. */
extern void *func_L39_004F7590(s32);
extern void func_L39_004F7620(void *);
extern s32 func_L39_004F6060(void *, void *, s32);
extern s32 func_L39_004F5EA0(void *, void *, void *);
extern u8 D_L39_0046F468[];

typedef struct S_00515778 {
    char pad0[0x18];
    s32 n;
    u8 *f1C;
    u8 *f20;
    u8 *f24;
} S_00515778;

s32 func_L39_00515778(void *ctx, S_00515708 *arg1) {
    S_00515778 *p = (S_00515778 *)arg1;
    S_00515778 *q;
    u8 **A;
    u8 **B;
    s32 err;
    s32 count;
    s32 k;
    s32 i;
    s32 off;

    B = 0;
    q = 0;
    count = p->n * 3 + 2;
    A = func_L39_004F7590(count << 2);
    err = 0x206;
    if (A != 0) {
        B = func_L39_004F7590(count << 2);
        if (B != 0) {
            err = func_L39_004F6060(ctx, &q, 0x28);
            if (err == 0) {
                err = func_L39_004F6060(ctx, &q->f1C, p->n << 3);
                if (err == 0) {
                    err = func_L39_004F6060(ctx, &q->f20, p->n << 3);
                    if (err == 0) {
                        err = func_L39_004F6060(ctx, &q->f24, (p->n - 1) << 3);
                        if (err == 0) {
                            A[1] = (u8 *)p + 8;
                            A[2] = (u8 *)p + 0x10;
                            A[0] = (u8 *)p;
                            k = 3;
                            i = 0;
                            B[0] = (u8 *)q;
                            B[1] = (u8 *)q + 8;
                            B[2] = (u8 *)q + 0x10;
                            A[3] = p->f1C;
                            B[3] = q->f1C;
                            A[p->n + k] = p->f20;
                            B[p->n + k] = q->f20;
                            off = 0;
                            if (p->n - 1 != err) {
                                do {
                                    A[p->n * 2 + k] = p->f24 + off;
                                    i++;
                                    B[p->n * 2 + k] = q->f24 + off;
                                    off = i << 3;
                                    k++;
                                    A[k] = p->f1C + off;
                                    B[k] = q->f1C + off;
                                    A[k + p->n] = p->f20 + off;
                                    B[k + p->n] = q->f20 + off;
                                } while (i != p->n - 1);
                            }
                            q->n = p->n;
                            for (k = 0; k < count; ) {
                                err = func_L39_005155E8(B[k], A[k], A[0], A, 1, ctx);
                                k++;
                                if (err != 0) {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    func_L39_004F7620(A);
    func_L39_004F7620(B);
    if (err != 0) {
        return err;
    }
    return func_L39_004F5EA0(ctx, D_L39_0046F468, q);
}
