/* exact: byte-identical at level 39 (free-by-type dispatch; parameter typed void * as the file's earlier declaration). */
extern void func_L39_004EA410(s32);
extern void func_L39_004DDA88(s32);
extern void func_L39_004DD250(s32);

typedef struct S_004E1268 {
    s32 type;
    s32 f4;
    s32 f8;
    s32 fC;
} S_004E1268;

void func_L39_004E1268(void *p) {
    S_004E1268 *a = p;
    switch (a->type) {
    case 6:
    case 0x13:
        func_L39_004EA410(a->fC);
        break;
    case 0x42:
    case 0x46:
    case 0x71:
    case 0x74:
        func_L39_004DDA88(a->fC);
        break;
    case 0x1C:
        func_L39_004DD250(a->fC);
        break;
    }
}
