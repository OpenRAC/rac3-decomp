/* func_L39_004FC1A0: near miss 17 diff (w2 p2w2); logic believed right, frame spacing differs (retail 16-byte save slots). */
typedef struct {
    void *buf;
    int pad4;
    int count;
    int padC;
    unsigned int flags;
} S_004FC1A0;
extern void func_0011D534(void *, int, int);
extern void func_L39_004BEF28(void *);

void func_L39_004FC1A0(S_004FC1A0 *p)
{
    unsigned int own;
    if (p == 0)
        return;
    if (p->buf != 0) {
        func_0011D534(p->buf, 0, p->count << 3);
        if (!(p->flags & 2))
            func_L39_004BEF28(p->buf);
    }
    own = p->flags & 1;
    func_0011D534(p, 0, 0x14);
    if (own)
        func_L39_004BEF28(p);
}
