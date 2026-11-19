/* exact: byte-identical at level 39 (free the pointer if non-null). */
extern void func_L39_004BEF28(void *);

void func_L39_004DEBF0(void *p) {
    if (p != 0) {
        func_L39_004BEF28(p);
    }
}
