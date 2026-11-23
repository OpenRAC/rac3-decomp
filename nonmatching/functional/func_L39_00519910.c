/* functional: high. Creates a new entry in the global list (D_0046F550/D_0046F554): picks a free id (func_L39_00519568), validates a1 (0 when equal to a0 for the mode-2 case, else only 1 or 3 allowed), allocates and zeroes a 0x70-byte node, fills id/kind/-1 fields, links it at the head, and returns the id. Error codes go through func_L39_005192A8 (0x60 wrong mode, 0x6B bad kind, 0xC out of memory). */
typedef struct N_00519910 N_00519910;
struct N_00519910 { N_00519910 *next; N_00519910 *prev; s32 id; u8 pad0C[8]; s32 kind; u8 pad18[0x4C]; s32 f64; s32 f68; s32 f6C; };
extern N_00519910 *D_L39_0046F550 __attribute__((section(".data")));
extern N_00519910 *D_L39_0046F554 __attribute__((section(".data")));
extern void *func_L39_005190E8(s32);
extern s32 func_L39_005192A8(void *, s32);
extern s32 func_L39_00519568(void);
extern void func_L39_00518FE0(void);
extern void func_0011D534(void *, s32, s32);

s32 func_L39_00519910(s32 mode, s32 kind) {
    void *h;
    s32 id;
    N_00519910 *n;
    N_00519910 *head;

    h = func_L39_005190E8(0);
    if (h == 0) {
        return -1;
    }
    if (mode != 2) {
        return func_L39_005192A8(h, 0x60);
    }
    id = func_L39_00519568();
    if (kind == mode) {
        kind = 0;
    } else if (kind < 3) {
        if (kind != 1) {
            return func_L39_005192A8(h, 0x6B);
        }
    } else if (kind != 3) {
        return func_L39_005192A8(h, 0x6B);
    }
    n = ((N_00519910 *(*)(s32))func_L39_00518FE0)(0x70);
    if (n == 0) {
        return func_L39_005192A8(h, 0xC);
    }
    func_0011D534(n, 0, 0x70);
    head = D_L39_0046F550;
    n->kind = kind;
    n->f6C = -1;
    n->id = id;
    n->f64 = -1;
    n->f68 = -1;
    n->next = head;
    if (head != 0) {
        head->prev = n;
    } else {
        D_L39_0046F554 = n;
    }
    D_L39_0046F550 = n;
    n->prev = 0;
    func_L39_005192A8(h, 0);
    return id;
}
