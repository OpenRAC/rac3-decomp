/* functional: high. Same loops, compares and calls as retail; frame/registers differ (retail uses Sony-style 0x60 frame). File context declares void func_L39_004F16C0(s32,s32) in L39_004F1678.c, which must become s32(void*,void*) to compile with this body. */
typedef struct Key_004F16C0 { s32 len; s32 pad4; void *data; } Key_004F16C0;
typedef struct Item_004F16C0 { s32 pad0; void *sub; Key_004F16C0 *key; s32 val; } Item_004F16C0;
typedef struct List_004F16C0 { s32 count; Item_004F16C0 **items; } List_004F16C0;
typedef struct Obj_004F16C0 { s32 pad0; List_004F16C0 *list; } Obj_004F16C0;

extern s32 func_11D2EC(void *, void *, s32);
extern s32 func_L39_004E0E98(void *, void *);

/* compare two ordered lists of (key bytes, value, sub-object) entries; 0 when equal */
s32 func_L39_004F16C0(Obj_004F16C0 *a, Obj_004F16C0 *b) {
    s32 i;
    s32 d;
    Item_004F16C0 *x;
    Item_004F16C0 *y;

    if (a->list->count != b->list->count) {
        return a->list->count - b->list->count;
    }
    for (i = a->list->count - 1; i >= 0; i--) {
        x = a->list->items[i];
        y = b->list->items[i];
        d = x->key->len - y->key->len;
        if (d != 0) {
            return d;
        }
        d = func_11D2EC(x->key->data, y->key->data, x->key->len);
        if (d != 0) {
            return d;
        }
        d = x->val - y->val;
        if (d != 0) {
            return d;
        }
    }
    for (i = a->list->count - 1; i >= 0; i--) {
        x = a->list->items[i];
        y = b->list->items[i];
        d = func_L39_004E0E98(x->sub, y->sub);
        if (d != 0) {
            return d;
        }
    }
    return 0;
}
