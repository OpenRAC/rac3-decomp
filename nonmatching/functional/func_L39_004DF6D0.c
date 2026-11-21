/* exact: byte-identical at level 39 (MD2_Init: clears num, data, cksm, state). */
extern void *func_L39_0011D534(void *, s32, s32);

typedef struct S_004DF6D0 {
    s32 num;
    u8 data[16];
    u32 cksm[16];
    u32 state[16];
} S_004DF6D0;

void func_L39_004DF6D0(S_004DF6D0 *c) {
    c->num = 0;
    func_L39_0011D534(c->state, 0, 0x40);
    func_L39_0011D534(c->cksm, 0, 0x40);
    func_L39_0011D534(c->data, 0, 0x10);
}
