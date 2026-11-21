/* exact: byte-identical at level 39 (OBJ_NAME_do_all style callback). */
typedef struct S_004E0668 {
    s32 type;
    s32 f4;
    const char *name;
} S_004E0668;
extern s32 D_L39_00453B3C __attribute__((section(".data")));
extern s32 func_L39_004E05B0(const char *, s32);

void func_L39_004E0668(S_004E0668 *a) {
    if (D_L39_00453B3C < 0 || D_L39_00453B3C == a->type) {
        func_L39_004E05B0(a->name, a->type);
    }
}
