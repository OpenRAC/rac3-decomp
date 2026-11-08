/* Near miss, ported from rac4-decomp's func_L00_004F8C40 (cross-game near pair). NEAR: 26 diff: 0x60 frame with 16-byte save slots (retail) vs 0x30 8-byte; body otherwise equal */
typedef void (*Fn_4BCE40)(void *value, void *context);
typedef struct Node_4BCE40 {
    void *value;
    struct Node_4BCE40 *next;
} Node_4BCE40;
typedef struct {
    Node_4BCE40 **buckets;
    char pad[8];
    int count;
} Tab_4BCE40;

void func_L39_004BCE40(Tab_4BCE40 *tab, Fn_4BCE40 fn, void *ctx) {
    int i;
    Node_4BCE40 *n;
    for (i = tab->count - 1; i >= 0; i--) {
        n = tab->buckets[i];
        while (n != 0) {
            void *v = n->value;
            n = n->next;
            fn(v, ctx);
        }
    }
}
